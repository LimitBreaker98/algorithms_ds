class Node: 
    def __init__(self, value, next = None, prev = None):
        self.value = value 
        self.next = next
        self.prev = prev
    
    def hasNext(self):
        return self.next != None
    
    def hasPrev(self):
        return self.prev != None
    
class DoublyLinkedList: 
    def __init__(self, head):
        self.head = Node(head)
        self.last = self.head

    def addAtEnd(self, value):
        temp = self.head
        while(temp.hasNext()):
            temp = temp.next
        last = Node(value)
        temp.next = last
        last.prev = temp
        self.last = last
    
    def printList(self):
        curr = self.head
        while(curr.hasNext()):
            print(curr.value, end = ", ")
            curr = curr.next
        print(curr.value)

    def printReversedList(self):
        curr = self.last
        while(curr.hasPrev()):
            print(curr.value, end = ", ")
            curr = curr.prev
        print(curr.value)

# Testing
head = int(input("Tell me the head number of the list: "))
sizeOfList = int(input("How many elements do you want to add? "))
l = DoublyLinkedList(head)
while sizeOfList > 0:
    curr = int(input("Insert a number: "))
    l.addAtEnd(curr)
    sizeOfList -= 1

l.printList()
l.printReversedList()


        