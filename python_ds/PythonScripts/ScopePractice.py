#!/usr/bin/env python
# coding: utf-8

# In[55]:


#Scope practice


# In[1]:


def f():
    s = 1
    for i in range(4):
        s = i + 1
    print(s)


# In[2]:


f()


# In[11]:


def f2():
    a = [1,2,3]
    for i in range(3):
        a.append(a[i])
    a[1] = 3
    print(a)


# In[12]:


f2()


# In[22]:


#keyword global
#used when a function requires access to a variable declared in a global scope.

x = 3

def f():
    global x ## without this, the function breaks
    print(x)
    x = 32
    print(x)


# In[23]:


f()
print(x) # global variable was modified


# In[35]:


arr = [1,2,3]
def f():
    global arr # try commenting this.
    arr = [9]
    arr.append(2)
    print(arr)
f()
print(arr)


# In[46]:


#Priority queue easy implementation
#python provides heapq module, which has functions to heapify a normal python list!
import heapq

heap = [9,5,7,3,1,2,4,6,10,8]
heapq.heapify(heap)

for i in range(3):
    heapq.heappush(heap, 5)
    


# In[47]:


print(heap)


# In[49]:


while len(heap):
    print(heapq.heappop(heap))


# In[54]:


#MaxPQ implementation
heap = [0,2,-3,7,5,44]
heapq._heapify_max(heap)
print(heap)

while len(heap):
    print(heapq._heappop_max(heap))
    


# In[ ]:




