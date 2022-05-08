
#matrix is N by 3
from typing import List


def maxHappiness(matrix: List[List[int]], n: int) -> int:
    maxVal = [[0 for _ in range(3)] for _ in range(n)]
    for c in range(3): #base cases
        maxVal[0][c] = matrix[0][c]

    for r in range(1, n):
        maxVal[r][0] = matrix[r][0] + max(maxVal[r-1][1], maxVal[r-1][2])
        maxVal[r][1] = matrix[r][1] + max(maxVal[r-1][0], maxVal[r-1][2])
        maxVal[r][2] = matrix[r][2] + max(maxVal[r-1][0], maxVal[r-1][1])
        
    return max(maxVal[n-1][0], maxVal[n-1][1], maxVal[n-1][2])

n = int(input())
mat = []
for _ in range(n):
    line = input().split(" ")
    mat.append([int(e) for e in line])

print(maxHappiness(mat, n))

