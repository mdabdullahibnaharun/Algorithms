
# Algorithm Repository

This repository contains a collection of classic and efficient algorithms implemented in **C++**. The algorithms cover a wide range of topics, from sorting and searching to graph theory and dynamic programming. They serve as a great resource for learning, reference, and practical implementation.

## Algorithms List

### 1. **BFS Adjacency Matrix**
   - **Description**: Implements **Breadth-First Search (BFS)** using an adjacency matrix.
   - **Pseudocode**:
     ```
     BFS(Graph, start):
         Initialize Queue Q
         Mark start node as visited
         Enqueue start node into Q
         while Q is not empty:
             node = Dequeue Q
             for each neighbor of node:
                 if neighbor is not visited:
                     Mark neighbor as visited
                     Enqueue neighbor into Q
     ```
   - **Time Complexity**: O(V^2) (where V is the number of vertices)
   - **Space Complexity**: O(V) (for storing visited nodes and queue)

### 2. **Binary Search**
   - **Description**: An efficient algorithm to search for an element in a sorted array with time complexity of O(log n).
   - **Pseudocode**:
     ```
     BinarySearch(arr, target):
         low = 0
         high = length of arr - 1
         while low <= high:
             mid = (low + high) / 2
             if arr[mid] == target:
                 return mid
             else if arr[mid] < target:
                 low = mid + 1
             else:
                 high = mid - 1
         return -1  // Target not found
     ```
   - **Time Complexity**: O(log n)
   - **Space Complexity**: O(1)

### 3. **Binary Tree Creation**
   - **Description**: Creates a binary tree structure for use in traversal algorithms.
   - **Pseudocode**:
     ```
     CreateBinaryTree():
         root = NULL
         insert(node):
             if root is NULL:
                 root = node
             else:
                 insertRecursive(root, node)
     ```
   - **Time Complexity**: O(n) (for creating n nodes)
   - **Space Complexity**: O(n)

### 4. **Binary Tree Traversal (TREEWALK)**
   - **Description**: Implements **In-order, Pre-order, and Post-order** tree traversal.
   - **Pseudocode** (for In-order):
     ```
     InorderTraversal(node):
         if node is not NULL:
             InorderTraversal(node.left)
             visit(node)
             InorderTraversal(node.right)
     ```
   - **Time Complexity**: O(n) (for visiting all nodes)
   - **Space Complexity**: O(h) (where h is the height of the tree, due to recursion stack)

### 5. **Bubble Sort**
   - **Description**: A simple **O(n²)** sorting algorithm, ideal for small datasets.
   - **Pseudocode**:
     ```
     BubbleSort(arr):
         n = length of arr
         for i = 0 to n-1:
             for j = 0 to n-i-2:
                 if arr[j] > arr[j+1]:
                     swap arr[j] and arr[j+1]
     ```
   - **Time Complexity**: O(n²)
   - **Space Complexity**: O(1)

### 6. **Dijkstra's Algorithm**
   - **Description**: Finds the shortest path in a weighted graph using **Dijkstra’s algorithm**. Ideal for graph traversal.
   - **Pseudocode**:
     ```
     Dijkstra(Graph, source):
         Initialize distance[source] = 0, distance[all other nodes] = infinity
         Initialize priorityQueue
         while priorityQueue is not empty:
             u = ExtractMin(priorityQueue)
             for each neighbor v of u:
                 if distance[u] + weight(u, v) < distance[v]:
                     distance[v] = distance[u] + weight(u, v)
                     Update priorityQueue with new distance[v]
     ```
   - **Time Complexity**: O(E log V) (where E is the number of edges, V is the number of vertices)
   - **Space Complexity**: O(V)

### 7. **Euclid's GCD Algorithm**
   - **Description**: Computes the greatest common divisor (**GCD**) using the **Euclidean method**.
   - **Pseudocode**:
     ```
     EuclidGCD(a, b):
         while b ≠ 0:
             temp = b
             b = a % b
             a = temp
         return a
     ```
   - **Time Complexity**: O(log(min(a, b)))
   - **Space Complexity**: O(1)

### 8. **Floyd-Warshall Algorithm**
   - **Description**: Finds the shortest paths between all pairs of nodes in a weighted graph using dynamic programming.
   - **Pseudocode**:
     ```
     FloydWarshall(Graph):
         Initialize distance[][] as adjacency matrix
         for k = 0 to n-1:
             for i = 0 to n-1:
                 for j = 0 to n-1:
                     distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
     ```
   - **Time Complexity**: O(V³) (where V is the number of vertices)
   - **Space Complexity**: O(V²)

