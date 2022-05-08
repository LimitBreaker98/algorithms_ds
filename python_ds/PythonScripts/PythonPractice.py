#!/usr/bin/env python
# coding: utf-8

# # Python practice
#     Author: Jorge A
#     Purpose: Knowing specific things of the python language that make it sweet.
# 

# ## Language WARNINGS
# 
# 1. Sets are UNORDERED in python. Use a priorityQueue instead.
#     from queue import PriorityQueue as PQ
#     PriorityQueue will require class nodes to be well ordered. Define __lt__ and use functools.totalordering annotation.
#     Sets use the hashing function to quickly test membership in constant time. 
#     
# 2. Use iterable comprehensions when possible to make code more succinct!
#     We can do it for lists, sets.

# ### Iterable unpacking: Assigning the values of an iterable to multiple references in one single line.
# ##### Python std iterable structures: List, Dict, Set, Tuple

# In[4]:


elem1, elem2 = [3,8]
print(elem1,elem2)
#print (elem1, elem2)

member1, member2, member3 = {1,2, "hwsdfa"}
print(member1, member2, member3)

a,b,c = ('a', [2,3], 'c')
print (a,b,c)

key_1, key_2, key_3 = {"a" : 1, "b": 2, "c": 3}
#print(key_1, key_2, key_3)
# Mutability rules
tup = ('a', 'b', 'c') # changing an element of the inner list is valid -> tup[1][0] = 3

# A set can receive anything as long as it is non mutable.
#References (x) will be treated as the object they point to at the moment of inclusion in the set

conjunto = {'a', tup} # Everything has to be hashable, adding a list to the set fails!
print(conjunto)


# In[4]:


## PriorityQueue example

# Defining a class that is well ordered so that we can use priority queue..
class use_only_first:
    def __init__(self, first, second):
        self._first, self._second = first, second

    def __lt__(self, other):
        return self._first < other._first

from queue import PriorityQueue as PQ

class Solution:
    def mergeKLists(self, lists):
        merged_head = curr = ListNode(-1)
        q = PQ()
        for head in lists:
            if head is not None:
                q.put(use_only_first(head.val, head))
        
        while not q.empty():
            obj = q.get()
            val, node = obj._first, obj._second
            curr.next = node
            curr = curr.next
            node = node.next
            if node: 
                q.put(use_only_first(node.val, node))
        return merged_head.next
        


# #### Lambda Expressions

# In[9]:


# List
lista = [3,2,1,5,6,7,8,9,-1,2,3,4,-2,-5,-6]
res = list(filter(lambda num: num < 0, lista))
print(res)


# In[6]:


tupleList = [(1,2), (3,4), (5,6)]
res = list(filter(lambda tup: tup[0] < tup[1], tupleList))


# In[7]:


tup = (3,4,5,6,7)
tup.count(10)


# ### Iterable Comprehensions: easy syntax to initialize Iterables

# In[15]:


## List
letters = [letter for letter in "string"]
#print(letters)

parity_of_integers = [num % 4 for num in range(30)]

#print(parity_of_integers)

seen_set = {x for x in [3,5,7,9,10,10,10,20]}
print(seen_set)

x = list(set([3,3,3,3,3,3,3,3,1,2,2,2,12,1,21,2,12,1,2,2]))
print(x)

seen_dict = {key: value for key, value in [(1,[10,20])]}  ## Less useful as we need a list of (maybe) any kind of 2 valued iterables
print(seen_dict)


# #### Applications of Iterable Comprehensions

# In[18]:


## Initialize dp cache
rows = 3
cols = 2
dp = [[0 for c in range(cols)] for r in range(rows)]
dp


# In[16]:


## Another version
dp2 = rows * [cols * [0]]
dp2


# #### Binary Search

# Binary Search has lots of applications, here we mention 2 super common cases. Simplified to search over arrays.
# 
# 
# ##### Case 1:
# Let P(X) be a monotonically increasing predicate. This means that P(X) >= P(X-1) for all X > 1
# Find X such that P(X) == target
# 

# In[17]:


P = [1,3,7,9,11,13,15,20]   # in this case X is the array index, P(X) is to be understood as P[index]


## Returns the position of the target value searched within the array, -1 if not found

def binarySearch (items, target: int):
    l, r = 0, len(items)-1

    while l <= r:
        print(f"l: {l}")
        mid = (l+r) // 2
        print(f"mid: {mid}")
        print(f"r: {r}")
        print('--------')
        if P[mid] == target:
            return mid
        elif P[mid] > target:
            r = mid - 1
        else:
            l = mid + 1
    return -1

'''
    testing
    P = [1,3,7,9,11,13,15,20]
    
    index(3) = 1
    index(-1) = -1
    index(100) = -1
    index (11) = 4
'''

#print(binarySearch(P, 3))
#print(binarySearch(P, -1))
#print(binarySearch(P, 100))
#print(binarySearch(P, 4))


# ##### Case 2: 
# Let P(X) be a monotonically increasing predicate. This means that P(X) >= P(X-1) for all X > 1
# Find X such that P(X) >= target and P(X-1) < target.
# i.e Find the index to the first element in the range [first,last) which does not compare less than target.
# 

# In[ ]:


def lower_bound(items, target):
    l, r = 0, len(items)-1
    
    while l <= r:
        mid = (l+r)//2
        


# ### Sorting using lambdas
# 

# In[27]:


l = [[100,103,105],[100,103,33],[100,10,27], [100, 103, 50]]


# In[28]:


l.sort(key = lambda x: (x[1], x[2]))


# In[29]:


l


# In[10]:


memo = [[0 for col in range(10)]] * 4


# In[11]:


memo


# In[12]:


memo[3][7] = 3


# In[13]:


memo


# In[14]:


memo = [[0 for col in range(10)] for row in range(4)] 


# In[16]:


memo[3][7] = 3


# In[17]:


memo


# In[18]:





# In[51]:


def longestPalindrome(s: str) -> str:
    n = len(s)
    isPalindrome = [[False for col in range(n)] for row in range(n)]
    posStart, posEnd = 0,0
    # base case 1, a one letter substring is a palindrome
    for i in range(n):
        isPalindrome[i][i] = True

    # base case 2, a 2 letter string is palindrome only if same letters
    for i in range(n-1):
        if s[i] == s[i+1]:
            isPalindrome[i][i+1] = True
            posStart, posEnd = i, i + 1

    #General case, iterate over the possible size of substrings, from 3 letters to N letters.
    
    for sz in range(2, n):
        for i in range(n):
            if i + sz < n: # valid substring
                sameEnd = s[i] == s[i + sz]
                isPalindrome[i][i + sz] = sameEnd and isPalindrome[i+1][i + sz - 1]
                if (isPalindrome[i][i + sz]):
                    posStart = i
                    posEnd = i + sz
    return s[posStart:posEnd+1]


# In[53]:


longestPalindrome("babad")


# In[ ]:





# In[ ]:




