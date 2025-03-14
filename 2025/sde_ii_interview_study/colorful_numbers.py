from typing import List

def is_colorful(num: List[int]):
    # get all substrings (consecutive subsequences/windows) of the digits of the num. Find the product and store in a set. If some calculation is repeated, then num is not colorful. 

    # to simplify the implementation, we can calculate the product of every subset as soon as we are considering it. No need to generate all substrings, then process each one.
    # to simplify, we consider the input as a list of integers instead of a string.
    # define the window as [l, r) for easiness of implementation.
    # define n as the length of the list of digits.

    l = 0
    stored_products = set() 
    while l < len(num): # O(n), as possible values of the left index (starting point of the current window) increase linearly with the amount of digits.
        r = l
        product = 1
        while r < len(num): # O(n), similar to above.
            product *= num[r]
            if product in stored_products:
                return False
            stored_products.add(product)
            r += 1
        l += 1
    return True

assert is_colorful([3, 2, 4, 5])
assert not is_colorful([3, 2, 6])
assert not is_colorful([1, 0, 3, 4])
assert not is_colorful([1, 1, 1, 1])
assert not is_colorful([1, 2, 3, 4])
assert is_colorful([2, 3, 4])
assert is_colorful([0])
assert is_colorful([1])
assert is_colorful([7])
assert not is_colorful([3,2,4,5,8])


## Note, if num is a string, we can read the integers with int(digit) where digit is a char of the string. 
