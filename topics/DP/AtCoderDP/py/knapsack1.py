
from typing import List
from math import inf
# best(w) = max value of items that add up to weight w.
# base case: best(0) = 0, with no weight we cant carry value. 
# all numbers in memo start with 0, we loop right to left.

def knapsack1(n: int, w: int) -> int:
    best = [0 for _ in range(w+1)]
    while (n):
        Wi, Vi = [int(e) for e in input().split(" ")]
        for j in reversed(range(Wi, w+1)):
            best[j] = max(best[j], best[j - Wi] + Vi)
        n -= 1

    return best[w]

line = input().split(" ")
n, w = int(line[0]), int(line[1])

print(knapsack1(n, w))
        




