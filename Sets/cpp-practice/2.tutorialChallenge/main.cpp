#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>  // For set operations like set_union, set_intersection, etc.
#include <iterator>   // For std::inserter, std::advance
#include <utility>    // For std::pair

using namespace std;


// ============================================================================
// CONCEPT 1: BASIC SET OPERATIONS
// ============================================================================

// Problem 1.1 (Easy): Find Missing Number
// Given a set of integers and a range [min, max], find all numbers in that range that are NOT in the set.
// Example: Set {1, 2, 4, 5}, range [1, 6] → Result: {3, 6}
// Example: Set {10, 20, 30}, range [15, 25] → Result: {15, 16, 17, 18, 19, 21, 22, 23, 24, 25}
// Constraints: Set size ≤ 1000, range size ≤ 1000
set<int> problem1_1(const set<int>& numbers, int min_val, int max_val)
{
    // TODO: Implement function to find missing numbers in range
    // Hint: Iterate through the range and check which numbers are not in the set
    return set<int>();
}

// Problem 1.2 (Easy): Remove Even Numbers
// Given a set of integers, remove all even numbers and return the modified set.
// Example: {1, 2, 3, 4, 5, 6} → Result: {1, 3, 5}
// Example: {10, 15, 20, 25} → Result: {15, 25}
// Constraints: Set size ≤ 1000, numbers between -1000 and 1000
set<int> problem1_2(const set<int>& numbers)
{
    // TODO: Implement function to remove even numbers
    // Hint: Use erase() or create a new set with only odd numbers
    return set<int>();
}

// Problem 1.3 (Medium): Validate Set Operations
// Given three sets A, B, C and an operation result, verify if the result matches A ∪ B ∩ C
// Example: A = {1,2,3}, B = {2,3,4}, C = {3,4,5}, result = {3} → Return: true
// Example: A = {1,2}, B = {2,3}, C = {3,4}, result = {2,3} → Return: false
// Constraints: All sets size ≤ 100, numbers between 1-1000
bool problem1_3(const set<int>& A, const set<int>& B, const set<int>& C, const set<int>& result)
{
    // TODO: Verify if result equals (A ∪ B) ∩ C
    // Hint: First compute union of A and B, then intersection with C
    return false;
}

// ============================================================================
// CONCEPT 2: SET ITERATORS AND TRAVERSAL
// ============================================================================

// Problem 2.1 (Easy): Find Nth Element
// Given a set of strings and an integer N, return the Nth element (0-indexed) using iterators.
// If N is out of bounds, return empty string.
// Example: Set {"apple", "banana", "cherry"}, N=1 → Result: "banana"
// Example: Set {"x", "y", "z"}, N=5 → Result: ""
// Constraints: Set size ≤ 1000, N ≥ 0
string problem2_1(const set<string>& words, int n)
{
    // TODO: Find the nth element using iterators
    // Hint: Use begin() and advance the iterator n times
    return "";
}

// Problem 2.2 (Easy): Reverse First N Elements
// Given a set of integers and number N, return a vector containing first N elements in reverse order.
// Example: Set {1,2,3,4,5}, N=3 → Result: {3,2,1}
// Example: Set {10,20,30}, N=5 → Result: {30,20,10}
// Constraints: Set size ≤ 1000, N ≥ 0
vector<int> problem2_2(const set<int>& numbers, int n)
{
    // TODO: Get first N elements in reverse order
    // Hint: Use iterators to traverse forward, then reverse the collected elements
    return vector<int>();
}

// Problem 2.3 (Medium): Find Closest Value
// Given a sorted set of integers and a target value, find the closest value in the set.
// If two values are equally close, return the smaller one.
// Example: Set {1,4,7,9}, target=5 → Result: 4
// Example: Set {10,20,30}, target=25 → Result: 20
// Example: Set {5,10,15}, target=12 → Result: 10
// Constraints: Set size ≤ 1000, numbers between -10000 and 10000
int problem2_3(const set<int>& numbers, int target)
{
    // TODO: Find the closest value to target
    // Hint: Use lower_bound/upper_bound and compare neighbors
    return 0;
}

// ============================================================================
// CONCEPT 3: SET ALGORITHMS AND OPERATIONS
// ============================================================================

// Problem 3.1 (Easy): Symmetric Difference of Multiple Sets
// Given two sets A and B, compute their symmetric difference (elements in A or B but not both).
// Example: A = {1,2,3}, B = {2,3,4} → Result: {1,4}
// Example: A = {5,10}, B = {10,15} → Result: {5,15}
// Constraints: Set sizes ≤ 1000
set<int> problem3_1(const set<int>& A, const set<int>& B)
{
    // TODO: Compute symmetric difference without using set_symmetric_difference
    // Hint: Use set_difference twice and combine results
    return set<int>();
}

// Problem 3.2 (Easy): Check Disjoint Sets
// Given two sets, check if they are disjoint (have no common elements).
// Example: A = {1,2,3}, B = {4,5,6} → Result: true
// Example: A = {1,2}, B = {2,3} → Result: false
// Constraints: Set sizes ≤ 1000
bool problem3_2(const set<int>& A, const set<int>& B)
{
    // TODO: Check if sets are disjoint
    // Hint: Check if intersection is empty
    return false;
}

// Problem 3.3 (Medium): Set Partition Validation
// Given a universal set U and two sets A and B, verify if A and B form a valid partition of U.
// Valid partition means: A ∪ B = U, A ∩ B = ∅, and neither A nor B is empty.
// Example: U = {1,2,3,4}, A = {1,2}, B = {3,4} → Result: true
// Example: U = {1,2,3}, A = {1,2}, B = {2,3} → Result: false
// Constraints: All sets size ≤ 1000
bool problem3_3(const set<int>& U, const set<int>& A, const set<int>& B)
{
    // TODO: Verify if A and B form valid partition of U
    // Hint: Check union equals U, intersection is empty, and both sets non-empty
    return false;
}

// ============================================================================
// CONCEPT 4: CUSTOM COMPARATORS AND ADVANCED FEATURES
// ============================================================================

struct Product {
    string name;
    double price;
    int quantity;
    
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}
    
    // Default ordering by name
    bool operator<(const Product& other) const {
        return name < other.name;
    }
};

// Problem 4.1 (Easy): Find Products Below Price
// Given a set of Products (sorted by name) and a max price, return all products with price <= max_price.
// Maintain the original ordering.
// Example: Products: [{"apple",1.5,10}, {"banana",0.5,20}, {"cherry",2.0,5}], max_price=1.0 → Result: {"banana"}
// Constraints: Set size ≤ 1000
set<Product> problem4_1(const set<Product>& products, double max_price)
{
    // TODO: Find products with price <= max_price
    // Hint: Iterate and filter based on price condition
    return set<Product>();
}

// Problem 4.2 (Easy): Sort Products by Quantity
// Given a set of Products, return a new set sorted by quantity in descending order.
// If quantities are equal, sort by name ascending.
// Example: [{"A",10,5}, {"B",20,10}, {"C",15,5}] → Result: [{"B",20,10}, {"A",10,5}, {"C",15,5}]
// Constraints: Set size ≤ 1000
set<Product> problem4_2(const set<Product>& products)
{
    // TODO: Create set with custom comparator for quantity descending
    // Hint: Define a custom comparator struct
    return set<Product>();
}

// Problem 4.3 (Medium): Price Range Search
// Given a set of Products sorted by price, find all products within a price range [min_price, max_price].
// Return them sorted by price.
// Example: Products sorted by price: [{"A",1.0,10}, {"B",2.5,5}, {"C",3.0,8}, {"D",4.0,2}]
//          Range [2.0, 3.5] → Result: [{"B",2.5,5}, {"C",3.0,8}]
// Constraints: Set size ≤ 1000
set<Product> problem4_3(const set<Product>& products, double min_price, double max_price)
{
    // TODO: Find products in price range using lower_bound/upper_bound
    // Hint: Create temporary Product for searching and use bounds
    return set<Product>();
}

// ============================================================================
// CONCEPT 5: SET VS UNORDERED_SET COMPARISON
// ============================================================================

// Problem 5.1 (Easy): Convert Set to Vector
// Given a set of integers, convert it to a vector while maintaining order.
// Example: {3,1,2} → Result: {1,2,3}
// Example: {5,2,8,1} → Result: {1,2,5,8}
// Constraints: Set size ≤ 1000
vector<int> problem5_1(const set<int>& numbers)
{
    // TODO: Convert set to vector (automatically sorted)
    // Hint: Use vector constructor with iterators
    return vector<int>();
}

// Problem 5.2 (Easy): Find Common Elements in Multiple Sets
// Given a vector of sets, find all elements that appear in every set.
// Example: [{1,2,3}, {2,3,4}, {3,4,5}] → Result: {3}
// Example: [{1,2}, {2,3}, {2,4}] → Result: {2}
// Constraints: Number of sets ≤ 10, each set size ≤ 1000
set<int> problem5_2(const vector<set<int>>& sets)
{
    // TODO: Find intersection of all sets
    // Hint: Start with first set, then repeatedly intersect with others
    return set<int>();
}

// Problem 5.3 (Medium): Optimized Lookup System
// Given a large set of words (dictionary) and a list of words to check,
// return a set containing only the words that exist in the dictionary.
// Optimize for fast lookups.
// Example: Dictionary = {"apple","banana","cherry"}, words = {"apple","date","banana"} → Result: {"apple","banana"}
// Constraints: Dictionary size ≤ 10000, words to check ≤ 1000
set<string> problem5_3(const set<string>& dictionary, const vector<string>& words)
{
    // TODO: Efficiently find which words exist in dictionary
    // Hint: Consider using unordered_set for faster lookups
    return set<string>();
}

// ============================================================================
// CONCEPT 6: REAL-WORLD APPLICATIONS
// ============================================================================

// Problem 6.1 (Easy): Remove Duplicates from Vector
// Given a vector of integers with possible duplicates, return a set containing unique values.
// Example: {1,2,2,3,3,3,4} → Result: {1,2,3,4}
// Example: {5,5,5,5} → Result: {5}
// Constraints: Vector size ≤ 10000
set<int> problem6_1(const vector<int>& numbers)
{
    // TODO: Remove duplicates using set properties
    // Hint: Set constructor automatically removes duplicates
    return set<int>();
}

// Problem 6.2 (Easy): Tag Union System
// Given multiple sets of tags (strings), compute their union (all unique tags across all sets).
// Example: [{"tech","science"}, {"science","art"}, {"tech","music"}] → Result: {"art","music","science","tech"}
// Constraints: Number of sets ≤ 10, each set size ≤ 100
set<string> problem6_2(const vector<set<string>>& tag_sets)
{
    // TODO: Compute union of all tag sets
    // Hint: Use set_union repeatedly or insert all elements
    return set<string>();
}

// Problem 6.3 (Medium): Recommendation System
// Given user preferences (set of liked tags) and available content with tags,
// recommend content that has at least 2 matching tags with user preferences.
// Return set of content names sorted by number of matching tags (descending).
// Example: User tags = {"tech","programming","games"}
//          Content: [{"article1",{"tech","news"}}, {"tutorial1",{"programming","tech"}}, {"blog1",{"food","travel"}}]
//          Result: {"tutorial1","article1"}
// Constraints: User tags ≤ 20, content items ≤ 1000
vector<string> problem6_3(const set<string>& user_tags, const vector<pair<string, set<string>>>& content)
{
    // TODO: Recommend content with at least 2 matching tags, sorted by match count
    // Hint: Compute intersection size for each content item
    return vector<string>();
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1_1()
{
    cout << "\n=== Testing Problem 1.1: Find Missing Number ===" << endl;

    // Test 1: Basic case with consecutive numbers
    set<int> nums1 = {1, 2, 4, 5};
    set<int> result1 = problem1_1(nums1, 1, 6);
    set<int> expected1 = {3, 6};
    cout << "Test 1 (Basic consecutive): " << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    // Test 2: Empty set
    set<int> nums2 = {};
    set<int> result2 = problem1_1(nums2, 1, 5);
    set<int> expected2 = {1, 2, 3, 4, 5};
    cout << "Test 2 (Empty set): " << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    // Test 3: No missing numbers
    set<int> nums3 = {1, 2, 3, 4, 5};
    set<int> result3 = problem1_1(nums3, 1, 5);
    set<int> expected3 = {};
    cout << "Test 3 (No missing): " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test 4: Range outside set values
    set<int> nums4 = {10, 20, 30};
    set<int> result4 = problem1_1(nums4, 15, 25);
    set<int> expected4 = {15, 16, 17, 18, 19, 21, 22, 23, 24, 25};
    cout << "Test 4 (Range outside): " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test 5: Single element
    set<int> nums5 = {5};
    set<int> result5 = problem1_1(nums5, 1, 10);
    set<int> expected5 = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    cout << "Test 5 (Single element): " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

void testProblem1_2()
{
    cout << "\n=== Testing Problem 1.2: Remove Even Numbers ===" << endl;

    // Test 1: Mixed even and odd numbers
    set<int> nums1 = {1, 2, 3, 4, 5, 6};
    set<int> result1 = problem1_2(nums1);
    set<int> expected1 = {1, 3, 5};
    cout << "Test 1 (Mixed numbers): " << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    // Test 2: All even numbers
    set<int> nums2 = {2, 4, 6, 8};
    set<int> result2 = problem1_2(nums2);
    set<int> expected2 = {};
    cout << "Test 2 (All even): " << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    // Test 3: All odd numbers
    set<int> nums3 = {1, 3, 5, 7};
    set<int> result3 = problem1_2(nums3);
    set<int> expected3 = {1, 3, 5, 7};
    cout << "Test 3 (All odd): " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test 4: Empty set
    set<int> nums4 = {};
    set<int> result4 = problem1_2(nums4);
    set<int> expected4 = {};
    cout << "Test 4 (Empty set): " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test 5: Negative numbers
    set<int> nums5 = {-3, -2, -1, 0, 1, 2};
    set<int> result5 = problem1_2(nums5);
    set<int> expected5 = {-3, -1, 1};
    cout << "Test 5 (Negative numbers): " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

void testProblem1_3()
{
    cout << "\n=== Testing Problem 1.3: Validate Set Operations ===" << endl;

    // Test 1: Correct operation
    set<int> A1 = {1, 2, 3}, B1 = {2, 3, 4}, C1 = {3, 4, 5}, result1 = {3};
    bool test1 = problem1_3(A1, B1, C1, result1);
    cout << "Test 1 (Correct operation): " << (test1 ? "PASS" : "FAIL") << endl;

    // Test 2: Incorrect operation
    set<int> A2 = {1, 2}, B2 = {2, 3}, C2 = {3, 4}, result2 = {2, 3};
    bool test2 = problem1_3(A2, B2, C2, result2);
    cout << "Test 2 (Incorrect operation): " << (!test2 ? "PASS" : "FAIL") << endl;

    // Test 3: Empty intersection
    set<int> A3 = {1, 2}, B3 = {3, 4}, C3 = {5, 6}, result3 = {};
    bool test3 = problem1_3(A3, B3, C3, result3);
    cout << "Test 3 (Empty intersection): " << (test3 ? "PASS" : "FAIL") << endl;

    // Test 4: All sets same
    set<int> A4 = {1, 2, 3}, B4 = {1, 2, 3}, C4 = {1, 2, 3}, result4 = {1, 2, 3};
    bool test4 = problem1_3(A4, B4, C4, result4);
    cout << "Test 4 (All sets same): " << (test4 ? "PASS" : "FAIL") << endl;

    // Test 5: Complex sets
    set<int> A5 = {1, 5, 9}, B5 = {2, 5, 8}, C5 = {3, 5, 7}, result5 = {5};
    bool test5 = problem1_3(A5, B5, C5, result5);
    cout << "Test 5 (Complex sets): " << (test5 ? "PASS" : "FAIL") << endl;
}

void testProblem2_1()
{
    cout << "\n=== Testing Problem 2.1: Find Nth Element ===" << endl;

    // Test 1: Valid index
    set<string> words1 = {"apple", "banana", "cherry"};
    string result1 = problem2_1(words1, 1);
    cout << "Test 1 (Valid index): " << (result1 == "banana" ? "PASS" : "FAIL") << endl;

    // Test 2: First element
    set<string> words2 = {"apple", "banana", "cherry"};
    string result2 = problem2_1(words2, 0);
    cout << "Test 2 (First element): " << (result2 == "apple" ? "PASS" : "FAIL") << endl;

    // Test 3: Last element
    set<string> words3 = {"apple", "banana", "cherry"};
    string result3 = problem2_1(words3, 2);
    cout << "Test 3 (Last element): " << (result3 == "cherry" ? "PASS" : "FAIL") << endl;

    // Test 4: Out of bounds
    set<string> words4 = {"apple", "banana", "cherry"};
    string result4 = problem2_1(words4, 5);
    cout << "Test 4 (Out of bounds): " << (result4 == "" ? "PASS" : "FAIL") << endl;

    // Test 5: Empty set
    set<string> words5 = {};
    string result5 = problem2_1(words5, 0);
    cout << "Test 5 (Empty set): " << (result5 == "" ? "PASS" : "FAIL") << endl;
}

void testProblem2_2()
{
    cout << "\n=== Testing Problem 2.2: Reverse First N Elements ===" << endl;

    // Test 1: Normal case
    set<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> result1 = problem2_2(nums1, 3);
    vector<int> expected1 = {3, 2, 1};
    cout << "Test 1 (Normal case): " << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    // Test 2: N larger than set size
    set<int> nums2 = {1, 2, 3};
    vector<int> result2 = problem2_2(nums2, 5);
    vector<int> expected2 = {3, 2, 1};
    cout << "Test 2 (N larger): " << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    // Test 3: N = 0
    set<int> nums3 = {1, 2, 3};
    vector<int> result3 = problem2_2(nums3, 0);
    vector<int> expected3 = {};
    cout << "Test 3 (N=0): " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test 4: Single element
    set<int> nums4 = {10};
    vector<int> result4 = problem2_2(nums4, 1);
    vector<int> expected4 = {10};
    cout << "Test 4 (Single element): " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test 5: Empty set
    set<int> nums5 = {};
    vector<int> result5 = problem2_2(nums5, 3);
    vector<int> expected5 = {};
    cout << "Test 5 (Empty set): " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

void testProblem2_3()
{
    cout << "\n=== Testing Problem 2.3: Find Closest Value ===" << endl;

    // Test 1: Exact match
    set<int> nums1 = {1, 4, 7, 9};
    int result1 = problem2_3(nums1, 4);
    cout << "Test 1 (Exact match): " << (result1 == 4 ? "PASS" : "FAIL") << endl;

    // Test 2: Closer to lower value
    set<int> nums2 = {1, 4, 7, 9};
    int result2 = problem2_3(nums2, 5);
    cout << "Test 2 (Closer to lower): " << (result2 == 4 ? "PASS" : "FAIL") << endl;

    // Test 3: Equidistant - choose smaller
    set<int> nums3 = {5, 10, 15};
    int result3 = problem2_3(nums3, 12);
    cout << "Test 3 (Equidistant): " << (result3 == 10 ? "PASS" : "FAIL") << endl;

    // Test 4: Below minimum
    set<int> nums4 = {10, 20, 30};
    int result4 = problem2_3(nums4, 5);
    cout << "Test 4 (Below min): " << (result4 == 10 ? "PASS" : "FAIL") << endl;

    // Test 5: Above maximum
    set<int> nums5 = {10, 20, 30};
    int result5 = problem2_3(nums5, 35);
    cout << "Test 5 (Above max): " << (result5 == 30 ? "PASS" : "FAIL") << endl;
}

void testProblem3_1()
{
    cout << "\n=== Testing Problem 3.1: Symmetric Difference ===" << endl;

    // Test 1: Basic symmetric difference
    set<int> A1 = {1, 2, 3}, B1 = {2, 3, 4};
    set<int> result1 = problem3_1(A1, B1);
    set<int> expected1 = {1, 4};
    cout << "Test 1 (Basic): " << (result1 == expected1 ? "PASS" : "FAIL") << endl;

    // Test 2: No common elements
    set<int> A2 = {1, 2}, B2 = {3, 4};
    set<int> result2 = problem3_1(A2, B2);
    set<int> expected2 = {1, 2, 3, 4};
    cout << "Test 2 (No common): " << (result2 == expected2 ? "PASS" : "FAIL") << endl;

    // Test 3: Identical sets
    set<int> A3 = {1, 2, 3}, B3 = {1, 2, 3};
    set<int> result3 = problem3_1(A3, B3);
    set<int> expected3 = {};
    cout << "Test 3 (Identical): " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test 4: Empty first set
    set<int> A4 = {}, B4 = {1, 2, 3};
    set<int> result4 = problem3_1(A4, B4);
    set<int> expected4 = {1, 2, 3};
    cout << "Test 4 (Empty first): " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test 5: Empty second set
    set<int> A5 = {1, 2, 3}, B5 = {};
    set<int> result5 = problem3_1(A5, B5);
    set<int> expected5 = {1, 2, 3};
    cout << "Test 5 (Empty second): " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
}

void testProblem3_2()
{
    cout << "\n=== Testing Problem 3.2: Check Disjoint Sets ===" << endl;

    // Test 1: Disjoint sets
    set<int> A1 = {1, 2, 3}, B1 = {4, 5, 6};
    bool result1 = problem3_2(A1, B1);
    cout << "Test 1 (Disjoint): " << (result1 ? "PASS" : "FAIL") << endl;

    // Test 2: Not disjoint
    set<int> A2 = {1, 2}, B2 = {2, 3};
    bool result2 = problem3_2(A2, B2);
    cout << "Test 2 (Not disjoint): " << (!result2 ? "PASS" : "FAIL") << endl;

    // Test 3: Empty sets
    set<int> A3 = {}, B3 = {};
    bool result3 = problem3_2(A3, B3);
    cout << "Test 3 (Both empty): " << (result3 ? "PASS" : "FAIL") << endl;

    // Test 4: One empty set
    set<int> A4 = {1, 2, 3}, B4 = {};
    bool result4 = problem3_2(A4, B4);
    cout << "Test 4 (One empty): " << (result4 ? "PASS" : "FAIL") << endl;

    // Test 5: Single common element
    set<int> A5 = {1, 2, 3, 4}, B5 = {4, 5, 6, 7};
    bool result5 = problem3_2(A5, B5);
    cout << "Test 5 (Single common): " << (!result5 ? "PASS" : "FAIL") << endl;
}

void testProblem3_3()
{
    cout << "\n=== Testing Problem 3.3: Set Partition Validation ===" << endl;

    // Test 1: Valid partition
    set<int> U1 = {1, 2, 3, 4}, A1 = {1, 2}, B1 = {3, 4};
    bool result1 = problem3_3(U1, A1, B1);
    cout << "Test 1 (Valid partition): " << (result1 ? "PASS" : "FAIL") << endl;

    // Test 2: Invalid - overlapping sets
    set<int> U2 = {1, 2, 3}, A2 = {1, 2}, B2 = {2, 3};
    bool result2 = problem3_3(U2, A2, B2);
    cout << "Test 2 (Overlapping): " << (!result2 ? "PASS" : "FAIL") << endl;

    // Test 3: Invalid - missing elements
    set<int> U3 = {1, 2, 3, 4}, A3 = {1, 2}, B3 = {3};
    bool result3 = problem3_3(U3, A3, B3);
    cout << "Test 3 (Missing elements): " << (!result3 ? "PASS" : "FAIL") << endl;

    // Test 4: Invalid - extra elements
    set<int> U4 = {1, 2, 3}, A4 = {1, 2}, B4 = {3, 4};
    bool result4 = problem3_3(U4, A4, B4);
    cout << "Test 4 (Extra elements): " << (!result4 ? "PASS" : "FAIL") << endl;

    // Test 5: Invalid - empty set
    set<int> U5 = {1, 2, 3}, A5 = {}, B5 = {1, 2, 3};
    bool result5 = problem3_3(U5, A5, B5);
    cout << "Test 5 (Empty partition): " << (!result5 ? "PASS" : "FAIL") << endl;
}

// Additional test functions for remaining problems would follow the same pattern...

// ============================================================================
// MAIN TEST RUNNER
// ============================================================================

int main() {
    cout << "=== C++ SETS PRACTICE PROBLEMS TEST RUNNER ===" << endl;
    
    // Test Concept 1 problems
    testProblem1_1();
    testProblem1_2();
    testProblem1_3();
    
    // Test Concept 2 problems  
    testProblem2_1();
    testProblem2_2();
    testProblem2_3();
    
    // Test Concept 3 problems
    testProblem3_1();
    testProblem3_2();
    testProblem3_3();
    
    cout << "\n=== TESTING COMPLETE ===" << endl;
    return 0;
}