#!/usr/bin/env python
# coding: utf-8

# ### Sortings in python
# #### Author: Jorge A (LimitBreaker98)
# 

# In[17]:


#MergeSort, recursive
from typing import List
def merge(list1: List[int], list2: List[int]):
    i, j = 0, 0
    merged = []
    while i < len(list1) and j < len(list2):
        if list1[i] <= list2[j]:
            merged.append(list1[i])
            i += 1
        else:
            merged.append(list2[j])
            j += 1
    ## here, we have some left over elements in either list1 or list2
    merged.extend(list1[i:])
    merged.extend(list2[j:])
    return merged

def merge_sort(nums: List[int]):
    if len(nums) == 1:
        return nums
    mid = len(nums)//2
    left_part = merge_sort(nums[0:mid])
    right_part = merge_sort(nums[mid:])
    
    return merge(left_part, right_part)


# In[18]:


merge_sort([1,3,5,7,9,2,4,6,8])


# In[ ]:




