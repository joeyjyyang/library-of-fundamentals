# library-of-fundamentals
Implementations of essential data structures and algorithms.

## Background

### What are Data Structures?
- Way of organizing data so it can be used (i.e. accessed, queried, updated, etc.) effectively.
- Essential ingredient in creating fast and powerful algorithms.
- Helps manage and organize data (in a natural way).
- Makes code cleaner and easier to understand.

### What are Abstract Data Types?
- Abstraction of a data structure which only provides the interface to which the data structure must adhere to.
	- The interface does not give any specific details about how something should be implemente or in what programming language. 
- i.e. Lists, Stacks, Queues, Priority Queues, Maps, Trees, Graphs, etc.

## Computational Complexity Analysis
- Runtime (time) and memory (space) requirements for algorithms to execute.

### Big-O Notation
- Standardized method of representing time and space complexities.
- Gives an upper bound of the complexity in the worse case, helping quantify performance as the input size n becomes arbitrarily large (theoretically to infinity; thus, ignore constants and multiplicative factors). 

#### Time Complexities and Big-O Notations 
- Constant time: O(1)	
	- i.e. access array element by index.
- Logarithmic time: O(log(n))
	- i.e. binary search.
- Linear time: O(n)
	- i.e. searching for element in unsorted array.
- Linearithmic time: O(nlog(n))
	- i.e. mergesort. 
- Quadratic time: O(n^2)
	- i.e. nested for loops.
- Cubic time: O(n^3)
	- i.e. nested for loops.
- Exponential time: O(b^n), b > 1
	- i.e. finding all subsets of a set.
- Factorial Time: O(n!)
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

#### Array (Worst Case) Time Complexities
|           | Static Arrays | Dynamic Arrays |
| --------- | ------------- | -------------- |
| Access    | O(1)          | O(1)           |
| Search    | O(n)          | O(n)           |
| Insertion | N/A           | O(n)           |
| Appending | N/A           | O(1)           |
| Deletion  | N/A           | O(n)           |


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
|                  | Singly Linked Lists | Doubly Linked Lists |
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
| --------- | ---- | 
| Pushing   | O(1) |       
| Popping   | O(1) |      
| Peeking   | O(1) |         
| Searching | O(n) |    
| Size      | O(1) |         

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

#### Queue (Worst Case) Time Complexities
| -------- | ---- | 
| Enqueue  | O(1) |       
| Dequeue  | O(1) |      
| Peeking  | O(1) |         
| Contains | O(n) |    
| Removal  | O(n) | 
| Is Empty | O(1) | 

### Priority Queues

#### Min Heap

#### Max Heap

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
