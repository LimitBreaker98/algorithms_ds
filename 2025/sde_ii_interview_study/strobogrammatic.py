# Defines an arbitrary character outside our input
# space such that the strobogrammatic comparison always return false
# for particular digits which are not strobogrammatic.

NON_STROBOGRAMMATIC_PLACEHOLDER = "x"

def is_strobogrammatic(num: str):
    l, r = 0, len(num) - 1

    while l <= r:
        if num[l] != get_strobogrammatic(num[r]):
            return False
        l += 1
        r -= 1
    return True

def get_strobogrammatic(char: str):
    mapping = {
        "0": "0",
        "1": "1",
        "2": NON_STROBOGRAMMATIC_PLACEHOLDER,
        "3": NON_STROBOGRAMMATIC_PLACEHOLDER,
        "4": NON_STROBOGRAMMATIC_PLACEHOLDER,
        "5": NON_STROBOGRAMMATIC_PLACEHOLDER,
        "6": "9",
        "7": NON_STROBOGRAMMATIC_PLACEHOLDER,
        "8": "8",
        "9": "6",
    }
    return mapping[char]
    


assert not is_strobogrammatic("131")
assert is_strobogrammatic("69")
assert is_strobogrammatic("010")
assert is_strobogrammatic("")
assert not is_strobogrammatic("6")
assert not is_strobogrammatic("9")