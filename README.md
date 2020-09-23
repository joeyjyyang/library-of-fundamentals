# library-of-fundamentals
Implementations of essential data structures and algorithms.

# Data Structures

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
- Prefix Sum Arrays can be used on Static Arrays to optimize accessing the sum of data between certain ranges/intervals from linear O(n) time to constant O(1) time.
	- Flaw in that when updating a value in the original array, the entire Prefix Sum Array must be recalculated, which takes linear O(n) time.
		- Resolved using the Fenwick Tree/Binary Index Tree data structure.

#### Dynamic Arrays
- Can grow and shrink in size.
- Typically implemented using Static Arrays.
	- i.e. create new array of double size and copy elements from old array upon exceeding capacity.
		- Exponential growth rate (i.e. growth factor of 2) to keep time complexity of insertions constant O(1).
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/dynamicarray/DynamicArray.java

#### Array Time Complexities
|            | Static Arrays | Dynamic Arrays |
| ---------- | ------------- | -------------- |
| Operations | Worst Case    | Worst Case     |
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
- Used in separate chaining due handle collisions in Hash Table implementations.
- Implementing adjacency lists for Graphs.

#### Singly Linked Lists
- Each node only references/points to the next node.
	- Unable to easily access previous elements.

#### Doubly Linked Lists
- Each node contains two pointers; one references/points to the next node, and the other references/points the the previous node.
	- Enables backwards traversal; however, complex to implement and takes up twice the memory of Singly Linked Lists.
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/linkedlist/DoublyLinkedList.java

#### Linked Lists (Worst Case) Time Complexities
|                  | Singly Linked Lists | Doubly Linked Lists |
| ---------------- | ------------------- | ------------------- |
| Operations       | Worst Case          | Worst Case          |
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

##### Naively Removing Elements in Linear O(n) Time
- When removing nodes which are not the root node, the swap (with last node), remove, then bubble idiom is still used; however, could either bubble up (swim) or bubble down (swim).
- Inefficiency from performing a linear search of the index of the node to be removed before swapping. 

##### Removing Elements in Logarithmic O(log(n)) Time
- Leverages a Hash Table for easy lookup of where the node to be removed is indexed at in the array.
	- Hash Tables provide constant time O(1) lookup and update for a mapping from a key (node value) to a value (node index).
- To deal with multiple nodes having the same value, instead of mapping one value to one position, map one value to multiple positions (at each index where duplicate exists).
	- Using a Set or Tree Set of indexes (value) for which a particular node value (key) maps to.
	- Swapping (and removal) occurs in Tree (for nodes) but also in the Hash Table (for indexes).
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
	- Note that can be done iteratively; however, requires a stack (or multiple stacks) as an auxiliary data structure.
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

### Hash Tables
- Data structure that provides a mapping of key-value pairs using a technique called hashing.
	- Keys must be unique and hashable, but values can be repeated.
- Often used to track item frequencies.
	- i.e. Counting the number of times a word appears in a given text.
- Provides very fast insertion, lookup, and removal time for data of constant O(1) time (in average case) by using a hash function as a way to index into the hash table.
- Neither key nor value elements of a key-value pair can be null.
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/hashtable/HashTableQuadraticProbing.java

#### What is a Hash Function?
- A function that maps a key x to a whole number in a fixed range.
	- Determines the index in the Array where the key-value pair will be stored.
- mod (%) capacity will return an integer in the domain of [0, capacity) exclusive at the end.
	- i.e. hash function H(x), where H(x) = (x^2 - 6x + 9) mod 10 maps all integer keys x to the range [0,9] inclusive, where the capacity of the auxiliary Array is 10.
- Hash functions can also be defined for arbitrary objects such as strings, lists, tuples, multi-data objects, etc.
	- i.e. for a string s, let H(s) be a hash function that calculates the sum of ASCII values of characters in the string, and applies mod 50 to the sum.
		- Effectively converted a string to an integer number.
- Lookup can be done by computing the hash value of a key, and looking at the key-value pair stored at that hash value index.

##### Properties of Hash Functions
- If the hash values of x and y are equal H(x) = H(y), then x and y might be equal.
	- Need to explicitly check x against y.
- If the hash values of x and y are not equal H(x) != H(y), then x and y are certainly not equal.
- Comparing precomputed hash values takes constant O(1) time, and can speed up comparison of large objects (i.e. files) rather than slowly comparing the actual contents.
	- Note that hash functions for files are complicated hash functions called crytographic hash functions or checksums.
- It is critical that a hash function must be deterministic.
	- If H(x) = y, then H(x) must always produce y and never another value.
- Important to try and create a uniform hash function.

##### Hash Collisions
- Occurs when two x and y objects hash to the same value H(x) = H(y).
- Try to make uniform hash functions to minimize the number of hash collisions.
- Can be resolved using two popular methods:
	1. Separate Chaining
	2. Open Addressing

##### Hashable Keys
- To enforce deterministic hash functions, keys of type T must be immutable.
	- Hence, if a key of type T is immutable, and given a hash function H(k) defined for all keys k of type T, then a key of type T is hashable.

#### Hash Table Time Complexities
| Operations | Average Case | Worst Case |
| ---------- | ------------ | ---------- |
| Insertion  | O(1)         | O(n)       |
| Removal    | O(1)         | O(n)       |         
| Search     | O(1)         | O(n)       |
- Note that the constant O(1) time is attributed to hash tables is only true if the hash function is uniform.	

#### Separate Chaining
- One of many hash collision resolution strategies.
- Maintains an auxiliary data structure (usually a Linked List) to hold all different values which hashed to a particular value.
	- Bucket behaviour.
	- Each index position in the Array is a Linked List.
- Upon hash collision, a new node is appended to the Linked List at the hash value index.
- Items with the same hash value are distinguished based on their unique keys, as the key-value pairs are stored in each node.
- To maintain constant O(1) time, Hash Tables with a lot of elements and long Linked Lists should be rehashed and dispersed throughout a new Hash Table with larger capacity. 
	- Dependent on the Load Factor.
		- Load Factor = # Current Items / # Size 
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/hashtable/HashTableSeperateChaining.java

##### Removing Key-Value Pairs with Separate Chaining
- Apply lookup procedure, then simply remove the corresponding node from the Linked List at the hash value index.

#### Open Addressing
- Key-value pairs are stored in the Hash Table (Array) itself, as opposed to an auxiliary data structure (i.e. Linked List) in Separate Chaining.
- Must be careful about Load Factor, or the size of the Hash Table vs. the number of elements currently stored inside. 
	- The Hash Table size must be increased (usually exponentially, i.e. double) once the Load Factor exceeds a specified threshold.
- Upon hash collision, use a probing sequence P(x) to determine an appropriate offset position.
	- This process is repeated until an unoccupied slot is found.
		- i.e. collision at H(k), probe forward until empty position found.
- Extremely sensitive to the hashing function and probing function used for probing sequence.
	- A poor decision can result in Chaos Cycles.

##### Probing Sequences
- General concept of incrementing the collided hash value with the result of some function P(x) applied to x (i.e. linear function P(x) = 4x), then applying mod to get an index.
	- Hash (array) index = H(k) + P(x) mod N, where H(k) is the hash value produced by the hash function, P(x) is the probing function, and N is the table size.
		- x is initialized to 1, and is continuously incremented and the update process is repeated if collision occurs again, until an empty index is found.
- Not all probing functions are viable, as they can result in Chaos Cycles shorter than the table size.
- There are an infinite amount of probing sequences that could be used; however, the probing functions used with these methods are very specific to avoid Chaos Cycles.
1. Linear Probing
2. Quadratic Probing
3. Double Hashing
4. Pseudo Random Number Generator


##### Chaos Cycles
- Infinite looping of cycle which are shorter than the actual table size N, and can be produced by poor probing functions.
- Most randomly selected probing sequences mod N will produce a cycle shorter than the table size.
	- This method becomes problematic when trying to insert a key-value pair and all buckets on the cycle are occupied, resulting in an infinite loop.
	- i.e. in a table of size 12 where the indexes 0, 4, and 8 are occupied and the probing function infinitely cycles between these filled indexes.
- Note that Separate Chaining does not suffer from Chaos Cycles.
- The general consensus is to rather than handling this issue, it is avoided altogether by restrictng the domain of probing functions to those which produce a cycle of exactly table size N.

##### Linear Probing
- A probing method which probes according to a linear formula.
	- P(x) = ax + b, where a and b are constants, and a != 0.
		- Note that the constant b is obsolete.
- The values of the constant a and the table size N must be relatively prime to avoid Chaos Cycles.
	- Two numbers are relatively prime if their Greatest Common Denominator (GCD) is equal to 1.
	- If GCD(a, N) = 1, then the probing function P(x) can generate a complete cycle and an empty bucket can be found. 
		i.e. for table size N = 9, P(x) = 2x will work since GCD(9, 2) = 1; however, P(x) = 6x will not work since GCD(9, 6) = 3.
	- Therefore, P(x) = 1x where a = 1 is a common choice for a probing function, since GCD(1, N) = 1 regardless of table size N.
	- Important to note that upon reaching the threshold determined by the load factor and the table size, the current table size must be doubled while maintaining the GCD(a, N) = 1 constraint.

##### Quadratic Probing
- A probing method which probes according to a quadratic formula.
	- P(x) = ax^2 + bx + c, and a != 0.
		- Note that the constant b is obsolete.
- Unlike linear probing which produce cycles of order N, where N is the table size, some quadratic probing functions produce a cycle of N/2, but are always able to find a free slot if the load factor is less than 1/2.
- Note that most randomly selected quadratic probing functions will cause Chaos Cycles.
	- They easily produce short cycles.
- Feasible quadratic probing functions are very specific, and depend on the function itself, the table size, the max load factor, and the table threshold (before resizing).
	- i.e. P(x) = (x^2 + x)/2 and keep the table size N a power of two.
		- i.e. N = 2^3 = 8, max load factor = 0.4, and table threshold = N * max load factor = 3.

##### Double Hashing
- A probing method which probes according to a constant multiple of another hash function.
	- P(k, x) = x * H2(k), where H2(k) is a second hash function.
	- Note that double hashing reduces to linear probing, except that the constant is unknown until runtime.
		- There may be cycles produced.
- To fix the issue of Chaos Cycles, pick the table size N to be a prime number and also compute the value of delta.
	- delta = H2(k) mod N.
	- Array index = H1(k) + x * delta mod N = H1(k) + x * H2(k) mod N mod N = H1(k) + P(k, x) mod N mod N?
	- Note that H2(k) must hash the same type of keys as H1(k).
	- In the case where delta = 0 (< 1), a cycle is guaranteed to occur; thus, set delta = 1.
- Upon resizing, compute 2N and find the next prime number above this value.

###### Constructing the Secondary Hash Function H2(k)
- Frequently, the hash functions selected to compose H2(k) are picked from a pool of universal hash functions which generally operate on one fundamental data type.

#### Open Addressing vs. Separate Chaining
- Open addressing hash functions are often more specialized and are of higher quality compared to those used in separate chaining.
- The load factor for open addressing is typically much lower.
- In open addressing, key-value pairs are stored in the table itself. In separate chaining, the key-value pairs are stored in an auxiliary data structure (i.e. linked list).

#### Removing Key-Value Pairs from Hash Tables

##### Naively Removing Key-Value Pairs with Open Addressing
- In the case where there are several collisions, naively removing an element will leave a null reference in the array. For subsequent searches for the other elements which collide with this removed index, the algorithm will determine that those elements also do not exist within the hash table, since null was encountered.

##### Removing/Replacing Key-Value Pairs with Open Addressing using Tombstones.
- Solution to naive method is to place a unique marker called a tombstone instead of a null to indicate that a key-value pair has been deleted, and that bucket should be skipped during a search.
- Tombstones increase the load factor, and will be removed when the table is resized.
- Tombstone buckets can also be replaced with new key-value pairs upon insertion.

###### Lazy Deletion
- An optimization by removing the earliest tombstone encountered with the key-value pair that was looked up and eventually found.
	- This method prevents inefficient additional probing in a Hash Table cluttered with tombstones.

### Fenwick Trees/Binary Indexed Trees
- A data structure that supports sum range queries as well as setting values (point updates) in a Static Array and getting the value of the prefix sum up some index efficiently.
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/fenwicktree/FenwickTreeRangeUpdatePointQuery.java

#### Fenwick Trees/Binary Indexed Trees Time Complexities
| Operations     | Worst Case | 
| -------------- | ---------- |
| Construction   | O(n)       |
| Point Update   | O(log(n))  |     
| Range Sum      | O(log(n))  | 
| Range Update   | O(log(n))  | 
| Adding Index   | N/A        | 
| Removing Index | N/A        | 

#### Fenwick Tree Range Sum Queries
- Unlike a regular Array, in a Fenwick Tree, each specific cell/index is responsible for a range of other cells as well, depending on the value of the least significant bit (LSB) in its binary representation.
	- The position of the LSB determines the range of responsibility that cell has to the cells below itself.
		i.e. for the number 40, the LSB is 1000 since its binary representation is 101000.
	- i.e. index 12 in binary is 1100, where the LSBA is at position 3; therefore, this index is responsible for 2^(3-1) = 4 cells , including 3 below itself.
	- i.e. index 11 in binary is 1011; therefore, responsible for 2^(1-1) = 1 cell (itself).
		- Note that all odd indexes are responsible for 1 cell each (themselves).
	- Range of responsibility increases exponentially by the power of 2 (doubles).
- Note that Fenwick Trees are one-based, not zero-based. 
- Compute the prefix sum up to a certain index, which ultimately allows the performance of range sum queries.
	- Sum by cascading downwards from the current index by ranges of index responsibilities by continuously removing the LSB, eventually to binary representation of 0 or index 1.
	- Obtaining the sum between a range that does not begin at index 1 requires calculating the difference between sums.
		- The sum of range [x, y] = sum of range [1, y] - sum of range [1, x], where x, y > 1.
- In the worst case, determining the sum between a range is logarithmic O(log(n)).
	- i.e. sum of range [7, 5], which both have lots of ones in their binary representations.

#### Fenwick Tree Point Updates
- Add the LSB (instead of removing) to propagate the value to the cells responsible for the current index, until out-of-bounds is reached.
	- i.e. updating the value at index 9 by some constant x requires adding the constant x to range of responsibilities of indexes 10, 12, and 16 as well.

#### Fenwick Tree Construction
- Given a Static Array of values, create a Fenwick Tree containing the appropriate prefix sums.
	- Note that the Static Array containing values does not change.

##### Naively Constructing in Linearithmic O(nlog(n)) Time
- For each element in the array A of values at index i, perform a point update on the Fenwick Tree with a value of A[i].
	- There are n elements and each point update takes logarithmic O(log(n)) time; thus, total of of linearithmic O(nlog(n)).

##### Constructing in Linear O(n) Time
- Cascading/propagating values throughout the Fenwick Tree by updating the parent index responsible for the current index in place.
	- Add the value in the current cell to the immediate cell that is responsible. 
		- Resembles point update cascading, but only one cell at a time.
- The parent index is the current index plus the LSB of the current index.
	- i.e. at index 4 with 0100 binary representation, the parent index is 8 with 1000 binary representation. Add the value at index 4 to the value at index 8.
- A parent index that is out of bounds is simply ignored.

### AVL Trees

#### Balanced Binary Search Tree 
- A self-balancing Binary Search Tree, which will adjust itself to maintain a low (logarithmic) height, allowing for faster operations such as insertions and deletions.
	- Addresses issues of chains of nodes in normal Binary Search Trees (i.e. from a stream of increasing numbers as input), which results in linear O(n) in the worst case for all operations.
	- Worst case becomes logarithmic O(log(n)) instead.
- Leverages a tree invariant (rule or property imposed that must be met after evrey operation) and tree rotations.

