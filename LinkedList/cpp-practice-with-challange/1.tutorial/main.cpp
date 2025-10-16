#include <iostream>
#include <iomanip>
using namespace std;

/*
===============================================================================
                        LINKED LIST EDUCATIONAL PROGRAM
===============================================================================

This program will teach you everything about Linked Lists in C++:
1. What is a Linked List and how it differs from arrays
2. Node structure and memory layout
3. Basic operations with detailed explanations
4. Visual representations of each operation
5. Memory management and best practices

Let's start with the fundamentals!
*/

// =============================================================================
// PART 1: UNDERSTANDING THE NODE STRUCTURE
// =============================================================================

struct ListNode {
    int data;           // The actual value stored in this node
    ListNode* next;     // Pointer to the next node in the list
    
    // Constructor to easily create a new node
    ListNode(int value) {
        data = value;
        next = nullptr;  // Initially, this node doesn't point to anything
    }
    
    // Alternative constructor
    ListNode(int value, ListNode* nextNode) {
        data = value;
        next = nextNode;
    }
};

// =============================================================================
// PART 2: VISUALIZATION HELPER FUNCTIONS
// =============================================================================

void printSeparator(const string& title) {
    cout << "\n" << string(60, '=') << endl;
    cout << "  " << title << endl;
    cout << string(60, '=') << endl;
}

void printList(ListNode* head, const string& listName = "List") {
    cout << "\n" << listName << ": ";
    if (!head) {
        cout << "Empty (NULL)" << endl;
        return;
    }
    
    ListNode* current = head;
    while (current) {
        cout << "[" << current->data << "]";
        if (current->next) {
            cout << " -> ";
        } else {
            cout << " -> NULL";
        }
        current = current->next;
    }
    cout << endl;
}

void printMemoryVisualization(ListNode* head, const string& operation = "") {
    cout << "\nMemory Layout" << (!operation.empty() ? " (" + operation + ")" : "") << ":" << endl;
    cout << string(50, '-') << endl;
    
    if (!head) {
        cout << "head -> NULL" << endl;
        return;
    }
    
    ListNode* current = head;
    int nodeCount = 1;
    
    cout << "head -> ";
    while (current) {
        cout << "[Node" << nodeCount << ": data=" << current->data 
             << ", next=" << (current->next ? "Node" + to_string(nodeCount + 1) : "NULL") << "]";
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
        nodeCount++;
    }
    cout << endl;
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// =============================================================================
// PART 3: CORE LINKED LIST OPERATIONS WITH DETAILED EXPLANATIONS
// =============================================================================

class LinkedListTutorial {
private:
    ListNode* head;
    
public:
    LinkedListTutorial() : head(nullptr) {}
    
    // Destructor to prevent memory leaks
    ~LinkedListTutorial() {
        clear();
    }
    
    // =================================================================
    // INSERTION OPERATIONS
    // =================================================================
    
    void insertAtBeginning(int value) {
        cout << "\n🔹 INSERTING " << value << " AT THE BEGINNING:" << endl;
        cout << "Step 1: Create a new node with value " << value << endl;
        
        ListNode* newNode = new ListNode(value);
        cout << "   newNode created at memory location (conceptual)" << endl;
        cout << "   newNode->data = " << value << endl;
        cout << "   newNode->next = nullptr" << endl;
        
        cout << "\nStep 2: Point new node to current head" << endl;
        newNode->next = head;
        cout << "   newNode->next now points to " << (head ? "first node" : "NULL") << endl;
        
        cout << "\nStep 3: Update head to point to new node" << endl;
        head = newNode;
        cout << "   head now points to the new node" << endl;
        
        printList(head, "Result");
        printMemoryVisualization(head, "After insertion at beginning");
    }
    
    void insertAtEnd(int value) {
        cout << "\n🔹 INSERTING " << value << " AT THE END:" << endl;
        
        ListNode* newNode = new ListNode(value);
        cout << "Step 1: Create new node with value " << value << endl;
        
        if (!head) {
            cout << "Step 2: List is empty, make new node the head" << endl;
            head = newNode;
            printList(head, "Result");
            return;
        }
        
        cout << "Step 2: Traverse to find the last node" << endl;
        ListNode* current = head;
        int position = 1;
        while (current->next) {
            cout << "   At position " << position << ": node->data = " << current->data 
                 << ", has next node" << endl;
            current = current->next;
            position++;
        }
        cout << "   At position " << position << ": node->data = " << current->data 
             << ", this is the last node (next = NULL)" << endl;
        
        cout << "\nStep 3: Link last node to new node" << endl;
        current->next = newNode;
        cout << "   last node->next now points to new node" << endl;
        
        printList(head, "Result");
        printMemoryVisualization(head, "After insertion at end");
    }
    
    void insertAtPosition(int value, int position) {
        cout << "\n🔹 INSERTING " << value << " AT POSITION " << position << ":" << endl;
        
        if (position < 1) {
            cout << "❌ Invalid position! Position must be >= 1" << endl;
            return;
        }
        
        if (position == 1) {
            cout << "Position 1 means insert at beginning" << endl;
            insertAtBeginning(value);
            return;
        }
        
        ListNode* newNode = new ListNode(value);
        cout << "Step 1: Create new node with value " << value << endl;
        
        cout << "Step 2: Traverse to position " << (position - 1) << endl;
        ListNode* current = head;
        for (int i = 1; i < position - 1 && current; i++) {
            cout << "   At position " << i << ": node->data = " << current->data << endl;
            current = current->next;
        }
        
        if (!current) {
            cout << "❌ Position " << position << " is beyond list length!" << endl;
            delete newNode;
            return;
        }
        
        cout << "Step 3: Insert new node between position " << (position-1) 
             << " and " << position << endl;
        newNode->next = current->next;
        current->next = newNode;
        cout << "   New node linked successfully!" << endl;
        
        printList(head, "Result");
        printMemoryVisualization(head, "After insertion at position " + to_string(position));
    }
    
    // =================================================================
    // DELETION OPERATIONS
    // =================================================================
    
    void deleteFromBeginning() {
        cout << "\n🔹 DELETING FROM THE BEGINNING:" << endl;
        
        if (!head) {
            cout << "❌ Cannot delete from empty list!" << endl;
            return;
        }
        
        cout << "Step 1: Store the current head node" << endl;
        ListNode* nodeToDelete = head;
        cout << "   nodeToDelete points to first node (data = " << nodeToDelete->data << ")" << endl;
        
        cout << "Step 2: Update head to point to second node" << endl;
        head = head->next;
        cout << "   head now points to " << (head ? "second node" : "NULL") << endl;
        
        cout << "Step 3: Delete the old first node to free memory" << endl;
        delete nodeToDelete;
        cout << "   Memory freed successfully!" << endl;
        
        printList(head, "Result");
        printMemoryVisualization(head, "After deletion from beginning");
    }
    
    void deleteFromEnd() {
        cout << "\n🔹 DELETING FROM THE END:" << endl;
        
        if (!head) {
            cout << "❌ Cannot delete from empty list!" << endl;
            return;
        }
        
        if (!head->next) {
            cout << "Only one node in list, deleting it" << endl;
            delete head;
            head = nullptr;
            printList(head, "Result");
            return;
        }
        
        cout << "Step 1: Find the second-to-last node" << endl;
        ListNode* current = head;
        while (current->next->next) {
            cout << "   Current node data: " << current->data << endl;
            current = current->next;
        }
        cout << "   Found second-to-last node (data = " << current->data << ")" << endl;
        
        cout << "Step 2: Delete the last node" << endl;
        ListNode* nodeToDelete = current->next;
        cout << "   Last node data: " << nodeToDelete->data << endl;
        delete nodeToDelete;
        
        cout << "Step 3: Update second-to-last node's next pointer" << endl;
        current->next = nullptr;
        cout << "   Second-to-last node now points to NULL" << endl;
        
        printList(head, "Result");
        printMemoryVisualization(head, "After deletion from end");
    }
    
    void deleteAtPosition(int position) {
        cout << "\n🔹 DELETING AT POSITION " << position << ":" << endl;
        
        if (position < 1) {
            cout << "❌ Invalid position! Position must be >= 1" << endl;
            return;
        }
        
        if (!head) {
            cout << "❌ Cannot delete from empty list!" << endl;
            return;
        }
        
        if (position == 1) {
            cout << "Position 1 means delete from beginning" << endl;
            deleteFromBeginning();
            return;
        }
        
        cout << "Step 1: Find the node before position " << position << endl;
        ListNode* current = head;
        for (int i = 1; i < position - 1 && current; i++) {
            cout << "   At position " << i << ": node->data = " << current->data << endl;
            current = current->next;
        }
        
        if (!current || !current->next) {
            cout << "❌ Position " << position << " doesn't exist!" << endl;
            return;
        }
        
        cout << "Step 2: Store and delete the target node" << endl;
        ListNode* nodeToDelete = current->next;
        cout << "   Target node data: " << nodeToDelete->data << endl;
        
        cout << "Step 3: Update links to skip the deleted node" << endl;
        current->next = nodeToDelete->next;
        
        delete nodeToDelete;
        cout << "   Node deleted and memory freed!" << endl;
        
        printList(head, "Result");
        printMemoryVisualization(head, "After deletion at position " + to_string(position));
    }
    
    // =================================================================
    // SEARCH AND UTILITY OPERATIONS
    // =================================================================
    
    bool search(int value) {
        cout << "\n🔍 SEARCHING FOR VALUE " << value << ":" << endl;
        
        ListNode* current = head;
        int position = 1;
        
        cout << "Traversing the list:" << endl;
        while (current) {
            cout << "   Position " << position << ": checking data " << current->data;
            if (current->data == value) {
                cout << " ✓ FOUND!" << endl;
                return true;
            }
            cout << " (not a match)" << endl;
            current = current->next;
            position++;
        }
        
        cout << "❌ Value " << value << " not found in the list" << endl;
        return false;
    }
    
    int getLength() {
        cout << "\n📏 CALCULATING LIST LENGTH:" << endl;
        
        int length = 0;
        ListNode* current = head;
        
        cout << "Counting nodes:" << endl;
        while (current) {
            length++;
            cout << "   Node " << length << ": data = " << current->data << endl;
            current = current->next;
        }
        
        cout << "Total length: " << length << " nodes" << endl;
        return length;
    }
    
    void reverse() {
        cout << "\n🔄 REVERSING THE LIST:" << endl;
        
        if (!head || !head->next) {
            cout << "List has 0 or 1 node, nothing to reverse" << endl;
            return;
        }
        
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        cout << "Using three pointers approach:" << endl;
        int step = 1;
        
        while (current) {
            cout << "\nStep " << step << ":" << endl;
            cout << "   previous = " << (previous ? to_string(previous->data) : "NULL") << endl;
            cout << "   current = " << current->data << endl;
            cout << "   next = " << (current->next ? to_string(current->next->data) : "NULL") << endl;
            
            // Store next node
            next = current->next;
            cout << "   Store next node" << endl;
            
            // Reverse the link
            current->next = previous;
            cout << "   Reverse current->next to point to previous" << endl;
            
            // Move pointers forward
            previous = current;
            current = next;
            cout << "   Move previous and current forward" << endl;
            
            step++;
        }
        
        head = previous;
        cout << "\nUpdate head to point to new first node" << endl;
        
        printList(head, "Result");
        printMemoryVisualization(head, "After reversal");
    }
    
    void clear() {
        cout << "\n🗑️ CLEARING ALL NODES (MEMORY CLEANUP):" << endl;
        
        while (head) {
            ListNode* temp = head;
            cout << "   Deleting node with data: " << temp->data << endl;
            head = head->next;
            delete temp;
        }
        cout << "All nodes cleared, memory freed!" << endl;
    }
    
    void displayCurrentState() {
        printList(head, "Current List");
        printMemoryVisualization(head);
    }
};

// =============================================================================
// PART 4: COMPARISON WITH ARRAYS
// =============================================================================

void explainLinkedListVsArray() {
    printSeparator("LINKED LIST VS ARRAY COMPARISON");
    
    cout << "\n📊 MEMORY LAYOUT DIFFERENCES:" << endl;
    cout << string(50, '-') << endl;
    
    cout << "\nARRAY (Contiguous Memory):" << endl;
    cout << "Memory: [1][2][3][4][5] <- All elements stored together" << endl;
    cout << "Access: Direct access using index (arr[2] = 3)" << endl;
    cout << "Time:   O(1) for access, O(n) for insertion/deletion" << endl;
    
    cout << "\nLINKED LIST (Scattered Memory):" << endl;
    cout << "Memory: [1|*] -> [2|*] -> [3|*] -> [4|*] -> [5|NULL]" << endl;
    cout << "        ↑        ↑        ↑        ↑        ↑" << endl;
    cout << "      Addr1    Addr2    Addr3    Addr4    Addr5" << endl;
    cout << "Access: Sequential access only (must traverse from head)" << endl;
    cout << "Time:   O(n) for access, O(1) for insertion/deletion at known position" << endl;
    
    cout << "\n⚖️ TRADE-OFFS:" << endl;
    cout << "Arrays are better for:" << endl;
    cout << "  ✓ Random access to elements" << endl;
    cout << "  ✓ Cache performance (memory locality)" << endl;
    cout << "  ✓ Less memory overhead per element" << endl;
    
    cout << "\nLinked Lists are better for:" << endl;
    cout << "  ✓ Dynamic size (grow/shrink during runtime)" << endl;
    cout << "  ✓ Efficient insertion/deletion at any position" << endl;
    cout << "  ✓ Memory allocation flexibility" << endl;
    
    waitForEnter();
}

// =============================================================================
// PART 5: INTERACTIVE TUTORIAL MENU
// =============================================================================

void showMenu() {
    cout << "\n" << string(60, '=') << endl;
    cout << "           LINKED LIST INTERACTIVE TUTORIAL" << endl;
    cout << string(60, '=') << endl;
    cout << "1.  Insert at Beginning" << endl;
    cout << "2.  Insert at End" << endl;
    cout << "3.  Insert at Position" << endl;
    cout << "4.  Delete from Beginning" << endl;
    cout << "5.  Delete from End" << endl;
    cout << "6.  Delete at Position" << endl;
    cout << "7.  Search for Value" << endl;
    cout << "8.  Get List Length" << endl;
    cout << "9.  Reverse List" << endl;
    cout << "10. Display Current List" << endl;
    cout << "11. Clear All Nodes" << endl;
    cout << "12. Explain Linked List vs Array" << endl;
    cout << "0.  Exit" << endl;
    cout << string(60, '=') << endl;
    cout << "Choose an option: ";
}

int main() {
    LinkedListTutorial tutorial;
    int choice, value, position;
    
    cout << "🎓 Welcome to the Complete Linked List Tutorial!" << endl;
    cout << "This program will teach you linked lists step by step." << endl;
    cout << "Each operation includes detailed explanations and visualizations." << endl;
    
    waitForEnter();
    
    while (true) {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                tutorial.insertAtBeginning(value);
                waitForEnter();
                break;
                
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                tutorial.insertAtEnd(value);
                waitForEnter();
                break;
                
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position (1-based): ";
                cin >> position;
                tutorial.insertAtPosition(value, position);
                waitForEnter();
                break;
                
            case 4:
                tutorial.deleteFromBeginning();
                waitForEnter();
                break;
                
            case 5:
                tutorial.deleteFromEnd();
                waitForEnter();
                break;
                
            case 6:
                cout << "Enter position to delete (1-based): ";
                cin >> position;
                tutorial.deleteAtPosition(position);
                waitForEnter();
                break;
                
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                tutorial.search(value);
                waitForEnter();
                break;
                
            case 8:
                tutorial.getLength();
                waitForEnter();
                break;
                
            case 9:
                tutorial.reverse();
                waitForEnter();
                break;
                
            case 10:
                tutorial.displayCurrentState();
                waitForEnter();
                break;
                
            case 11:
                tutorial.clear();
                waitForEnter();
                break;
                
            case 12:
                explainLinkedListVsArray();
                break;
                
            case 0:
                cout << "\n🎓 Tutorial completed! You've learned:" << endl;
                cout << "✓ Node structure and memory layout" << endl;
                cout << "✓ Insertion operations (beginning, end, position)" << endl;
                cout << "✓ Deletion operations (beginning, end, position)" << endl;
                cout << "✓ Search and traversal techniques" << endl;
                cout << "✓ List reversal algorithm" << endl;
                cout << "✓ Memory management best practices" << endl;
                cout << "✓ Linked list vs array comparison" << endl;
                cout << "\nKeep practicing with different problems to master linked lists!" << endl;
                return 0;
                
            default:
                cout << "❌ Invalid choice! Please try again." << endl;
                waitForEnter();
                break;
        }
    }
    
    return 0;
}

/*
===============================================================================
                            ADDITIONAL LEARNING NOTES
===============================================================================

🎯 KEY CONCEPTS YOU'VE LEARNED:

1. NODE STRUCTURE:
   - A node contains data and a pointer to the next node
   - The last node's next pointer is NULL
   - Head pointer keeps track of the first node

2. MEMORY MANAGEMENT:
   - Always use 'new' to create nodes dynamically
   - Always use 'delete' to free memory and prevent leaks
   - Be careful with dangling pointers

3. BASIC OPERATIONS:
   - Insertion: Create node, update pointers
   - Deletion: Update pointers, then delete node
   - Traversal: Follow next pointers until NULL

4. TIME COMPLEXITIES:
   - Access: O(n) - must traverse from head
   - Search: O(n) - must check each node
   - Insertion at beginning: O(1)
   - Insertion at end: O(n) without tail pointer
   - Deletion at beginning: O(1)
   - Deletion at end: O(n) without previous pointer

5. COMMON PATTERNS:
   - Two-pointer technique (slow/fast pointers)
   - Dummy node to simplify edge cases
   - Recursive vs iterative approaches

🔄 VARIATIONS TO EXPLORE LATER:
   - Doubly Linked List (nodes have prev and next pointers)
   - Circular Linked List (last node points to first)
   - Linked List with tail pointer for O(1) end operations

💡 PROBLEM-SOLVING TIPS:
   - Always check for NULL pointers
   - Handle empty list cases
   - Draw diagrams to visualize pointer changes
   - Test with single-node lists
   - Consider edge cases in your solutions

===============================================================================
*/