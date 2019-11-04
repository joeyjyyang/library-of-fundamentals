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

#### Static Arrays
- Fixed length container containing n indexable elements.
- Given as contiguous chunks of memory; memory addresses of elements are adjacent.
- i.e. storing and accessing sequential data, temporarily storing objects, used as buffers for I/O routines, lookup tables and inverse lookup tables, hack to return multiple values from a function (via pointer), memoization (caching) results in dynamic programming problems, etc.

#### Dynamic Arrays
- Can grow and shrink in size.
- Typically implemented using static arrays.
	- i.e. create new array of double size and copy elements from old array upon exceeding capacity.
		- Exponential growth rate (i.e. growth factor of 2) to keep time complexity of insertions constant O(1).
- **Implementation**: https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/dynamicarray/DynamicArray.java

#### Array Time Complexities
|           | Static Array | Dynamic Array |
| --------- | ------------ | ------------- |
| Access    | O(1)         | O(1)          |
| Search    | O(n)         | O(n)          |
| Insertion | N/A          | O(n)          |
| Appending | N/A          | O(1)          |
| Deletion  | N/A          | O(n)          |



- Linked Lists
- Stacks
- Queues
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
