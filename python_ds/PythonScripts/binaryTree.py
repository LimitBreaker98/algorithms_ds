#!/usr/bin/env python
# coding: utf-8

# # Binary Tree Implementation
# ### Author: Jorge A Esguerra A (LimitBreaker98)

# In[2]:


from collections import deque

'''
    Node class representing the nodes of a Binary Tree.
    Repeated values are handled by the count attribute of the node. It represents how many times the node's value has been added to the tree.
'''
class Node:
    def __init__(self, val, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
        self.count = 1
        
    def __str__(self):
        return f"(val: {self.val}, cnt: {self.count})"
    
    def __repr__(self): ## To print in interactive mode
        return self.__str__()

'''
    The DS that defines a Binary Tree. Objects of this class have a reference to the head Node of the binary tree.
'''

class BinaryTree:

    def __init__(self, val):
        self.head = Node(val)
    
    def insert(self, val):
        parentNode = self.findParent(val)
        if (val < parentNode.val):
            parentNode.left = Node(val)
        elif (val > parentNode.val):
            parentNode.right = Node(val)
        else:
            parentNode.count += 1
            
    def findParent(self, val):
        
        '''
        Finds the parent node of the value val that we are adding to the BT.
        If val is already in the BT, it returns the corresponding Node.
        '''
        def findParentHelper(prev, curr, val):
            if not curr:
                return prev
            if curr.val == val:
                return curr
            if val < curr.val:
                return findParentHelper(curr, curr.left, val)
            if val > curr.val:
                return findParentHelper(curr, curr.right, val)
        prev = curr = self.head
        parent = findParentHelper(prev, curr, val)
        return parent
        
    
    '''
        Tries deleting the corresponding Node of the value val. 
            - If said Node is not in the tree, the tree is not modified.
            - If said Node has a count > 1, the count is reduced by 1
            - If said Node has a count == 1, the node is deleted
    '''
    def delete(self, val):
        parentNode = self.findParent(val)
        if (parentNode.val == val):
            pass
    
    '''
        Returns a list containing the Pre-Order Traversal, calculated Recursively:
        PreOrder is: root, left, right
    '''
    def preOrder(self):
        l = []
        def preOrderHelper(curr):
            l.append(curr)
            if (curr.left): 
                preOrderHelper(curr.left)
            if (curr.right): 
                preOrderHelper(curr.right)
        
    
        preOrderHelper(self.head)
        return l
    
    '''
        Returns a list containing the Post-Order Traversal, calculated Recursively:
        PostOrder is: left, right, root
    '''
    
    def postOrder(self):
        l = []
        
        def postOrderHelper(curr):
            if (curr.left):
                postOrderHelper(curr.left)
            if (curr.right):
                postOrderHelper(curr.right)
            l.append(curr)
        postOrderHelper(self.head)
        return l
    
    '''
        Returns a list containing the In-Order Traversal, calculated Recursively:
        In-Order is: left, root, right
    '''
    
    def inOrder(self):
        l = []
        def inOrderHelper(curr):
            if (curr.left):
                inOrderHelper(curr.left)
            l.append(curr)
            if (curr.right):
                inOrderHelper(curr.right)
        inOrderHelper(self.head)
        return l
    
    '''
        Returns a list containing the BFS Traversal of the tree.
        Format: 
        [
          [3],
          [9,20],
          [15,7]
        ]
    '''
    def BFS(self):
        myQueue = deque()
        myQueue.append(self.head)
        l = []
        while (len(myQueue)):
            levelSz = len(myQueue) ## cuantas veces hacer pop, es como 2 pointers ish.
            l.append([])
            for i in range(levelSz):
                curr = myQueue.popleft()
                l[-1].append(curr.val)
                if (curr.left):
                    myQueue.append(curr.left)
                if (curr.right):
                    myQueue.append(curr.right)
        return l
    
    


# In[3]:


'''
    Testing:
    
    The following will be the tree used for testing
    
                    F
              B          G
           A     D         I
               C   E     H
               
    Results should be:
    PreOrder = [F, B, A, D, C, E, G, I, H]
    
    PostOrder = [A, C, E, D, B, H, I, G, F]
    
    InOrder = [A, B, C, D, E, F, G, H, I]
    
    BFS = ['F', 'B', 'G', 'A', 'D', 'I', 'C', 'E', 'H'] (could be different but this is what the implementation should return)
'''
testTree = BinaryTree('F')
testTree.insert('B')
testTree.insert('A')
testTree.insert('D')
testTree.insert('C')
testTree.insert('E')
testTree.insert('G')
testTree.insert('I')
testTree.insert('H')


# In[4]:


print([node.val for node in testTree.preOrder()])


# In[152]:


print([node.val for node in testTree.postOrder()])


# In[153]:


print([node.val for node in testTree.inOrder()])


# In[154]:


print(testTree.BFS())


# In[ ]:




