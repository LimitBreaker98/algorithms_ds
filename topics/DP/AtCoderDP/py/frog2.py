from math import inf
from typing import List

# minCost[index] is the minimum cost to reach index in the array values.
# base case: minCost[0] = 0 // you start at index 0.
# recursiveCase: minCost[j] = min(minCost[j-1] + abs(values[j-1] - values[j]), minCost[j-2] + abs(values[j-2] - values[j]))
def minCost(values: List[int], k: int) -> int:
    n = len(values)
    minCostMem = [inf for _ in range(n)]
    minCostMem[0] = 0 ## base case
    for j in range(1, n):
        for i in range(k+1):
            if j-i >= 0:
                minCostMem[j] = min(minCostMem[j], minCostMem[j-i] + abs(values[j-i] - values[j]))
    return minCostMem[n-1]

line = input().split(" ")
n, k = int(line[0]), int(line[1])
values = [0 for _ in range(n)]

line = input().split(" ")
values = [int(e) for e in line]


print(minCost(values, k))