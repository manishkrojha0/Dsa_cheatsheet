# implemntation of LRU cache
# steps to perform
# we will use doubly linked list along with a dictionary to implement this feature
# doubly ll will take constant time to delete and insert element at front and end
# we will perform these operations
# 1. insert in cache - the element will be inserted in the front which suggests the most recently used.
# 2. search in cache - if element present in cache we will insert that element at the front and if it is
#    not present in the cache we will add it and then insert it at the front and will store the key in map or dict.

class Node:
    
    def __init__(self, data=None, key=None):
        self.data = data
        self.key = key
        self.prev = None
        self.next = None

class LRUCache:
    
    def __init__(self, size):
        self.size = size
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head
        self.cache = {}
    
    def __add_node(self, node):
        self.head.next.prev = node
        node.next = self.head.next
        self.head.next = node
        node.prev = self.head
    
    def __remove_node(self, node):
        self.head.next = node.next
        node.next.prev = self.head
        
    
    def __move_to_head(self, node):
        self.__remove_node(node)
        self.__add_node(node)
    
    def _pop_tail(self, node):
        tail_node = self.tail.prev
        self.__remove_node(tail_node)
        return tail_node
    
    def search(self, x):
        if x not in self.cache:
            new_node = Node(data=x)
            self.__add_node(new_node)
            self.cache[x] = new_node
            return False
        else:
            node = self.cache[x]
            self.__move_to_head(node)
            return True
    
    def put(self, x):
        if x not in self.cache:
            if len(self.cache) == self.size:
                node = self.__remove_node()
                del self.cache[node.data]
            new_node = Node(data=x)
            self.__add_node(new_node)
            self.cache[x] = new_node
        else:
            node = self.cache[x]
            self.__move_to_head(node)


obj = LRUCache(3)
obj.put(4)
obj.put(5)

print(obj.search(2))
print(obj.search(2))
            
    
    
    
    
                
            
