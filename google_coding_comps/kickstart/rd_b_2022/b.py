import math

# 31425342456

# let s be a set

# all subsets of a set are 2^n where n is the size of the set
# Proof: binary representation of set membership... how many nums can be made with that representation :).

# O(n) per number.
# num = x
# iterate over all nums from 1 to x, count if palindrome and factor. 

# limits
# Time limit: 2 seconds.
# Memory limit: 1 GB.
# 1≤T≤100.
# Test Set 1
# 1≤A≤10e3.
# Test Set 2
# 1≤A≤10e10.

# O(A) per number -> O(T*A) 
# in test set 1, T*A = 100 * 1000 = 10e5 < 5*10e8
# in test set 2 -> T * A = 100 * 10e10 = 10^12

# evaluate if a number is prime is O(sq_root(n))
# If you have a number n, you can check up to sq_root(n) all its factors and if nothing divides it, it is prime.
# No number greater than sq_root(n) will divide n
# 100
# I will only try with all numbers up to sq_root(n)
# And I can get the complement of any number in the same step 

def uniqueFactors(n):
    factor_set = {"1", str(n)}

    for i in range(2, int(math.sqrt(n)) + 1): #O(sq_root(n))
        if n % i == 0:
            factor_set = factor_set | {str(i), str(n // i)}
    return factor_set


def isPalindrome(factor):
    return factor == factor[::-1]

def solve(n, case_num):
    factor_set = uniqueFactors(n)
    ans = 0
    for factor in factor_set:
        if isPalindrome(factor):
            ans += 1
    print(f"Case #{case_num}: {ans}")


t = int(input())
case_num = 1
while t:
    n = int(input())
    solve(n, case_num)
    case_num += 1
    t -= 1