#### Balanced Binary Search Tree Time Complexities
| Operations | Average Case | Worst Case |
| ---------- | ------------ | ---------- |
| Insert     | O(log(n))    | O(log(n))  |
| Delete     | O(log(n))    | O(log(n))  |         
| Remove     | O(log(n))    | O(log(n))  |        
| Search     | O(log(n))    | O(log(n))  | 

#### Tree Rotations
- Applied after a tree operation to ensure that the tree invariant is met.

### Indexed Priority Queues

#### Indexed D-ary Heaps

### Graphs
- Networks consisting of nodes and edges, where the edge (u, v) goes from node u to node v.
- Directed or undirected? 
- Weight or unweighted edges?
- Likely to be sparse or dense with edges?
- Use adjacency matrices, adjacency lists, edge lists, or other structure to represent efficiently?

#### Graph Theory
- Mathematical theory of the properties and applications of graphs (networks).

#### Types of Graphs

##### Undirected Graphs
- Graphs in which edges (paths) have no orientation and are bidirectional.
	- The edge (u, v) is identical to the edge (v, u).
	- i.e. nodes representing cities and edges representing two-way roads.

##### Directed Graphs/Digraphs
- Graphs in which edges have orientations and are unidirectional (represented with arrows).
	- i.e. nodes representing people and edges representing giving presents.

##### Weighted Graphs
- Many graphs can have edges that contain a certain weight w to represent an arbitrary value, such as cost, distance, quantity, etc.
	- Edge denoted by triplet (u, v, w).
- Important to specify if the weighted graph is directed or undirected.

##### Special Graphs
1. Trees
	- Undirected graphs with no cycles.
	- Connected graphs with N nodes and N-1 edges.
2. Rooted Trees
	- Trees with designated root nodes where every edge either points away from or towards the root node.
3. Directed Acyclic Graphs (DAGs)
	- Directed graphs with no cycles.
	- Used to represent structures with dependencies.
		- i.e. schedulers, compilers, university class prerequisites, etc.
	- Useful algorithms include finding the shortest path(s), and producing a topological ordering of nodes.
4. Bipartite Graphs
	- Graphs whose vertices can be split into two independent groups U and V, such that every edge connects between U and V.
	- Play a critical role in Network Flow.
5. Complete Graphs
	- There is a unique edge between every pair of nodes.
	- Useful for testing an algorithm for performance.

#### Representing Graphs
- Important to carefully select the data structure to represent the type of graph.
This ultimately has a huge impact on performance.

##### Adjacency Matrices
- The simplest way of representing a graph in a 2D matrix.
- Given an adjacency matrix m, the cell m[i][j] represents the edge weight of going from node i to node j.
	- Often assumed that the edge of going from a node to itself has a cost of 0; thus, the diagonal of the adjacency matrix is all zeros.
- Space efficient for dense graphs, and also provides edge weight lookup of constant O(1) time.
- Typically not the first choice since it requires V^2 space, and requires V^2 time to iterate over all edges, which is especially inefficient for sparse graphs where there are many empty cells.

##### Adjacency Lists
- Represent a graph as a map from nodes to their corresponding list of edges.
	- Each node tracks its own list of outgoing edges and weights.
		i.e. node C can reach node A and node B is represented by C -> [(A, 4), (B, 1)].
- Adjacency lists only need to keep track of the end nodes and their corresponding weights, since the start nodes are already implicitly known.
- The main alternative to adjacency matrices, since adjacency lists are space efficient in space for representing sparse graphs, and can iterate over all edges in efficient time.
- Slightly more complex to implement as a graph representation, and are less space efficient for dense graphs.

##### Edge Lists
- Simply represent a graph as an unordered list of edges (and weights).
	- The list contains triplets (u, v, w), which represent the cost w from node u to node v.
	- i.e. [(C, A, 4), (A, C, 1), (B, C, 6)]
- Rarely used due to the lack of structure; however, edge lists are conceptually simply and practical in a handful of algorithms.

#### Common Graph Theory Problems

##### Shortest Path 
- Given a weighted graph, find the shortest path (minimum total weight/cost) of edges from node A to node B.
- Typical solution algorithms include Breadth-First Search (for unweighted graph), Dijkstra's, Bellman-Ford, A* (A star), etc.

