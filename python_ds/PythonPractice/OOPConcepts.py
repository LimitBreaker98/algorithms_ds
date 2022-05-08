"""
    Finally learning how objects are written in Python 3.

    Author:
    - Jorge A (limitl3ss).
"""

"""
    A class to represent a Dog
"""


class Dog: 
    def __init__(self, name, age, favorite_food):
        # These are called INSTANCE ATTRIBUTES
        self.name = name
        self.age = age
        self.favorite_food = favorite_food
    
    def get_age(self):
        return self.age

    """ 
        Similar to Java equals method for all objects.
        If the __eq__ is not defined for a class, the value NotImplemented is returned.
    """
    def __eq__(self, dog2):
        return isinstance(dog2, Dog) and self.name == dog2.name

    """
        Other Rich comparators include the following
    """
    # Less than or equal (replace with ge for greater than or equal)
    def __le__(self, value):
        pass
    # Less than (replace with gt for greater than). (STRICT)
    def __lt__(self, value):
        return super().__gt__(value)

dog1 = Dog("Jorge", 20, "Potatoes")
dog2 = Dog("Jorge", 20, "lol")

print(dog1.__eq__(dog2))


