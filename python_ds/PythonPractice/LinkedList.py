"""
    A class that defines a LinkedList implementation
    Author:
        Jorge A
"""

class Node:
    # Creates a new Node with a given value, and no successor.
    def __init__(self, value = None, next = None):
        self.value = value
        self.next = next
    
    def hasNext(self):
        return self.next != None
    
class LinkedList:
    def __init__(self, head):
        self.head = Node(head)

    def addAtEnd(self, value):
        temp = self.head
        while(temp.hasNext()):
            temp = temp.next
        temp.next = Node(value)

    def printList(self):
        curr = self.head
        while(curr.hasNext()):
            print(curr.value, end = ", ")
            curr = curr.next
        print(curr.value)
        
### Testing
ll1 = LinkedList(24)
ll1.addAtEnd(32)
ll1.addAtEnd(64)
ll1.addAtEnd(128)

ll1.printList()

