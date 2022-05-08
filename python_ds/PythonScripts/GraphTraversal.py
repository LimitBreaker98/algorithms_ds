#!/usr/bin/env python
# coding: utf-8

# ### Graph algorithms and tree algorithms, ideas
# #### Author: Jorge A

# In[66]:


from typing import List
from collections import deque
## Defining a graph as an adjacency list
graph = [[2], [2,3,4], [0,1], [3], [1,5], [4,6], [5]]


# In[70]:


class GraphTraversal:
    def __init__(self, graph: List[List[int]]):
        self.visited = [False for _ in graph]
        self.graph = graph
        
    def dfs(self, src: int) -> None:
        self.visited[src] = True
        print(src)
        for nei in self.graph[src]:
            if not self.visited[nei]:
                self.dfs(nei)
                
    def dfs_iter(self, src: int) -> None:
        stack = [src]
        while len(stack):
            curr_node = stack.pop()
            print(curr_node)
            self.visited[curr_node] = True
            for nei in self.graph[curr_node]:
                if not self.visited[nei]:
                    stack.append(nei)
    
    def reset_visited(self):
        self.visited = [False for _ in graph]
        
    def print_dfs(self, src: int):
        traversals.dfs(src)
        traversals.reset_visited()

    def print_dfs_iter(self, src: int):
        traversals.dfs_iter(src)
        traversals.reset_visited()
    


# In[71]:


traversals = GraphTraversal(graph)
traversals.print_dfs(0)


# In[72]:


traversals.print_dfs_iter(0)


# In[55]:


"""
    Trees are special graphs with n nodes, n-1 edges, and a single connected component. In other words, they are acyclic. 
"""
class TreeTraversal:
    def __init__(self, graph: List[List[int]]):
        self.visited = [False for _ in graph]
        self.graph = graph
    


# In[56]:





# In[ ]:




