#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ============================================================================
// CONCEPT 1: BASIC SET OPERATIONS
// ============================================================================

// Problem 1.1 (Easy): Insert and Check Existence
// Given a vector of integers, insert all elements into a set and count how many
// unique elements exist.
// Example: {1, 2, 2, 3, 3, 3} → Result: 3 unique elements
// Example: {5, 5, 5, 5} → Result: 1 unique element
// Constraints: 0 <= vector size <= 1000, -1000 <= elements <= 1000
int basicOps_problem1_1(const vector<int>& nums) {
    // TODO: Insert all elements into a set and return its size
    // Hint: Create a set, insert all elements, and return set.size()
    return 0;
}

// Problem 1.2 (Easy): Remove and Count
// Given a set of integers and a value to remove, remove the value and return
// the new size of the set.
// Example: Set {1, 2, 3, 4, 5}, remove 3 → Result: 4
// Example: Set {10, 20, 30}, remove 40 → Result: 3 (40 not in set)
// Constraints: 1 <= set size <= 100, value is any integer
int basicOps_problem1_2(set<int>& s, int value) {
    // TODO: Erase the value from set and return new size
    // Hint: Use erase() method, it returns number of elements removed
    return 0;
}

// Problem 1.3 (Medium): Count Valid Insertions
// Given a vector of integers, try to insert each element into a set.
// Count how many insertions were successful (element didn't exist before).
// Example: {1, 2, 2, 3, 1} → Result: 3 (successful insertions: 1, 2, 3)
// Example: {5, 5, 5} → Result: 1 (only first 5 is inserted)
// Constraints: 1 <= vector size <= 1000, elements can be any integer
int basicOps_problem1_3(const vector<int>& nums) {
    // TODO: Try inserting each element and count successful insertions
    // Hint: insert() returns a pair, check the second element (bool)
    return 0;
}

// ============================================================================
// CONCEPT 2: SET ITERATORS AND TRAVERSAL
// ============================================================================

// Problem 2.1 (Easy): Sum Using Forward Iterator
// Given a set of integers, use forward iteration to calculate the sum of all elements.
// Example: {1, 2, 3, 4, 5} → Result: 15
// Example: {10, 20, 30} → Result: 60
// Constraints: 1 <= set size <= 100, -100 <= elements <= 100
int iterators_problem2_1(const set<int>& s) {
    // TODO: Use iterators to traverse and sum all elements
    // Hint: Use a loop from begin() to end() with iterator
    return 0;
}

// Problem 2.2 (Easy): Get First and Last Elements
// Given a non-empty set of strings, return the concatenation of the first
// and last elements (alphabetically).
// Example: {"apple", "banana", "cherry"} → Result: "applecherry"
// Example: {"zebra", "ant"} → Result: "antzebra"
// Constraints: set size >= 1, strings are non-empty
string iterators_problem2_2(const set<string>& s) {
    // TODO: Access first element using begin() and last using rbegin()
    // Hint: *s.begin() gives first, *s.rbegin() gives last
    return "";
}

// Problem 2.3 (Medium): Count Elements After Target
// Given a set of integers and a target value, find the target and count
// how many elements come after it in the set (including target if found).
// Example: Set {1, 2, 3, 4, 5}, target=3 → Result: 3 (elements: 3, 4, 5)
// Example: Set {10, 20, 30}, target=15 → Result: 0 (target not found)
// Constraints: 1 <= set size <= 100, target is any integer
int iterators_problem2_3(const set<int>& s, int target) {
    // TODO: Find target, then count elements from that position to end
    // Hint: Use find() to get iterator, then distance to end()
    return 0;
}

// ============================================================================
// CONCEPT 3: SET ALGORITHMS
// ============================================================================

// Problem 3.1 (Easy): Find Common Elements
// Given two sets of integers, return the number of common elements (intersection).
// Example: A={1,2,3}, B={2,3,4} → Result: 2 (common: 2, 3)
// Example: A={1,2}, B={3,4} → Result: 0 (no common elements)
// Constraints: 0 <= set sizes <= 100
int setAlgo_problem3_1(const set<int>& setA, const set<int>& setB) {
    // TODO: Use set_intersection to find common elements
    // Hint: Create result set, use set_intersection with inserter
    return 0;
}

// Problem 3.2 (Easy): Combine Two Sets
// Given two sets of integers, return the size of their union (all unique elements).
// Example: A={1,2,3}, B={3,4,5} → Result: 5 (union: 1,2,3,4,5)
// Example: A={1,2}, B={1,2} → Result: 2 (union: 1,2)
// Constraints: 0 <= set sizes <= 100
int setAlgo_problem3_2(const set<int>& setA, const set<int>& setB) {
    // TODO: Use set_union to combine sets without duplicates
    // Hint: Create result set, use set_union with inserter
    return 0;
}

// Problem 3.3 (Medium): Unique Elements Count
// Given two sets A and B, return the count of elements that are in A but not in B
// (set difference), plus elements in B but not in A.
// Example: A={1,2,3}, B={2,3,4} → Result: 2 (1 from A, 4 from B)
// Example: A={1,2}, B={1,2} → Result: 0 (no unique elements)
// Constraints: 0 <= set sizes <= 100
int setAlgo_problem3_3(const set<int>& setA, const set<int>& setB) {
    // TODO: Use set_symmetric_difference or calculate both differences
    // Hint: Elements in A-B plus elements in B-A
    return 0;
}

// ============================================================================
// CONCEPT 4: CUSTOM COMPARATORS AND SORTING
// ============================================================================

// Problem 4.1 (Easy): Count Descending Order
// Given a set of integers (stored in ascending order by default), count how
// many pairs of adjacent elements are in descending order when reversed.
// Example: {1, 2, 3, 4} reversed is {4, 3, 2, 1} → Result: 3 pairs descending
// Example: {5, 10} reversed is {10, 5} → Result: 1 pair descending
// Constraints: set size >= 2, elements are unique integers
int customComp_problem4_1(const set<int>& s) {
    // TODO: Count adjacent pairs in reverse order that are descending
    // Hint: Use reverse iterator and check consecutive elements
    return 0;
}

// Problem 4.2 (Easy): Find Maximum Element
// Given a set of integers, return the maximum element.
// Example: {1, 5, 3, 9, 2} → Result: 9
// Example: {-10, -20, -5} → Result: -5
// Constraints: set size >= 1
int customComp_problem4_2(const set<int>& s) {
    // TODO: Find and return the maximum element
    // Hint: The last element in set is the maximum (use rbegin())
    return 0;
}

// Problem 4.3 (Medium): Count Within Range
// Given a set of integers and a range [low, high], count how many elements
// fall within this range (inclusive).
// Example: Set {1,2,3,4,5}, range [2,4] → Result: 3 (elements: 2,3,4)
// Example: Set {10,20,30}, range [15,25] → Result: 1 (element: 20)
// Constraints: 1 <= set size <= 100, low <= high
int customComp_problem4_3(const set<int>& s, int low, int high) {
    // TODO: Count elements in range [low, high]
    // Hint: Use lower_bound(low) and upper_bound(high), calculate distance
    return 0;
}

// ============================================================================
// CONCEPT 5: LOWER_BOUND AND UPPER_BOUND
// ============================================================================

// Problem 5.1 (Easy): Find First Greater or Equal
// Given a set of integers and a target value, return the smallest element
// that is greater than or equal to target. Return -1 if no such element exists.
// Example: Set {1,3,5,7,9}, target=4 → Result: 5
// Example: Set {1,2,3}, target=5 → Result: -1
// Constraints: 1 <= set size <= 100, target is any integer
int lowerUpper_problem5_1(const set<int>& s, int target) {
    // TODO: Use lower_bound to find first element >= target
    // Hint: lower_bound returns iterator to first element >= target
    return -1;
}

// Problem 5.2 (Easy): Find First Strictly Greater
// Given a set of integers and a target value, return the smallest element
// that is strictly greater than target. Return -1 if no such element exists.
// Example: Set {1,3,5,7,9}, target=5 → Result: 7
// Example: Set {1,2,3}, target=3 → Result: -1
// Constraints: 1 <= set size <= 100, target is any integer
int lowerUpper_problem5_2(const set<int>& s, int target) {
    // TODO: Use upper_bound to find first element > target
    // Hint: upper_bound returns iterator to first element > target
    return -1;
}

// Problem 5.3 (Medium): Count Elements in Range
// Given a set of integers, count how many elements are in the range [low, high]
// using lower_bound and upper_bound efficiently.
// Example: Set {1,2,3,4,5,6,7,8,9}, range [3,7] → Result: 5
// Example: Set {10,20,30}, range [5,15] → Result: 1 (only 10)
// Constraints: 1 <= set size <= 1000, low <= high
int lowerUpper_problem5_3(const set<int>& s, int low, int high) {
    // TODO: Use lower_bound(low) and upper_bound(high) to find range
    // Hint: distance between lower_bound(low) and upper_bound(high)
    return 0;
}

// ============================================================================
// CONCEPT 6: SET VS UNORDERED_SET PERFORMANCE
// ============================================================================

// Problem 6.1 (Easy): Check Ordering
// Given a set and an unordered_set with same elements, return true if the
// set maintains sorted order (first < second < third...).
// Example: set {1,2,3} → Result: true (sorted)
// Example: Only check the set, unordered_set order doesn't matter
// Constraints: 2 <= set size <= 100
bool performance_problem6_1(const set<int>& orderedSet) {
    // TODO: Verify set maintains ascending order
    // Hint: Iterate and check each element < next element
    return false;
}

// Problem 6.2 (Easy): Find in Both
// Given a set and unordered_set with same elements, and a target value,
// return true if target exists in BOTH containers.
// Example: set {1,2,3}, unordered_set {1,2,3}, target=2 → Result: true
// Example: set {1,2}, unordered_set {1,2}, target=5 → Result: false
// Constraints: 1 <= container size <= 100
bool performance_problem6_2(const set<int>& s, const unordered_set<int>& us, int target) {
    // TODO: Check if target exists in both containers
    // Hint: Use find() or count() for both containers
    return false;
}

// Problem 6.3 (Medium): Compare Container Sizes After Operations
// Given two vectors of integers, insert all elements from vector1 into a set
// and all from vector2 into an unordered_set. Return the difference in their
// final sizes (|set.size() - unordered_set.size()|).
// Example: v1={1,2,2,3}, v2={1,1,1} → set size=3, unordered_set size=1, diff=2
// Constraints: 1 <= vector sizes <= 100
int performance_problem6_3(const vector<int>& vec1, const vector<int>& vec2) {
    // TODO: Create set from vec1, unordered_set from vec2, return size difference
    // Hint: Both automatically handle duplicates, compare final sizes
    return 0;
}

