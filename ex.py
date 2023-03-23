# Space complexity: O()

def isValid(s):

    brackets = {']':'[', ')':'(','}':'{'} # constant space
    
    n = len(s) # single valued variable, is O(1) space
    mem = [] # Space complexity is O(n)
    for i in range(n): # O(n) Time complexity
        if s[i] not in brackets:        #If checks in keys. O(1)
            mem.append(s[i])                #Includes new bracket in mem. O(1) 99.9% coz dynamic sizing
        elif len(mem) == 0:             #O(1)
            return False
        else:
            last_mem=mem.pop()      #O(1) coz is last element
            if brackets[s[i]] != last_mem: #O(1) 
                return False #O(1)

    return len(mem) == 0 # O(1)

## Follow up: Solve the problem using constant space, linear time. 