### 9. **Greedy Coin Change**
   - **Description**: Solves the **coin change problem** using a greedy approach.
   - **Pseudocode**:
     ```
     CoinChange(coins, amount):
         Sort coins in descending order
         result = []
         for each coin in coins:
             while amount >= coin:
                 result.append(coin)
                 amount -= coin
         return result
     ```
   - **Time Complexity**: O(n log n) (due to sorting the coins)
   - **Space Complexity**: O(m) (where m is the number of coins in the result)

### 10. **Heap Sort**
   - **Description**: A comparison-based sorting algorithm with **O(n log n)** time complexity.
   - **Pseudocode**:
     ```
     HeapSort(arr):
         BuildMaxHeap(arr)
         for i = n-1 to 1:
             swap arr[0] and arr[i]
             MaxHeapify(arr, 0, i)
     ```
   - **Time Complexity**: O(n log n)
   - **Space Complexity**: O(1)

### 11. **Insertion Sort**
   - **Description**: Builds the sorted array one item at a time.
   - **Pseudocode**:
     ```
     InsertionSort(arr):
         for i = 1 to length(arr)-1:
             key = arr[i]
             j = i-1
             while j >= 0 and arr[j] > key:
                 arr[j+1] = arr[j]
                 j = j-1
             arr[j+1] = key
     ```
   - **Time Complexity**: O(n²)
   - **Space Complexity**: O(1)

### 12. **Longest Common Subsequence (LCS)**
   - **Description**: Solves the **Longest Common Subsequence** problem using dynamic programming.
   - **Pseudocode**:
     ```
     LCS(X, Y):
         Initialize table of size len(X) + 1, len(Y) + 1
         for i = 1 to len(X):
             for j = 1 to len(Y):
                 if X[i-1] == Y[j-1]:
                     table[i][j] = table[i-1][j-1] + 1
                 else:
                     table[i][j] = max(table[i-1][j], table[i][j-1])
         return table[len(X)][len(Y)]
     ```
   - **Time Complexity**: O(m * n) (where m and n are the lengths of the two sequences)
   - **Space Complexity**: O(m * n)

### 13. **Longest Increasing Subsequence (LIS)**
   - **Description**: Finds the **longest increasing subsequence** in an array using dynamic programming.
   - **Pseudocode**:
     ```
     LIS(arr):
         n = length of arr
         dp = [1] * n
         for i = 1 to n-1:
             for j = 0 to i-1:
                 if arr[i] > arr[j]:
                     dp[i] = max(dp[i], dp[j] + 1)
         return max(dp)
     ```
   - **Time Complexity**: O(n²)
   - **Space Complexity**: O(n)

### 14. **Linear Search**
   - **Description**: A simple searching algorithm that sequentially checks each element in an array for a match.
   - **Pseudocode**:
     ```
     LinearSearch(arr, target):
         for i = 0 to length(arr) - 1:
             if arr[i] == target:
                 return i
         return -1  // Target not found
     ```
   - **Time Complexity**: O(n)
   - **Space Complexity**: O(1)

### 15. **Merge Sort**
   - **Description**: A divide-and-conquer sorting algorithm with **O(n log n)** complexity.
   - **Pseudocode**:
     ```
     MergeSort(arr):
         if length(arr) <= 1:
             return arr
         mid = length(arr) // 2
         left = MergeSort(arr[0:mid])
         right = MergeSort(arr[mid:])
         return Merge(left, right)
     
     Merge(left, right):
         result = []
         while left and right:
             if left[0] < right[0]:
                 result.append(left.pop(0))
             else:
                 result.append(right.pop(0))
         return result + left + right
     ```
   - **Time Complexity**: O(n log n)
   - **Space Complexity**: O(n)

### 16. **Queue Data Structure**
   - **Description**: Implements a **queue** data structure that follows First In, First Out (FIFO) order.
   - **Pseudocode**:
     ```
     Queue():
         Initialize front, rear as NULL
         enqueue(item):
             Insert item at rear
         dequeue():
             Remove item from front
     ```
   - **Time Complexity**: O(1)
   - **Space Complexity**: O(n)

