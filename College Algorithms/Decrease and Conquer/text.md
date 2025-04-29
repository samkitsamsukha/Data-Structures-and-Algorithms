# Decrease and Conquer

## Variants

**1. Decrease by 1 (constant)**

- Example Problems:
  - Insertion Sort
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)

**2. Decrease by a constant factor**

- Example Problems:
  - Fake Coin Problem
  - Josephus Problem

**3. Variable Size Decrease**

- Example Problems:
  - Finding median using partition method
  - Finding LCM using GCD algorithm

---

## Concept

> Similar to **Divide and Conquer**, but here we **do not divide** the problem into two (or more) independent subproblems.
>
> Instead, we **reduce** the size of the problem step-by-step and exploit the relation between the solution of a **current instance** and a **smaller instance** of the same problem.

---

# Problems

## Insertion Sort

> **Idea:**  
> To sort an array `A[0...n-1]`, we assume that `A[0...n-2]` is already sorted and simply decide where to insert `A[n-1]` to maintain sorted order.

### Example:

Given array:

```
A = [24, 12, 8, 15, 20]
```

- **First Iteration:**  
  Compare 12 with 24 → Swap

  ```
  A = [12, 24, 8, 15, 20]
  ```

- **Second Iteration:**  
  Compare 8 with 12 and 24 → Insert at beginning

  ```
  A = [8, 12, 24, 15, 20]
  ```

- **Third Iteration:**  
  Insert 15 between 12 and 24

  ```
  A = [8, 12, 15, 24, 20]
  ```

- **Fourth Iteration:**  
  Insert 20 between 15 and 24
  ```
  A = [8, 12, 15, 20, 24]
  ```

---

### Analysis

- **Number of Elements:** `n`
- **Number of Insertions:** `n-1`

---

### Insertion Sort Algorithm

```text
1. Input: Array A of n elements
2. Output: Sorted Array A

3. for i = 1 to n-1 do
4.     v = A[i]
5.     j = i-1
6.     while j >= 0 and A[j] > v do
7.         A[j+1] = A[j]
8.         j = j-1
9.     A[j+1] = v
```

---

### Time Complexity

- **Best Case (Already Sorted):**

  - Comparisons: `n-1`
  - Shifts: `0`
  - **Time:** O(N)

- **Worst Case (Reversely Sorted):**
  - Comparisons: `1 + 2 + ... + (n-1) = (n*(n-1))/2`
  - **Time:** O(N²)

## DFS - Graph Traversal

```text
1. Input: A graph G={V,E}
2. Output: A graph G with its vertices marked with consecutive integers in order in which they have been encountered in DFS 

3. mark each vector in V with 0 as a mark of being unvisited
4. count = 0
5. for each vertex v in V
6.     if v is marked 0
7.         dfs(v)
``` 

dfs(v) - visits all the unvisited vertices connected to vertex v and assigns them the number in order they are encountered via the variable count.
```text
1. count = count+1
2. mark v with count
3. for each vertex w in V adjacent to V do
4.     if w is marked with 0 do
5.         dfs(w)
```

## BFS - Graph Traversal

```text
1. Input: A graph G={V,E}
2. Output: A graph G with its vertices marked with consecutive integers in order in which they have been encountered in BFS 

3. mark each vector in V with 0 as a mark of being unvisited
4. count = 0
5. for each vertex v in V
6.     if v is marked 0
7.         dfs(v)
``` 

dfs(v) - visits all the unvisited vertices connected to vertex v and assigns them the number in order they are encountered via the variable count.
```text
1. count = count+1
2. mark v with count and initialise queue
3. for each vertex w in V adjacent to V do
4.     if w is marked with 0 do
5.         count = count+1
6.         mark w with count
7.         add w to the queue
5.     remove v from the queue
```

### Time Complecity for BFS and DFS

1. Adjacency Matrix - `O(V^2)`
2. Adjacency List - `O(V+E)`

## Topological Sort
