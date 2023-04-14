"""
Example input:["R","(x,x,x,x,x,x,x)","(x,x,x,x,x,x,x)","(x,x,x,x,x,x,x)","(x,x,x,R,x,x,x)","(x,x,x,R,x,x,x)","(x,x,x,R,Y,Y,Y)"]

For example, if strArr is: ["R","(x,x,x,x,x,x,x)","(x,x,x,x,x,x,x)","(x,x,x,x,x,x,x)","(x,x,x,R,x,x,x)","(x,x,x,R,x,x,x)","(x,x,x,R,Y,Y,Y)"] then your program should return (3x4).
  Note for evaluators: I'm taking a little break until 6:30pm my local time (right now it's 5:42 pm), 
  since I need to help my mom with something.
  It's 6:30 now and I'll continue with the exercise, thanks for understanding!

  Also, FYI I copied-pasted an example I printed from the console on the right to the code.
"""

"""
  Idea:
  First, model the strArr as a 2 dimensional list of 6 rows and 7 columns, to represent the game. Call this variable 'board'.
  Fill each cell of the board according to input. 

  The board will always have a valid state (legal setup)

  We need to check at most 7 different possibilities for our next move. We check every one of them to see if placing 
  a chip there will give us victory.

  Return none if there are no plays that let us win, otherwise return RxC, where R is the row and C the column where
   we play to win the game. 
  

  How to check if placing a certain chip will give us victory is discussed in the comment of the function
  play_wins(board, play)
"""

# Takes a string of the form '(x,x,x,x,x,x,x)' where each x may be an x, R or Y, and transforms it into
# a list which represents an equivalent board row, like ['x', 'x', 'x', 'x', 'x', 'x', 'x']
def get_formatted_row(strRow):
  row_entries = strRow.split(",")
  row_entries[0] = row_entries[0][1]
  row_entries[-1] = row_entries[-1][0]
  return row_entries

def get_formatted_board(strArr):
  rows, cols = 6, 7
  board_entries = strArr[1:]
  board = [get_formatted_row(board_entries[row]) for row in range(rows)]
  return board


""" 
  Returns True if playing a chip at play, a tuple with (row, col), wins the game for the current player.
  Otherwise returns False.
  Modeling:
  Let's say we want to verify if playing the X chip yields a victory. Let's call A the adjacent cells of X we 
  are going to check.

  In the case with the most possible adjacent cells, we have the following submatrix to verify:
  A-----A
  -A---A-  
  --A-A--
  AAAXAAA
  --AAA--
  -A-A-A-
  A--A--A
  
  Above, each dash represents a cell we don't have to verify. All the A's represent cells we have to verify in order to tell if 
  playing a chip at cell X wins the game.

  So, lets name the lines:
    Let (row, col) be the row and column of the cell marked by X.
    diagonal_1 starts at (row-3, col-3) and ends at (row+3, col+3)
    diagonal_2 starts at (row+3, col-3) and ends at (row-3, col+3)
    downwards_line starts at (row, col) and ends at (row+3, col)
    horizontal_line is just the same row where we place X, starts at (row, col-3) and ends at (row, col + 3)
  
  To verify if placing X wins, get the maximum amount of consecutive equal elements in each of diagonal_1, diagonal_2 and
  downwards_line (including the chip that will be placed at X).
  If any of those maximums is 4 or greater, the play wins. Otherwise, it doesn't.
  
"""

def play_wins(board, play, turn):
  # Represent each diagonal's start and end in a list of tuples of the form (start_row, start_col, end_row, end_col)
  max_diag1 = max_diagonal_1(board, play, turn)
  max_diag2 = max_diagonal_2(board, play, turn)
  max_downwards = max_downwards_line(board, play, turn)
  max_horizontal = max_horizontal_line(board, play, turn) 
  max_consecutive_per_line = max(max_diag1, max_diag2, max_downwards, max_horizontal)

  return max_consecutive_per_line >= 4

def is_valid_cell(row, col):
  return 0 <= row <= 5 and 0 <= col <= 6

def max_diagonal_1(board, play, turn):
  row, col = play
  delta = -3
  best, curr = 0, 0
  while delta < 4:
    cell_row, cell_col = row + delta, col + delta
    if is_valid_cell(cell_row, cell_col): 
      if board[cell_row][cell_col] == turn or delta == 0:
        curr += 1
      else:
        curr = 0
    best = max(curr, best)
    delta += 1
  
  return best



def max_diagonal_2(board, play, turn):
  row, col = play
  delta_row = -3 # this value increases each step
  delta_col = 3 # this value decreases each step
  best, curr = 0, 0
  while delta_row < 4 and delta_col > -4:
    cell_row, cell_col = row + delta_row, col + delta_col
    if is_valid_cell(cell_row, cell_col): 
      if board[cell_row][cell_col] == turn or (delta_col == 0 and delta_row == 0):
        curr += 1
      else:
        curr = 0
    best = max(curr, best)
    delta_row += 1
    delta_col -= 1
  return best

def max_downwards_line(board, play, turn):
  row, col = play
  best, curr, delta = 0, 0, 0
  while delta < 4:
    cell_row = row + delta
    if is_valid_cell(cell_row, col): 
      if board[cell_row][col] == turn or delta == 0:
        curr += 1
      else:
        curr = 0
    best = max(curr, best)
    delta += 1
  return best

def max_horizontal_line(board, play, turn):
  row, col = play
  best, curr, = 0, 0
  delta = -3 
  while delta < 4:
    cell_col = col + delta
    if is_valid_cell(row, cell_col): 
      if board[row][cell_col] == turn or delta == 0:
        curr += 1
      else:
        curr = 0
    best = max(curr, best)
    delta += 1
  return best


  

# Returns a list of tuples (row, col) where row and col are ints representing 
# The row and column of a possible chip placement with current board state.
def get_possible_plays(board):
  rows, cols = 6, 7
  possible_plays = []
  for col in range(cols):
    for row in reversed(range(rows)):
      if board[row][col] == "x":
        possible_plays.append((row, col))
        break
  return possible_plays


def ConnectFourWinner(strArr):
  board = get_formatted_board(strArr)
  next_player = strArr[0]
  possible_plays = get_possible_plays(board)
  for play in possible_plays:
    if play_wins(board, play, next_player):
      row, col = play
      return f"({row+1}x{col+1})"
  return "none"

# keep this function call here 
print(ConnectFourWinner(input()))