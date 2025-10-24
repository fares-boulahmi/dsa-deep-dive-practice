#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

// Helper function to print a set
template <typename T>
void printSet(const set<T> &s)
{
    cout << "{ ";
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (it != s.begin())
            cout << ", ";
        cout << *it;
    }
    cout << " }";
}

// Helper function to compare sets
template <typename T>
bool setsEqual(const set<T> &s1, const set<T> &s2)
{
    return s1 == s2;
}

// ============================================================================
// PROBLEM SET FOR SETS
// ============================================================================

// Problem 1: Easy - Count Unique Elements
// Given an array of integers, count how many unique elements exist.
// Input: A vector of integers (may contain duplicates)
// Output: Integer representing the count of unique elements
//
// Example 1:
// Input: [1, 2, 3, 2, 1, 4]
// Output: 4
//
// Example 2:
// Input: [5, 5, 5, 5]
// Output: 1
//
// Example 3:
// Input: []
// Output: 0
//
// Constraints:
// - Array size: 0 <= n <= 10^5
// - Element values: -10^9 <= elements <= 10^9
int problem1Solution(const vector<int> &arr)
{
    // TODO: Implement your solution here using Sets
    // Hint: Insert all elements into a set and return its size
    set<int> result;
    for (size_t i = 0; i < arr.size(); i++)
    {
        result.insert(arr[i]);
    }

    return result.size();
}

// Problem 2: Easy - Check Element Existence
// Given a set of integers and a target value, check if the target exists in the set.
// Input: A set of integers and a target integer
// Output: Boolean indicating if target exists
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
// - Set size: 0 <= n <= 10^5
// - Element values and target: -10^9 <= value <= 10^9
bool problem2Solution(const set<int> &s, int target)
{
    // TODO: Implement your solution here using Sets
    // Hint: Use the find() method of set
    if (s.find(target) != s.end())
    {
        return true;
    }

    return false;
}

// Problem 3: Easy - Find Minimum and Maximum
// Given a set of integers, find both the minimum and maximum values.
// Input: A non-empty set of integers
// Output: A pair containing (minimum, maximum)
//
// Example 1:
// Input: {3, 1, 4, 1, 5, 9}
// Output: (1, 9)
//
// Example 2:
// Input: {-5, -2, 0, 3}
// Output: (-5, 3)
//
// Example 3:
// Input: {42}
// Output: (42, 42)
//
// Constraints:
// - Set size: 1 <= n <= 10^5
// - Element values: -10^9 <= elements <= 10^9
pair<int, int> problem3Solution(const set<int> &s)
{
    // TODO: Implement your solution here using Sets
    // Hint: Sets are sorted, use begin() and rbegin() or --end()
    if (s.size() == 0)
        return {0, 0};
    int min = INT_MAX;
    int max = INT_MIN;
    for (auto elm : s)
    {
        if (elm > max)
        {
            max = elm;
        }
        if (elm < min)
        {
            min = elm;
        }
    }

    return {min, max};
}

// Problem 4: Medium - Union of Two Sets
// Given two sets of integers, return their union (all unique elements from both sets).
// Input: Two sets of integers
// Output: A new set containing all unique elements from both input sets
//
// Example 1:
// Input: set1 = {1, 2, 3}, set2 = {3, 4, 5}
// Output: {1, 2, 3, 4, 5}
//
// Example 2:
// Input: set1 = {1, 2}, set2 = {}
// Output: {1, 2}
//
// Example 3:
// Input: set1 = {}, set2 = {}
// Output: {}
//
// Constraints:
// - Set sizes: 0 <= n1, n2 <= 10^4
// - Element values: -10^6 <= elements <= 10^6
set<int> problem4Solution(const set<int> &set1, const set<int> &set2)
{
    // TODO: Implement your solution here using Sets
    // Hint: Insert all elements from both sets into a new set
    set<int> result{};
    if (set1.size() == 0 && set2.size() == 0)
        return result;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));
    return result;
}

// Problem 5: Medium - Intersection of Two Sets
// Given two sets of integers, return their intersection (elements present in both sets).
// Input: Two sets of integers
// Output: A new set containing only elements present in both input sets
//
// Example 1:
// Input: set1 = {1, 2, 3, 4}, set2 = {3, 4, 5, 6}
// Output: {3, 4}
//
// Example 2:
// Input: set1 = {1, 2, 3}, set2 = {4, 5, 6}
// Output: {}
//
// Example 3:
// Input: set1 = {1, 2, 3}, set2 = {1, 2, 3}
// Output: {1, 2, 3}
//
// Constraints:
// - Set sizes: 0 <= n1, n2 <= 10^4
// - Element values: -10^6 <= elements <= 10^6
set<int> problem5Solution(const set<int> &set1, const set<int> &set2)
{
    // TODO: Implement your solution here using Sets
    // Hint: Iterate through one set and check if each element exists in the other
    set<int> result{};
    for (auto elm : set1)
    {
        for (auto elm2 : set2)
        {
            if (elm == elm2)
            {
                result.insert(elm);
            }
        }
    }

    return result;
}

// Problem 6: Medium - Symmetric Difference
// Given two sets, return their symmetric difference (elements in either set but not in both).
// Input: Two sets of integers
// Output: A new set containing elements present in exactly one of the input sets
//
// Example 1:
// Input: set1 = {1, 2, 3}, set2 = {2, 3, 4}
// Output: {1, 4}
//
// Example 2:
// Input: set1 = {1, 2}, set2 = {3, 4}
// Output: {1, 2, 3, 4}
//
// Example 3:
// Input: set1 = {1, 2, 3}, set2 = {1, 2, 3}
// Output: {}
//
// Constraints:
// - Set sizes: 0 <= n1, n2 <= 10^4
// - Element values: -10^6 <= elements <= 10^6
set<int> problem6Solution(const set<int> &set1, const set<int> &set2)
{
    // TODO: Implement your solution here using Sets
    // Hint: (set1 - set2) union (set2 - set1), or use XOR logic
    set<int> result{};
    if (set1.size() == 0 && set2.size() == 0)
        return result;
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));
    return result;
}

// Problem 7: Hard - Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest consecutive
// elements sequence. The algorithm must run in O(n) time complexity.
// Input: A vector of integers
// Output: Integer representing the length of the longest consecutive sequence
//
// Example 1:
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4 (The sequence is [1, 2, 3, 4])
//
// Example 2:
// Input: [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
// Output: 9 (The sequence is [0, 1, 2, 3, 4, 5, 6, 7, 8])
//
// Example 3:
// Input: [9, 1, 4, 7, 3, 2, 8, 5, 6]
// Output: 9
//
// Constraints:
// - Array size: 0 <= n <= 10^5
// - Element values: -10^9 <= elements <= 10^9
// - Time complexity must be O(n)
int problem7Solution(const vector<int> &arr)
{
    // TODO: Implement your solution here using Sets
    // Hint: Use a set for O(1) lookups. For each element, check if it's the start of a sequence
    return 0;
}

// Problem 8: Hard - Find All Missing Numbers in Range
// Given an array of n integers where each integer is in the range [1, n+k],
// find all numbers in the range [1, n+k] that are missing from the array.
// Return them in a sorted set.
// Input: A vector of integers and an integer k
// Output: A set of missing integers in the range [1, n+k]
//
// Example 1:
// Input: arr = [4, 3, 2, 7, 8], k = 3
// Output: {1, 5, 6} (range is [1, 8], missing: 1, 5, 6)
//
// Example 2:
// Input: arr = [1, 1], k = 2
// Output: {2, 3, 4} (range is [1, 4], missing: 2, 3, 4)
//
// Example 3:
// Input: arr = [2, 3, 4], k = 1
// Output: {1} (range is [1, 4], missing: 1)
//
// Constraints:
// - Array size: 1 <= n <= 10^4
// - k: 0 <= k <= 100
// - Element values: 1 <= elements <= n+k
set<int> problem8Solution(const vector<int> &arr, int k)
{
    // TODO: Implement your solution here using Sets
    // Hint: Create a set from array, then iterate through range to find missing numbers
    set<int> all{};
    set<int> missSet{};
    set<int> result{};
    k = k + arr.size();
    for (int i = 1; i <= k; i++)
    {
        all.insert(i);
    }
    for (size_t i = 0; i < arr.size(); i++)
    {
        missSet.insert(arr[i]);
        all.insert(arr[i]);
    }
    set_symmetric_difference(all.begin(), all.end(), missSet.begin(), missSet.end(), inserter(result, result.begin()));

    return result;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Count Unique Elements ===" << endl;

    // Test Case 1: Normal case with duplicates
    // Manual verification: [1, 2, 3, 2, 1, 4] has unique elements {1, 2, 3, 4} = 4 elements
    vector<int> arr1 = {1, 2, 3, 2, 1, 4};
    cout << "Test 1 - Input: [1, 2, 3, 2, 1, 4]" << endl;
    int result1 = problem1Solution(arr1);
    cout << "Expected: 4, Got: " << result1 << endl;
    cout << "Result: " << (result1 == 4 ? "PASS" : "FAIL") << endl;

    // Test Case 2: All same elements
    // Manual verification: [5, 5, 5, 5] has only one unique element = 1
    vector<int> arr2 = {5, 5, 5, 5};
    cout << "\nTest 2 - Input: [5, 5, 5, 5]" << endl;
    int result2 = problem1Solution(arr2);
    cout << "Expected: 1, Got: " << result2 << endl;
    cout << "Result: " << (result2 == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Empty array
    // Manual verification: Empty array has 0 unique elements
    vector<int> arr3 = {};
    cout << "\nTest 3 - Input: []" << endl;
    int result3 = problem1Solution(arr3);
    cout << "Expected: 0, Got: " << result3 << endl;
    cout << "Result: " << (result3 == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 4: All unique elements
    // Manual verification: [1, 2, 3, 4, 5] has 5 unique elements
    vector<int> arr4 = {1, 2, 3, 4, 5};
    cout << "\nTest 4 - Input: [1, 2, 3, 4, 5]" << endl;
    int result4 = problem1Solution(arr4);
    cout << "Expected: 5, Got: " << result4 << endl;
    cout << "Result: " << (result4 == 5 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Single element
    // Manual verification: [42] has 1 unique element
    vector<int> arr5 = {42};
    cout << "\nTest 5 - Input: [42]" << endl;
    int result5 = problem1Solution(arr5);
    cout << "Expected: 1, Got: " << result5 << endl;
    cout << "Result: " << (result5 == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Negative numbers
    // Manual verification: [-1, -2, -1, 0, -2] has unique {-2, -1, 0} = 3 elements
    vector<int> arr6 = {-1, -2, -1, 0, -2};
    cout << "\nTest 6 - Input: [-1, -2, -1, 0, -2]" << endl;
    int result6 = problem1Solution(arr6);
    cout << "Expected: 3, Got: " << result6 << endl;
    cout << "Result: " << (result6 == 3 ? "PASS" : "FAIL") << endl;
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Check Element Existence ===" << endl;

    // Test Case 1: Element exists in middle
    // Manual verification: 5 is in {1, 3, 5, 7, 9}
    set<int> s1 = {1, 3, 5, 7, 9};
    cout << "Test 1 - Input: set = {1, 3, 5, 7, 9}, target = 5" << endl;
    bool result1 = problem2Solution(s1, 5);
    cout << "Expected: true (1), Got: " << result1 << endl;
    cout << "Result: " << (result1 == true ? "PASS" : "FAIL") << endl;

    // Test Case 2: Element does not exist
    // Manual verification: 5 is not in {2, 4, 6, 8}
    set<int> s2 = {2, 4, 6, 8};
    cout << "\nTest 2 - Input: set = {2, 4, 6, 8}, target = 5" << endl;
    bool result2 = problem2Solution(s2, 5);
    cout << "Expected: false (0), Got: " << result2 << endl;
    cout << "Result: " << (result2 == false ? "PASS" : "FAIL") << endl;

    // Test Case 3: Empty set
    // Manual verification: Empty set cannot contain any element
    set<int> s3 = {};
    cout << "\nTest 3 - Input: set = {}, target = 1" << endl;
    bool result3 = problem2Solution(s3, 1);
    cout << "Expected: false (0), Got: " << result3 << endl;
    cout << "Result: " << (result3 == false ? "PASS" : "FAIL") << endl;

    // Test Case 4: Single element - exists
    // Manual verification: 42 is in {42}
    set<int> s4 = {42};
    cout << "\nTest 4 - Input: set = {42}, target = 42" << endl;
    bool result4 = problem2Solution(s4, 42);
    cout << "Expected: true (1), Got: " << result4 << endl;
    cout << "Result: " << (result4 == true ? "PASS" : "FAIL") << endl;

    // Test Case 5: First element
    // Manual verification: 1 is the first element in {1, 2, 3, 4, 5}
    set<int> s5 = {1, 2, 3, 4, 5};
    cout << "\nTest 5 - Input: set = {1, 2, 3, 4, 5}, target = 1" << endl;
    bool result5 = problem2Solution(s5, 1);
    cout << "Expected: true (1), Got: " << result5 << endl;
    cout << "Result: " << (result5 == true ? "PASS" : "FAIL") << endl;

    // Test Case 6: Last element
    // Manual verification: 100 is the last element in {10, 20, 50, 100}
    set<int> s6 = {10, 20, 50, 100};
    cout << "\nTest 6 - Input: set = {10, 20, 50, 100}, target = 100" << endl;
    bool result6 = problem2Solution(s6, 100);
    cout << "Expected: true (1), Got: " << result6 << endl;
    cout << "Result: " << (result6 == true ? "PASS" : "FAIL") << endl;

    // Test Case 7: Negative number
    // Manual verification: -5 is in {-10, -5, 0, 5}
    set<int> s7 = {-10, -5, 0, 5};
    cout << "\nTest 7 - Input: set = {-10, -5, 0, 5}, target = -5" << endl;
    bool result7 = problem2Solution(s7, -5);
    cout << "Expected: true (1), Got: " << result7 << endl;
    cout << "Result: " << (result7 == true ? "PASS" : "FAIL") << endl;
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Find Minimum and Maximum ===" << endl;

    // Test Case 1: Normal case
    // Manual verification: {1, 3, 4, 5, 9} has min=1, max=9
    set<int> s1 = {3, 1, 4, 1, 5, 9};
    cout << "Test 1 - Input: {3, 1, 4, 1, 5, 9}" << endl;
    pair<int, int> result1 = problem3Solution(s1);
    cout << "Expected: (1, 9), Got: (" << result1.first << ", " << result1.second << ")" << endl;
    cout << "Result: " << (result1.first == 1 && result1.second == 9 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Negative and positive
    // Manual verification: {-5, -2, 0, 3} has min=-5, max=3
    set<int> s2 = {-5, -2, 0, 3};
    cout << "\nTest 2 - Input: {-5, -2, 0, 3}" << endl;
    pair<int, int> result2 = problem3Solution(s2);
    cout << "Expected: (-5, 3), Got: (" << result2.first << ", " << result2.second << ")" << endl;
    cout << "Result: " << (result2.first == -5 && result2.second == 3 ? "PASS" : "FAIL") << endl;

    // Test Case 3: Single element
    // Manual verification: {42} has min=42, max=42
    set<int> s3 = {42};
    cout << "\nTest 3 - Input: {42}" << endl;
    pair<int, int> result3 = problem3Solution(s3);
    cout << "Expected: (42, 42), Got: (" << result3.first << ", " << result3.second << ")" << endl;
    cout << "Result: " << (result3.first == 42 && result3.second == 42 ? "PASS" : "FAIL") << endl;

    // Test Case 4: All negative
    // Manual verification: {-10, -5, -3, -1} has min=-10, max=-1
    set<int> s4 = {-10, -5, -3, -1};
    cout << "\nTest 4 - Input: {-10, -5, -3, -1}" << endl;
    pair<int, int> result4 = problem3Solution(s4);
    cout << "Expected: (-10, -1), Got: (" << result4.first << ", " << result4.second << ")" << endl;
    cout << "Result: " << (result4.first == -10 && result4.second == -1 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Two elements
    // Manual verification: {5, 10} has min=5, max=10
    set<int> s5 = {10, 5};
    cout << "\nTest 5 - Input: {10, 5}" << endl;
    pair<int, int> result5 = problem3Solution(s5);
    cout << "Expected: (5, 10), Got: (" << result5.first << ", " << result5.second << ")" << endl;
    cout << "Result: " << (result5.first == 5 && result5.second == 10 ? "PASS" : "FAIL") << endl;
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Union of Two Sets ===" << endl;

    // Test Case 1: Normal case with overlap
    // Manual verification: {1, 2, 3} ∪ {3, 4, 5} = {1, 2, 3, 4, 5}
    set<int> s1a = {1, 2, 3};
    set<int> s1b = {3, 4, 5};
    set<int> expected1 = {1, 2, 3, 4, 5};
    cout << "Test 1 - Input: set1 = {1, 2, 3}, set2 = {3, 4, 5}" << endl;
    set<int> result1 = problem4Solution(s1a, s1b);
    cout << "Expected: {1, 2, 3, 4, 5}, Got: ";
    printSet(result1);
    cout << endl;
    cout << "Result: " << (setsEqual(result1, expected1) ? "PASS" : "FAIL") << endl;

    // Test Case 2: One empty set
    // Manual verification: {1, 2} ∪ {} = {1, 2}
    set<int> s2a = {1, 2};
    set<int> s2b = {};
    set<int> expected2 = {1, 2};
    cout << "\nTest 2 - Input: set1 = {1, 2}, set2 = {}" << endl;
    set<int> result2 = problem4Solution(s2a, s2b);
    cout << "Expected: {1, 2}, Got: ";
    printSet(result2);
    cout << endl;
    cout << "Result: " << (setsEqual(result2, expected2) ? "PASS" : "FAIL") << endl;

    // Test Case 3: Both empty
    // Manual verification: {} ∪ {} = {}
    set<int> s3a = {};
    set<int> s3b = {};
    set<int> expected3 = {};
    cout << "\nTest 3 - Input: set1 = {}, set2 = {}" << endl;
    set<int> result3 = problem4Solution(s3a, s3b);
    cout << "Expected: {}, Got: ";
    printSet(result3);
    cout << endl;
    cout << "Result: " << (setsEqual(result3, expected3) ? "PASS" : "FAIL") << endl;

    // Test Case 4: No overlap
    // Manual verification: {1, 2} ∪ {3, 4} = {1, 2, 3, 4}
    set<int> s4a = {1, 2};
    set<int> s4b = {3, 4};
    set<int> expected4 = {1, 2, 3, 4};
    cout << "\nTest 4 - Input: set1 = {1, 2}, set2 = {3, 4}" << endl;
    set<int> result4 = problem4Solution(s4a, s4b);
    cout << "Expected: {1, 2, 3, 4}, Got: ";
    printSet(result4);
    cout << endl;
    cout << "Result: " << (setsEqual(result4, expected4) ? "PASS" : "FAIL") << endl;

    // Test Case 5: Identical sets
    // Manual verification: {1, 2, 3} ∪ {1, 2, 3} = {1, 2, 3}
    set<int> s5a = {1, 2, 3};
    set<int> s5b = {1, 2, 3};
    set<int> expected5 = {1, 2, 3};
    cout << "\nTest 5 - Input: set1 = {1, 2, 3}, set2 = {1, 2, 3}" << endl;
    set<int> result5 = problem4Solution(s5a, s5b);
    cout << "Expected: {1, 2, 3}, Got: ";
    printSet(result5);
    cout << endl;
    cout << "Result: " << (setsEqual(result5, expected5) ? "PASS" : "FAIL") << endl;

    // Test Case 6: Negative numbers
    // Manual verification: {-3, -1, 0} ∪ {-2, 0, 2} = {-3, -2, -1, 0, 2}
    set<int> s6a = {-3, -1, 0};
    set<int> s6b = {-2, 0, 2};
    set<int> expected6 = {-3, -2, -1, 0, 2};
    cout << "\nTest 6 - Input: set1 = {-3, -1, 0}, set2 = {-2, 0, 2}" << endl;
    set<int> result6 = problem4Solution(s6a, s6b);
    cout << "Expected: {-3, -2, -1, 0, 2}, Got: ";
    printSet(result6);
    cout << endl;
    cout << "Result: " << (setsEqual(result6, expected6) ? "PASS" : "FAIL") << endl;
}

void testProblem5()
{
    cout << "\n=== Testing Problem 5: Intersection of Two Sets ===" << endl;

    // Test Case 1: Normal case with overlap
    // Manual verification: {1, 2, 3, 4} ∩ {3, 4, 5, 6} = {3, 4}
    set<int> s1a = {1, 2, 3, 4};
    set<int> s1b = {3, 4, 5, 6};
    set<int> expected1 = {3, 4};
    cout << "Test 1 - Input: set1 = {1, 2, 3, 4}, set2 = {3, 4, 5, 6}" << endl;
    set<int> result1 = problem5Solution(s1a, s1b);
    cout << "Expected: {3, 4}, Got: ";
    printSet(result1);
    cout << endl;
    cout << "Result: " << (setsEqual(result1, expected1) ? "PASS" : "FAIL") << endl;

    // Test Case 2: No overlap
    // Manual verification: {1, 2, 3} ∩ {4, 5, 6} = {}
    set<int> s2a = {1, 2, 3};
    set<int> s2b = {4, 5, 6};
    set<int> expected2 = {};
    cout << "\nTest 2 - Input: set1 = {1, 2, 3}, set2 = {4, 5, 6}" << endl;
    set<int> result2 = problem5Solution(s2a, s2b);
    cout << "Expected: {}, Got: ";
    printSet(result2);
    cout << endl;
    cout << "Result: " << (setsEqual(result2, expected2) ? "PASS" : "FAIL") << endl;

    // Test Case 3: Identical sets
    // Manual verification: {1, 2, 3} ∩ {1, 2, 3} = {1, 2, 3}
    set<int> s3a = {1, 2, 3};
    set<int> s3b = {1, 2, 3};
    set<int> expected3 = {1, 2, 3};
    cout << "\nTest 3 - Input: set1 = {1, 2, 3}, set2 = {1, 2, 3}" << endl;
    set<int> result3 = problem5Solution(s3a, s3b);
    cout << "Expected: {1, 2, 3}, Got: ";
    printSet(result3);
    cout << endl;
    cout << "Result: " << (setsEqual(result3, expected3) ? "PASS" : "FAIL") << endl;

    // Test Case 4: One empty set
    // Manual verification: {1, 2, 3} ∩ {} = {}
    set<int> s4a = {1, 2, 3};
    set<int> s4b = {};
    set<int> expected4 = {};
    cout << "\nTest 4 - Input: set1 = {1, 2, 3}, set2 = {}" << endl;
    set<int> result4 = problem5Solution(s4a, s4b);
    cout << "Expected: {}, Got: ";
    printSet(result4);
    cout << endl;
    cout << "Result: " << (setsEqual(result4, expected4) ? "PASS" : "FAIL") << endl;

    // Test Case 5: Single element overlap
    // Manual verification: {1, 2, 5} ∩ {5, 6, 7} = {5}
    set<int> s5a = {1, 2, 5};
    set<int> s5b = {5, 6, 7};
    set<int> expected5 = {5};
    cout << "\nTest 5 - Input: set1 = {1, 2, 5}, set2 = {5, 6, 7}" << endl;
    set<int> result5 = problem5Solution(s5a, s5b);
    cout << "Expected: {5}, Got: ";
    printSet(result5);
    cout << endl;
    cout << "Result: " << (setsEqual(result5, expected5) ? "PASS" : "FAIL") << endl;

    // Test Case 6: Negative numbers
    // Manual verification: {-5, -2, 0, 3} ∩ {-2, 0, 5} = {-2, 0}
    set<int> s6a = {-5, -2, 0, 3};
    set<int> s6b = {-2, 0, 5};
    set<int> expected6 = {-2, 0};
    cout << "\nTest 6 - Input: set1 = {-5, -2, 0, 3}, set2 = {-2, 0, 5}" << endl;
    set<int> result6 = problem5Solution(s6a, s6b);
    cout << "Expected: {-2, 0}, Got: ";
    printSet(result6);
    cout << endl;
    cout << "Result: " << (setsEqual(result6, expected6) ? "PASS" : "FAIL") << endl;
}

void testProblem6()
{
    cout << "\n=== Testing Problem 6: Symmetric Difference ===" << endl;

    // Test Case 1: Normal case
    // Manual verification: {1, 2, 3} ⊕ {2, 3, 4} = {1, 4}
    set<int> s1a = {1, 2, 3};
    set<int> s1b = {2, 3, 4};
    set<int> expected1 = {1, 4};
    cout << "Test 1 - Input: set1 = {1, 2, 3}, set2 = {2, 3, 4}" << endl;
    set<int> result1 = problem6Solution(s1a, s1b);
    cout << "Expected: {1, 4}, Got: ";
    printSet(result1);
    cout << endl;
    cout << "Result: " << (setsEqual(result1, expected1) ? "PASS" : "FAIL") << endl;

    // Test Case 2: No overlap
    // Manual verification: {1, 2} ⊕ {3, 4} = {1, 2, 3, 4}
    set<int> s2a = {1, 2};
    set<int> s2b = {3, 4};
    set<int> expected2 = {1, 2, 3, 4};
    cout << "\nTest 2 - Input: set1 = {1, 2}, set2 = {3, 4}" << endl;
    set<int> result2 = problem6Solution(s2a, s2b);
    cout << "Expected: {1, 2, 3, 4}, Got: ";
    printSet(result2);
    cout << endl;
    cout << "Result: " << (setsEqual(result2, expected2) ? "PASS" : "FAIL") << endl;

    // Test Case 3: Identical sets
    // Manual verification: {1, 2, 3} ⊕ {1, 2, 3} = {}
    set<int> s3a = {1, 2, 3};
    set<int> s3b = {1, 2, 3};
    set<int> expected3 = {};
    cout << "\nTest 3 - Input: set1 = {1, 2, 3}, set2 = {1, 2, 3}" << endl;
    set<int> result3 = problem6Solution(s3a, s3b);
    cout << "Expected: {}, Got: ";
    printSet(result3);
    cout << endl;
    cout << "Result: " << (setsEqual(result3, expected3) ? "PASS" : "FAIL") << endl;

    // Test Case 4: One empty set
    // Manual verification: {1, 2, 3} ⊕ {} = {1, 2, 3}
    set<int> s4a = {1, 2, 3};
    set<int> s4b = {};
    set<int> expected4 = {1, 2, 3};
    cout << "\nTest 4 - Input: set1 = {1, 2, 3}, set2 = {}" << endl;
    set<int> result4 = problem6Solution(s4a, s4b);
    cout << "Expected: {1, 2, 3}, Got: ";
    printSet(result4);
    cout << endl;
    cout << "Result: " << (setsEqual(result4, expected4) ? "PASS" : "FAIL") << endl;

    // Test Case 5: Subset relationship
    // Manual verification: {1, 2, 3, 4} ⊕ {2, 3} = {1, 4}
    set<int> s5a = {1, 2, 3, 4};
    set<int> s5b = {2, 3};
    set<int> expected5 = {1, 4};
    cout << "\nTest 5 - Input: set1 = {1, 2, 3, 4}, set2 = {2, 3}" << endl;
    set<int> result5 = problem6Solution(s5a, s5b);
    cout << "Expected: {1, 4}, Got: ";
    printSet(result5);
    cout << endl;
    cout << "Result: " << (setsEqual(result5, expected5) ? "PASS" : "FAIL") << endl;

    // Test Case 6: Mixed positive and negative
    // Manual verification: {-2, -1, 0, 1} ⊕ {-1, 0, 2, 3} = {-2, 1, 2, 3}
    set<int> s6a = {-2, -1, 0, 1};
    set<int> s6b = {-1, 0, 2, 3};
    set<int> expected6 = {-2, 1, 2, 3};
    cout << "\nTest 6 - Input: set1 = {-2, -1, 0, 1}, set2 = {-1, 0, 2, 3}" << endl;
    set<int> result6 = problem6Solution(s6a, s6b);
    cout << "Expected: {-2, 1, 2, 3}, Got: ";
    printSet(result6);
    cout << endl;
    cout << "Result: " << (setsEqual(result6, expected6) ? "PASS" : "FAIL") << endl;
}

void testProblem7()
{
    cout << "\n=== Testing Problem 7: Longest Consecutive Sequence ===" << endl;

    // Test Case 1: Normal case
    // Manual verification: [100, 4, 200, 1, 3, 2] contains sequence [1, 2, 3, 4] = length 4
    vector<int> arr1 = {100, 4, 200, 1, 3, 2};
    cout << "Test 1 - Input: [100, 4, 200, 1, 3, 2]" << endl;
    int result1 = problem7Solution(arr1);
    cout << "Expected: 4, Got: " << result1 << endl;
    cout << "Result: " << (result1 == 4 ? "PASS" : "FAIL") << endl;

    // Test Case 2: Long consecutive sequence
    // Manual verification: [0, 3, 7, 2, 5, 8, 4, 6, 0, 1] contains [0, 1, 2, 3, 4, 5, 6, 7, 8] = length 9
    vector<int> arr2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "\nTest 2 - Input: [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]" << endl;
    int result2 = problem7Solution(arr2);
    cout << "Expected: 9, Got: " << result2 << endl;
    cout << "Result: " << (result2 == 9 ? "PASS" : "FAIL") << endl;

    // Test Case 3: All consecutive
    // Manual verification: [9, 1, 4, 7, 3, 2, 8, 5, 6] contains [1-9] = length 9
    vector<int> arr3 = {9, 1, 4, 7, 3, 2, 8, 5, 6};
    cout << "\nTest 3 - Input: [9, 1, 4, 7, 3, 2, 8, 5, 6]" << endl;
    int result3 = problem7Solution(arr3);
    cout << "Expected: 9, Got: " << result3 << endl;
    cout << "Result: " << (result3 == 9 ? "PASS" : "FAIL") << endl;

    // Test Case 4: No consecutive sequence (all singles)
    // Manual verification: [1, 3, 5, 7, 9] has no consecutive pairs, longest = 1
    vector<int> arr4 = {1, 3, 5, 7, 9};
    cout << "\nTest 4 - Input: [1, 3, 5, 7, 9]" << endl;
    int result4 = problem7Solution(arr4);
    cout << "Expected: 1, Got: " << result4 << endl;
    cout << "Result: " << (result4 == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Empty array
    // Manual verification: Empty array has no sequence = 0
    vector<int> arr5 = {};
    cout << "\nTest 5 - Input: []" << endl;
    int result5 = problem7Solution(arr5);
    cout << "Expected: 0, Got: " << result5 << endl;
    cout << "Result: " << (result5 == 0 ? "PASS" : "FAIL") << endl;

    // Test Case 6: Single element
    // Manual verification: [42] has sequence of length 1
    vector<int> arr6 = {42};
    cout << "\nTest 6 - Input: [42]" << endl;
    int result6 = problem7Solution(arr6);
    cout << "Expected: 1, Got: " << result6 << endl;
    cout << "Result: " << (result6 == 1 ? "PASS" : "FAIL") << endl;

    // Test Case 7: Negative numbers
    // Manual verification: [-2, -1, 0, 1, 2, 10] contains [-2, -1, 0, 1, 2] = length 5
    vector<int> arr7 = {-2, -1, 0, 1, 2, 10};
    cout << "\nTest 7 - Input: [-2, -1, 0, 1, 2, 10]" << endl;
    int result7 = problem7Solution(arr7);
    cout << "Expected: 5, Got: " << result7 << endl;
    cout << "Result: " << (result7 == 5 ? "PASS" : "FAIL") << endl;
}

void testProblem8()
{
    cout << "\n=== Testing Problem 8: Find All Missing Numbers in Range ===" << endl;

    // Test Case 1: Normal case
    // Manual verification: arr=[4, 3, 2, 7, 8], n=5, k=3, range=[1, 8], missing={1, 5, 6}
    vector<int> arr1 = {4, 3, 2, 7, 8};
    set<int> expected1 = {1, 5, 6};
    cout << "Test 1 - Input: arr = [4, 3, 2, 7, 8], k = 3" << endl;
    set<int> result1 = problem8Solution(arr1, 3);
    cout << "Expected: {1, 5, 6}, Got: ";
    printSet(result1);
    cout << endl;
    cout << "Result: " << (setsEqual(result1, expected1) ? "PASS" : "FAIL") << endl;

    // Test Case 2: Duplicates in array
    // Manual verification: arr=[1, 1], n=2, k=2, range=[1, 4], missing={2, 3, 4}
    vector<int> arr2 = {1, 1};
    set<int> expected2 = {2, 3, 4};
    cout << "\nTest 2 - Input: arr = [1, 1], k = 2" << endl;
    set<int> result2 = problem8Solution(arr2, 2);
    cout << "Expected: {2, 3, 4}, Got: ";
    printSet(result2);
    cout << endl;
    cout << "Result: " << (setsEqual(result2, expected2) ? "PASS" : "FAIL") << endl;

    // Test Case 3: Missing only first element
    // Manual verification: arr=[2, 3, 4], n=3, k=1, range=[1, 4], missing={1}
    vector<int> arr3 = {2, 3, 4};
    set<int> expected3 = {1};
    cout << "\nTest 3 - Input: arr = [2, 3, 4], k = 1" << endl;
    set<int> result3 = problem8Solution(arr3, 1);
    cout << "Expected: {1}, Got: ";
    printSet(result3);
    cout << endl;
    cout << "Result: " << (setsEqual(result3, expected3) ? "PASS" : "FAIL") << endl;

    // Test Case 4: No missing numbers
    // Manual verification: arr=[1, 2, 3], n=3, k=0, range=[1, 3], missing={}
    vector<int> arr4 = {1, 2, 3};
    set<int> expected4 = {};
    cout << "\nTest 4 - Input: arr = [1, 2, 3], k = 0" << endl;
    set<int> result4 = problem8Solution(arr4, 0);
    cout << "Expected: {}, Got: ";
    printSet(result4);
    cout << endl;
    cout << "Result: " << (setsEqual(result4, expected4) ? "PASS" : "FAIL") << endl;

    // Test Case 5: Single element, multiple missing
    // Manual verification: arr=[3], n=1, k=3, range=[1, 4], missing={1, 2, 4}
    vector<int> arr5 = {3};
    set<int> expected5 = {1, 2, 4};
    cout << "\nTest 5 - Input: arr = [3], k = 3" << endl;
    set<int> result5 = problem8Solution(arr5, 3);
    cout << "Expected: {1, 2, 4}, Got: ";
    printSet(result5);
    cout << endl;
    cout << "Result: " << (setsEqual(result5, expected5) ? "PASS" : "FAIL") << endl;

    // Test Case 6: Large k value
    // Manual verification: arr=[1, 3, 5], n=3, k=4, range=[1, 7], missing={2, 4, 6, 7}
    vector<int> arr6 = {1, 3, 5};
    set<int> expected6 = {2, 4, 6, 7};
    cout << "\nTest 6 - Input: arr = [1, 3, 5], k = 4" << endl;
    set<int> result6 = problem8Solution(arr6, 4);
    cout << "Expected: {2, 4, 6, 7}, Got: ";
    printSet(result6);
    cout << endl;
    cout << "Result: " << (setsEqual(result6, expected6) ? "PASS" : "FAIL") << endl;

    // Test Case 7: k = 0 (range equals array size)
    // Manual verification: arr=[2, 4], n=2, k=0, range=[1, 2], missing={1}
    vector<int> arr7 = {2, 4};
    set<int> expected7 = {1};
    cout << "\nTest 7 - Input: arr = [2, 4], k = 0" << endl;
    set<int> result7 = problem8Solution(arr7, 0);
    cout << "Expected: {1}, Got: ";
    printSet(result7);
    cout << endl;
    cout << "Result: " << (setsEqual(result7, expected7) ? "PASS" : "FAIL") << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "=== SETS PRACTICE PROBLEMS ===" << endl;
    cout << "Choose a problem to test (1-8) or 9 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Count Unique Elements" << endl;
    cout << "2. Problem 2 (Easy) - Check Element Existence" << endl;
    cout << "3. Problem 3 (Easy) - Find Minimum and Maximum" << endl;
    cout << "4. Problem 4 (Medium) - Union of Two Sets" << endl;
    cout << "5. Problem 5 (Medium) - Intersection of Two Sets" << endl;
    cout << "6. Problem 6 (Medium) - Symmetric Difference" << endl;
    cout << "7. Problem 7 (Hard) - Longest Consecutive Sequence" << endl;
    cout << "8. Problem 8 (Hard) - Find All Missing Numbers in Range" << endl;
    cout << "9. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        testProblem1();
        break;
    case 2:
        testProblem2();
        break;
    case 3:
        testProblem3();
        break;
    case 4:
        testProblem4();
        break;
    case 5:
        testProblem5();
        break;
    case 6:
        testProblem6();
        break;
    case 7:
        testProblem7();
        break;
    case 8:
        testProblem8();
        break;
    case 9:
        testProblem1();
        testProblem2();
        testProblem3();
        testProblem4();
        testProblem5();
        testProblem6();
        testProblem7();
        testProblem8();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}