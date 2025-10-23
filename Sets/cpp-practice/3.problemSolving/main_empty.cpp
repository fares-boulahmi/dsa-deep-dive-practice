#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

// ============================================================================
// HELPER FUNCTIONS
// ============================================================================

template<typename T>
void displaySet(const set<T>& s, const string& name = "Set") {
    cout << name << ": { ";
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

template<typename T>
bool compareSets(const set<T>& s1, const set<T>& s2) {
    if (s1.size() != s2.size()) return false;
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    while (it1 != s1.end()) {
        if (*it1 != *it2) return false;
        ++it1;
        ++it2;
    }
    return true;
}

// ============================================================================
// CONCEPT 1: BASIC SET OPERATIONS
// ============================================================================

// Problem 1: (Easy) - Count Unique Elements
// Given a vector of integers, return the count of unique elements using a set.
// Input: A vector of integers (may contain duplicates)
// Output: Integer representing count of unique elements
//
// Example 1:
// Input: {1, 2, 2, 3, 3, 3, 4}
// Output: 4
//
// Example 2:
// Input: {5, 5, 5, 5}
// Output: 1
//
// Example 3:
// Input: {}
// Output: 0
//
// Constraints:
// - 0 <= vector size <= 1000
// - Elements can be negative, zero, or positive
int basicOps_problem1Solution(const vector<int>& nums) {
    // TODO: Create a set from the vector and return its size
    // Hint: Set constructor can take iterators as parameters
    return 0;
}

// Problem 2: (Easy) - Check Element Existence
// Check if a specific value exists in a set of integers.
// Input: A set of integers and a target value
// Output: Boolean indicating if target exists in set
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9}, target = 5
// Output: true
//
// Example 2:
// Input: set = {2, 4, 6, 8}, target = 5
// Output: false
//
// Example 3:
// Input: set = {}, target = 1
// Output: false
//
// Constraints:
// - Set size <= 1000
// - Use set's find() or count() method
bool basicOps_problem2Solution(const set<int>& s, int target) {
    // TODO: Use find() or count() to check if target exists
    // Hint: find() returns end() if not found, count() returns 0 or 1
    return false;
}

// Problem 3: (Easy) - Remove All Even Numbers
// Remove all even numbers from a set of integers.
// Input: A set of integers
// Output: Modified set with only odd numbers
//
// Example 1:
// Input: {1, 2, 3, 4, 5, 6}
// Output: {1, 3, 5}
//
// Example 2:
// Input: {2, 4, 6, 8}
// Output: {}
//
// Example 3:
// Input: {1, 3, 5, 7}
// Output: {1, 3, 5, 7}
//
// Constraints:
// - Set size <= 1000
// - Modify the original set
// - Elements can be negative
void basicOps_problem3Solution(set<int>& s) {
    // TODO: Iterate through set and erase even numbers
    // Hint: Use iterator and erase carefully to avoid invalidation
}

// Problem 4: (Medium) - Insert and Report Duplicates
// Insert elements from a vector into a set and return count of duplicate attempts.
// Input: Empty set and vector of integers
// Output: Number of elements that were already in set (duplicates)
//
// Example 1:
// Input: vector = {1, 2, 2, 3, 3, 3}
// Output: 3 (second 2, second 3, third 3 were duplicates)
//
// Example 2:
// Input: vector = {1, 2, 3, 4, 5}
// Output: 0
//
// Example 3:
// Input: vector = {}
// Output: 0
//
// Constraints:
// - Vector size <= 1000
// - Use insert() return value to detect duplicates
int basicOps_problem4Solution(set<int>& s, const vector<int>& nums) {
    // TODO: Insert each element and count how many insertions failed
    // Hint: insert() returns pair<iterator, bool> where bool is false if element exists
    return 0;
}

// Problem 5: (Medium) - Find Missing Numbers in Range
// Given a set of integers and a range [start, end], find all missing numbers.
// Input: Set of integers, start value, end value
// Output: Vector of missing numbers in ascending order
//
// Example 1:
// Input: set = {1, 3, 5, 7}, start = 1, end = 7
// Output: {2, 4, 6}
//
// Example 2:
// Input: set = {1, 2, 3, 4, 5}, start = 1, end = 5
// Output: {}
//
// Example 3:
// Input: set = {}, start = 1, end = 3
// Output: {1, 2, 3}
//
// Constraints:
// - start <= end
// - 0 <= end - start <= 1000
// - Use find() to check existence efficiently
vector<int> basicOps_problem5Solution(const set<int>& s, int start, int end) {
    // TODO: Check each number in range and collect missing ones
    // Hint: Loop through range and use find() for O(log n) lookup
    return {};
}

// Problem 6: (Medium) - Merge Two Sets with Size Limit
// Merge two sets but keep only the smallest k elements.
// Input: Two sets of integers and integer k
// Output: New set containing smallest k elements from both sets
//
// Example 1:
// Input: set1 = {1, 5, 9}, set2 = {2, 6, 10}, k = 4
// Output: {1, 2, 5, 6}
//
// Example 2:
// Input: set1 = {3, 7}, set2 = {4, 8}, k = 10
// Output: {3, 4, 7, 8}
//
// Example 3:
// Input: set1 = {}, set2 = {1, 2, 3}, k = 2
// Output: {1, 2}
//
// Constraints:
// - k >= 0
// - Total elements <= 1000
// - Sets are already sorted (property of set)
set<int> basicOps_problem6Solution(const set<int>& s1, const set<int>& s2, int k) {
    // TODO: Merge sets and keep only first k elements
    // Hint: Use iterators and insert up to k elements
    return {};
}

// Problem 7: (Hard) - Symmetric Set Modification
// Remove elements that appear in both sets from both sets.
// Input: Two sets passed by reference
// Output: void (modify both sets in place)
//
// Example 1:
// Input: set1 = {1, 2, 3, 4}, set2 = {3, 4, 5, 6}
// Output: set1 = {1, 2}, set2 = {5, 6}
//
// Example 2:
// Input: set1 = {1, 2}, set2 = {3, 4}
// Output: set1 = {1, 2}, set2 = {3, 4}
//
// Example 3:
// Input: set1 = {1, 2, 3}, set2 = {1, 2, 3}
// Output: set1 = {}, set2 = {}
//
// Constraints:
// - Set sizes <= 1000
// - Must handle all common elements correctly
// - Optimize to avoid unnecessary iterations
void basicOps_problem7Solution(set<int>& s1, set<int>& s2) {
    // TODO: Find common elements and remove from both sets
    // Hint: Find intersection first, then erase from both
}

// Problem 8: (Hard) - Balanced Set Split
// Split a set into two sets with approximately equal sums.
// Input: Set of positive integers
// Output: Pair of sets with minimum sum difference
//
// Example 1:
// Input: {1, 2, 3, 4, 5, 6}
// Output: One possible split: ({1, 2, 3, 6}, {4, 5}) - sums: 12 and 9
//
// Example 2:
// Input: {1, 5, 11, 5}
// Output: ({11}, {1, 5, 5}) - sums: 11 and 11
//
// Example 3:
// Input: {1}
// Output: ({1}, {})
//
// Constraints:
// - All elements are positive
// - Set size <= 20 (due to complexity)
// - Return any valid split with minimum difference
pair<set<int>, set<int>> basicOps_problem8Solution(const set<int>& s) {
    // TODO: Use greedy or dynamic programming approach to split set
    // Hint: Sort elements (already sorted in set) and distribute to balance sums
    return {{}, {}};
}

// ============================================================================
// CONCEPT 2: SET ITERATORS AND TRAVERSAL
// ============================================================================

// Problem 1: (Easy) - Sum All Elements
// Calculate the sum of all elements in a set using iterators.
// Input: Set of integers
// Output: Sum of all elements
//
// Example 1:
// Input: {1, 2, 3, 4, 5}
// Output: 15
//
// Example 2:
// Input: {-5, -3, 2, 6}
// Output: 0
//
// Example 3:
// Input: {}
// Output: 0
//
// Constraints:
// - Set size <= 1000
// - Must use iterators (begin() to end())
// - Elements can be negative
int iterators_problem1Solution(const set<int>& s) {
    // TODO: Use iterators to traverse and sum all elements
    // Hint: for(auto it = s.begin(); it != s.end(); ++it)
    return 0;
}

// Problem 2: (Easy) - Get First and Last Elements
// Return the first and last elements of a set.
// Input: Non-empty set of integers
// Output: Pair containing (first, last) elements
//
// Example 1:
// Input: {3, 1, 4, 1, 5, 9}
// Output: (1, 9)
//
// Example 2:
// Input: {42}
// Output: (42, 42)
//
// Example 3:
// Input: {-10, 0, 10}
// Output: (-10, 10)
//
// Constraints:
// - Set is guaranteed to be non-empty
// - Use begin() and rbegin()
pair<int, int> iterators_problem2Solution(const set<int>& s) {
    // TODO: Access first element with begin() and last with rbegin()
    // Hint: *s.begin() gives first, *s.rbegin() gives last
    return {0, 0};
}

// Problem 3: (Easy) - Count Elements Greater Than Value
// Count how many elements in the set are greater than a given value.
// Input: Set of integers and a threshold value
// Output: Count of elements greater than threshold
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9}, threshold = 4
// Output: 3
//
// Example 2:
// Input: set = {2, 4, 6}, threshold = 10
// Output: 0
//
// Example 3:
// Input: set = {}, threshold = 5
// Output: 0
//
// Constraints:
// - Set size <= 1000
// - Use iterators to traverse
int iterators_problem3Solution(const set<int>& s, int threshold) {
    // TODO: Iterate through set and count elements > threshold
    // Hint: Simple counter with range-based for loop or iterators
    return 0;
}

// Problem 4: (Medium) - Reverse Copy to Vector
// Copy set elements to a vector in reverse order using reverse iterators.
// Input: Set of integers
// Output: Vector with elements in descending order
//
// Example 1:
// Input: {1, 3, 5, 7, 9}
// Output: {9, 7, 5, 3, 1}
//
// Example 2:
// Input: {42}
// Output: {42}
//
// Example 3:
// Input: {}
// Output: {}
//
// Constraints:
// - Set size <= 1000
// - Must use reverse iterators (rbegin() to rend())
vector<int> iterators_problem4Solution(const set<int>& s) {
    // TODO: Use reverse iterators to copy elements to vector
    // Hint: for(auto it = s.rbegin(); it != s.rend(); ++it)
    return {};
}

// Problem 5: (Medium) - Find Nth Element
// Return the nth element in the set (0-indexed).
// Input: Set of integers and index n
// Output: The nth element, or -1 if index out of bounds
//
// Example 1:
// Input: set = {10, 20, 30, 40, 50}, n = 2
// Output: 30
//
// Example 2:
// Input: set = {5, 15, 25}, n = 5
// Output: -1
//
// Example 3:
// Input: set = {100}, n = 0
// Output: 100
//
// Constraints:
// - Set size <= 1000
// - 0 <= n < set.size() for valid access
// - Use advance() or manual iteration
int iterators_problem5Solution(const set<int>& s, int n) {
    // TODO: Advance iterator n positions and return element
    // Hint: Use std::advance(iterator, n) or loop n times
    return -1;
}

// Problem 6: (Medium) - Extract Range Between Two Values
// Extract all elements between two values (inclusive) into a vector.
// Input: Set of integers, start value, end value
// Output: Vector of elements in range [start, end]
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9, 11}, start = 4, end = 9
// Output: {5, 7, 9}
//
// Example 2:
// Input: set = {2, 4, 6, 8}, start = 1, end = 3
// Output: {2}
//
// Example 3:
// Input: set = {10, 20, 30}, start = 5, end = 15
// Output: {10}
//
// Constraints:
// - start <= end
// - Set size <= 1000
// - Use iterators to find range
vector<int> iterators_problem6Solution(const set<int>& s, int start, int end) {
    // TODO: Find starting point and iterate until end value
    // Hint: Use find() or lower_bound() to locate start
    return {};
}

// Problem 7: (Hard) - Alternating Elements
// Create two sets from alternating elements (0th, 2nd, 4th... and 1st, 3rd, 5th...).
// Input: Set of integers
// Output: Pair of sets containing alternating elements
//
// Example 1:
// Input: {1, 2, 3, 4, 5, 6}
// Output: ({1, 3, 5}, {2, 4, 6})
//
// Example 2:
// Input: {10, 20, 30}
// Output: ({10, 30}, {20})
//
// Example 3:
// Input: {5}
// Output: ({5}, {})
//
// Constraints:
// - Set size <= 1000
// - Maintain sorted order in both output sets
// - Use iterators with index tracking
pair<set<int>, set<int>> iterators_problem7Solution(const set<int>& s) {
    // TODO: Iterate with index counter and distribute to two sets
    // Hint: Track position with counter, insert into appropriate set
    return {{}, {}};
}

