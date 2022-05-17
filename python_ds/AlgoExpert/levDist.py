from collections import deque

def levenshteinDistance(str1, str2):
    cols = len(str1)
    rows = len(str2)
    best = [[10 for _ in range(rows+1)] for _ in range(cols+1)]
    return levDistHelper(best, str1, str2, cols, rows)

def levDistHelper(best, str1, str2, n, m):
    if m == 0:
        return n
    if n == 0:
        return m
    if best[n-1][m-1] != 10:
        return best[n-1][m-1]

    if str1[n-1] == str2[m-1]:
        best[n-1][m-1] = levDistHelper(best, str1, str2, n-1, m-1)
        return best[n-1][n-1]
        
    else:
        best[n][m-1] = levDistHelper(best, str1, str2, n, m-1)
        best[n-1][m] = levDistHelper(best, str1, str2, n-1, m)
        best[n-1][m-1] = levDistHelper(best, str1, str2, n-1, m-1)
        best[n][m] = 1 + min(best[n][m-1] , best[n-1][m], best[n-1][m-1])
    return best[n][m]

print(levenshteinDistance("abc", "yabc"))			