##### Connectivity
- Does there exist a path between node A and node B?
- Typical solution algorithms include using Union Find or any search algorithm (i.e. DFS, BFS, etc.).

##### Negative Cyclces
- Detecting negative cycles in a weighted graph.
	- Negative cycles can have pros and cons in the given context.
- Typical solution algorithms include Bellman-Ford and Floyd-Warshall.

##### Strongly Connected Components
- Finding self-contained cycles within a directed graph, where every vertex (node) in a given cycle can reach every other vertex in the same cycle.
	- Usually an intermediate step for other problems.
- Typical solution algorithms include Tarjan's and Kosaraju's.

##### Travelling Salesman 
- Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?
- This is an NP-Hard problem, meaning it's very computationally challenging; unfortunately, this problem also has several important applications.
- Typical solution algorithms include Held-Karp (dynamica programming), Branch and Bound, and many other approximation algorithms.

##### Minimum Spanning Tree (MST)
- A subset of edges (tree) of a connected, edge-weighted graph that connects all the vertices together, without any cucles and with the minimum total edge weight.
- Used to design a least cost network, circuit design, transportation networks, etc.
- Typical solution algorithms include Kruskal's, Prim's, Boruvka's, etc.

##### Finding Max Flow from Network Flow Graph
- With an infinite input source, how much flow can be pushed through the network?
- Edges weights represent capacities of the system.
	- i.e. max volume through a pipe, max number of cars on a road, etc.
- Typical solution algorithms include Ford-Fulkerson, Edmonds-Karp, Dinic's, etc.

#### Graph Algorithms

##### Depth-First Search (DFS)
- A fundamental traversal/search algorithm used to explore nodes and edges of a graph. 
- Plunges depth first into a graph without regard for which edge it takes next until it cannot go any further, at which point it backtracks and continues.
	- i.e. starts at node 0 and continuously searches deeper and subsequently backtracking until all nodes are visited and the algorithm returns back to node 0.
- Visited nodes are marked; already visited nodes do not need to be further traversed.
- Runs with a time complexity of O(V+E), where V is the number of vertices (nodes), and E is the number of edges.	
	- Proportional to size of graph.
- Often used as a building block in other algorithms.
- Very powerful when augmented to perform other tasks such as count connected components, determine connectivity, find bridges/articulation points, detect and find cycles, topologically sort the nodes, generate mazes, etc.
- Convenient to use adjacency lists.
- **Implementation**: https://github.com/williamfiset/Algorithms/blob/master/com/williamfiset/algorithms/graphtheory/DepthFirstSearchAdjacencyListRecursive.java

##### Breadth-First Search (BFS)
- A fundamental traversal/search algorithm used to explore nodes and edges of a graph. 
- Runs with a time complexity of O(V+E), where V is the number of vertices (nodes), and E is the number of edges.	
	- Proportional to size of graph.
- Often used as a building block in other algorithms.
- Starts at some arbitrary node of a graph and explores the neighbour nodes first, before moving to the next level of neighbours.
	- BFS explores nodes in "layers" by maintaining a Queue of which nodes to visit next.
		- At the beginning, the start node is added to the queue, marked as visited (i.e. in a list), popped from the Queue, and has its neighbour nodes added to the queue (if unvisited).
	- The algorithm ends when the Queue is empty; in other words, all nodes have been visited.
- Particularly useful for finding the shortest path on unweighted graphs.
- **Implementation**: https://github.com/williamfiset/Algorithms/blob/master/com/williamfiset/algorithms/graphtheory/BreadthFirstSearchAdjacencyListIterative.java

###### Determining Connected Components
- Marking all nodes connected/reachable by a node as part of the same component (group).
	- i.e. assign integer value to each group to distinguish.

###### Find Shortest Path on a Grid using Breadth-First Search
- Many problems in graph theory can be represented using a grid.
	- Grids are a form of implicit graph because we can determine a node's neighbours based on our location witin the grid.
	- i.e. solving a maze, routing through obstacles to get to a location, shortest path through a dungeon, etc.
- Common approach to solving graph theory problems on grids is to first convert the grid to a familiar format such as an adjacency list or an adjacency matrix.
	- However, this may not always be the most efficient method.