// Problem 8: (Hard) - Skip Pattern Iterator
// Extract elements at positions matching a pattern: every kth element.
// Input: Set of integers and skip value k
// Output: Vector of every kth element (starting from position 0)
//
// Example 1:
// Input: set = {1, 2, 3, 4, 5, 6, 7, 8, 9}, k = 3
// Output: {1, 4, 7}
//
// Example 2:
// Input: set = {10, 20, 30, 40, 50}, k = 2
// Output: {10, 30, 50}
//
// Example 3:
// Input: set = {5, 15, 25}, k = 1
// Output: {5, 15, 25}
//
// Constraints:
// - k >= 1
// - Set size <= 1000
// - Must use iterators efficiently
vector<int> iterators_problem8Solution(const set<int>& s, int k) {
    // TODO: Advance iterator by k positions each time
    // Hint: Use std::advance() in loop or manual counter
    return {};
}

// ============================================================================
// CONCEPT 3: SET ALGORITHMS
// ============================================================================

// Problem 1: (Easy) - Simple Union
// Find the union of two sets (all unique elements from both).
// Input: Two sets of integers
// Output: New set containing union
//
// Example 1:
// Input: set1 = {1, 2, 3}, set2 = {3, 4, 5}
// Output: {1, 2, 3, 4, 5}
//
// Example 2:
// Input: set1 = {1, 2}, set2 = {5, 6}
// Output: {1, 2, 5, 6}
//
// Example 3:
// Input: set1 = {}, set2 = {1, 2}
// Output: {1, 2}
//
// Constraints:
// - Set sizes <= 1000
// - Use set_union algorithm
set<int> algorithms_problem1Solution(const set<int>& s1, const set<int>& s2) {
    // TODO: Use set_union with inserter
    // Hint: set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(result, result.begin()))
    return {};
}

// Problem 2: (Easy) - Simple Intersection
// Find the intersection of two sets (common elements).
// Input: Two sets of integers
// Output: New set containing intersection
//
// Example 1:
// Input: set1 = {1, 2, 3, 4}, set2 = {3, 4, 5, 6}
// Output: {3, 4}
//
// Example 2:
// Input: set1 = {1, 2}, set2 = {5, 6}
// Output: {}
//
// Example 3:
// Input: set1 = {1, 2, 3}, set2 = {1, 2, 3}
// Output: {1, 2, 3}
//
// Constraints:
// - Set sizes <= 1000
// - Use set_intersection algorithm
set<int> algorithms_problem2Solution(const set<int>& s1, const set<int>& s2) {
    // TODO: Use set_intersection with inserter
    // Hint: set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(result, result.begin()))
    return {};
}

// Problem 3: (Easy) - Check Subset
// Check if set1 is a subset of set2 (all elements of set1 are in set2).
// Input: Two sets of integers
// Output: Boolean indicating if set1 ⊆ set2
//
// Example 1:
// Input: set1 = {1, 2}, set2 = {1, 2, 3, 4}
// Output: true
//
// Example 2:
// Input: set1 = {1, 5}, set2 = {1, 2, 3, 4}
// Output: false
//
// Example 3:
// Input: set1 = {}, set2 = {1, 2}
// Output: true
//
// Constraints:
// - Set sizes <= 1000
// - Use includes() algorithm
bool algorithms_problem3Solution(const set<int>& s1, const set<int>& s2) {
    // TODO: Use includes to check if s2 contains all of s1
    // Hint: includes(s2.begin(), s2.end(), s1.begin(), s1.end())
    return false;
}

// Problem 4: (Medium) - Symmetric Difference
// Find elements that are in either set but not in both.
// Input: Two sets of integers
// Output: New set containing symmetric difference
//
// Example 1:
// Input: set1 = {1, 2, 3, 4}, set2 = {3, 4, 5, 6}
// Output: {1, 2, 5, 6}
//
// Example 2:
// Input: set1 = {1, 2}, set2 = {1, 2}
// Output: {}
//
// Example 3:
// Input: set1 = {}, set2 = {1, 2}
// Output: {1, 2}
//
// Constraints:
// - Set sizes <= 1000
// - Use set_symmetric_difference algorithm
set<int> algorithms_problem4Solution(const set<int>& s1, const set<int>& s2) {
    // TODO: Use set_symmetric_difference with inserter
    // Hint: set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(result, result.begin()))
    return {};
}

// Problem 5: (Medium) - Triple Set Intersection
// Find common elements across three sets.
// Input: Three sets of integers
// Output: New set containing elements present in all three
//
// Example 1:
// Input: set1 = {1, 2, 3, 4}, set2 = {2, 3, 4, 5}, set3 = {3, 4, 5, 6}
// Output: {3, 4}
//
// Example 2:
// Input: set1 = {1, 2}, set2 = {3, 4}, set3 = {5, 6}
// Output: {}
//
// Example 3:
// Input: set1 = {1, 2, 3}, set2 = {1, 2, 3}, set3 = {1, 2, 3}
// Output: {1, 2, 3}
//
// Constraints:
// - Set sizes <= 1000
// - Apply set_intersection twice
set<int> algorithms_problem5Solution(const set<int>& s1, const set<int>& s2, const set<int>& s3) {
    // TODO: Find intersection of first two, then intersect with third
    // Hint: temp = intersect(s1, s2), then intersect(temp, s3)
    return {};
}

// Problem 6: (Medium) - Difference Chain
// Find (A - B) - C: elements in A that are not in B or C.
// Input: Three sets of integers
// Output: New set containing A - B - C
//
// Example 1:
// Input: A = {1, 2, 3, 4, 5}, B = {2, 3}, C = {4}
// Output: {1, 5}
//
// Example 2:
// Input: A = {1, 2, 3}, B = {}, C = {}
// Output: {1, 2, 3}
//
// Example 3:
// Input: A = {1, 2, 3}, B = {1, 2, 3}, C = {}
// Output: {}
//
// Constraints:
// - Set sizes <= 1000
// - Apply set_difference twice
set<int> algorithms_problem6Solution(const set<int>& A, const set<int>& B, const set<int>& C) {
    // TODO: Find A - B, then subtract C from result
    // Hint: temp = difference(A, B), then difference(temp, C)
    return {};
}

// Problem 7: (Hard) - Partition into Disjoint Sets
// Given a universal set and a collection of subsets, verify they form a partition.
// A partition means: subsets are disjoint and their union equals universal set.
// Input: Universal set and vector of subsets
// Output: Boolean indicating if subsets form valid partition
//
// Example 1:
// Input: universal = {1, 2, 3, 4, 5}, subsets = {{1, 2}, {3, 4}, {5}}
// Output: true
//
// Example 2:
// Input: universal = {1, 2, 3, 4}, subsets = {{1, 2}, {2, 3}, {4}}
// Output: false (2 appears twice)
//
// Example 3:
// Input: universal = {1, 2, 3}, subsets = {{1, 2}}
// Output: false (missing 3)
//
// Constraints:
// - Set sizes <= 1000
// - Check both: union equals universal AND subsets are disjoint
bool algorithms_problem7Solution(const set<int>& universal, const vector<set<int>>& subsets) {
    // TODO: Verify union of subsets equals universal and no overlaps
    // Hint: Count total elements, check for duplicates, compare union with universal
    return false;
}

// Problem 8: (Hard) - Maximum Independent Set Size
// Find size of largest subset where no two elements differ by 1.
// Input: Set of integers
// Output: Size of maximum independent set
//
// Example 1:
// Input: {1, 2, 3, 4, 5}
// Output: 3 (can pick {1, 3, 5} or {2, 4})
//
// Example 2:
// Input: {1, 3, 5, 7}
// Output: 4 (all elements)
//
// Example 3:
// Input: {10, 11, 12, 13}
// Output: 2 (e.g., {10, 12} or {11, 13})
//
// Constraints:
// - Set size <= 100
// - Dynamic programming or greedy approach
// - Elements are unique (set property)
int algorithms_problem8Solution(const set<int>& s) {
    // TODO: Use DP to find maximum subset with no consecutive elements
    // Hint: Similar to "House Robber" problem
    return 0;
}

// ============================================================================
// CONCEPT 4: CUSTOM COMPARATORS
// ============================================================================

// Custom struct for problems
struct Person {
    string name;
    int age;
    
    Person(string n, int a) : name(n), age(a) {}
    
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

struct CompareByNameLength {
    bool operator()(const string& a, const string& b) const {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    }
};

// Problem 1: (Easy) - Sort Strings by Length
// Create a set of strings sorted by length (then alphabetically).
// Input: Vector of strings
// Output: Set with custom comparator sorting by length
//
// Example 1:
// Input: {"cat", "elephant", "dog", "ant"}
// Output: {"ant", "cat", "dog", "elephant"}
//
// Example 2:
// Input: {"abc", "ab", "a", "abcd"}
// Output: {"a", "ab", "abc", "abcd"}
//
// Example 3:
// Input: {"hello", "world"}
// Output: {"hello", "world"} (same length, alphabetical)
//
// Constraints:
// - Vector size <= 1000
// - Use CompareByNameLength comparator
set<string, CompareByNameLength> customComp_problem1Solution(const vector<string>& words) {
    // TODO: Insert all words into set with custom comparator
    // Hint: set<string, CompareByNameLength> result;
    return {};
}

// Problem 2: (Easy) - Count People by Age Group
// Given a set of Person objects, count how many are adults (age >= 18).
// Input: Set of Person objects
// Output: Count of adults
//
// Example 1:
// Input: {Person("Alice", 25), Person("Bob", 15), Person("Charlie", 30)}
// Output: 2
//
// Example 2:
// Input: {Person("David", 17), Person("Eve", 16)}
// Output: 0
//
// Example 3:
// Input: {}
// Output: 0
//
// Constraints:
// - Set size <= 1000
// - Age >= 0
int customComp_problem2Solution(const set<Person>& people) {
    // TODO: Count people with age >= 18
    // Hint: Simple iteration with counter
    return 0;
}

// Problem 3: (Easy) - Find Youngest Person
// Return the name of the youngest person in the set.
// Input: Non-empty set of Person objects
// Output: Name of youngest person
//
// Example 1:
// Input: {Person("Alice", 25), Person("Bob", 20), Person("Charlie", 30)}
// Output: "Bob"
//
// Example 2:
// Input: {Person("John", 40)}
// Output: "John"
//
// Example 3:
// Input: {Person("A", 10), Person("B", 10)}
// Output: "A" (first one if tie)
//
// Constraints:
// - Set is guaranteed non-empty
// - Set is sorted by age (operator<)
string customComp_problem3Solution(const set<Person>& people) {
    // TODO: Return name of first person in set
    // Hint: Set is sorted by age, so first element is youngest
    return "";
}

// Problem 4: (Medium) - Reverse Sort Numbers
// Create a set that stores integers in descending order.
// Input: Vector of integers
// Output: Set sorted in reverse order
//
// Example 1:
// Input: {1, 5, 3, 9, 2}
// Output: {9, 5, 3, 2, 1}
//
// Example 2:
// Input: {10, 20, 30}
// Output: {30, 20, 10}
//
// Example 3:
// Input: {}
// Output: {}
//// Constraints:
// - Vector size <= 1000
// - Use greater<int> as comparator
set<int, greater<int>> customComp_problem4Solution(const vector<int>& nums) {
    // TODO: Create set with greater<int> comparator for descending order
    // Hint: set<int, greater<int>> result(nums.begin(), nums.end());
    return {};
}

// Problem 5: (Medium) - Group People by Age Range
// Create multiple sets grouping people by age ranges: <18, 18-30, 31-50, >50.
// Input: Vector of Person objects
// Output: Vector of 4 sets representing each age group
//
// Example 1:
// Input: {Person("A", 15), Person("B", 25), Person("C", 40), Person("D", 60)}
// Output: [{Person("A",15)}, {Person("B",25)}, {Person("C",40)}, {Person("D",60)}]
//
// Example 2:
// Input: {Person("X", 20), Person("Y", 22)}
// Output: [{}, {Person("X",20), Person("Y",22)}, {}, {}]
//
// Example 3:
// Input: {}
// Output: [{}, {}, {}, {}]
//
// Constraints:
// - Vector size <= 1000
// - Age ranges: [0,17], [18,30], [31,50], [51,∞]
vector<set<Person>> customComp_problem5Solution(const vector<Person>& people) {
    // TODO: Create 4 sets and distribute people based on age
    // Hint: Use if-else to determine which set to insert into
    return {{}, {}, {}, {}};
}

// Problem 6: (Medium) - Case-Insensitive String Set
// Create a set that treats strings as case-insensitive.
// Input: Vector of strings (mixed case)
// Output: Set with case-insensitive comparison (keeps first occurrence)
//
// Example 1:
// Input: {"Apple", "banana", "APPLE", "Banana"}
// Output: {"Apple", "banana"} (or {"APPLE", "Banana"})
//
// Example 2:
// Input: {"hello", "HELLO", "HeLLo"}
// Output: {"hello"} (or any case variation, only one)
//
// Example 3:
// Input: {"a", "B", "c"}
// Output: {"a", "B", "c"}
//
// Constraints:
// - Vector size <= 1000
// - Custom comparator compares lowercase versions
struct CaseInsensitiveCompare {
    bool operator()(const string& a, const string& b) const {
        string lowerA = a, lowerB = b;
        transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
        transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);
        return lowerA < lowerB;
    }
};

set<string, CaseInsensitiveCompare> customComp_problem6Solution(const vector<string>& words) {
    // TODO: Insert words into set with case-insensitive comparator
    // Hint: set<string, CaseInsensitiveCompare> result;
    return {};
}

// Problem 7: (Hard) - Multi-Criteria Sorting
// Sort people by: 1) age (ascending), 2) name length (descending), 3) name (alphabetical).
// Input: Vector of Person objects
// Output: Set sorted by multiple criteria
//
// Example 1:
// Input: {Person("Alice", 25), Person("Bob", 25), Person("Charlie", 25)}
// Output: {Person("Charlie", 25), Person("Alice", 25), Person("Bob", 25)}
//
// Example 2:
// Input: {Person("A", 20), Person("B", 30), Person("C", 20)}
// Output: {Person("A", 20), Person("C", 20), Person("B", 30)}
//
// Example 3:
// Input: {Person("John", 25), Person("Jane", 25)}
// Output: {Person("John", 25), Person("Jane", 25)} (same length, alphabetical)
//
// Constraints:
// - Vector size <= 1000
// - Implement custom comparator with 3 levels
struct MultiCriteriaCompare {
    bool operator()(const Person& a, const Person& b) const {
        if (a.age != b.age) return a.age < b.age;
        if (a.name.length() != b.name.length()) return a.name.length() > b.name.length();
        return a.name < b.name;
    }
};

set<Person, MultiCriteriaCompare> customComp_problem7Solution(const vector<Person>& people) {
    // TODO: Create set with multi-criteria comparator
    // Hint: Insert all people into set<Person, MultiCriteriaCompare>
    return {};
}

// Problem 8: (Hard) - Priority-Based Task Scheduler
// Implement a task set where tasks are ordered by: priority (high to low), 
// then deadline (earliest first), then task name (alphabetical).
// Input: Vector of tasks (name, priority, deadline)
// Output: Set ordered by scheduling priority
//
// Example 1:
// Input: {Task("A",1,10), Task("B",2,5), Task("C",2,3)}
// Output: {Task("B",2,5), Task("C",2,3), Task("A",1,10)} - but sorted by comparator
//
// Example 2:
// Input: {Task("X",5,100), Task("Y",5,50), Task("Z",3,25)}
// Output: Ordered by: priority 5 first, then by deadline
//
// Constraints:
// - Vector size <= 1000
// - Priority: 1-10 (higher is more important)
// - Deadline: positive integers (lower is more urgent)
struct Task {
    string name;
    int priority;
    int deadline;
    
    Task(string n, int p, int d) : name(n), priority(p), deadline(d) {}
};

struct TaskCompare {
    bool operator()(const Task& a, const Task& b) const {
        if (a.priority != b.priority) return a.priority > b.priority; // Higher priority first
        if (a.deadline != b.deadline) return a.deadline < b.deadline; // Earlier deadline first
        return a.name < b.name; // Alphabetical
    }
};

set<Task, TaskCompare> customComp_problem8Solution(const vector<Task>& tasks) {
    // TODO: Create set with TaskCompare comparator
    // Hint: Insert all tasks into set<Task, TaskCompare>
    return {};
}

// ============================================================================
// CONCEPT 5: LOWER/UPPER BOUND OPERATIONS
// ============================================================================

// Problem 1: (Easy) - Find First Element >= Target
// Find the first element in set that is greater than or equal to target.
// Input: Set of integers and target value
// Output: The element found, or -1 if none exists
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9}, target = 4
// Output: 5
//
// Example 2:
// Input: set = {1, 3, 5, 7, 9}, target = 10
// Output: -1
//
// Example 3:
// Input: set = {2, 4, 6, 8}, target = 2
// Output: 2
//
// Constraints:
// - Set size <= 1000
// - Use lower_bound()
int bounds_problem1Solution(const set<int>& s, int target) {
    // TODO: Use lower_bound to find first element >= target
    // Hint: auto it = s.lower_bound(target); check if it != s.end()
    return -1;
}

// Problem 2: (Easy) - Find First Element > Target
// Find the first element in set that is strictly greater than target.
// Input: Set of integers and target value
// Output: The element found, or -1 if none exists
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9}, target = 5
// Output: 7
//
// Example 2:
// Input: set = {1, 3, 5, 7, 9}, target = 9
// Output: -1
//
// Example 3:
// Input: set = {2, 4, 6, 8}, target = 1
// Output: 2
//
// Constraints:
// - Set size <= 1000
// - Use upper_bound()
int bounds_problem2Solution(const set<int>& s, int target) {
    // TODO: Use upper_bound to find first element > target
    // Hint: auto it = s.upper_bound(target); check if it != s.end()
    return -1;
}

// Problem 3: (Easy) - Count Elements in Range
// Count how many elements are in the range [low, high] inclusive.
// Input: Set of integers, low and high bounds
// Output: Count of elements in range
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9}, low = 3, high = 7
// Output: 3 (elements: 3, 5, 7)
//
// Example 2:
// Input: set = {2, 4, 6, 8, 10}, low = 5, high = 9
// Output: 2 (elements: 6, 8)
//
// Example 3:
// Input: set = {1, 2, 3}, low = 10, high = 20
// Output: 0
//
// Constraints:
// - Set size <= 1000
// - low <= high
// - Use lower_bound and upper_bound
int bounds_problem3Solution(const set<int>& s, int low, int high) {
    // TODO: Use lower_bound(low) and upper_bound(high), count distance
    // Hint: distance(lower_bound(low), upper_bound(high))
    return 0;
}

// Problem 4: (Medium) - Find Closest Element
// Find the element in set closest to target value.
// Input: Set of integers and target value
// Output: Element closest to target (prefer smaller if tie)
//
// Example 1:
// Input: set = {1, 5, 10, 15, 20}, target = 12
// Output: 10 (distance 2 vs 15 with distance 3)
//
// Example 2:
// Input: set = {1, 5, 9}, target = 7
// Output: 5 (both 5 and 9 have distance 2, prefer smaller)
//
// Example 3:
// Input: set = {10}, target = 5
// Output: 10
//
// Constraints:
// - Set is guaranteed non-empty
// - Set size <= 1000
// - Use lower_bound to find candidates
int bounds_problem4Solution(const set<int>& s, int target) {
    // TODO: Use lower_bound, check element before and after
    // Hint: Compare distances to target for neighbors
    return 0;
}

// Problem 5: (Medium) - Range Sum Query
// Calculate sum of all elements in range [low, high] inclusive.
// Input: Set of integers, low and high bounds
// Output: Sum of elements in range
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9}, low = 3, high = 7
// Output: 15 (3 + 5 + 7)
//
// Example 2:
// Input: set = {2, 4, 6, 8}, low = 5, high = 7
// Output: 6
//
// Example 3:
// Input: set = {10, 20, 30}, low = 1, high = 5
// Output: 0
//
// Constraints:
// - Set size <= 1000
// - low <= high
// - Use bounds to find range, then iterate
int bounds_problem5Solution(const set<int>& s, int low, int high) {
    // TODO: Find range with bounds, iterate and sum
    // Hint: lower_bound(low) to upper_bound(high)
    return 0;
}

// Problem 6: (Medium) - Extract Subrange
// Extract all elements in range [low, high] into a new set.
// Input: Set of integers, low and high bounds
// Output: New set containing only elements in range
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9, 11}, low = 4, high = 9
// Output: {5, 7, 9}
//
// Example 2:
// Input: set = {2, 4, 6, 8}, low = 1, high = 100
// Output: {2, 4, 6, 8}
//
// Example 3:
// Input: set = {10, 20, 30}, low = 15, high = 25
// Output: {20}
//
// Constraints:
// - Set size <= 1000
// - low <= high
// - Use bounds to define range
set<int> bounds_problem6Solution(const set<int>& s, int low, int high) {
    // TODO: Use lower_bound and upper_bound to extract range
    // Hint: Copy from lower_bound(low) to upper_bound(high)
    return {};
}

// Problem 7: (Hard) - Find K Closest Elements
// Find k elements closest to target value.
// Input: Set of integers, target value, k
// Output: Vector of k closest elements (sorted)
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9}, target = 6, k = 3
// Output: {5, 7, 9} or {3, 5, 7} depending on distances
//
// Example 2:
// Input: set = {1, 2, 3, 4, 5}, target = 3, k = 2
// Output: {2, 3} or {3, 4}
//
// Example 3:
// Input: set = {10, 20, 30, 40}, target = 25, k = 2
// Output: {20, 30}
//
// Constraints:
// - k <= set.size()
// - Set size <= 1000
// - Use lower_bound as starting point
vector<int> bounds_problem7Solution(const set<int>& s, int target, int k) {
    // TODO: Find position near target, expand outward comparing distances
    // Hint: Two-pointer approach from lower_bound position
    return {};
}

// Problem 8: (Hard) - Median of Range Query
// Find median element(s) in range [low, high]. Return floor of median.
// Input: Set of integers, low and high bounds
// Output: Median value (middle element) or -1 if range empty
//
// Example 1:
// Input: set = {1, 3, 5, 7, 9}, low = 3, high = 7
// Output: 5 (middle of {3, 5, 7})
//
// Example 2:
// Input: set = {2, 4, 6, 8}, low = 2, high = 6
// Output: 4 (middle of {2, 4, 6})
//
// Example 3:
// Input: set = {10, 20, 30}, low = 5, high = 15
// Output: 10
//
// Constraints:
// - Set size <= 1000
// - low <= high
// - Use bounds and advance to middle position
int bounds_problem8Solution(const set<int>& s, int low, int high) {
    // TODO: Find range, calculate size, advance to middle
    // Hint: distance/2 to find middle position
    return -1;
}

// ============================================================================
// CONCEPT 6: SET VS UNORDERED_SET
// ============================================================================

// Problem 1: (Easy) - Convert Set to Unordered Set
// Convert a set to an unordered_set.
// Input: Set of integers
// Output: Unordered_set with same elements
//
// Example 1:
// Input: {1, 3, 5, 7, 9}
// Output: {elements in any order}
//
// Example 2:
// Input: {}
// Output: {}
//
// Example 3:
// Input: {42}
// Output: {42}
//
// Constraints:
// - Set size <= 1000
// - Order doesn't matter in output
unordered_set<int> setVsUnordered_problem1Solution(const set<int>& s) {
    // TODO: Create unordered_set from set
    // Hint: unordered_set<int> result(s.begin(), s.end());
    return {};
}

// Problem 2: (Easy) - Check Order Preservation
// Check if elements in set are in ascending order (always true for set).
// Input: Set of integers
// Output: Always true (demonstration of set property)
//
// Example 1:
// Input: {5, 1, 9, 3, 7}
// Output: true (set stores as {1, 3, 5, 7, 9})
//
// Example 2:
// Input: {100, 50, 25}
// Output: true (set stores as {25, 50, 100})
//
// Example 3:
// Input: {}
// Output: true
//
// Constraints:
// - Set size <= 1000
// - Verify by iterating
bool setVsUnordered_problem2Solution(const set<int>& s) {
    // TODO: Verify elements are in ascending order
    // Hint: Compare each element with previous
    return true;
}

// Problem 3: (Easy) - Count Lookup Operations
// Perform n lookups and return count of successful finds.
// Input: Set or unordered_set of integers, vector of queries
// Output: Count of queries found in set
//
// Example 1:
// Input: set = {1, 3, 5, 7}, queries = {1, 2, 3, 4, 5}
// Output: 3 (found: 1, 3, 5)
//
// Example 2:
// Input: set = {10, 20, 30}, queries = {5, 15, 25}
// Output: 0
//
// Example 3:
// Input: set = {}, queries = {1, 2, 3}
// Output: 0
//
// Constraints:
// - Set size <= 1000
// - Queries size <= 1000
int setVsUnordered_problem3Solution(const set<int>& s, const vector<int>& queries) {
    // TODO: For each query, check if it exists in set
    // Hint: Use find() or count() for each query
    return 0;
}

// Problem 4: (Medium) - Find When to Use Set vs Unordered Set
// Determine which container is better based on operations needed.
// Input: Boolean flags - needsSorted, needsRangeQuery, needsFastLookup
// Output: String "set" or "unordered_set"
//
// Example 1:
// Input: needsSorted = true, needsRangeQuery = false, needsFastLookup = true
// Output: "set"
//
// Example 2:
// Input: needsSorted = false, needsRangeQuery = false, needsFastLookup = true
// Output: "unordered_set"
//
// Example 3:
// Input: needsSorted = false, needsRangeQuery = true, needsFastLookup = false
// Output: "set"
//
// Constraints:
// - If needsSorted or needsRangeQuery is true, must use set
// - Otherwise, prefer unordered_set for faster lookups
string setVsUnordered_problem4Solution(bool needsSorted, bool needsRangeQuery, bool needsFastLookup) {
    // TODO: Return appropriate container based on requirements
    // Hint: set is required for sorted order or range queries
    return "set";
}

// Problem 5: (Medium) - Merge with Order Preference
// Merge two sets. If orderMatters=true, use set; else use unordered_set.
// Input: Two sets of integers, boolean orderMatters
// Output: Count of unique elements in merged result
//
// Example 1:
// Input: set1 = {1, 2, 3}, set2 = {3, 4, 5}, orderMatters = true
// Output: 5 (merged: {1, 2, 3, 4, 5})
//
// Example 2:
// Input: set1 = {1, 2}, set2 = {1, 2}, orderMatters = false
// Output: 2
//
// Example 3:
// Input: set1 = {}, set2 = {1, 2, 3}, orderMatters = true
// Output: 3
//
// Constraints:
// - Set sizes <= 1000
// - Just return count, not actual container
int setVsUnordered_problem5Solution(const set<int>& s1, const set<int>& s2, bool orderMatters) {
    // TODO: Merge into appropriate container and return size
    // Hint: Use set or unordered_set based on orderMatters flag
    return 0;
}

// Problem 6: (Medium) - Optimize Container Choice
// Given a frequency of operations, recommend set or unordered_set.
// Operations: insertCount, searchCount, rangeQueryCount
// Input: Three integers representing operation frequencies
// Output: String "set" or "unordered_set"
//
// Example 1:
// Input: insertCount = 100, searchCount = 1000, rangeQueryCount = 0
// Output: "unordered_set" (many searches, no range queries)
//
// Example 2:
// Input: insertCount = 50, searchCount = 50, rangeQueryCount = 10
// Output: "set" (needs range queries)
//
// Example 3:
// Input: insertCount = 1000, searchCount = 10, rangeQueryCount = 0
// Output: "unordered_set" (insertion-heavy, no range queries)
//
// Constraints:
// - All counts >= 0
// - If rangeQueryCount > 0, must use set
// - Otherwise, prefer unordered_set if searchCount is high
string setVsUnordered_problem6Solution(int insertCount, int searchCount, int rangeQueryCount) {
    // TODO: Analyze operation patterns and recommend container
    // Hint: Range queries require set; otherwise consider search frequency
    return "set";
}

// Problem 7: (Hard) - Hybrid Container Strategy
// Maintain data in both set and unordered_set for different operations.
// Perform inserts and return both ordered list and fast lookup capability.
// Input: Vector of integers to insert
// Output: Pair of (ordered vector from set, lookup count test result)
//
// Example 1:
// Input: {5, 1, 9, 3, 7}
// Output: (ordered: {1, 3, 5, 7, 9}, verified all lookups work)
//
// Example 2:
// Input: {10, 10, 20, 20}
// Output: (ordered: {10, 20}, verified all lookups work)
//
// Constraints:
// - Vector size <= 1000
// - Maintain consistency between both containers
// - Return ordered elements and boolean (true if all elements found)
pair<vector<int>, bool> setVsUnordered_problem7Solution(const vector<int>& nums) {
    // TODO: Insert into both set and unordered_set, verify consistency
    // Hint: Maintain both containers, extract ordered from set, verify with unordered_set
    return {{}, false};
}

