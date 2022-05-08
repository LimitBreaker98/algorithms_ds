class LinkedList:
    
    ## 2 underscores in front means its hidden except for the LinkedList class
    class __Node:
        def __init__(self, item, next = None):
            self.item = item
            self.next = next
        
        def get_next(self):
            return self.next
    
        def get_item(self):
            return self.item

        def set_item(self, newItem):
            self.item = newItem

        def set_next(self, newNext):
            self.next = newNext
        
        def __str__(self):
            return str(self.item)
    
    class __LinkedListIterator:
        
        def __init__(self, head):
            self.current = head.next
            
        def __iter__(self):
            return self
        
        def __next__(self):
            if not self.current:
                raise StopIteration
            else:
                val = self.current.get_item()
                self.current = self.current.get_next()
                return val
    
    ## implement next 2 methods to make linkedList iterable!
    def __next__(self):
        if (self.first):
            val = self.first
            self.first = self.first.next
            return val
        else: 
            raise StopIteration

    def __iter__(self):
        return LinkedList.__LinkedListIterator(self.first)
        
    def __str__(self):
        curr = self.first.next
        rep = ["("]
        while(curr):
            if (curr.next):
                rep.append(str(curr.item) + " -> ")
            else: 
                rep.append(str(curr.item) + ")")
            curr = curr.next
        return "".join(rep) ## Fastest string concat!
        
    def append(self, newNode):
        self.last.set_next(newNode)
        self.last = self.last.next
        self.sz += 1
    
    def __len__(self):
        return self.sz
    
    def __init__ (self, contents=[]):
        self.first = self.last =  LinkedList.__Node(None, None)
        self.sz = 0
        self.curr = self.first
        
        for e in contents:
            self.append(LinkedList.__Node(e))
        