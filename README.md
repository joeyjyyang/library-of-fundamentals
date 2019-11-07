# library-of-fundamentals
Implementations of essential data structures and algorithms.

## Background

### What is a Data Structure?
- Way of organizing data so it can be used (i.e. accessed, queried, updated, etc.) effectively.
- Essential ingredient in creating fast and powerful algorithms.
- Helps manage and organize data (in a natural way).
- Makes code cleaner and easier to understand.

### What is an Abstract Data Type?
- Abstraction of a data structure which only provides the interface to which the data structure must adhere to.
	- The interface does not give any specific details about how something should be implemente or in what programming language. 
- i.e. Lists, Stacks, Queues, Priority Queues, Maps, Trees, Graphs, etc.

## Computational Complexity Analysis
- Runtime (time) and memory (space) requirements for algorithms to execute.

### Big-O Notation
- Standardized method of representing time and space complexities.
- Gives an upper bound of the complexity in the worse case, helping quantify performance as the input size n becomes arbitrarily large (theoretically to infinity; thus, ignore constants and multiplicative factors). 

#### Time Complexities and Big-O Notations 
- Constant time: O(1).	
	- i.e. access array element by index.
- Logarithmic time: O(log(n)).
	- i.e. binary search.
- Linear time: O(n).
	- i.e. searching for element in unsorted array.
- Linearithmic time: O(nlog(n)).
	- i.e. mergesort. 
- Quadratic time: O(n^2).
	- i.e. nested for loops.
- Cubic time: O(n^3).
	- i.e. nested for loops.
- Exponential time: O(b^n), b > 1.
	- i.e. finding all subsets of a set.
- Factorial Time: O(n!).
	- i.e. finding all permutations of a string.

## Data Structures

### Arrays (Static and Dynamic)

#### Array Usages
- Storing and accessing sequential data.
- Temporarily storing objects.
- Used as buffers for I/O routines.
- Lookup tables and inverse lookup tables.
- Hack to return multiple values from a function (via pointer).
- Memoization (caching) results in dynamic programming problems.

#### Static Arrays
- Fixed length container containing n indexable elements.
- Given as contiguous chunks of memory; memory addresses of elements are adjacent.

#### Dynamic Arrays
- Can grow and shrink in size.
- Typically implemented using Static Arrays.
	- i.e. create new array of double size and copy elements from old array upon exceeding capacity.
		- Exponential growth rate (i.e. growth factor of 2) to keep time complexity of insertions constant O(1).
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/dynamicarray/DynamicArray.java

#### Array Time Complexities
| Operations | Static Arrays | Dynamic Arrays |
|            | Worst Case    | Worst Case     |
| ---------- | ------------- | -------------- |
| Access     | O(1)          | O(1)           |
| Search     | O(n)          | O(n)           |
| Insertion  | N/A           | O(n)           |
| Appending  | N/A           | O(1)           |
| Deletion   | N/A           | O(n)           |


### Linked Lists
- Sequential list of nodes that hold data which point to other nodes also containing data.
	- Each node points to the next node.
	- Final node points to null (null reference).
- References/pointers to the head (first) node and tail (last) node are kept.
- Nodes are objects containing data and pointer(s), and usually implemented as classes or structs.
- Important to deallocate (free) memory to prevent memory leaks when manually handling pointers.

#### Linked List Usages
- Implementing Lists, Queues, and Stacks abstract data types (due to great time complexities for adding and removing elements).
- Creating circular lists.
- Modelling real world objects such as trains.
- Used in separate chaining due handle collisions in Hashtable implementations.
- Implementing adjacency lists for Graphs.

#### Singly Linked Lists
- Each node only references/points to the next node.
	- Unable to easily access previous elements.

#### Doubly Linked Lists
- Each node contains two pointers; one references/points to the next node, and the other references/points the the previous node.
	- Enables backwards traversal; however, complex to implement and takes up twice the memory of Singly Linked Lists.
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/linkedlist/DoublyLinkedList.java

#### Linked Lists (Worst Case) Time Complexities
| Operations       | Singly Linked Lists | Doubly Linked Lists |
|                  | Worst Case          | Worst Case          |
| ---------------- | ------------------- | ------------------- |
| Search           | O(n)                | O(n)                |
| Insert at Head   | O(1)                | O(1)                |
| Insert at Tail   | O(1)                | O(1)                |
| Remove at Head   | O(1)                | O(1)                |
| Remove at Tail   | O(n)                | O(1)                |
| Remove in Middle | O(n)                | O(n)                |   

### Stacks
- One-ended linear data structure which models a real world stack by having two primary operations, namely push and pop.
- Last In First Out (LIFO).
- Often implemented using Arrays, Linked Lists, or Queues.
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/stack/Stack.java

#### Stack Usages
- Undo mechanisms in text editors.
- Compiler syntax checking for matching brackets and braces.
	- Checking the validity of a given bracket sequence.
- Modelling a pile of books or plates, or even games such as the Tower of Hanoi.
- Used behind the scenes to support recursion by keeping track of previous function calls.
- Depth First Search (DFS) traversal on a Graph in Graph Theory.

#### Stack (Worst Case) Time Complexities
| Operations | Worst Case |
| ---------- | ---------- | 
| Pushing    | O(1)       |       
| Popping    | O(1)       |        
| Peeking    | O(1)       |         
| Searching  | O(n)       |    
| Size       | O(1)       |         

### Queues
- A linear data structure which models real world queues by having two primary operations, namely enqueue (adding element to end) and dequeue (removing element from front).
- First In First Out (FIFO).
- Often implemented using Arrays, Linked Lists, or Stacks.
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/queue/Queue.java

#### Queue Usages
- Any waiting line models.
- Can be used to efficiently keep trakc of the x most recently added elements.
- Web server request management where you want first come first serve.
- Breadth First Search (BFS) traversal on a Graph in Graph Theory.

#### Queue Time Complexities
| Operations | Worst Case | 
| ---------- | ---------- | 
| Enqueue    | O(1)       |       
| Dequeue    | O(1)       |      
| Peeking    | O(1)       |          
| Contains   | O(n)       |    
| Removal    | O(n)       | 
| Is Empty   | O(1)       | 

### Priority Queues
- An abstract data type that operates similar to a normal queue except that each element has a certain priority. 
	- The priority of the elements determine the order in which elements are removed.
- Only supports comparable data, meaning data inserted must be able to be ordered in some way either from least to greatest or greatest to least.
	- Ensures the possibility of assigning relative priorities to each element.
- Typically implemented using Heaps (Min or Max), since Heaps provide the best possible time complexity for operations.
	- For simplicity, the Binary Heap is commonly used.
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/priorityqueue/BinaryHeap.java

#### Heaps
- A Tree based data structure that satisfies the heap invariant that if A is a parent node of B, then A is ordered with respect to B for all nodes A, B in the heap.
	- i.e. the parent node is always less than or equal to, or greater than or equal to, its child nodes for all nodes.
- Form the canonical underlying data structure for Priority Queues.
	- Important not to be confused with Priority Queues, since Priority Queues are abstract data types and can be implemented using other methods (i.e. unsorted lists).
- Heaps must be Trees; therefore, Heaps cannot contain cycles.
- If all elements are known (i.e. stored in Binary Tree or Array), a Priority Queue can be created in linear O(n) time using the Heapify operation.

#### Binary Heaps
- A Binary Tree that supports the heap invariant.
- Each node has exactly two children (including leaf nodes which have null referenced children).
- Canonical method of representing Binary Heaps is to use Arrays.
	- Elegent and fast, as new elements/nodes are appended to the last index of the array.
	- Root node is stored at the first index.
	- Traversal of array and Binary Heap goes from left to right. 
	- Provides easy access to nodes (i.e. zero based indexing).
		- i is the parent node index in the array.
		- 2i + 1 is the left child index.
		- 2i + 2 is the right child index.

#### Inserting Elements into Binary Heaps
- The structure of a Binary Heap used for a Priority Queue should always be in the form of a Complete Binary Tree to maintain an insertion point.
	- Every level, except possibly the last level, is filled and all nodes are as far left as possible. 
		1. Nodes are inserted at the bottom level as far left as possible to maintain this property.
		2. The inserted node is bubbled up (swimming) until it no longer violates the heap invariant and is in the correct position.

#### Removing Elements from Binary Heaps

##### Removing the Root Node (Polling)
- Generally want to always remove the root node (polling), which has the highest priority.
	- Do not need to search, as the root node has index 0 in the array.
	1. Before removing root node, it is swapped with the last node of the Binary Heap (in the last index of the array).
	2. After the root node is removed, the swapped node is bubbled down (sinking) to satisfy the heap invariant.
		- Remember to swap with left child node when bubbling down if two child nodes have the same value.

##### Removing Elements in O(n)
- When removing nodes which are not the root node, the swap (with last node), remove, then bubble idiom is still used; however, could either bubble up (swim) or bubble down (swim).
- Inefficiency from performing a linear search of the index of the node to be removed before swapping. 

