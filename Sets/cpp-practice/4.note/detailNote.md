# Comprehensive Guide to Sets and Sorting Algorithms

Based on MIT 6.006 Course Notes - Detailed Explanation with C++ and JavaScript Implementations

---

## Table of Contents
1. [Set Interface](#set-interface)
2. [Sorting Fundamentals](#sorting-fundamentals)
3. [Permutation Sort](#permutation-sort)
4. [Selection Sort](#selection-sort)
5. [Insertion Sort](#insertion-sort)
6. [Merge Sort](#merge-sort)
7. [Solving Recurrences](#solving-recurrences)

---

## Set Interface

### What is a Set Data Structure?

A **set** is an abstract data type that stores a collection of unique items, each identified by a **key**. The set interface defines operations for managing and querying these items.

**Source**: *Introduction to Algorithms* (CLRS), Chapter 10-12 - Data Structures

### Three Categories of Operations

#### 1. **Container Operations**
Operations that deal with the set as a whole collection.

- **`build(X)`**: Initialize the set with items from an iterable collection X
  - Time complexity depends on implementation
  - Example: Creating a set from an array of 5 elements
  
- **`len()`**: Return the number of items currently stored
  - Should be O(1) in most implementations

#### 2. **Static Operations**
Operations for querying the set (read-only).

- **`find(k)`**: Search for and return the item with key k
  - If key doesn't exist, typically returns null/undefined
  - Performance varies: O(n) for unsorted array, O(log n) for sorted array with binary search

#### 3. **Dynamic Operations**
Operations that modify the set.

- **`insert(x)`**: Add item x to the set
  - If an item with key x.key already exists, replace it
  - Maintains set uniqueness property
  
- **`delete(k)`**: Remove and return the item with key k
  - If key doesn't exist, behavior varies by implementation

#### 4. **Order Operations**
Operations that leverage sorted order (only efficient if data is sorted).

- **`iter_ord()`**: Return items one-by-one in sorted key order
- **`find_min()`**: Return item with smallest key
- **`find_max()`**: Return item with largest key
- **`find_next(k)`**: Return item with smallest key larger than k (successor)
- **`find_prev(k)`**: Return item with largest key smaller than k (predecessor)

**Source**: MIT 6.006 Course Materials, Lecture 3

### Array-Based Set Implementations

#### Unsorted Array Implementation

**Characteristics:**
- Items stored in arbitrary order
- Simple to implement
- Poor performance for most operations

**Time Complexities:**

| Operation | Time Complexity | Reason |
|-----------|----------------|---------|
| `build(X)` | O(n) | Copy n items into array |
| `find(k)` | O(n) | Must scan entire array in worst case |
| `insert(x)` | O(n) | Must check for duplicates, possibly shift elements |
| `delete(k)` | O(n) | Must find item, then shift elements |
| `find_min()` | O(n) | Must scan entire array |
| `find_max()` | O(n) | Must scan entire array |
| `find_prev(k)` | O(n) | Must scan to find appropriate item |
| `find_next(k)` | O(n) | Must scan to find appropriate item |

**Source**: Cormen et al., *Introduction to Algorithms*, 3rd Edition, Section 10.2

#### Sorted Array Implementation

**Characteristics:**
- Items stored in increasing order by key
- Enables binary search for faster lookups
- Order operations become much more efficient

**Time Complexities:**

| Operation | Time Complexity | Reason |
|-----------|----------------|---------|
| `build(X)` | O(n log n) | Must sort n items |
| `find(k)` | O(log n) | Binary search on sorted array |
| `insert(x)` | O(n) | Binary search to find position (O(log n)), but shifting elements takes O(n) |
| `delete(k)` | O(n) | Find with binary search (O(log n)), shifting takes O(n) |
| `find_min()` | O(1) | First element in array |
| `find_max()` | O(1) | Last element in array |
| `find_prev(k)` | O(log n) | Binary search to find position |
| `find_next(k)` | O(log n) | Binary search to find position |

**Key Insight**: Sorted arrays make searching much faster (O(log n) vs O(n)), but building the sorted array efficiently requires good sorting algorithms.

**Source**: Sedgewick & Wayne, *Algorithms*, 4th Edition, Chapter 1.4 - Analysis of Algorithms

---

## Sorting Fundamentals

### What is Sorting?

**Sorting** is the process of arranging a collection of items in a specific order (typically ascending or descending).

**Formal Definition:**
- **Input**: Array A containing n elements
- **Output**: Array B that is a sorted permutation of A
  - **Permutation**: Same elements as A, possibly in different order
  - **Sorted**: B[i-1] ≤ B[i] for all i ∈ {1, 2, ..., n}

**Example**: [8, 2, 4, 9, 3] → [2, 3, 4, 8, 9]

**Source**: Knuth, *The Art of Computer Programming, Volume 3: Sorting and Searching*

### Important Sorting Terminology

#### Destructive vs Non-Destructive

- **Destructive Sort**: Overwrites the original array A
  - Modifies input directly
  - Saves memory but loses original data
  
- **Non-Destructive Sort**: Creates new array B, leaves A unchanged
  - Preserves original data
  - Requires extra memory

#### In-Place Sorting

- **In-Place Sort**: Uses O(1) extra space (constant additional memory)
  - Only uses a few extra variables (like loop counters, temp variables)
  - All in-place sorts are destructive (but not all destructive sorts are in-place)
  - Example: Only using a few integer variables regardless of input size

**Mathematical Notation**: in-place ⊆ destructive (in-place is a subset of destructive)

**Source**: CLRS, Chapter 2.1 - Insertion Sort

---

## Permutation Sort

### Algorithm Concept

**Permutation Sort** (also called **Bogosort** or **Stupid Sort**) is a highly inefficient sorting algorithm based on **brute force**: try every possible arrangement until finding the sorted one.

**How It Works:**
1. Generate all possible permutations of the input array
2. For each permutation, check if it's sorted
3. Return the first sorted permutation found

**Example with [2, 3, 1]:**

All 3! = 6 permutations:
- [1, 2, 3] ✓ (sorted!)
- [1, 3, 2] ✗
- [2, 1, 3] ✗
- [2, 3, 1] ✗
- [3, 1, 2] ✗
- [3, 2, 1] ✗

**Source**: Wikipedia contributors, "Bogosort," Wikipedia, The Free Encyclopedia

### Implementation

#### C++ Version

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Check if array is sorted in ascending order
// Time: O(n)
bool is_sorted(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}

// Permutation sort algorithm
// Time: O(n! * n) - extremely inefficient!
vector<int> permutation_sort(vector<int> arr) {
    // Sort to get first permutation
    sort(arr.begin(), arr.end());
    
    // Try all permutations
    do {
        if (is_sorted(arr)) {
            return arr;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    
    return arr;
}

int main() {
    vector<int> arr = {8, 2, 4, 9, 3};
    
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    vector<int> sorted = permutation_sort(arr);
    
    cout << "Sorted array: ";
    for (int x : sorted) cout << x << " ";
    cout << endl;
    
    return 0;
}
```

#### JavaScript Version

```javascript
// Check if array is sorted in ascending order
// Time: O(n)
function isSorted(arr) {
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}

// Generate all permutations recursively
// Time: O(n!)
function* permutations(arr) {
    if (arr.length <= 1) {
        yield arr;
        return;
    }
    
    for (let i = 0; i < arr.length; i++) {
        const rest = [...arr.slice(0, i), ...arr.slice(i + 1)];
        for (const perm of permutations(rest)) {
            yield [arr[i], ...perm];
        }
    }
}

// Permutation sort algorithm
// Time: O(n! * n) - extremely inefficient!
function permutationSort(arr) {
    for (const perm of permutations(arr)) {
        if (isSorted(perm)) {
            return perm;
        }
    }
    return arr;
}

// Example usage
const arr = [8, 2, 4, 9, 3];
console.log("Original array:", arr);
const sorted = permutationSort(arr);
console.log("Sorted array:", sorted);
```

### Analysis

**Correctness:**
- **Brute Force Approach**: Tries all possibilities, guaranteed to find solution
- For n items, there are n! (n factorial) permutations
- At least one permutation must be sorted

**Time Complexity:**
- Number of permutations: O(n!)
- Checking if sorted: O(n)
- **Total: Ω(n! × n)** (worst case could be even worse)

**Why This Is Terrible:**
- n = 5: 5! = 120 permutations
- n = 10: 10! = 3,628,800 permutations
- n = 20: 20! = 2,432,902,008,176,640,000 permutations (quintillions!)

**Factorial growth is faster than exponential growth** (like 2^n)

**Source**: Cormen et al., *Introduction to Algorithms*, Section 2.2 - Analyzing Algorithms

---

## Selection Sort

### Algorithm Concept

**Selection Sort** works by repeatedly finding the maximum element from the unsorted portion and placing it at the end of the sorted portion.

**Strategy:**
1. Find the largest element in array A[0...i]
2. Swap it with element at position i (putting it in correct final position)
3. Recursively sort the prefix A[0...i-1]
4. Repeat until entire array is sorted

**Visual Example with [8, 2, 4, 9, 3]:**

```
Step 0: [8, 2, 4, 9, 3]  - Find max in [0..4], it's 9 at index 3
Step 1: [8, 2, 4, 3, 9]  - Swapped 9 to end, now sort [0..3]
Step 2: [3, 2, 4, 8, 9]  - Found max 8 at index 0, swapped to position 3
Step 3: [3, 2, 4, 8, 9]  - Found max 4 at index 2, already in place
Step 4: [2, 3, 4, 8, 9]  - Found max 3 at index 1, swapped with position 1
Step 5: [2, 3, 4, 8, 9]  - One element left, done!
```

**Source**: Sedgewick & Wayne, *Algorithms*, 4th Edition, Section 2.1 - Elementary Sorts

### Implementation

#### C++ Version

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Find index of maximum element in array[0..i]
// Time: O(i+1) = O(n)
int prefix_max(const vector<int>& arr, int i) {
    // Base case: only one element
    if (i == 0) {
        return 0;
    }
    
    // Recursive case: max is either at position i or in prefix
    int j = prefix_max(arr, i - 1);
    
    if (arr[i] < arr[j]) {
        return j;  // Max is in the prefix
    }
    return i;  // Max is at current position
}

// Selection sort algorithm (recursive version)
// Time: O(n²)
void selection_sort_recursive(vector<int>& arr, int i) {
    // Base case: array of size 0 or 1 is already sorted
    if (i <= 0) {
        return;
    }
    
    // Find index of maximum in prefix [0..i]
    int j = prefix_max(arr, i);
    
    // Swap maximum to position i
    swap(arr[i], arr[j]);
    
    // Recursively sort prefix [0..i-1]
    selection_sort_recursive(arr, i - 1);
}

// Wrapper function
void selection_sort(vector<int>& arr) {
    if (arr.empty()) return;
    selection_sort_recursive(arr, arr.size() - 1);
}

// Iterative version (more common in practice)
void selection_sort_iterative(vector<int>& arr) {
    int n = arr.size();
    
    // Move boundary of unsorted subarray one by one
    for (int i = n - 1; i > 0; i--) {
        // Find maximum element in arr[0..i]
        int max_idx = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        
        // Swap found maximum with element at position i
        swap(arr[i], arr[max_idx]);
    }
}

int main() {
    vector<int> arr1 = {8, 2, 4, 9, 3};
    vector<int> arr2 = {8, 2, 4, 9, 3};
    
    cout << "Original array: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    selection_sort(arr1);
    cout << "Sorted (recursive): ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    selection_sort_iterative(arr2);
    cout << "Sorted (iterative): ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    
    return 0;
}
```

#### JavaScript Version

```javascript
// Find index of maximum element in array[0..i]
// Time: O(i+1) = O(n)
function prefixMax(arr, i) {
    // Base case: only one element
    if (i === 0) {
        return 0;
    }
    
    // Recursive case: max is either at position i or in prefix
    const j = prefixMax(arr, i - 1);
    
    if (arr[i] < arr[j]) {
        return j;  // Max is in the prefix
    }
    return i;  // Max is at current position
}

// Selection sort algorithm (recursive version)
// Time: O(n²)
function selectionSortRecursive(arr, i = arr.length - 1) {
    // Base case: array of size 0 or 1 is already sorted
    if (i <= 0) {
        return;
    }
    
    // Find index of maximum in prefix [0..i]
    const j = prefixMax(arr, i);
    
    // Swap maximum to position i
    [arr[i], arr[j]] = [arr[j], arr[i]];
    
    // Recursively sort prefix [0..i-1]
    selectionSortRecursive(arr, i - 1);
}

// Wrapper function
function selectionSort(arr) {
    if (arr.length === 0) return;
    selectionSortRecursive(arr, arr.length - 1);
}

// Iterative version (more common in practice)
function selectionSortIterative(arr) {
    const n = arr.length;
    
    // Move boundary of unsorted subarray one by one
    for (let i = n - 1; i > 0; i--) {
        // Find maximum element in arr[0..i]
        let maxIdx = 0;
        for (let j = 1; j <= i; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        
        // Swap found maximum with element at position i
        [arr[i], arr[maxIdx]] = [arr[maxIdx], arr[i]];
    }
}

// Example usage
const arr1 = [8, 2, 4, 9, 3];
const arr2 = [8, 2, 4, 9, 3];

console.log("Original array:", arr1);

selectionSort(arr1);
console.log("Sorted (recursive):", arr1);

selectionSortIterative(arr2);
console.log("Sorted (iterative):", arr2);
```

### Analysis

#### Correctness Proof (by Induction)

**For `prefix_max` function:**

- **Base Case**: When i = 0, array has one element, so index 0 is the maximum. ✓
- **Inductive Step**: Assume correct for i-1. For position i, the maximum is either:
  - The maximum of A[0...i-1] (found by recursion), OR
  - The element at A[i]
  - We compare both and return the correct index. ✓

**For `selection_sort` function:**

- **Base Case**: When i = 0, array has one element, so it's already sorted. ✓
- **Inductive Step**: Assume sorting works correctly for arrays of size i. For size i+1:
  - We find the largest element in A[0...i] (proven correct above)
  - Place it at position i (its final sorted position)
  - Recursively sort A[0...i-1] (correct by induction hypothesis)
  - Result is a sorted array ✓

**Source**: Cormen et al., *Introduction to Algorithms*, Section 2.1 - Loop Invariants

#### Time Complexity Analysis

**For `prefix_max`:**

Recurrence relation: S(i) = S(i-1) + Θ(1)
- S(1) = Θ(1) (base case)
- S(n) = S(n-1) + Θ(1)

**Solving by substitution:**
```
S(n) = S(n-1) + Θ(1)
     = S(n-2) + Θ(1) + Θ(1)
     = S(n-3) + Θ(1) + Θ(1) + Θ(1)
     ...
     = S(1) + (n-1)×Θ(1)
     = Θ(1) + Θ(n)
     = Θ(n)
```

**For `selection_sort`:**

Recurrence relation: T(n) = T(n-1) + Θ(n)
- T(1) = Θ(1) (base case)
- T(n) = T(n-1) + Θ(n)

**Solving by substitution:**
```
T(n) = T(n-1) + Θ(n)
     = T(n-2) + Θ(n-1) + Θ(n)
     = T(n-3) + Θ(n-2) + Θ(n-1) + Θ(n)
     ...
     = Θ(1) + Θ(2) + Θ(3) + ... + Θ(n)
     = Θ(1 + 2 + 3 + ... + n)
     = Θ(n(n+1)/2)
     = Θ(n²)
```

**Summary:**
- **Time Complexity**: O(n²) - quadratic
- **Space Complexity**: O(1) - in-place (iterative version), O(n) for recursion stack (recursive version)
- **Stability**: Not stable (equal elements may swap positions)
- **When to use**: Small datasets, when memory writes are expensive

**Source**: Knuth, *The Art of Computer Programming*, Volume 3, Section 5.2.3

---

## Insertion Sort

### Algorithm Concept

**Insertion Sort** builds the sorted array one element at a time by repeatedly inserting the next unsorted element into its correct position within the already-sorted portion.

**Strategy:**
1. Assume prefix A[0...i-1] is already sorted
2. Insert element A[i] into its correct position within the sorted prefix
3. Do this by repeatedly swapping A[i] backward until it's in the right spot
4. Repeat for all elements

**Think of it like sorting playing cards in your hand:**
- Pick up cards one at a time
- Insert each new card into its correct position among the cards you're already holding

**Visual Example with [8, 2, 4, 9, 3]:**

```
Step 0: [8 | 2, 4, 9, 3]      - 8 is "sorted", now insert 2
Step 1: [2, 8 | 4, 9, 3]      - Inserted 2 before 8, now insert 4
Step 2: [2, 4, 8 | 9, 3]      - Inserted 4 between 2 and 8, now insert 9
Step 3: [2, 4, 8, 9 | 3]      - 9 is already in place, now insert 3
Step 4: [2, 3, 4, 8, 9]       - Inserted 3 after 2
```

The `|` symbol shows the boundary between sorted and unsorted portions.

**Source**: Sedgewick & Wayne, *Algorithms*, 4th Edition, Section 2.1

### Implementation

#### C++ Version

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Insert A[i] into its correct position in the sorted prefix A[0..i]
// Time: O(i) in worst case
void insert_last(vector<int>& arr, int i) {
    // Base case: if at start or element is in correct position
    if (i <= 0 || arr[i] >= arr[i-1]) {
        return;
    }
    
    // Swap with previous element
    swap(arr[i], arr[i-1]);
    
    // Recursively insert into earlier position
    insert_last(arr, i - 1);
}

// Insertion sort algorithm (recursive version)
// Time: O(n²)
void insertion_sort_recursive(vector<int>& arr, int i) {
    // Base case: array of size 0 or 1 is already sorted
    if (i <= 0) {
        return;
    }
    
    // Recursively sort prefix [0..i-1]
    insertion_sort_recursive(arr, i - 1);
    
    // Insert element at position i into sorted prefix
    insert_last(arr, i);
}

// Wrapper function
void insertion_sort(vector<int>& arr) {
    if (arr.empty()) return;
    insertion_sort_recursive(arr, arr.size() - 1);
}

// Iterative version (more common in practice)
void insertion_sort_iterative(vector<int>& arr) {
    int n = arr.size();
    
    // Start from second element (first element is trivially sorted)
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert key at correct position
        arr[j + 1] = key;
    }
}

// Optimized iterative version with binary search for position
// Still O(n²) because of shifting, but fewer comparisons
void insertion_sort_binary(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        
        // Find position using binary search
        int pos = lower_bound(arr.begin(), arr.begin() + i, key) - arr.begin();
        
        // Shift elements to make space
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        
        // Insert key at found position
        arr[pos] = key;
    }
}

int main() {
    vector<int> arr1 = {8, 2, 4, 9, 3};
    vector<int> arr2 = {8, 2, 4, 9, 3};
    vector<int> arr3 = {8, 2, 4, 9, 3};
    
    cout << "Original array: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    insertion_sort(arr1);
    cout << "Sorted (recursive): ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    insertion_sort_iterative(arr2);
    cout << "Sorted (iterative): ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    
    insertion_sort_binary(arr3);
    cout << "Sorted (binary search): ";
    for (int x : arr3) cout << x << " ";
    cout << endl;
    
    return 0;
}
```

#### JavaScript Version

```javascript
// Insert arr[i] into its correct position in the sorted prefix arr[0..i]
// Time: O(i) in worst case
function insertLast(arr, i) {
    // Base case: if at start or element is in correct position
    if (i <= 0 || arr[i] >= arr[i-1]) {
        return;
    }
    
    // Swap with previous element
    [arr[i], arr[i-1]] = [arr[i-1], arr[i]];
    
    // Recursively insert into earlier position
    insertLast(arr, i - 1);
}

// Insertion sort algorithm (recursive version)
// Time: O(n²)
function insertionSortRecursive(arr, i = arr.length - 1) {
    // Base case: array of size 0 or 1 is already sorted
    if (i <= 0) {
        return;
    }
    
    // Recursively sort prefix [0..i-1]
    insertionSortRecursive(arr, i - 1);
    
    // Insert element at position i into sorted prefix
    insertLast(arr, i);
}

// Wrapper function
function insertionSort(arr) {
    if (arr.length === 0) return;
    insertionSortRecursive(arr, arr.length - 1);
}

// Iterative version (more common in practice)
function insertionSortIterative(arr) {
    const n = arr.length;
    
    // Start from second element (first element is trivially sorted)
    for (let i = 1; i < n; i++) {
        const key = arr[i];
        let j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert key at correct position
        arr[j + 1] = key;
    }
}

// Optimized iterative version with binary search for position
// Still O(n²) because of shifting, but fewer comparisons
function insertionSortBinary(arr) {
    const n = arr.length;
    
    for (let i = 1; i < n; i++) {
        const key = arr[i];
        
        // Find position using binary search
        let left = 0, right = i;
        while (left < right) {
            const mid = Math.floor((left + right) / 2);
            if (arr[mid] > key) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        const pos = left;
        
        // Shift elements to make space
        for (let j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        
        // Insert key at found position
        arr[pos] = key;
    }
}

// Example usage
const arr1 = [8, 2, 4, 9, 3];
const arr2 = [8, 2, 4, 9, 3];
const arr3 = [8, 2, 4, 9, 3];

console.log("Original array:", arr1);

insertionSort(arr1);
console.log("Sorted (recursive):", arr1);

insertionSortIterative(arr2);
console.log("Sorted (iterative):", arr2);

insertionSortBinary(arr3);
console.log("Sorted (binary search):", arr3);
```

### Analysis

#### Correctness Proof (by Induction)

**For `insert_last` function:**

- **Base Case**: When i = 0, element is at the start, so it's in position. ✓
- **Base Case 2**: When A[i] >= A[i-1], element is already in correct position. ✓
- **Inductive Step**: Assume correct for position i-1. If A[i] < A[i-1]:
  - We swap them, so now A[i-1] is in position
  - A[i] might still be out of position relative to A[i-2]
  - Recursively calling with i-1 ensures it gets to the right spot (by induction) ✓

**For `insertion_sort` function:**

- **Base Case**: When i = 0, array has one element, already sorted. ✓
- **Inductive Step**: Assume sorting works for arrays of size i. For size i+1:
  - Recursively sort A[0...i-1] (correct by induction)
  - Call `insert_last` to put A[i] in correct position (proven correct above)
  - Result: A[0...i] is now sorted ✓

**Source**: Cormen et al., *Introduction to Algorithms*, Section 2.1

#### Time Complexity Analysis

**For `insert_last`:**

Recurrence relation: S(i) = S(i-1) + Θ(1)
- Best case: Element already in position → O(1)
- Worst case: Element needs to move to front → O(i)
- S(n) = Θ(n)

**For `insertion_sort`:**

Recurrence relation: T(n) = T(n-1) + Θ(n)
- T(1) = Θ(1)
- T(n) = T(n-1) + Θ(n)

**This is the same recurrence as Selection Sort:**
```
T(n)= T(n-1) + Θ(n)
     = T(n-2) + Θ(n-1) + Θ(n)
     = T(n-3) + Θ(n-2) + Θ(n-1) + Θ(n)
     ...
     = Θ(1) + Θ(2) + Θ(3) + ... + Θ(n)
     = Θ(n²)
```

**Best Case Analysis:**
- If array is already sorted, each `insert_last` call returns immediately
- Time: O(n) - linear time!
- This makes insertion sort **adaptive** (performs better on nearly sorted data)

**Average Case:**
- On average, each element moves halfway back
- Still Θ(n²)

**Summary:**
- **Best Case**: O(n) - array already sorted
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - array sorted in reverse
- **Space Complexity**: O(1) - in-place (iterative), O(n) for recursion stack
- **Stability**: Stable (equal elements maintain relative order)
- **Adaptive**: Yes! Efficient for nearly sorted data
- **Online**: Can sort data as it arrives

**When to use Insertion Sort:**
- Small datasets (n < 10-20)
- Nearly sorted data
- As part of hybrid algorithms (like Timsort)
- When stability is required

**Source**: Sedgewick & Wayne, *Algorithms*, 4th Edition, Section 2.1; Knuth, *The Art of Computer Programming*, Volume 3

---

## Merge Sort

### Algorithm Concept

**Merge Sort** is a **divide-and-conquer** algorithm that recursively breaks the array into smaller subarrays, sorts them, and then merges the sorted subarrays back together.

**Divide-and-Conquer Strategy:**
1. **Divide**: Split array into two halves
2. **Conquer**: Recursively sort each half
3. **Combine**: Merge the two sorted halves into one sorted array

**Key Insight**: Merging two sorted arrays into one sorted array can be done in linear time using the **two-finger algorithm**.

**Visual Example with [7, 1, 5, 6, 2, 4, 9, 3]:**

```
Level 0:  [7, 1, 5, 6, 2, 4, 9, 3]         (original array)
          /                        \
Level 1:  [7, 1, 5, 6]            [2, 4, 9, 3]    (divide)
          /        \              /        \
Level 2: [7, 1]  [5, 6]        [2, 4]  [9, 3]      (divide more)
         /  \    /  \          /  \    /  \
Level 3: [7][1]  [5][6]        [2][4]  [9][3]      (base case - size 1)
         \  /    \  /          \  /    \  /
Level 2: [1,7]  [5,6]          [2,4]  [3,9]        (merge)
          \      /              \      /
Level 1:  [1,5,6,7]            [2,3,4,9]           (merge)
          \                    /
Level 0:  [1,2,3,4,5,6,7,9]                        (final merge)
```

**Source**: Cormen et al., *Introduction to Algorithms*, Section 2.3 - Designing Algorithms

### The Two-Finger Algorithm (Merging)

**Problem**: Given two sorted arrays L and R, merge them into one sorted array.

**Algorithm:**
- Use two "fingers" (indices), one pointing to end of L, one to end of R
- Compare elements at both fingers
- Take the larger element and place it at the end of result array
- Move that finger backward
- Repeat until all elements are placed

**Why from the back?**
- Allows in-place merging without extra temporary space
- Avoids overwriting elements we haven't processed yet

**Example Merging [1, 7] and [5, 6]:**

```
L = [1, 7]    R = [5, 6]    Result = [_, _, _, _]
     ^                ^                         ^
     i                j                         k

Compare: 7 > 6, so place 7 at position 3
L = [1, 7]    R = [5, 6]    Result = [_, _, _, 7]
     ^             ^                      ^
     i             j                      k

Compare: 6 > 1, so place 6 at position 2
L = [1, 7]    R = [5, 6]    Result = [_, _, 6, 7]
     ^          ^                   ^
     i          j                   k

Compare: 5 > 1, so place 5 at position 1
L = [1, 7]    R = [5, 6]    Result = [_, 5, 6, 7]
     ^       ^                    ^
     i       j                    k

R exhausted, copy remaining from L
L = [1, 7]    R = [5, 6]    Result = [1, 5, 6, 7]
```

**Source**: Knuth, *The Art of Computer Programming*, Volume 3, Section 5.2.4

### Implementation

#### C++ Version

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Merge two sorted subarrays L and R into array A
// L contains elements that were in A[a..c), R contains A[c..b)
// Time: O(n) where n = b - a
void merge(vector<int>& L, vector<int>& R, vector<int>& A, 
           int i, int j, int a, int b) {
    // Base case: if we've filled the result array, we're done
    if (a >= b) {
        return;
    }
    
    // Choose which array to take from
    // Take from L if: R is exhausted OR (L not exhausted AND L's element is larger)
    if (j <= 0 || (i > 0 && L[i - 1] > R[j - 1])) {
        A[b - 1] = L[i - 1];  // Place L's element
        i--;                   // Move L's finger back
    } else {
        A[b - 1] = R[j - 1];  // Place R's element
        j--;                   // Move R's finger back
    }
    
    // Recursively merge the rest
    merge(L, R, A, i, j, a, b - 1);
}

// Merge sort algorithm (recursive version)
// Sorts A[a..b)
// Time: O(n log n)
void merge_sort(vector<int>& A, int a = 0, int b = -1) {
    // Initialize b to array size on first call
    if (b == -1) {
        b = A.size();
    }
    
    // Base case: arrays of size 0 or 1 are already sorted
    if (b - a <= 1) {
        return;
    }
    
    // Find midpoint
    int c = (a + b + 1) / 2;
    
    // Recursively sort left half
    merge_sort(A, a, c);
    
    // Recursively sort right half
    merge_sort(A, c, b);
    
    // Create temporary arrays for merging
    vector<int> L(A.begin() + a, A.begin() + c);
    vector<int> R(A.begin() + c, A.begin() + b);
    
    // Merge sorted halves back into A
    merge(L, R, A, L.size(), R.size(), a, b);
}

// Iterative merge helper (more practical)
void merge_iterative(vector<int>& A, int left, int mid, int right) {
    // Create temporary arrays
    vector<int> L(A.begin() + left, A.begin() + mid);
    vector<int> R(A.begin() + mid, A.begin() + right);
    
    int i = 0, j = 0, k = left;
    
    // Merge from front (easier to understand)
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }
    
    // Copy remaining elements from L
    while (i < L.size()) {
        A[k++] = L[i++];
    }
    
    // Copy remaining elements from R
    while (j < R.size()) {
        A[k++] = R[j++];
    }
}

// Iterative merge sort (using explicit stack)
void merge_sort_iterative(vector<int>& A) {
    int n = A.size();
    
    // Start with merge subarrays of size 1, then 2, 4, 8, ...
    for (int size = 1; size < n; size *= 2) {
        // Pick starting index of left subarray
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = min(left + size, n);
            int right = min(left + 2 * size, n);
            
            merge_iterative(A, left, mid, right);
        }
    }
}

int main() {
    vector<int> arr1 = {7, 1, 5, 6, 2, 4, 9, 3};
    vector<int> arr2 = {7, 1, 5, 6, 2, 4, 9, 3};
    
    cout << "Original array: ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    merge_sort(arr1);
    cout << "Sorted (recursive): ";
    for (int x : arr1) cout << x << " ";
    cout << endl;
    
    merge_sort_iterative(arr2);
    cout << "Sorted (iterative): ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    
    return 0;
}
```

#### JavaScript Version

```javascript
// Merge two sorted subarrays L and R into array A
// L contains elements that were in A[a..c), R contains A[c..b)
// Time: O(n) where n = b - a
function merge(L, R, A, i, j, a, b) {
    // Base case: if we've filled the result array, we're done
    if (a >= b) {
        return;
    }
    
    // Choose which array to take from
    // Take from L if: R is exhausted OR (L not exhausted AND L's element is larger)
    if (j <= 0 || (i > 0 && L[i - 1] > R[j - 1])) {
        A[b - 1] = L[i - 1];  // Place L's element
        i--;                   // Move L's finger back
    } else {
        A[b - 1] = R[j - 1];  // Place R's element
        j--;                   // Move R's finger back
    }
    
    // Recursively merge the rest
    merge(L, R, A, i, j, a, b - 1);
}

// Merge sort algorithm (recursive version)
// Sorts A[a..b)
// Time: O(n log n)
function mergeSort(A, a = 0, b = null) {
    // Initialize b to array size on first call
    if (b === null) {
        b = A.length;
    }
    
    // Base case: arrays of size 0 or 1 are already sorted
    if (b - a <= 1) {
        return;
    }
    
    // Find midpoint
    const c = Math.floor((a + b + 1) / 2);
    
    // Recursively sort left half
    mergeSort(A, a, c);
    
    // Recursively sort right half
    mergeSort(A, c, b);
    
    // Create temporary arrays for merging
    const L = A.slice(a, c);
    const R = A.slice(c, b);
    
    // Merge sorted halves back into A
    merge(L, R, A, L.length, R.length, a, b);
}

// Iterative merge helper (more practical)
function mergeIterative(A, left, mid, right) {
    // Create temporary arrays
    const L = A.slice(left, mid);
    const R = A.slice(mid, right);
    
    let i = 0, j = 0, k = left;
    
    // Merge from front (easier to understand)
    while (i < L.length && j < R.length) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }
    
    // Copy remaining elements from L
    while (i < L.length) {
        A[k++] = L[i++];
    }
    
    // Copy remaining elements from R
    while (j < R.length) {
        A[k++] = R[j++];
    }
}

// Iterative merge sort (using bottom-up approach)
function mergeSortIterative(A) {
    const n = A.length;
    
    // Start with merge subarrays of size 1, then 2, 4, 8, ...
    for (let size = 1; size < n; size *= 2) {
        // Pick starting index of left subarray
        for (let left = 0; left < n - 1; left += 2 * size) {
            const mid = Math.min(left + size, n);
            const right = Math.min(left + 2 * size, n);
            
            mergeIterative(A, left, mid, right);
        }
    }
}

// Example usage
const arr1 = [7, 1, 5, 6, 2, 4, 9, 3];
const arr2 = [7, 1, 5, 6, 2, 4, 9, 3];

console.log("Original array:", arr1);

mergeSort(arr1);
console.log("Sorted (recursive):", arr1);

mergeSortIterative(arr2);
console.log("Sorted (iterative):", arr2);
```

### Analysis

#### Correctness Proof (by Induction)

**For `merge` function:**

- **Base Case**: When a >= b, we've filled the entire result array. ✓
- **Inductive Step**: Assume correct for arrays of size n-1. For size n:
  - Both L and R are sorted
  - A[b-1] must hold the largest element among all remaining elements
  - Since L and R are sorted, this is either L[i-1] or R[j-1]
  - We correctly choose the larger one
  - By induction, the remaining n-1 elements are merged correctly ✓

**For `merge_sort` function:**

- **Base Case**: When b - a <= 1, array has 0 or 1 elements, already sorted. ✓
- **Inductive Step**: Assume sorting works for arrays smaller than n. For size n:
  - Split array into two halves
  - Recursively sort each half (correct by induction, both halves are smaller)
  - Merge the sorted halves (proven correct above)
  - Result is a sorted array ✓

**Source**: Cormen et al., *Introduction to Algorithms*, Section 2.3.1

#### Time Complexity Analysis

**For `merge`:**

Recurrence relation: S(n) = S(n-1) + Θ(1)
- Each recursive call processes one element
- Total: S(n) = Θ(n)

**For `merge_sort`:**

Recurrence relation: T(n) = 2T(n/2) + Θ(n)
- T(1) = Θ(1) (base case)
- T(n) = 2T(n/2) + Θ(n)

**Method 1: Substitution**

Let's guess T(n) = Θ(n log n) and verify:

```
Assume T(n) = c·n·log(n) for some constant c

T(n) = 2T(n/2) + Θ(n)
c·n·log(n) = 2·c·(n/2)·log(n/2) + Θ(n)
c·n·log(n) = c·n·log(n/2) + Θ(n)
c·n·log(n) = c·n·(log(n) - log(2)) + Θ(n)
c·n·log(n) = c·n·log(n) - c·n·log(2) + Θ(n)

Simplifying:
0 = -c·n·log(2) + Θ(n)
c·n·log(2) = Θ(n)
c·log(2) = Θ(1)  ✓ (This is satisfied for appropriate c)
```

**Method 2: Recursion Tree**

```
Level 0:                   n                    (1 node, n work)
                         /   \
Level 1:               n/2   n/2               (2 nodes, n/2 work each = n total)
                      / \   / \
Level 2:           n/4 n/4 n/4 n/4             (4 nodes, n/4 work each = n total)
                   ...  ...  ...
Level log₂n:      1  1  1...1                  (n nodes, 1 work each = n total)

Height of tree: log₂(n) levels
Work per level: n
Total work: n × log₂(n) = Θ(n log n)
```

**Method 3: Master Theorem** (discussed in next section)

For recurrence T(n) = aT(n/b) + f(n):
- a = 2 (two subproblems)
- b = 2 (each of size n/2)
- f(n) = Θ(n)

log_b(a) = log₂(2) = 1
f(n) = Θ(n) = Θ(n^1)

Since f(n) = Θ(n^(log_b(a))), we're in **Case 2** of Master Theorem:
T(n) = Θ(n^(log_b(a)) × log n) = Θ(n log n)

**Summary:**
- **Time Complexity**: O(n log n) in all cases (best, average, worst)
- **Space Complexity**: O(n) - needs temporary arrays for merging
- **Not in-place**: Requires O(n) extra space
- **Stable**: Yes, equal elements maintain relative order
- **Not adaptive**: Same performance regardless of input order
- **Parallelizable**: Each half can be sorted independently

**When to use Merge Sort:**
- When O(n log n) worst-case time is required
- When stability is important
- For linked lists (can be done in-place)
- External sorting (data doesn't fit in memory)
- As a general-purpose sorting algorithm

**Source**: Cormen et al., *Introduction to Algorithms*, Section 2.3; Knuth, *The Art of Computer Programming*, Volume 3

---

## Solving Recurrences

Recurrence relations describe the running time of recursive algorithms. There are three main methods to solve them:

### Method 1: Substitution Method

**Steps:**
1. **Guess** the form of the solution
2. **Prove** by mathematical induction
3. **Solve** for constants

**Example from Selection Sort:**

```
T(n) = T(n-1) + Θ(n)
Guess: T(n) = Θ(n²)
Prove: T(n) = c·n² for some constant c

Base case: T(1) = c·1² = c (satisfies T(1) = Θ(1) for appropriate c)

Inductive step:
T(n) = T(n-1) + Θ(n)
c·n² = c·(n-1)² + d·n  (where d is a constant from Θ(n))
c·n² = c·(n² - 2n + 1) + d·n
c·n² = c·n² - 2cn + c + d·n
0 = -2cn + c + d·n
2cn = c + d·n
c(2n - 1/n) = d  (satisfied for large enough n and appropriate c)
```

**Source**: Cormen et al., *Introduction to Algorithms*, Section 4.3

### Method 2: Recursion Tree Method

**Steps:**
1. **Draw** a tree where each node represents cost of a subproblem
2. **Sum** costs across each level
3. **Add** costs of all levels

**Example from Merge Sort:**

```
T(n) = 2T(n/2) + cn

Tree:
                    cn              Level 0: 1 node × cn = cn
                   /  \
                cn/2  cn/2          Level 1: 2 nodes × cn/2 = cn
                / \   / \
              cn/4 cn/4 ...         Level 2: 4 nodes × cn/4 = cn
              ...

Number of levels: log₂(n) + 1
Work per level: cn
Total: cn × (log₂(n) + 1) = Θ(n log n)
```

**Source**: Cormen et al., *Introduction to Algorithms*, Section 4.4

### Method 3: Master Theorem

The **Master Theorem** provides a "cookbook" method for solving recurrences of the form:

**T(n) = aT(n/b) + f(n)**

Where:
- a ≥ 1 (number of subproblems)
- b > 1 (factor by which problem size is reduced)
- f(n) is the cost of dividing and combining

**Critical exponent**: n^(log_b(a))

**Three Cases:**

**Case 1**: If f(n) = O(n^(log_b(a) - ε)) for some ε > 0
- f(n) grows **polynomially slower** than n^(log_b(a))
- **Solution**: T(n) = Θ(n^(log_b(a)))
- **Interpretation**: Cost dominated by leaves of recursion tree

**Case 2**: If f(n) = Θ(n^(log_b(a)) × log^k(n)) for some k ≥ 0
- f(n) grows **at the same rate** as n^(log_b(a)) (times logarithmic factor)
- **Solution**: T(n) = Θ(n^(log_b(a)) × log^(k+1)(n))
- **Interpretation**: Cost evenly distributed across all levels

**Case 3**: If f(n) = Ω(n^(log_b(a) + ε)) for some ε > 0
- AND if a·f(n/b) ≤ c·f(n) for some c < 1 and large n (regularity condition)
- f(n) grows **polynomially faster** than n^(log_b(a))
- **Solution**: T(n) = Θ(f(n))
- **Interpretation**: Cost dominated by root of recursion tree

**Examples:**

**1. Merge Sort**: T(n) = 2T(n/2) + Θ(n)
- a = 2, b = 2, f(n) = Θ(n)
- n^(log_b(a)) = n^(log₂(2)) = n^1 = n
- f(n) = Θ(n) = Θ(n^1 × log^0(n))
- **Case 2 with k=0**: T(n) = Θ(n^1 × log^1(n)) = **Θ(n log n)**

**2. Binary Search**: T(n) = T(n/2) + Θ(1)
- a = 1, b = 2, f(n) = Θ(1)
- n^(log_b(a)) = n^(log₂(1)) = n^0 = 1
- f(n) = Θ(1) = Θ(n^0 × log^0(n))
- **Case 2 with k=0**: T(n) = Θ(n^0 × log^1(n)) = **Θ(log n)**

**3. Fictional algorithm**: T(n) = 4T(n/2) + Θ(n)
- a = 4, b = 2, f(n) = Θ(n)
- n^(log_b(a)) = n^(log₂(4)) = n^2
- f(n) = Θ(n) = O(n^(2-1)) = O(n^(2-ε)) with ε=1
- **Case 1**: T(n) = Θ(n^2)

**4. Fictional algorithm**: T(n) = 2T(n/2) + Θ(n²)
- a = 2, b = 2, f(n) = Θ(n²)
- n^(log_b(a)) = n^1 = n
- f(n) = Θ(n²) = Ω(n^(1+1)) = Ω(n^(1+ε)) with ε=1
- Check regularity: 2·f(n/2) = 2·(n/2)² = n²/2 ≤ c·n² for c=1/2 < 1 ✓
- **Case 3**: T(n) = Θ(n²)

**Source**: Cormen et al., *Introduction to Algorithms*, Section 4.5 - The Master Theorem

**Important Notes:**
- Master Theorem doesn't work for all recurrences
- Gaps exist between cases (e.g., f(n) = n log n doesn't fit any case for T(n) = 2T(n/2) + n log n)
- The regularity condition in Case 3 is crucial but often overlooked

---

## Comparison of Sorting Algorithms

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable | In-Place | Adaptive |
|-----------|-----------|--------------|------------|-------|--------|----------|----------|
| Permutation Sort | O(n!·n) | O(n!·n) | O(n!·n) | O(1) | Yes | Yes | No |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | Yes | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No | No |

**Source**: Sedgewick & Wayne, *Algorithms*, 4th Edition, Chapter 2

---

## Key Takeaways

1. **Sorted arrays enable efficient set operations** through binary search (O(log n) vs O(n))

2. **Building sorted arrays efficiently requires good sorting algorithms** - this motivates studying sorting

3. **Simple sorts (Selection, Insertion) are O(n²)** but have their uses:
   - Small datasets
   - Nearly sorted data (Insertion Sort)
   - Educational purposes

4. **Divide-and-conquer (Merge Sort) achieves O(n log n)**:
   - Optimal comparison-based sorting
   - Requires extra space
   - Guaranteed worst-case performance

5. **Recurrence analysis is essential** for understanding recursive algorithms:
   - Substitution for proving guesses
   - Recursion trees for visualization
   - Master Theorem for common patterns

6. **Trade-offs exist**:
   - Time vs Space (Merge Sort uses O(n) space for O(n log n) time)
   - Simplicity vs Efficiency (Insertion Sort is simple but O(n²))
   - Worst-case vs Average-case (Insertion Sort is adaptive)

**Source**: MIT 6.006 Course Materials; Cormen et al., *Introduction to Algorithms*

---

## Additional Resources

- **CLRS**: Cormen, Leiserson, Rivest, Stein - *Introduction to Algorithms*, 3rd Edition
- **Sedgewick**: Sedgewick & Wayne - *Algorithms*, 4th Edition  
- **Knuth**: Donald Knuth - *The Art of Computer Programming, Volume 3: Sorting and Searching*
- **MIT 6.006**: https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/

---

