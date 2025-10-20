#include <iostream>
#include <string>
using namespace std;

// Node structure for linked list
struct Node
{
    int data;
    Node *next;
};

// ============================================================================
// CONCEPT 1: INSERT AT BEGINNING
// ============================================================================

// Problem 1.1 (Easy): Add Single Node at Beginning
// Given a linked list head pointer and a value, insert the value at the beginning.
// Return the new head pointer.
// Example: List: 2->3->4, Value: 1 → Result: 1->2->3->4
// Constraints: Value is any integer, list can be empty
Node *problem1_1(Node *head, int value)
{
    // TODO: Implement inserting a node at the beginning
    // Hint: Create new node, set its next to current head, return new node as new head
    Node *newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

// Problem 1.2 (Easy): Add Multiple Nodes at Beginning
// Given a linked list and an array of values, insert all values at the beginning in order.
// Example: List: 4->5, Values: [1,2,3] → Result: 3->2->1->4->5
// Constraints: Array size 1-10, values are any integers
Node *problem1_2(Node *head, int values[], int size)
{
    // TODO: Implement inserting multiple nodes at the beginning
    // Hint: Loop through array and insert each value at the beginning
    Node *tempNode = head;
    for (int i = 0; i < size; i++)
    {
        Node *newNode = new Node(values[i]);
        newNode->next = tempNode;
        tempNode = newNode;
    }

    return tempNode;
}

// Problem 1.3 (Medium): Insert at Beginning with Duplicate Check
// Insert value at beginning only if it doesn't already exist in the list.
// Return true if inserted, false if duplicate found.
// Example: List: 2->3->4, Value: 2 → No insertion, return false
// Example: List: 2->3->4, Value: 1 → Result: 1->2->3->4, return true
// Constraints: List size 0-100, values are positive integers
bool problem1_3(Node *&head, int value)
{
    // TODO: Implement insert at beginning with duplicate check
    // Hint: First search the list, then insert only if not found
    if (head == nullptr)
    {
        Node *newNode = new Node(value);
        head = newNode;
        return true;
    }
    Node *tempNode = head;
    while (tempNode != nullptr)
    {
        if (tempNode->data == value)
        {
            return false;
        }
        tempNode = tempNode->next;
    }
    Node *insValue = new Node(head->data);
    insValue->next = head->next;
    head->next = insValue;
    head->data = value;
    return true;
}

// ============================================================================
// CONCEPT 2: INSERT AT END
// ============================================================================

// Problem 2.1 (Easy): Add Single Node at End
// Given a linked list and a value, insert the value at the end.
// Example: List: 1->2->3, Value: 4 → Result: 1->2->3->4
// Constraints: Value is any integer, list can be empty
void problem2_1(Node *&head, int value)
{
    // TODO: Implement inserting a node at the end
    // Hint: If empty, set as head. Otherwise traverse to last node and add there
    if (head == nullptr)
    {

        Node *newNode = new Node(value);
        head = newNode;
    }
    else
    {

        Node *tempNode = head;
        while (tempNode->next != nullptr)
        {
            tempNode = tempNode->next;
        }
        Node *newNode = new Node(value);
        tempNode->next = newNode;
    }
}

// Problem 2.2 (Easy): Add Multiple Nodes at End
// Given a linked list and an array of values, insert all values at the end in order.
// Example: List: 1->2, Values: [3,4,5] → Result: 1->2->3->4->5
// Constraints: Array size 1-10, values are any integers
void problem2_2(Node *&head, int values[], int size)
{
    // TODO: Implement inserting multiple nodes at the end
    // Hint: Loop through array and insert each value at the end
    Node *loopHead = new Node(values[0]);
    Node *tempLoopHead = loopHead;
    for (int i = 1; i < size; i++)
    {
        Node *loopNode = new Node(values[i]);
        tempLoopHead->next = loopNode;
        tempLoopHead = tempLoopHead->next;
    }

    if (head == nullptr)
    {
        head = loopHead;
    }
    else
    {
        Node *tempNode = head;
        while (tempNode->next != nullptr)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = loopHead;
    }
}

// Problem 2.3 (Medium): Insert at End with Sum Validation
// Insert value at end only if it doesn't make the sum of all values exceed maxSum.
// Return true if inserted, false if sum would exceed.
// Example: List: 10->20->30 (sum=60), Value: 15, maxSum: 80 → Insert (75≤80), return true
// Example: List: 10->20->30 (sum=60), Value: 25, maxSum: 80 → Don't insert (85>80), return false
// Constraints: maxSum > 0, values are positive integers
bool problem2_3(Node *&head, int value, int maxSum)
{
    // TODO: Implement insert at end with sum validation
    // Hint: Calculate current sum, check if adding value exceeds maxSum, then insert
    Node *current = head;
    int sum = 0;
    bool result = false;
    if (head == nullptr)
    {
        if (value <= maxSum)
        {
            Node *newNode = new Node(value);
            head = newNode;
            result = true;
        }
    }
    else
    {
        sum += head->data;
        while (current->next != nullptr)
        {
            current = current->next;
            sum += current->data;
        }
        if ((sum + value) <= maxSum)
        {
            Node *newNode = new Node(value);
            current->next = newNode;
            result = true;
        }
    }

    return result;
}

// ============================================================================
// CONCEPT 3: INSERT AT POSITION
// ============================================================================

// Problem 3.1 (Easy): Insert at Specific Position (0-indexed)
// Insert value at given position (0 = beginning, n = end).
// Return true if successful, false if position is invalid.
// Example: List: 1->3->4, Position: 1, Value: 2 → Result: 1->2->3->4
// Constraints: Position ≥ 0, list size 0-100
bool problem3_1(Node *&head, int position, int value)
{
    // TODO: Implement inserting at a specific position
    // Hint: Handle position 0 separately, then traverse to position-1 and insert
    Node *current = head;
    bool result = false;
    Node *newNode = new Node(value);
    Node *nextNode;
    if (position == 0)
    {
        if (head != nullptr)
        {
            nextNode = current->next;
            newNode->data = head->data;
            head->next = newNode;
            newNode->next = nextNode;
            head->data = value;
        }
        else
        {
            head = newNode;
        }
        result = true;
    }
    else
    {
        for (int i = 0; i < (position - 1); i++)
        {
            current = current->next;
            if (current == nullptr)
            {
                return false;
            }
        }
        nextNode = current->next;
        current->next = newNode;
        newNode->next = nextNode;
        result = true;
    }

    return result;
}

// Problem 3.2 (Easy): Insert Before First Occurrence
// Insert value before the first occurrence of target value.
// Return true if target found and inserted, false otherwise.
// Example: List: 1->2->4->5, Target: 4, Value: 3 → Result: 1->2->3->4->5
// Constraints: Values are positive integers
bool problem3_2(Node *&head, int target, int value)
{
    // TODO: Implement inserting before first occurrence of target
    // Hint: Traverse keeping track of previous node, insert when target is found
    Node *current = head;
    Node *prevTarget = nullptr;
    Node *newNode = new Node(value);
    bool result = false;
    if (head == nullptr)
        return false;
    if (head->data == target)
    {
        current = current->next;
        newNode->data = head->data;
        head->data = value;
        head->next = newNode;
        newNode->next = current;
        return true;
    }
    while (current != nullptr)
    {
        if (current->data != target)
        {
            prevTarget = current;
            current = current->next;
        }
        else if (current->data == target)
        {
            current = nullptr;
            result = true;
        }
    }
    if (result)
    {
        current = prevTarget->next;
        prevTarget->next = newNode;
        newNode->next = current;
    }

    return result;
}

// Problem 3.3 (Medium): Insert in Sorted Position
// Given a sorted linked list (ascending), insert value maintaining sorted order.
// Example: List: 1->3->5->7, Value: 4 → Result: 1->3->4->5->7
// Constraints: List is sorted in ascending order, values are integers
void problem3_3(Node *&head, int value)
{
    // TODO: Implement inserting in sorted position
    // Hint: Find the position where value should go, then insert there
    Node *newNode = new Node(value);
    Node *current = head;
    if (head == nullptr)
    {
        head = newNode;
        current = nullptr;
    }
    Node *nextNode = head != nullptr ? head->next : nullptr;
    if (head->data >= value)
    {
        newNode->data = head->data;
        head->data = value;
        head->next = newNode;
        newNode->next = nextNode;
        current = nullptr;
    }
    /*  while (current != nullptr )
    {
        cout << "the while is ative" << ((current->data < value ) && (nextNode == nullptr ))<< endl;
        if(current->data <= value && nextNode->data >= value) { // this the problem in last node there no next data the place of condition is the problem
            current->next = newNode;
            newNode->next = nextNode;
            current = nullptr;
        } else if ( nextNode != nullptr) {
            current = current->next;
            nextNode = current->next;
        } else {
            // order = true;
            current->next = newNode;
            current = nullptr;
        }
    } */

    while (current != nullptr)
    {
        /*
          we have two state
              - first the value is be duplicated or less upper between value
              - the value is bigger than all of linked list
          already check the the head mean the head at this point not null and not bigger than the value
          i need to check if the current is less ( that nonsense always will be equal or less )
              - mean there need to check the next
              - and if there the point the next in nullptr mean the value is will the tail
           */
        if (current->next == nullptr)
        {
            current->next = newNode;
            current = nullptr;
        }
        else if (current->data <= value && nextNode->data >= value)
        {
            current->next = newNode;
            newNode->next = nextNode;
            current = nullptr;
        }
        else
        {
            current = current->next;
            nextNode = nextNode->next;
        }
        // *** I learn that i have to plan my progress or will suffer without knowing way that happen
    }
}

// ============================================================================
// CONCEPT 4: DELETE FROM BEGINNING
// ============================================================================

// Problem 4.1 (Easy): Delete First Node
// Delete the first node and return its value. Return -1 if list is empty.
// Example: List: 1->2->3 → Result: 2->3, return 1
// Constraints: Values are positive integers (or 0), -1 indicates empty list
int problem4_1(Node *&head)
{
    // TODO: Implement deleting first node
    // Hint: Save head data, move head to next, delete old head, return saved data
    /*
    start time : 9:29
    end time : 9:42
    */
    Node *nodeToDelete = head;
    if (head == nullptr)
        return -1;
    int data = nodeToDelete->data;
    if (head->next == nullptr)
    {
        head = nullptr;
        return data;
    }
    head = head->next;
    delete nodeToDelete;

    return data;
}

// Problem 4.2 (Easy): Delete N Nodes from Beginning
// Delete first N nodes from the list. Return count of nodes actually deleted.
// Example: List: 1->2->3->4->5, N: 3 → Result: 4->5, return 3
// Example: List: 1->2, N: 5 → Result: empty list, return 2
// Constraints: N ≥ 0
int problem4_2(Node *&head, int n)
{
    // TODO: Implement deleting N nodes from beginning
    // Hint: Loop N times deleting first node, count successful deletions
    /*
    start time : 9:42
    end time : 9:48
    */
    if (head == nullptr)
        return 0;
    int operations = 0;
    Node *nodeToDelete = head;
    for (int i = 0; i < n; i++)
    {
        head = head->next;
        delete nodeToDelete;
        operations++;
        if (head == nullptr)
            n = 0;
        nodeToDelete = head;
    }

    return operations;
}

// Problem 4.3 (Medium): Delete from Beginning Until Condition
// Delete nodes from beginning until you find a node with value > threshold.
// Return count of deleted nodes.
// Example: List: 1->2->3->8->9, Threshold: 5 → Result: 8->9, return 3
// Constraints: Threshold ≥ 0, values are positive integers
int problem4_3(Node *&head, int threshold)
{
    // TODO: Implement deleting from beginning until condition met
    // Hint: Keep deleting first node while its value <= threshold
    /*
    start time : 9:48
    end time : 9:54
    */
    if (head == nullptr)
        return 0;
    int operation = 0;
    Node *nodeToDelete = head;
    while (nodeToDelete != nullptr)
    {
        if (head->data <= threshold)
        {
            operation++;
            head = head->next;
            delete nodeToDelete;
            nodeToDelete = head;
        }
        else
        {
            nodeToDelete = nullptr;
        }
    }
    return operation;
}

// ============================================================================
// CONCEPT 5: DELETE FROM END
// ============================================================================

// Problem 5.1 (Easy): Delete Last Node
// Delete the last node and return its value. Return -1 if list is empty.
// Example: List: 1->2->3 → Result: 1->2, return 3
// Constraints: Values are positive integers (or 0), -1 indicates empty list
int problem5_1(Node *&head)
{
    // TODO: Implement deleting last node
    // Hint: Traverse to second-to-last node, save last node's data, delete last, return data
    /*
    start time : 9:54
    end time : 10:41
    */
    if (head == nullptr)
        return -1;
    Node *nodeToDelete = head;
    int Data = nodeToDelete->data;
    Node *prevData = head;
    if (head->next == nullptr)
    {
        head = nullptr;
        delete nodeToDelete;
        return Data;
    }
    while (nodeToDelete->next != nullptr)
    {
        prevData = nodeToDelete;
        nodeToDelete = nodeToDelete->next;
    }
    Data = nodeToDelete->data;
    if (nodeToDelete->next == nullptr)
    {
        prevData->next = nullptr;
        delete nodeToDelete;
    }
    /*
    in linked list when delete the last node most make ther n-1 node is next to null point or will return undefined behavior
    the linked list is work by node point to address of the next one but you delete the next one what will happen if you try to access to that non memroy address one
    */
    return Data;
}

// Problem 5.2 (Easy): Delete N Nodes from End
// Delete last N nodes from the list. Return count of nodes actually deleted.
// Example: List: 1->2->3->4->5, N: 2 → Result: 1->2->3, return 2
// Constraints: N ≥ 0
int problem5_2(Node *&head, int n)
{
    // TODO: Implement deleting N nodes from end
    // Hint: First count total nodes, then delete from position (total-n)
    /*
    start time : 11:45
    stop in : 12:35
    return in : 14:25
    end time :14:56
    total time : 1h:20min
    */
    if (head == nullptr || n == 0)
        return 0;
    Node *current = head;
    int total = 0;
    while (current != nullptr)
    {
        total++;
        current = current->next;
    }
    current = head;
    int EndNode = total - n <= 0 ? 0 : total - n;
    Node *nextNode;
    if (EndNode != 0)
    {
        for (int i = 1; i < EndNode; i++)
        {
            current = current->next;
        }
        /* code */
        nextNode = current->next;
        current->next = nullptr;
    }
    else
    {
        head = nullptr;
        nextNode = current;
    }
    while (nextNode != nullptr)
    {
        /*
            what i have to do is to store the next next node and delete the next node and update the current next to nullptr
                what i have to do is make store the next node in the current one then store the next node of prev next node
                after that delete the current node
        */
        current = nextNode;
        nextNode = nextNode->next;
        delete current;
    }
    total = total - n <= 0 ? total : n;
    return total;

    /*   while (current != nullptr)
      {
          // nextNode = nextNode->next ;
          // delete current->next;
          // current->next = nullptr;
          // current = nextNode;

          // Assuming this code is inside a loop or function where current and nextNode are defined.

          nextNode = nextNode->next;
          cout << "Moved nextNode to nextNode->next: " << nextNode << " | " << nextNode->data<< endl;

          // WARNING: Deleting current->next here is incorrect — it's already nullptr!
          // So this line is not doing anything useful, and may cause undefined behavior
          delete current->next;
          cout << "Attempted to delete current->next ." << endl;


          current->next = nullptr;
          cout << "Set current->next to nullptr." << current->next << endl;


          current = nextNode;
          // current->next = nextNode->next;
          cout << "Moved current to nextNode: " << current << " | " << current->data << " | " << (current->next != nullptr ? current->next->data : 0 )<< endl;
      } */

    /*
        the problem was three main reasons didn't inculde in thinking process
            - first to make condition for delete start from head
                - not making the head in this case nullptr
            - in total return the nodes that suppose to travel to reach the last one before delete
        the remain normal just the other make the process seem nonsense
        => make more confidenet in logical solution and search where the problem was
        => think always the start problem like empty null condition
    */
}

// Problem 5.3 (Medium): Delete from End While Sum Exceeds Target
// Delete nodes from end one by one until the sum of remaining nodes ≤ target.
// Return count of deleted nodes.
// Example: List: 10->20->30->40 (sum=100), Target: 50 → Delete 40,30 (sum=30), return 2
// Constraints: Target ≥ 0, values are positive integers
int problem5_3(Node *&head, int target)
{
    // TODO: Implement deleting from end while sum exceeds target
    // Hint: Calculate sum, keep deleting last node and updating sum until sum <= target
    /*
        start time :18:23
        end time :19:27
        total time : 1h:3min
    */
    if (head == nullptr)
        return 0;
    Node *current = head;
    int value = target;
    if (head->next == nullptr)
    {
        if (head->data <= value)
        {
            return 0;
        }
        if (head->data > value)
        {
            delete current;
            head = nullptr;
            return 1;
        }
    }
    int sum = 0;

    /*
        i have to minus from target till reach below zero
        the node make below zero is the node we need to start delete
        in case the head is bigger than the target will delete all the nodes
        when not bigger and find the tager that we have to store the the prev to unlinked
            that mean we have to delete from head and then start to delete from the next
        in the end we want the node we start delete from it in head less we need to unlinked to last node will note deleted
    */
    Node *nextNode = current->next;
    if (head->data < target)
    {
        target = target - head->data;
        while (target > 0 && current->next != nullptr)
        {
            target = target - current->next->data;
            if (target > 0)
            {
                current = current->next;
            }
        }
        if (target > 0 && current->next == nullptr)
            return 0;
        nextNode = current->next;
        current->next = nullptr;
        current = nextNode;
    }
    else
    {
        current = head;
        nextNode = current;
        head = nullptr;
    }
    while (current != nullptr)
    {
        sum++;
        nextNode = nextNode->next;
        delete current;
        current = nextNode;
    }

    // Node *nextNode = current->next;
    // if (head->data > target ) {
    //     while (value > 0 )
    //     {
    //         if (current == nullptr) return 0;
    //         value = value - current->data;
    //         if (value > 0)
    //         {
    //             current = current->next;
    //         }
    //     }
    //     nextNode = current->next ;
    //     current->next = nullptr;
    // } else {
    //     head = nullptr;
    //     delete current;
    // }

    // while (current != nullptr)
    // {
    //     sum++;
    //     current = nextNode;
    //     nextNode = nextNode->next;
    //     delete current;
    // }

    /*
        please plan before coding is turing chaos and in last planning and turn smooth
    */
    return sum;
}

// ============================================================================
// CONCEPT 6: DELETE AT POSITION
// ============================================================================

// Problem 6.1 (Easy): Delete Node at Position (0-indexed)
// Delete node at given position. Return true if deleted, false if invalid position.
// Example: List: 1->2->3->4, Position: 2 → Result: 1->2->4, return true
// Constraints: Position ≥ 0
bool problem6_1(Node *&head, int position)
{
    // TODO: Implement deleting at specific position
    // Hint: Handle position 0 separately, then traverse to position-1 and delete next
    /*
        take care of null head
        then travel by moving the current to next and position to munis -1
        if not found return false if found return true and delete
        take care if the head is deleted one
        forget to link the next to head the test function is still test in head
        ** you forget to stop in the position 0 condtion is worked and lead to double delete and while error
    */
    /*
         start time : 08:09
         end time : 08:29
    */
    if (head == nullptr)
        return false;
    Node *current = head;
    Node *nextNode = head->next;
    if (position == 0)
    {
        delete current;
        head = nextNode;
        return true;
    }
    position--;
    while (nextNode != nullptr && position != 0)
    {
        // cout << " the while worked in position " << position << endl;
        current = current->next;
        nextNode = nextNode->next;
        position--;
    }
    if (nextNode == nullptr)
        return false;
    current->next = nextNode->next;
    delete nextNode;
    return true;
}

// Problem 6.2 (Easy): Delete All Even Positioned Nodes (0-indexed)
// Delete all nodes at even positions (0, 2, 4, ...).
// Return count of deleted nodes.
// Example: List: 1->2->3->4->5 → Result: 2->4, return 3 (deleted positions 0,2,4)
// Constraints: List size 0-100
int problem6_2(Node *&head)
{
    // TODO: Implement deleting all even positioned nodes
    // Hint: Loop through list keeping track of position, delete when position is even
    /*
        start time : 08:30
        end time : 09:07
    */
    /*
         take care of null head in single node at first
         make int that count and check if divide by 2 or not
         check if reach the tail or not
         store the prev and current
         the prev next become current next
         then delete the current
         the prolem happen because of the head i must be careful in to make always the head = to new head
    */
    if (head == nullptr)
        return 0;
    Node *current = head;
    if (head->next == nullptr)
    {
        head = nullptr;
        delete current;
        return 1;
    }
    Node *prevNode = nullptr;
    Node *nextNode = head->next;
    int sum = 0;
    int check = 0;
    head = nextNode;
    while (current != nullptr)
    {
        if ((check % 2) == 0)
        {
            if (prevNode != nullptr)
                prevNode->next = nextNode;
            delete current;
            current = nextNode;
            nextNode = nextNode != nullptr ? nextNode->next : nullptr;
            sum++;
        }
        else
        {
            prevNode = current;
            current = nextNode;
            nextNode = nextNode != nullptr ? nextNode->next : nullptr;
        }
        check++;
    }

    return sum;
}

// Problem 6.3 (Medium): Delete Range of Positions
// Delete all nodes from position start to end (inclusive, 0-indexed).
// Return count of deleted nodes.
// Example: List: 1->2->3->4->5, Start: 1, End: 3 → Result: 1->5, return 3
// Constraints: 0 ≤ start ≤ end
int problem6_3(Node *&head, int start, int end)
{
    // TODO: Implement deleting range of positions
    // Hint: Traverse to position start-1, then delete nodes until reaching end
    /*
        start time : 09:09
        end time : 09:47
    */
    /*
        take care of null head or single list
        calc to total of nodes will be deleted
        take care of head if postion start from 0
        travel to reach the node that start delete after
        save next to link to prev node
        stop when reach end or nullptr
    */
    int sum = end - start + 1;
    int total = 0;
    if (head == nullptr)
        return 0;
    Node *startNode = head;
    Node *nextNode = head->next;
    if (head->next == nullptr)
    {
        if (start == 0)
        {
            head = nullptr;
            delete startNode;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (start == 0)
        head = nullptr;
    start--;
    while (nextNode != nullptr && start > 0)
    {
        startNode = nextNode;
        nextNode = nextNode->next;
        start--;
    }

    while (nextNode != nullptr && sum != 0)
    {
        startNode->next = nextNode->next;
        delete nextNode;
        nextNode = startNode->next;
        sum--;
        total++;
    }
    if (head == nullptr)
    {
        head = startNode->next;
        delete startNode;
        total++;
    }
    return total;
}

// ============================================================================
// CONCEPT 7: SEARCH FOR VALUE
// ============================================================================

// Problem 7.1 (Easy): Find First Occurrence Position
// Return the position (0-indexed) of first occurrence of value. Return -1 if not found.
// Example: List: 10->20->30->20, Value: 20 → return 1
// Constraints: Values are any integers
int problem7_1(Node *head, int value)
{
    // TODO: Implement finding first occurrence position
    // Hint: Traverse list with counter, return counter when value found
    /*
        start time : 07:54
        end time : 08:09
    */
    /*
         first take care of head null condition
         travel from head to tail if not find return -1
    */
    if (head == nullptr)
        return -1;
    Node *current = head;
    int travel = 0;
    int dataSearch = current->data;
    while (dataSearch != value && current != nullptr)
    {
        current = current->next;
        dataSearch = current != nullptr ? current->data : -1;
        travel++;
    }
    if (current == nullptr)
        return -1;

    return travel;
}

// Problem 7.2 (Easy): Count Occurrences
// Return the count of how many times value appears in the list.
// Example: List: 1->2->2->3->2->4, Value: 2 → return 3
// Constraints: Values are any integers
int problem7_2(Node *head, int value)
{
    // TODO: Implement counting occurrences
    // Hint: Traverse list incrementing counter each time value is found$
    /*
        start time : 09:48
        end time : 09:50
    */
    if (head == nullptr)
        return 0;
    int sum = 0;
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == value)
            sum++;
        current = current->next;
    }

    return sum;
}

// Problem 7.3 (Medium): Find Kth Occurrence Position
// Return position (0-indexed) of the kth occurrence of value (k starts at 1).
// Return -1 if less than k occurrences exist.
// Example: List: 5->3->5->7->5, Value: 5, K: 2 → return 2 (second 5 is at position 2)
// Constraints: K ≥ 1, values are any integers
int problem7_3(Node *head, int value, int k)
{
    // TODO: Implement finding kth occurrence position
    // Hint: Traverse list counting occurrences, return position when count reaches k
    /*
        start time : 09:51
        end time : 10:04
    */
    if (head == nullptr)
        return 0;
    if (head->next == nullptr)
        return 0;
    Node *current = head;
    int sum = 0;
    bool firstK = false;
    while (current != nullptr && firstK != true)
    {
        /* code */
        if (current->data == value)
        {
            firstK = true;
        }
        else
        {
            current = current->next;
            sum++;
        }
    }
    if (current == nullptr)
        return -1;
    while (current != nullptr && k != 1)
    {
        current = current->next;
        if (current != nullptr)
        {

            if (current->data == value)
            {
                /* code */
                k--;
            }
            sum++;
        }
    }

    if (current == nullptr && k > 1)
        return -1;
    return sum;
}

// ============================================================================
// CONCEPT 8: GET LIST LENGTH
// ============================================================================

// Problem 8.1 (Easy): Count Total Nodes
// Return the total number of nodes in the list.
// Example: List: 1->2->3->4 → return 4
// Constraints: List size 0-1000
int problem8_1(Node *head)
{
    // TODO: Implement counting total nodes
    // Hint: Traverse list with counter, return counter at end
    /*
        start time : 08:11
        end time : 08:13
    */
    if (head == nullptr)
        return 0;
    Node *current = head;
    int total = 0;
    while (current != nullptr)
    {
        total++;
        current = current->next;
    }

    return total;
}

// Problem 8.2 (Easy): Count Nodes with Value Greater Than X
// Return count of nodes with value > x.
// Example: List: 5->10->3->15->8, X: 7 → return 3 (nodes: 10, 15, 8)
// Constraints: Values are integers
int problem8_2(Node *head, int x)
{
    // TODO: Implement counting nodes with value > x
    // Hint: Traverse list incrementing counter when node value > x
    /*
        start time : 09:33
        end time : 09:35
    */
    if (head == nullptr)
        return 0;
    Node *current = head;
    int total = 0;
    while (current != nullptr)
    {
        if (current->data > x)
            total++;
        current = current->next;
    }

    return total;
}

// Problem 8.3 (Medium): Count Nodes in Range
// Return count of nodes with values in range [min, max] (inclusive).
// Example: List: 2->8->5->12->6->3, Min: 4, Max: 10 → return 3 (nodes: 8, 5, 6)
// Constraints: min ≤ max, values are integers
int problem8_3(Node *head, int minVal, int maxVal)
{
    // TODO: Implement counting nodes in range
    // Hint: Traverse list incrementing counter when min <= node value <= max
    /*
        start time : 09:36
        end time : 09:38
    */
    if (head == nullptr)
        return 0;
    Node *current = head;
    int total = 0;
    while (current != nullptr)
    {
        if (current->data >= minVal && current->data <= maxVal)
            total++;
        current = current->next;
    }

    return total;
}

// ============================================================================
// CONCEPT 9: REVERSE LIST
// ============================================================================

// Problem 9.1 (Easy): Reverse Entire List
// Reverse the entire linked list in-place.
// Example: List: 1->2->3->4 → Result: 4->3->2->1
// Constraints: List size 0-100
void problem9_1(Node *&head)
{
    // TODO: Implement reversing entire list
    // Hint: Use three pointers (prev, current, next) to reverse links
    /*
        start time : 09:36
        end time : 10:03
    */
    /*
         first need to start the head and tail to reverse position the function not return node
         make the next to prev and store the current to move to next
    */
    if (head != nullptr)
    {

        Node *prevNode = nullptr;
        Node *current = head;
        Node *nextNode = head->next;
        while (nextNode != nullptr)
        {
            current->next = prevNode;
            prevNode = current;
            current = nextNode;
            nextNode = nextNode->next;
        }
        head = current;
        head->next = prevNode;
        /*
            what make it harder is the function not return node to start as head that why the while is end the current in last node without maki it the next of
            after while end make the head is the current the last node and the next of head is the before last node the rest has the next correct
        */
    }
}

// Problem 9.2 (Easy): Check if List is Palindrome
// Return true if list reads same forwards and backwards, false otherwise.
// Example: List: 1->2->3->2->1 → return true
// Example: List: 1->2->3 → return false
// Constraints: List size 0-100, values are positive integers
bool problem9_2(Node *head)
{
    // TODO: Implement palindrome check
    // Hint: Find middle, reverse second half, compare with first half
    /*
        start time : 10:03
        end time : 10:27
    */
    if (head == nullptr)
        return true;
    if (head->next == nullptr)
        return true;
    // calc the total nodes
    int total = 0;
    Node *current = head;
    while (current != nullptr)
    {
        total++;
        current = current->next;
    }
    // find the first half node
    int middel = total / 2;
    current = head;
    while (middel != 0 && current != nullptr)
    {
        middel--;
        current = current->next;
    }
    // start after the middle of the list is odd
    if (total % 2 != 0)
        current = current->next;
    cout << "start reversing from " << current->data << endl;
    // start reversing the second  half take from prev don't repeat yourself
    Node *prevNode = nullptr;
    Node *nextNode = current->next;
    while (nextNode != nullptr)
    {
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
        nextNode = nextNode->next;
    }
    current->next = prevNode;
    Node *current2 = head;
    while (current != nullptr)
    {
        if (current->data != current2->data)
            return false;
        current = current->next;
        current2 = current2->next;
    }
    /*
        the problem from my idiot memory forget the take care that the node are address and data and calc two different address and i need data
        node 1 : data -> 1 , adress : place1
        node 5 : data -> 1 , adress : place5
        node 1 == node 2 instead of node 1->data == node 2->data
        good false to not repeat in future
    */
    return true;
}

// Problem 9.3 (Medium): Reverse List in Groups of K
// Reverse nodes in groups of k. If remaining nodes < k, leave them as is.
// Example: List: 1->2->3->4->5->6->7, K: 3 → Result: 3->2->1->6->5->4->7
// Constraints: K ≥ 1, list size 0-100
void problem9_3(Node *&head, int k)
{
    // TODO: Implement reversing in groups of k
    // Hint: Process k nodes at a time, reverse each group, connect groups
    // if (head != nullptr)
    // {
    //     Node *current = head;
    //     while (current->next != nullptr && current->data != k)
    //     {
    //         current = current->next;
    //     }
    //     if (current->data == k)
    //     {
    //         cout << "the current before reverse is :" << current->data << endl;
    //         Node *tail = current;
    //         current = head;
    //         Node *prevNode = nullptr;
    //         Node *nextNode = current->next;
    //         while (nextNode != tail->next)
    //         {
    //             current->next = prevNode;
    //             prevNode = current;
    //             current = nextNode;
    //             nextNode = nextNode->next;
    //         }
    //         head->next = tail->next;
    //         current->next = prevNode;
    //         head = current;
    //         current = head;
    //         while (current != nullptr)
    //         {
    //             cout << current->data;
    //             if (current->next != nullptr)
    //             {
    //                 cout << "->";
    //             }
    //             else
    //             {
    //                 cout << endl;
    //             }
    //             current = current->next;
    //         }
    //     }
    //     // solving something else didn't understand the problem
    // }
    /*
        start time : 08:34
        stop at : 09:50
        return at : 10:29
    */
    /*
         i have to save the third node to return the new head
         save the start node of every reverse loop
         save the head and tail of every loop if the tail after loop of two next become nullptr the loop end
    */
    if (head != nullptr)
    {
        int total = 0;
        Node *currentHead = head;
        Node *prevHead = nullptr;
        Node *tail = head;
        Node *nextNode = head;
        // Node * current = head;
        int i = 2;
        while (i)
        {
            if (currentHead->next == nullptr)
            {
                i = 0;
            }
            else
            {
                currentHead = currentHead->next;
                i--;
            }
        }
        if (currentHead != nullptr)
        {
            head = currentHead;
            currentHead = nextNode;
            while (tail != nullptr)
            {
                cout << "the current tail is "  << tail->data << endl;
                i = 2;
                while (i)
                {
                    if (tail->next == nullptr)
                    {
                        tail = nullptr;
                        i = 0;
                    }
                    else
                    {
                        tail = tail->next;
                        i--;
                    }
                }
                /*   if (prevHead != nullptr)
                  {
                      prevHead->next = currentHead;
                      prevHead = currentHead;
                  } else {
                      prevHead = currentHead;
                  }
                  nextNode = currentHead->next;
                  nextNode->next = currentHead;
                  currentHead = tail->next;
                  tail->next = nextNode;
                  tail = currentHead; */
                  if (tail != nullptr) {

                      if (prevHead != nullptr)
                      {
                          prevHead->next = tail;
                          cout << "prevHead is not null, setting prevHead->next to currentHead: " << prevHead->data << " | " << tail->data << endl;
                          
                          prevHead = currentHead;
                          cout << "Updated prevHead to currentHead: " << prevHead->data << endl;
                        }
                        else
                        {
                            prevHead = currentHead;
                            cout << "prevHead was null, now set to currentHead: " << prevHead->data << endl;
                        }
                        
                        nextNode = currentHead->next;
                        cout << "Set nextNode to currentHead->next: " << nextNode->data << endl;
                        
                        currentHead->next = nullptr;
                        nextNode->next = currentHead;
                        cout << "Set nextNode->next to currentHead: " << currentHead->data << endl;
                        
                        currentHead = tail->next;
                        cout << "Updated currentHead to tail->next: " << currentHead->data << endl;
                        
                        tail->next = nextNode;
                        cout << "Set tail->next to nextNode: " << nextNode->data << endl;
                        
                        tail = currentHead;
                        cout << "Moved tail to currentHead: " << tail->data << endl;
                        if (tail->next == nullptr)
                        {
                            prevHead->next = tail ;
                            tail->next = nullptr;
                            /* code */
                        }
                    }
                
                
                /*  ne = current->next;
                 // current->next = tail->next;
                 nextHead->next = current;
                 current = tail;
                 tail->next = nextHead;
                 tail = current->next;
                 current = tail;
                 cout << "work " << endl; */

                /*  cout << "before the if workded " << endl;
                 tempHead->next = tail;
                 tempHead = current;
                 if (tail != nullptr)
                 {
                     cout << "tail is  " << tail->data << endl;
                     // point the next head to head in new cycel
                     nextHead = tail->next;
                     // make the tail point to middle one
                     tail->next = tempHead->next;
                     // make the current is the middle one
                     current = tempHead->next;
                     // make the middle point to head
                     current->next = tempHead;
                     // make the old head point to next new head
                     // tempHead->next = nextHead; // and this the wrong one
                     // return the temp head to the head of next cycel
                     current = nextHead;
                     tail = nextHead;
                     cout << "ended " << endl;

                 } */
            }
            // currentHead = head;
            // while (currentHead != nullptr)
            // {
            //     cout << currentHead->data;
            //     if (currentHead->next == nullptr)
            //     {
            //         cout << endl;
            //     }
            //     else
            //     {
            //         cout << " -> ";
            //     }
            //     currentHead = currentHead->next;
            // }
        }
        // while (current != nullptr)
        // {
        //     total++;
        //     current = current->next;
        // }
        // current = head;
        // total = total / k;
        // while (0)
        // {
        //     /* code */
        // }
    }
}

// ============================================================================
// CONCEPT 10: DISPLAY CURRENT LIST
// ============================================================================

// Problem 10.1 (Easy): Display List in Order
// Print all node values separated by " -> ", end with "NULL".
// Example: List: 1->2->3 → Output: "1 -> 2 -> 3 -> NULL"
// Constraints: List size 0-100
void problem10_1(Node *head)
{
    // TODO: Implement displaying list
    // Hint: Traverse list printing each value with arrow, print NULL at end
}

// Problem 10.2 (Easy): Display List in Reverse Order
// Print all node values in reverse order separated by " -> ", end with "NULL".
// Do NOT modify the list.
// Example: List: 1->2->3 → Output: "3 -> 2 -> 1 -> NULL"
// Constraints: List size 0-100
void problem10_2(Node *head)
{
    // TODO: Implement displaying list in reverse without modifying it
    // Hint: Use recursion or store values in array then print backwards
}

// Problem 10.3 (Medium): Display Nodes at Even Positions
// Print values of nodes at even positions (0, 2, 4, ...) separated by " -> ".
// Example: List: 10->20->30->40->50 → Output: "10 -> 30 -> 50 -> NULL"
// Constraints: List size 0-100
void problem10_3(Node *head)
{
    // TODO: Implement displaying nodes at even positions
    // Hint: Traverse with position counter, print only when position is even
}

// ============================================================================
// CONCEPT 11: CLEAR ALL NODES
// ============================================================================

// Problem 11.1 (Easy): Delete All Nodes
// Delete all nodes and set head to nullptr. Return count of deleted nodes.
// Example: List: 1->2->3 → Result: empty list, return 3
// Constraints: List size 0-100
int problem11_1(Node *&head)
{
    // TODO: Implement deleting all nodes
    // Hint: Loop deleting first node until list is empty, count deletions
    return 0;
}

// Problem 11.2 (Easy): Delete All Nodes with Specific Value
// Delete all occurrences of target value. Return count of deleted nodes.
// Example: List: 1->2->3->2->4->2, Target: 2 → Result: 1->3->4, return 3
// Constraints: Values are any integers
int problem11_2(Node *&head, int target)
{
    // TODO: Implement deleting all nodes with specific value
    // Hint: Handle head nodes with target, then traverse deleting matching nodes
    return 0;
}

// Problem 11.3 (Medium): Clear List and Return Statistics
// Delete all nodes and return an array of 3 values: [total_nodes, sum, max_value].
// Return [-1, -1, -1] if list was empty.
// Example: List: 5->2->8->3 → Result: empty list, return [4, 18, 8]
// Constraints: Values are positive integers
void problem11_3(Node *&head, int result[3])
{
    // TODO: Implement clearing list and returning statistics
    // Hint: Calculate stats while traversing, then delete all nodes
}

// ============================================================================
// CONCEPT 12: LINKED LIST VS ARRAY OPERATIONS
// ============================================================================

// Problem 12.1 (Easy): Convert Array to Linked List
// Given an array and its size, create a linked list with same elements in order.
// Example: Array: [1, 2, 3, 4] → Result: 1->2->3->4
// Constraints: Array size 0-100
Node *problem12_1(int arr[], int size)
{
    // TODO: Implement converting array to linked list
    // Hint: Loop through array creating and linking nodes
    Node *newNode = new Node(5);
    return newNode;
}

// Problem 12.2 (Easy): Convert Linked List to Array
// Convert linked list to dynamically allocated array. Store size in provided pointer.
// Return the array pointer.
// Example: List: 1->2->3 → Result: Array[1,2,3], size=3
// Constraints: List size 0-100, remember to allocate memory
int *problem12_2(Node *head, int *size)
{
    // TODO: Implement converting linked list to array
    // Hint: First count nodes, allocate array, then copy values
    int *temp = nullptr;
    return temp;
}

// Problem 12.3 (Medium): Merge Two Sorted Lists
// Given two sorted linked lists, merge them into one sorted list.
// Example: List1: 1->3->5, List2: 2->4->6 → Result: 1->2->3->4->5->6
// Constraints: Both lists are sorted in ascending order
Node *problem12_3(Node *list1, Node *list2)
{
    // TODO: Implement merging two sorted lists
    // Hint: Compare heads, choose smaller, advance that list, repeat
    Node *newNode = new Node(5);
    return newNode;
}

// ============================================================================
// HELPER FUNCTIONS FOR TESTING
// ============================================================================

// Create a node
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Create list from array
Node *createList(int arr[], int size)
{
    if (size == 0)
        return nullptr;
    Node *head = createNode(arr[0]);
    Node *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Display list
void displayList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
            cout << " -> ";
        current = current->next;
    }
    if (head == nullptr)
        cout << "Empty";
    cout << endl;
}

// Count nodes
int countNodes(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Delete all nodes
void deleteAllNodes(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Compare two lists
bool compareLists(Node *list1, Node *list2)
{
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data != list2->data)
            return false;
        list1 = list1->next;
        list2 = list2->next;
    }

    return list1 == nullptr && list2 == nullptr;
}

// ============================================================================
// TEST FUNCTIONS
// ============================================================================

void testProblem1_1()
{
    cout << "\n=== Testing Problem 1.1: Insert Single Node at Beginning ===" << endl;

    // Test 1: Insert into empty list
    // Step: head=nullptr, value=5
    // Expected: 5->NULL, new head points to node with data=5
    Node *test1 = nullptr;
    test1 = problem1_1(test1, 5);
    cout << "Test 1 (Empty list, insert 5): ";
    cout << (test1 != nullptr && test1->data == 5 && test1->next == nullptr ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: Insert into single-node list
    // Step: head=10, value=5
    // Expected: 5->10->NULL
    int arr2[] = {10};
    Node *test2 = createList(arr2, 1);
    test2 = problem1_1(test2, 5);
    cout << "Test 2 (List: 10, insert 5): ";
    int expected2[] = {5, 10};
    Node *exp2 = createList(expected2, 2);
    cout << (compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Insert into multi-node list
    // Step: head=2->3->4, value=1
    // Expected: 1->2->3->4->NULL
    int arr3[] = {2, 3, 4};
    Node *test3 = createList(arr3, 3);
    test3 = problem1_1(test3, 1);
    cout << "Test 3 (List: 2->3->4, insert 1): ";
    int expected3[] = {1, 2, 3, 4};
    Node *exp3 = createList(expected3, 4);
    cout << (compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Insert negative number
    // Step: head=1->2->3, value=-5
    // Expected: -5->1->2->3->NULL
    int arr4[] = {1, 2, 3};
    Node *test4 = createList(arr4, 3);
    test4 = problem1_1(test4, -5);
    cout << "Test 4 (List: 1->2->3, insert -5): ";
    int expected4[] = {-5, 1, 2, 3};
    Node *exp4 = createList(expected4, 4);
    cout << (compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Insert into large list
    // Step: head=10->20->30->40->50, value=5
    // Expected: 5->10->20->30->40->50->NULL
    int arr5[] = {10, 20, 30, 40, 50};
    Node *test5 = createList(arr5, 5);
    test5 = problem1_1(test5, 5);
    cout << "Test 5 (List: 10->20->30->40->50, insert 5): ";
    int expected5[] = {5, 10, 20, 30, 40, 50};
    Node *exp5 = createList(expected5, 6);
    cout << (compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem1_2()
{
    cout << "\n=== Testing Problem 1.2: Insert Multiple Nodes at Beginning ===" << endl;

    // Test 1: Insert into empty list
    // Step: head=nullptr, values=[1,2,3]
    // Expected: 3->2->1->NULL (inserted in order, so reversed)
    Node *test1 = nullptr;
    int vals1[] = {1, 2, 3};
    test1 = problem1_2(test1, vals1, 3);
    cout << "Test 1 (Empty list, insert [1,2,3]): ";
    int expected1[] = {3, 2, 1};
    Node *exp1 = createList(expected1, 3);
    cout << (compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Insert into existing list
    // Step: head=4->5, values=[1,2,3]
    // Expected: 3->2->1->4->5->NULL
    int arr2[] = {4, 5};
    Node *test2 = createList(arr2, 2);
    int vals2[] = {1, 2, 3};
    test2 = problem1_2(test2, vals2, 3);
    cout << "Test 2 (List: 4->5, insert [1,2,3]): ";
    int expected2[] = {3, 2, 1, 4, 5};
    Node *exp2 = createList(expected2, 5);
    cout << (compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Insert single value
    // Step: head=2->3, values=[1]
    // Expected: 1->2->3->NULL
    int arr3[] = {2, 3};
    Node *test3 = createList(arr3, 2);
    int vals3[] = {1};
    test3 = problem1_2(test3, vals3, 1);
    cout << "Test 3 (List: 2->3, insert [1]): ";
    int expected3[] = {1, 2, 3};
    Node *exp3 = createList(expected3, 3);
    cout << (compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Insert with negative numbers
    // Step: head=5->6, values=[-1,0,1]
    // Expected: 1->0->-1->5->6->NULL
    int arr4[] = {5, 6};
    Node *test4 = createList(arr4, 2);
    int vals4[] = {-1, 0, 1};
    test4 = problem1_2(test4, vals4, 3);
    cout << "Test 4 (List: 5->6, insert [-1,0,1]): ";
    int expected4[] = {1, 0, -1, 5, 6};
    Node *exp4 = createList(expected4, 5);
    cout << (compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Insert larger array
    // Step: head=10, values=[5,6,7,8,9]
    // Expected: 9->8->7->6->5->10->NULL
    int arr5[] = {10};
    Node *test5 = createList(arr5, 1);
    int vals5[] = {5, 6, 7, 8, 9};
    test5 = problem1_2(test5, vals5, 5);
    cout << "Test 5 (List: 10, insert [5,6,7,8,9]): ";
    int expected5[] = {9, 8, 7, 6, 5, 10};
    Node *exp5 = createList(expected5, 6);
    cout << (compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem1_3()
{
    cout << "\n=== Testing Problem 1.3: Insert at Beginning with Duplicate Check ===" << endl;

    // Test 1: Insert into empty list (always succeeds)
    // Step: head=nullptr, value=5
    // Expected: 5->NULL, return true
    Node *test1 = nullptr;
    bool result1 = problem1_3(test1, 5);
    cout << "Test 1 (Empty list, insert 5): ";
    cout << (result1 && test1 != nullptr && test1->data == 5 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: Insert non-duplicate
    // Step: head=2->3->4, value=1 (not in list)
    // Expected: 1->2->3->4->NULL, return true
    int arr2[] = {2, 3, 4};
    Node *test2 = createList(arr2, 3);
    bool result2 = problem1_3(test2, 1);
    cout << "Test 2 (List: 2->3->4, insert 1): ";
    int expected2[] = {1, 2, 3, 4};
    Node *exp2 = createList(expected2, 4);
    cout << (result2 && compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Insert duplicate (should fail)
    // Step: head=2->3->4, value=3 (exists in list)
    // Expected: 2->3->4->NULL (unchanged), return false
    int arr3[] = {2, 3, 4};
    Node *test3 = createList(arr3, 3);
    bool result3 = problem1_3(test3, 3);
    cout << "Test 3 (List: 2->3->4, insert 3 - duplicate): ";
    int expected3[] = {2, 3, 4};
    Node *exp3 = createList(expected3, 3);
    cout << (!result3 && compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Insert duplicate at end
    // Step: head=1->2->3, value=3 (exists at end)
    // Expected: 1->2->3->NULL (unchanged), return false
    int arr4[] = {1, 2, 3};
    Node *test4 = createList(arr4, 3);
    bool result4 = problem1_3(test4, 3);
    cout << "Test 4 (List: 1->2->3, insert 3 - duplicate at end): ";
    int expected4[] = {1, 2, 3};
    Node *exp4 = createList(expected4, 3);
    cout << (!result4 && compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Insert non-duplicate in large list
    // Step: head=10->20->30->40->50, value=5 (not in list)
    // Expected: 5->10->20->30->40->50->NULL, return true
    int arr5[] = {10, 20, 30, 40, 50};
    Node *test5 = createList(arr5, 5);
    bool result5 = problem1_3(test5, 5);
    cout << "Test 5 (List: 10->20->30->40->50, insert 5): ";
    int expected5[] = {5, 10, 20, 30, 40, 50};
    Node *exp5 = createList(expected5, 6);
    cout << (result5 && compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem2_1()
{
    cout << "\n=== Testing Problem 2.1: Insert Single Node at End ===" << endl;

    // Test 1: Insert into empty list
    // Step: head=nullptr, value=5
    // Expected: 5->NULL
    Node *test1 = nullptr;
    problem2_1(test1, 5);
    cout << "Test 1 (Empty list, insert 5): ";
    cout << (test1 != nullptr && test1->data == 5 && test1->next == nullptr ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: Insert into single-node list
    // Step: head=10, value=20
    // Expected: 10->20->NULL
    int arr2[] = {10};
    Node *test2 = createList(arr2, 1);
    problem2_1(test2, 20);
    cout << "Test 2 (List: 10, insert 20): ";
    int expected2[] = {10, 20};
    Node *exp2 = createList(expected2, 2);
    cout << (compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Insert into multi-node list
    // Step: head=1->2->3, value=4
    // Expected: 1->2->3->4->NULL
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    problem2_1(test3, 4);
    cout << "Test 3 (List: 1->2->3, insert 4): ";
    int expected3[] = {1, 2, 3, 4};
    Node *exp3 = createList(expected3, 4);
    cout << (compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Insert negative number
    // Step: head=1->2->3, value=-10
    // Expected: 1->2->3->-10->NULL
    int arr4[] = {1, 2, 3};
    Node *test4 = createList(arr4, 3);
    problem2_1(test4, -10);
    cout << "Test 4 (List: 1->2->3, insert -10): ";
    int expected4[] = {1, 2, 3, -10};
    Node *exp4 = createList(expected4, 4);
    cout << (compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Insert into large list
    // Step: head=5->10->15->20->25, value=30
    // Expected: 5->10->15->20->25->30->NULL
    int arr5[] = {5, 10, 15, 20, 25};
    Node *test5 = createList(arr5, 5);
    problem2_1(test5, 30);
    cout << "Test 5 (List: 5->10->15->20->25, insert 30): ";
    int expected5[] = {5, 10, 15, 20, 25, 30};
    Node *exp5 = createList(expected5, 6);
    cout << (compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem2_2()
{
    cout << "\n=== Testing Problem 2.2: Insert Multiple Nodes at End ===" << endl;

    // Test 1: Insert into empty list
    // Step: head=nullptr, values=[1,2,3]
    // Expected: 1->2->3->NULL
    Node *test1 = nullptr;
    int vals1[] = {1, 2, 3};
    problem2_2(test1, vals1, 3);
    cout << "Test 1 (Empty list, insert [1,2,3]): ";
    int expected1[] = {1, 2, 3};
    Node *exp1 = createList(expected1, 3);
    cout << (compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Insert into existing list
    // Step: head=1->2, values=[3,4,5]
    // Expected: 1->2->3->4->5->NULL
    int arr2[] = {1, 2};
    Node *test2 = createList(arr2, 2);
    int vals2[] = {3, 4, 5};
    problem2_2(test2, vals2, 3);
    cout << "Test 2 (List: 1->2, insert [3,4,5]): ";
    int expected2[] = {1, 2, 3, 4, 5};
    Node *exp2 = createList(expected2, 5);
    cout << (compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Insert single value
    // Step: head=5->10, values=[15]
    // Expected: 5->10->15->NULL
    int arr3[] = {5, 10};
    Node *test3 = createList(arr3, 2);
    int vals3[] = {15};
    problem2_2(test3, vals3, 1);
    cout << "Test 3 (List: 5->10, insert [15]): ";
    int expected3[] = {5, 10, 15};
    Node *exp3 = createList(expected3, 3);
    cout << (compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Insert with mixed numbers
    // Step: head=0, values=[-5,10,-3,7]
    // Expected: 0->-5->10->-3->7->NULL
    int arr4[] = {0};
    Node *test4 = createList(arr4, 1);
    int vals4[] = {-5, 10, -3, 7};
    problem2_2(test4, vals4, 4);
    cout << "Test 4 (List: 0, insert [-5,10,-3,7]): ";
    int expected4[] = {0, -5, 10, -3, 7};
    Node *exp4 = createList(expected4, 5);
    cout << (compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Insert larger array
    // Step: head=1->2->3, values=[4,5,6,7,8]
    // Expected: 1->2->3->4->5->6->7->8->NULL
    int arr5[] = {1, 2, 3};
    Node *test5 = createList(arr5, 3);
    int vals5[] = {4, 5, 6, 7, 8};
    problem2_2(test5, vals5, 5);
    cout << "Test 5 (List: 1->2->3, insert [4,5,6,7,8]): ";
    int expected5[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *exp5 = createList(expected5, 8);
    cout << (compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem2_3()
{
    cout << "\n=== Testing Problem 2.3: Insert at End with Sum Validation ===" << endl;

    // Test 1: Insert when sum is within limit
    // Step: head=10->20->30 (sum=60), value=15, maxSum=80
    // Calculation: 60+15=75, 75<=80, insert
    // Expected: 10->20->30->15->NULL, return true
    int arr1[] = {10, 20, 30};
    Node *test1 = createList(arr1, 3);
    bool result1 = problem2_3(test1, 15, 80);
    cout << "Test 1 (List sum=60, insert 15, maxSum=80): ";
    int expected1[] = {10, 20, 30, 15};
    Node *exp1 = createList(expected1, 4);
    cout << (result1 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Insert would exceed limit
    // Step: head=10->20->30 (sum=60), value=25, maxSum=80
    // Calculation: 60+25=85, 85>80, don't insert
    // Expected: 10->20->30->NULL (unchanged), return false
    int arr2[] = {10, 20, 30};
    Node *test2 = createList(arr2, 3);
    bool result2 = problem2_3(test2, 25, 80);
    cout << "Test 2 (List sum=60, insert 25, maxSum=80 - exceeds): ";
    int expected2[] = {10, 20, 30};
    Node *exp2 = createList(expected2, 3);
    cout << (!result2 && compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Insert into empty list
    // Step: head=nullptr (sum=0), value=50, maxSum=100
    // Calculation: 0+50=50, 50<=100, insert
    // Expected: 50->NULL, return true
    Node *test3 = nullptr;
    bool result3 = problem2_3(test3, 50, 100);
    cout << "Test 3 (Empty list, insert 50, maxSum=100): ";
    cout << (result3 && test3 != nullptr && test3->data == 50 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);

    // Test 4: Insert exactly at limit
    // Step: head=40->35 (sum=75), value=25, maxSum=100
    // Calculation: 75+25=100, 100<=100, insert
    // Expected: 40->35->25->NULL, return true
    int arr4[] = {40, 35};
    Node *test4 = createList(arr4, 2);
    bool result4 = problem2_3(test4, 25, 100);
    cout << "Test 4 (List sum=75, insert 25, maxSum=100 - exact): ";
    int expected4[] = {40, 35, 25};
    Node *exp4 = createList(expected4, 3);
    cout << (result4 && compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Insert with single node
    // Step: head=50 (sum=50), value=60, maxSum=100
    // Calculation: 50+60=110, 110>100, don't insert
    // Expected: 50->NULL (unchanged), return false
    int arr5[] = {50};
    Node *test5 = createList(arr5, 1);
    bool result5 = problem2_3(test5, 60, 100);
    cout << "Test 5 (List sum=50, insert 60, maxSum=100 - exceeds): ";
    int expected5[] = {50};
    Node *exp5 = createList(expected5, 1);
    cout << (!result5 && compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

// Continue with remaining test functions...
// Due to length, I'll provide a representative sample and indicate the pattern

void testProblem3_1()
{
    cout << "\n=== Testing Problem 3.1: Insert at Specific Position ===" << endl;

    // Test 1: Insert at position 0 (beginning)
    int arr1[] = {2, 3, 4};
    Node *test1 = createList(arr1, 3);
    bool result1 = problem3_1(test1, 0, 1);
    cout << "Test 1 (List: 2->3->4, insert 1 at pos 0): ";
    int expected1[] = {1, 2, 3, 4};
    Node *exp1 = createList(expected1, 4);
    cout << (result1 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Insert at middle position
    int arr2[] = {1, 3, 4};
    Node *test2 = createList(arr2, 3);
    bool result2 = problem3_1(test2, 1, 2);
    cout << "Test 2 (List: 1->3->4, insert 2 at pos 1): ";
    int expected2[] = {1, 2, 3, 4};
    Node *exp2 = createList(expected2, 4);
    cout << (result2 && compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Insert at end position
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    bool result3 = problem3_1(test3, 3, 4);
    cout << "Test 3 (List: 1->2->3, insert 4 at pos 3): ";
    int expected3[] = {1, 2, 3, 4};
    Node *exp3 = createList(expected3, 4);
    cout << (result3 && compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Invalid position (too large)
    int arr4[] = {1, 2, 3};
    Node *test4 = createList(arr4, 3);
    bool result4 = problem3_1(test4, 10, 99);
    cout << "Test 4 (List: 1->2->3, insert at pos 10 - invalid): ";
    int expected4[] = {1, 2, 3};
    Node *exp4 = createList(expected4, 3);
    cout << (!result4 && compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Insert into empty list at position 0
    Node *test5 = nullptr;
    bool result5 = problem3_1(test5, 0, 42);
    cout << "Test 5 (Empty list, insert 42 at pos 0): ";
    cout << (result5 && test5 != nullptr && test5->data == 42 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
}
void testProblem3_2()
{
    cout << "\n=== Testing Problem 3.2: Insert Before First Occurrence ===" << endl;

    // Test 1: Insert before target in middle
    // Step: head=1->2->4->5, target=4, value=3
    // Expected: 1->2->3->4->5->NULL, return true
    int arr1[] = {1, 2, 4, 5};
    Node *test1 = createList(arr1, 4);
    bool result1 = problem3_2(test1, 4, 3);
    cout << "Test 1 (List: 1->2->4->5, insert 3 before 4): ";
    int expected1[] = {1, 2, 3, 4, 5};
    Node *exp1 = createList(expected1, 5);
    cout << (result1 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Insert before first node
    // Step: head=5->10->15, target=5, value=1
    // Expected: 1->5->10->15->NULL, return true
    int arr2[] = {5, 10, 15};
    Node *test2 = createList(arr2, 3);
    bool result2 = problem3_2(test2, 5, 1);
    cout << "Test 2 (List: 5->10->15, insert 1 before 5): ";
    int expected2[] = {1, 5, 10, 15};
    Node *exp2 = createList(expected2, 4);
    cout << (result2 && compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Target not found
    // Step: head=1->2->3, target=10, value=5
    // Expected: 1->2->3->NULL (unchanged), return false
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    bool result3 = problem3_2(test3, 10, 5);
    cout << "Test 3 (List: 1->2->3, insert before 10 - not found): ";
    int expected3[] = {1, 2, 3};
    Node *exp3 = createList(expected3, 3);
    cout << (!result3 && compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Empty list
    // Step: head=nullptr, target=5, value=3
    // Expected: nullptr (unchanged), return false
    Node *test4 = nullptr;
    bool result4 = problem3_2(test4, 5, 3);
    cout << "Test 4 (Empty list, insert before 5): ";
    cout << (!result4 && test4 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 5: Insert before last node
    // Step: head=10->20->30, target=30, value=25
    // Expected: 10->20->25->30->NULL, return true
    int arr5[] = {10, 20, 30};
    Node *test5 = createList(arr5, 3);
    bool result5 = problem3_2(test5, 30, 25);
    cout << "Test 5 (List: 10->20->30, insert 25 before 30): ";
    int expected5[] = {10, 20, 25, 30};
    Node *exp5 = createList(expected5, 4);
    cout << (result5 && compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem3_3()
{
    cout << "\n=== Testing Problem 3.3: Insert in Sorted Position ===" << endl;

    // Test 1: Insert in middle of sorted list
    // Step: head=1->3->5->7, value=4
    // Expected: 1->3->4->5->7->NULL
    int arr1[] = {1, 3, 5, 7};
    Node *test1 = createList(arr1, 4);
    problem3_3(test1, 4);
    cout << "Test 1 (List: 1->3->5->7, insert 4): ";
    int expected1[] = {1, 3, 4, 5, 7};
    Node *exp1 = createList(expected1, 5);
    cout << (compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Insert at beginning
    // Step: head=5->10->15, value=2
    // Expected: 2->5->10->15->NULL
    int arr2[] = {5, 10, 15};
    Node *test2 = createList(arr2, 3);
    problem3_3(test2, 2);
    cout << "Test 2 (List: 5->10->15, insert 2): ";
    int expected2[] = {2, 5, 10, 15};
    Node *exp2 = createList(expected2, 4);
    cout << (compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Insert at end
    // Step: head=1->2->3, value=10
    // Expected: 1->2->3->10->NULL
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    problem3_3(test3, 10);
    cout << "Test 3 (List: 1->2->3, insert 10): ";
    int expected3[] = {1, 2, 3, 10};
    Node *exp3 = createList(expected3, 4);
    cout << (compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Insert into empty list
    // Step: head=nullptr, value=5
    // Expected: 5->NULL
    Node *test4 = nullptr;
    problem3_3(test4, 5);
    cout << "Test 4 (Empty list, insert 5): ";
    cout << (test4 != nullptr && test4->data == 5 && test4->next == nullptr ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);

    // Test 5: Insert duplicate value (maintains sorted order)
    // Step: head=2->4->6->8, value=4
    // Expected: 2->4->4->6->8->NULL
    int arr5[] = {2, 4, 6, 8};
    Node *test5 = createList(arr5, 4);
    problem3_3(test5, 4);
    cout << "Test 5 (List: 2->4->6->8, insert 4 - duplicate): ";
    int expected5[] = {2, 4, 4, 6, 8};
    Node *exp5 = createList(expected5, 5);
    cout << (compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem4_1()
{
    cout << "\n=== Testing Problem 4.1: Delete First Node ===" << endl;

    // Test 1: Delete from multi-node list
    // Step: head=1->2->3
    // Expected: 2->3->NULL, return 1
    int arr1[] = {1, 2, 3};
    Node *test1 = createList(arr1, 3);
    int result1 = problem4_1(test1);
    cout << "Test 1 (List: 1->2->3, delete first): ";
    int expected1[] = {2, 3};
    Node *exp1 = createList(expected1, 2);
    cout << (result1 == 1 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Delete from single-node list
    // Step: head=42
    // Expected: nullptr, return 42
    int arr2[] = {42};
    Node *test2 = createList(arr2, 1);
    int result2 = problem4_1(test2);
    cout << "Test 2 (List: 42, delete first): ";
    cout << (result2 == 42 && test2 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 3: Delete from empty list
    // Step: head=nullptr
    // Expected: nullptr, return -1
    Node *test3 = nullptr;
    int result3 = problem4_1(test3);
    cout << "Test 3 (Empty list, delete first): ";
    cout << (result3 == -1 && test3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Delete multiple times
    // Step: head=5->10->15->20, delete twice
    // Expected: 15->20->NULL, returns 5 then 10
    int arr4[] = {5, 10, 15, 20};
    Node *test4 = createList(arr4, 4);
    int result4a = problem4_1(test4);
    int result4b = problem4_1(test4);
    cout << "Test 4 (List: 5->10->15->20, delete first twice): ";
    int expected4[] = {15, 20};
    Node *exp4 = createList(expected4, 2);
    cout << (result4a == 5 && result4b == 10 && compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Delete with large values
    // Step: head=1000->2000->3000
    // Expected: 2000->3000->NULL, return 1000
    int arr5[] = {1000, 2000, 3000};
    Node *test5 = createList(arr5, 3);
    int result5 = problem4_1(test5);
    cout << "Test 5 (List: 1000->2000->3000, delete first): ";
    int expected5[] = {2000, 3000};
    Node *exp5 = createList(expected5, 2);
    cout << (result5 == 1000 && compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem4_2()
{
    cout << "\n=== Testing Problem 4.2: Delete N Nodes from Beginning ===" << endl;

    // Test 1: Delete N nodes where N < list size
    // Step: head=1->2->3->4->5, N=3
    // Expected: 4->5->NULL, return 3
    int arr1[] = {1, 2, 3, 4, 5};
    Node *test1 = createList(arr1, 5);
    int result1 = problem4_2(test1, 3);
    cout << "Test 1 (List: 1->2->3->4->5, delete 3 nodes): ";
    int expected1[] = {4, 5};
    Node *exp1 = createList(expected1, 2);
    cout << (result1 == 3 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Delete N nodes where N > list size
    // Step: head=1->2, N=5
    // Expected: nullptr, return 2
    int arr2[] = {1, 2};
    Node *test2 = createList(arr2, 2);
    int result2 = problem4_2(test2, 5);
    cout << "Test 2 (List: 1->2, delete 5 nodes): ";
    cout << (result2 == 2 && test2 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 3: Delete N=0 nodes
    // Step: head=1->2->3, N=0
    // Expected: 1->2->3->NULL (unchanged), return 0
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    int result3 = problem4_2(test3, 0);
    cout << "Test 3 (List: 1->2->3, delete 0 nodes): ";
    int expected3[] = {1, 2, 3};
    Node *exp3 = createList(expected3, 3);
    cout << (result3 == 0 && compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Delete from empty list
    // Step: head=nullptr, N=3
    // Expected: nullptr, return 0
    Node *test4 = nullptr;
    int result4 = problem4_2(test4, 3);
    cout << "Test 4 (Empty list, delete 3 nodes): ";
    cout << (result4 == 0 && test4 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 5: Delete all nodes (N = list size)
    // Step: head=10->20->30, N=3
    // Expected: nullptr, return 3
    int arr5[] = {10, 20, 30};
    Node *test5 = createList(arr5, 3);
    int result5 = problem4_2(test5, 3);
    cout << "Test 5 (List: 10->20->30, delete 3 nodes - all): ";
    cout << (result5 == 3 && test5 == nullptr ? "PASS" : "FAIL") << endl;
}

void testProblem4_3()
{
    cout << "\n=== Testing Problem 4.3: Delete from Beginning Until Condition ===" << endl;

    // Test 1: Delete until finding value > threshold
    // Step: head=1->2->3->8->9, threshold=5
    // Expected: 8->9->NULL, return 3
    int arr1[] = {1, 2, 3, 8, 9};
    Node *test1 = createList(arr1, 5);
    int result1 = problem4_3(test1, 5);
    cout << "Test 1 (List: 1->2->3->8->9, threshold=5): ";
    int expected1[] = {8, 9};
    Node *exp1 = createList(expected1, 2);
    cout << (result1 == 3 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: First node already > threshold
    // Step: head=10->20->30, threshold=5
    // Expected: 10->20->30->NULL (unchanged), return 0
    int arr2[] = {10, 20, 30};
    Node *test2 = createList(arr2, 3);
    int result2 = problem4_3(test2, 5);
    cout << "Test 2 (List: 10->20->30, threshold=5 - first > threshold): ";
    int expected2[] = {10, 20, 30};
    Node *exp2 = createList(expected2, 3);
    cout << (result2 == 0 && compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: All nodes <= threshold
    // Step: head=1->2->3->4, threshold=10
    // Expected: nullptr, return 4
    int arr3[] = {1, 2, 3, 4};
    Node *test3 = createList(arr3, 4);
    int result3 = problem4_3(test3, 10);
    cout << "Test 3 (List: 1->2->3->4, threshold=10 - all deleted): ";
    cout << (result3 == 4 && test3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Empty list
    // Step: head=nullptr, threshold=5
    // Expected: nullptr, return 0
    Node *test4 = nullptr;
    int result4 = problem4_3(test4, 5);
    cout << "Test 4 (Empty list, threshold=5): ";
    cout << (result4 == 0 && test4 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 5: Threshold is 0
    // Step: head=0->0->5->10, threshold=0
    // Expected: 5->10->NULL, return 2
    int arr5[] = {0, 0, 5, 10};
    Node *test5 = createList(arr5, 4);
    int result5 = problem4_3(test5, 0);
    cout << "Test 5 (List: 0->0->5->10, threshold=0): ";
    int expected5[] = {5, 10};
    Node *exp5 = createList(expected5, 2);
    cout << (result5 == 2 && compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem5_1()
{
    cout << "\n=== Testing Problem 5.1: Delete Last Node ===" << endl;

    // Test 1: Delete from multi-node list
    // Step: head=1->2->3
    // Expected: 1->2->NULL, return 3
    int arr1[] = {1, 2, 3};
    Node *test1 = createList(arr1, 3);
    int result1 = problem5_1(test1);
    cout << "Test 1 (List: 1->2->3, delete last): ";
    int expected1[] = {1, 2};
    Node *exp1 = createList(expected1, 2);
    cout << (result1 == 3 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Delete from single-node list
    // Step: head=99
    // Expected: nullptr, return 99
    int arr2[] = {99};
    Node *test2 = createList(arr2, 1);
    int result2 = problem5_1(test2);
    cout << "Test 2 (List: 99, delete last): ";
    cout << (result2 == 99 && test2 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 3: Delete from empty list
    // Step: head=nullptr
    // Expected: nullptr, return -1
    Node *test3 = nullptr;
    int result3 = problem5_1(test3);
    cout << "Test 3 (Empty list, delete last): ";
    cout << (result3 == -1 && test3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Delete from two-node list
    // Step: head=10->20
    // Expected: 10->NULL, return 20
    int arr4[] = {10, 20};
    Node *test4 = createList(arr4, 2);
    int result4 = problem5_1(test4);
    cout << "Test 4 (List: 10->20, delete last): ";
    int expected4[] = {10};
    Node *exp4 = createList(expected4, 1);
    cout << (result4 == 20 && compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Delete last twice
    // Step: head=5->10->15->20, delete last twice
    // Expected: 5->10->NULL, returns 20 then 15
    int arr5[] = {5, 10, 15, 20};
    Node *test5 = createList(arr5, 4);
    int result5a = problem5_1(test5);
    int result5b = problem5_1(test5);
    cout << "Test 5 (List: 5->10->15->20, delete last twice): ";
    int expected5[] = {5, 10};
    Node *exp5 = createList(expected5, 2);
    cout << (result5a == 20 && result5b == 15 && compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem5_2()
{
    cout << "\n=== Testing Problem 5.2: Delete N Nodes from End ===" << endl;

    // Test 1: Delete N nodes from end where N < list size
    // Step: head=1->2->3->4->5, N=2
    // Expected: 1->2->3->NULL, return 2
    int arr1[] = {1, 2, 3, 4, 5};
    Node *test1 = createList(arr1, 5);
    int result1 = problem5_2(test1, 2);
    cout << "Test 1 (List: 1->2->3->4->5, delete last 2): ";
    int expected1[] = {1, 2, 3};
    Node *exp1 = createList(expected1, 3);
    cout << (result1 == 2 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Delete N nodes where N > list size
    // Step: head=1->2->3, N=5
    // Expected: nullptr, return 3
    int arr2[] = {1, 2, 3};
    Node *test2 = createList(arr2, 3);
    int result2 = problem5_2(test2, 5);
    cout << "Test 2 (List: 1->2->3, delete last 5): ";
    cout << (result2 == 3 && test2 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 3: Delete N=0 nodes
    // Step: head=10->20->30, N=0
    // Expected: 10->20->30->NULL (unchanged), return 0
    int arr3[] = {10, 20, 30};
    Node *test3 = createList(arr3, 3);
    int result3 = problem5_2(test3, 0);
    cout << "Test 3 (List: 10->20->30, delete last 0): ";
    int expected3[] = {10, 20, 30};
    Node *exp3 = createList(expected3, 3);
    cout << (result3 == 0 && compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Delete from empty list
    // Step: head=nullptr, N=2
    // Expected: nullptr, return 0
    Node *test4 = nullptr;
    int result4 = problem5_2(test4, 2);
    cout << "Test 4 (Empty list, delete last 2): ";
    cout << (result4 == 0 && test4 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 5: Delete all nodes (N = list size)
    // Step: head=7->8->9, N=3
    // Expected: nullptr, return 3
    int arr5[] = {7, 8, 9};
    Node *test5 = createList(arr5, 3);
    int result5 = problem5_2(test5, 3);
    cout << "Test 5 (List: 7->8->9, delete last 3 - all): ";
    cout << (result5 == 3 && test5 == nullptr ? "PASS" : "FAIL") << endl;
}

void testProblem5_3()
{
    cout << "\n=== Testing Problem 5.3: Delete from End While Sum Exceeds Target ===" << endl;

    // Test 1: Delete nodes until sum <= target
    // Step: head=10->20->30->40 (sum=100), target=50
    // Expected: 10->20->NULL (sum=30), return 2
    int arr1[] = {10, 20, 30, 40};
    Node *test1 = createList(arr1, 4);
    int result1 = problem5_3(test1, 50);
    cout << "Test 1 (List sum=100, target=50): ";
    int expected1[] = {10, 20};
    Node *exp1 = createList(expected1, 2);
    cout << (result1 == 2 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Sum already <= target
    // Step: head=5->10->15 (sum=30), target=50
    // Expected: 5->10->15->NULL (unchanged), return 0
    int arr2[] = {5, 10, 15};
    Node *test2 = createList(arr2, 3);
    int result2 = problem5_3(test2, 50);
    cout << "Test 2 (List sum=30, target=50 - no deletion): ";
    int expected2[] = {5, 10, 15};
    Node *exp2 = createList(expected2, 3);
    cout << (result2 == 0 && compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Delete all nodes
    // Step: head=100->200 (sum=300), target=10
    // Expected: nullptr, return 2
    int arr3[] = {100, 200};
    Node *test3 = createList(arr3, 2);
    int result3 = problem5_3(test3, 10);
    cout << "Test 3 (List sum=300, target=10 - delete all): ";
    cout << (result3 == 2 && test3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Empty list
    // Step: head=nullptr, target=100
    // Expected: nullptr, return 0
    Node *test4 = nullptr;
    int result4 = problem5_3(test4, 100);
    cout << "Test 4 (Empty list, target=100): ";
    cout << (result4 == 0 && test4 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 5: Target is 0
    // Step: head=1->2->3 (sum=6), target=0
    // Expected: nullptr, return 3
    int arr5[] = {1, 2, 3};
    Node *test5 = createList(arr5, 3);
    int result5 = problem5_3(test5, 0);
    cout << "Test 5 (List sum=6, target=0): ";
    cout << (result5 == 3 && test5 == nullptr ? "PASS" : "FAIL") << endl;
}

void testProblem6_1()
{
    cout << "\n=== Testing Problem 6.1: Delete Node at Position ===" << endl;

    // Test 1: Delete at position 0 (first node)
    // Step: head=1->2->3->4, position=0
    // Expected: 2->3->4->NULL, return true
    int arr1[] = {1, 2, 3, 4};
    Node *test1 = createList(arr1, 4);
    bool result1 = problem6_1(test1, 0);
    cout << "Test 1 (List: 1->2->3->4, delete pos 0): ";
    int expected1[] = {2, 3, 4};
    Node *exp1 = createList(expected1, 3);
    cout << (result1 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Delete at middle position
    // Step: head=1->2->3->4, position=2
    // Expected: 1->2->4->NULL, return true
    int arr2[] = {1, 2, 3, 4};
    Node *test2 = createList(arr2, 4);
    bool result2 = problem6_1(test2, 2);
    cout << "Test 2 (List: 1->2->3->4, delete pos 2): ";
    int expected2[] = {1, 2, 4};
    Node *exp2 = createList(expected2, 3);
    cout << (result2 && compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Delete at last position
    // Step: head=10->20->30, position=2
    // Expected: 10->20->NULL, return true
    int arr3[] = {10, 20, 30};
    Node *test3 = createList(arr3, 3);
    bool result3 = problem6_1(test3, 2);
    cout << "Test 3 (List: 10->20->30, delete pos 2 - last): ";
    int expected3[] = {10, 20};
    Node *exp3 = createList(expected3, 2);
    cout << (result3 && compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Invalid position (too large)
    // Step: head=1->2->3, position=10
    // Expected: 1->2->3->NULL (unchanged), return false
    int arr4[] = {1, 2, 3};
    Node *test4 = createList(arr4, 3);
    bool result4 = problem6_1(test4, 10);
    cout << "Test 4 (List: 1->2->3, delete pos 10 - invalid): ";
    int expected4[] = {1, 2, 3};
    Node *exp4 = createList(expected4, 3);
    cout << (!result4 && compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Delete from single-node list
    // Step: head=42, position=0
    // Expected: nullptr, return true
    int arr5[] = {42};
    Node *test5 = createList(arr5, 1);
    bool result5 = problem6_1(test5, 0);
    cout << "Test 5 (List: 42, delete pos 0): ";
    cout << (result5 && test5 == nullptr ? "PASS" : "FAIL") << endl;
}

void testProblem6_2()
{
    cout << "\n=== Testing Problem 6.2: Delete All Even Positioned Nodes ===" << endl;

    // Test 1: Delete even positions from list
    // Step: head=1->2->3->4->5 (positions 0,1,2,3,4)
    // Expected: 2->4->NULL (keep positions 1,3), return 3
    int arr1[] = {1, 2, 3, 4, 5};
    Node *test1 = createList(arr1, 5);
    int result1 = problem6_2(test1);
    cout << "Test 1 (List: 1->2->3->4->5, delete even positions): ";
    int expected1[] = {2, 4};
    Node *exp1 = createList(expected1, 2);
    cout << (result1 == 3 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Delete from two-node list
    // Step: head=10->20 (positions 0,1)
    // Expected: 20->NULL (keep position 1), return 1
    int arr2[] = {10, 20};
    Node *test2 = createList(arr2, 2);
    int result2 = problem6_2(test2);
    cout << "Test 2 (List: 10->20, delete even positions): ";
    int expected2[] = {20};
    Node *exp2 = createList(expected2, 1);
    cout << (result2 == 1 && compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Delete from single-node list
    // Step: head=99 (position 0)
    // Expected: nullptr, return 1
    int arr3[] = {99};
    Node *test3 = createList(arr3, 1);
    int result3 = problem6_2(test3);
    cout << "Test 3 (List: 99, delete even positions): ";
    cout << (result3 == 1 && test3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Empty list
    // Step: head=nullptr
    // Expected: nullptr, return 0
    Node *test4 = nullptr;
    int result4 = problem6_2(test4);
    cout << "Test 4 (Empty list, delete even positions): ";
    cout << (result4 == 0 && test4 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 5: Delete from even-length list
    // Step: head=1->2->3->4->5->6 (positions 0-5)
    // Expected: 2->4->6->NULL (keep positions 1,3,5), return 3
    int arr5[] = {1, 2, 3, 4, 5, 6};
    Node *test5 = createList(arr5, 6);
    int result5 = problem6_2(test5);
    cout << "Test 5 (List: 1->2->3->4->5->6, delete even positions): ";
    int expected5[] = {2, 4, 6};
    Node *exp5 = createList(expected5, 3);
    cout << (result5 == 3 && compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem6_3()
{
    cout << "\n=== Testing Problem 6.3: Delete Range of Positions ===" << endl;

    // Test 1: Delete middle range
    // Step: head=1->2->3->4->5, start=1, end=3
    // Expected: 1->5->NULL, return 3
    int arr1[] = {1, 2, 3, 4, 5};
    Node *test1 = createList(arr1, 5);
    int result1 = problem6_3(test1, 1, 3);
    cout << "Test 1 (List: 1->2->3->4->5, delete pos 1-3): ";
    int expected1[] = {1, 5};
    Node *exp1 = createList(expected1, 2);
    cout << (result1 == 3 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Delete from beginning
    // Step: head=10->20->30->40, start=0, end=2
    // Expected: 40->NULL, return 3
    int arr2[] = {10, 20, 30, 40};
    Node *test2 = createList(arr2, 4);
    int result2 = problem6_3(test2, 0, 2);
    cout << "Test 2 (List: 10->20->30->40, delete pos 0-2): ";
    int expected2[] = {40};
    Node *exp2 = createList(expected2, 1);
    cout << (result2 == 3 && compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Delete to end
    // Step: head=5->10->15->20->25, start=2, end=4
    // Expected: 5->10->NULL, return 3
    int arr3[] = {5, 10, 15, 20, 25};
    Node *test3 = createList(arr3, 5);
    int result3 = problem6_3(test3, 2, 4);
    cout << "Test 3 (List: 5->10->15->20->25, delete pos 2-4): ";
    int expected3[] = {5, 10};
    Node *exp3 = createList(expected3, 2);
    cout << (result3 == 3 && compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Delete single position (start=end)
    // Step: head=1->2->3->4, start=2, end=2
    // Expected: 1->2->4->NULL, return 1
    int arr4[] = {1, 2, 3, 4};
    Node *test4 = createList(arr4, 4);
    int result4 = problem6_3(test4, 2, 2);
    cout << "Test 4 (List: 1->2->3->4, delete pos 2-2): ";
    int expected4[] = {1, 2, 4};
    Node *exp4 = createList(expected4, 3);
    cout << (result4 == 1 && compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Delete all nodes
    // Step: head=7->8->9, start=0, end=2
    // Expected: nullptr, return 3
    int arr5[] = {7, 8, 9};
    Node *test5 = createList(arr5, 3);
    int result5 = problem6_3(test5, 0, 2);
    cout << "Test 5 (List: 7->8->9, delete pos 0-2 - all): ";
    cout << (result5 == 3 && test5 == nullptr ? "PASS" : "FAIL") << endl;
}

void testProblem7_1()
{
    cout << "\n=== Testing Problem 7.1: Find First Occurrence Position ===" << endl;

    // Test 1: Find value in middle
    // Step: head=10->20->30->20, value=20
    // Expected: return 1 (first occurrence at position 1)
    int arr1[] = {10, 20, 30, 20};
    Node *test1 = createList(arr1, 4);
    int result1 = problem7_1(test1, 20);
    cout << "Test 1 (List: 10->20->30->20, find 20): ";
    cout << (result1 == 1 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: Find value at beginning
    // Step: head=5->10->15, value=5
    // Expected: return 0
    int arr2[] = {5, 10, 15};
    Node *test2 = createList(arr2, 3);
    int result2 = problem7_1(test2, 5);
    cout << "Test 2 (List: 5->10->15, find 5): ";
    cout << (result2 == 0 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);

    // Test 3: Find value at end
    // Step: head=1->2->3->4, value=4
    // Expected: return 3
    int arr3[] = {1, 2, 3, 4};
    Node *test3 = createList(arr3, 4);
    int result3 = problem7_1(test3, 4);
    cout << "Test 3 (List: 1->2->3->4, find 4): ";
    cout << (result3 == 3 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);

    // Test 4: Value not found
    // Step: head=10->20->30, value=99
    // Expected: return -1
    int arr4[] = {10, 20, 30};
    Node *test4 = createList(arr4, 3);
    int result4 = problem7_1(test4, 99);
    cout << "Test 4 (List: 10->20->30, find 99 - not found): ";
    cout << (result4 == -1 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);

    // Test 5: Empty list
    // Step: head=nullptr, value=5
    // Expected: return -1
    Node *test5 = nullptr;
    int result5 = problem7_1(test5, 5);
    cout << "Test 5 (Empty list, find 5): ";
    cout << (result5 == -1 ? "PASS" : "FAIL") << endl;
}

void testProblem7_2()
{
    cout << "\n=== Testing Problem 7.2: Count Occurrences ===" << endl;

    // Test 1: Count multiple occurrences
    // Step: head=1->2->2->3->2->4, value=2
    // Expected: return 3
    int arr1[] = {1, 2, 2, 3, 2, 4};
    Node *test1 = createList(arr1, 6);
    int result1 = problem7_2(test1, 2);
    cout << "Test 1 (List: 1->2->2->3->2->4, count 2): ";
    cout << (result1 == 3 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: Count single occurrence
    // Step: head=10->20->30, value=20
    // Expected: return 1
    int arr2[] = {10, 20, 30};
    Node *test2 = createList(arr2, 3);
    int result2 = problem7_2(test2, 20);
    cout << "Test 2 (List: 10->20->30, count 20): ";
    cout << (result2 == 1 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);

    // Test 3: Value not in list
    // Step: head=1->2->3, value=99
    // Expected: return 0
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    int result3 = problem7_2(test3, 99);
    cout << "Test 3 (List: 1->2->3, count 99 - not found): ";
    cout << (result3 == 0 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);

    // Test 4: All nodes have same value
    // Step: head=5->5->5->5, value=5
    // Expected: return 4
    int arr4[] = {5, 5, 5, 5};
    Node *test4 = createList(arr4, 4);
    int result4 = problem7_2(test4, 5);
    cout << "Test 4 (List: 5->5->5->5, count 5): ";
    cout << (result4 == 4 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);

    // Test 5: Empty list
    // Step: head=nullptr, value=10
    // Expected: return 0
    Node *test5 = nullptr;
    int result5 = problem7_2(test5, 10);
    cout << "Test 5 (Empty list, count 10): ";
    cout << (result5 == 0 ? "PASS" : "FAIL") << endl;
}

void testProblem7_3()
{
    cout << "\n=== Testing Problem 7.3: Find Kth Occurrence Position ===" << endl;

    // Test 1: Find 2nd occurrence
    // Step: head=5->3->5->7->5, value=5, k=2
    // Expected: return 2 (second 5 is at position 2)
    int arr1[] = {5, 3, 5, 7, 5};
    Node *test1 = createList(arr1, 5);
    int result1 = problem7_3(test1, 5, 2);
    cout << "Test 1 (List: 5->3->5->7->5, find 2nd occurrence of 5): ";
    cout << (result1 == 2 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: Find 1st occurrence
    // Step: head=10->20->30->20, value=20, k=1
    // Expected: return 1
    int arr2[] = {10, 20, 30, 20};
    Node *test2 = createList(arr2, 4);
    int result2 = problem7_3(test2, 20, 1);
    cout << "Test 2 (List: 10->20->30->20, find 1st occurrence of 20): ";
    cout << (result2 == 1 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);

    // Test 3: K exceeds occurrences
    // Step: head=1->2->1->3, value=1, k=3
    // Expected: return -1 (only 2 occurrences of 1)
    int arr3[] = {1, 2, 1, 3};
    Node *test3 = createList(arr3, 4);
    int result3 = problem7_3(test3, 1, 3);
    cout << "Test 3 (List: 1->2->1->3, find 3rd occurrence of 1 - doesn't exist): ";
    cout << (result3 == -1 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);

    // Test 4: Value not in list
    // Step: head=5->10->15, value=99, k=1
    // Expected: return -1
    int arr4[] = {5, 10, 15};
    Node *test4 = createList(arr4, 3);
    int result4 = problem7_3(test4, 99, 1);
    cout << "Test 4 (List: 5->10->15, find 1st occurrence of 99 - not found): ";
    cout << (result4 == -1 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);

    // Test 5: Find 3rd occurrence in list with many duplicates
    // Step: head=7->7->3->7->5->7, value=7, k=3
    // Expected: return 3 (third 7 is at position 3)
    int arr5[] = {7, 7, 3, 7, 5, 7};
    Node *test5 = createList(arr5, 6);
    int result5 = problem7_3(test5, 7, 3);
    cout << "Test 5 (List: 7->7->3->7->5->7, find 3rd occurrence of 7): ";
    cout << (result5 == 3 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
}

void testProblem8_1()
{
    cout << "\n=== Testing Problem 8.1: Count Total Nodes ===" << endl;

    // Test 1: Count nodes in regular list
    // Step: head=1->2->3->4
    // Expected: return 4
    int arr1[] = {1, 2, 3, 4};
    Node *test1 = createList(arr1, 4);
    int result1 = problem8_1(test1);
    cout << "Test 1 (List: 1->2->3->4, count nodes): ";
    cout << (result1 == 4 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: Count single node
    // Step: head=42
    // Expected: return 1
    int arr2[] = {42};
    Node *test2 = createList(arr2, 1);
    int result2 = problem8_1(test2);
    cout << "Test 2 (List: 42, count nodes): ";
    cout << (result2 == 1 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);

    // Test 3: Empty list
    // Step: head=nullptr
    // Expected: return 0
    Node *test3 = nullptr;
    int result3 = problem8_1(test3);
    cout << "Test 3 (Empty list, count nodes): ";
    cout << (result3 == 0 ? "PASS" : "FAIL") << endl;

    // Test 4: Count larger list
    // Step: head=10->20->30->40->50->60->70
    // Expected: return 7
    int arr4[] = {10, 20, 30, 40, 50, 60, 70};
    Node *test4 = createList(arr4, 7);
    int result4 = problem8_1(test4);
    cout << "Test 4 (List: 10->20->30->40->50->60->70, count nodes): ";
    cout << (result4 == 7 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);

    // Test 5: Count two nodes
    // Step: head=5->10
    // Expected: return 2
    int arr5[] = {5, 10};
    Node *test5 = createList(arr5, 2);
    int result5 = problem8_1(test5);
    cout << "Test 5 (List: 5->10, count nodes): ";
    cout << (result5 == 2 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
}

void testProblem8_2()
{
    cout << "\n=== Testing Problem 8.2: Count Nodes with Value Greater Than X ===" << endl;

    // Test 1: Count nodes > x
    // Step: head=5->10->3->15->8, x=7
    // Expected: return 3 (nodes: 10, 15, 8)
    int arr1[] = {5, 10, 3, 15, 8};
    Node *test1 = createList(arr1, 5);
    int result1 = problem8_2(test1, 7);
    cout << "Test 1 (List: 5->10->3->15->8, count > 7): ";
    cout << (result1 == 3 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: All nodes > x
    // Step: head=10->20->30, x=5
    // Expected: return 3
    int arr2[] = {10, 20, 30};
    Node *test2 = createList(arr2, 3);
    int result2 = problem8_2(test2, 5);
    cout << "Test 2 (List: 10->20->30, count > 5 - all): ";
    cout << (result2 == 3 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);

    // Test 3: No nodes > x
    // Step: head=1->2->3, x=10
    // Expected: return 0
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    int result3 = problem8_2(test3, 10);
    cout << "Test 3 (List: 1->2->3, count > 10 - none): ";
    cout << (result3 == 0 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);

    // Test 4: Empty list
    // Step: head=nullptr, x=5
    // Expected: return 0
    Node *test4 = nullptr;
    int result4 = problem8_2(test4, 5);
    cout << "Test 4 (Empty list, count > 5): ";
    cout << (result4 == 0 ? "PASS" : "FAIL") << endl;

    // Test 5: Count with negative numbers
    // Step: head=-5->0->5->10, x=0
    // Expected: return 2 (nodes: 5, 10)
    int arr5[] = {-5, 0, 5, 10};
    Node *test5 = createList(arr5, 4);
    int result5 = problem8_2(test5, 0);
    cout << "Test 5 (List: -5->0->5->10, count > 0): ";
    cout << (result5 == 2 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
}

void testProblem8_3()
{
    cout << "\n=== Testing Problem 8.3: Count Nodes in Range ===" << endl;

    // Test 1: Count nodes in range
    // Step: head=2->8->5->12->6->3, min=4, max=10
    // Expected: return 3 (nodes: 8, 5, 6)
    int arr1[] = {2, 8, 5, 12, 6, 3};
    Node *test1 = createList(arr1, 6);
    int result1 = problem8_3(test1, 4, 10);
    cout << "Test 1 (List: 2->8->5->12->6->3, count in range [4,10]): ";
    cout << (result1 == 3 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: All nodes in range
    // Step: head=5->6->7->8, min=1, max=10
    // Expected: return 4
    int arr2[] = {5, 6, 7, 8};
    Node *test2 = createList(arr2, 4);
    int result2 = problem8_3(test2, 1, 10);
    cout << "Test 2 (List: 5->6->7->8, count in range [1,10] - all): ";
    cout << (result2 == 4 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);

    // Test 3: No nodes in range
    // Step: head=1->2->3, min=10, max=20
    // Expected: return 0
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    int result3 = problem8_3(test3, 10, 20);
    cout << "Test 3 (List: 1->2->3, count in range [10,20] - none): ";
    cout << (result3 == 0 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);

    // Test 4: Count at boundaries
    // Step: head=5->10->15->20, min=10, max=15
    // Expected: return 2 (nodes: 10, 15)
    int arr4[] = {5, 10, 15, 20};
    Node *test4 = createList(arr4, 4);
    int result4 = problem8_3(test4, 10, 15);
    cout << "Test 4 (List: 5->10->15->20, count in range [10,15]): ";
    cout << (result4 == 2 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);

    // Test 5: Empty list
    // Step: head=nullptr, min=5, max=10
    // Expected: return 0
    Node *test5 = nullptr;
    int result5 = problem8_3(test5, 5, 10);
    cout << "Test 5 (Empty list, count in range [5,10]): ";
    cout << (result5 == 0 ? "PASS" : "FAIL") << endl;
}

void testProblem9_1()
{
    cout << "\n=== Testing Problem 9.1: Reverse Entire List ===" << endl;

    // Test 1: Reverse regular list
    // Step: head=1->2->3->4
    // Expected: 4->3->2->1->NULL
    int arr1[] = {1, 2, 3, 4};
    Node *test1 = createList(arr1, 4);
    problem9_1(test1);
    cout << "Test 1 (List: 1->2->3->4, reverse): ";
    int expected1[] = {4, 3, 2, 1};
    Node *exp1 = createList(expected1, 4);
    cout << (compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Reverse single node
    // Step: head=42
    // Expected: 42->NULL (unchanged)
    int arr2[] = {42};
    Node *test2 = createList(arr2, 1);
    problem9_1(test2);
    cout << "Test 2 (List: 42, reverse): ";
    int expected2[] = {42};
    Node *exp2 = createList(expected2, 1);
    cout << (compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Reverse empty list
    // Step: head=nullptr
    // Expected: nullptr
    Node *test3 = nullptr;
    problem9_1(test3);
    cout << "Test 3 (Empty list, reverse): ";
    cout << (test3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Reverse two nodes
    // Step: head=10->20
    // Expected: 20->10->NULL
    int arr4[] = {10, 20};
    Node *test4 = createList(arr4, 2);
    problem9_1(test4);
    cout << "Test 4 (List: 10->20, reverse): ";
    int expected4[] = {20, 10};
    Node *exp4 = createList(expected4, 2);
    cout << (compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Reverse larger list
    // Step: head=5->10->15->20->25
    // Expected: 25->20->15->10->5->NULL
    int arr5[] = {5, 10, 15, 20, 25};
    Node *test5 = createList(arr5, 5);
    problem9_1(test5);
    cout << "Test 5 (List: 5->10->15->20->25, reverse): ";
    int expected5[] = {25, 20, 15, 10, 5};
    Node *exp5 = createList(expected5, 5);
    cout << (compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem9_2()
{
    cout << "\n=== Testing Problem 9.2: Check if List is Palindrome ===" << endl;

    // Test 1: Palindrome with odd length
    // Step: head=1->2->3->2->1
    // Expected: return true
    int arr1[] = {1, 2, 3, 2, 1};
    Node *test1 = createList(arr1, 5);
    bool result1 = problem9_2(test1);
    cout << "Test 1 (List: 1->2->3->2->1, check palindrome): ";
    cout << (result1 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);

    // Test 2: Palindrome with even length
    // Step: head=1->2->2->1
    // Expected: return true
    int arr2[] = {1, 2, 2, 1};
    Node *test2 = createList(arr2, 4);
    bool result2 = problem9_2(test2);
    cout << "Test 2 (List: 1->2->2->1, check palindrome): ";
    cout << (result2 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);

    // Test 3: Not a palindrome
    // Step: head=1->2->3
    // Expected: return false
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    bool result3 = problem9_2(test3);
    cout << "Test 3 (List: 1->2->3, check palindrome - not): ";
    cout << (!result3 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);

    // Test 4: Single node (palindrome)
    // Step: head=5
    // Expected: return true
    int arr4[] = {5};
    Node *test4 = createList(arr4, 1);
    bool result4 = problem9_2(test4);
    cout << "Test 4 (List: 5, check palindrome): ";
    cout << (result4 ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);

    // Test 5: Empty list (palindrome)
    // Step: head=nullptr
    // Expected: return true
    Node *test5 = nullptr;
    bool result5 = problem9_2(test5);
    cout << "Test 5 (Empty list, check palindrome): ";
    cout << (result5 ? "PASS" : "FAIL") << endl;
}

void testProblem9_3()
{
    cout << "\n=== Testing Problem 9.3: Reverse List in Groups of K ===" << endl;

    // Test 1: Reverse in groups of 3
    // Step: head=1->2->3->4->5->6->7, k=3
    // Expected: 3->2->1->6->5->4->7->NULL
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    Node *test1 = createList(arr1, 7);
    problem9_3(test1, 3);
    cout << "Test 1 (List: 1->2->3->4->5->6->7, reverse groups of 3): ";
    int expected1[] = {3, 2, 1, 6, 5, 4, 7};
    Node *exp1 = createList(expected1, 7);
    cout << (compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Reverse in groups of 2
    // Step: head=1->2->3->4->5, k=2
    // Expected: 2->1->4->3->5->NULL
    int arr2[] = {1, 2, 3, 4, 5};
    Node *test2 = createList(arr2, 5);
    problem9_3(test2, 2);
    cout << "Test 2 (List: 1->2->3->4->5, reverse groups of 2): ";
    int expected2[] = {2, 1, 4, 3, 5};
    Node *exp2 = createList(expected2, 5);
    cout << (compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: K equals list size
    // Step: head=1->2->3->4, k=4
    // Expected: 4->3->2->1->NULL
    int arr3[] = {1, 2, 3, 4};
    Node *test3 = createList(arr3, 4);
    problem9_3(test3, 4);
    cout << "Test 3 (List: 1->2->3->4, reverse groups of 4): ";
    int expected3[] = {4, 3, 2, 1};
    Node *exp3 = createList(expected3, 4);
    cout << (compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: K=1 (no change)
    // Step: head=5->10->15, k=1
    // Expected: 5->10->15->NULL (unchanged)
    int arr4[] = {5, 10, 15};
    Node *test4 = createList(arr4, 3);
    problem9_3(test4, 1);
    cout << "Test 4 (List: 5->10->15, reverse groups of 1): ";
    int expected4[] = {5, 10, 15};
    Node *exp4 = createList(expected4, 3);
    cout << (compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: K larger than list
    // Step: head=1->2->3, k=5
    // Expected: 3->2->1->NULL
    int arr5[] = {1, 2, 3};
    Node *test5 = createList(arr5, 3);
    problem9_3(test5, 5);
    cout << "Test 5 (List: 1->2->3, reverse groups of 5): ";
    int expected5[] = {3, 2, 1};
    Node *exp5 = createList(expected5, 3);
    cout << (compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem10_1()
{
    cout << "\n=== Testing Problem 10.1: Display List in Order ===" << endl;

    // Test 1: Display regular list
    // Step: head=1->2->3
    // Expected output: "1 -> 2 -> 3 -> NULL"
    cout << "Test 1 (List: 1->2->3, display): ";
    int arr1[] = {1, 2, 3};
    Node *test1 = createList(arr1, 3);
    problem10_1(test1);
    deleteAllNodes(test1);

    // Test 2: Display single node
    // Step: head=42
    // Expected output: "42 -> NULL"
    cout << "Test 2 (List: 42, display): ";
    int arr2[] = {42};
    Node *test2 = createList(arr2, 1);
    problem10_1(test2);
    deleteAllNodes(test2);

    // Test 3: Display empty list
    // Step: head=nullptr
    // Expected output: "NULL" or "Empty"
    cout << "Test 3 (Empty list, display): ";
    Node *test3 = nullptr;
    problem10_1(test3);

    // Test 4: Display larger list
    // Step: head=10->20->30->40->50
    // Expected output: "10 -> 20 -> 30 -> 40 -> 50 -> NULL"
    cout << "Test 4 (List: 10->20->30->40->50, display): ";
    int arr4[] = {10, 20, 30, 40, 50};
    Node *test4 = createList(arr4, 5);
    problem10_1(test4);
    deleteAllNodes(test4);

    // Test 5: Display with negative numbers
    // Step: head=-5->0->5
    // Expected output: "-5 -> 0 -> 5 -> NULL"
    cout << "Test 5 (List: -5->0->5, display): ";
    int arr5[] = {-5, 0, 5};
    Node *test5 = createList(arr5, 3);
    problem10_1(test5);
    deleteAllNodes(test5);
}

void testProblem10_2()
{
    cout << "\n=== Testing Problem 10.2: Display List in Reverse Order ===" << endl;

    // Test 1: Display reverse of regular list
    // Step: head=1->2->3
    // Expected output: "3 -> 2 -> 1 -> NULL"
    cout << "Test 1 (List: 1->2->3, display reverse): ";
    int arr1[] = {1, 2, 3};
    Node *test1 = createList(arr1, 3);
    problem10_2(test1);
    deleteAllNodes(test1);

    // Test 2: Display reverse of single node
    // Step: head=99
    // Expected output: "99 -> NULL"
    cout << "Test 2 (List: 99, display reverse): ";
    int arr2[] = {99};
    Node *test2 = createList(arr2, 1);
    problem10_2(test2);
    deleteAllNodes(test2);

    // Test 3: Display reverse of empty list
    // Step: head=nullptr
    // Expected output: "NULL" or "Empty"
    cout << "Test 3 (Empty list, display reverse): ";
    Node *test3 = nullptr;
    problem10_2(test3);

    // Test 4: Display reverse of two nodes
    // Step: head=10->20
    // Expected output: "20 -> 10 -> NULL"
    cout << "Test 4 (List: 10->20, display reverse): ";
    int arr4[] = {10, 20};
    Node *test4 = createList(arr4, 2);
    problem10_2(test4);
    deleteAllNodes(test4);

    // Test 5: Display reverse of larger list
    // Step: head=5->10->15->20->25
    // Expected output: "25 -> 20 -> 15 -> 10 -> 5 -> NULL"
    cout << "Test 5 (List: 5->10->15->20->25, display reverse): ";
    int arr5[] = {5, 10, 15, 20, 25};
    Node *test5 = createList(arr5, 5);
    problem10_2(test5);
    deleteAllNodes(test5);
}

void testProblem10_3()
{
    cout << "\n=== Testing Problem 10.3: Display Nodes at Even Positions ===" << endl;

    // Test 1: Display even positions from list
    // Step: head=10->20->30->40->50 (positions 0,1,2,3,4)
    // Expected output: "10 -> 30 -> 50 -> NULL" (positions 0,2,4)
    cout << "Test 1 (List: 10->20->30->40->50, display even positions): ";
    int arr1[] = {10, 20, 30, 40, 50};
    Node *test1 = createList(arr1, 5);
    problem10_3(test1);
    deleteAllNodes(test1);

    // Test 2: Display single node (position 0)
    // Step: head=42
    // Expected output: "42 -> NULL"
    cout << "Test 2 (List: 42, display even positions): ";
    int arr2[] = {42};
    Node *test2 = createList(arr2, 1);
    problem10_3(test2);
    deleteAllNodes(test2);

    // Test 3: Display empty list
    // Step: head=nullptr
    // Expected output: "NULL" or "Empty"
    cout << "Test 3 (Empty list, display even positions): ";
    Node *test3 = nullptr;
    problem10_3(test3);

    // Test 4: Display from two-node list
    // Step: head=5->10 (positions 0,1)
    // Expected output: "5 -> NULL" (position 0)
    cout << "Test 4 (List: 5->10, display even positions): ";
    int arr4[] = {5, 10};
    Node *test4 = createList(arr4, 2);
    problem10_3(test4);
    deleteAllNodes(test4);

    // Test 5: Display from larger list
    // Step: head=1->2->3->4->5->6->7 (positions 0-6)
    // Expected output: "1 -> 3 -> 5 -> 7 -> NULL" (positions 0,2,4,6)
    cout << "Test 5 (List: 1->2->3->4->5->6->7, display even positions): ";
    int arr5[] = {1, 2, 3, 4, 5, 6, 7};
    Node *test5 = createList(arr5, 7);
    problem10_3(test5);
    deleteAllNodes(test5);
}

void testProblem11_1()
{
    cout << "\n=== Testing Problem 11.1: Delete All Nodes ===" << endl;

    // Test 1: Delete all from regular list
    // Step: head=1->2->3
    // Expected: nullptr, return 3
    int arr1[] = {1, 2, 3};
    Node *test1 = createList(arr1, 3);
    int result1 = problem11_1(test1);
    cout << "Test 1 (List: 1->2->3, delete all): ";
    cout << (result1 == 3 && test1 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 2: Delete all from single node
    // Step: head=42
    // Expected: nullptr, return 1
    int arr2[] = {42};
    Node *test2 = createList(arr2, 1);
    int result2 = problem11_1(test2);
    cout << "Test 2 (List: 42, delete all): ";
    cout << (result2 == 1 && test2 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 3: Delete all from empty list
    // Step: head=nullptr
    // Expected: nullptr, return 0
    Node *test3 = nullptr;
    int result3 = problem11_1(test3);
    cout << "Test 3 (Empty list, delete all): ";
    cout << (result3 == 0 && test3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Delete all from two nodes
    // Step: head=10->20
    // Expected: nullptr, return 2
    int arr4[] = {10, 20};
    Node *test4 = createList(arr4, 2);
    int result4 = problem11_1(test4);
    cout << "Test 4 (List: 10->20, delete all): ";
    cout << (result4 == 2 && test4 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 5: Delete all from larger list
    // Step: head=5->10->15->20->25
    // Expected: nullptr, return 5
    int arr5[] = {5, 10, 15, 20, 25};
    Node *test5 = createList(arr5, 5);
    int result5 = problem11_1(test5);
    cout << "Test 5 (List: 5->10->15->20->25, delete all): ";
    cout << (result5 == 5 && test5 == nullptr ? "PASS" : "FAIL") << endl;
}

void testProblem11_2()
{
    cout << "\n=== Testing Problem 11.2: Delete All Nodes with Specific Value ===" << endl;

    // Test 1: Delete multiple occurrences
    // Step: head=1->2->3->2->4->2, target=2
    // Expected: 1->3->4->NULL, return 3
    int arr1[] = {1, 2, 3, 2, 4, 2};
    Node *test1 = createList(arr1, 6);
    int result1 = problem11_2(test1, 2);
    cout << "Test 1 (List: 1->2->3->2->4->2, delete all 2s): ";
    int expected1[] = {1, 3, 4};
    Node *exp1 = createList(expected1, 3);
    cout << (result1 == 3 && compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Delete all nodes (all have target value)
    // Step: head=5->5->5, target=5
    // Expected: nullptr, return 3
    int arr2[] = {5, 5, 5};
    Node *test2 = createList(arr2, 3);
    int result2 = problem11_2(test2, 5);
    cout << "Test 2 (List: 5->5->5, delete all 5s): ";
    cout << (result2 == 3 && test2 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 3: Target not in list
    // Step: head=1->2->3, target=99
    // Expected: 1->2->3->NULL (unchanged), return 0
    int arr3[] = {1, 2, 3};
    Node *test3 = createList(arr3, 3);
    int result3 = problem11_2(test3, 99);
    cout << "Test 3 (List: 1->2->3, delete all 99s - not found): ";
    int expected3[] = {1, 2, 3};
    Node *exp3 = createList(expected3, 3);
    cout << (result3 == 0 && compareLists(test3, exp3) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test3);
    deleteAllNodes(exp3);

    // Test 4: Delete from head only
    // Step: head=10->20->30, target=10
    // Expected: 20->30->NULL, return 1
    int arr4[] = {10, 20, 30};
    Node *test4 = createList(arr4, 3);
    int result4 = problem11_2(test4, 10);
    cout << "Test 4 (List: 10->20->30, delete all 10s): ";
    int expected4[] = {20, 30};
    Node *exp4 = createList(expected4, 2);
    cout << (result4 == 1 && compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Empty list
    // Step: head=nullptr, target=5
    // Expected: nullptr, return 0
    Node *test5 = nullptr;
    int result5 = problem11_2(test5, 5);
    cout << "Test 5 (Empty list, delete all 5s): ";
    cout << (result5 == 0 && test5 == nullptr ? "PASS" : "FAIL") << endl;
}

void testProblem11_3()
{
    cout << "\n=== Testing Problem 11.3: Clear List and Return Statistics ===" << endl;

    // Test 1: Clear list and get stats
    // Step: head=5->2->8->3
    // Expected: nullptr, result=[4, 18, 8]
    int arr1[] = {5, 2, 8, 3};
    Node *test1 = createList(arr1, 4);
    int result1[3];
    problem11_3(test1, result1);
    cout << "Test 1 (List: 5->2->8->3, clear and stats): ";
    cout << (test1 == nullptr && result1[0] == 4 && result1[1] == 18 && result1[2] == 8 ? "PASS" : "FAIL") << endl;

    // Test 2: Clear single node
    // Step: head=42
    // Expected: nullptr, result=[1, 42, 42]
    int arr2[] = {42};
    Node *test2 = createList(arr2, 1);
    int result2[3];
    problem11_3(test2, result2);
    cout << "Test 2 (List: 42, clear and stats): ";
    cout << (test2 == nullptr && result2[0] == 1 && result2[1] == 42 && result2[2] == 42 ? "PASS" : "FAIL") << endl;

    // Test 3: Clear empty list
    // Step: head=nullptr
    // Expected: nullptr, result=[-1, -1, -1]
    Node *test3 = nullptr;
    int result3[3];
    problem11_3(test3, result3);
    cout << "Test 3 (Empty list, clear and stats): ";
    cout << (test3 == nullptr && result3[0] == -1 && result3[1] == -1 && result3[2] == -1 ? "PASS" : "FAIL") << endl;

    // Test 4: Clear with max at beginning
    // Step: head=10->5->3->2
    // Expected: nullptr, result=[4, 20, 10]
    int arr4[] = {10, 5, 3, 2};
    Node *test4 = createList(arr4, 4);
    int result4[3];
    problem11_3(test4, result4);
    cout << "Test 4 (List: 10->5->3->2, clear and stats): ";
    cout << (test4 == nullptr && result4[0] == 4 && result4[1] == 20 && result4[2] == 10 ? "PASS" : "FAIL") << endl;

    // Test 5: Clear with max at end
    // Step: head=1->2->3->100
    // Expected: nullptr, result=[4, 106, 100]
    int arr5[] = {1, 2, 3, 100};
    Node *test5 = createList(arr5, 4);
    int result5[3];
    problem11_3(test5, result5);
    cout << "Test 5 (List: 1->2->3->100, clear and stats): ";
    cout << (test5 == nullptr && result5[0] == 4 && result5[1] == 106 && result5[2] == 100 ? "PASS" : "FAIL") << endl;
}

void testProblem12_1()
{
    cout << "\n=== Testing Problem 12.1: Convert Array to Linked List ===" << endl;

    // Test 1: Convert regular array
    // Step: array=[1,2,3,4], size=4
    // Expected: 1->2->3->4->NULL
    int arr1[] = {1, 2, 3, 4};
    Node *test1 = problem12_1(arr1, 4);
    cout << "Test 1 (Array: [1,2,3,4], convert to list): ";
    int expected1[] = {1, 2, 3, 4};
    Node *exp1 = createList(expected1, 4);
    cout << (compareLists(test1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test1);
    deleteAllNodes(exp1);

    // Test 2: Convert single element
    // Step: array=[42], size=1
    // Expected: 42->NULL
    int arr2[] = {42};
    Node *test2 = problem12_1(arr2, 1);
    cout << "Test 2 (Array: [42], convert to list): ";
    int expected2[] = {42};
    Node *exp2 = createList(expected2, 1);
    cout << (compareLists(test2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test2);
    deleteAllNodes(exp2);

    // Test 3: Convert empty array
    // Step: array=[], size=0
    // Expected: nullptr
    int arr3[] = {};
    Node *test3 = problem12_1(arr3, 0);
    cout << "Test 3 (Array: [], convert to list): ";
    cout << (test3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Convert with negative numbers
    // Step: array=[-5,0,5,10], size=4
    // Expected: -5->0->5->10->NULL
    int arr4[] = {-5, 0, 5, 10};
    Node *test4 = problem12_1(arr4, 4);
    cout << "Test 4 (Array: [-5,0,5,10], convert to list): ";
    int expected4[] = {-5, 0, 5, 10};
    Node *exp4 = createList(expected4, 4);
    cout << (compareLists(test4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test4);
    deleteAllNodes(exp4);

    // Test 5: Convert larger array
    // Step: array=[10,20,30,40,50,60], size=6
    // Expected: 10->20->30->40->50->60->NULL
    int arr5[] = {10, 20, 30, 40, 50, 60};
    Node *test5 = problem12_1(arr5, 6);
    cout << "Test 5 (Array: [10,20,30,40,50,60], convert to list): ";
    int expected5[] = {10, 20, 30, 40, 50, 60};
    Node *exp5 = createList(expected5, 6);
    cout << (compareLists(test5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(test5);
    deleteAllNodes(exp5);
}

void testProblem12_2()
{
    cout << "\n=== Testing Problem 12.2: Convert Linked List to Array ===" << endl;

    // Test 1: Convert regular list
    // Step: head=1->2->3
    // Expected: array=[1,2,3], size=3
    int arr1[] = {1, 2, 3};
    Node *test1 = createList(arr1, 3);
    int size1 = 0;
    int *result1 = problem12_2(test1, &size1);
    cout << "Test 1 (List: 1->2->3, convert to array): ";
    bool pass1 = (size1 == 3 && result1[0] == 1 && result1[1] == 2 && result1[2] == 3);
    cout << (pass1 ? "PASS" : "FAIL") << endl;
    delete[] result1;
    deleteAllNodes(test1);

    // Test 2: Convert single node
    // Step: head=99
    // Expected: array=[99], size=1
    int arr2[] = {99};
    Node *test2 = createList(arr2, 1);
    int size2 = 0;
    int *result2 = problem12_2(test2, &size2);
    cout << "Test 2 (List: 99, convert to array): ";
    bool pass2 = (size2 == 1 && result2[0] == 99);
    cout << (pass2 ? "PASS" : "FAIL") << endl;
    delete[] result2;
    deleteAllNodes(test2);

    // Test 3: Convert empty list
    // Step: head=nullptr
    // Expected: array=nullptr, size=0
    Node *test3 = nullptr;
    int size3 = 0;
    int *result3 = problem12_2(test3, &size3);
    cout << "Test 3 (Empty list, convert to array): ";
    cout << (size3 == 0 && result3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Convert list with negative numbers
    // Step: head=-10->0->10
    // Expected: array=[-10,0,10], size=3
    int arr4[] = {-10, 0, 10};
    Node *test4 = createList(arr4, 3);
    int size4 = 0;
    int *result4 = problem12_2(test4, &size4);
    cout << "Test 4 (List: -10->0->10, convert to array): ";
    bool pass4 = (size4 == 3 && result4[0] == -10 && result4[1] == 0 && result4[2] == 10);
    cout << (pass4 ? "PASS" : "FAIL") << endl;
    delete[] result4;
    deleteAllNodes(test4);

    // Test 5: Convert larger list
    // Step: head=5->10->15->20->25
    // Expected: array=[5,10,15,20,25], size=5
    int arr5[] = {5, 10, 15, 20, 25};
    Node *test5 = createList(arr5, 5);
    int size5 = 0;
    int *result5 = problem12_2(test5, &size5);
    cout << "Test 5 (List: 5->10->15->20->25, convert to array): ";
    bool pass5 = (size5 == 5 && result5[0] == 5 && result5[1] == 10 && result5[2] == 15 && result5[3] == 20 && result5[4] == 25);
    cout << (pass5 ? "PASS" : "FAIL") << endl;
    delete[] result5;
    deleteAllNodes(test5);
}
void testProblem12_3()
{
    cout << "\n=== Testing Problem 12.3: Merge Two Sorted Lists ===" << endl;

    // Test 1: Merge two regular sorted lists
    // Step: list1=1->3->5, list2=2->4->6
    // Expected: 1->2->3->4->5->6->NULL
    int arr1a[] = {1, 3, 5};
    int arr1b[] = {2, 4, 6};
    Node *test1a = createList(arr1a, 3);
    Node *test1b = createList(arr1b, 3);
    Node *result1 = problem12_3(test1a, test1b);
    cout << "Test 1 (List1: 1->3->5, List2: 2->4->6, merge): ";
    int expected1[] = {1, 2, 3, 4, 5, 6};
    Node *exp1 = createList(expected1, 6);
    cout << (compareLists(result1, exp1) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(result1);
    deleteAllNodes(exp1);

    // Test 2: Merge with one empty list
    // Step: list1=1->2->3, list2=nullptr
    // Expected: 1->2->3->NULL
    int arr2a[] = {1, 2, 3};
    Node *test2a = createList(arr2a, 3);
    Node *test2b = nullptr;
    Node *result2 = problem12_3(test2a, test2b);
    cout << "Test 2 (List1: 1->2->3, List2: empty, merge): ";
    int expected2[] = {1, 2, 3};
    Node *exp2 = createList(expected2, 3);
    cout << (compareLists(result2, exp2) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(result2);
    deleteAllNodes(exp2);

    // Test 3: Merge with both empty lists
    // Step: list1=nullptr, list2=nullptr
    // Expected: nullptr
    Node *test3a = nullptr;
    Node *test3b = nullptr;
    Node *result3 = problem12_3(test3a, test3b);
    cout << "Test 3 (List1: empty, List2: empty, merge): ";
    cout << (result3 == nullptr ? "PASS" : "FAIL") << endl;

    // Test 4: Merge lists with different lengths
    // Step: list1=1->5->10, list2=2->3->4->6->7->8
    // Expected: 1->2->3->4->5->6->7->8->10->NULL
    int arr4a[] = {1, 5, 10};
    int arr4b[] = {2, 3, 4, 6, 7, 8};
    Node *test4a = createList(arr4a, 3);
    Node *test4b = createList(arr4b, 6);
    Node *result4 = problem12_3(test4a, test4b);
    cout << "Test 4 (List1: 1->5->10, List2: 2->3->4->6->7->8, merge): ";
    int expected4[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    Node *exp4 = createList(expected4, 9);
    cout << (compareLists(result4, exp4) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(result4);
    deleteAllNodes(exp4);

    // Test 5: Merge lists with duplicate values
    // Step: list1=1->3->5, list2=1->3->5
    // Expected: 1->1->3->3->5->5->NULL
    int arr5a[] = {1, 3, 5};
    int arr5b[] = {1, 3, 5};
    Node *test5a = createList(arr5a, 3);
    Node *test5b = createList(arr5b, 3);
    Node *result5 = problem12_3(test5a, test5b);
    cout << "Test 5 (List1: 1->3->5, List2: 1->3->5, merge with duplicates): ";
    int expected5[] = {1, 1, 3, 3, 5, 5};
    Node *exp5 = createList(expected5, 6);
    cout << (compareLists(result5, exp5) ? "PASS" : "FAIL") << endl;
    deleteAllNodes(result5);
    deleteAllNodes(exp5);
}

// Main menu function
int main()
{
    int choice;
    cout << "=== Linked List Practice Problems ===" << endl;
    cout << "\nCONCEPT 1: Insert at Beginning" << endl;
    cout << "1. Problem 1.1 (Easy): Add Single Node at Beginning" << endl;
    cout << "2. Problem 1.2 (Easy): Add Multiple Nodes at Beginning" << endl;
    cout << "3. Problem 1.3 (Medium): Insert with Duplicate Check" << endl;

    cout << "\nCONCEPT 2: Insert at End" << endl;
    cout << "4. Problem 2.1 (Easy): Add Single Node at End" << endl;
    cout << "5. Problem 2.2 (Easy): Add Multiple Nodes at End" << endl;
    cout << "6. Problem 2.3 (Medium): Insert with Sum Validation" << endl;

    cout << "\nCONCEPT 3: Insert at Position" << endl;
    cout << "7. Problem 3.1 (Easy): Insert at Specific Position" << endl;
    cout << "8. Problem 3.2 (Easy): Insert Before First Occurrence" << endl;
    cout << "9. Problem 3.3 (Medium): Insert in Sorted Position" << endl;

    cout << "\nCONCEPT 4: Delete from Beginning" << endl;
    cout << "10. Problem 4.1 (Easy): Delete First Node" << endl;
    cout << "11. Problem 4.2 (Easy): Delete N Nodes from Beginning" << endl;
    cout << "12. Problem 4.3 (Medium): Delete Until Condition" << endl;

    cout << "\nCONCEPT 5: Delete from End" << endl;
    cout << "13. Problem 5.1 (Easy): Delete Last Node" << endl;
    cout << "14. Problem 5.2 (Easy): Delete N Nodes from End" << endl;
    cout << "15. Problem 5.3 (Medium): Delete While Sum Exceeds Target" << endl;

    cout << "\nCONCEPT 6: Delete at Position" << endl;
    cout << "16. Problem 6.1 (Easy): Delete Node at Position" << endl;
    cout << "17. Problem 6.2 (Easy): Delete All Even Positioned Nodes" << endl;
    cout << "18. Problem 6.3 (Medium): Delete Range of Positions" << endl;

    cout << "\nCONCEPT 7: Search for Value" << endl;
    cout << "19. Problem 7.1 (Easy): Find First Occurrence Position" << endl;
    cout << "20. Problem 7.2 (Easy): Count Occurrences" << endl;
    cout << "21. Problem 7.3 (Medium): Find Kth Occurrence Position" << endl;

    cout << "\nCONCEPT 8: Get List Length" << endl;
    cout << "22. Problem 8.1 (Easy): Count Total Nodes" << endl;
    cout << "23. Problem 8.2 (Easy): Count Nodes with Value Greater Than X" << endl;
    cout << "24. Problem 8.3 (Medium): Count Nodes in Range" << endl;

    cout << "\nCONCEPT 9: Reverse List" << endl;
    cout << "25. Problem 9.1 (Easy): Reverse Entire List" << endl;
    cout << "26. Problem 9.2 (Easy): Check if List is Palindrome" << endl;
    cout << "27. Problem 9.3 (Medium): Reverse List in Groups of K" << endl;

    cout << "\nCONCEPT 10: Display Current List" << endl;
    cout << "28. Problem 10.1 (Easy): Display List in Order" << endl;
    cout << "29. Problem 10.2 (Easy): Display List in Reverse Order" << endl;
    cout << "30. Problem 10.3 (Medium): Display Nodes at Even Positions" << endl;

    cout << "\nCONCEPT 11: Clear All Nodes" << endl;
    cout << "31. Problem 11.1 (Easy): Delete All Nodes" << endl;
    cout << "32. Problem 11.2 (Easy): Delete All Nodes with Specific Value" << endl;
    cout << "33. Problem 11.3 (Medium): Clear List and Return Statistics" << endl;

    cout << "\nCONCEPT 12: Linked List vs Array Operations" << endl;
    cout << "34. Problem 12.1 (Easy): Convert Array to Linked List" << endl;
    cout << "35. Problem 12.2 (Easy): Convert Linked List to Array" << endl;
    cout << "36. Problem 12.3 (Medium): Merge Two Sorted Lists" << endl;

    cout << "\n37. Test ALL Problems" << endl;
    cout << "\nEnter problem number (1-37): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        testProblem1_1();
        break;
    case 2:
        testProblem1_2();
        break;
    case 3:
        testProblem1_3();
        break;
    case 4:
        testProblem2_1();
        break;
    case 5:
        testProblem2_2();
        break;
    case 6:
        testProblem2_3();
        break;
    case 7:
        testProblem3_1();
        break;
    case 8:
        testProblem3_2();
        break;
    case 9:
        testProblem3_3();
        break;
    case 10:
        testProblem4_1();
        break;
    case 11:
        testProblem4_2();
        break;
    case 12:
        testProblem4_3();
        break;
    case 13:
        testProblem5_1();
        break;
    case 14:
        testProblem5_2();
        break;
    case 15:
        testProblem5_3();
        break;
    case 16:
        testProblem6_1();
        break;
    case 17:
        testProblem6_2();
        break;
    case 18:
        testProblem6_3();
        break;
    case 19:
        testProblem7_1();
        break;
    case 20:
        testProblem7_2();
        break;
    case 21:
        testProblem7_3();
        break;
    case 22:
        testProblem8_1();
        break;
    case 23:
        testProblem8_2();
        break;
    case 24:
        testProblem8_3();
        break;
    case 25:
        testProblem9_1();
        break;
    case 26:
        testProblem9_2();
        break;
    case 27:
        testProblem9_3();
        break;
    case 28:
        testProblem10_1();
        break;
    case 29:
        testProblem10_2();
        break;
    case 30:
        testProblem10_3();
        break;
    case 31:
        testProblem11_1();
        break;
    case 32:
        testProblem11_2();
        break;
    case 33:
        testProblem11_3();
        break;
    case 34:
        testProblem12_1();
        break;
    case 35:
        testProblem12_2();
        break;
    case 36:
        testProblem12_3();
        break;
    case 37:
        testProblem1_1();
        testProblem1_2();
        testProblem1_3();
        testProblem2_1();
        testProblem2_2();
        testProblem2_3();
        testProblem3_1();
        testProblem3_2();
        testProblem3_3();
        testProblem4_1();
        testProblem4_2();
        testProblem4_3();
        testProblem5_1();
        testProblem5_2();
        testProblem5_3();
        testProblem6_1();
        testProblem6_2();
        testProblem6_3();
        testProblem7_1();
        testProblem7_2();
        testProblem7_3();
        testProblem8_1();
        testProblem8_2();
        testProblem8_3();
        testProblem9_1();
        testProblem9_2();
        testProblem9_3();
        testProblem10_1();
        testProblem10_2();
        testProblem10_3();
        testProblem11_1();
        testProblem11_2();
        testProblem11_3();
        testProblem12_1();
        testProblem12_2();
        testProblem12_3();
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}