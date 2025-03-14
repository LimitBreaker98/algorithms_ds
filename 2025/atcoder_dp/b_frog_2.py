# Let cost[i] be the minimum cost to reach stone i.
# We can calculate all cost[i] from i 0...n in left to right order. 

# Jumping from stone i to j costs abs(stones[j] - stones[i])
# Let's use j as the index of the target rock for a jump, and i for the source of the jump, as stated in the problem description.

def jump(src, target, stones):
    return abs(stones[target] - stones[src])

def bottom_up_frog_2(N, K, stones):
    cost = [int(1e9) for _ in stones]
    cost[0] = 0
    for j in range(1, N):
        # now all possible jumps are defined by K, you can jump at most K from a given rock.
        k = 1
        while k <= K and j-k >= 0:
            cost[j] = min(cost[j], cost[j-k] + jump(j-k, j, stones))
            k += 1
    # print(cost)
    return cost[N-1]

if __name__ == "__main__":
    N, K = [int(x) for x in input().split()]
    stones = [int(x) for x in input().split()]

    print(bottom_up_frog_2(N, K, stones))