##### Removing Elements in O(log(n))
- Leverages a Hashtable for easy lookup of where the node to be removed is indexed at in the array.
	- Hashtables provide constant time O(1) lookup and update for a mapping from a key (node value) to a value (node index).
- To deal with multiple nodes having the same value, instead of mapping one value to one position, map one value to multiple positions (at each index where duplicate exists).
	- Using a Set or Tree Set of indexes (value) for which a particular node value (key) maps to.
	- Swapping (and removal) occurs in Tree (for nodes) but also in the Hashtable (for indexes).
	- Note that it does not matter which duplicate node is removed, as long as the heap invariant is satisfied in the end. 

#### Priority Queue Usages
- Graph Theory algorithms.
- Certain implementations of Dijkstra's Shortest Path algorithm to fetch the next nodes to explore.
- Anytime the "next best" or "next worst" element needs to be dynamically fetched.
- Huffman coding (lossless data compression).
- Best First Search (BFS) algorithms such as A* (A star) to continuously grab the next most promising node in a Graph during traversal.
- Used by Minimum Spanning Tree (MST) algorithms on Directed Graphs.

#### Priority Queue (Worst Case) Time Complexities
| Operations               | Worst Case |
| ------------------------ | ---------- | 
| Polling                  | O(log(n))  |          
| Peeking                  | O(1)       |           
| Adding                   | O(log(n))  |              
| Binary Heap Construction | O(n)       |       
| Naive Removing           | O(n)       |     
| Removing with Hash Table | O(log(n))  |     
| Naive Contains           | O(n)       |     
| Contains with Hash Table | O(1)       |                   

#### Min Heaps
- Parent node always has a lower value than its child nodes.

#### Max Heaps
- Parent node always has a greater value than its child nodes.

#### Min/Max Heap Conversion
- Important to be able to convert between Min Heaps and Max Heaps, since most programming languages only provide a standard Min Heap.
- Simply negate comparable (comparator operands, not equals) interface to convert.
	i.e. lex comparator for strings, where nlex is the negation.
- Alternative method for numbers is to negate the numbers as they are inserted into the Priority Queue, and negate them again when taking numbers out. 
	- Same effect as negating the comparator.

### Union Find (Disjoint Set)
- Data structure that keeps track of elements which are split into one or more disjoint sets.
- Two primary operations, find and union.
	- Find reports which subset/group the given element belongs to.
	- Union merges (unifies) two subsets together.

#### Union Find Usages
- Kruskal's Minimum Spanning Tree algorithm.
- Grid percolation.
- Network connectivity.
- Least common ancestor in trees.
- Image processing.

#### Union Find Time Complexities
| Operations         | Worst Case |
| ------------------ | ---------- | 
| Construction       | O(n)       |       
| Union              | a(n)       |      
| Find               | a(n)       |         
| Get Component Size | a(n)       |  
| Check if Connected | a(n)       |
| Count Components   | O(1)       |
- Amortized constant time a(n).
	- Nearly constant time O(n)

#### Kruskal's Minimum Spanning Tree
- A subset of the edges of a Graph which connect all vertices in the graph with the minimal total edge cost.
- Not necessarily unique.
- All edges must be sorted by ascending weight first.
- Traverse through sorted edges and look at the two nodes the edge belongs to.
	- If nodes already unified, do not include the edge; otherwise, include the edge and unify the nodes into the appropriate group.
- Algorithm terminates when every edge has been processed or all the vertices have been unified into a single group.
- Ignore and do not create edge for elements already in the same group to prevent cycles.
	- Use find operation to check which group(s) the elements belong to.
- Merge elements into same group if both elements are currently in different groups.
	- Use union operation to merge groups together efficiently.
	- Smaller group gets merged into larger group.

#### Union and Find Operations

##### Creating Union Find
- First construct a bijection (a mapping) between the n objects and the integers in range [0, n).
	- Random assignment, as long as one-to-one mapping.
	- Not necessary, but allows for construction of an array-based union find, which is efficient and easy to work with.
- Subsequently store Union Find information in an array.
	- Each index has an associated object (i.e. letter) which can be looked-up through mapping.
	- Each object initially points to itself, as the in

### Binary Search Trees

#### What is a Tree?
- Undirected graph which satisfies any of the following definitions:
	- An acyclic connected graphs.
	- A connected graph with N nodes and N-1 edges
	- A graph in which any two vertices are connected by exactly one path; otherwise, there is a cycle (another route to get to the node).
- The root node is the top-most node of the tree.
- A child node is a node extend from another node, while 
- Leaf nodes do not have children, and are at the bottom-most level of the tree.

#### Tree Usages
- Filesystems.
	- The parent of the root directory (node) is the root itself.

