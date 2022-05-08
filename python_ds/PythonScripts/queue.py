#!/usr/bin/env python
# coding: utf-8

# In[29]:


## Circular Queue Implementation
## Author: Jorge A
## Inspired by LeetCode Circular Queue Implementation Question


class Node:
    def __init__(self, value, prev, nxt):
        self.value = value
        self.next = nxt
        self.prev = prev
        


class MyCircularQueue:
    
    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the  max size of the queue to be k.
        """
        self.maxSz = k
        self.first = None
        self.last = None
        self.sz = 0

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if not self.isFull():  
            if self.isEmpty():
                self.first = self.last = Node(value, None, None)
            else:
                self.last.next = Node(value, self.last, self.first) ## make it circular
                self.last = self.last.next
            self.sz += 1
            return True
        return False
            
    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        
        self.first = self.first.next
        self.last.next = self.first
        if self.sz > 1:
            self.first.prev = self.last
        self.sz -= 1
        return True

    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.isEmpty():
            return -1
        return self.first.value

    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        if self.isEmpty():
            return -1
        return self.last.value
        

    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        return self.sz == 0
        

    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        return self.sz == self.maxSz
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()


# In[30]:





# In[ ]:





# In[ ]:




