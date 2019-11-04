# library-of-fundamentals
**Implementations of essential data structures and algorithms.**

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

#### Time Complexities, Big-O Notations, and Examples
- Constant time: O(1)	
	- Access array element by index.
- Logarithmic time: O(log(n))
	- Binary search.
- Linear time: O(n)
	- Searching for element in unsorted array.
- Linearithmic time: O(nlog(n))
	- Mergesort. 
- Quadratic time: O(n^2)
	- Nested for loops.
- Cubic time: O(n^3)
	- Nested for loops.
- Exponential time: O(b^n), b > 1
	- Finding all subsets of a set.
- Factorial Time: O(n!)
	- Finding all permutations of a string.

## Data Structures

### Arrays (Static and Dynamic)

#### Static Arrays
- Fixed length container containing n indexable elements.
- Given as contiguous chunks of memory; memory addresses of elements are adjacent.
- Storing and accessing sequential data, temporarily storing objects, used as buffers for I/O routines, lookup tables and inverse lookup tables, hack to return multiple values from a function (via pointer), memoization (caching) results in dynamic programming problems.

#### Time Complexities
|               | **Static Array** | **Dynamic Array** |
| **Access**    | O(1)             | O(1)              |
| **Search**    | O(N)             | O(N)              |
| **Insertion** | N/A              | O(n)              |
| **Appending** | N/A              | O(1)              |
| **Deletion**  | N/A              | O(N)              |

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
