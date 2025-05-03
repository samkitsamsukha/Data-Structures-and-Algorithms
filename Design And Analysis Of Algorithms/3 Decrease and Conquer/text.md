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

#### If n is even, `n = 2k`
then `J(2k) = 2J(k)-1`
Base case: `J(1) = 1`
Let's take n = 8, so k = 4
Here, `J(8) = 2J(4)-1`
`J(8) = 2[2J(2)-1]-1`
`J(8) = 4J(2)-3`
`J(8) = 4[2J(1)-1]-3`
`J(8) = 8J(1)-7`
`J(8) = 8-7 = 1`

#### If n is odd, `n=2k+1`
then `J(2k+1) = 2J(k)+1`
Base case: `J(1) = 1`
Let's take n = 7, so k = 3
then, `J(7) = 2J(3)+1`
`J(7) = 2[2J(1)+1]+1`
`J(7) = 4J(1)+3`
`J(7) = 4+3 = 7`

---

### 🪙 Fake Coin Problem 
Given `n` coins where one is **fake** and **weighs less**, identify the fake coin using a minimum number of weighings. The only allowed operation is comparing two equal-sized groups of coins using a weighing scale.

#### Strategy
1. Divide `n` coins into two equal halves.
2. If `n` is odd, set aside one coin temporarily.
3. Weigh both halves.
   * If both weigh the same, the set-aside coin is fake.
   * Else, the lighter half contains the fake coin.
4. Repeat the process recursively with the lighter group.

#### Recurrence Relation

Let `w(n)` be the number of weighings required.

* Base Case: `w(1) = 0` (No weighing needed when only one coin is left).
* Recursive Case: `w(n) = w(n/2) + 1`

This recurrence captures the fact that in each weighing, we halve the problem size and do **one** weighing.

#### Solving Using Master’s Theorem

Master’s Theorem for divide and conquer recurrences:
```
T(n) = aT(n/b) + f(n)
```
In our case:
* `a = 1` (only one recursive call)
* `b = 2` (problem size divided by 2)
* `f(n) = 1` (constant time for weighing)
Now we compare `f(n)` to `n^log_b(a)`:
* `log_b(a) = log₂(1) = 0`
* So, `n^log_b(a) = n⁰ = 1`

Since `f(n) = Θ(1)`, this matches **Case 2** of Master’s Theorem:

> If f(n) = Θ(n^log\_b(a) \* log^k n), then
> T(n) = Θ(n^log\_b(a) \* log^(k+1) n)

In our case, `k = 0`, so:

```
T(n) = Θ(log n)
```

**Time Complexity: Θ(log n)**

#### Example: n = 9 Coins

Let's step through finding the fake coin among `n = 9` coins:

##### Step 1:

* Divide into: 4 coins vs 4 coins, and set aside 1 coin.
* Weigh the two groups of 4:

  * If equal → fake coin is the one set aside.
  * If unequal → fake is in lighter group of 4.

##### Step 2:

* Take 4 coins → divide into 2 vs 2.
* Weigh the two:

  * Equal → fake is among the remaining 1 or 0.
  * Unequal → take the lighter 2.

##### Step 3:

* 2 coins → weigh 1 vs 1.

  * Lighter one is fake.

##### Total Weighings: 3 → `log₂(9) ≈ 3.17`

---

Here's a complete `.md` file content for the **Selection Problem** with a full dry run of computing the **median** using partition logic:

---

### Selection Problem – Finding the kth Smallest Element (Median)

Given a set of `n` elements, we want to find the **kth smallest element**. If `k = ceil(n/2)`, it gives the **median**.

We use the **partition-based selection algorithm** (similar to QuickSelect):

* Choose a pivot element.
* Partition the array around the pivot.
* Let `s` be the position of the pivot after partitioning.

  * If `s == k`, the pivot is the median.
  * If `s < k`, recursively search in the right half.
  * If `s > k`, recursively search in the left half.

#### Example: Compute Median of

**Array**: `4 1 10 9 7 12 8 2 15`
**n = 9** → `k = ceil(9 / 2) = 5`
Goal: Find the **5th smallest element**

#### Step 1: Initial Partition

* **Pivot** = 4 (first element)
* **i = 1** → points to 1
* **j = 15** → points to 15

##### Partition Logic:

Repeat:
* if `A[i] <= pivot`, `i++`
* if `A[j] > pivot`, `j--`
* if `i < j`, `swap(A[i], A[j])`
* if `i >= j`, `swap(A[low], A[j])` to place pivot correctly

##### Initial State:

```
[4, 1, 10, 9, 7, 12, 8, 2, 15]
 l           i                j
```

#### Dry Run:

**Iteration 1:**

* A\[i] = 1 ≤ 4 → i++

```
i = 2
```

* A\[j] = 15 > 4 → j--

```
j = 7
```

* A\[j] = 2 ≤ 4, A\[i] = 10 > 4 → swap(A\[i], A\[j])

```
Swap 10 and 2 → [4, 1, 2, 9, 7, 12, 8, 10, 15]
                l     i             j
```

```
i = 3, j = 6
```

**Iteration 2:**

* A\[i] = 9 > 4 → stay
* A\[j] = 8 > 4 → j--

```
j = 5 → A[j] = 12 > 4 → j--
j = 4 → A[j] = 7 > 4 → j--
j = 3 → A[j] = 9 > 4 → j--
j = 2 → A[j] = 2 ≤ 4
```

Now, i = 3, j = 2 → i ≥ j
Partition step ends.

#### Swap pivot with A\[j]

```
Swap 4 with 2 → [2, 1, 4, 9, 7, 12, 8, 10, 15]
               ^        j
```

* Pivot placed at index `j = 2` (0-based) ⇒ s = 3 (1-based)

#### Check:

* s = 3 < 5 → Search in **right half** (indices 3 to 8)

#### Step 2: Partition Right Half

Subarray: `[9, 7, 12, 8, 10, 15]`
New pivot = 9 (first element of subarray)
Set i = 4, j = 8

#### Dry Run 2:

**Iteration 1:**

* A\[i] = 7 ≤ 9 → i++

```
i = 5
```

* A\[j] = 15 > 9 → j--

```
j = 7 → A[j] = 10 > 9 → j--
j = 6 → A[j] = 8 ≤ 9

Swap A[i], A[j] → swap 12 and 8  
[2, 1, 4, 9, 7, 8, 12, 10, 15]
              l     i    j
```

```
i = 6, j = 5
```

* i ≥ j → swap pivot with A\[j] = 8

---

#### Swap Pivot with A\[j]

```
Swap 9 with 8 → [2, 1, 4, 8, 7, 9, 12, 10, 15]
                   ^     j
```

* Pivot placed at index 5 (0-based) ⇒ s = 6 (1-based in full array)

#### Check:

* s = 6 > 5 → Search in **left half** of this subarray (indices 3 to 4)

#### Step 3: Partition `[8, 7]`

Pivot = 8, i = 4, j = 4

* A\[j] = 7 ≤ 8 → no movement
* i = j → swap A\[3] and A\[4]

```
Swap 8 and 7 → [2, 1, 4, 7, 8, 9, 12, 10, 15]
```

Pivot placed at index 3 ⇒ s = 4 (1-based)

#### Step 4:

s = 4 < 5 → Search in index 4 (value = 8)

Now only one element → 8 is the **5th smallest**!

##### Final Answer:

**Median = 8**

#### Time Complexity

Let `c(n)` be total number of comparison.
Recurrence Relation: `c(n) = c(n/2)+(n+1)`

Applying Masters Theorem a = 1, b = 2, f(n) = O(n)
Find `n^(log_b(a)) = n^0 = 1`
Here `f(n)>n^(log_b(a))` therefore we apply case 3
**c(n) = Θ(f(n))= Θ(n)**

Let us also consider worst case scenario, 1 2 3 4 5 6 7 8
here the recurrence relation becomes `c(n) = c(n-1) + 1`, which becomes `Θ(n^2)`

### Interpolation Search

It is just an improvement over Binary Search

Input Constraint
- The elements of array should be sorted
- Array elements should be **uniformly distributed**

Which means we can have
- 10 20 30 40 50
- 2 4 6 8 10 12
- 5 20 35 50 65
and so on

Consider Array: `2 4 6 8 10 12 14 16`
We have the following variables
- `l=1`
- `r=8`
- `A[l] = 2`
- `A[r] = 16`
- To find `v=10`
- Calculate $x = l + \left\lfloor \frac{(v - A[l]) \cdot (r - l)}{A[r] - A[l]} \right\rfloor$
- `x = 1 + floor((10-2).(8-1)/(16-2))`
- `x = 1 + floor(8x7/14)`
- `x = 1 + floor(8/2)`
- `x = 1 + 4`
- `x = 5`
- compare A[5] with v and we get 10 = 10 hence search successful

Efficiency - `log_2(log_2(n))+1`