#### What is a Binary Tree?
- A tree for which every mode has at most two child nodes.

#### What is a Binary Search Tree?
- A Binary Tree that satisfies the Binary Search Tree invariant: left subtree has smaller elements and right subtree has larger elements.
	- Elements must be comparable to be ordered.
	- Invariant is modified depending on whether or not duplicates are allowed.
		- Binary Search Tree operations allow for duplicates; however, usually interested only in having unique elements inside the tree.
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/binarysearchtree/BinarySearchTree.java

#### Binary Search Tree Usages
- Implementation of some Map and Set abstract data types.
- Red Black Trees.
- AVL Trees.
- Splay Trees.
- Used to implementation binary heaps.
- Syntax Trees (used by compiler and calculators)
- Treap - a probabilistic data structure.

#### Binary Search Tree Time Complexities
| Operations | Average Case | Worst Case |
| ---------- | ------------ | ---------- |
| Insert     | O(log(n))    | O(n)       |
| Delete     | O(log(n))    | O(n)       |         
| Remove     | O(log(n))    | O(n)       |        
| Search     | O(log(n))    | O(n)       |            
- Worst case linear O(n) time is addressed using Balanced or Self-Balancing Binary Search Trees.

#### Inserting Elements into Binary Search Trees
- Start at root node, then begin comparing the element's value to the value stored in the node currently being considered, then:
	- Recurse down left subtree if less than (<) case.
	- Recurse down right subtree if greater than (>) case.
	- Handle finding a duplicate value if equal (=) case.
	- Create a new node if found a null leaf node (null reference).

#### Removing Elements from Binary Search Trees
- Can be seen as a two step process:
	1. Find the element to be removed (if it exists).
		- Traverse in accordance to Binary Search Tree invariant.
	2. Replace the node to be removed with its successor (if any) to maintain the Binary Search Tree invariant.
		- In the case where the node to be removed has both left and right child nodes (which may or may not be subtrees), there are two successors.
			- The successor can either be the largest value in the left subtree (dig as far right as possible) or the smallest value in the right subtree (dig as far left as possible). 
			- It is guaranteed that the successfor will not have two child nodes/subtrees.

#### Tree Traversals

##### Pre-Order, In-Order, and Post-Order Traversals 
- Naturally defined recursively.
- Depth-First Search (DFS) methods.
	- Make use of the call stack.
		- Pushing off recursive calls when the subtree of a node is visited.
- Begin traversal at root node.
- Differences in when the current parent node's value is printed relative to the recursive calls to child nodes.
	- Involves pushing the recursive traversal call off of the call stack for the child node that was just visited and recursing back up to parent node, before recursing back down again to next child node.

###### Pre-Order Traversal
- Print before recursive calls.
	- Prints the value of the current node, then traverse the left subtree, followed by the right subtree.

###### In-Order Traversal
- Print between recursive calls.
	- Traverse the left subtree, then print the value of the node, and continue traversing the right subtree.
- Note that with a Binary Search Tree, the values are printed in increasing order through inorder traversal.

###### Post-Order Traversal
- Print after recursive calls.
	- Traverse the left subtree, followed by the right subtree, then print the value of the node.
- The value of the root node is last to be print, as the entire left and right subtrees of the root node must be traversed through first and printed.

#### Level Order Traversal
- Naturally defined iteratively.
- Breadth-First Search (BFS) methods.
	- Make use of a queue as an auxiliary data structure.
		- Keeps track of the nodes left to explore.
		- Begin with the root node inside of the queue, and finish when the queue is empty.
		- At each iteration level, remove the current node from the queue, print the value of the current node, and add the left child and right child of the current node to the queue.
- Begin traversal at root node.
- Print the nodes as they appear one layer at a time.




## Unfinished
- Maps/Sets
	- Hash Tables
- Trees
	- Binary Search Trees
	- Tries (Prefix Trees)
- Heaps/Priority Queues
- Graphs

## Algorithms
- Traversal
	- Depth First Search (DFS)
	- Breadth First Search (BFS)
- Sorting
	- Quick Sort
	- Merge Sort
	- Bubble Sort
	- Insertion Sort
	- Selection Sort
- Sliding Window Technique
- Greedy Algorithms

## C++ STL Containers
- Sequence Containers
	- `std::array`
	- `std::vector`
	- `std::deque`
	- `std::list`
- Container Adaptors
	- `std::stack`
	- `std::queue`
	- `std::priority_queue`
- (Ordered and Unordered) Associative Containers
	- `std::set`
	- `std::unordered_set`
	- `std::map`
	- `std::unordered_map`
