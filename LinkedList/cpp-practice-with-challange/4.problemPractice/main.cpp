#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Node structure for singly linked list
struct ListNode {
    int data;
    ListNode* next;
    
    ListNode(int val) : data(val), next(nullptr) {}
};

// Helper function to create linked list from array (for testing)
ListNode* createList(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    if (!head) {
        cout << "NULL" << endl;
        return;
    }
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

// Helper function to compare two linked lists
bool compareLists(ListNode* list1, ListNode* list2) {
    while (list1 && list2) {
        if (list1->data != list2->data) return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1 == nullptr && list2 == nullptr;
}

// Helper function to get list length
int getListLength(ListNode* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Helper function to convert list to vector for easy comparison
vector<int> listToVector(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->data);
        head = head->next;
    }
    return result;
}

// Problem 1: Easy 1 - Count Nodes in Linked List
// Given a linked list, count the total number of nodes.
// Input: Head of the linked list
// Output: Integer representing the count of nodes
// 
// Example 1:
// Input: 1 -> 2 -> 3 -> NULL
// Output: 3
//
// Example 2:
// Input: 5 -> NULL
// Output: 1
//
// Example 3:
// Input: NULL
// Output: 0
//
// Constraints: 0 ≤ number of nodes ≤ 1000
int problem1Solution(ListNode* head) {
    // TODO: Implement your solution here using Linked Lists
    // Hint: Traverse the list and count each node until you reach NULL
    return 0;
}

// Problem 2: Easy 2 - Find Maximum Value in Linked List
// Given a linked list of integers, find the maximum value.
// Input: Head of the linked list (guaranteed to have at least one node)
// Output: Integer representing the maximum value
//
// Example 1:
// Input: 3 -> 1 -> 4 -> 2 -> NULL
// Output: 4
//
// Example 2:
// Input: -5 -> -2 -> -10 -> NULL
// Output: -2
//
// Example 3:
// Input: 7 -> NULL
// Output: 7
//
// Constraints: 1 ≤ number of nodes ≤ 1000, -1000 ≤ node value ≤ 1000
int problem2Solution(ListNode* head) {
    // TODO: Implement your solution here using Linked Lists
    // Hint: Keep track of the maximum value while traversing the list
    return 0;
}

// Problem 3: Easy 3 - Search for Value in Linked List
// Given a linked list and a target value, return true if the value exists in the list.
// Input: Head of the linked list and target value
// Output: Boolean indicating if target is found
//
// Example 1:
// Input: 1 -> 2 -> 3 -> 4 -> NULL, target = 3
// Output: true
//
// Example 2:
// Input: 1 -> 2 -> 3 -> 4 -> NULL, target = 5
// Output: false
//
// Example 3:
// Input: NULL, target = 1
// Output: false
//
// Constraints: 0 ≤ number of nodes ≤ 1000, -1000 ≤ values ≤ 1000
bool problem3Solution(ListNode* head, int target) {
    // TODO: Implement your solution here using Linked Lists
    // Hint: Traverse the list and compare each node's data with the target
    return false;
}

// Problem 4: Medium 1 - Insert Node at Specific Position
// Given a linked list, insert a new node with given value at the specified position (0-indexed).
// Input: Head of the linked list, value to insert, and position
// Output: Head of the modified linked list
//
// Example 1:
// Input: 1 -> 2 -> 4 -> NULL, value = 3, position = 2
// Output: 1 -> 2 -> 3 -> 4 -> NULL
//
// Example 2:
// Input: 1 -> 2 -> 3 -> NULL, value = 0, position = 0
// Output: 0 -> 1 -> 2 -> 3 -> NULL
//
// Example 3:
// Input: NULL, value = 5, position = 0
// Output: 5 -> NULL
//
// Constraints: 0 ≤ position ≤ length of list, -1000 ≤ value ≤ 1000
ListNode* problem4Solution(ListNode* head, int value, int position) {
    // TODO: Implement your solution here using Linked Lists
    // Hint: Handle insertion at beginning separately, then traverse to the position
    return nullptr;
}

// Problem 5: Medium 2 - Delete All Nodes with Given Value
// Given a linked list and a value, delete all nodes that have this value.
// Input: Head of the linked list and value to delete
// Output: Head of the modified linked list
//
// Example 1:
// Input: 1 -> 2 -> 3 -> 2 -> 4 -> NULL, value = 2
// Output: 1 -> 3 -> 4 -> NULL
//
// Example 2:
// Input: 1 -> 1 -> 1 -> NULL, value = 1
// Output: NULL
//
// Example 3:
// Input: 1 -> 2 -> 3 -> NULL, value = 4
// Output: 1 -> 2 -> 3 -> NULL
//
// Constraints: 0 ≤ number of nodes ≤ 1000, -1000 ≤ values ≤ 1000
ListNode* problem5Solution(ListNode* head, int value) {
    // TODO: Implement your solution here using Linked Lists
    // Hint: Handle deletion at the beginning in a loop, then traverse for middle/end deletions
    return nullptr;
}

// Problem 6: Medium 3 - Reverse Linked List
// Given a linked list, reverse it and return the new head.
// Input: Head of the linked list
// Output: Head of the reversed linked list
//
// Example 1:
// Input: 1 -> 2 -> 3 -> 4 -> NULL
// Output: 4 -> 3 -> 2 -> 1 -> NULL
//
// Example 2:
// Input: 1 -> 2 -> NULL
// Output: 2 -> 1 -> NULL
//
// Example 3:
// Input: NULL
// Output: NULL
//
// Constraints: 0 ≤ number of nodes ≤ 1000
ListNode* problem6Solution(ListNode* head) {
    // TODO: Implement your solution here using Linked Lists
    // Hint: Use three pointers to reverse the links between nodes
    return nullptr;
}

// Problem 7: Hard 1 - Merge Two Sorted Linked Lists
// Given two sorted linked lists, merge them into one sorted linked list.
// Input: Heads of two sorted linked lists
// Output: Head of the merged sorted linked list
//
// Example 1:
// Input: list1 = 1 -> 2 -> 4 -> NULL, list2 = 1 -> 3 -> 4 -> NULL
// Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> NULL
//
// Example 2:
// Input: list1 = NULL, list2 = 0 -> NULL
// Output: 0 -> NULL
//
// Example 3:
// Input: list1 = NULL, list2 = NULL
// Output: NULL
//
// Constraints: 0 ≤ number of nodes in each list ≤ 50, -100 ≤ node values ≤ 100
// Both lists are sorted in ascending order
ListNode* problem7Solution(ListNode* list1, ListNode* list2) {
    // TODO: Implement your solution here using Linked Lists
    // Hint: Use a dummy node and two pointers to compare and link nodes
    return nullptr;
}

// Problem 8: Hard 2 - Remove Nth Node from End
// Given a linked list, remove the nth node from the end and return the head.
// Input: Head of the linked list and n (1-indexed from the end)
// Output: Head of the modified linked list
//
// Example 1:
// Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL, n = 2
// Output: 1 -> 2 -> 3 -> 5 -> NULL (removed 4, which is 2nd from end)
//
// Example 2:
// Input: 1 -> NULL, n = 1
// Output: NULL
//
// Example 3:
// Input: 1 -> 2 -> NULL, n = 2
// Output: 2 -> NULL (removed 1, which is 2nd from end)
//
// Constraints: 1 ≤ number of nodes ≤ 30, 1 ≤ n ≤ number of nodes
ListNode* problem8Solution(ListNode* head, int n) {
    // TODO: Implement your solution here using Linked Lists
    // Hint: Use two pointers with a gap of n nodes, or count total length first
    return nullptr;
}

void testProblem1() {
    cout << "\n=== Testing Problem 1: Count Nodes ===" << endl;
    
    // Test Case 1: Normal list with 3 nodes
    // Manual verification: 1 -> 2 -> 3 -> NULL = 3 nodes
    vector<int> input1 = {1, 2, 3};
    ListNode* head1 = createList(input1);
    cout << "Test 1 - Input: "; printList(head1);
    cout << "Expected: 3, Got: " << problem1Solution(head1) << endl;
    cout << "Result: " << (problem1Solution(head1) == 3 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Single node
    // Manual verification: 5 -> NULL = 1 node
    vector<int> input2 = {5};
    ListNode* head2 = createList(input2);
    cout << "\nTest 2 - Input: "; printList(head2);
    cout << "Expected: 1, Got: " << problem1Solution(head2) << endl;
    cout << "Result: " << (problem1Solution(head2) == 1 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Empty list
    // Manual verification: NULL = 0 nodes
    ListNode* head3 = nullptr;
    cout << "\nTest 3 - Input: "; printList(head3);
    cout << "Expected: 0, Got: " << problem1Solution(head3) << endl;
    cout << "Result: " << (problem1Solution(head3) == 0 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Large list
    // Manual verification: 1->2->3->4->5->6->7 = 7 nodes
    vector<int> input4 = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head4 = createList(input4);
    cout << "\nTest 4 - Input: "; printList(head4);
    cout << "Expected: 7, Got: " << problem1Solution(head4) << endl;
    cout << "Result: " << (problem1Solution(head4) == 7 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Two nodes
    // Manual verification: 10 -> 20 -> NULL = 2 nodes
    vector<int> input5 = {10, 20};
    ListNode* head5 = createList(input5);
    cout << "\nTest 5 - Input: "; printList(head5);
    cout << "Expected: 2, Got: " << problem1Solution(head5) << endl;
    cout << "Result: " << (problem1Solution(head5) == 2 ? "PASS" : "FAIL") << endl;
}

void testProblem2() {
    cout << "\n=== Testing Problem 2: Find Maximum Value ===" << endl;
    
    // Test Case 1: Normal case
    // Manual verification: 3, 1, 4, 2 -> max is 4
    vector<int> input1 = {3, 1, 4, 2};
    ListNode* head1 = createList(input1);
    cout << "Test 1 - Input: "; printList(head1);
    cout << "Expected: 4, Got: " << problem2Solution(head1) << endl;
    cout << "Result: " << (problem2Solution(head1) == 4 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: All negative numbers
    // Manual verification: -5, -2, -10 -> max is -2
    vector<int> input2 = {-5, -2, -10};
    ListNode* head2 = createList(input2);
    cout << "\nTest 2 - Input: "; printList(head2);
    cout << "Expected: -2, Got: " << problem2Solution(head2) << endl;
    cout << "Result: " << (problem2Solution(head2) == -2 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Single node
    // Manual verification: 7 -> max is 7
    vector<int> input3 = {7};
    ListNode* head3 = createList(input3);
    cout << "\nTest 3 - Input: "; printList(head3);
    cout << "Expected: 7, Got: " << problem2Solution(head3) << endl;
    cout << "Result: " << (problem2Solution(head3) == 7 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Max at beginning
    // Manual verification: 10, 5, 3, 1 -> max is 10
    vector<int> input4 = {10, 5, 3, 1};
    ListNode* head4 = createList(input4);
    cout << "\nTest 4 - Input: "; printList(head4);
    cout << "Expected: 10, Got: " << problem2Solution(head4) << endl;
    cout << "Result: " << (problem2Solution(head4) == 10 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Max at end
    // Manual verification: 1, 3, 5, 15 -> max is 15
    vector<int> input5 = {1, 3, 5, 15};
    ListNode* head5 = createList(input5);
    cout << "\nTest 5 - Input: "; printList(head5);
    cout << "Expected: 15, Got: " << problem2Solution(head5) << endl;
    cout << "Result: " << (problem2Solution(head5) == 15 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: All same values
    // Manual verification: 5, 5, 5 -> max is 5
    vector<int> input6 = {5, 5, 5};
    ListNode* head6 = createList(input6);
    cout << "\nTest 6 - Input: "; printList(head6);
    cout << "Expected: 5, Got: " << problem2Solution(head6) << endl;
    cout << "Result: " << (problem2Solution(head6) == 5 ? "PASS" : "FAIL") << endl;
}

void testProblem3() {
    cout << "\n=== Testing Problem 3: Search for Value ===" << endl;
    
    // Test Case 1: Target found in middle
    // Manual verification: 1, 2, 3, 4 contains 3 -> true
    vector<int> input1 = {1, 2, 3, 4};
    ListNode* head1 = createList(input1);
    cout << "Test 1 - Input: "; printList(head1);
    cout << "Target: 3, Expected: true, Got: " << (problem3Solution(head1, 3) ? "true" : "false") << endl;
    cout << "Result: " << (problem3Solution(head1, 3) == true ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Target not found
    // Manual verification: 1, 2, 3, 4 does not contain 5 -> false
    vector<int> input2 = {1, 2, 3, 4};
    ListNode* head2 = createList(input2);
    cout << "\nTest 2 - Input: "; printList(head2);
    cout << "Target: 5, Expected: false, Got: " << (problem3Solution(head2, 5) ? "true" : "false") << endl;
    cout << "Result: " << (problem3Solution(head2, 5) == false ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Empty list
    // Manual verification: NULL does not contain 1 -> false
    ListNode* head3 = nullptr;
    cout << "\nTest 3 - Input: "; printList(head3);
    cout << "Target: 1, Expected: false, Got: " << (problem3Solution(head3, 1) ? "true" : "false") << endl;
    cout << "Result: " << (problem3Solution(head3, 1) == false ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Target at beginning
    // Manual verification: 10, 20, 30 contains 10 -> true
    vector<int> input4 = {10, 20, 30};
    ListNode* head4 = createList(input4);
    cout << "\nTest 4 - Input: "; printList(head4);
    cout << "Target: 10, Expected: true, Got: " << (problem3Solution(head4, 10) ? "true" : "false") << endl;
    cout << "Result: " << (problem3Solution(head4, 10) == true ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Target at end
    // Manual verification: 5, 10, 15 contains 15 -> true
    vector<int> input5 = {5, 10, 15};
    ListNode* head5 = createList(input5);
    cout << "\nTest 5 - Input: "; printList(head5);
    cout << "Target: 15, Expected: true, Got: " << (problem3Solution(head5, 15) ? "true" : "false") << endl;
    cout << "Result: " << (problem3Solution(head5, 15) == true ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Single node - target found
    // Manual verification: 7 contains 7 -> true
    vector<int> input6 = {7};
    ListNode* head6 = createList(input6);
    cout << "\nTest 6 - Input: "; printList(head6);
    cout << "Target: 7, Expected: true, Got: " << (problem3Solution(head6, 7) ? "true" : "false") << endl;
    cout << "Result: " << (problem3Solution(head6, 7) == true ? "PASS" : "FAIL") << endl;
    
    // Test Case 7: Single node - target not found
    // Manual verification: 7 does not contain 8 -> false
    vector<int> input7 = {7};
    ListNode* head7 = createList(input7);
    cout << "\nTest 7 - Input: "; printList(head7);
    cout << "Target: 8, Expected: false, Got: " << (problem3Solution(head7, 8) ? "true" : "false") << endl;
    cout << "Result: " << (problem3Solution(head7, 8) == false ? "PASS" : "FAIL") << endl;
}

void testProblem4() {
    cout << "\n=== Testing Problem 4: Insert Node at Position ===" << endl;
    
    // Test Case 1: Insert in middle
    // Manual verification: 1->2->4 insert 3 at pos 2 -> 1->2->3->4
    vector<int> input1 = {1, 2, 4};
    ListNode* head1 = createList(input1);
    cout << "Test 1 - Input: "; printList(head1);
    ListNode* result1 = problem4Solution(head1, 3, 2);
    cout << "Insert 3 at position 2" << endl;
    cout << "Expected: 1 -> 2 -> 3 -> 4 -> NULL" << endl;
    cout << "Got: "; printList(result1);
    vector<int> expected1 = {1, 2, 3, 4};
    vector<int> actual1 = listToVector(result1);
    cout << "Result: " << (actual1 == expected1 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Insert at beginning
    // Manual verification: 1->2->3 insert 0 at pos 0 -> 0->1->2->3
    vector<int> input2 = {1, 2, 3};
    ListNode* head2 = createList(input2);
    cout << "\nTest 2 - Input: "; printList(head2);
    ListNode* result2 = problem4Solution(head2, 0, 0);
    cout << "Insert 0 at position 0" << endl;
    cout << "Expected: 0 -> 1 -> 2 -> 3 -> NULL" << endl;
    cout << "Got: "; printList(result2);
    vector<int> expected2 = {0, 1, 2, 3};
    vector<int> actual2 = listToVector(result2);
    cout << "Result: " << (actual2 == expected2 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Insert in empty list
    // Manual verification: NULL insert 5 at pos 0 -> 5
    ListNode* head3 = nullptr;
    cout << "\nTest 3 - Input: "; printList(head3);
    ListNode* result3 = problem4Solution(head3, 5, 0);
    cout << "Insert 5 at position 0" << endl;
    cout << "Expected: 5 -> NULL" << endl;
    cout << "Got: "; printList(result3);
    vector<int> expected3 = {5};
    vector<int> actual3 = listToVector(result3);
    cout << "Result: " << (actual3 == expected3 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Insert at end
    // Manual verification: 1->2->3 insert 4 at pos 3 -> 1->2->3->4
    vector<int> input4 = {1, 2, 3};
    ListNode* head4 = createList(input4);
    cout << "\nTest 4 - Input: "; printList(head4);
    ListNode* result4 = problem4Solution(head4, 4, 3);
    cout << "Insert 4 at position 3" << endl;
    cout << "Expected: 1 -> 2 -> 3 -> 4 -> NULL" << endl;
    cout << "Got: "; printList(result4);
    vector<int> expected4 = {1, 2, 3, 4};
    vector<int> actual4 = listToVector(result4);
    cout << "Result: " << (actual4 == expected4 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Insert in single node list at end
    // Manual verification: 1 insert 2 at pos 1 -> 1->2
    vector<int> input5 = {1};
    ListNode* head5 = createList(input5);
    cout << "\nTest 5 - Input: "; printList(head5);
    ListNode* result5 = problem4Solution(head5, 2, 1);
    cout << "Insert 2 at position 1" << endl;
    cout << "Expected: 1 -> 2 -> NULL" << endl;
    cout << "Got: "; printList(result5);
    vector<int> expected5 = {1, 2};
    vector<int> actual5 = listToVector(result5);
    cout << "Result: " << (actual5 == expected5 ? "PASS" : "FAIL") << endl;
}

void testProblem5() {
    cout << "\n=== Testing Problem 5: Delete All Nodes with Given Value ===" << endl;
    
    // Test Case 1: Delete from middle
    // Manual verification: 1->2->3->2->4 delete 2 -> 1->3->4
    vector<int> input1 = {1, 2, 3, 2, 4};
    ListNode* head1 = createList(input1);
    cout << "Test 1 - Input: "; printList(head1);
    ListNode* result1 = problem5Solution(head1, 2);
    cout << "Delete all nodes with value 2" << endl;
    cout << "Expected: 1 -> 3 -> 4 -> NULL" << endl;
    cout << "Got: "; printList(result1);
    vector<int> expected1 = {1, 3, 4};
    vector<int> actual1 = listToVector(result1);
    cout << "Result: " << (actual1 == expected1 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Delete all nodes
    // Manual verification: 1->1->1 delete 1 -> NULL
    vector<int> input2 = {1, 1, 1};
    ListNode* head2 = createList(input2);
    cout << "\nTest 2 - Input: "; printList(head2);
    ListNode* result2 = problem5Solution(head2, 1);
    cout << "Delete all nodes with value 1" << endl;
    cout << "Expected: NULL" << endl;
    cout << "Got: "; printList(result2);
    vector<int> expected2 = {};
    vector<int> actual2 = listToVector(result2);
    cout << "Result: " << (actual2 == expected2 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Value not found
    // Manual verification: 1->2->3 delete 4 -> 1->2->3
    vector<int> input3 = {1, 2, 3};
    ListNode* head3 = createList(input3);
    cout << "\nTest 3 - Input: "; printList(head3);
    ListNode* result3 = problem5Solution(head3, 4);
    cout << "Delete all nodes with value 4" << endl;
    cout << "Expected: 1 -> 2 -> 3 -> NULL" << endl;
    cout << "Got: "; printList(result3);
    vector<int> expected3 = {1, 2, 3};
    vector<int> actual3 = listToVector(result3);
    cout << "Result: " << (actual3 == expected3 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Delete from beginning
    // Manual verification: 5->5->1->2 delete 5 -> 1->2
    vector<int> input4 = {5, 5, 1, 2};
    ListNode* head4 = createList(input4);
    cout << "\nTest 4 - Input: "; printList(head4);
    ListNode* result4 = problem5Solution(head4, 5);
    cout << "Delete all nodes with value 5" << endl;
    cout << "Expected: 1 -> 2 -> NULL" << endl;
    cout << "Got: "; printList(result4);
    vector<int> expected4 = {1, 2};
    vector<int> actual4 = listToVector(result4);
    cout << "Result: " << (actual4 == expected4 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Delete from end
    // Manual verification: 1->2->3->3 delete 3 -> 1->2
    vector<int> input5 = {1, 2, 3, 3};
    ListNode* head5 = createList(input5);
    cout << "\nTest 5 - Input: "; printList(head5);
    ListNode* result5 = problem5Solution(head5, 3);
    cout << "Delete all nodes with value 3" << endl;
    cout << "Expected: 1 -> 2 -> NULL" << endl;
    cout << "Got: "; printList(result5);
    vector<int> expected5 = {1, 2};
    vector<int> actual5 = listToVector(result5);
    cout << "Result: " << (actual5 == expected5 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Single node - delete it
    // Manual verification: 7 delete 7 -> NULL
    vector<int> input6 = {7};
    ListNode* head6 = createList(input6);
    cout << "\nTest 6 - Input: "; printList(head6);
    ListNode* result6 = problem5Solution(head6, 7);
    cout << "Delete all nodes with value 7" << endl;
    cout << "Expected: NULL" << endl;
    cout << "Got: "; printList(result6);
    vector<int> expected6 = {};
    vector<int> actual6 = listToVector(result6);
    cout << "Result: " << (actual6 == expected6 ? "PASS" : "FAIL") << endl;
}

void testProblem6() {
    cout << "\n=== Testing Problem 6: Reverse Linked List ===" << endl;
    
    // Test Case 1: Normal case
    // Manual verification: 1->2->3->4 reverse -> 4->3->2->1
    vector<int> input1 = {1, 2, 3, 4};
    ListNode* head1 = createList(input1);
    cout << "Test 1 - Input: "; printList(head1);
    ListNode* result1 = problem6Solution(head1);
    cout << "Expected: 4 -> 3 -> 2 -> 1 -> NULL" << endl;
    cout << "Got: "; printList(result1);
    vector<int> expected1 = {4, 3, 2, 1};
    vector<int> actual1 = listToVector(result1);
    cout << "Result: " << (actual1 == expected1 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Two nodes
    // Manual verification: 1->2 reverse -> 2->1
    vector<int> input2 = {1, 2};
    ListNode* head2 = createList(input2);
    cout << "\nTest 2 - Input: "; printList(head2);
    ListNode* result2 = problem6Solution(head2);
    cout << "Expected: 2 -> 1 -> NULL" << endl;
    cout << "Got: "; printList(result2);
    vector<int> expected2 = {2, 1};
    vector<int> actual2 = listToVector(result2);
    cout << "Result: " << (actual2 == expected2 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Empty list
    // Manual verification: NULL reverse -> NULL
    ListNode* head3 = nullptr;
    cout << "\nTest 3 - Input: "; printList(head3);
    ListNode* result3 = problem6Solution(head3);
    cout << "Expected: NULL" << endl;
    cout << "Got: "; printList(result3);
    vector<int> expected3 = {};
    vector<int> actual3 = listToVector(result3);
    cout << "Result: " << (actual3 == expected3 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Single node
    // Manual verification: 5 reverse -> 5
    vector<int> input4 = {5};
    ListNode* head4 = createList(input4);
    cout << "\nTest 4 - Input: "; printList(head4);
    ListNode* result4 = problem6Solution(head4);
    cout << "Expected: 5 -> NULL" << endl;
    cout << "Got: "; printList(result4);
    vector<int> expected4 = {5};
    vector<int> actual4 = listToVector(result4);
    cout << "Result: " << (actual4 == expected4 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Longer list
    // Manual verification: 1->2->3->4->5->6 reverse -> 6->5->4->3->2->1
    vector<int> input5 = {1, 2, 3, 4, 5, 6};
    ListNode* head5 = createList(input5);
    cout << "\nTest 5 - Input: "; printList(head5);
    ListNode* result5 = problem6Solution(head5);
    cout << "Expected: 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL" << endl;
    cout << "Got: "; printList(result5);
    vector<int> expected5 = {6, 5, 4, 3, 2, 1};
    vector<int> actual5 = listToVector(result5);
    cout << "Result: " << (actual5 == expected5 ? "PASS" : "FAIL") << endl;
}

void testProblem7() {
    cout << "\n=== Testing Problem 7: Merge Two Sorted Lists ===" << endl;
    
    // Test Case 1: Normal merge
    // Manual verification: (1->2->4) + (1->3->4) = 1->1->2->3->4->4
    vector<int> input1a = {1, 2, 4};
    vector<int> input1b = {1, 3, 4};
    ListNode* list1a = createList(input1a);
    ListNode* list1b = createList(input1b);
    cout << "Test 1 - List1: "; printList(list1a);
    cout << "         List2: "; printList(list1b);
    ListNode* result1 = problem7Solution(list1a, list1b);
    cout << "Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> NULL" << endl;
    cout << "Got: "; printList(result1);
    vector<int> expected1 = {1, 1, 2, 3, 4, 4};
    vector<int> actual1 = listToVector(result1);
    cout << "Result: " << (actual1 == expected1 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: One empty list
    // Manual verification: NULL + (0) = 0
    ListNode* list2a = nullptr;
    vector<int> input2b = {0};
    ListNode* list2b = createList(input2b);
    cout << "\nTest 2 - List1: "; printList(list2a);
    cout << "         List2: "; printList(list2b);
    ListNode* result2 = problem7Solution(list2a, list2b);
    cout << "Expected: 0 -> NULL" << endl;
    cout << "Got: "; printList(result2);
    vector<int> expected2 = {0};
    vector<int> actual2 = listToVector(result2);
    cout << "Result: " << (actual2 == expected2 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Both empty lists
    // Manual verification: NULL + NULL = NULL
    ListNode* list3a = nullptr;
    ListNode* list3b = nullptr;
    cout << "\nTest 3 - List1: "; printList(list3a);
    cout << "         List2: "; printList(list3b);
    ListNode* result3 = problem7Solution(list3a, list3b);
    cout << "Expected: NULL" << endl;
    cout << "Got: "; printList(result3);
    vector<int> expected3 = {};
    vector<int> actual3 = listToVector(result3);
    cout << "Result: " << (actual3 == expected3 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Different lengths
    // Manual verification: (1->5->6) + (2->3->4->7) = 1->2->3->4->5->6->7
    vector<int> input4a = {1, 5, 6};
    vector<int> input4b = {2, 3, 4, 7};
    ListNode* list4a = createList(input4a);
    ListNode* list4b = createList(input4b);
    cout << "\nTest 4 - List1: "; printList(list4a);
    cout << "         List2: "; printList(list4b);
    ListNode* result4 = problem7Solution(list4a, list4b);
    cout << "Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL" << endl;
    cout << "Got: "; printList(result4);
    vector<int> expected4 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> actual4 = listToVector(result4);
    cout << "Result: " << (actual4 == expected4 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: All elements from first list come first
    // Manual verification: (1->2->3) + (4->5->6) = 1->2->3->4->5->6
    vector<int> input5a = {1, 2, 3};
    vector<int> input5b = {4, 5, 6};
    ListNode* list5a = createList(input5a);
    ListNode* list5b = createList(input5b);
    cout << "\nTest 5 - List1: "; printList(list5a);
    cout << "         List2: "; printList(list5b);
    ListNode* result5 = problem7Solution(list5a, list5b);
    cout << "Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL" << endl;
    cout << "Got: "; printList(result5);
    vector<int> expected5 = {1, 2, 3, 4, 5, 6};
    vector<int> actual5 = listToVector(result5);
    cout << "Result: " << (actual5 == expected5 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Single nodes
    // Manual verification: (1) + (2) = 1->2
    vector<int> input6a = {1};
    vector<int> input6b = {2};
    ListNode* list6a = createList(input6a);
    ListNode* list6b = createList(input6b);
    cout << "\nTest 6 - List1: "; printList(list6a);
    cout << "         List2: "; printList(list6b);
    ListNode* result6 = problem7Solution(list6a, list6b);
    cout << "Expected: 1 -> 2 -> NULL" << endl;
    cout << "Got: "; printList(result6);
    vector<int> expected6 = {1, 2};
    vector<int> actual6 = listToVector(result6);
    cout << "Result: " << (actual6 == expected6 ? "PASS" : "FAIL") << endl;
}

void testProblem8() {
    cout << "\n=== Testing Problem 8: Remove Nth Node from End ===" << endl;
    
    // Test Case 1: Remove 2nd from end
    // Manual verification: 1->2->3->4->5 remove 2nd from end (4) -> 1->2->3->5
    // Positions from end: 5(1st), 4(2nd), 3(3rd), 2(4th), 1(5th)
    vector<int> input1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(input1);
    cout << "Test 1 - Input: "; printList(head1);
    ListNode* result1 = problem8Solution(head1, 2);
    cout << "Remove 2nd node from end" << endl;
    cout << "Expected: 1 -> 2 -> 3 -> 5 -> NULL" << endl;
    cout << "Got: "; printList(result1);
    vector<int> expected1 = {1, 2, 3, 5};
    vector<int> actual1 = listToVector(result1);
    cout << "Result: " << (actual1 == expected1 ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Remove only node
    // Manual verification: 1 remove 1st from end -> NULL
    vector<int> input2 = {1};
    ListNode* head2 = createList(input2);
    cout << "\nTest 2 - Input: "; printList(head2);
    ListNode* result2 = problem8Solution(head2, 1);
    cout << "Remove 1st node from end" << endl;
    cout << "Expected: NULL" << endl;
    cout << "Got: "; printList(result2);
    vector<int> expected2 = {};
    vector<int> actual2 = listToVector(result2);
    cout << "Result: " << (actual2 == expected2 ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Remove first node (from 2-node list)
    // Manual verification: 1->2 remove 2nd from end (1) -> 2
    // Positions from end: 2(1st), 1(2nd)
    vector<int> input3 = {1, 2};
    ListNode* head3 = createList(input3);
    cout << "\nTest 3 - Input: "; printList(head3);
    ListNode* result3 = problem8Solution(head3, 2);
    cout << "Remove 2nd node from end" << endl;
    cout << "Expected: 2 -> NULL" << endl;
    cout << "Got: "; printList(result3);
    vector<int> expected3 = {2};
    vector<int> actual3 = listToVector(result3);
    cout << "Result: " << (actual3 == expected3 ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Remove last node
    // Manual verification: 1->2->3 remove 1st from end (3) -> 1->2
    vector<int> input4 = {1, 2, 3};
    ListNode* head4 = createList(input4);
    cout << "\nTest 4 - Input: "; printList(head4);
    ListNode* result4 = problem8Solution(head4, 1);
    cout << "Remove 1st node from end" << endl;
    cout << "Expected: 1 -> 2 -> NULL" << endl;
    cout << "Got: "; printList(result4);
    vector<int> expected4 = {1, 2};
    vector<int> actual4 = listToVector(result4);
    cout << "Result: " << (actual4 == expected4 ? "PASS" : "FAIL") << endl;
    
    // Test Case 5: Remove middle node
    // Manual verification: 1->2->3->4->5->6 remove 3rd from end (4) -> 1->2->3->5->6
    // Positions from end: 6(1st), 5(2nd), 4(3rd), 3(4th), 2(5th), 1(6th)
    vector<int> input5 = {1, 2, 3, 4, 5, 6};
    ListNode* head5 = createList(input5);
    cout << "\nTest 5 - Input: "; printList(head5);
    ListNode* result5 = problem8Solution(head5, 3);
    cout << "Remove 3rd node from end" << endl;
    cout << "Expected: 1 -> 2 -> 3 -> 5 -> 6 -> NULL" << endl;
    cout << "Got: "; printList(result5);
    vector<int> expected5 = {1, 2, 3, 5, 6};
    vector<int> actual5 = listToVector(result5);
    cout << "Result: " << (actual5 == expected5 ? "PASS" : "FAIL") << endl;
    
    // Test Case 6: Remove first node from longer list
    // Manual verification: 1->2->3->4 remove 4th from end (1) -> 2->3->4
    // Positions from end: 4(1st), 3(2nd), 2(3rd), 1(4th)
    vector<int> input6 = {1, 2, 3, 4};
    ListNode* head6 = createList(input6);
    cout << "\nTest 6 - Input: "; printList(head6);
    ListNode* result6 = problem8Solution(head6, 4);
    cout << "Remove 4th node from end" << endl;
    cout << "Expected: 2 -> 3 -> 4 -> NULL" << endl;
    cout << "Got: "; printList(result6);
    vector<int> expected6 = {2, 3, 4};
    vector<int> actual6 = listToVector(result6);
    cout << "Result: " << (actual6 == expected6 ? "PASS" : "FAIL") << endl;
    
    // Test Case 7: Remove from 2-node list (last node)
    // Manual verification: 1->2 remove 1st from end (2) -> 1
    vector<int> input7 = {1, 2};
    ListNode* head7 = createList(input7);
    cout << "\nTest 7 - Input: "; printList(head7);
    ListNode* result7 = problem8Solution(head7, 1);
    cout << "Remove 1st node from end" << endl;
    cout << "Expected: 1 -> NULL" << endl;
    cout << "Got: "; printList(result7);
    vector<int> expected7 = {1};
    vector<int> actual7 = listToVector(result7);
    cout << "Result: " << (actual7 == expected7 ? "PASS" : "FAIL") << endl;
}

int main() {
    int choice;
    cout << "=== LINKED LIST PRACTICE PROBLEMS ===" << endl;
    cout << "Choose a problem to test (1-8) or 9 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Count Nodes" << endl;
    cout << "2. Problem 2 (Easy) - Find Maximum Value" << endl;
    cout << "3. Problem 3 (Easy) - Search for Value" << endl;
    cout << "4. Problem 4 (Medium) - Insert Node at Position" << endl;
    cout << "5. Problem 5 (Medium) - Delete All Nodes with Value" << endl;
    cout << "6. Problem 6 (Medium) - Reverse Linked List" << endl;
    cout << "7. Problem 7 (Hard) - Merge Two Sorted Lists" << endl;
    cout << "8. Problem 8 (Hard) - Remove Nth Node from End" << endl;
    cout << "9. Test All Problems" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1: testProblem1(); break;
        case 2: testProblem2(); break;
        case 3: testProblem3(); break;
        case 4: testProblem4(); break;
        case 5: testProblem5(); break;
        case 6: testProblem6(); break;
        case 7: testProblem7(); break;
        case 8: testProblem8(); break;
        case 9:
            testProblem1(); testProblem2(); testProblem3(); testProblem4();
            testProblem5(); testProblem6(); testProblem7(); testProblem8();
            break;
        default: cout << "Invalid choice!" << endl;
    }

    return 0;
}