### 17. **Quick Sort**
   - **Description**: A divide-and-conquer sorting algorithm that picks a pivot and partitions the array for efficient sorting.
   - **Pseudocode**:
     ```
     QuickSort(arr, low, high):
         if low < high:
             pivot = Partition(arr, low, high)
             QuickSort(arr, low, pivot - 1)
             QuickSort(arr, pivot + 1, high)
         
     Partition(arr, low, high):
         pivot = arr[high]
         i = low - 1
         for j = low to high - 1:
             if arr[j] < pivot:
                 i = i + 1
                 swap arr[i] and arr[j]
         swap arr[i + 1] and arr[high]
         return i + 1
     ```
   - **Time Complexity**: O(n log n) (average case), O(n²) (worst case)
   - **Space Complexity**: O(log n)

### 18. **QuickSort using Pivot**
   - **Description**: A variation of **Quick Sort**, using a pivot element for faster sorting.
   - **Pseudocode**:
     ```
     QuickSortUsingPivot(arr):
         choose pivot
         partition array based on pivot
         recursively sort the two sub-arrays
     ```
   - **Time Complexity**: O(n log n) (average case), O(n²) (worst case)
   - **Space Complexity**: O(log n)

### 19.

 **Selection Sort**
   - **Description**: A simple sorting algorithm that repeatedly selects the smallest (or largest) element and swaps it.
   - **Pseudocode**:
     ```
     SelectionSort(arr):
         for i = 0 to length(arr)-1:
             minIndex = i
             for j = i+1 to length(arr):
                 if arr[j] < arr[minIndex]:
                     minIndex = j
             swap arr[i] and arr[minIndex]
     ```
   - **Time Complexity**: O(n²)
   - **Space Complexity**: O(1)

### 20. **Stack Data Structure**
   - **Description**: Implements a **stack** data structure following the Last In, First Out (LIFO) principle.
   - **Pseudocode**:
     ```
     Stack():
         Initialize stack
         push(item):
             Add item to top of stack
         pop():
             Remove item from top of stack
     ```
   - **Time Complexity**: O(1)
   - **Space Complexity**: O(n)

### 21. **Tower of Hanoi**
   - **Description**: A classic algorithm to solve the Tower of Hanoi puzzle recursively.
   - **Pseudocode**:
     ```
     TowerOfHanoi(n, source, target, auxiliary):
         if n == 1:
             move disk from source to target
         else:
             TowerOfHanoi(n-1, source, auxiliary, target)
             move disk from source to target
             TowerOfHanoi(n-1, auxiliary, target, source)
     ```
   - **Time Complexity**: O(2^n)
   - **Space Complexity**: O(n)

### 22. **Warshall's Algorithm (1 & 2)**
   - **Description**: Implements **Warshall's algorithm** to find transitive closures and shortest paths.
   - **Pseudocode**:
     ```
     Warshall(Graph):
         for k = 0 to n-1:
             for i = 0 to n-1:
                 for j = 0 to n-1:
                     if graph[i][k] and graph[k][j]:
                         graph[i][j] = 1
     ```
   - **Time Complexity**: O(n³)
   - **Space Complexity**: O(n²)

### 23. **Palindrome Check**
   - **Description**: Checks if a given string is a **palindrome**.
   - **Pseudocode**:
     ```
     PalindromeCheck(str):
         for i = 0 to len(str)/2:
             if str[i] != str[len(str)-1-i]:
                 return False
         return True
     ```
   - **Time Complexity**: O(n)
   - **Space Complexity**: O(1)

### 24. **Knapsack Problem**
   - **Description**: Solves the **0/1 Knapsack problem** using dynamic programming to maximize value.
   - **Pseudocode**:
     ```
     Knapsack(values, weights, capacity):
         dp = [0] * (capacity+1)
         for i = 0 to len(values)-1:
             for w = capacity down to weights[i]:
                 dp[w] = max(dp[w], dp[w - weights[i]] + values[i])
         return dp[capacity]
     ```
   - **Time Complexity**: O(n * W) (where n is the number of items, W is the weight capacity)
   - **Space Complexity**: O(W)

### 25. **Sieve of Eratosthenes**
   - **Description**: An efficient algorithm to find all **prime numbers** up to a specified integer.
   - **Pseudocode**:
     ```
     SieveOfEratosthenes(n):
         Create boolean array sieve[0..n]
         for i = 2 to sqrt(n):
             if sieve[i] is True:
                 for j = i * i to n by i:
                     sieve[j] = False
         return all indices i where sieve[i] is True
     ```
   - **Time Complexity**: O(n log log n)
   - **Space Complexity**: O(n)

--- 

## Usage

Each algorithm is implemented in **C++** and can be used as-is or integrated into larger projects. You can either clone the repository or download individual files based on your requirements.

## Contributing

Feel free to fork the repository, submit issues, and contribute improvements or new algorithms.

---

Let me know if you'd like to add anything else!
