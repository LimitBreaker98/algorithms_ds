# Let cost[i] be the minimum cost to reach stone i.
# We can calculate all cost[i] from i 0...n in left to right order. 

# Jumping from stone i to j costs abs(stones[j] - stones[i])
# Let's use j as the index of the target rock for a jump, and i for the source of the jump, as stated in the problem description.

def jump(i, j, stones):
    return abs(stones[j] - stones[i])

def bottom_up_frog_1(n, stones):
    cost = [0 for _ in stones]
    cost[1] = abs(stones[1]- stones[0])

    for j in range(2,len(stones)):
        # j-1 and j-2 are our possible i's, that is, the sources for our current target j. 
        cost[j] = min(cost[j-1] + jump(j-1, j, stones), cost[j-2] + jump(j-2, j, stones))

    return cost[n-1]

if __name__ == "__main__":
    N = int(input())
    stones = [int(x) for x in input().split()]

    print(bottom_up_frog_1(N, stones))