// Problem 8: (Hard) - Performance Analysis Simulation
// Compare theoretical operation counts for set vs unordered_set.
// Input: Number of elements n, number of operations m
// Output: Pair of estimated operation costs (set_cost, unordered_set_cost)
//
// Example 1:
// Input: n = 1000, m = 1000 (1000 lookups in 1000 elements)
// Output: (set: ~10000 comparisons, unordered_set: ~1000 operations)
//
// Example 2:
// Input: n = 100, m = 10
// Output: (set: ~70, unordered_set: ~10)
//
// Constraints:
// - Assumptions: set = O(log n) per operation, unordered_set = O(1) average
// - Return theoretical comparison counts
// - set_cost = m * log2(n), unordered_set_cost = m * 1
pair<int, int> setVsUnordered_problem8Solution(int n, int m) {
    // TODO: Calculate theoretical costs for both containers
    // Hint: set = m * log2(n), unordered_set = m
    return {0, 0};
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 1: BASIC SET OPERATIONS
// ============================================================================

void test_basicOps_problem1() {
    cout << "\n=== Testing Basic Set Operations - Problem 1: Count Unique Elements ===" << endl;
    
    // Test 1: Normal case with duplicates
    // Manual verification: {1,2,2,3,3,3,4} has unique elements {1,2,3,4} = 4 elements
    vector<int> nums1 = {1, 2, 2, 3, 3, 3, 4};
    cout << "Test 1 - Input: {1, 2, 2, 3, 3, 3, 4}" << endl;
    int result1 = basicOps_problem1Solution(nums1);
    cout << "Expected: 4" << endl;
    cout << "Got: " << result1 << endl;
    cout << "Result: " << (result1 == 4 ? "PASS" : "FAIL") << endl;
    
    // Test 2: All same elements
    // Manual verification: {5,5,5,5} has only 1 unique element
    vector<int> nums2 = {5, 5, 5, 5};
    cout << "\nTest 2 - Input: {5, 5, 5, 5}" << endl;
    int result2 = basicOps_problem1Solution(nums2);
    cout << "Expected: 1" << endl;
    cout << "Got: " << result2 << endl;
    cout << "Result: " << (result2 == 1 ? "PASS" : "FAIL") << endl;
    
    // Test 3: Empty vector
    // Manual verification: Empty vector has 0 unique elements
    vector<int> nums3 = {};
    cout << "\nTest 3 - Input: {}" << endl;
    int result3 = basicOps_problem1Solution(nums3);
    cout << "Expected: 0" << endl;
    cout << "Got: " << result3 << endl;
    cout << "Result: " << (result3 == 0 ? "PASS" : "FAIL") << endl;
    
    // Test 4: All unique elements
    // Manual verification: {1,2,3,4,5} has 5 unique elements
    vector<int> nums4 = {1, 2, 3, 4, 5};
    cout << "\nTest 4 - Input: {1, 2, 3, 4, 5}" << endl;
    int result4 = basicOps_problem1Solution(nums4);
    cout << "Expected: 5" << endl;
    cout << "Got: " << result4 << endl;
    cout << "Result: " << (result4 == 5 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Negative numbers with duplicates
    // Manual verification: {-1,-1,0,0,1,1} has unique {-1,0,1} = 3 elements
    vector<int> nums5 = {-1, -1, 0, 0, 1, 1};
    cout << "\nTest 5 - Input: {-1, -1, 0, 0, 1, 1}" << endl;
    int result5 = basicOps_problem1Solution(nums5);
    cout << "Expected: 3" << endl;
    cout << "Got: " << result5 << endl;
    cout << "Result: " << (result5 == 3 ? "PASS" : "FAIL") << endl;
}

void test_basicOps_problem2() {
    cout << "\n=== Testing Basic Set Operations - Problem 2: Check Element Existence ===" << endl;
    
    // Test 1: Element exists in middle
    // Manual verification: 5 is in {1,3,5,7,9}
    set<int> s1 = {1, 3, 5, 7, 9};
    cout << "Test 1 - Input: set = {1, 3, 5, 7, 9}, target = 5" << endl;
    bool result1 = basicOps_problem2Solution(s1, 5);
    cout << "Expected: true (1)" << endl;
    cout << "Got: " << result1 << endl;
    cout << "Result: " << (result1 == true ? "PASS" : "FAIL") << endl;
    
    // Test 2: Element doesn't exist
    // Manual verification: 5 is not in {2,4,6,8}
    set<int> s2 = {2, 4, 6, 8};
    cout << "\nTest 2 - Input: set = {2, 4, 6, 8}, target = 5" << endl;
    bool result2 = basicOps_problem2Solution(s2, 5);
    cout << "Expected: false (0)" << endl;
    cout << "Got: " << result2 << endl;
    cout << "Result: " << (result2 == false ? "PASS" : "FAIL") << endl;
    
    // Test 3: Empty set
    // Manual verification: Any element in empty set returns false
    set<int> s3 = {};
    cout << "\nTest 3 - Input: set = {}, target = 1" << endl;
    bool result3 = basicOps_problem2Solution(s3, 1);
    cout << "Expected: false (0)" << endl;
    cout << "Got: " << result3 << endl;
    cout << "Result: " << (result3 == false ? "PASS" : "FAIL") << endl;
    
    // Test 4: First element
    // Manual verification: 1 is the first element in {1,2,3}
    set<int> s4 = {1, 2, 3};
    cout << "\nTest 4 - Input: set = {1, 2, 3}, target = 1" << endl;
    bool result4 = basicOps_problem2Solution(s4, 1);
    cout << "Expected: true (1)" << endl;
    cout << "Got: " << result4 << endl;
    cout << "Result: " << (result4 == true ? "PASS" : "FAIL") << endl;
    
    // Test 5: Last element
    // Manual verification: 100 is the last element in {10,50,100}
    set<int> s5 = {10, 50, 100};
    cout << "\nTest 5 - Input: set = {10, 50, 100}, target = 100" << endl;
    bool result5 = basicOps_problem2Solution(s5, 100);
    cout << "Expected: true (1)" << endl;
    cout << "Got: " << result5 << endl;
    cout << "Result: " << (result5 == true ? "PASS" : "FAIL") << endl;
}

void test_basicOps_problem3() {
    cout << "\n=== Testing Basic Set Operations - Problem 3: Remove All Even Numbers ===" << endl;
    
    // Test 1: Mixed odd and even
    // Manual verification: {1,2,3,4,5,6} after removing evens {2,4,6} should be {1,3,5}
    set<int> s1 = {1, 2, 3, 4, 5, 6};
    cout << "Test 1 - Input: {1, 2, 3, 4, 5, 6}" << endl;
    basicOps_problem3Solution(s1);
    set<int> expected1 = {1, 3, 5};
    cout << "Expected: {1, 3, 5}" << endl;
    cout << "Got: ";
    displaySet(s1, "");
    cout << "Result: " << (compareSets(s1, expected1) ? "PASS" : "FAIL") << endl;
    
    // Test 2: All even numbers
    // Manual verification: {2,4,6,8} after removing all evens should be {}
    set<int> s2 = {2, 4, 6, 8};
    cout << "\nTest 2 - Input: {2, 4, 6, 8}" << endl;
    basicOps_problem3Solution(s2);
    set<int> expected2 = {};
    cout << "Expected: {}" << endl;
    cout << "Got: ";
    displaySet(s2, "");
    cout << "Result: " << (compareSets(s2, expected2) ? "PASS" : "FAIL") << endl;
    
    // Test 3: All odd numbers
    // Manual verification: {1,3,5,7} has no evens, should remain {1,3,5,7}
    set<int> s3 = {1, 3, 5, 7};
    cout << "\nTest 3 - Input: {1, 3, 5, 7}" << endl;
    basicOps_problem3Solution(s3);
    set<int> expected3 = {1, 3, 5, 7};
    cout << "Expected: {1, 3, 5, 7}" << endl;
    cout << "Got: ";
    displaySet(s3, "");
    cout << "Result: " << (compareSets(s3, expected3) ? "PASS" : "FAIL") << endl;
    
    // Test 4: Negative numbers
    // Manual verification: {-4,-3,-2,-1,0,1,2} remove evens {-4,-2,0,2} leaves {-3,-1,1}
    set<int> s4 = {-4, -3, -2, -1, 0, 1, 2};
    cout << "\nTest 4 - Input: {-4, -3, -2, -1, 0, 1, 2}" << endl;
    basicOps_problem3Solution(s4);
    set<int> expected4 = {-3, -1, 1};
    cout << "Expected: {-3, -1, 1}" << endl;
    cout << "Got: ";
    displaySet(s4, "");
    cout << "Result: " << (compareSets(s4, expected4) ? "PASS" : "FAIL") << endl;
    
    // Test 5: Empty set
    // Manual verification: Empty set remains empty
    set<int> s5 = {};
    cout << "\nTest 5 - Input: {}" << endl;
    basicOps_problem3Solution(s5);
    set<int> expected5 = {};
    cout << "Expected: {}" << endl;
    cout << "Got: ";
    displaySet(s5, "");
    cout << "Result: " << (compareSets(s5, expected5) ? "PASS" : "FAIL") << endl;
}

void test_basicOps_problem4() {
    cout << "\n=== Testing Basic Set Operations - Problem 4: Insert and Report Duplicates ===" << endl;
    
    // Test 1: Multiple duplicates
    // Manual verification: {1,2,2,3,3,3} - first insert of each succeeds, then 1 duplicate 2, 2 duplicate 3s = 3 duplicates
    set<int> s1;
    vector<int> nums1 = {1, 2, 2, 3, 3, 3};
    cout << "Test 1 - Input: {1, 2, 2, 3, 3, 3}" << endl;
    int result1 = basicOps_problem4Solution(s1, nums1);
    cout << "Expected: 3" << endl;
    cout << "Got: " << result1 << endl;
    cout << "Result: " << (result1 == 3 ? "PASS" : "FAIL") << endl;
    
    // Test 2: No duplicates
    // Manual verification: {1,2,3,4,5} all unique, 0 duplicates
    set<int> s2;
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "\nTest 2 - Input: {1, 2, 3, 4, 5}" << endl;
    int result2 = basicOps_problem4Solution(s2, nums2);
    cout << "Expected: 0" << endl;
    cout << "Got: " << result2 << endl;
    cout << "Result: " << (result2 == 0 ? "PASS" : "FAIL") << endl;
    
    // Test 3: Empty vector
    // Manual verification: Empty vector has 0 duplicates
    set<int> s3;
    vector<int> nums3 = {};
    cout << "\nTest 3 - Input: {}" << endl;
    int result3 = basicOps_problem4Solution(s3, nums3);
    cout << "Expected: 0" << endl;
    cout << "Got: " << result3 << endl;
    cout << "Result: " << (result3 == 0 ? "PASS" : "FAIL") << endl;
    
    // Test 4: All same elements
    // Manual verification: {5,5,5,5,5} - first succeeds, 4 are duplicates
    set<int> s4;
    vector<int> nums4 = {5, 5, 5, 5, 5};
    cout << "\nTest 4 - Input: {5, 5, 5, 5, 5}" << endl;
    int result4 = basicOps_problem4Solution(s4, nums4);
    cout << "Expected: 4" << endl;
    cout << "Got: " << result4 << endl;
    cout << "Result: " << (result4 == 4 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Two pairs of duplicates
    // Manual verification: {1,1,2,2} - 2 duplicates total
    set<int> s5;
    vector<int> nums5 = {1, 1, 2, 2};
    cout << "\nTest 5 - Input: {1, 1, 2, 2}" << endl;
    int result5 = basicOps_problem4Solution(s5, nums5);
    cout << "Expected: 2" << endl;
    cout << "Got: " << result5 << endl;
    cout << "Result: " << (result5 == 2 ? "PASS" : "FAIL") << endl;
}

void test_basicOps_problem5() {
    cout << "\n=== Testing Basic Set Operations - Problem 5: Find Missing Numbers in Range ===" << endl;
    
    // Test 1: Some missing numbers
    // Manual verification: Range [1,7] with {1,3,5,7} missing {2,4,6}
    set<int> s1 = {1, 3, 5, 7};
    cout << "Test 1 - Input: set = {1, 3, 5, 7}, range [1, 7]" << endl;
    vector<int> result1 = basicOps_problem5Solution(s1, 1, 7);
    vector<int> expected1 = {2, 4, 6};
    cout << "Expected: {2, 4, 6}" << endl;
    cout << "Got: { ";
    for (int x : result1) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    
    // Test 2: No missing numbers
    // Manual verification: Range [1,5] with {1,2,3,4,5} missing {}
    set<int> s2 = {1, 2, 3, 4, 5};
    cout << "\nTest 2 - Input: set = {1, 2, 3, 4, 5}, range [1, 5]" << endl;
    vector<int> result2 = basicOps_problem5Solution(s2, 1, 5);
    vector<int> expected2 = {};
    cout << "Expected: {}" << endl;
    cout << "Got: { ";
    for (int x : result2) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    
    // Test 3: All missing
    // Manual verification: Range [1,3] with empty set missing {1,2,3}
    set<int> s3 = {};
    cout << "\nTest 3 - Input: set = {}, range [1, 3]" << endl;
    vector<int> result3 = basicOps_problem5Solution(s3, 1, 3);
    vector<int> expected3 = {1, 2, 3};
    cout << "Expected: {1, 2, 3}" << endl;
    cout << "Got: { ";
    for (int x : result3) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;
    
    // Test 4: Set has extra elements outside range
    // Manual verification: Range [5,8] with {1,3,5,7,9,11} missing {6,8}
    set<int> s4 = {1, 3, 5, 7, 9, 11};
    cout << "\nTest 4 - Input: set = {1, 3, 5, 7, 9, 11}, range [5, 8]" << endl;
    vector<int> result4 = basicOps_problem5Solution(s4, 5, 8);
    vector<int> expected4 = {6, 8};
    cout << "Expected: {6, 8}" << endl;
    cout << "Got: { ";
    for (int x : result4) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Single element range
    // Manual verification: Range [5,5] with {1,2,3} missing {5}
    set<int> s5 = {1, 2, 3};
    cout << "\nTest 5 - Input: set = {1, 2, 3}, range [5, 5]" << endl;
    vector<int> result5 = basicOps_problem5Solution(s5, 5, 5);
    vector<int> expected5 = {5};
    cout << "Expected: {5}" << endl;
    cout << "Got: { ";
    for (int x : result5) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

void test_basicOps_problem6() {
    cout << "\n=== Testing Basic Set Operations - Problem 6: Merge Two Sets with Size Limit ===" << endl;
    
    // Test 1: k smaller than total elements
    // Manual verification: {1,5,9} + {2,6,10} = {1,2,5,6,9,10}, first 4 are {1,2,5,6}
    set<int> s1 = {1, 5, 9};
    set<int> s2 = {2, 6, 10};
    cout << "Test 1 - Input: set1 = {1, 5, 9}, set2 = {2, 6, 10}, k = 4" << endl;
    set<int> result1 = basicOps_problem6Solution(s1, s2, 4);
    set<int> expected1 = {1, 2, 5, 6};
    cout << "Expected: {1, 2, 5, 6}" << endl;
    cout << "Got: ";
    displaySet(result1, "");
    cout << "Result: " << (compareSets(result1, expected1) ? "PASS" : "FAIL") << endl;
    
    // Test 2: k larger than total elements
    // Manual verification: {3,7} + {4,8} = {3,4,7,8}, all 4 fit in k=10
    set<int> s3 = {3, 7};
    set<int> s4 = {4, 8};
    cout << "\nTest 2 - Input: set1 = {3, 7}, set2 = {4, 8}, k = 10" << endl;
    set<int> result2 = basicOps_problem6Solution(s3, s4, 10);
    set<int> expected2 = {3, 4, 7, 8};
    cout << "Expected: {3, 4, 7, 8}" << endl;
    cout << "Got: ";
    displaySet(result2, "");
    cout << "Result: " << (compareSets(result2, expected2) ? "PASS" : "FAIL") << endl;
    
    // Test 3: One empty set
    // Manual verification: {} + {1,2,3} with k=2 should give {1,2}
    set<int> s5 = {};
    set<int> s6 = {1, 2, 3};
    cout << "\nTest 3 - Input: set1 = {}, set2 = {1, 2, 3}, k = 2" << endl;
    set<int> result3 = basicOps_problem6Solution(s5, s6, 2);
    set<int> expected3 = {1, 2};
    cout << "Expected: {1, 2}" << endl;
    cout << "Got: ";
    displaySet(result3, "");
    cout << "Result: " << (compareSets(result3, expected3) ? "PASS" : "FAIL") << endl;
    
    // Test 4: k = 0
    // Manual verification: Any sets with k=0 should give empty result
    set<int> s7 = {1, 2, 3};
    set<int> s8 = {4, 5, 6};
    cout << "\nTest 4 - Input: set1 = {1, 2, 3}, set2 = {4, 5, 6}, k = 0" << endl;
    set<int> result4 = basicOps_problem6Solution(s7, s8, 0);
    set<int> expected4 = {};
    cout << "Expected: {}" << endl;
    cout << "Got: ";
    displaySet(result4, "");
    cout << "Result: " << (compareSets(result4, expected4) ? "PASS" : "FAIL") << endl;
    
    // Test 5: Overlapping sets
    // Manual verification: {1,2,3} + {2,3,4} = {1,2,3,4}, first 3 are {1,2,3}
    set<int> s9 = {1, 2, 3};
    set<int> s10 = {2, 3, 4};
    cout << "\nTest 5 - Input: set1 = {1, 2, 3}, set2 = {2, 3, 4}, k = 3" << endl;
    set<int> result5 = basicOps_problem6Solution(s9, s10, 3);
    set<int> expected5 = {1, 2, 3};
    cout << "Expected: {1, 2, 3}" << endl;
    cout << "Got: ";
    displaySet(result5, "");
    cout << "Result: " << (compareSets(result5, expected5) ? "PASS" : "FAIL") << endl;
}

void test_basicOps_problem7() {
    cout << "\n=== Testing Basic Set Operations - Problem 7: Symmetric Set Modification ===" << endl;
    
    // Test 1: Some common elements
    // Manual verification: {1,2,3,4} ∩ {3,4,5,6} = {3,4}, remove from both leaves {1,2} and {5,6}
    set<int> s1 = {1, 2, 3, 4};
    set<int> s2 = {3, 4, 5, 6};
    cout << "Test 1 - Input: set1 = {1, 2, 3, 4}, set2 = {3, 4, 5, 6}" << endl;
    basicOps_problem7Solution(s1, s2);
    set<int> expected1_1 = {1, 2};
    set<int> expected1_2 = {5, 6};
    cout << "Expected: set1 = {1, 2}, set2 = {5, 6}" << endl;
    cout << "Got: set1 = ";
    displaySet(s1, "");
    cout << "     set2 = ";
    displaySet(s2, "");
    cout << "Result: " << (compareSets(s1, expected1_1) && compareSets(s2, expected1_2) ? "PASS" : "FAIL") << endl;
    
    // Test 2: No common elements
    // Manual verification: {1,2} ∩ {3,4} = {}, nothing to remove, both stay same
    set<int> s3 = {1, 2};
    set<int> s4 = {3, 4};
    cout << "\nTest 2 - Input: set1 = {1, 2}, set2 = {3, 4}" << endl;
    basicOps_problem7Solution(s3, s4);
    set<int> expected2_1 = {1, 2};
    set<int> expected2_2 = {3, 4};
    cout << "Expected: set1 = {1, 2}, set2 = {3, 4}" << endl;
    cout << "Got: set1 = ";
    displaySet(s3, "");
    cout << "     set2 = ";
    displaySet(s4, "");
    cout << "Result: " << (compareSets(s3, expected2_1) && compareSets(s4, expected2_2) ? "PASS" : "FAIL") << endl;
    
    // Test 3: All common elements
    // Manual verification: {1,2,3} ∩ {1,2,3} = {1,2,3}, remove all, both become empty
    set<int> s5 = {1, 2, 3};
    set<int> s6 = {1, 2, 3};
    cout << "\nTest 3 - Input: set1 = {1, 2, 3}, set2 = {1, 2, 3}" << endl;
    basicOps_problem7Solution(s5, s6);
    set<int> expected3_1 = {};
    set<int> expected3_2 = {};
    cout << "Expected: set1 = {}, set2 = {}" << endl;
    cout << "Got: set1 = ";
    displaySet(s5, "");
    cout << "     set2 = ";
    displaySet(s6, "");
    cout << "Result: " << (compareSets(s5, expected3_1) && compareSets(s6, expected3_2) ? "PASS" : "FAIL") << endl;
    
    // Test 4: One empty set
    // Manual verification: {} ∩ {1,2,3} = {}, nothing to remove, both stay same
    set<int> s7 = {};
    set<int> s8 = {1, 2, 3};
    cout << "\nTest 4 - Input: set1 = {}, set2 = {1, 2, 3}" << endl;
    basicOps_problem7Solution(s7, s8);
    set<int> expected4_1 = {};
    set<int> expected4_2 = {1, 2, 3};
    cout << "Expected: set1 = {}, set2 = {1, 2, 3}" << endl;
    cout << "Got: set1 = ";
    displaySet(s7, "");
    cout << "     set2 = ";
    displaySet(s8, "");
    cout << "Result: " << (compareSets(s7, expected4_1) && compareSets(s8, expected4_2) ? "PASS" : "FAIL") << endl;
    
    // Test 5: Single common element
    // Manual verification: {1,2,3,4,5} ∩ {5,6,7} = {5}, remove 5 from both
    set<int> s9 = {1, 2, 3, 4, 5};
    set<int> s10 = {5, 6, 7};
    cout << "\nTest 5 - Input: set1 = {1, 2, 3, 4, 5}, set2 = {5, 6, 7}" << endl;
    basicOps_problem7Solution(s9, s10);
    set<int> expected5_1 = {1, 2, 3, 4};
    set<int> expected5_2 = {6, 7};
    cout << "Expected: set1 = {1, 2, 3, 4}, set2 = {6, 7}" << endl;
    cout << "Got: set1 = ";
    displaySet(s9, "");
    cout << "     set2 = ";
    displaySet(s10, "");
    cout << "Result: " << (compareSets(s9, expected5_1) && compareSets(s10, expected5_2) ? "PASS" : "FAIL") << endl;
}

void test_basicOps_problem8() {
    cout << "\n=== Testing Basic Set Operations - Problem 8: Balanced Set Split ===" << endl;
    
    // Test 1: Even split possible
    // Manual verification: {1,2,3,4,5,6} sum=21, can split to sums ~10.5 each
    set<int> s1 = {1, 2, 3, 4, 5, 6};
    cout << "Test 1 - Input: {1, 2, 3, 4, 5, 6} (sum = 21)" << endl;
    auto result1 = basicOps_problem8Solution(s1);
    int sum1_1 = 0, sum1_2 = 0;
    for (int x : result1.first) sum1_1 += x;
    for (int x : result1.second) sum1_2 += x;
    cout << "Expected: Two sets with sums close to 10-11" << endl;
    cout << "Got: Set1 sum = " << sum1_1 << ", Set2 sum = " << sum1_2 << endl;
    cout << "     Difference = " << abs(sum1_1 - sum1_2) << endl;
    cout << "Result: " << (abs(sum1_1 - sum1_2) <= 3 ? "PASS" : "FAIL") << " (difference <= 3)" << endl;
    
    // Test 2: Perfect split possible
    // Manual verification: {1,5,11,5} sum=22, can split to 11 each: {11} and {1,5,5}
    set<int> s2 = {1, 5, 11};
    cout << "\nTest 2 - Input: {1, 5, 11} (sum = 17)" << endl;
    auto result2 = basicOps_problem8Solution(s2);
    int sum2_1 = 0, sum2_2 = 0;
    for (int x : result2.first) sum2_1 += x;
    for (int x : result2.second) sum2_2 += x;
    cout << "Expected: Two sets with minimal difference" << endl;
    cout << "Got: Set1 sum = " << sum2_1 << ", Set2 sum = " << sum2_2 << endl;
    cout << "     Difference = " << abs(sum2_1 - sum2_2) << endl;
    cout << "Result: " << (abs(sum2_1 - sum2_2) <= 5 ? "PASS" : "FAIL") << " (difference <= 5)" << endl;
    
    // Test 3: Single element
    // Manual verification: {1} can only split to {1} and {}
    set<int> s3 = {1};
    cout << "\nTest 3 - Input: {1}" << endl;
    auto result3 = basicOps_problem8Solution(s3);
    int sum3_1 = 0, sum3_2 = 0;
    for (int x : result3.first) sum3_1 += x;
    for (int x : result3.second) sum3_2 += x;
    cout << "Expected: One set has 1, other is empty" << endl;
    cout << "Got: Set1 sum = " << sum3_1 << ", Set2 sum = " << sum3_2 << endl;
    cout << "Result: " << ((sum3_1 == 1 && sum3_2 == 0) || (sum3_1 == 0 && sum3_2 == 1) ? "PASS" : "FAIL") << endl;
    
    // Test 4: Two elements
    // Manual verification: {10,20} sum=30, split to {10} and {20} or {20} and {10}
    set<int> s4 = {10, 20};
    cout << "\nTest 4 - Input: {10, 20} (sum = 30)" << endl;
    auto result4 = basicOps_problem8Solution(s4);
    int sum4_1 = 0, sum4_2 = 0;
    for (int x : result4.first) sum4_1 += x;
    for (int x : result4.second) sum4_2 += x;
    cout << "Expected: Sums of 10 and 20 (difference = 10)" << endl;
    cout << "Got: Set1 sum = " << sum4_1 << ", Set2 sum = " << sum4_2 << endl;
    cout << "     Difference = " << abs(sum4_1 - sum4_2) << endl;
    cout << "Result: " << (abs(sum4_1 - sum4_2) == 10 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Large values
    // Manual verification: {100,200,300} sum=600, best split could be {100,200} and {300}
    set<int> s5 = {100, 200, 300};
    cout << "\nTest 5 - Input: {100, 200, 300} (sum = 600)" << endl;
    auto result5 = basicOps_problem8Solution(s5);
    int sum5_1 = 0, sum5_2 = 0;
    for (int x : result5.first) sum5_1 += x;
    for (int x : result5.second) sum5_2 += x;
    cout << "Expected: Close to 300 each" << endl;
    cout << "Got: Set1 sum = " << sum5_1 << ", Set2 sum = " << sum5_2 << endl;
    cout << "     Difference = " << abs(sum5_1 - sum5_2) << endl;
    cout << "Result: " << (sum5_1 + sum5_2 == 600 ? "PASS" : "FAIL") << " (total preserved)" << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 2: ITERATORS AND TRAVERSAL
// ============================================================================

void test_iterators_problem1() {
    cout << "\n=== Testing Iterators and Traversal - Problem 1: Sum All Elements ===" << endl;
    
    // Test 1: Positive numbers
    // Manual verification: 1+2+3+4+5 = 15
    set<int> s1 = {1, 2, 3, 4, 5};
    cout << "Test 1 - Input: {1, 2, 3, 4, 5}" << endl;
    int result1 = iterators_problem1Solution(s1);
    cout << "Expected: 15" << endl;
    cout << "Got: " << result1 << endl;
    cout << "Result: " << (result1 == 15 ? "PASS" : "FAIL") << endl;
    
    // Test 2: Mixed positive and negative
    // Manual verification: -5 + (-3) + 2 + 6 = 0
    set<int> s2 = {-5, -3, 2, 6};
    cout << "\nTest 2 - Input: {-5, -3, 2, 6}" << endl;
    int result2 = iterators_problem1Solution(s2);
    cout << "Expected: 0" << endl;
    cout << "Got: " << result2 << endl;
    cout << "Result: " << (result2 == 0 ? "PASS" : "FAIL") << endl;
    
    // Test 3: Empty set
    // Manual verification: Empty set has sum 0
    set<int> s3 = {};
    cout << "\nTest 3 - Input: {}" << endl;
    int result3 = iterators_problem1Solution(s3);
    cout << "Expected: 0" << endl;
    cout << "Got: " << result3 << endl;
    cout << "Result: " << (result3 == 0 ? "PASS" : "FAIL") << endl;
    
    // Test 4: Single element
    // Manual verification: {42} sum is 42
    set<int> s4 = {42};
    cout << "\nTest 4 - Input: {42}" << endl;
    int result4 = iterators_problem1Solution(s4);
    cout << "Expected: 42" << endl;
    cout << "Got: " << result4 << endl;
    cout << "Result: " << (result4 == 42 ? "PASS" : "FAIL") << endl;
    
    // Test 5: All negative
    // Manual verification: -10 + (-20) + (-30) = -60
    set<int> s5 = {-10, -20, -30};
    cout << "\nTest 5 - Input: {-10, -20, -30}" << endl;
    int result5 = iterators_problem1Solution(s5);
    cout << "Expected: -60" << endl;
    cout << "Got: " << result5 << endl;
    cout << "Result: " << (result5 == -60 ? "PASS" : "FAIL") << endl;
}

void test_iterators_problem2() {
    cout << "\n=== Testing Iterators and Traversal - Problem 2: Get First and Last Elements ===" << endl;
    
    // Test 1: Multiple elements
    // Manual verification: {1,3,4,5,9} first=1, last=9
    set<int> s1 = {3, 1, 4, 1, 5, 9};
    cout << "Test 1 - Input: {3, 1, 4, 1, 5, 9} (stored as {1, 3, 4, 5, 9})" << endl;
    auto result1 = iterators_problem2Solution(s1);
    cout << "Expected: (1, 9)" << endl;
    cout << "Got: (" << result1.first << ", " << result1.second << ")" << endl;
    cout << "Result: " << (result1.first == 1 && result1.second == 9 ? "PASS" : "FAIL") << endl;
    
    // Test 2: Single element
    // Manual verification: {42} first=42, last=42
    set<int> s2 = {42};
    cout << "\nTest 2 - Input: {42}" << endl;
    auto result2 = iterators_problem2Solution(s2);
    cout << "Expected: (42, 42)" << endl;
    cout << "Got: (" << result2.first << ", " << result2.second << ")" << endl;
    cout << "Result: " << (result2.first == 42 && result2.second == 42 ? "PASS" : "FAIL") << endl;
    
    // Test 3: Negative to positive range
    // Manual verification: {-10,0,10} first=-10, last=10
    set<int> s3 = {-10, 0, 10};
    cout << "\nTest 3 - Input: {-10, 0, 10}" << endl;
    auto result3 = iterators_problem2Solution(s3);
    cout << "Expected: (-10, 10)" << endl;
    cout << "Got: (" << result3.first << ", " << result3.second << ")" << endl;
    cout << "Result: " << (result3.first == -10 && result3.second == 10 ? "PASS" : "FAIL") << endl;
    
    // Test 4: Two elements
    // Manual verification: {5,10} first=5, last=10
    set<int> s4 = {5, 10};
    cout << "\nTest 4 - Input: {5, 10}" << endl;
    auto result4 = iterators_problem2Solution(s4);
    cout << "Expected: (5, 10)" << endl;
    cout << "Got: (" << result4.first << ", " << result4.second << ")" << endl;
    cout << "Result: " << (result4.first == 5 && result4.second == 10 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Large range
    // Manual verification: {1,100,200,500,1000} first=1, last=1000
    set<int> s5 = {1, 100, 200, 500, 1000};
    cout << "\nTest 5 - Input: {1, 100, 200, 500, 1000}" << endl;
    auto result5 = iterators_problem2Solution(s5);
    cout << "Expected: (1, 1000)" << endl;
    cout << "Got: (" << result5.first << ", " << result5.second << ")" << endl;
    cout << "Result: " << (result5.first == 1 && result5.second == 1000 ? "PASS" : "FAIL") << endl;
}

void test_iterators_problem3() {
    cout << "\n=== Testing Iterators and Traversal - Problem 3: Count Elements Greater Than Value ===" << endl;
    
    // Test 1: Some elements greater
    // Manual verification: {1,3,5,7,9} elements > 4 are {5,7,9} = 3 elements
    set<int> s1 = {1, 3, 5, 7, 9};
    cout << "Test 1 - Input: set = {1, 3, 5, 7, 9}, threshold = 4" << endl;
    int result1 = iterators_problem3Solution(s1, 4);
    cout << "Expected: 3" << endl;
    cout << "Got: " << result1 << endl;
    cout << "Result: " << (result1 == 3 ? "PASS" : "FAIL") << endl;
    
    // Test 2: No elements greater
    // Manual verification: {2,4,6} elements > 10 are {} = 0 elements
    set<int> s2 = {2, 4, 6};
    cout << "\nTest 2 - Input: set = {2, 4, 6}, threshold = 10" << endl;
    int result2 = iterators_problem3Solution(s2, 10);
    cout << "Expected: 0" << endl;
    cout << "Got: " << result2 << endl;
    cout << "Result: " << (result2 == 0 ? "PASS" : "FAIL") << endl;
    
    // Test 3: Empty set
    // Manual verification: {} has 0 elements > 5
    set<int> s3 = {};
    cout << "\nTest 3 - Input: set = {}, threshold = 5" << endl;
    int result3 = iterators_problem3Solution(s3, 5);
    cout << "Expected: 0" << endl;
    cout << "Got: " << result3 << endl;
    cout << "Result: " << (result3 == 0 ? "PASS" : "FAIL") << endl;
    
    // Test 4: All elements greater
    // Manual verification: {10,20,30,40} elements > 5 are all 4
    set<int> s4 = {10, 20, 30, 40};
    cout << "\nTest 4 - Input: set = {10, 20, 30, 40}, threshold = 5" << endl;
    int result4 = iterators_problem3Solution(s4, 5);
    cout << "Expected: 4" << endl;
    cout << "Got: " << result4 << endl;
    cout << "Result: " << (result4 == 4 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Threshold equals element
    // Manual verification: {1,2,3,4,5} elements > 3 are {4,5} = 2 elements
    set<int> s5 = {1, 2, 3, 4, 5};
    cout << "\nTest 5 - Input: set = {1, 2, 3, 4, 5}, threshold = 3" << endl;
    int result5 = iterators_problem3Solution(s5, 3);
    cout << "Expected: 2" << endl;
    cout << "Got: " << result5 << endl;
    cout << "Result: " << (result5 == 2 ? "PASS" : "FAIL") << endl;
}

void test_iterators_problem4() {
    cout << "\n=== Testing Iterators and Traversal - Problem 4: Reverse Copy to Vector ===" << endl;
    
    // Test 1: Multiple elements
    // Manual verification: {1,3,5,7,9} reversed is {9,7,5,3,1}
    set<int> s1 = {1, 3, 5, 7, 9};
    cout << "Test 1 - Input: {1, 3, 5, 7, 9}" << endl;
    vector<int> result1 = iterators_problem4Solution(s1);
    vector<int> expected1 = {9, 7, 5, 3, 1};
    cout << "Expected: {9, 7, 5, 3, 1}" << endl;
    cout << "Got: { ";
    for (int x : result1) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    
    // Test 2: Single element
    // Manual verification: {42} reversed is {42}
    set<int> s2 = {42};
    cout << "\nTest 2 - Input: {42}" << endl;
    vector<int> result2 = iterators_problem4Solution(s2);
    vector<int> expected2 = {42};
    cout << "Expected: {42}" << endl;
    cout << "Got: { ";
    for (int x : result2) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    
    // Test 3: Empty set
    // Manual verification: {} reversed is {}
    set<int> s3 = {};
    cout << "\nTest 3 - Input: {}" << endl;
    vector<int> result3 = iterators_problem4Solution(s3);
    vector<int> expected3 = {};
    cout << "Expected: {}" << endl;
    cout << "Got: { ";
    for (int x : result3) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;
    
    // Test 4: Two elements
    // Manual verification: {10,20} reversed is {20,10}
    set<int> s4 = {10, 20};
    cout << "\nTest 4 - Input: {10, 20}" << endl;
    vector<int> result4 = iterators_problem4Solution(s4);
    vector<int> expected4 = {20, 10};
    cout << "Expected: {20, 10}" << endl;
    cout << "Got: { ";
    for (int x : result4) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Negative numbers
    // Manual verification: {-5,-3,-1,0,2} reversed is {2,0,-1,-3,-5}
    set<int> s5 = {-5, -3, -1, 0, 2};
    cout << "\nTest 5 - Input: {-5, -3, -1, 0, 2}" << endl;
    vector<int> result5 = iterators_problem4Solution(s5);
    vector<int> expected5 = {2, 0, -1, -3, -5};
    cout << "Expected: {2, 0, -1, -3, -5}" << endl;
    cout << "Got: { ";
    for (int x : result5) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

void test_iterators_problem5() {
    cout << "\n=== Testing Iterators and Traversal - Problem 5: Find Nth Element ===" << endl;
    
    // Test 1: Middle element
    // Manual verification: {10,20,30,40,50} at index 2 is 30
    set<int> s1 = {10, 20, 30, 40, 50};
    cout << "Test 1 - Input: set = {10, 20, 30, 40, 50}, n = 2" << endl;
    int result1 = iterators_problem5Solution(s1, 2);
    cout << "Expected: 30" << endl;
    cout << "Got: " << result1 << endl;
    cout << "Result: " << (result1 == 30 ? "PASS" : "FAIL") << endl;
    
    // Test 2: Out of bounds
    // Manual verification: {5,15,25} at index 5 is out of bounds, return -1
    set<int> s2 = {5, 15, 25};
    cout << "\nTest 2 - Input: set = {5, 15, 25}, n = 5" << endl;
    int result2 = iterators_problem5Solution(s2, 5);
    cout << "Expected: -1" << endl;
    cout << "Got: " << result2 << endl;
    cout << "Result: " << (result2 == -1 ? "PASS" : "FAIL") << endl;
    
    // Test 3: First element
    // Manual verification: {100} at index 0 is 100
    set<int> s3 = {100};
    cout << "\nTest 3 - Input: set = {100}, n = 0" << endl;
    int result3 = iterators_problem5Solution(s3, 0);
    cout << "Expected: 100" << endl;
    cout << "Got: " << result3 << endl;
    cout << "Result: " << (result3 == 100 ? "PASS" : "FAIL") << endl;
    
    // Test 4: Last element
    // Manual verification: {1,2,3,4,5} at index 4 is 5
    set<int> s4 = {1, 2, 3, 4, 5};
    cout << "\nTest 4 - Input: set = {1, 2, 3, 4, 5}, n = 4" << endl;
    int result4 = iterators_problem5Solution(s4, 4);
    cout << "Expected: 5" << endl;
    cout << "Got: " << result4 << endl;
    cout << "Result: " << (result4 == 5 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Empty set
    // Manual verification: {} at any index returns -1
    set<int> s5 = {};
    cout << "\nTest 5 - Input: set = {}, n = 0" << endl;
    int result5 = iterators_problem5Solution(s5, 0);
    cout << "Expected: -1" << endl;
    cout << "Got: " << result5 << endl;
    cout << "Result: " << (result5 == -1 ? "PASS" : "FAIL") << endl;
}

void test_iterators_problem6() {
    cout << "\n=== Testing Iterators and Traversal - Problem 6: Extract Range Between Two Values ===" << endl;
    
    // Test 1: Range in middle
    // Manual verification: {1,3,5,7,9,11} range [4,9] includes {5,7,9}
    set<int> s1 = {1, 3, 5, 7, 9, 11};
    cout << "Test 1 - Input: set = {1, 3, 5, 7, 9, 11}, range [4, 9]" << endl;
    vector<int> result1 = iterators_problem6Solution(s1, 4, 9);
    vector<int> expected1 = {5, 7, 9};
    cout << "Expected: {5, 7, 9}" << endl;
    cout << "Got: { ";
    for (int x : result1) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    
    // Test 2: Range covers few elements
    // Manual verification: {2,4,6,8} range [1,3] includes {2}
    set<int> s2 = {2, 4, 6, 8};
    cout << "\nTest 2 - Input: set = {2, 4, 6, 8}, range [1, 3]" << endl;
    vector<int> result2 = iterators_problem6Solution(s2, 1, 3);
    vector<int> expected2 = {2};
    cout << "Expected: {2}" << endl;
    cout << "Got: { ";
    for (int x : result2) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    
    // Test 3: Range before all elements
    // Manual verification: {10,20,30} range [5,15] includes {10}
    set<int> s3 = {10, 20, 30};
    cout << "\nTest 3 - Input: set = {10, 20, 30}, range [5, 15]" << endl;
    vector<int> result3 = iterators_problem6Solution(s3, 5, 15);
    vector<int> expected3 = {10};
    cout << "Expected: {10}" << endl;
    cout << "Got: { ";
    for (int x : result3) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;
    
    // Test 4: Range covers all
    // Manual verification: {5,10,15} range [1,100] includes all
    set<int> s4 = {5, 10, 15};
    cout << "\nTest 4 - Input: set = {5, 10, 15}, range [1, 100]" << endl;
    vector<int> result4 = iterators_problem6Solution(s4, 1, 100);
    vector<int> expected4 = {5, 10, 15};
    cout << "Expected: {5, 10, 15}" << endl;
    cout << "Got: { ";
    for (int x : result4) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Empty result
    // Manual verification: {1,2,3} range [10,20] includes {}
    set<int> s5 = {1, 2, 3};
    cout << "\nTest 5 - Input: set = {1, 2, 3}, range [10, 20]" << endl;
    vector<int> result5 = iterators_problem6Solution(s5, 10, 20);
    vector<int> expected5 = {};
    cout << "Expected: {}" << endl;
    cout << "Got: { ";
    for (int x : result5) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

void test_iterators_problem7() {
    cout << "\n=== Testing Iterators and Traversal - Problem 7: Alternating Elements ===" << endl;
    
    // Test 1: Even count
    // Manual verification: {1,2,3,4,5,6} positions 0,2,4 → {1,3,5}, positions 1,3,5 → {2,4,6}
    set<int> s1 = {1, 2, 3, 4, 5, 6};
    cout << "Test 1 - Input: {1, 2, 3, 4, 5, 6}" << endl;
    auto result1 = iterators_problem7Solution(s1);
    set<int> expected1_1 = {1, 3, 5};
    set<int> expected1_2 = {2, 4, 6};
    cout << "Expected: ({1, 3, 5}, {2, 4, 6})" << endl;
    cout << "Got: (";
    displaySet(result1.first, "");
    cout << ", ";
    displaySet(result1.second, "");
    cout << ")" << endl;
    cout << "Result: " << (compareSets(result1.first, expected1_1) && compareSets(result1.second, expected1_2) ? "PASS" : "FAIL") << endl;
    
    // Test 2: Odd count
    // Manual verification: {10,20,30} positions 0,2 → {10,30}, position 1 → {20}
    set<int> s2 = {10, 20, 30};
    cout << "\nTest 2 - Input: {10, 20, 30}" << endl;
    auto result2 = iterators_problem7Solution(s2);
    set<int> expected2_1 = {10, 30};
    set<int> expected2_2 = {20};
    cout << "Expected: ({10, 30}, {20})" << endl;
    cout << "Got: (";
    displaySet(result2.first, "");
    cout << ", ";
    displaySet(result2.second, "");
    cout << ")" << endl;
    cout << "Result: " << (compareSets(result2.first, expected2_1) && compareSets(result2.second, expected2_2) ? "PASS" : "FAIL") << endl;
    
    // Test 3: Single element
    // Manual verification: {5} position 0 → {5}, none at position 1 → {}
    set<int> s3 = {5};
    cout << "\nTest 3 - Input: {5}" << endl;
    auto result3 = iterators_problem7Solution(s3);
    set<int> expected3_1 = {5};
    set<int> expected3_2 = {};
    cout << "Expected: ({5}, {})" << endl;
    cout << "Got: (";
    displaySet(result3.first, "");
    cout << ", ";
    displaySet(result3.second, "");
    cout << ")" << endl;
    cout << "Result: " << (compareSets(result3.first, expected3_1) && compareSets(result3.second, expected3_2) ? "PASS" : "FAIL") << endl;
    
    // Test 4: Two elements
    // Manual verification: {100,200} position 0 → {100}, position 1 → {200}
    set<int> s4 = {100, 200};
    cout << "\nTest 4 - Input: {100, 200}" << endl;
    auto result4 = iterators_problem7Solution(s4);
    set<int> expected4_1 = {100};
    set<int> expected4_2 = {200};
    cout << "Expected: ({100}, {200})" << endl;
    cout << "Got: (";
    displaySet(result4.first, "");
    cout << ", ";
    displaySet(result4.second, "");
    cout << ")" << endl;
    cout << "Result: " << (compareSets(result4.first, expected4_1) && compareSets(result4.second, expected4_2) ? "PASS" : "FAIL") << endl;
    
    // Test 5: Empty set
    // Manual verification: {} no elements → ({}, {})
    set<int> s5 = {};
    cout << "\nTest 5 - Input: {}" << endl;
    auto result5 = iterators_problem7Solution(s5);
    set<int> expected5_1 = {};
    set<int> expected5_2 = {};
    cout << "Expected: ({}, {})" << endl;
    cout << "Got: (";
    displaySet(result5.first, "");
    cout << ", ";
    displaySet(result5.second, "");
    cout << ")" << endl;
    cout << "Result: " << (compareSets(result5.first, expected5_1) && compareSets(result5.second, expected5_2) ? "PASS" : "FAIL") << endl;
}

void test_iterators_problem8() {
    cout << "\n=== Testing Iterators and Traversal - Problem 8: Skip Pattern Iterator ===" << endl;
    
    // Test 1: Skip by 3
    // Manual verification: {1,2,3,4,5,6,7,8,9} positions 0,3,6 → {1,4,7}
    set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Test 1 - Input: set = {1, 2, 3, 4, 5, 6, 7, 8, 9}, k = 3" << endl;
    vector<int> result1 = iterators_problem8Solution(s1, 3);
    vector<int> expected1 = {1, 4, 7};
    cout << "Expected: {1, 4, 7}" << endl;
    cout << "Got: { ";
    for (int x : result1) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    
    // Test 2: Skip by 2
    // Manual verification: {10,20,30,40,50} positions 0,2,4 → {10,30,50}
    set<int> s2 = {10, 20, 30, 40, 50};
    cout << "\nTest 2 - Input: set = {10, 20, 30, 40, 50}, k = 2" << endl;
    vector<int> result2 = iterators_problem8Solution(s2, 2);
    vector<int> expected2 = {10, 30, 50};
    cout << "Expected: {10, 30, 50}" << endl;
    cout << "Got: { ";
    for (int x : result2) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    
    // Test 3: Skip by 1 (all elements)
    // Manual verification: {5,15,25} positions 0,1,2 → {5,15,25}
    set<int> s3 = {5, 15, 25};
    cout << "\nTest 3 - Input: set = {5, 15, 25}, k = 1" << endl;
    vector<int> result3 = iterators_problem8Solution(s3, 1);
    vector<int> expected3 = {5, 15, 25};
    cout << "Expected: {5, 15, 25}" << endl;
    cout << "Got: { ";
    for (int x : result3) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;
    
    // Test 4: Skip larger than size
    // Manual verification: {1,2,3} with k=5 positions 0 → {1}
    set<int> s4 = {1, 2, 3};
    cout << "\nTest 4 - Input: set = {1, 2, 3}, k = 5" << endl;
    vector<int> result4 = iterators_problem8Solution(s4, 5);
    vector<int> expected4 = {1};
    cout << "Expected: {1}" << endl;
    cout << "Got: { ";
    for (int x : result4) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Single element
    // Manual verification: {100} with k=1 positions 0 → {100}
    set<int> s5 = {100};
    cout << "\nTest 5 - Input: set = {100}, k = 1" << endl;
    vector<int> result5 = iterators_problem8Solution(s5, 1);
    vector<int> expected5 = {100};
    cout << "Expected: {100}" << endl;
    cout << "Got: { ";
    for (int x : result5) cout << x << " ";
    cout << "}" << endl;
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    int conceptChoice, choice;

    cout << "=== SETS PRACTICE PROBLEMS ===" << endl;
    cout << "\nSelect Concept:" << endl;
    cout << "1. Basic Set Operations" << endl;
    cout << "2. Set Iterators and Traversal" << endl;
    cout << "3. Set Algorithms" << endl;
    cout << "4. Custom Comparators" << endl;
    cout << "5. Lower/Upper Bound Operations" << endl;
    cout << "6. Set vs Unordered_Set" << endl;
    cout << "Enter concept number: ";
    cin >> conceptChoice;

    if (conceptChoice == 1) {
        cout << "\n=== BASIC SET OPERATIONS PROBLEMS ===" << endl;
        cout << "Choose a problem to test (1-8) or 9 to test all:" << endl;
        cout << "1. Problem 1 (Easy) - Count Unique Elements" << endl;
        cout << "2. Problem 2 (Easy) - Check Element Existence" << endl;
        cout << "3. Problem 3 (Easy) - Remove All Even Numbers" << endl;
        cout << "4. Problem 4 (Medium) - Insert and Report Duplicates" << endl;
        cout << "5. Problem 5 (Medium) - Find Missing Numbers in Range" << endl;
        cout << "6. Problem 6 (Medium) - Merge Two Sets with Size Limit" << endl;
        cout << "7. Problem 7 (Hard) - Symmetric Set Modification" << endl;
        cout << "8. Problem 8 (Hard) - Balanced Set Split" << endl;
        cout << "9. Test All Problems" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: test_basicOps_problem1(); break;
            case 2: test_basicOps_problem2(); break;
            case 3: test_basicOps_problem3(); break;
            case 4: test_basicOps_problem4(); break;
            case 5: test_basicOps_problem5(); break;
            case 6: test_basicOps_problem6(); break;
            case 7: test_basicOps_problem7(); break;
            case 8: test_basicOps_problem8(); break;
            case 9:
                test_basicOps_problem1(); test_basicOps_problem2();
                test_basicOps_problem3(); test_basicOps_problem4();
                test_basicOps_problem5(); test_basicOps_problem6();
                test_basicOps_problem7(); test_basicOps_problem8();
                break;
            default: cout << "Invalid choice!" << endl;
        }
    }
    else if (conceptChoice == 2) {
        cout << "\n=== SET ITERATORS AND TRAVERSAL PROBLEMS ===" << endl;
        cout << "Choose a problem to test (1-8) or 9 to test all:" << endl;
        cout << "1. Problem 1 (Easy) - Sum All Elements" << endl;
        cout << "2. Problem 2 (Easy) - Get First and Last Elements" << endl;
        cout << "3. Problem 3 (Easy) - Count Elements Greater Than Value" << endl;
        cout << "4. Problem 4 (Medium) - Reverse Copy to Vector" << endl;
        cout << "5. Problem 5 (Medium) - Find Nth Element" << endl;
        cout << "6. Problem 6 (Medium) - Extract Range Between Two Values" << endl;
        cout << "7. Problem 7 (Hard) - Alternating Elements" << endl;
        cout << "8. Problem 8 (Hard) - Skip Pattern Iterator" << endl;
        cout << "9. Test All Problems" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: test_iterators_problem1(); break;
            case 2: test_iterators_problem2(); break;
            case 3: test_iterators_problem3(); break;
            case 4: test_iterators_problem4(); break;
            case 5: test_iterators_problem5(); break;
            case 6: test_iterators_problem6(); break;
            case 7: test_iterators_problem7(); break;
            case 8: test_iterators_problem8(); break;
            case 9:
                test_iterators_problem1(); test_iterators_problem2();
                test_iterators_problem3(); test_iterators_problem4();
                test_iterators_problem5(); test_iterators_problem6();
                test_iterators_problem7(); test_iterators_problem8();
                break;
            default: cout << "Invalid choice!" << endl;
        }
    }
    else if (conceptChoice == 3) {
        cout << "\n=== SET ALGORITHMS PROBLEMS ===" << endl;
        cout << "Choose a problem to test (1-8):" << endl;
        cout << "1. Problem 1 (Easy) - Simple Union" << endl;
        cout << "2. Problem 2 (Easy) - Simple Intersection" << endl;
        cout << "3. Problem 3 (Easy) - Check Subset" << endl;
        cout << "4. Problem 4 (Medium) - Symmetric Difference" << endl;
        cout << "5. Problem 5 (Medium) - Triple Set Intersection" << endl;
        cout << "6. Problem 6 (Medium) - Difference Chain" << endl;
        cout << "7. Problem 7 (Hard) - Partition into Disjoint Sets" << endl;
        cout << "8. Problem 8 (Hard) - Maximum Independent Set Size" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Test function for algorithms_problem1 not yet implemented" << endl; break;
            case 2: cout << "Test function for algorithms_problem2 not yet implemented" << endl; break;
            case 3: cout << "Test function for algorithms_problem3 not yet implemented" << endl; break;
            case 4: cout << "Test function for algorithms_problem4 not yet implemented" << endl; break;
            case 5: cout << "Test function for algorithms_problem5 not yet implemented" << endl; break;
            case 6: cout << "Test function for algorithms_problem6 not yet implemented" << endl; break;
            case 7: cout << "Test function for algorithms_problem7 not yet implemented" << endl; break;
            case 8: cout << "Test function for algorithms_problem8 not yet implemented" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    }
    else if (conceptChoice == 4) {
        cout << "\n=== CUSTOM COMPARATORS PROBLEMS ===" << endl;
        cout << "Choose a problem to test (1-8):" << endl;
        cout << "1. Problem 1 (Easy) - Sort Strings by Length" << endl;
        cout << "2. Problem 2 (Easy) - Count People by Age Group" << endl;
        cout << "3. Problem 3 (Easy) - Find Youngest Person" << endl;
        cout << "4. Problem 4 (Medium) - Reverse Sort Numbers" << endl;
        cout << "5. Problem 5 (Medium) - Group People by Age Range" << endl;
        cout << "6. Problem 6 (Medium) - Case-Insensitive String Set" << endl;
        cout << "7. Problem 7 (Hard) - Multi-Criteria Sorting" << endl;
        cout << "8. Problem 8 (Hard) - Priority-Based Task Scheduler" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Test function for customComp_problem1 not yet implemented" << endl; break;
            case 2: cout << "Test function for customComp_problem2 not yet implemented" << endl; break;
            case 3: cout << "Test function for customComp_problem3 not yet implemented" << endl; break;
            case 4: cout << "Test function for customComp_problem4 not yet implemented" << endl; break;
            case 5: cout << "Test function for customComp_problem5 not yet implemented" << endl; break;
            case 6: cout << "Test function for customComp_problem6 not yet implemented" << endl; break;
            case 7: cout << "Test function for customComp_problem7 not yet implemented" << endl; break;
            case 8: cout << "Test function for customComp_problem8 not yet implemented" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    }
    else if (conceptChoice == 5) {
        cout << "\n=== LOWER/UPPER BOUND OPERATIONS PROBLEMS ===" << endl;
        cout << "Choose a problem to test (1-8):" << endl;
        cout << "1. Problem 1 (Easy) - Find First Element >= Target" << endl;
        cout << "2. Problem 2 (Easy) - Find First Element > Target" << endl;
        cout << "3. Problem 3 (Easy) - Count Elements in Range" << endl;
        cout << "4. Problem 4 (Medium) - Find Closest Element" << endl;
        cout << "5. Problem 5 (Medium) - Range Sum Query" << endl;
        cout << "6. Problem 6 (Medium) - Extract Subrange" << endl;
        cout << "7. Problem 7 (Hard) - Find K Closest Elements" << endl;
        cout << "8. Problem 8 (Hard) - Median of Range Query" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Test function for bounds_problem1 not yet implemented" << endl; break;
            case 2: cout << "Test function for bounds_problem2 not yet implemented" << endl; break;
            case 3: cout << "Test function for bounds_problem3 not yet implemented" << endl; break;
            case 4: cout << "Test function for bounds_problem4 not yet implemented" << endl; break;
            case 5: cout << "Test function for bounds_problem5 not yet implemented" << endl; break;
            case 6: cout << "Test function for bounds_problem6 not yet implemented" << endl; break;
            case 7: cout << "Test function for bounds_problem7 not yet implemented" << endl; break;
            case 8: cout << "Test function for bounds_problem8 not yet implemented" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    }
    else if (conceptChoice == 6) {
        cout << "\n=== SET VS UNORDERED_SET PROBLEMS ===" << endl;
        cout << "Choose a problem to test (1-8):" << endl;
        cout << "1. Problem 1 (Easy) - Convert Set to Unordered Set" << endl;
        cout << "2. Problem 2 (Easy) - Check Order Preservation" << endl;
        cout << "3. Problem 3 (Easy) - Count Lookup Operations" << endl;
        cout << "4. Problem 4 (Medium) - Find When to Use Set vs Unordered Set" << endl;
        cout << "5. Problem 5 (Medium) - Merge with Order Preference" << endl;
        cout << "6. Problem 6 (Medium) - Optimize Container Choice" << endl;
        cout << "7. Problem 7 (Hard) - Hybrid Container Strategy" << endl;
        cout << "8. Problem 8 (Hard) - Performance Analysis Simulation" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: cout << "Test function for setVsUnordered_problem1 not yet implemented" << endl; break;
            case 2: cout << "Test function for setVsUnordered_problem2 not yet implemented" << endl; break;
            case 3: cout << "Test function for setVsUnordered_problem3 not yet implemented" << endl; break;
            case 4: cout << "Test function for setVsUnordered_problem4 not yet implemented" << endl; break;
            case 5: cout << "Test function for setVsUnordered_problem5 not yet implemented" << endl; break;
            case 6: cout << "Test function for setVsUnordered_problem6 not yet implemented" << endl; break;
            case 7: cout << "Test function for setVsUnordered_problem7 not yet implemented" << endl; break;
            case 8: cout << "Test function for setVsUnordered_problem8 not yet implemented" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    }
    else {
        cout << "Invalid concept choice!" << endl;
    }

    return 0;
}