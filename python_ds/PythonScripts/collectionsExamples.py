#!/usr/bin/env python
# coding: utf-8

# ## Examples using the collections built in library:
# 
# ### Contents:
# 
# #### 1. deque

# In[101]:


## Implement an efficient way to calculate the moving average of a stream of data. 
## the number of elements in the moving average is given

from collections import deque
from typing import List

class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.window = deque([], size)
        self.sum = 0
        self.maxlen = size

    def next(self, val: int) -> float:
        if (self.maxlen == len(self.window)):
            self.sum -= self.window.popleft()
        self.window.append(val) ## since fixed size, it pops from left if full but IT DOESNT RETURN IT
        self.sum += val
        return self.sum / len(self.window)
        


# In[151]:



def BFS(rooms: List[List[int]], queue) -> None:
    INF = int(1 << 31) - 1
    def validCoords(row, col, maxRow, maxCol) -> bool:
        return 0 <= row <= maxRow and 0 <= col <= maxCol and rooms[row][col] != -1 and rooms[row][col] != -1 and rooms[row][col] == INF
    
    maxRow = len(rooms) - 1
    maxCol = len(rooms[0]) - 1

    currLevel = 0
    currSz = len(queue)
    while len(queue):
        
        currR, currC = queue.popleft()
        
        rooms[currR][currC] = currLevel
        
        if validCoords(currR + 1, currC, maxRow, maxCol):
            queue.append((currR + 1, currC))
            rooms[currR + 1][currC] = currLevel + 1
            
        if validCoords(currR, currC + 1, maxRow, maxCol):
            queue.append((currR, currC + 1))
            rooms[currR][currC + 1] = currLevel + 1
            
        if validCoords(currR - 1, currC, maxRow, maxCol):
            queue.append((currR - 1, currC))
            rooms[currR - 1][currC] = currLevel + 1
            
        if validCoords(currR, currC - 1, maxRow, maxCol):
            queue.append((currR, currC - 1))
            rooms[currR][currC - 1] = currLevel + 1

        currSz -= 1

        if currSz == 0:
            currLevel += 1
            currSz = len(queue)
            print("level ", str(currLevel), queue)



def wallsAndGates(rooms: List[List[int]]) -> None:
    """
    Do not return anything, modify rooms in-place instead.
    """
    sources = deque()
    for row in range(len(rooms)):
        for col in range(len(rooms[0])):
            if rooms[row][col] == 0: ## multisourced BFS
                sources.append((row,col))
    print("level ", str(0), sources)      
    BFS(rooms, sources)
    
    for row in rooms:
        print(row)


# In[152]:


INF = int(1 << 31) - 1
mat = [
    [INF , -1,  0,  INF],
    [INF, INF, INF,  -1],
    [INF,  -1, INF,  -1],
      [0,  -1, INF, INF],
]


# In[153]:


wallsAndGates(mat)


# In[ ]:





# In[1]:


import math
listita = [1,2,3]
listaGrande = []

k = 100
for i in range(3):
    listita.append(k)
    k += 3
    listaGrande.append(listita)
    print(listaGrande)


# In[2]:


print(listaGrande)


# In[ ]:





# In[ ]:




