# Space and Time Trade-Offs

## 1. Distribution Sort

### Algorithm Overview

Distribution sort is a general category of sorting algorithms that distribute elements into buckets or groups and sort each group individually. It assumes that the data can be efficiently partitioned.

Examples include counting sort, bucket sort, and radix sort.

### Complexity Analysis

* **Time Complexity**: O(n + k), where `n` is the number of elements and `k` is the range of input.
* **Space Complexity**: O(n + k), due to auxiliary storage like count arrays or buckets.

### Use Case

Efficient when the range of input data (`k`) is not significantly larger than the number of items (`n`).

```cpp
function distributionSort(arr):
    // Create an empty array of buckets based on the range of the input
    create an empty list of buckets
    
    // Distribute the elements of arr into the corresponding buckets
    for each element in arr:
        place element into the corresponding bucket based on its value
    
    // Sort each bucket individually (you can use any sorting algorithm)
    for each bucket in buckets:
        sort(bucket)
    
    // Concatenate all sorted buckets into the final sorted array
    result = concatenate all sorted buckets
    
    return result
```

---

## 2. Counting Sort

### Algorithm

1. Find the maximum element in the input array.
2. Initialize a count array of size (max+1) and store the count of each element.
3. Modify the count array by adding the previous counts (cumulative sum).
4. Place elements into the output array based on count values.
5. Copy the output array to the original array.

### Example

Input: \[4, 2, 2, 8, 3, 3, 1]
Output: \[1, 2, 2, 3, 3, 4, 8]

### Time Complexity

* **Best Case**: O(n + k)
* **Average Case**: O(n + k)
* **Worst Case**: O(n + k)

### Space Complexity

* O(n + k)

```cpp
function countingSort(arr):
    // Step 1: Find the maximum element in the input array
    max_element = findMax(arr)
    
    // Step 2: Create a count array and initialize to 0
    create count array of size (max_element + 1) and initialize all elements to 0
    
    // Step 3: Populate the count array with frequency of each element in arr
    for each element in arr:
        increment count[element]
    
    // Step 4: Modify count array by performing cumulative sum
    for i = 1 to max_element:
        count[i] += count[i-1]
    
    // Step 5: Create output array and place elements based on the count array
    create output array of the same size as arr
    for i = size of arr - 1 down to 0:
        output[count[arr[i]] - 1] = arr[i]
        decrement count[arr[i]]
    
    // Step 6: Copy the sorted elements from output to the original array
    for i = 0 to size of arr - 1:
        arr[i] = output[i]
    
    return arr
```

---

## 3. Horsepool Algorithm

### Algorithm

Horsepool is an efficient string matching algorithm that preprocesses the pattern to create a bad character shift table and then uses it for efficient searching.

### Steps

1. Create the shift table using the pattern.
2. Align the pattern with the text and compare from right to left.
3. If a mismatch occurs, shift the pattern using the value in the shift table.
4. Repeat until end of text.

### Example

Text: "I AM A STUDENT AT RV COLLEGE OF ENGINEERING"
Pattern: "COLLEGE"
Match found at position 22.

### Time Complexity

* **Best Case**: O(n/m)
* **Average Case**: O(n)
* **Worst Case**: O(mn) (highly unlikely in practice)

### Space Complexity

* O(k), where `k` is the alphabet size.

```cpp
function horspoolSearch(text, pattern):
    // Step 1: Create bad character shift table for the pattern
    create an array shift of size 256 (for all ASCII characters)
    
    // Initialize shift array: shift[i] = length of pattern for all i
    for each character c in pattern:
        shift[c] = length of pattern - position of c in pattern - 1
    
    // Step 2: Start comparing the pattern with the text from right to left
    position = 0
    while position <= length of text - length of pattern:
        j = length of pattern - 1
        // Compare characters from right to left in the pattern
        while j >= 0 and text[position + j] == pattern[j]:
            j -= 1
        if j < 0:
            // Match found at position
            return position
        else:
            // Shift position based on the bad character rule
            position += shift[text[position + length of pattern - 1]]
    
    // No match found
    return -1
```

---

## 4. Boyer-Moore Algorithm

### Algorithm

Boyer-Moore is a highly efficient string matching algorithm using both bad character and good suffix heuristics.

### Steps

1. Preprocess the pattern to build bad character and good suffix tables.
2. Compare the pattern to the text from right to left.
3. Use the larger shift between the two heuristics to skip sections of the text.
4. Continue until the pattern is found or the text ends.

### Example

Text: "HERE IS A SIMPLE EXAMPLE"
Pattern: "EXAMPLE"
Match found at position 17.

### Time Complexity

* **Best Case**: O(n/m)
* **Average Case**: O(n)
* **Worst Case**: O(mn)

### Space Complexity

* O(m + k), where `m` is the pattern length and `k` is the alphabet size.

```cpp
function boyerMooreSearch(text, pattern):
    // Step 1: Create bad character shift and good suffix shift tables for the pattern
    create bad_char_shift array for the pattern
    create good_suffix_shift array for the pattern
    
    // Step 2: Start comparing the pattern with the text from right to left
    i = length of pattern - 1
    j = length of pattern - 1
    while i <= length of text - 1:
        if pattern[j] == text[i]:
            if j == 0:
                // Match found at position i
                return i
            else:
                i -= 1
                j -= 1
        else:
            // Shift position based on the bad character and good suffix rules
            shift_value = max(bad_char_shift[text[i]], good_suffix_shift[j])
            i += shift_value
            j = length of pattern - 1
    
    // No match found
    return -1
```