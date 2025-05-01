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

Topological ordering of a DAG is the linear ordering of all the nodes in the graph such that if there is an edge from X to Y, X should always be placed before B in Topological Order

There are 2 methods to obtain topological sort - DFS and Vertex Deletion method (Source Removal method)

### 1. DFS Method

1. Traverse the graph using DFS
2. Note down the order in which the nodes become dead end (that is note down the popping order of nodes)
3. Reverse the popping order and get Topological Order


### 2. Vertex Removal Method

1. Calculate Indegree of all nodes
2. Place all nodes with indegree of 0 in the order
3. Decrement indegree of all nodes having an edge from node placed in step 2
4. repeat step 2 and 3 untill all nodes are placed

## Applications

### Johnson-Trotter Algorithm (Decrease by 1)

The **Johnson-Trotter algorithm** is used to generate all permutations of a given set of numbers from `1` to `n`. Unlike recursive backtracking, this algorithm generates permutations iteratively by maintaining a **direction** for each number and repeatedly identifying and moving the **largest mobile integer**.

#### Key Concepts

- **Permutation**: An arrangement of all elements of a set in a specific order.
- **Direction**: Each number has an arrow indicating movement (`←` left or `→` right).
- **Mobile Integer**: An integer `k` is **mobile** if:
  - The arrow of `k` points to an adjacent value smaller than `k`.

#### Example:
```
1 → 2 ← 3 → 4 → 5 ←
```
In this state:
- `2` is mobile (pointing to `1`)
- `5` is mobile (pointing to `4`)
- Among these, `5` is the **largest mobile integer**

#### Algorithm Steps

1. **Input**: A positive integer `n`
2. **Output**: All permutations of `{1, 2, ..., n}` in a specific Johnson-Trotter order

3. **Initialize**:
   - Start with the first permutation: `[1 ← 2 ← 3 ← ... ← n]`
   - All elements initially point to the left (`←`)

4. **Repeat until no mobile integer exists**:
   - Find the **largest mobile integer** `k`
   - Swap `k` with the adjacent number it points to
   - Reverse the direction of all numbers **greater than `k`**

#### Example for n = 3

```
Initial:       [1 ← 2 ← 3 ←]
Step 1:        [1 ← 3 ← 2 ←]   // 3 moves left (largest mobile)
Step 2:        [3 ← 1 ← 2 ←]   // 3 moves left again
Step 3:        [3 → 2 ← 1 ←]   // 2 is mobile, swap with 1, reverse direction of 3
Step 4:        [2 ← 3 → 1 ←]   // 3 is still mobile
Step 5:        [2 ← 1 ← 3 →]   // 3 is still mobile
Step 6:        [1 ← 2 ← 3 →]   // 3 has no mobile move left
```

#### Final Output

For `n = 3`, the permutations in Johnson-Trotter order are:

1. 1 2 3  
2. 1 3 2  
3. 3 1 2  
4. 3 2 1  
5. 2 3 1  
6. 2 1 3

#### Time Complexity

- Total permutations: `n!`
- Each step takes O(n) time to find the largest mobile and update directions
- **Overall Complexity**: **O(n × n!)**

#### Advantages

- Generates each permutation from the previous one by a simple swap
- Memory-efficient and iterative
- Useful in generating permutations in order (minimal-change order)

---

### Josephus Problem (Decrease by Constant Factor)

Problem Statement - 
There are n people standing in circular arrangement numbered `1` to `n`.
Starting the count with 1, eliminate every second person and tell who is the survivor at the end.

Example
1. 1 2 3 4 5 6 7
2. 1 `2` 3 4 5 6 7
3. 1 `2` 3 `4` 5 6 7
4. 1 `2` 3 `4` 5 `6` 7
5. `1` `2` 3 `4` 5 `6` 7
6. `1` `2` 3 `4` `5` `6` 7
7. `1` `2` `3` `4` `5` `6` 7
8. Survivor - `7`


### Fake Coin Problem

### Selection Problem & Interpolation Searching