- Transformations between graph representations (i.e. adjacency lists, adjacency matrices, etc.) can usually be avoided due to the structure of a grid by using direction vectors instead.
	- By simply indexing +/- 1 to the object's current row-column (i.e. x and y) position in the grid, we can move the object left, right, up, down and/or diagonally to easily access its neighbouring cells.
		- This method is easy to implement and can be scaled to higher dimensions.
- Typically for the BFS method, a Queue is used to maintain tracking and visiting of neighbouring nodes, and an Array is used to keep track of already visited nodes, so that redundant neighbour nodes are not added to the Queue and revisited.
	- Starting at the initial cell/node, current nodes are continuously popped while neighbouring nodes are subsequently pushed until the end goal has been reached.
	- Obstacles (i.e. marked by some character symbol) will prevent some neighbouring cells from being reached directly.
	- BFS algorithm can stop before all cells/nodes are visited, as long as the end has been reached.
	- The smallest number of steps it takes to go from start to end is equal to the number of times, or "layers", the neighbouring nodes of all current nodes popped from the queue are pushed (i.e. number of while loop iterations).
	- To obtain the actual shortest path itself, the previously visited node of each node must be tracked (i.e. in a 2D matrix) to retrace the path taken to achieve the smallest number of steps.
	- This method requires a lot of packing and unpacking of values accessed through the Queue, since each Queue element stores the next x and y position as a pair.
		- Requires an array or an object wrapper to store the coordinate values.
- An alternative method of representing multi-dimensional coordinates which requires less setup and effort is to use multiple Queues. 
	- One Queue for each dimensions.
		- i.e. in 3D, there will be three Queues (for x, y, and z dimensions).

#### Dijkstra's Shortest Path Algorithm
- Able to determine the shortest paths between the starting node and all other nodes throughout the entire graph.
- One of the most important algorithms for finding the shortest path in a graph.
- It is a Single Source Shortest Path (SSSP) algorithm for graphs with non-negative edge weights.
	- The initial node must be explicitly specified at the beginning of the algorithm to indicate a relative starting point.
- Depending on how the algorithm is implemented and which data structures are used, the time complexity is typically O(E * log(V)), where E and V represent the number of edges (paths) and vertices (nodes) respectively.
- The main constraint for Dijkstra's Algorithm is that the graph must only contain non-negative edge weights. 
	- This is imposed to ensure that once a node has been visited, its optimal distance cannot be improved.
	- Ultimately, this constraint enables the algorithm to act in a greedy manner by always selecting the next most promising node.

##### Dijkstra's Algorithm Overview 
- A dist Array, a Min  Priority Queue (implemented as a Min Binary Heap in the lazy approach, or as an Min Indexed D-ary Heap in the eager approach), and a visited Array are typically used.
	- A dist Array, where the distance to every node (from the starting node) is positive infinity. At the starting node's index, mark the distance as 0.
	- Maintain a Min Priority Queue  of key-value pairs (node index, distance) to indicate which node to visit next, based on sorted min value of distance from the starting node.
	- The visited Array will also be updated in parallel to mark already visited nodes prevent them from being revisited as neighbouring nodes to the current node.
1. Initially, insert (s, 0) into the Priority Queue, and loop while the Priority Queue is not empty, keep pulling out the next most promising pair (node index, distance) pair.
	- Node s will be visited first, since it has the best distance in the Priority Queue, and is also the only node in the Priority Queue initially.
