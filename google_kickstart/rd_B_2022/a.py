import math

def calc_area(r):
    return r * r * math.pi

def solve(r, a, b, case_num):
    ans = 0
    mult = True
    while r:
        ans += calc_area(r)
        if mult:
            r = r * a
        else: 
            r = r // b
        mult = not mult

    print(f"Case #{case_num}: {ans:.8f}")


t = int(input())
case_num = 1
while t:
    nums_as_str = input().split(" ")
    r, a, b = [int(num) for num in nums_as_str]
    solve(r, a, b, case_num)
    case_num += 1
    t -= 1