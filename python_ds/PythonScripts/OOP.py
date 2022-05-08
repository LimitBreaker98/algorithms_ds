#!/usr/bin/env python
# coding: utf-8

# ## Objects in Python
# 
# ### Defining classes 

# In[15]:


"""
    A class to model furniture. This will be the base clase from which diverse objects will inherit from.

"""

class Furniture:
    ## attributes without "self", declared outside of __init__, are CLASS ATTRIBUTES.
    ## These are Attributes that an instance can access, but are the same for all instances of the class.
    ## Also, one does not need an instance to create them.
    
    num_of_created_items = 0
    num_of_sold_items = 0
    
    # Initializing method for an instance, creates an instance. 
    def __init__(self, price, color, name, f_type = "generic"):
        ## instance attributes, these belong to every instance. Not shared between instances.
        self.price = price
        self.color = color
        self.furniture_type = f_type
        self.name = name
        Furniture.count_new_item()
    
    # instance method, operates over instance attributes. 
    def get_price(self):
        return self.price
    
    def get_color(self):
        return self.color
    
    ## Modifies an instance attribute. 
    def set_color(self, color):
        self.color = color
        
    def set_price(self, price):
        self.price = price
        
    ## Dunder or magic methods for instances.
    def __str__(self):
        return f"Name: {self.name}. Price: {self.price}. Color: {self.color}. Furniture Type: {self.furniture_type}"
    
    def __repr__(self): ## To print in interactive mode
        return self.__str__()
    
    ## CLASS METHODS. METHODS THAT DON'T NEED AN INSTANCE TO OPERATE ON.
    ## cls is similar to self. Denotes that this is a class method.
    @classmethod
    def num_created_items(cls):
        return cls.num_of_created_items
    
    @classmethod
    def num_sold_items(cls):
        return cls.num_of_sold_items
    
    @classmethod
    def count_new_item(cls):
        cls.num_of_created_items += 1
    
        
    
    


# In[18]:


generic_furniture = Furniture(0, None, None)


# In[19]:


print(generic_furniture)


# ### Inheritance
# 
# #### Specific subtypes of furniture can inherit from the base class Furniture.

# In[20]:


## Chair is a class which inherits from Furniture
class Chair(Furniture):
    
    def __init__(self, price, color, name, f_type, num_legs, rigidness, fabric):
        super().__init__(price, color, name, f_type)
        self.num_legs = num_legs
        self.rigidness = rigidness ## hard, soft, med
        self.fabric = fabric
        Furniture.count_new_item()
    
    def get_details(self):
        return f"Rigidness: {self.rigidness}. Number of Legs = {self.num_legs}. Fabric: {self.fabric}"


# In[32]:


gamer_chair = Chair(200000, "Blue", "Type95 RazerChair", "Chair", 4, "Very Soft", "Wool")


# In[33]:


print(isinstance(gamer_chair, Chair))
print(isinstance(gamer_chair, Furniture))


# In[34]:


print(gamer_chair.get_details())
print(gamer_chair)


# In[2]:


from collections import deque


# In[3]:


x = deque()


# In[5]:


x.append(1)


# In[6]:


x.append(2)


# In[7]:


print(x)


# In[9]:


x[1]


# In[ ]:




