def fx():
    cols = 2
    rows = 3

    mat = [[n for n in range(1, cols+1)] for multip in range(1, rows+1)]


    for row in range(rows):
        print(mat[row])

def gx(str1, str2):
    cols = len(str1)
    rows = len(str2)
    best = [[1 << 31 for col in range(cols)] for row in range(rows)]
    print(best)

gx("abc", "yabd")