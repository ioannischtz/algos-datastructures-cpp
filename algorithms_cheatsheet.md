# Algorithms Cheat Sheet

## 1. Binary Search

- **Explanation**: Efficiently find a specific item in a sorted collection by
  repeatedly dividing the search space in half.
- **Big O Notation**:
  - Time Complexity: O(log n)
- **Use When**:
  - Searching in a sorted array or list.
- **Avoid When**:
  - The data is not sorted.
- **Typical Interview Problems**:
  - Find the target element in a sorted array.
  - Search in a rotated sorted array.

## 2. Merge Sort

- **Explanation**: A divide-and-conquer sorting algorithm that recursively
  divides an array into two halves, sorts them, and merges them.
- **Big O Notation**:
  - Time Complexity: O(n log n)
- **Use When**:
  - Need a stable and efficient sorting algorithm.
- **Avoid When**:
  - Memory usage is a concern.
- **Typical Interview Problems**:
  - Sort an array or linked list.

## 3. Quick Sort

- **Explanation**: A divide-and-conquer sorting algorithm that selects a "pivot"
  element and partitions the array into smaller and larger elements.
- **Big O Notation**:
  - Time Complexity: O(n^2) worst-case, O(n log n) average-case.
- **Use When**:
  - Need an in-place sorting algorithm with good average-case performance.
- **Avoid When**:
  - Sorting nearly sorted or already sorted data.
- **Typical Interview Problems**:
  - Sort an array in-place.
  - Find the kth smallest or largest element in an array.

## 4. Breadth-First Search (BFS)

- **Explanation**: Explore all neighbors of a node before moving on to their
  children in a graph or tree.
- **Big O Notation**:
  - Time Complexity: O(V + E), where V is the number of vertices and E is the
    number of edges.
- **Use When**:
  - Finding the shortest path in an unweighted graph.
- **Avoid When**:
  - Need to explore deeper levels of a tree or graph quickly.
- **Typical Interview Problems**:
  - Find the shortest path in a maze.
  - Detect if a graph is bipartite.

## 5. Depth-First Search (DFS)

- **Explanation**: Explore as far down a branch as possible before backtracking
  in a graph or tree.
- **Big O Notation**:
  - Time Complexity: O(V + E), where V is the number of vertices and E is the
    number of edges.
- **Use When**:
  - Exploring all possible paths in a tree or graph.
- **Avoid When**:
  - Need to find the shortest path.
- **Typical Interview Problems**:
  - Find all connected components in a graph.
  - Solve problems involving recursion.

## 6. Dijkstra's Algorithm

- **Explanation**: Find the shortest path in a weighted graph by iteratively
  selecting the vertex with the smallest known distance.
- **Big O Notation**:
  - Time Complexity: O(V^2) with a matrix, O(E + V log V) with a priority queue.
- **Use When**:
  - Need to find the shortest path in a weighted graph.
- **Avoid When**:
  - There are negative edge weights.
- **Typical Interview Problems**:
  - Find the shortest path between two nodes in a graph.

## 7. Greedy Algorithms

- **Explanation**: Make the locally optimal choice at each step to find a global
  optimum.
- **Big O Notation**: Depends on the specific algorithm.
- **Use When**:
  - Solving optimization problems where a greedy choice leads to the best
    solution.
- **Avoid When**:
  - Problems that require a guarantee of finding the global optimum.
- **Typical Interview Problems**:
  - Fractional Knapsack problem.
  - Huffman coding.

## 8. Dynamic Programming

- **Explanation**: Solve a problem by breaking it into smaller subproblems and
  storing their solutions to avoid redundant computations.
- **Big O Notation**: Depends on the specific problem and algorithm.
- **Use When**:
  - Solving problems with overlapping subproblems.
- **Avoid When**:
  - The problem can be solved efficiently using simpler methods.
- **Typical Interview Problems**:
  - Fibonacci sequence.
  - Longest common subsequence.

## 9. Two Pointers Technique

- **Explanation**: Maintain two pointers in an array, typically at the start and
  end, and move them closer together based on certain conditions.
- **Big O Notation**:
  - Time Complexity: O(n)
- **Use When**:
  - Searching for pairs or subsequences in a sorted array.
- **Avoid When**:
  - The array is not sorted.
- **Typical Interview Problems**:
  - Determine if there are two elements in a sorted array that sum to a target
    value.
  - Find a triplet in an array that sums to a given value.

## 10. Sliding Window Technique

- **Explanation**: Maintain a window of elements within an array and slide it to
  explore different subarrays.
- **Big O Notation**:
  - Time Complexity: O(n)
- **Use When**:
  - Finding a subarray with a specific property (e.g., maximum sum, minimum
    length).
- **Avoid When**:
  - The problem can be solved more efficiently with other techniques.
- **Typical Interview Problems**:
  - Find the maximum sum of a subarray of a fixed size.
  - Find the minimum length of a subarray with a sum greater than or equal to a
    target value.

## 11. Binary Search Trees (BST) Operations

- **Explanation**: Implement common operations on binary search trees, including
  insertion, deletion, and searching.
- **Big O Notation**:
  - Time Complexity: O(log n) on average, O(n) in the worst case.
- **Use When**:
  - Maintaining a dynamically changing sorted data structure.
- **Avoid When**:
  - You require guaranteed balanced trees, as the tree can become unbalanced.
- **Typical Interview Problems**:
  - Implement the operations of a binary search tree.
  - Determine if a binary tree is a valid binary search tree.

## 12. Topological Sorting

- **Explanation**: Arrange the vertices of a directed acyclic graph (DAG) such
  that for every directed edge (u, v), vertex u comes before vertex v in the
  ordering.
- **Big O Notation**:
  - Time Complexity: O(V + E), where V is the number of vertices and E is the
    number of edges.
- **Use When**:
  - Solving problems involving dependencies or tasks with prerequisites.
- **Avoid When**:
  - The graph contains cycles, as topological sorting is only applicable to
    DAGs.
- **Typical Interview Problems**:
  - Schedule tasks or courses with prerequisites.
  - Detect circular dependencies.

## 13. Floyd-Warshall Algorithm

- **Explanation**: Find the shortest paths between all pairs of vertices in a
  weighted graph, even if there are negative edge weights.
- **Big O Notation**:
  - Time Complexity: O(V^3), where V is the number of vertices.
- **Use When**:
  - Need to find the shortest paths between all pairs of vertices in a weighted
    graph.
- **Avoid When**:
  - The graph is too large, as the cubic time complexity can become inefficient.
- **Typical Interview Problems**:
  - Find the shortest paths between all pairs of vertices in a graph.

## 14. Simplex Algorithm

- **Explanation**: An iterative method for solving linear programming problems
  to find the optimal solution by moving along the edges of a polyhedral
  feasible region.
- **Big O Notation**:
  - Time Complexity: In practice, it's often efficient, but in the worst case,
    it can be exponential.
- **Use When**:
  - Solving linear programming problems, such as optimization, resource
    allocation, and scheduling.
- **Avoid When**:
  - Dealing with non-linear optimization problems, as the simplex algorithm is
    designed for linear programming.
- **Typical Solver Problems**:
  - Linear programming problems involving resource allocation, transportation,
    or production planning.
  - Finding the optimal solution to a set of linear constraints.

These algorithms cover a wide range of problem-solving techniques commonly
encountered in technical interviews and solver applications. Understanding these
algorithms can be invaluable for tackling complex problems and optimizing
various processes.
