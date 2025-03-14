"""
    Vacation:
    Choose a sequence of activities to do on each day from 1 to N, such that total happiness is maximal.
    You can't choose same activity on 2 or more consecutive days. (Therefore solution is not simply summing the max value per row)
    N = 3
    10 40 70 (day 1)
    20 50 80 (day 2)
    30 60 90 (day N)
"""

"""
    Solution:
    The DP state is described in terms of two variables. 
    best[DAY][SELECTION] is the maximal achievable happiness by day DAY while choosing activity SELECTION.
    0 <= SELECTION <= 2 (each column is a different selection).

    The transition is to choose the maximum possible happiness value from the previous day while choosing different from current SELECTION.

    Calculate all the states of a given day before moving on to the next one.
    The answer is simply max(best[N-1][0],best[N-1][1], best[N-1][2]).
"""

def vacation_bottom_up(N, activity_happiness):
    best = [[0, 0, 0] for _ in range(N)]
    SELECTIONS = [0, 1, 2]
    best[0] = activity_happiness[0].copy()
    for day in range(1, N):
        for selection in SELECTIONS:
            best[day][selection] = activity_happiness[day][selection] + max(
                best[day-1][(selection + 1) % 3],
                best[day-1][(selection + 2) % 3]
            )
    
    # print(best)
    return max(best[N-1][0],best[N-1][1], best[N-1][2])



if __name__ == "__main__":
    N = int(input())
    
    n = 0
    activity_happiness = []
    # activity_happiness[day][selection] is the intended use.
    while n < N:
        activity_happiness.append([int(x) for x in input().split()])
        n += 1

    print(vacation_bottom_up(N, activity_happiness))
    

