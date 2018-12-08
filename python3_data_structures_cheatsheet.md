
# Hash set

Taken from [LeetCode's Hash Table overview](https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1130/).

```python
# 1. initialize the hash set
hashset = set() 

# 2. add a new key
hashset.add(3)
hashset.add(2)
hashset.add(1)

# 3. remove a key
hashset.remove(2)

# 4. check if the key is in the hash set
if (2 not in hashset):
    print("Key 2 is not in the hash set.")

# 5. get the size of the hash set
print("Size of hashset is:", len(hashset)) 

# 6. iterate the hash set
for x in hashset:
    print(x, end=" ")
print("are in the hash set.")

# 7. clear the hash set
hashset.clear()                         
print("Size of hashset:", len(hashset))
```

# Hash map

Taken from [LeetCode's Hash Table overview](https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1129/).

```python
# 1. initialize a hash map
hashmap = {0 : 0, 2 : 3}

# 2. insert a new (key, value) pair or update the value of existed key
hashmap[1] = 1
hashmap[1] = 2

# 3. get the value of a key
print("The value of key 1 is: " + str(hashmap[1]))

# 4. delete a key
del hashmap[2]

# 5. check if a key is in the hash map
if 2 not in hashmap:
    print("Key 2 is not in the hash map.")

# 6. both key and value can have different type in a hash map
hashmap["pi"] = 3.1415

# 7. get the size of the hash map
print("The size of hash map is: " + str(len(hashmap)))

# 8. iterate the hash map
for key in hashmap:
    print("(" + str(key) + "," + str(hashmap[key]) + ")", end=" ")
print("are in the hash map.")

# 9. get all keys in hash map
print(hashmap.keys())

# 10. clear the hash map
hashmap.clear();
print("The size of hash map is: " + str(len(hashmap)))
```

# Trees implementation

```python
# standard definition of a tree node class
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```

# Linked List implementation

More @ [TutorialsPoint](https://www.tutorialspoint.com/python/python_linked_lists.htm).

```python
class Node:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextval = None

class SLinkedList:
    def __init__(self):
        self.headval = None

list1 = SLinkedList()
list1.headval = Node("Mon")
e2 = Node("Tue")
e3 = Node("Wed")

# Link first Node to second node
list1.headval.nextval = e2

# Link second Node to third node
e2.nextval = e3
```

# Graph implementation

[Succinct implementation of a graph from @mVCHr on StackOverflow:](https://stackoverflow.com/a/30747003)

```python
from collections import defaultdict

class Graph(object):
    """ Graph data structure, undirected by default. """

    def __init__(self, connections, directed=False):
        self._graph = defaultdict(set)
        self._directed = directed
        self.add_connections(connections)

    def add_connections(self, connections):
        """ Add connections (list of tuple pairs) to graph """

        for node1, node2 in connections:
            self.add(node1, node2)

    def add(self, node1, node2):
        """ Add connection between node1 and node2 """

        self._graph[node1].add(node2)
        if not self._directed:
            self._graph[node2].add(node1)

    def remove(self, node):
        """ Remove all references to node """

        for n, cxns in self._graph.iteritems():
            try:
                cxns.remove(node)
            except KeyError:
                pass
        try:
            del self._graph[node]
        except KeyError:
            pass

    def is_connected(self, node1, node2):
        """ Is node1 directly connected to node2 """

        return node1 in self._graph and node2 in self._graph[node1]

    def find_path(self, node1, node2, path=[]):
        """ Find any path between node1 and node2 (may not be shortest) """

        path = path + [node1]
        if node1 == node2:
            return path
        if node1 not in self._graph:
            return None
        for node in self._graph[node1]:
            if node not in path:
                new_path = self.find_path(node, node2, path)
                if new_path:
                    return new_path
        return None

    def __str__(self):
        return '{}({})'.format(self.__class__.__name__, dict(self._graph))
```
