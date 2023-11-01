# Data Structures Cheat Sheet

## Arrays

- **Explanation**: A collection of elements stored in contiguous memory
  locations.
- **Big O Notation**:
  - Access: O(1)
  - Insertion (at the end): O(1)
  - Deletion (at the end): O(1)
  - Insertion (in the middle, on average): O(n)
  - Deletion (in the middle, on average): O(n)
- **Use When**:
  - You need constant-time access to elements.
  - You know the size of the array in advance.
- **Avoid When**:
  - Frequent insertions/deletions in the middle.
  - You don't know the size in advance and it may change.
- **Methods**:
  - `get(index)`: Get the element at a specific index.
  - `set(index, value)`: Set the value of an element at a specific index.
  - `insert(index, value)`: Insert a value at a specific index.
  - `remove(index)`: Remove the element at a specific index.
  - `size()`: Get the number of elements in the array.

## Singly-Linked Lists

- **Explanation**: A collection of nodes where each node contains data and a
  reference to the next node.
- **Big O Notation**:
  - Access (by index): O(n)
  - Insertion (at the beginning): O(1)
  - Deletion (at the beginning): O(1)
  - Insertion (in the middle): O(1) if you have a reference to the node.
  - Deletion (in the middle): O(1) if you have a reference to the node.
- **Use When**:
  - You need frequent insertions and deletions at the beginning.
  - Memory allocation is dynamic.
- **Avoid When**:
  - You need fast random access by index.
- **Methods**:
  - `get(index)`: Get the element at a specific index.
  - `insertAtBeginning(value)`: Insert a value at the beginning of the list.
  - `insertAtIndex(index, value)`: Insert a value at a specific index.
  - `deleteAtBeginning()`: Delete the element at the beginning of the list.
  - `deleteAtIndex(index)`: Delete the element at a specific index.
  - `size()`: Get the number of elements in the list.

## Doubly-Linked Lists

- **Explanation**: Similar to singly-linked lists, but each node contains
  references to both the next and previous nodes.
- **Big O Notation**:
  - Access (by index): O(n)
  - Insertion (at the beginning): O(1)
  - Deletion (at the beginning): O(1)
  - Insertion (in the middle): O(1) if you have a reference to the node.
  - Deletion (in the middle): O(1) if you have a reference to the node.
- **Use When**:
  - You need frequent insertions and deletions at both the beginning and end.
  - Bi-directional traversal is necessary.
- **Avoid When**:
  - Memory usage is a concern, as each node requires more storage.
- **Methods** (in addition to singly-linked methods):
  - `insertAtEnd(value)`: Insert a value at the end of the list.
  - `deleteAtEnd()`: Delete the element at the end of the list.

## Stacks

- **Explanation**: A linear data structure that follows the Last-In-First-Out
  (LIFO) principle.
- **Big O Notation**:
  - Push (insertion): O(1)
  - Pop (deletion): O(1)
  - Top (access the top element): O(1)
- **Use When**:
  - Managing function calls and their state.
  - Tracking state changes in algorithms (e.g., backtracking).
- **Avoid When**:
  - You need to access elements in the middle.
- **Methods**:
  - `push(value)`: Push a value onto the stack.
  - `pop()`: Pop the top element from the stack.
  - `top()`: Get the value at the top of the stack.
  - `isEmpty()`: Check if the stack is empty.

## Queues

- **Explanation**: A linear data structure that follows the First-In-First-Out
  (FIFO) principle.
- **Big O Notation**:
  - Enqueue (insertion): O(1)
  - Dequeue (deletion): O(1)
  - Front (access the front element): O(1)
- **Use When**:
  - Managing tasks in a print spooler.
  - Implementing breadth-first search.
- **Avoid When**:
  - You need to access elements in the middle.
- **Methods**:
  - `enqueue(value)`: Add a value to the back of the queue.
  - `dequeue()`: Remove and return the value from the front of the queue.
  - `front()`: Get the value at the front of the queue.
  - `isEmpty()`: Check if the queue is empty.

## Hash Tables

- **Explanation**: A data structure that stores key-value pairs and provides
  fast access to values based on their keys.
- **Big O Notation**:
  - Insertion: O(1) on average (can be worst-case O(n) due to collisions).
  - Access: O(1) on average (can be worst-case O(n) due to collisions).
  - Deletion: O(1) on average (can be worst-case O(n) due to collisions).
- **Use When**:
  - Fast key-based data retrieval is needed.
- **Avoid When**:
  - You need elements in a specific order.
  - Memory usage is a concern.
- **Methods**:
  - `insert(key, value)`: Insert a key-value pair into the hash table.
  - `remove(key)`: Remove a key and its associated value.
  - `lookup(key)`: Retrieve the value associated with a key.
  - `contains(key)`: Check if the hash table contains a specific key.
  - `size()`: Get the number of key-value pairs in the hash table.

## Binary Search Trees

- **Explanation**: A hierarchical data structure in which each node has at most
  two children, and the left child is smaller, while the right child is larger.
- **Big O Notation** (balanced tree):
  - Insertion: O(log n)
  - Access: O(log n)
  - Deletion: O(log n)
- **Use When**:
  - Need to maintain data in sorted order.
- **Avoid When**:
  - Tree becomes unbalanced, leading to O(n) operations.
- **Methods**:
  - `insert(value)`: Insert a value into the binary search tree.
  - `remove(value)`: Remove a value from the binary search tree.
  - `search(value)`: Search for a value in the tree.
  - `getMin()`: Get the minimum value in the tree.
  - `getMax()`: Get the maximum value in the tree.
  - `inOrderTraversal()`: Traverse the tree in in-order (sorted) fashion.
  - `preOrderTraversal()`: Traverse the tree in pre-order fashion.
  - `postOrderTraversal()`: Traverse the tree in post-order fashion.

## Graphs

- **Explanation**: A non-linear data structure composed of nodes (vertices) and
  edges that connect these nodes.
- **Big O Notation** (for typical operations):
  - Insertion/Removal of a vertex: O(1)
  - Insertion/Removal of an edge: O(1)
  - Depth-First Search (DFS): O(V + E), where V is the number of vertices and E
    is the number of edges.
  - Breadth-First Search (BFS): O(V + E), where V is the number of vertices and
    E is the number of edges.
- **Use When**:
  - Modeling relationships between objects or entities.
  - Solving problems that involve networks, routing, or complex dependencies.
- **Avoid When**:
  - You need direct access to elements by index (like arrays) or keys (like hash
    tables).
  - The data is highly structured, and a simpler data structure suffices.
- **Methods**:
  - `addVertex(vertex)`: Add a vertex to the graph.
  - `removeVertex(vertex)`: Remove a vertex from the graph.
  - `addEdge(fromVertex, toVertex)`: Add an edge between two vertices.
  - `removeEdge(fromVertex, toVertex)`: Remove an edge between two vertices.
  - `getNeighbors(vertex)`: Get the neighbors of a given vertex.
  - `isConnected(fromVertex, toVertex)`: Check if there is an edge between two
    vertices.
  - Graph traversal methods (e.g., DFS and BFS) for exploring the graph.

These are basic methods for each data structure. Depending on your specific use
case, you may need to implement additional methods or optimize existing ones.
