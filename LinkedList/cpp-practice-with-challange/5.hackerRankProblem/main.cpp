#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

// ============================================================================
// SINGLY LINKED LIST NODE DEFINITION
// ============================================================================
struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

// ============================================================================
// DOUBLY LINKED LIST NODE DEFINITION
// ============================================================================
struct DoublyLinkedListNode
{
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// ============================================================================
// HELPER FUNCTIONS FOR LINKED LISTS
// ============================================================================

// Create a singly linked list from a vector
SinglyLinkedListNode *createSinglyLinkedList(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    SinglyLinkedListNode *head = new SinglyLinkedListNode(arr[0]);
    SinglyLinkedListNode *current = head;

    for (size_t i = 1; i < arr.size(); i++)
    {
        current->next = new SinglyLinkedListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Create a doubly linked list from a vector
DoublyLinkedListNode *createDoublyLinkedList(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    DoublyLinkedListNode *head = new DoublyLinkedListNode(arr[0]);
    DoublyLinkedListNode *current = head;

    for (size_t i = 1; i < arr.size(); i++)
    {
        current->next = new DoublyLinkedListNode(arr[i]);
        current->next->prev = current;
        current = current->next;
    }

    return head;
}

// Convert singly linked list to vector
vector<int> singlyLinkedListToVector(SinglyLinkedListNode *head)
{
    vector<int> result;
    while (head != nullptr)
    {
        result.push_back(head->data);
        head = head->next;
    }
    return result;
}

// Convert doubly linked list to vector
vector<int> doublyLinkedListToVector(DoublyLinkedListNode *head)
{
    vector<int> result;
    while (head != nullptr)
    {
        result.push_back(head->data);
        head = head->next;
    }
    return result;
}

// Free singly linked list memory
void freeSinglyLinkedList(SinglyLinkedListNode *head)
{
    while (head != nullptr)
    {
        SinglyLinkedListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// Free doubly linked list memory
void freeDoublyLinkedList(DoublyLinkedListNode *head)
{
    while (head != nullptr)
    {
        DoublyLinkedListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// Print vector
void printVector(const vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
            cout << " ";
    }
    cout << endl;
}

// ============================================================================
// PROBLEM 1 (EASY): Print the Elements of a Linked List
// HackerRank Link: https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem
// ============================================================================
// Difficulty: Easy
// Max Score: 5
//
// Problem Description:
// Given a pointer to the head node of a linked list, print each node's data element,
// one per line. If the head pointer is null (empty list), there is nothing to print.
//
// Function Description:
// Complete the printLinkedList function that takes head of a linked list as parameter.
//
// Input Format:
// The first line contains n, the number of elements in the linked list.
// The next n lines contain one element each, the data for each node.
//
// Output Format:
// Print the integer data for each element of the linked list, one per line.
//
// Sample Input:
// 2
// 16
// 13
//
// Sample Output:
// 16
// 13

vector<int> problem1Solution(SinglyLinkedListNode *head)
{
    // TODO: Implement your solution here
    // Hint: Traverse the linked list and collect all data values
    vector<int> result;
    SinglyLinkedListNode *current = head;
    while (current != nullptr)
    {
        result.push_back(current->data);
        current = current->next;
    }

    return result;
}

// ============================================================================
// PROBLEM 2 (EASY): Insert a Node at the Tail of a Linked List
// HackerRank Link: https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem
// ============================================================================
// Difficulty: Easy
// Max Score: 5
//
// Problem Description:
// You are given the pointer to the head node of a linked list and an integer to add
// to the list. Create a new node with the given integer. Insert this node at the tail
// of the linked list and return the head node of the linked list.
//
// The head pointer given may be null meaning that the initial list is empty.
//
// Function Description:
// Complete the insertNodeAtTail function that takes head and data as parameters.
//
// Input Format:
// The first line contains n, the number of elements to be inserted.
// The next n lines contain one element each to be inserted at the tail.
//
// Output Format:
// Return a reference to the head of the linked list.
//
// Sample Input:
// 5
// 141
// 302
// 164
// 530
// 474
//
// Sample Output:
// 141 302 164 530 474

SinglyLinkedListNode *problem2Solution(SinglyLinkedListNode *head, int data)
{
    // TODO: Implement your solution here
    // Hint: Create a new node and insert it at the end of the list
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    if (head == nullptr)
    {
        head = newNode;
        return head;
    };
    SinglyLinkedListNode *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

// ============================================================================
// PROBLEM 3 (EASY): Insert a Node at a Specific Position
// HackerRank Link: https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem
// ============================================================================
// Difficulty: Easy
// Max Score: 5
//
// Problem Description:
// Given the pointer to the head node of a linked list and an integer to insert at a
// certain position, create a new node with the given integer as its data attribute,
// insert this node at the desired position and return the head node.
//
// A position of 0 indicates head, a position of 1 indicates one node away from the head and so on.
//
// Function Description:
// Complete the insertNodeAtPosition function that takes head, data, and position as parameters.
//
// Input Format:
// The first line contains n, the number of elements in the linked list.
// Each of the next n lines contains an integer representing a node's data.
// The last line contains position, the position where the new node should be inserted.
//
// Output Format:
// Return the head of the linked list after insertion.
//
// Sample Input:
// 3
// 16
// 13
// 7
// 1
// 2
//
// Sample Output:
// 16 13 1 7

SinglyLinkedListNode *problem3Solution(SinglyLinkedListNode *head, int data, int position)
{
    // TODO: Implement your solution here
    // Hint: Traverse to position-1, then insert the new node
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    if (head == nullptr)
    {
        head = newNode;
        return head;
    }
    SinglyLinkedListNode *prev = nullptr;
    SinglyLinkedListNode *current = head;
    if (position == 0)
    {
        head = newNode;
        newNode->next = current;
    }
    else
    {
        while (position)
        {
            prev = current;
            current = current->next;
            position--;
        }
        prev->next = newNode;
        newNode->next = current;
    }

    return head;
}

// ============================================================================
// PROBLEM 4 (EASY): Delete a Node
// HackerRank Link: https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem
// ============================================================================
// Difficulty: Easy
// Max Score: 5
//
// Problem Description:
// Delete the node at a given position in a linked list and return a reference to the
// head node. The head is at position 0. If you're given position 0, delete the head.
//
// Function Description:
// Complete the deleteNode function that takes head and position as parameters.
//
// Input Format:
// The first line contains an integer n, the number of elements in the linked list.
// Each of the next n lines contains an integer, the node data values.
// The last line contains an integer position, the position to delete.
//
// Output Format:
// Return a reference to the head of the modified linked list.
//
// Sample Input:
// 8
// 20
// 6
// 2
// 19
// 7
// 4
// 15
// 9
// 3
//
// Sample Output:
// 20 6 2 7 4 15 9

SinglyLinkedListNode *problem4Solution(SinglyLinkedListNode *head, int position)
{
    // TODO: Implement your solution here
    // Hint: Handle the case where position is 0 (delete head), otherwise traverse to position-1
    if (head == nullptr)
        return head;
    SinglyLinkedListNode *prevNode = nullptr;
    SinglyLinkedListNode *nextNode = head->next;
    SinglyLinkedListNode *current = head;
    if (position == 0)
    {
        delete current;
        head = nextNode;
        return head;
    }
    while (position)
    {
        prevNode = current;
        current = current->next;
        nextNode = nextNode->next;
        position--;
    }
    if (current == nullptr)
    {
        return head;
    }
    prevNode->next = nextNode;
    delete current;

    return head;
}

// ============================================================================
// PROBLEM 5 (MEDIUM): Reverse a Linked List
// HackerRank Link: https://www.hackerrank.com/challenges/reverse-a-linked-list/problem
// ============================================================================
// Difficulty: Easy (but requires careful pointer manipulation)
// Max Score: 5
//
// Problem Description:
// Given the pointer to the head node of a linked list, change the next pointers of
// the nodes so that their order is reversed. The head pointer given may be null
// meaning that the initial list is empty.
//
// Function Description:
// Complete the reverse function that takes head as parameter.
//
// Input Format:
// The first line contains an integer t, the number of test cases.
// For each test case:
//   - First line contains an integer n, the number of elements in the linked list.
//   - Each of the next n lines contains an integer, the data values of elements.
//
// Output Format:
// Return a reference to the head of the reversed list.
//
// Sample Input:
// 1
// 5
// 1
// 2
// 3
// 4
// 5
//
// Sample Output:
// 5 4 3 2 1

SinglyLinkedListNode *problem5Solution(SinglyLinkedListNode *head)
{
    // TODO: Implement your solution here
    // Hint: Use three pointers: prev, current, and next
    if (head == nullptr)
        return head;
    if (head->next == nullptr)
        return head;
    SinglyLinkedListNode *prev = nullptr;
    SinglyLinkedListNode *current = head;
    SinglyLinkedListNode *next = head->next;
    while (current != nullptr)
    {
        current->next = prev;
        prev = current;
        current = next;
        next = next != nullptr ? next->next : nullptr;
    }

    return prev;
}

// ============================================================================
// PROBLEM 6 (MEDIUM): Compare Two Linked Lists
// HackerRank Link: https://www.hackerrank.com/challenges/compare-two-linked-lists/problem
// ============================================================================
// Difficulty: Easy
// Max Score: 5
//
// Problem Description:
// You're given the pointer to the head nodes of two linked lists. Compare the data in
// the nodes of the linked lists to check if they are equal. If all data attributes are
// equal and the lists are the same length, return 1. Otherwise, return 0.
//
// Function Description:
// Complete the compare_lists function that takes two head pointers as parameters.
//
// Input Format:
// The first line contains t, the number of test cases.
// For each test case:
//   - First line contains n, the number of nodes in the first linked list.
//   - Next n lines contain an integer each, the data for each node.
//   - Next line contains m, the number of nodes in the second linked list.
//   - Next m lines contain an integer each, the data for each node.
//
// Output Format:
// Return 1 if lists are equal, 0 otherwise.
//
// Sample Input:
// 2
// 2
// 1
// 2
// 1
// 1
// 2
// 1
// 2
// 2
// 1
// 2
//
// Sample Output:
// 0
// 1

bool problem6Solution(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    // TODO: Implement your solution here
    // Hint: Traverse both lists simultaneously and compare data and lengths
    SinglyLinkedListNode *current1 = head1;
    SinglyLinkedListNode *current2 = head2;
    if (head1 == nullptr && head2 == nullptr)
        return true;

    if (head1 == nullptr && head2 != nullptr)
    {
        return false;
    }
    else if (head1 != nullptr && head2 == nullptr)
    {
        return false;
    }
    

    while (current1 != nullptr && current2 != nullptr)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1 == nullptr && current2 != nullptr)
    {
        return false ;
    } else if (current1 != nullptr && current2 == nullptr)
    {
        return false ;
    }
    
    
    return true;
}

// ============================================================================
// PROBLEM 7 (MEDIUM): Merge Two Sorted Linked Lists
// HackerRank Link: https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem
// ============================================================================
// Difficulty: Easy
// Max Score: 5
//
// Problem Description:
// Given pointers to the heads of two sorted linked lists, merge them into a single,
// sorted linked list. Either head pointer may be null meaning that the corresponding
// list is empty.
//
// Function Description:
// Complete the mergeLists function that takes two head pointers as parameters.
//
// Input Format:
// The first line contains t, the number of test cases.
// For each test case:
//   - First line contains an integer n, the length of the first linked list.
//   - Next n lines contain an integer each, the elements of the linked list.
//   - Next line contains an integer m, the length of the second linked list.
//   - Next m lines contain an integer each, the elements of the second linked list.
//
// Output Format:
// Return a pointer to the head of the merged list.
//
// Sample Input:
// 1
// 3
// 1
// 2
// 3
// 2
// 3
// 4
//
// Sample Output:
// 1 2 3 3 4

SinglyLinkedListNode *problem7Solution(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    // TODO: Implement your solution here
    // Hint: Use a dummy node and compare elements from both lists
    return nullptr;
}

// ============================================================================
// PROBLEM 8 (HARD): Find Merge Point of Two Lists
// HackerRank Link: https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem
// ============================================================================
// Difficulty: Medium
// Max Score: 5
//
// Problem Description:
// Given pointers to the head nodes of 2 linked lists that merge together at some point,
// find the node where the two lists merge. The merge point is where both lists point to
// the same node, i.e. they reference the same memory location. It is guaranteed that the
// two head nodes will be different, and neither will be NULL.
//
// Function Description:
// Complete the findMergeNode function that takes two head pointers as parameters.
//
// Input Format:
// The first line contains t, the number of test cases.
// For each test case:
//   - First line contains an integer, index, the node number where merge occurs.
//   - Next line contains n1, the number of nodes in the first list.
//   - Next n1 lines contain integers, the data values for each node.
//   - Next line contains n2, the number of nodes in the second list.
//   - Next n2 lines contain integers, the data values for each node.
//
// Output Format:
// Return the integer value of the data attribute of the node where the merge occurs.
//
// Sample Input:
// 1
// 1 [Merge at position 1]
// 2
// 1
// 2
// 1
// 3
//
// Sample Output:
// 2

int problem8Solution(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    // TODO: Implement your solution here
    // Hint: Calculate lengths and align the pointers, or use the two-pointer technique
    return -1;
}

// ============================================================================
// PROBLEM 9 (HARD): Reverse a Doubly Linked List
// HackerRank Link: https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem
// ============================================================================
// Difficulty: Easy (for doubly linked list)
// Max Score: 5
//
// Problem Description:
// Given the pointer to the head node of a doubly linked list, reverse the order of the
// nodes in place. That is, change the next and prev pointers of the nodes so that the
// direction of the list is reversed. Return a reference to the head node of the reversed list.
//
// Note: The head node might be NULL to indicate that the list is empty.
//
// Function Description:
// Complete the reverse function that takes head of a doubly linked list as parameter.
//
// Input Format:
// The first line contains t, the number of test cases.
// For each test case:
//   - First line contains n, the number of elements in the linked list.
//   - Next n lines contain an integer each denoting an element of the linked list.
//
// Output Format:
// Return a reference to the head of the reversed list.
//
// Sample Input:
// 1
// 4
// 1
// 2
// 3
// 4
//
// Sample Output:
// 4 3 2 1

DoublyLinkedListNode *problem9Solution(DoublyLinkedListNode *head)
{
    // TODO: Implement your solution here
    // Hint: Swap next and prev pointers for each node
    return head;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1()
{
    cout << "\n=== Testing Problem 1: Print the Elements of a Linked List ===" << endl;

    // Test Case 1: Normal case
    vector<int> arr1 = {16, 13};
    SinglyLinkedListNode *head1 = createSinglyLinkedList(arr1);
    vector<int> expected1 = {16, 13};
    cout << "Test 1 - Input: 16 -> 13 -> NULL" << endl;
    vector<int> result1 = problem1Solution(head1);
    cout << "Expected: ";
    printVector(expected1);
    cout << "Got:      ";
    printVector(result1);
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head1);

    // Test Case 2: Single element
    vector<int> arr2 = {1};
    SinglyLinkedListNode *head2 = createSinglyLinkedList(arr2);
    vector<int> expected2 = {1};
    cout << "\nTest 2 - Input: 1 -> NULL" << endl;
    vector<int> result2 = problem1Solution(head2);
    cout << "Expected: ";
    printVector(expected2);
    cout << "Got:      ";
    printVector(result2);
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head2);

    // Test Case 3: Empty list
    SinglyLinkedListNode *head3 = nullptr;
    vector<int> expected3 = {};
    cout << "\nTest 3 - Input: NULL" << endl;
    vector<int> result3 = problem1Solution(head3);
    cout << "Expected: ";
    printVector(expected3);
    cout << "Got:      ";
    printVector(result3);
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Multiple elements
    vector<int> arr4 = {3, 7, 2, 9, 5};
    SinglyLinkedListNode *head4 = createSinglyLinkedList(arr4);
    vector<int> expected4 = {3, 7, 2, 9, 5};
    cout << "\nTest 4 - Input: 3 -> 7 -> 2 -> 9 -> 5 -> NULL" << endl;
    vector<int> result4 = problem1Solution(head4);
    cout << "Expected: ";
    printVector(expected4);
    cout << "Got:      ";
    printVector(result4);
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head4);

    // Test Case 5: Large list
    vector<int> arr5 = {10, 20, 30, 40, 50, 60, 70};
    SinglyLinkedListNode *head5 = createSinglyLinkedList(arr5);
    vector<int> expected5 = {10, 20, 30, 40, 50, 60, 70};
    cout << "\nTest 5 - Input: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> NULL" << endl;
    vector<int> result5 = problem1Solution(head5);
    cout << "Expected: ";
    printVector(expected5);
    cout << "Got:      ";
    printVector(result5);
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head5);
}

void testProblem2()
{
    cout << "\n=== Testing Problem 2: Insert a Node at the Tail ===" << endl;

    // Test Case 1: Insert into empty list
    SinglyLinkedListNode *head1 = nullptr;
    head1 = problem2Solution(head1, 141);
    vector<int> expected1 = {141};
    cout << "Test 1 - Insert 141 into empty list" << endl;
    vector<int> result1 = singlyLinkedListToVector(head1);
    cout << "Expected: ";
    printVector(expected1);
    cout << "Got:      ";
    printVector(result1);
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head1);

    // Test Case 2: Insert multiple elements
    SinglyLinkedListNode *head2 = nullptr;
    head2 = problem2Solution(head2, 141);
    head2 = problem2Solution(head2, 302);
    head2 = problem2Solution(head2, 164);
    vector<int> expected2 = {141, 302, 164};
    cout << "\nTest 2 - Insert 141, 302, 164" << endl;
    vector<int> result2 = singlyLinkedListToVector(head2);
    cout << "Expected: ";
    printVector(expected2);
    cout << "Got:      ";
    printVector(result2);
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head2);

    // Test Case 3: Insert into single element list
    SinglyLinkedListNode *head3 = createSinglyLinkedList({5});
    head3 = problem2Solution(head3, 10);
    vector<int> expected3 = {5, 10};
    cout << "\nTest 3 - Insert 10 into list with 5" << endl;
    vector<int> result3 = singlyLinkedListToVector(head3);
    cout << "Expected: ";
    printVector(expected3);
    cout << "Got:      ";
    printVector(result3);
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head3);

    // Test Case 4: Insert multiple times
    SinglyLinkedListNode *head4 = nullptr;
    for (int i = 1; i <= 5; i++)
    {
        head4 = problem2Solution(head4, i * 10);
    }
    vector<int> expected4 = {10, 20, 30, 40, 50};
    cout << "\nTest 4 - Insert 10, 20, 30, 40, 50" << endl;
    vector<int> result4 = singlyLinkedListToVector(head4);
    cout << "Expected: ";
    printVector(expected4);
    cout << "Got:      ";
    printVector(result4);
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head4);

    // Test Case 5: Insert negative numbers
    SinglyLinkedListNode *head5 = createSinglyLinkedList({-5, -10});
    head5 = problem2Solution(head5, -15);
    vector<int> expected5 = {-5, -10, -15};
    cout << "\nTest 5 - Insert -15 into list with -5, -10" << endl;
    vector<int> result5 = singlyLinkedListToVector(head5);
    cout << "Expected: ";
    printVector(expected5);
    cout << "Got:      ";
    printVector(result5);
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head5);
}

void testProblem3()
{
    cout << "\n=== Testing Problem 3: Insert a Node at a Specific Position ===" << endl;

    // Test Case 1: Insert at beginning
    SinglyLinkedListNode *head1 = createSinglyLinkedList({16, 13, 7});
    head1 = problem3Solution(head1, 1, 0);
    vector<int> expected1 = {1, 16, 13, 7};
    cout << "Test 1 - Insert 1 at position 0 in [16, 13, 7]" << endl;
    vector<int> result1 = singlyLinkedListToVector(head1);
    cout << "Expected: ";
    printVector(expected1);
    cout << "Got:      ";
    printVector(result1);
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head1);

    // Test Case 2: Insert in middle
    SinglyLinkedListNode *head2 = createSinglyLinkedList({16, 13, 7});
    head2 = problem3Solution(head2, 1, 2);
    vector<int> expected2 = {16, 13, 1, 7};
    cout << "\nTest 2 - Insert 1 at position 2 in [16, 13, 7]" << endl;
    vector<int> result2 = singlyLinkedListToVector(head2);
    cout << "Expected: ";
    printVector(expected2);
    cout << "Got:      ";
    printVector(result2);
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head2);

    // Test Case 3: Insert at end
    SinglyLinkedListNode *head3 = createSinglyLinkedList({16, 13, 7});
    head3 = problem3Solution(head3, 1, 3);
    vector<int> expected3 = {16, 13, 7, 1};
    cout << "\nTest 3 - Insert 1 at position 3 in [16, 13, 7]" << endl;
    vector<int> result3 = singlyLinkedListToVector(head3);
    cout << "Expected: ";
    printVector(expected3);
    cout << "Got:      ";
    printVector(result3);
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head3);

    // Test Case 4: Insert in single element list
    SinglyLinkedListNode *head4 = createSinglyLinkedList({5});
    head4 = problem3Solution(head4, 10, 1);
    vector<int> expected4 = {5, 10};
    cout << "\nTest 4 - Insert 10 at position 1 in [5]" << endl;
    vector<int> result4 = singlyLinkedListToVector(head4);
    cout << "Expected: ";
    printVector(expected4);
    cout << "Got:      ";
    printVector(result4);
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head4);

    // Test Case 5: Insert at position 1
    SinglyLinkedListNode *head5 = createSinglyLinkedList({1, 2, 3, 4});
    head5 = problem3Solution(head5, 99, 1);
    vector<int> expected5 = {1, 99, 2, 3, 4};
    cout << "\nTest 5 - Insert 99 at position 1 in [1, 2, 3, 4]" << endl;
    vector<int> result5 = singlyLinkedListToVector(head5);
    cout << "Expected: ";
    printVector(expected5);
    cout << "Got:      ";
    printVector(result5);
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head5);
}

void testProblem4()
{
    cout << "\n=== Testing Problem 4: Delete a Node ===" << endl;

    // Test Case 1: Delete from middle
    SinglyLinkedListNode *head1 = createSinglyLinkedList({20, 6, 2, 19, 7, 4, 15, 9});
    head1 = problem4Solution(head1, 3);
    vector<int> expected1 = {20, 6, 2, 7, 4, 15, 9};
    cout << "Test 1 - Delete position 3 from [20, 6, 2, 19, 7, 4, 15, 9]" << endl;
    vector<int> result1 = singlyLinkedListToVector(head1);
    cout << "Expected: ";
    printVector(expected1);
    cout << "Got:      ";
    printVector(result1);
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head1);

    // Test Case 2: Delete head
    SinglyLinkedListNode *head2 = createSinglyLinkedList({1, 2, 3, 4, 5});
    head2 = problem4Solution(head2, 0);
    vector<int> expected2 = {2, 3, 4, 5};
    cout << "\nTest 2 - Delete position 0 from [1, 2, 3, 4, 5]" << endl;
    vector<int> result2 = singlyLinkedListToVector(head2);
    cout << "Expected: ";
    printVector(expected2);
    cout << "Got:      ";
    printVector(result2);
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head2);

    // Test Case 3: Delete last element
    SinglyLinkedListNode *head3 = createSinglyLinkedList({1, 2, 3});
    head3 = problem4Solution(head3, 2);
    vector<int> expected3 = {1, 2};
    cout << "\nTest 3 - Delete position 2 from [1, 2, 3]" << endl;
    vector<int> result3 = singlyLinkedListToVector(head3);
    cout << "Expected: ";
    printVector(expected3);
    cout << "Got:      ";
    printVector(result3);
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head3);

    // Test Case 4: Delete from two element list
    SinglyLinkedListNode *head4 = createSinglyLinkedList({10, 20});
    head4 = problem4Solution(head4, 1);
    vector<int> expected4 = {10};
    cout << "\nTest 4 - Delete position 1 from [10, 20]" << endl;
    vector<int> result4 = singlyLinkedListToVector(head4);
    cout << "Expected: ";
    printVector(expected4);
    cout << "Got:      ";
    printVector(result4);
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head4);

    // Test Case 5: Delete first position
    SinglyLinkedListNode *head5 = createSinglyLinkedList({5, 10, 15, 20});
    head5 = problem4Solution(head5, 1);
    vector<int> expected5 = {5, 15, 20};
    cout << "\nTest 5 - Delete position 1 from [5, 10, 15, 20]" << endl;
    vector<int> result5 = singlyLinkedListToVector(head5);
    cout << "Expected: ";
    printVector(expected5);
    cout << "Got:      ";
    printVector(result5);
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head5);
}

void testProblem5()
{
    cout << "\n=== Testing Problem 5: Reverse a Linked List ===" << endl;

    // Test Case 1: Normal case
    SinglyLinkedListNode *head1 = createSinglyLinkedList({1, 2, 3, 4, 5});
    head1 = problem5Solution(head1);
    vector<int> expected1 = {5, 4, 3, 2, 1};
    cout << "Test 1 - Reverse [1, 2, 3, 4, 5]" << endl;
    vector<int> result1 = singlyLinkedListToVector(head1);
    cout << "Expected: ";
    printVector(expected1);
    cout << "Got:      ";
    printVector(result1);
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head1);

    // Test Case 2: Single element
    SinglyLinkedListNode *head2 = createSinglyLinkedList({1});
    head2 = problem5Solution(head2);
    vector<int> expected2 = {1};
    cout << "\nTest 2 - Reverse [1]" << endl;
    vector<int> result2 = singlyLinkedListToVector(head2);
    cout << "Expected: ";
    printVector(expected2);
    cout << "Got:      ";
    printVector(result2);
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head2);

    // Test Case 3: Two elements
    SinglyLinkedListNode *head3 = createSinglyLinkedList({1, 2});
    head3 = problem5Solution(head3);
    vector<int> expected3 = {2, 1};
    cout << "\nTest 3 - Reverse [1, 2]" << endl;
    vector<int> result3 = singlyLinkedListToVector(head3);
    cout << "Expected: ";
    printVector(expected3);
    cout << "Got:      ";
    printVector(result3);
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head3);

    // Test Case 4: Empty list
    SinglyLinkedListNode *head4 = nullptr;
    head4 = problem5Solution(head4);
    vector<int> expected4 = {};
    cout << "\nTest 4 - Reverse []" << endl;
    vector<int> result4 = singlyLinkedListToVector(head4);
    cout << "Expected: ";
    printVector(expected4);
    cout << "Got:      ";
    printVector(result4);
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Longer list
    SinglyLinkedListNode *head5 = createSinglyLinkedList({10, 20, 30, 40, 50, 60});
    head5 = problem5Solution(head5);
    vector<int> expected5 = {60, 50, 40, 30, 20, 10};
    cout << "\nTest 5 - Reverse [10, 20, 30, 40, 50, 60]" << endl;
    vector<int> result5 = singlyLinkedListToVector(head5);
    cout << "Expected: ";
    printVector(expected5);
    cout << "Got:      ";
    printVector(result5);
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head5);

    // Test Case 6: Negative numbers
    SinglyLinkedListNode *head6 = createSinglyLinkedList({-5, -3, -1, 0, 2});
    head6 = problem5Solution(head6);
    vector<int> expected6 = {2, 0, -1, -3, -5};
    cout << "\nTest 6 - Reverse [-5, -3, -1, 0, 2]" << endl;
    vector<int> result6 = singlyLinkedListToVector(head6);
    cout << "Expected: ";
    printVector(expected6);
    cout << "Got:      ";
    printVector(result6);
    cout << "Result: " << (result6 == expected6 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head6);
}

void testProblem6()
{
    cout << "\n=== Testing Problem 6: Compare Two Linked Lists ===" << endl;

    // Test Case 1: Different lengths
    SinglyLinkedListNode *head1a = createSinglyLinkedList({1, 2});
    SinglyLinkedListNode *head1b = createSinglyLinkedList({1});
    cout << "Test 1 - Compare [1, 2] and [1]" << endl;
    bool result1 = problem6Solution(head1a, head1b);
    cout << "Expected: 0 (false), Got: " << result1 << endl;
    cout << "Result: " << (result1 == false ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head1a);
    freeSinglyLinkedList(head1b);

    // Test Case 2: Same lists
    SinglyLinkedListNode *head2a = createSinglyLinkedList({1, 2});
    SinglyLinkedListNode *head2b = createSinglyLinkedList({1, 2});
    cout << "\nTest 2 - Compare [1, 2] and [1, 2]" << endl;
    bool result2 = problem6Solution(head2a, head2b);
    cout << "Expected: 1 (true), Got: " << result2 << endl;
    cout << "Result: " << (result2 == true ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head2a);
    freeSinglyLinkedList(head2b);

    // Test Case 3: Different data
    SinglyLinkedListNode *head3a = createSinglyLinkedList({1, 2, 3});
    SinglyLinkedListNode *head3b = createSinglyLinkedList({1, 2, 4});
    cout << "\nTest 3 - Compare [1, 2, 3] and [1, 2, 4]" << endl;
    bool result3 = problem6Solution(head3a, head3b);
    cout << "Expected: 0 (false), Got: " << result3 << endl;
    cout << "Result: " << (result3 == false ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head3a);
    freeSinglyLinkedList(head3b);

    // Test Case 4: Both empty
    SinglyLinkedListNode *head4a = nullptr;
    SinglyLinkedListNode *head4b = nullptr;
    cout << "\nTest 4 - Compare [] and []" << endl;
    bool result4 = problem6Solution(head4a, head4b);
    cout << "Expected: 1 (true), Got: " << result4 << endl;
    cout << "Result: " << (result4 == true ? "PASS" : "FAIL") << endl;

    // Test Case 5: Single element same
    SinglyLinkedListNode *head5a = createSinglyLinkedList({5});
    SinglyLinkedListNode *head5b = createSinglyLinkedList({5});
    cout << "\nTest 5 - Compare [5] and [5]" << endl;
    bool result5 = problem6Solution(head5a, head5b);
    cout << "Expected: 1 (true), Got: " << result5 << endl;
    cout << "Result: " << (result5 == true ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head5a);
    freeSinglyLinkedList(head5b);

    // Test Case 6: Longer identical lists
    SinglyLinkedListNode *head6a = createSinglyLinkedList({10, 20, 30, 40, 50});
    SinglyLinkedListNode *head6b = createSinglyLinkedList({10, 20, 30, 40, 50});
    cout << "\nTest 6 - Compare [10, 20, 30, 40, 50] and [10, 20, 30, 40, 50]" << endl;
    bool result6 = problem6Solution(head6a, head6b);
    cout << "Expected: 1 (true), Got: " << result6 << endl;
    cout << "Result: " << (result6 == true ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head6a);
    freeSinglyLinkedList(head6b);
}

void testProblem7()
{
    cout << "\n=== Testing Problem 7: Merge Two Sorted Linked Lists ===" << endl;

    // Test Case 1: Normal case
    SinglyLinkedListNode *head1a = createSinglyLinkedList({1, 2, 3});
    SinglyLinkedListNode *head1b = createSinglyLinkedList({3, 4});
    SinglyLinkedListNode *merged1 = problem7Solution(head1a, head1b);
    vector<int> expected1 = {1, 2, 3, 3, 4};
    cout << "Test 1 - Merge [1, 2, 3] and [3, 4]" << endl;
    vector<int> result1 = singlyLinkedListToVector(merged1);
    cout << "Expected: ";
    printVector(expected1);
    cout << "Got:      ";
    printVector(result1);
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(merged1);

    // Test Case 2: One empty list
    SinglyLinkedListNode *head2a = createSinglyLinkedList({1, 2, 3});
    SinglyLinkedListNode *head2b = nullptr;
    SinglyLinkedListNode *merged2 = problem7Solution(head2a, head2b);
    vector<int> expected2 = {1, 2, 3};
    cout << "\nTest 2 - Merge [1, 2, 3] and []" << endl;
    vector<int> result2 = singlyLinkedListToVector(merged2);
    cout << "Expected: ";
    printVector(expected2);
    cout << "Got:      ";
    printVector(result2);
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(merged2);

    // Test Case 3: Both empty
    SinglyLinkedListNode *head3a = nullptr;
    SinglyLinkedListNode *head3b = nullptr;
    SinglyLinkedListNode *merged3 = problem7Solution(head3a, head3b);
    vector<int> expected3 = {};
    cout << "\nTest 3 - Merge [] and []" << endl;
    vector<int> result3 = singlyLinkedListToVector(merged3);
    cout << "Expected: ";
    printVector(expected3);
    cout << "Got:      ";
    printVector(result3);
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;

    // Test Case 4: Interleaved elements
    SinglyLinkedListNode *head4a = createSinglyLinkedList({1, 3, 5, 7});
    SinglyLinkedListNode *head4b = createSinglyLinkedList({2, 4, 6, 8});
    SinglyLinkedListNode *merged4 = problem7Solution(head4a, head4b);
    vector<int> expected4 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "\nTest 4 - Merge [1, 3, 5, 7] and [2, 4, 6, 8]" << endl;
    vector<int> result4 = singlyLinkedListToVector(merged4);
    cout << "Expected: ";
    printVector(expected4);
    cout << "Got:      ";
    printVector(result4);
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(merged4);

    // Test Case 5: All elements from one list first
    SinglyLinkedListNode *head5a = createSinglyLinkedList({1, 2, 3});
    SinglyLinkedListNode *head5b = createSinglyLinkedList({10, 20, 30});
    SinglyLinkedListNode *merged5 = problem7Solution(head5a, head5b);
    vector<int> expected5 = {1, 2, 3, 10, 20, 30};
    cout << "\nTest 5 - Merge [1, 2, 3] and [10, 20, 30]" << endl;
    vector<int> result5 = singlyLinkedListToVector(merged5);
    cout << "Expected: ";
    printVector(expected5);
    cout << "Got:      ";
    printVector(result5);
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(merged5);

    // Test Case 6: Single elements
    SinglyLinkedListNode *head6a = createSinglyLinkedList({5});
    SinglyLinkedListNode *head6b = createSinglyLinkedList({3});
    SinglyLinkedListNode *merged6 = problem7Solution(head6a, head6b);
    vector<int> expected6 = {3, 5};
    cout << "\nTest 6 - Merge [5] and [3]" << endl;
    vector<int> result6 = singlyLinkedListToVector(merged6);
    cout << "Expected: ";
    printVector(expected6);
    cout << "Got:      ";
    printVector(result6);
    cout << "Result: " << (result6 == expected6 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(merged6);
}

void testProblem8()
{
    cout << "\n=== Testing Problem 8: Find Merge Point of Two Lists ===" << endl;

    // Helper function to create merging lists
    auto createMergingLists = [](const vector<int> &list1Data, const vector<int> &list2Data,
                                 const vector<int> &mergeData, int mergePos)
        -> pair<SinglyLinkedListNode *, SinglyLinkedListNode *>
    {
        // Create the common tail
        SinglyLinkedListNode *mergeTail = createSinglyLinkedList(mergeData);

        // Create first list
        SinglyLinkedListNode *head1 = createSinglyLinkedList(list1Data);
        SinglyLinkedListNode *tail1 = head1;
        while (tail1->next != nullptr)
            tail1 = tail1->next;
        tail1->next = mergeTail;

        // Create second list
        SinglyLinkedListNode *head2 = createSinglyLinkedList(list2Data);
        SinglyLinkedListNode *tail2 = head2;
        while (tail2->next != nullptr)
            tail2 = tail2->next;
        tail2->next = mergeTail;

        return {head1, head2};
    };

    // Test Case 1: Merge at node with value 2
    auto [head1a, head1b] = createMergingLists({1}, {3}, {2}, 1);
    cout << "Test 1 - Lists: [1] and [3] merge at node with value 2" << endl;
    int result1 = problem8Solution(head1a, head1b);
    cout << "Expected: 2, Got: " << result1 << endl;
    cout << "Result: " << (result1 == 2 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head1a);
    delete head1b; // Only delete head, rest is shared and already freed

    // Test Case 2: Merge at first common node
    auto [head2a, head2b] = createMergingLists({1, 2}, {3, 4}, {5, 6, 7}, 2);
    cout << "\nTest 2 - Lists merge at node with value 5" << endl;
    int result2 = problem8Solution(head2a, head2b);
    cout << "Expected: 5, Got: " << result2 << endl;
    cout << "Result: " << (result2 == 5 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head2a);
    delete head2b;

    // Test Case 3: Different length lists
    auto [head3a, head3b] = createMergingLists({1, 2, 3}, {4}, {10, 20}, 3);
    cout << "\nTest 3 - Lists [1,2,3] and [4] merge at node with value 10" << endl;
    int result3 = problem8Solution(head3a, head3b);
    cout << "Expected: 10, Got: " << result3 << endl;
    cout << "Result: " << (result3 == 10 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head3a);
    delete head3b;

    // Test Case 4: Long common tail
    auto [head4a, head4b] = createMergingLists({1}, {2}, {3, 4, 5, 6, 7, 8}, 1);
    cout << "\nTest 4 - Lists merge at node with value 3 (long tail)" << endl;
    int result4 = problem8Solution(head4a, head4b);
    cout << "Expected: 3, Got: " << result4 << endl;
    cout << "Result: " << (result4 == 3 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head4a);
    delete head4b;

    // Test Case 5: Single node merge
    auto [head5a, head5b] = createMergingLists({10, 20}, {30, 40, 50}, {100}, 2);
    cout << "\nTest 5 - Lists merge at single node with value 100" << endl;
    int result5 = problem8Solution(head5a, head5b);
    cout << "Expected: 100, Got: " << result5 << endl;
    cout << "Result: " << (result5 == 100 ? "PASS" : "FAIL") << endl;
    freeSinglyLinkedList(head5a);
    delete head5b;
}

void testProblem9()
{
    cout << "\n=== Testing Problem 9: Reverse a Doubly Linked List ===" << endl;

    // Test Case 1: Normal case
    DoublyLinkedListNode *head1 = createDoublyLinkedList({1, 2, 3, 4});
    head1 = problem9Solution(head1);
    vector<int> expected1 = {4, 3, 2, 1};
    cout << "Test 1 - Reverse [1, 2, 3, 4]" << endl;
    vector<int> result1 = doublyLinkedListToVector(head1);
    cout << "Expected: ";
    printVector(expected1);
    cout << "Got:      ";
    printVector(result1);
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << endl;
    freeDoublyLinkedList(head1);

    // Test Case 2: Single element
    DoublyLinkedListNode *head2 = createDoublyLinkedList({1});
    head2 = problem9Solution(head2);
    vector<int> expected2 = {1};
    cout << "\nTest 2 - Reverse [1]" << endl;
    vector<int> result2 = doublyLinkedListToVector(head2);
    cout << "Expected: ";
    printVector(expected2);
    cout << "Got:      ";
    printVector(result2);
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << endl;
    freeDoublyLinkedList(head2);

    // Test Case 3: Two elements
    DoublyLinkedListNode *head3 = createDoublyLinkedList({5, 10});
    head3 = problem9Solution(head3);
    vector<int> expected3 = {10, 5};
    cout << "\nTest 3 - Reverse [5, 10]" << endl;
    vector<int> result3 = doublyLinkedListToVector(head3);
    cout << "Expected: ";
    printVector(expected3);
    cout << "Got:      ";
    printVector(result3);
    cout << "Result: " << (result3 == expected3 ? "PASS" : "FAIL") << endl;
    freeDoublyLinkedList(head3);

    // Test Case 4: Empty list
    DoublyLinkedListNode *head4 = nullptr;
    head4 = problem9Solution(head4);
    vector<int> expected4 = {};
    cout << "\nTest 4 - Reverse []" << endl;
    vector<int> result4 = doublyLinkedListToVector(head4);
    cout << "Expected: ";
    printVector(expected4);
    cout << "Got:      ";
    printVector(result4);
    cout << "Result: " << (result4 == expected4 ? "PASS" : "FAIL") << endl;

    // Test Case 5: Longer list
    DoublyLinkedListNode *head5 = createDoublyLinkedList({10, 20, 30, 40, 50, 60});
    head5 = problem9Solution(head5);
    vector<int> expected5 = {60, 50, 40, 30, 20, 10};
    cout << "\nTest 5 - Reverse [10, 20, 30, 40, 50, 60]" << endl;
    vector<int> result5 = doublyLinkedListToVector(head5);
    cout << "Expected: ";
    printVector(expected5);
    cout << "Got:      ";
    printVector(result5);
    cout << "Result: " << (result5 == expected5 ? "PASS" : "FAIL") << endl;
    freeDoublyLinkedList(head5);

    // Test Case 6: Negative numbers
    DoublyLinkedListNode *head6 = createDoublyLinkedList({-5, -3, 0, 3, 5});
    head6 = problem9Solution(head6);
    vector<int> expected6 = {5, 3, 0, -3, -5};
    cout << "\nTest 6 - Reverse [-5, -3, 0, 3, 5]" << endl;
    vector<int> result6 = doublyLinkedListToVector(head6);
    cout << "Expected: ";
    printVector(expected6);
    cout << "Got:      ";
    printVector(result6);
    cout << "Result: " << (result6 == expected6 ? "PASS" : "FAIL") << endl;
    freeDoublyLinkedList(head6);
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    int choice;
    cout << "=== HACKERRANK LINKED LIST PRACTICE PROBLEMS ===" << endl;
    cout << "Choose a problem to test (1-9) or 10 to test all:" << endl;
    cout << "1. Problem 1 (Easy) - Print the Elements of a Linked List" << endl;
    cout << "2. Problem 2 (Easy) - Insert a Node at the Tail" << endl;
    cout << "3. Problem 3 (Easy) - Insert a Node at a Specific Position" << endl;
    cout << "4. Problem 4 (Easy) - Delete a Node" << endl;
    cout << "5. Problem 5 (Medium) - Reverse a Linked List" << endl;
    cout << "6. Problem 6 (Medium) - Compare Two Linked Lists" << endl;
    cout << "7. Problem 7 (Medium) - Merge Two Sorted Linked Lists" << endl;
    cout << "8. Problem 8 (Hard) - Find Merge Point of Two Lists" << endl;
    cout << "9. Problem 9 (Hard) - Reverse a Doubly Linked List" << endl;
    cout << "10. Test All Problems" << endl;
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
        testProblem9();
        break;
    case 10:
        testProblem1();
        testProblem2();
        testProblem3();
        testProblem4();
        testProblem5();
        testProblem6();
        testProblem7();
        testProblem8();
        testProblem9();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}