// ============================================================================
// CONCEPT 7: ORDERED VS UNORDERED DATA STRUCTURES
// ============================================================================

// Problem 7.1 (Easy): Get Minimum Element
// Given a set (ordered) and unordered_set with same elements, return the
// minimum element (which can be efficiently found in ordered set).
// Example: set {3,1,4,2} → minimum is 1 (set maintains order)
// Example: set {-5,-10,0} → minimum is -10
// Constraints: 1 <= set size <= 100
int ordered_problem7_1(const set<int>& s) {
    // TODO: Return minimum element from ordered set
    // Hint: In set, minimum is at begin()
    return 0;
}

// Problem 7.2 (Easy): Check Sorted Property
// Given a set of integers, return true if when you traverse it, elements
// appear in strictly increasing order.
// Example: {1,2,3,4} → Result: true
// Example: {1,1,2} → impossible in set, sets don't allow duplicates
// Constraints: 1 <= set size <= 100, elements are unique
bool ordered_problem7_2(const set<int>& s) {
    // TODO: Check if set elements are in strictly increasing order
    // Hint: Sets are always sorted, so always return true for valid input
    return false;
}

// Problem 7.3 (Medium): Find Median
// Given a set of integers, find and return the median element.
// If size is odd, return middle element. If even, return lower middle element.
// Example: {1,2,3,4,5} → Result: 3 (middle element)
// Example: {1,2,3,4} → Result: 2 (lower middle)
// Constraints: 1 <= set size <= 1000
int ordered_problem7_3(const set<int>& s) {
    // TODO: Find median element using ordered property
    // Hint: Advance iterator to middle position (size/2)
    return 0;
}

// ============================================================================
// CONCEPT 8: DUPLICATE REMOVAL
// ============================================================================

// Problem 8.1 (Easy): Count Duplicates Removed
// Given a vector of integers, return how many duplicate elements were removed
// when converting to a set.
// Example: {1,2,2,3,3,3} → Result: 3 duplicates removed (3 unique remain)
// Example: {1,2,3} → Result: 0 duplicates removed
// Constraints: 1 <= vector size <= 1000
int duplicateRemoval_problem8_1(const vector<int>& nums) {
    // TODO: Calculate original size minus unique elements
    // Hint: Create set from vector, return vector.size() - set.size()
    return 0;
}

// Problem 8.2 (Easy): Remove Duplicates from String
// Given a string, return a new string with all duplicate characters removed,
// maintaining the order of first occurrence.
// Example: "hello" → Result: "helo" (second 'l' removed)
// Example: "aabbcc" → Result: "abc"
// Constraints: 1 <= string length <= 1000
string duplicateRemoval_problem8_2(const string& str) {
    // TODO: Use set to track seen characters, build result string
    // Hint: Iterate string, use set to check if character seen before
    return "";
}

// Problem 8.3 (Medium): Keep Only Duplicates
// Given a vector of integers, return a vector containing only the elements
// that appear more than once in the original vector (each duplicate once).
// Example: {1,2,2,3,3,3,4} → Result: {2,3} (elements with duplicates)
// Example: {1,2,3,4} → Result: {} (no duplicates)
// Constraints: 1 <= vector size <= 1000
vector<int> duplicateRemoval_problem8_3(const vector<int>& nums) {
    // TODO: Find elements that appear more than once
    // Hint: Use set to track seen and another set for duplicates
    return {};
}

// ============================================================================
// CONCEPT 9: UNIQUE ELEMENT TRACKING
// ============================================================================

// Problem 9.1 (Easy): Count Unique Elements
// Given a vector of integers, return the count of unique elements.
// Example: {1,1,2,2,3} → Result: 3 unique elements
// Example: {5,5,5,5} → Result: 1 unique element
// Constraints: 1 <= vector size <= 1000
int uniqueTracking_problem9_1(const vector<int>& nums) {
    // TODO: Insert into set and return size
    // Hint: Set automatically keeps only unique elements
    return 0;
}

// Problem 9.2 (Easy): First Unique Element
// Given a vector of integers, return the first element that appears only once.
// Return -1 if no such element exists.
// Example: {1,2,2,3,3,4} → Result: 1 (first unique)
// Example: {1,1,2,2} → Result: -1 (no unique elements)
// Constraints: 1 <= vector size <= 1000, elements > 0
int uniqueTracking_problem9_2(const vector<int>& nums) {
    // TODO: Track frequency and find first element with count 1
    // Hint: Use map to count, then find first with count 1 in original order
    return -1;
}

// Problem 9.3 (Medium): Count Unique Pairs
// Given a vector of integers, count how many unique unordered pairs exist.
// A pair (a,b) is same as (b,a).
// Example: {1,2,3} → Result: 3 pairs: (1,2), (1,3), (2,3)
// Example: {1,1,2} → unique elements are {1,2} → Result: 1 pair (1,2)
// Constraints: 1 <= vector size <= 100
int uniqueTracking_problem9_3(const vector<int>& nums) {
    // TODO: Find unique elements, then calculate combination C(n,2)
    // Hint: Unique pairs = n*(n-1)/2 where n is number of unique elements
    return 0;
}

// ============================================================================
// CONCEPT 10: SET-BASED SEARCH OPERATIONS
// ============================================================================

// Problem 10.1 (Easy): Fast Membership Check
// Given a set of integers and a vector of query values, count how many
// queries exist in the set.
// Example: set {1,2,3,4,5}, queries {2,4,6,8} → Result: 2 (2 and 4 found)
// Example: set {10,20}, queries {5,10,15,20} → Result: 2 (10 and 20 found)
// Constraints: 1 <= set size <= 1000, 1 <= queries size <= 1000
int searchOps_problem10_1(const set<int>& s, const vector<int>& queries) {
    // TODO: For each query, check if it exists in set
    // Hint: Use find() or count() for O(log n) lookup
    return 0;
}

// Problem 10.2 (Easy): Find Missing Number
// Given a set containing numbers from 1 to N with one number missing,
// find and return the missing number.
// Example: {1,2,4,5} → Result: 3 (missing number)
// Example: {1,3,4,5,6} → Result: 2 (missing number)
// Constraints: set contains N-1 unique integers from range [1,N]
int searchOps_problem10_2(const set<int>& s) {
    // TODO: Find which number from 1 to N+1 is missing
    // Hint: Expected sum is N*(N+1)/2, subtract actual sum
    return 0;
}

// Problem 10.3 (Medium): Count Range Queries
// Given a set of integers and a vector of range queries [low, high],
// return a vector containing the count of elements in each range.
// Example: set {1,2,3,4,5}, queries [(1,3), (2,4)] → Result: {3, 3}
// Example: set {10,20,30}, queries [(5,15), (15,25)] → Result: {1, 1}
// Constraints: 1 <= set size <= 1000, 1 <= queries size <= 100
vector<int> searchOps_problem10_3(const set<int>& s, const vector<pair<int,int>>& ranges) {
    // TODO: For each range, count elements using lower_bound and upper_bound
    // Hint: Use efficient range counting for each query
    return {};
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 1
// ============================================================================

void testBasicOps_Problem1_1() {
    cout << "\n=== Testing Problem 1.1: Insert and Check Existence ===" << endl;
    
    // Test 1: Normal case with duplicates
    // Step: Vector with several duplicate values
    // Expected: Should return count of unique elements (3)
    vector<int> test1 = {1, 2, 2, 3, 3, 3};
    int result1 = basicOps_problem1_1(test1);
    cout << "Test 1 (Duplicates): " << (result1 == 3 ? "PASS" : "FAIL") 
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: All same elements
    // Step: Vector with all identical values
    // Expected: Should return 1 unique element
    vector<int> test2 = {5, 5, 5, 5};
    int result2 = basicOps_problem1_1(test2);
    cout << "Test 2 (All same): " << (result2 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result2 << ")" << endl;
    
    // Test 3: Empty vector
    // Step: Empty input vector
    // Expected: Should return 0
    vector<int> test3 = {};
    int result3 = basicOps_problem1_1(test3);
    cout << "Test 3 (Empty): " << (result3 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result3 << ")" << endl;
    
    // Test 4: All unique elements
    // Step: Vector with no duplicates
    // Expected: Should return count equal to vector size (5)
    vector<int> test4 = {1, 2, 3, 4, 5};
    int result4 = basicOps_problem1_1(test4);
    cout << "Test 4 (All unique): " << (result4 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result4 << ")" << endl;
    
    // Test 5: Negative numbers with duplicates
    // Step: Vector with negative numbers and duplicates
    // Expected: Should count unique negative numbers (3)
    vector<int> test5 = {-1, -2, -2, -3, -3, -3};
    int result5 = basicOps_problem1_1(test5);
    cout << "Test 5 (Negative numbers): " << (result5 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result5 << ")" << endl;
}

void testBasicOps_Problem1_2() {
    cout << "\n=== Testing Problem 1.2: Remove and Count ===" << endl;
    
    // Test 1: Remove existing element
    // Step: Set {1,2,3,4,5}, remove 3
    // Expected: Size should be 4 after removal
    set<int> test1 = {1, 2, 3, 4, 5};
    int result1 = basicOps_problem1_2(test1, 3);
    cout << "Test 1 (Remove existing): " << (result1 == 4 ? "PASS" : "FAIL")
         << " (Expected: 4, Got: " << result1 << ")" << endl;
    
    // Test 2: Remove non-existing element
    // Step: Set {10,20,30}, remove 40
    // Expected: Size should remain 3
    set<int> test2 = {10, 20, 30};
    int result2 = basicOps_problem1_2(test2, 40);
    cout << "Test 2 (Remove non-existing): " << (result2 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result2 << ")" << endl;
    
    // Test 3: Remove from single element set
    // Step: Set {5}, remove 5
    // Expected: Size should be 0 (empty set)
    set<int> test3 = {5};
    int result3 = basicOps_problem1_2(test3, 5);
    cout << "Test 3 (Remove only element): " << (result3 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result3 << ")" << endl;
    
    // Test 4: Remove first element
    // Step: Set {1,2,3,4}, remove 1
    // Expected: Size should be 3
    set<int> test4 = {1, 2, 3, 4};
    int result4 = basicOps_problem1_2(test4, 1);
    cout << "Test 4 (Remove first): " << (result4 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result4 << ")" << endl;
    
    // Test 5: Remove last element
    // Step: Set {1,2,3,4}, remove 4
    // Expected: Size should be 3
    set<int> test5 = {1, 2, 3, 4};
    int result5 = basicOps_problem1_2(test5, 4);
    cout << "Test 5 (Remove last): " << (result5 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result5 << ")" << endl;
}

void testBasicOps_Problem1_3() {
    cout << "\n=== Testing Problem 1.3: Count Valid Insertions ===" << endl;
    
    // Test 1: Mixed duplicates
    // Step: Vector {1,2,2,3,1}
    // Expected: 3 successful insertions (1,2,3)
    vector<int> test1 = {1, 2, 2, 3, 1};
    int result1 = basicOps_problem1_3(test1);
    cout << "Test 1 (Mixed duplicates): " << (result1 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: All same value
    // Step: Vector {5,5,5}
    // Expected: 1 successful insertion (only first 5)
    vector<int> test2 = {5, 5, 5};
    int result2 = basicOps_problem1_3(test2);
    cout << "Test 2 (All same): " << (result2 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result2 << ")" << endl;
    
    // Test 3: All unique values
    // Step: Vector {1,2,3,4,5}
    // Expected: 5 successful insertions (all different)
    vector<int> test3 = {1, 2, 3, 4, 5};
    int result3 = basicOps_problem1_3(test3);
    cout << "Test 3 (All unique): " << (result3 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result3 << ")" << endl;
    
    // Test 4: Single element
    // Step: Vector {10}
    // Expected: 1 successful insertion
    vector<int> test4 = {10};
    int result4 = basicOps_problem1_3(test4);
    cout << "Test 4 (Single element): " << (result4 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result4 << ")" << endl;
    
    // Test 5: Alternating duplicates
    // Step: Vector {1,2,1,2,1,2}
    // Expected: 2 successful insertions (1 and 2)
    vector<int> test5 = {1, 2, 1, 2, 1, 2};
    int result5 = basicOps_problem1_3(test5);
    cout << "Test 5 (Alternating): " << (result5 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result5 << ")" << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 2
// ============================================================================

void testIterators_Problem2_1() {
    cout << "\n=== Testing Problem 2.1: Sum Using Forward Iterator ===" << endl;
    
    // Test 1: Positive numbers
    // Step: Set {1,2,3,4,5}
    // Expected: Sum = 15
    set<int> test1 = {1, 2, 3, 4, 5};
    int result1 = iterators_problem2_1(test1);
    cout << "Test 1 (Positive numbers): " << (result1 == 15 ? "PASS" : "FAIL")
         << " (Expected: 15, Got: " << result1 << ")" << endl;
    
    // Test 2: Mixed positive and negative
    // Step: Set {-5,-2,0,3,4}
    // Expected: Sum = 0
    set<int> test2 = {-5, -2, 0, 3, 4};
    int result2 = iterators_problem2_1(test2);
    cout << "Test 2 (Mixed numbers): " << (result2 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result2 << ")" << endl;
    
    // Test 3: Single element
    // Step: Set {42}
    // Expected: Sum = 42
    set<int> test3 = {42};
    int result3 = iterators_problem2_1(test3);
    cout << "Test 3 (Single element): " << (result3 == 42 ? "PASS" : "FAIL")
         << " (Expected: 42, Got: " << result3 << ")" << endl;
    
    // Test 4: All negative numbers
    // Step: Set {-10,-20,-30}
    // Expected: Sum = -60
    set<int> test4 = {-10, -20, -30};
    int result4 = iterators_problem2_1(test4);
    cout << "Test 4 (All negative): " << (result4 == -60 ? "PASS" : "FAIL")
         << " (Expected: -60, Got: " << result4 << ")" << endl;
    
    // Test 5: Larger set
    // Step: Set {10,20,30}
    // Expected: Sum = 60
    set<int> test5 = {10, 20, 30};
    int result5 = iterators_problem2_1(test5);
    cout << "Test 5 (Larger values): " << (result5 == 60 ? "PASS" : "FAIL")
         << " (Expected: 60, Got: " << result5 << ")" << endl;
}

void testIterators_Problem2_2() {
    cout << "\n=== Testing Problem 2.2: Get First and Last Elements ===" << endl;
    
    // Test 1: Three strings
    // Step: Set {"apple","banana","cherry"}
    // Expected: "applecherry" (first + last alphabetically)
    set<string> test1 = {"apple", "banana", "cherry"};
    string result1 = iterators_problem2_2(test1);
    cout << "Test 1 (Three strings): " << (result1 == "applecherry" ? "PASS" : "FAIL")
         << " (Expected: applecherry, Got: " << result1 << ")" << endl;
    
    // Test 2: Two strings
    // Step: Set {"zebra","ant"}
    // Expected: "antzebra"
    set<string> test2 = {"zebra", "ant"};
    string result2 = iterators_problem2_2(test2);
    cout << "Test 2 (Two strings): " << (result2 == "antzebra" ? "PASS" : "FAIL")
         << " (Expected: antzebra, Got: " << result2 << ")" << endl;
    
    // Test 3: Single string
    // Step: Set {"hello"}
    // Expected: "hellohello" (same string twice)
    set<string> test3 = {"hello"};
    string result3 = iterators_problem2_2(test3);
    cout << "Test 3 (Single string): " << (result3 == "hellohello" ? "PASS" : "FAIL")
         << " (Expected: hellohello, Got: " << result3 << ")" << endl;
    
    // Test 4: Numerical strings
    // Step: Set {"1","2","3"}
    // Expected: "13"
    set<string> test4 = {"1", "2", "3"};
    string result4 = iterators_problem2_2(test4);
    cout << "Test 4 (Numerical strings): " << (result4 == "13" ? "PASS" : "FAIL")
         << " (Expected: 13, Got: " << result4 << ")" << endl;
    
    // Test 5: Mixed case
    // Step: Set {"Apple","apple","Zebra"}
    // Expected: "AppleZebra" (uppercase comes before lowercase)
    set<string> test5 = {"Apple", "apple", "Zebra"};
    string result5 = iterators_problem2_2(test5);
    cout << "Test 5 (Mixed case): " << (result5 == "AppleZebra" ? "PASS" : "FAIL")
         << " (Expected: AppleZebra, Got: " << result5 << ")" << endl;
}

void testIterators_Problem2_3() {
    cout << "\n=== Testing Problem 2.3: Count Elements After Target ===" << endl;
    
    // Test 1: Target exists in middle
    // Step: Set {1,2,3,4,5}, target=3
    // Expected: 3 elements (3,4,5)
    set<int> test1 = {1, 2, 3, 4, 5};
    int result1 = iterators_problem2_3(test1, 3);
    cout << "Test 1 (Target in middle): " << (result1 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: Target not found
    // Step: Set {10,20,30}, target=15
    // Expected: 0 (target doesn't exist)
    set<int> test2 = {10, 20, 30};
    int result2 = iterators_problem2_3(test2, 15);
    cout << "Test 2 (Target not found): " << (result2 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result2 << ")" << endl;
    
    // Test 3: Target is first element
    // Step: Set {1,2,3,4,5}, target=1
    // Expected: 5 elements (all elements)
    set<int> test3 = {1, 2, 3, 4, 5};
    int result3 = iterators_problem2_3(test3, 1);
    cout << "Test 3 (Target is first): " << (result3 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result3 << ")" << endl;
    
    // Test 4: Target is last element
    // Step: Set {1,2,3,4,5}, target=5
    // Expected: 1 element (only 5)
    set<int> test4 = {1, 2, 3, 4, 5};
    int result4 = iterators_problem2_3(test4, 5);
    cout << "Test 4 (Target is last): " << (result4 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result4 << ")" << endl;
    
    // Test 5: Single element set with target
    // Step: Set {10}, target=10
    // Expected: 1 element
    set<int> test5 = {10};
    int result5 = iterators_problem2_3(test5, 10);
    cout << "Test 5 (Single element): " << (result5 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result5 << ")" << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 3
// ============================================================================

void testSetAlgo_Problem3_1() {
    cout << "\n=== Testing Problem 3.1: Find Common Elements ===" << endl;
    
    // Test 1: Some common elements
    // Step: A={1,2,3}, B={2,3,4}
    // Expected: 2 common elements (2,3)
    set<int> a1 = {1, 2, 3};
    set<int> b1 = {2, 3, 4};
    int result1 = setAlgo_problem3_1(a1, b1);
    cout << "Test 1 (Some common): " << (result1 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result1 << ")" << endl;
    
    // Test 2: No common elements
    // Step: A={1,2}, B={3,4}
    // Expected: 0 common elements
    set<int> a2 = {1, 2};
    set<int> b2 = {3, 4};
    int result2 = setAlgo_problem3_1(a2, b2);
    cout << "Test 2 (No common): " << (result2 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result2 << ")" << endl;
    
    // Test 3: Identical sets
    // Step: A={1,2,3}, B={1,2,3}
    // Expected: 3 common elements
    set<int> a3 = {1, 2, 3};
    set<int> b3 = {1, 2, 3};
    int result3 = setAlgo_problem3_1(a3, b3);
    cout << "Test 3 (Identical sets): " << (result3 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result3 << ")" << endl;
    
    // Test 4: One empty set
    // Step: A={1,2,3}, B={}
    // Expected: 0 common elements
    set<int> a4 = {1, 2, 3};
    set<int> b4 = {};
    int result4 = setAlgo_problem3_1(a4, b4);
    cout << "Test 4 (One empty): " << (result4 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result4 << ")" << endl;
    
    // Test 5: Single common element
    // Step: A={1,2,3,4,5}, B={5,6,7,8,9}
    // Expected: 1 common element (5)
    set<int> a5 = {1, 2, 3, 4, 5};
    set<int> b5 = {5, 6, 7, 8, 9};
    int result5 = setAlgo_problem3_1(a5, b5);
    cout << "Test 5 (Single common): " << (result5 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result5 << ")" << endl;
}

void testSetAlgo_Problem3_2() {
    cout << "\n=== Testing Problem 3.2: Combine Two Sets ===" << endl;
    
    // Test 1: Some overlap
    // Step: A={1,2,3}, B={3,4,5}
    // Expected: 5 elements in union (1,2,3,4,5)
    set<int> a1 = {1, 2, 3};
    set<int> b1 = {3, 4, 5};
    int result1 = setAlgo_problem3_2(a1, b1);
    cout << "Test 1 (Some overlap): " << (result1 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result1 << ")" << endl;
    
    // Test 2: Identical sets
    // Step: A={1,2}, B={1,2}
    // Expected: 2 elements in union
    set<int> a2 = {1, 2};
    set<int> b2 = {1, 2};
    int result2 = setAlgo_problem3_2(a2, b2);
    cout << "Test 2 (Identical sets): " << (result2 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result2 << ")" << endl;
    
    // Test 3: No overlap
    // Step: A={1,2}, B={3,4}
    // Expected: 4 elements in union
    set<int> a3 = {1, 2};
    set<int> b3 = {3, 4};
    int result3 = setAlgo_problem3_2(a3, b3);
    cout << "Test 3 (No overlap): " << (result3 == 4 ? "PASS" : "FAIL")
         << " (Expected: 4, Got: " << result3 << ")" << endl;
    
    // Test 4: One empty set
    // Step: A={1,2,3}, B={}
    // Expected: 3 elements (all from A)
    set<int> a4 = {1, 2, 3};
    set<int> b4 = {};
    int result4 = setAlgo_problem3_2(a4, b4);
    cout << "Test 4 (One empty): " << (result4 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result4 << ")" << endl;
    
    // Test 5: Subset relationship
    // Step: A={1,2}, B={1,2,3,4}
    // Expected: 4 elements (B contains all of A)
    set<int> a5 = {1, 2};
    set<int> b5 = {1, 2, 3, 4};
    int result5 = setAlgo_problem3_2(a5, b5);
    cout << "Test 5 (Subset): " << (result5 == 4 ? "PASS" : "FAIL")
         << " (Expected: 4, Got: " << result5 << ")" << endl;
}

void testSetAlgo_Problem3_3() {
    cout << "\n=== Testing Problem 3.3: Unique Elements Count ===" << endl;
    
    // Test 1: Some unique in each
    // Step: A={1,2,3}, B={2,3,4}
    // Expected: 2 (1 from A, 4 from B)
    set<int> a1 = {1, 2, 3};
    set<int> b1 = {2, 3, 4};
    int result1 = setAlgo_problem3_3(a1, b1);
    cout << "Test 1 (Some unique): " << (result1 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result1 << ")" << endl;
    
    // Test 2: Identical sets
    // Step: A={1,2}, B={1,2}
    // Expected: 0 (no unique elements)
    set<int> a2 = {1, 2};
    set<int> b2 = {1, 2};
    int result2 = setAlgo_problem3_3(a2, b2);
    cout << "Test 2 (Identical): " << (result2 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result2 << ")" << endl;
    
    // Test 3: Completely different
    // Step: A={1,2}, B={3,4}
    // Expected: 4 (all elements are unique)
    set<int> a3 = {1, 2};
    set<int> b3 = {3, 4};
    int result3 = setAlgo_problem3_3(a3, b3);
    cout << "Test 3 (Completely different): " << (result3 == 4 ? "PASS" : "FAIL")
         << " (Expected: 4, Got: " << result3 << ")" << endl;
    
    // Test 4: One element overlap
    // Step: A={1,2,3}, B={3,4,5}
    // Expected: 4 (1,2 from A and 4,5 from B)
    set<int> a4 = {1, 2, 3};
    set<int> b4 = {3, 4, 5};
    int result4 = setAlgo_problem3_3(a4, b4);
    cout << "Test 4 (One overlap): " << (result4 == 4 ? "PASS" : "FAIL")
         << " (Expected: 4, Got: " << result4 << ")" << endl;
    
    // Test 5: B subset of A
    // Step: A={1,2,3,4}, B={2,3}
    // Expected: 2 (1,4 from A)
    set<int> a5 = {1, 2, 3, 4};
    set<int> b5 = {2, 3};
    int result5 = setAlgo_problem3_3(a5, b5);
    cout << "Test 5 (Subset): " << (result5 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result5 << ")" << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 4
// ============================================================================

void testCustomComp_Problem4_1() {
    cout << "\n=== Testing Problem 4.1: Count Descending Order ===" << endl;
    
    // Test 1: Simple ascending set
    // Step: Set {1,2,3,4} reversed is {4,3,2,1}
    // Expected: 3 descending pairs
    set<int> test1 = {1, 2, 3, 4};
    int result1 = customComp_problem4_1(test1);
    cout << "Test 1 (Simple ascending): " << (result1 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: Two elements
    // Step: Set {5,10} reversed is {10,5}
    // Expected: 1 descending pair
    set<int> test2 = {5, 10};
    int result2 = customComp_problem4_1(test2);
    cout << "Test 2 (Two elements): " << (result2 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result2 << ")" << endl;
    
    // Test 3: Larger gaps
    // Step: Set {1,10,20,30}
    // Expected: 3 descending pairs when reversed
    set<int> test3 = {1, 10, 20, 30};
    int result3 = customComp_problem4_1(test3);
    cout << "Test 3 (Larger gaps): " << (result3 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result3 << ")" << endl;
    
    // Test 4: Negative numbers
    // Step: Set {-4,-3,-2,-1}
    // Expected: 3 descending pairs when reversed
    set<int> test4 = {-4, -3, -2, -1};
    int result4 = customComp_problem4_1(test4);
    cout << "Test 4 (Negative numbers): " << (result4 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result4 << ")" << endl;
    
    // Test 5: Five elements
    // Step: Set {1,2,3,4,5}
    // Expected: 4 descending pairs when reversed
    set<int> test5 = {1, 2, 3, 4, 5};
    int result5 = customComp_problem4_1(test5);
    cout << "Test 5 (Five elements): " << (result5 == 4 ? "PASS" : "FAIL")
         << " (Expected: 4, Got: " << result5 << ")" << endl;
}

void testCustomComp_Problem4_2() {
    cout << "\n=== Testing Problem 4.2: Find Maximum Element ===" << endl;
    
    // Test 1: Positive numbers
    // Step: Set {1,5,3,9,2}
    // Expected: Maximum is 9
    set<int> test1 = {1, 5, 3, 9, 2};
    int result1 = customComp_problem4_2(test1);
    cout << "Test 1 (Positive numbers): " << (result1 == 9 ? "PASS" : "FAIL")
         << " (Expected: 9, Got: " << result1 << ")" << endl;
    
    // Test 2: All negative numbers
    // Step: Set {-10,-20,-5}
    // Expected: Maximum is -5
    set<int> test2 = {-10, -20, -5};
    int result2 = customComp_problem4_2(test2);
    cout << "Test 2 (All negative): " << (result2 == -5 ? "PASS" : "FAIL")
         << " (Expected: -5, Got: " << result2 << ")" << endl;
    
    // Test 3: Single element
    // Step: Set {42}
    // Expected: Maximum is 42
    set<int> test3 = {42};
    int result3 = customComp_problem4_2(test3);
    cout << "Test 3 (Single element): " << (result3 == 42 ? "PASS" : "FAIL")
         << " (Expected: 42, Got: " << result3 << ")" << endl;
    
    // Test 4: Mixed positive and negative
    // Step: Set {-5,0,10,3,-2}
    // Expected: Maximum is 10
    set<int> test4 = {-5, 0, 10, 3, -2};
    int result4 = customComp_problem4_2(test4);
    cout << "Test 4 (Mixed): " << (result4 == 10 ? "PASS" : "FAIL")
         << " (Expected: 10, Got: " << result4 << ")" << endl;
    
    // Test 5: Large numbers
    // Step: Set {100,500,250,750,1000}
    // Expected: Maximum is 1000
    set<int> test5 = {100, 500, 250, 750, 1000};
    int result5 = customComp_problem4_2(test5);
    cout << "Test 5 (Large numbers): " << (result5 == 1000 ? "PASS" : "FAIL")
         << " (Expected: 1000, Got: " << result5 << ")" << endl;
}

void testCustomComp_Problem4_3() {
    cout << "\n=== Testing Problem 4.3: Count Within Range ===" << endl;
    
    // Test 1: Some elements in range
    // Step: Set {1,2,3,4,5}, range [2,4]
    // Expected: 3 elements (2,3,4)
    set<int> test1 = {1, 2, 3, 4, 5};
    int result1 = customComp_problem4_3(test1, 2, 4);
    cout << "Test 1 (Some in range): " << (result1 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: One element in range
    // Step: Set {10,20,30}, range [15,25]
    // Expected: 1 element (20)
    set<int> test2 = {10, 20, 30};
    int result2 = customComp_problem4_3(test2, 15, 25);
    cout << "Test 2 (One in range): " << (result2 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result2 << ")" << endl;
    
    // Test 3: No elements in range
    // Step: Set {1,2,3}, range [10,20]
    // Expected: 0 elements
    set<int> test3 = {1, 2, 3};
    int result3 = customComp_problem4_3(test3, 10, 20);
    cout << "Test 3 (None in range): " << (result3 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result3 << ")" << endl;
    
    // Test 4: All elements in range
    // Step: Set {5,6,7,8}, range [5,8]
    // Expected: 4 elements (all)
    set<int> test4 = {5, 6, 7, 8};
    int result4 = customComp_problem4_3(test4, 5, 8);
    cout << "Test 4 (All in range): " << (result4 == 4 ? "PASS" : "FAIL")
         << " (Expected: 4, Got: " << result4 << ")" << endl;
    
    // Test 5: Range includes boundaries
    // Step: Set {1,3,5,7,9}, range [3,7]
    // Expected: 3 elements (3,5,7)
    set<int> test5 = {1, 3, 5, 7, 9};
    int result5 = customComp_problem4_3(test5, 3, 7);
    cout << "Test 5 (With boundaries): " << (result5 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result5 << ")" << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 5
// ============================================================================

void testLowerUpper_Problem5_1() {
    cout << "\n=== Testing Problem 5.1: Find First Greater or Equal ===" << endl;
    
    // Test 1: Element exists in middle
    // Step: Set {1,3,5,7,9}, target=4
    // Expected: 5 (first element >= 4)
    set<int> test1 = {1, 3, 5, 7, 9};
    int result1 = lowerUpper_problem5_1(test1, 4);
    cout << "Test 1 (Middle target): " << (result1 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result1 << ")" << endl;
    
    // Test 2: Target greater than all
    // Step: Set {1,2,3}, target=5
    // Expected: -1 (no element >= 5)
    set<int> test2 = {1, 2, 3};
    int result2 = lowerUpper_problem5_1(test2, 5);
    cout << "Test 2 (Target too large): " << (result2 == -1 ? "PASS" : "FAIL")
         << " (Expected: -1, Got: " << result2 << ")" << endl;
    
    // Test 3: Exact match
    // Step: Set {10,20,30}, target=20
    // Expected: 20 (exact match)
    set<int> test3 = {10, 20, 30};
    int result3 = lowerUpper_problem5_1(test3, 20);
    cout << "Test 3 (Exact match): " << (result3 == 20 ? "PASS" : "FAIL")
         << " (Expected: 20, Got: " << result3 << ")" << endl;
    
    // Test 4: Target smaller than all
    // Step: Set {5,10,15}, target=1
    // Expected: 5 (first element)
    set<int> test4 = {5, 10, 15};
    int result4 = lowerUpper_problem5_1(test4, 1);
    cout << "Test 4 (Target too small): " << (result4 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result4 << ")" << endl;
    
    // Test 5: Single element set
    // Step: Set {7}, target=7
    // Expected: 7
    set<int> test5 = {7};
    int result5 = lowerUpper_problem5_1(test5, 7);
    cout << "Test 5 (Single element): " << (result5 == 7 ? "PASS" : "FAIL")
         << " (Expected: 7, Got: " << result5 << ")" << endl;
}

void testLowerUpper_Problem5_2() {
    cout << "\n=== Testing Problem 5.2: Find First Strictly Greater ===" << endl;
    
    // Test 1: Element exists
    // Step: Set {1,3,5,7,9}, target=5
    // Expected: 7 (first element > 5)
    set<int> test1 = {1, 3, 5, 7, 9};
    int result1 = lowerUpper_problem5_2(test1, 5);
    cout << "Test 1 (Middle target): " << (result1 == 7 ? "PASS" : "FAIL")
         << " (Expected: 7, Got: " << result1 << ")" << endl;
    
    // Test 2: Target is maximum
    // Step: Set {1,2,3}, target=3
    // Expected: -1 (no element > 3)
    set<int> test2 = {1, 2, 3};
    int result2 = lowerUpper_problem5_2(test2, 3);
    cout << "Test 2 (Target is max): " << (result2 == -1 ? "PASS" : "FAIL")
         << " (Expected: -1, Got: " << result2 << ")" << endl;
    
    // Test 3: Target not in set
    // Step: Set {10,20,30}, target=15
    // Expected: 20 (first element > 15)
    set<int> test3 = {10, 20, 30};
    int result3 = lowerUpper_problem5_2(test3, 15);
    cout << "Test 3 (Target between): " << (result3 == 20 ? "PASS" : "FAIL")
         << " (Expected: 20, Got: " << result3 << ")" << endl;
    
    // Test 4: Target smaller than all
    // Step: Set {5,10,15}, target=1
    // Expected: 5 (first element)
    set<int> test4 = {5, 10, 15};
    int result4 = lowerUpper_problem5_2(test4, 1);
    cout << "Test 4 (Target too small): " << (result4 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result4 << ")" << endl;
    
    // Test 5: Target larger than all
    // Step: Set {1,2,3}, target=10
    // Expected: -1
    set<int> test5 = {1, 2, 3};
    int result5 = lowerUpper_problem5_2(test5, 10);
    cout << "Test 5 (Target too large): " << (result5 == -1 ? "PASS" : "FAIL")
         << " (Expected: -1, Got: " << result5 << ")" << endl;
}

void testLowerUpper_Problem5_3() {
    cout << "\n=== Testing Problem 5.3: Count Elements in Range ===" << endl;
    
    // Test 1: Multiple elements in range
    // Step: Set {1,2,3,4,5,6,7,8,9}, range [3,7]
    // Expected: 5 elements (3,4,5,6,7)
    set<int> test1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result1 = lowerUpper_problem5_3(test1, 3, 7);
    cout << "Test 1 (Multiple in range): " << (result1 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result1 << ")" << endl;
    
    // Test 2: Partial overlap
    // Step: Set {10,20,30}, range [5,15]
    // Expected: 1 element (10)
    set<int> test2 = {10, 20, 30};
    int result2 = lowerUpper_problem5_3(test2, 5, 15);
    cout << "Test 2 (Partial overlap): " << (result2 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result2 << ")" << endl;
    
    // Test 3: No elements in range
    // Step: Set {1,2,3}, range [10,20]
    // Expected: 0 elements
    set<int> test3 = {1, 2, 3};
    int result3 = lowerUpper_problem5_3(test3, 10, 20);
    cout << "Test 3 (No overlap): " << (result3 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result3 << ")" << endl;
    
    // Test 4: All elements in range
    // Step: Set {5,6,7}, range [5,7]
    // Expected: 3 elements (all)
    set<int> test4 = {5, 6, 7};
    int result4 = lowerUpper_problem5_3(test4, 5, 7);
    cout << "Test 4 (All in range): " << (result4 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result4 << ")" << endl;
    
    // Test 5: Single element in range
    // Step: Set {1,5,10,15,20}, range [8,12]
    // Expected: 1 element (10)
    set<int> test5 = {1, 5, 10, 15, 20};
    int result5 = lowerUpper_problem5_3(test5, 8, 12);
    cout << "Test 5 (Single in range): " << (result5 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result5 << ")" << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 6
// ============================================================================

void testPerformance_Problem6_1() {
    cout << "\n=== Testing Problem 6.1: Check Ordering ===" << endl;
    
    // Test 1: Sorted set
    // Step: Set {1,2,3}
    // Expected: true (maintains sorted order)
    set<int> test1 = {1, 2, 3};
    bool result1 = performance_problem6_1(test1);
    cout << "Test 1 (Sorted): " << (result1 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result1 ? "true" : "false") << ")" << endl;
    
    // Test 2: Two elements
    // Step: Set {5,10}
    // Expected: true
    set<int> test2 = {5, 10};
    bool result2 = performance_problem6_1(test2);
    cout << "Test 2 (Two elements): " << (result2 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result2 ? "true" : "false") << ")" << endl;
    
    // Test 3: Larger sorted set
    // Step: Set {1,3,5,7,9}
    // Expected: true
    set<int> test3 = {1, 3, 5, 7, 9};
    bool result3 = performance_problem6_1(test3);
    cout << "Test 3 (Larger sorted): " << (result3 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result3 ? "true" : "false") << ")" << endl;
    
    // Test 4: Negative numbers
    // Step: Set {-10,-5,0,5,10}
    // Expected: true
    set<int> test4 = {-10, -5, 0, 5, 10};
    bool result4 = performance_problem6_1(test4);
    cout << "Test 4 (With negatives): " << (result4 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result4 ? "true" : "false") << ")" << endl;
    
    // Test 5: Random insertions still sorted
    // Step: Set {9,1,5,3,7} becomes {1,3,5,7,9}
    // Expected: true
    set<int> test5 = {9, 1, 5, 3, 7};
    bool result5 = performance_problem6_1(test5);
    cout << "Test 5 (Random inserts): " << (result5 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result5 ? "true" : "false") << ")" << endl;
}

void testPerformance_Problem6_2() {
    cout << "\n=== Testing Problem 6.2: Find in Both ===" << endl;
    
    // Test 1: Element exists in both
    // Step: set {1,2,3}, unordered_set {1,2,3}, target=2
    // Expected: true
    set<int> s1 = {1, 2, 3};
    unordered_set<int> us1 = {1, 2, 3};
    bool result1 = performance_problem6_2(s1, us1, 2);
    cout << "Test 1 (Exists in both): " << (result1 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result1 ? "true" : "false") << ")" << endl;
    
    // Test 2: Element doesn't exist
    // Step: set {1,2}, unordered_set {1,2}, target=5
    // Expected: false
    set<int> s2 = {1, 2};
    unordered_set<int> us2 = {1, 2};
    bool result2 = performance_problem6_2(s2, us2, 5);
    cout << "Test 2 (Not in either): " << (result2 == false ? "PASS" : "FAIL")
         << " (Expected: false, Got: " << (result2 ? "true" : "false") << ")" << endl;
    
    // Test 3: Element only in set
    // Step: set {1,2,3}, unordered_set {1,2}, target=3
    // Expected: false (not in both)
    set<int> s3 = {1, 2, 3};
    unordered_set<int> us3 = {1, 2};
    bool result3 = performance_problem6_2(s3, us3, 3);
    cout << "Test 3 (Only in set): " << (result3 == false ? "PASS" : "FAIL")
         << " (Expected: false, Got: " << (result3 ? "true" : "false") << ")" << endl;
    
    // Test 4: Element only in unordered_set
    // Step: set {1,2}, unordered_set {1,2,3}, target=3
    // Expected: false
    set<int> s4 = {1, 2};
    unordered_set<int> us4 = {1, 2, 3};
    bool result4 = performance_problem6_2(s4, us4, 3);
    cout << "Test 4 (Only in unordered): " << (result4 == false ? "PASS" : "FAIL")
         << " (Expected: false, Got: " << (result4 ? "true" : "false") << ")" << endl;
    
    // Test 5: Negative number in both
    // Step: set {-5,0,5}, unordered_set {-5,0,5}, target=-5
    // Expected: true
    set<int> s5 = {-5, 0, 5};
    unordered_set<int> us5 = {-5, 0, 5};
    bool result5 = performance_problem6_2(s5, us5, -5);
    cout << "Test 5 (Negative in both): " << (result5 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result5 ? "true" : "false") << ")" << endl;
}

void testPerformance_Problem6_3() {
    cout << "\n=== Testing Problem 6.3: Compare Container Sizes ===" << endl;
    
    // Test 1: Different duplicates
    // Step: v1={1,2,2,3}, v2={1,1,1}
    // Expected: |3-1| = 2
    vector<int> v1_1 = {1, 2, 2, 3};
    vector<int> v2_1 = {1, 1, 1};
    int result1 = performance_problem6_3(v1_1, v2_1);
    cout << "Test 1 (Different duplicates): " << (result1 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result1 << ")" << endl;
    
    // Test 2: Same unique count
    // Step: v1={1,2,3}, v2={4,5,6}
    // Expected: |3-3| = 0
    vector<int> v1_2 = {1, 2, 3};
    vector<int> v2_2 = {4, 5, 6};
    int result2 = performance_problem6_3(v1_2, v2_2);
    cout << "Test 2 (Same unique count): " << (result2 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result2 << ")" << endl;
    
    // Test 3: One vector all duplicates
    // Step: v1={1,1,1,1}, v2={1,2,3,4}
    // Expected: |1-4| = 3
    vector<int> v1_3 = {1, 1, 1, 1};
    vector<int> v2_3 = {1, 2, 3, 4};
    int result3 = performance_problem6_3(v1_3, v2_3);
    cout << "Test 3 (One all duplicates): " << (result3 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result3 << ")" << endl;
    
    // Test 4: No duplicates
    // Step: v1={1,2,3}, v2={4,5}
    // Expected: |3-2| = 1
    vector<int> v1_4 = {1, 2, 3};
    vector<int> v2_4 = {4, 5};
    int result4 = performance_problem6_3(v1_4, v2_4);
    cout << "Test 4 (No duplicates): " << (result4 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result4 << ")" << endl;
    
    // Test 5: Both single unique
    // Step: v1={7,7,7}, v2={8,8}
    // Expected: |1-1| = 0
    vector<int> v1_5 = {7, 7, 7};
    vector<int> v2_5 = {8, 8};
    int result5 = performance_problem6_3(v1_5, v2_5);
    cout << "Test 5 (Both single unique): " << (result5 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result5 << ")" << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 7
// ============================================================================

void testOrdered_Problem7_1() {
    cout << "\n=== Testing Problem 7.1: Get Minimum Element ===" << endl;
    
    // Test 1: Positive numbers
    // Step: Set {3,1,4,2}
    // Expected: 1 (minimum)
    set<int> test1 = {3, 1, 4, 2};
    int result1 = ordered_problem7_1(test1);
    cout << "Test 1 (Positive numbers): " << (result1 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result1 << ")" << endl;
    
    // Test 2: All negative
    // Step: Set {-5,-10,0}
    // Expected: -10 (minimum)
    set<int> test2 = {-5, -10, 0};
    int result2 = ordered_problem7_1(test2);
    cout << "Test 2 (All negative): " << (result2 == -10 ? "PASS" : "FAIL")
         << " (Expected: -10, Got: " << result2 << ")" << endl;
    
    // Test 3: Single element
    // Step: Set {42}
    // Expected: 42
    set<int> test3 = {42};
    int result3 = ordered_problem7_1(test3);
    cout << "Test 3 (Single element): " << (result3 == 42 ? "PASS" : "FAIL")
         << " (Expected: 42, Got: " << result3 << ")" << endl;
    
    // Test 4: Large range
    // Step: Set {100,1,50,25,75}
    // Expected: 1
    set<int> test4 = {100, 1, 50, 25, 75};
    int result4 = ordered_problem7_1(test4);
    cout << "Test 4 (Large range): " << (result4 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result4 << ")" << endl;
    
    // Test 5: Two elements
    // Step: Set {10,5}
    // Expected: 5
    set<int> test5 = {10, 5};
    int result5 = ordered_problem7_1(test5);
    cout << "Test 5 (Two elements): " << (result5 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result5 << ")" << endl;
}

void testOrdered_Problem7_2() {
    cout << "\n=== Testing Problem 7.2: Check Sorted Property ===" << endl;
    
    // Test 1: Normal set
    // Step: Set {1,2,3,4}
    // Expected: true (sets are always sorted)
    set<int> test1 = {1, 2, 3, 4};
    bool result1 = ordered_problem7_2(test1);
    cout << "Test 1 (Normal set): " << (result1 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result1 ? "true" : "false") << ")" << endl;
    
    // Test 2: Random insertion order
    // Step: Set {5,1,3,2,4}
    // Expected: true (becomes sorted)
    set<int> test2 = {5, 1, 3, 2, 4};
    bool result2 = ordered_problem7_2(test2);
    cout << "Test 2 (Random insertion): " << (result2 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result2 ? "true" : "false") << ")" << endl;
    
    // Test 3: Negative numbers
    // Step: Set {-1,-5,-3}
    // Expected: true
    set<int> test3 = {-1, -5, -3};
    bool result3 = ordered_problem7_2(test3);
    cout << "Test 3 (Negative numbers): " << (result3 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result3 ? "true" : "false") << ")" << endl;
    
    // Test 4: Single element
    // Step: Set {7}
    // Expected: true
    set<int> test4 = {7};
    bool result4 = ordered_problem7_2(test4);
    cout << "Test 4 (Single element): " << (result4 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result4 ? "true" : "false") << ")" << endl;
    
    // Test 5: Large gaps
    // Step: Set {1,100,50,25}
    // Expected: true (becomes 1,25,50,100)
    set<int> test5 = {1, 100, 50, 25};
    bool result5 = ordered_problem7_2(test5);
    cout << "Test 5 (Large gaps): " << (result5 == true ? "PASS" : "FAIL")
         << " (Expected: true, Got: " << (result5 ? "true" : "false") << ")" << endl;
}

void testOrdered_Problem7_3() {
    cout << "\n=== Testing Problem 7.3: Find Median ===" << endl;
    
    // Test 1: Odd size
    // Step: Set {1,2,3,4,5}
    // Expected: 3 (middle element)
    set<int> test1 = {1, 2, 3, 4, 5};
    int result1 = ordered_problem7_3(test1);
    cout << "Test 1 (Odd size): " << (result1 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: Even size
    // Step: Set {1,2,3,4}
    // Expected: 2 (lower middle)
    set<int> test2 = {1, 2, 3, 4};
    int result2 = ordered_problem7_3(test2);
    cout << "Test 2 (Even size): " << (result2 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result2 << ")" << endl;
    
    // Test 3: Single element
    // Step: Set {10}
    // Expected: 10
    set<int> test3 = {10};
    int result3 = ordered_problem7_3(test3);
    cout << "Test 3 (Single element): " << (result3 == 10 ? "PASS" : "FAIL")
         << " (Expected: 10, Got: " << result3 << ")" << endl;
    
    // Test 4: Two elements
    // Step: Set {5,10}
    // Expected: 5 (lower middle)
    set<int> test4 = {5, 10};
    int result4 = ordered_problem7_3(test4);
    cout << "Test 4 (Two elements): " << (result4 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result4 << ")" << endl;
    
    // Test 5: Seven elements
    // Step: Set {10,20,30,40,50,60,70}
    // Expected: 40 (middle element)
    set<int> test5 = {10, 20, 30, 40, 50, 60, 70};
    int result5 = ordered_problem7_3(test5);
    cout << "Test 5 (Seven elements): " << (result5 == 40 ? "PASS" : "FAIL")
         << " (Expected: 40, Got: " << result5 << ")" << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 8
// ============================================================================

void testDuplicateRemoval_Problem8_1() {
    cout << "\n=== Testing Problem 8.1: Count Duplicates Removed ===" << endl;
    
    // Test 1: Some duplicates
    // Step: Vector {1,2,2,3,3,3}
    // Expected: 3 duplicates removed (6-3=3)
    vector<int> test1 = {1, 2, 2, 3, 3, 3};
    int result1 = duplicateRemoval_problem8_1(test1);
    cout << "Test 1 (Some duplicates): " << (result1 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: No duplicates
    // Step: Vector {1,2,3}
    // Expected: 0 duplicates removed
    vector<int> test2 = {1, 2, 3};
    int result2 = duplicateRemoval_problem8_1(test2);
    cout << "Test 2 (No duplicates): " << (result2 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result2 << ")" << endl;
    
    // Test 3: All same
    // Step: Vector {5,5,5,5}
    // Expected: 3 duplicates removed (4-1=3)
    vector<int> test3 = {5, 5, 5, 5};
    int result3 = duplicateRemoval_problem8_1(test3);
    cout << "Test 3 (All same): " << (result3 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result3 << ")" << endl;
    
    // Test 4: Single element
    // Step: Vector {1}
    // Expected: 0 duplicates removed
    vector<int> test4 = {1};
    int result4 = duplicateRemoval_problem8_1(test4);
    cout << "Test 4 (Single element): " << (result4 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result4 << ")" << endl;
    
    // Test 5: Many duplicates
    // Step: Vector {1,1,2,2,3,3,4,4}
    // Expected: 4 duplicates removed (8-4=4)
    vector<int> test5 = {1, 1, 2, 2, 3, 3, 4, 4};
    int result5 = duplicateRemoval_problem8_1(test5);
    cout << "Test 5 (Many duplicates): " << (result5 == 4 ? "PASS" : "FAIL")
         << " (Expected: 4, Got: " << result5 << ")" << endl;
}

void testDuplicateRemoval_Problem8_2() {
    cout << "\n=== Testing Problem 8.2: Remove Duplicates from String ===" << endl;
    
    // Test 1: Normal string
    // Step: "hello"
    // Expected: "helo" (second 'l' removed)
    string test1 = "hello";
    string result1 = duplicateRemoval_problem8_2(test1);
    cout << "Test 1 (Normal string): " << (result1 == "helo" ? "PASS" : "FAIL")
         << " (Expected: helo, Got: " << result1 << ")" << endl;
    
    // Test 2: All duplicates
    // Step: "aabbcc"
    // Expected: "abc"
    string test2 = "aabbcc";
    string result2 = duplicateRemoval_problem8_2(test2);
    cout << "Test 2 (All duplicates): " << (result2 == "abc" ? "PASS" : "FAIL")
         << " (Expected: abc, Got: " << result2 << ")" << endl;
    
    // Test 3: No duplicates
    // Step: "abcdef"
    // Expected: "abcdef"
    string test3 = "abcdef";
    string result3 = duplicateRemoval_problem8_2(test3);
    cout << "Test 3 (No duplicates): " << (result3 == "abcdef" ? "PASS" : "FAIL")
         << " (Expected: abcdef, Got: " << result3 << ")" << endl;
    
    // Test 4: Single character
    // Step: "a"
    // Expected: "a"
    string test4 = "a";
    string result4 = duplicateRemoval_problem8_2(test4);
    cout << "Test 4 (Single char): " << (result4 == "a" ? "PASS" : "FAIL")
         << " (Expected: a, Got: " << result4 << ")" << endl;
    
    // Test 5: All same character
    // Step: "aaaaa"
    // Expected: "a"
    string test5 = "aaaaa";
    string result5 = duplicateRemoval_problem8_2(test5);
    cout << "Test 5 (All same): " << (result5 == "a" ? "PASS" : "FAIL")
         << " (Expected: a, Got: " << result5 << ")" << endl;
}

void testDuplicateRemoval_Problem8_3() {
    cout << "\n=== Testing Problem 8.3: Keep Only Duplicates ===" << endl;
    
    // Test 1: Some duplicates
    // Step: Vector {1,2,2,3,3,3,4}
    // Expected: {2,3} (elements with duplicates)
    vector<int> test1 = {1, 2, 2, 3, 3, 3, 4};
    vector<int> result1 = duplicateRemoval_problem8_3(test1);
    vector<int> expected1 = {2, 3};
    bool pass1 = (result1.size() == expected1.size() && 
                  equal(result1.begin(), result1.end(), expected1.begin()));
    cout << "Test 1 (Some duplicates): " << (pass1 ? "PASS" : "FAIL") << endl;
    
    // Test 2: No duplicates
    // Step: Vector {1,2,3,4}
    // Expected: {} (empty)// Test 2: No duplicates
    // Step: Vector {1,2,3,4}
    // Expected: {} (empty)
    vector<int> test2 = {1, 2, 3, 4};
    vector<int> result2 = duplicateRemoval_problem8_3(test2);
    bool pass2 = (result2.size() == 0);
    cout << "Test 2 (No duplicates): " << (pass2 ? "PASS" : "FAIL") << endl;
    
    // Test 3: All duplicates
    // Step: Vector {1,1,2,2,3,3}
    // Expected: {1,2,3} (all have duplicates)
    vector<int> test3 = {1, 1, 2, 2, 3, 3};
    vector<int> result3 = duplicateRemoval_problem8_3(test3);
    vector<int> expected3 = {1, 2, 3};
    bool pass3 = (result3.size() == expected3.size() && 
                  equal(result3.begin(), result3.end(), expected3.begin()));
    cout << "Test 3 (All duplicates): " << (pass3 ? "PASS" : "FAIL") << endl;
    
    // Test 4: Single duplicate pair
    // Step: Vector {1,2,3,3}
    // Expected: {3}
    vector<int> test4 = {1, 2, 3, 3};
    vector<int> result4 = duplicateRemoval_problem8_3(test4);
    bool pass4 = (result4.size() == 1 && result4[0] == 3);
    cout << "Test 4 (Single duplicate): " << (pass4 ? "PASS" : "FAIL") << endl;
    
    // Test 5: All same element
    // Step: Vector {5,5,5,5}
    // Expected: {5}
    vector<int> test5 = {5, 5, 5, 5};
    vector<int> result5 = duplicateRemoval_problem8_3(test5);
    bool pass5 = (result5.size() == 1 && result5[0] == 5);
    cout << "Test 5 (All same): " << (pass5 ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 9
// ============================================================================

void testUniqueTracking_Problem9_1() {
    cout << "\n=== Testing Problem 9.1: Count Unique Elements ===" << endl;
    
    // Test 1: Some duplicates
    // Step: Vector {1,1,2,2,3}
    // Expected: 3 unique elements
    vector<int> test1 = {1, 1, 2, 2, 3};
    int result1 = uniqueTracking_problem9_1(test1);
    cout << "Test 1 (Some duplicates): " << (result1 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: All same
    // Step: Vector {5,5,5,5}
    // Expected: 1 unique element
    vector<int> test2 = {5, 5, 5, 5};
    int result2 = uniqueTracking_problem9_1(test2);
    cout << "Test 2 (All same): " << (result2 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result2 << ")" << endl;
    
    // Test 3: All unique
    // Step: Vector {1,2,3,4,5}
    // Expected: 5 unique elements
    vector<int> test3 = {1, 2, 3, 4, 5};
    int result3 = uniqueTracking_problem9_1(test3);
    cout << "Test 3 (All unique): " << (result3 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result3 << ")" << endl;
    
    // Test 4: Single element
    // Step: Vector {10}
    // Expected: 1 unique element
    vector<int> test4 = {10};
    int result4 = uniqueTracking_problem9_1(test4);
    cout << "Test 4 (Single element): " << (result4 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result4 << ")" << endl;
    
    // Test 5: Mixed duplicates
    // Step: Vector {1,2,1,3,2,4}
    // Expected: 4 unique elements (1,2,3,4)
    vector<int> test5 = {1, 2, 1, 3, 2, 4};
    int result5 = uniqueTracking_problem9_1(test5);
    cout << "Test 5 (Mixed duplicates): " << (result5 == 4 ? "PASS" : "FAIL")
         << " (Expected: 4, Got: " << result5 << ")" << endl;
}

void testUniqueTracking_Problem9_2() {
    cout << "\n=== Testing Problem 9.2: First Unique Element ===" << endl;
    
    // Test 1: Has unique element
    // Step: Vector {1,2,2,3,3,4}
    // Expected: 1 (first unique)
    vector<int> test1 = {1, 2, 2, 3, 3, 4};
    int result1 = uniqueTracking_problem9_2(test1);
    cout << "Test 1 (Has unique): " << (result1 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result1 << ")" << endl;
    
    // Test 2: No unique elements
    // Step: Vector {1,1,2,2}
    // Expected: -1
    vector<int> test2 = {1, 1, 2, 2};
    int result2 = uniqueTracking_problem9_2(test2);
    cout << "Test 2 (No unique): " << (result2 == -1 ? "PASS" : "FAIL")
         << " (Expected: -1, Got: " << result2 << ")" << endl;
    
    // Test 3: All unique
    // Step: Vector {1,2,3}
    // Expected: 1 (first element)
    vector<int> test3 = {1, 2, 3};
    int result3 = uniqueTracking_problem9_2(test3);
    cout << "Test 3 (All unique): " << (result3 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result3 << ")" << endl;
    
    // Test 4: Unique at end
    // Step: Vector {1,1,2,2,3}
    // Expected: 3
    vector<int> test4 = {1, 1, 2, 2, 3};
    int result4 = uniqueTracking_problem9_2(test4);
    cout << "Test 4 (Unique at end): " << (result4 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result4 << ")" << endl;
    
    // Test 5: Single element
    // Step: Vector {5}
    // Expected: 5
    vector<int> test5 = {5};
    int result5 = uniqueTracking_problem9_2(test5);
    cout << "Test 5 (Single element): " << (result5 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result5 << ")" << endl;
}

void testUniqueTracking_Problem9_3() {
    cout << "\n=== Testing Problem 9.3: Count Unique Pairs ===" << endl;
    
    // Test 1: Three unique elements
    // Step: Vector {1,2,3}
    // Expected: 3 pairs (C(3,2) = 3)
    vector<int> test1 = {1, 2, 3};
    int result1 = uniqueTracking_problem9_3(test1);
    cout << "Test 1 (Three unique): " << (result1 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: With duplicates
    // Step: Vector {1,1,2}
    // Expected: 1 pair (only pair (1,2))
    vector<int> test2 = {1, 1, 2};
    int result2 = uniqueTracking_problem9_3(test2);
    cout << "Test 2 (With duplicates): " << (result2 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result2 << ")" << endl;
    
    // Test 3: Two unique elements
    // Step: Vector {1,2,1,2}
    // Expected: 1 pair
    vector<int> test3 = {1, 2, 1, 2};
    int result3 = uniqueTracking_problem9_3(test3);
    cout << "Test 3 (Two unique): " << (result3 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result3 << ")" << endl;
    
    // Test 4: Four unique elements
    // Step: Vector {1,2,3,4}
    // Expected: 6 pairs (C(4,2) = 6)
    vector<int> test4 = {1, 2, 3, 4};
    int result4 = uniqueTracking_problem9_3(test4);
    cout << "Test 4 (Four unique): " << (result4 == 6 ? "PASS" : "FAIL")
         << " (Expected: 6, Got: " << result4 << ")" << endl;
    
    // Test 5: Single unique element
    // Step: Vector {5,5,5}
    // Expected: 0 pairs (C(1,2) = 0)
    vector<int> test5 = {5, 5, 5};
    int result5 = uniqueTracking_problem9_3(test5);
    cout << "Test 5 (Single unique): " << (result5 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result5 << ")" << endl;
}

// ============================================================================
// TEST FUNCTIONS - CONCEPT 10
// ============================================================================

void testSearchOps_Problem10_1() {
    cout << "\n=== Testing Problem 10.1: Fast Membership Check ===" << endl;
    
    // Test 1: Some queries found
    // Step: set {1,2,3,4,5}, queries {2,4,6,8}
    // Expected: 2 (2 and 4 found)
    set<int> s1 = {1, 2, 3, 4, 5};
    vector<int> q1 = {2, 4, 6, 8};
    int result1 = searchOps_problem10_1(s1, q1);
    cout << "Test 1 (Some found): " << (result1 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result1 << ")" << endl;
    
    // Test 2: Multiple found
    // Step: set {10,20}, queries {5,10,15,20}
    // Expected: 2 (10 and 20 found)
    set<int> s2 = {10, 20};
    vector<int> q2 = {5, 10, 15, 20};
    int result2 = searchOps_problem10_1(s2, q2);
    cout << "Test 2 (Multiple found): " << (result2 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result2 << ")" << endl;
    
    // Test 3: None found
    // Step: set {1,2,3}, queries {4,5,6}
    // Expected: 0
    set<int> s3 = {1, 2, 3};
    vector<int> q3 = {4, 5, 6};
    int result3 = searchOps_problem10_1(s3, q3);
    cout << "Test 3 (None found): " << (result3 == 0 ? "PASS" : "FAIL")
         << " (Expected: 0, Got: " << result3 << ")" << endl;
    
    // Test 4: All found
    // Step: set {1,2,3,4,5}, queries {1,2,3}
    // Expected: 3
    set<int> s4 = {1, 2, 3, 4, 5};
    vector<int> q4 = {1, 2, 3};
    int result4 = searchOps_problem10_1(s4, q4);
    cout << "Test 4 (All found): " << (result4 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result4 << ")" << endl;
    
    // Test 5: Single query
    // Step: set {5,10,15}, query {10}
    // Expected: 1
    set<int> s5 = {5, 10, 15};
    vector<int> q5 = {10};
    int result5 = searchOps_problem10_1(s5, q5);
    cout << "Test 5 (Single query): " << (result5 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result5 << ")" << endl;
}

void testSearchOps_Problem10_2() {
    cout << "\n=== Testing Problem 10.2: Find Missing Number ===" << endl;
    
    // Test 1: Missing in middle
    // Step: Set {1,2,4,5}
    // Expected: 3 (missing number)
    set<int> test1 = {1, 2, 4, 5};
    int result1 = searchOps_problem10_2(test1);
    cout << "Test 1 (Missing in middle): " << (result1 == 3 ? "PASS" : "FAIL")
         << " (Expected: 3, Got: " << result1 << ")" << endl;
    
    // Test 2: Missing at start
    // Step: Set {2,3,4,5,6}
    // Expected: 1
    set<int> test2 = {2, 3, 4, 5, 6};
    int result2 = searchOps_problem10_2(test2);
    cout << "Test 2 (Missing at start): " << (result2 == 1 ? "PASS" : "FAIL")
         << " (Expected: 1, Got: " << result2 << ")" << endl;
    
    // Test 3: Missing at end
    // Step: Set {1,2,3,4}
    // Expected: 5
    set<int> test3 = {1, 2, 3, 4};
    int result3 = searchOps_problem10_2(test3);
    cout << "Test 3 (Missing at end): " << (result3 == 5 ? "PASS" : "FAIL")
         << " (Expected: 5, Got: " << result3 << ")" << endl;
    
    // Test 4: Small set
    // Step: Set {1,3}
    // Expected: 2
    set<int> test4 = {1, 3};
    int result4 = searchOps_problem10_2(test4);
    cout << "Test 4 (Small set): " << (result4 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result4 << ")" << endl;
    
    // Test 5: Another middle case
    // Step: Set {1,3,4,5,6}
    // Expected: 2
    set<int> test5 = {1, 3, 4, 5, 6};
    int result5 = searchOps_problem10_2(test5);
    cout << "Test 5 (Another middle): " << (result5 == 2 ? "PASS" : "FAIL")
         << " (Expected: 2, Got: " << result5 << ")" << endl;
}

void testSearchOps_Problem10_3() {
    cout << "\n=== Testing Problem 10.3: Count Range Queries ===" << endl;
    
    // Test 1: Multiple ranges
    // Step: set {1,2,3,4,5}, queries [(1,3), (2,4)]
    // Expected: {3, 3}
    set<int> s1 = {1, 2, 3, 4, 5};
    vector<pair<int,int>> ranges1 = {{1,3}, {2,4}};
    vector<int> result1 = searchOps_problem10_3(s1, ranges1);
    vector<int> expected1 = {3, 3};
    bool pass1 = (result1 == expected1);
    cout << "Test 1 (Multiple ranges): " << (pass1 ? "PASS" : "FAIL") << endl;
    
    // Test 2: Different counts
    // Step: set {10,20,30}, queries [(5,15), (15,25)]
    // Expected: {1, 1}
    set<int> s2 = {10, 20, 30};
    vector<pair<int,int>> ranges2 = {{5,15}, {15,25}};
    vector<int> result2 = searchOps_problem10_3(s2, ranges2);
    vector<int> expected2 = {1, 1};
    bool pass2 = (result2 == expected2);
    cout << "Test 2 (Different counts): " << (pass2 ? "PASS" : "FAIL") << endl;
    
    // Test 3: Empty range
    // Step: set {1,2,3}, query [(10,20)]
    // Expected: {0}
    set<int> s3 = {1, 2, 3};
    vector<pair<int,int>> ranges3 = {{10,20}};
    vector<int> result3 = searchOps_problem10_3(s3, ranges3);
    bool pass3 = (result3.size() == 1 && result3[0] == 0);
    cout << "Test 3 (Empty range): " << (pass3 ? "PASS" : "FAIL") << endl;
    
    // Test 4: Full range
    // Step: set {1,2,3,4,5}, query [(1,5)]
    // Expected: {5}
    set<int> s4 = {1, 2, 3, 4, 5};
    vector<pair<int,int>> ranges4 = {{1,5}};
    vector<int> result4 = searchOps_problem10_3(s4, ranges4);
    bool pass4 = (result4.size() == 1 && result4[0] == 5);
    cout << "Test 4 (Full range): " << (pass4 ? "PASS" : "FAIL") << endl;
    
    // Test 5: Three queries
    // Step: set {1,5,10,15,20}, queries [(1,6), (8,16), (18,25)]
    // Expected: {2, 2, 1}
    set<int> s5 = {1, 5, 10, 15, 20};
    vector<pair<int,int>> ranges5 = {{1,6}, {8,16}, {18,25}};
    vector<int> result5 = searchOps_problem10_3(s5, ranges5);
    vector<int> expected5 = {2, 2, 1};
    bool pass5 = (result5 == expected5);
    cout << "Test 5 (Three queries): " << (pass5 ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    int conceptChoice, problemChoice;
    
    cout << "=== C++ SETS PRACTICE PROBLEMS ===" << endl;
    cout << "\nSelect Concept:" << endl;
    cout << "1. Basic Set Operations" << endl;
    cout << "2. Set Iterators and Traversal" << endl;
    cout << "3. Set Algorithms" << endl;
    cout << "4. Custom Comparators and Sorting" << endl;
    cout << "5. Lower_bound and Upper_bound" << endl;
    cout << "6. Set vs Unordered_set Performance" << endl;
    cout << "7. Ordered vs Unordered Data Structures" << endl;
    cout << "8. Duplicate Removal" << endl;
    cout << "9. Unique Element Tracking" << endl;
    cout << "10. Set-based Search Operations" << endl;
    cout << "0. Exit" << endl;
    cout << "\nEnter concept number: ";
    cin >> conceptChoice;
    
    if (conceptChoice == 0) {
        cout << "Exiting..." << endl;
        return 0;
    }
    
    if (conceptChoice < 1 || conceptChoice > 10) {
        cout << "Invalid concept number!" << endl;
        return 1;
    }
    
    string conceptNames[] = {
        "", "Basic Set Operations", "Set Iterators and Traversal",
        "Set Algorithms", "Custom Comparators and Sorting",
        "Lower_bound and Upper_bound", "Set vs Unordered_set Performance",
        "Ordered vs Unordered Data Structures", "Duplicate Removal",
        "Unique Element Tracking", "Set-based Search Operations"
    };
    
    cout << "\n=== CONCEPT " << conceptChoice << ": " << conceptNames[conceptChoice] << " ===" << endl;
    cout << "Choose a problem to test:" << endl;
    cout << "1. Problem " << conceptChoice << ".1 (Easy)" << endl;
    cout << "2. Problem " << conceptChoice << ".2 (Easy)" << endl;
    cout << "3. Problem " << conceptChoice << ".3 (Medium)" << endl;
    cout << "4. Test All Problems for this Concept" << endl;
    cout << "Enter your choice: ";
    cin >> problemChoice;
    
    switch(conceptChoice) {
        case 1:
            if (problemChoice == 1) testBasicOps_Problem1_1();
            else if (problemChoice == 2) testBasicOps_Problem1_2();
            else if (problemChoice == 3) testBasicOps_Problem1_3();
            else if (problemChoice == 4) {
                testBasicOps_Problem1_1();
                testBasicOps_Problem1_2();
                testBasicOps_Problem1_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        case 2:
            if (problemChoice == 1) testIterators_Problem2_1();
            else if (problemChoice == 2) testIterators_Problem2_2();
            else if (problemChoice == 3) testIterators_Problem2_3();
            else if (problemChoice == 4) {
                testIterators_Problem2_1();
                testIterators_Problem2_2();
                testIterators_Problem2_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        case 3:
            if (problemChoice == 1) testSetAlgo_Problem3_1();
            else if (problemChoice == 2) testSetAlgo_Problem3_2();
            else if (problemChoice == 3) testSetAlgo_Problem3_3();
            else if (problemChoice == 4) {
                testSetAlgo_Problem3_1();
                testSetAlgo_Problem3_2();
                testSetAlgo_Problem3_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        case 4:
            if (problemChoice == 1) testCustomComp_Problem4_1();
            else if (problemChoice == 2) testCustomComp_Problem4_2();
            else if (problemChoice == 3) testCustomComp_Problem4_3();
            else if (problemChoice == 4) {
                testCustomComp_Problem4_1();
                testCustomComp_Problem4_2();
                testCustomComp_Problem4_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        case 5:
            if (problemChoice == 1) testLowerUpper_Problem5_1();
            else if (problemChoice == 2) testLowerUpper_Problem5_2();
            else if (problemChoice == 3) testLowerUpper_Problem5_3();
            else if (problemChoice == 4) {
                testLowerUpper_Problem5_1();
                testLowerUpper_Problem5_2();
                testLowerUpper_Problem5_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        case 6:
            if (problemChoice == 1) testPerformance_Problem6_1();
            else if (problemChoice == 2) testPerformance_Problem6_2();
            else if (problemChoice == 3) testPerformance_Problem6_3();
            else if (problemChoice == 4) {
                testPerformance_Problem6_1();
                testPerformance_Problem6_2();
                testPerformance_Problem6_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        case 7:
            if (problemChoice == 1) testOrdered_Problem7_1();
            else if (problemChoice == 2) testOrdered_Problem7_2();
            else if (problemChoice == 3) testOrdered_Problem7_3();
            else if (problemChoice == 4) {
                testOrdered_Problem7_1();
                testOrdered_Problem7_2();
                testOrdered_Problem7_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        case 8:
            if (problemChoice == 1) testDuplicateRemoval_Problem8_1();
            else if (problemChoice == 2) testDuplicateRemoval_Problem8_2();
            else if (problemChoice == 3) testDuplicateRemoval_Problem8_3();
            else if (problemChoice == 4) {
                testDuplicateRemoval_Problem8_1();
                testDuplicateRemoval_Problem8_2();
                testDuplicateRemoval_Problem8_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        case 9:
            if (problemChoice == 1) testUniqueTracking_Problem9_1();
            else if (problemChoice == 2) testUniqueTracking_Problem9_2();
            else if (problemChoice == 3) testUniqueTracking_Problem9_3();
            else if (problemChoice == 4) {
                testUniqueTracking_Problem9_1();
                testUniqueTracking_Problem9_2();
                testUniqueTracking_Problem9_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        case 10:
            if (problemChoice == 1) testSearchOps_Problem10_1();
            else if (problemChoice == 2) testSearchOps_Problem10_2();
            else if (problemChoice == 3) testSearchOps_Problem10_3();
            else if (problemChoice == 4) {
                testSearchOps_Problem10_1();
                testSearchOps_Problem10_2();
                testSearchOps_Problem10_3();
            }
            else cout << "Invalid choice!" << endl;
            break;
            
        default:
            cout << "Invalid concept!" << endl;
    }
    
    return 0;
}