# Transform and Conquer

A problem that can be solved by transforming a given problem instance into an intermediate instance and then determining the solution.

1. **Instance Simplification** - transforming the problem into a simpler or more convenient way
   1. Presorting
   2. AVL Tree
2. **Representation Change** - transforming the problem instance into a different representation of the same problem
   1. 2-3 Tree
   2. Heap Sort
3. **Problem Reduction** - Transformation to an instance of a different problem for which the solution is already available
   1. LCM can be found out using GCD, `LCM(a,b) = axb / GCD(a,b)`

## Instance Simplification

### Presorting

It is not a direct problem solving technique, it is just an intermediate stage to solve the problem.

**Problem** - Find element uniqueness in a set of elements.

Brute Force - N^2

Sort using Merge Sort - NlogN
Compare adjacent elements - N-1 comparisons

Total Time = NlogN + N - 1
vis NlogN

**Problem** - Find the mode of a set of elements.

Brute Force - N^2

Sort using Merge Sort - NlogN
Compare adjacent elements - N-1 comparisons

Total Time = NlogN + N - 1
vis NlogN