2. For each node visited, iterate over all edges outwards from the current node and relax each edge, appending a new (node index, distance) key-value pair to the Priority Queue for every relaxation.
	- The currently visited node's neighbouring nodes will be added to the Priority Queue, and if the distance from the starting node (value at the neighbouring node's index in the dist Array) plus the edge's cost is less than the current stored value in the dist Array (initially positive infinity), update the value with the neighbouring node's new shortest distance.
	- In the lazy approach, a new key-value pair must be inserted (takes logarithmic O(log(n)) time) if the neighbouring node's distance is updated with a shorter distance.
		- Note that this insertion operation is much faster than the linear O(n) time it takes to search for the key in the Priority Queue and subsequently update the distance value.
		- Downside is that duplicate key-value pairs may be inserted.
		- This method can be optimized into an eager approach using an Indexed Priority Queue (implemented as an Indexed Binary Heap), which provides constant O(1) time access to key-value pairs for update.
	- The current node is then deqeued/removed from the Priority Queue, and the next neighbouring node to visit is selected based on the minimum distance.
		- Outdated and non-optimal key-value pairs of node index and distance from the starting node are lazily deleted from the Priority Queue once selected, since they have the minimum distance amongst all elements currently in the Priority Queue; however, the corresponding node already has a shorter distance in the dist Array.
		- The solution is to simply check if the stored minimum distance in the dist Array is less than the distance of the key-value pair pulled from the Priority Queue; if true, the key-value pair can be ignored and removed, since we know that we already have a shorter path for that node.
- Once the Priority Queue is empty, the shortest distance to each node from the starting node will be stored in the dist Array.

##### Finding the Optimal Path
- If interested in finding not only the optimal distance to a particular starting node, but also what sequence of nodes were taken to get there, additional info must be stored using a prev Array.
	- The prev Array tracks the index of the node previously taken to reach the current node i.
	- Initially should be initialized with null values.
- At the end of the algorithm, the prev Array will contain the previous nodes taken along the shortest path to reach all nodes.
- Note that the prev Array must be reversed at the end to obtain the shortest path.

##### Stopping Early
- Once the destination node has been reached, every other node in the graph/network will be visited only in the worst case.
- The main idea for stopping early is that Dijkstra's Algorithm processes each next most promising node in order, so if the destination node has been visited, its shortest distance will not change as more future nodes are visited.
- In implementation, after finishing visiting the current node's neighbours, simply check if the current node index is equal to the destination node; if true, stop the algorithm.

##### Lazy Dijkstra's Algorithm
- The approach of inserting duplicate key-value pairs in the Min Priority Queue (Min Binary Heap) in logarithmic O(log(n)) time, rather than searching for the key to update the value in linear O(n) time, is inefficient for dense graphs, since there will be several outdated key-value pairs in the Priority Queue.
- **Implementation**: https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/graphtheory/DijkstrasShortestPathAdjacencyList.java

##### Eager Dijkstra's Algorithm using an Indexed Priority Queue
- Avoids duplicate key-value pairs and supports efficient value updates in logarithmic O(log(n)) time by using an Indexed Priority Queue (implemented using an Indexed Binary Heap).
- An Indexed Priority Queue is a Priority Queue variant which allows access to key-value pairs in constant O(1) time (as opposed to the linear O(n) access time in normal Priority Queues) and updates in logarithmic O(log(n)) time if using a Binary Heap.
- Upon discovering a shorter path for a node, access then update the key-value pair in the Indexed Priority Queue, instead of inserting a new key-value pair.

##### D-ary Heap Optimization
- In Dijkstra's Algorithm, there are typically a lot more update operations (i.e. decrease key) to key-value pairs than there are dequeue removal operations.
- The Min Indexed D-ary Heap is a Heap variant in which each node has D children. 
	- Speeds up decrease key operations at the expense of more costly removals.
- In general, D = E / V is the best degree to use to balance removals against decrease key operations and optize Dijkstra's Algorithm, improving the time complexity to O(E * log(V)), which is especially better for dense graphs.
- **Implementation**:
https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/graphtheory/DijkstrasShortestPathAdjacencyListWithDHeap.java

##### Fibonacci Heap
- The current state-of-the-art Heap, which gives Dijkstra's Algorithm a time complexity of O(E+ Vlog(V)).
- In practice, Fibonacci Heaps are very difficult to implement and have a large enough constant amortized overhead to make them impractical, unless the graph is extremely large.

# Algorithms

## Sorting 

## Searching

## Greedy 

## Sliding Window

## Brute Force

### Iteration

### Recursion

## Divide and Conquer

## Dynamic Programming (Optimization)

## Tabulation
- Bottom-up.

### Memoization (Recursion)
- Top-down.
