#!/usr/bin/env python
# coding: utf-8

# #### A section where solutions to DP are presented in python

# In[1]:


### Longest Palindromic substring
# Given s, a string, determine the longest palindromic substring inside it.


# In[2]:


## V1, DP O(n^2) time, O(n^2) space where n = len(s)
## Veredict: Accepted

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


# In[11]:


## Improving space to O(n)
## Realize you can iterate from end to beginning starting points, and only have an array for the next level answer
## Draw arrows in the DP matrix to realize the form of the dependency graph
## Veredict: Accepted

def longestPalindromeV2(s: str) -> str:
    n = len(s)
    if len(s) == 0:
        return ''
    isPalindrome = [False for col in range(n)]
    isPalindrome[n-1] = True
    posStart, posEnd = n-1, n-1
    
    
    for r in reversed(range(n)):
        for c in reversed(range(r, n)):
            if r == c: # base case 1
                isPalindrome[c] = True
            elif r + 1 == c and s[r] == s[c]: #base case 2
                isPalindrome[c] = True
                if c - r + 1 > posEnd - posStart + 1:
                    posStart, posEnd = r, c
            else:
                isPalindrome[c] = isPalindrome[c-1] and s[r] == s[c]
                if isPalindrome[c] and c - r + 1 > posEnd - posStart + 1:
                    posStart, posEnd = r, c
    
    return s[posStart:posEnd + 1]
    
    


# In[14]:


longestPalindromeV2("babab")


# In[46]:


#Longest palindromic subsequence

#best(i, j) -> the length of the longest palindromic subsequence using characters of s from i to j, inclusive.

def longestPalindromeSubseq(s: str) -> int:
    n = len(s)
    best = [[0 for col in range(n)] for row in range(n)]
    ans = 1
    # base case 1: single character is always a palindrome
    for i in range(n):
        best[i][i] = 1
    # base case 2: for length 2 substrings, palindrome only if same characters
    for i in range(n-1):
        best[i][i+1] = 1
        if s[i] == s[i+1]:
            best[i][i+1] = 2
            ans = 2
    
    # Other cases
    for xtrLtts in range(2, n):
        for stPos in range(n):
            endPos = stPos + xtrLtts
            if endPos < n:
                best[stPos][endPos] = best[stPos + 1][endPos - 1] 
                if s[stPos] == s[endPos]:
                    best[stPos][endPos] += 2 
                print(best[stPos][endPos], stPos, endPos)
                ans = max(ans, best[stPos][endPos])
    
    return ans
    
        


# In[54]:


longestPalindromeSubseq("bbbab")


# In[ ]:




