"""
    N W
    3 8

    Wi Vi      Weight, Value.
    3 30
    4 50
    5 60

    Given W, a maximum amount of allowed weight, and a list of items (weight, value)
    you can pick from, choose a subset that maximizes the sum of selected items's weights.
"""

"""
    Approach:
    
    Try selecting all items in order, and store the best score up to the current index... What happens with the weight?
    We need to try with all the weights. 

    Try weights from 0 to N. 
    The best solution for a particular weight is either: 
        - based of a best solution of a smaller weight (by construction let's say we have optimality in this previous best)
        - taking a new item with a greater weight which is not allowed with previous constructions. 

    Ideas:
    best[0<= current weight <= max weight] needs to store the accumulated value sum only. 

    For a new weight, need to explore following previously calculated states. 
    best[weight - 1, weight - 2]

    However, with this path, at every step, we need to consider all elements. 

    Complexity: 
    O(W*N)? should pass since N is 1e5 and W is 

    best[idx][]
"""

def knapsack(N, W, weights, values):
    pass