/*
================================================================================
                    INTERACTIVE LINKED LIST TUTORIAL
                        Complete C++ Educational Program
================================================================================

TUTORIAL OVERVIEW:
This comprehensive tutorial teaches Linked Lists through interactive demonstrations,
detailed explanations, and hands-on practice. The program covers everything from
basic node structure to advanced operations and memory management.

LEARNING OBJECTIVES COVERED:
1. Node Structure and Implementation
2. Creating and Connecting Nodes
3. Traversing Linked Lists
4. Inserting Nodes (beginning, middle, end)
5. Deleting Nodes
6. Memory Management with Linked Lists

PROGRAM STRUCTURE:
- Educational Introduction Section
- Progressive Learning Modules
- Interactive Tutorial Class
- Hands-on Menu System
- Visualization Tools
- Memory Management Demonstrations

PREREQUISITES:
- Basic C++ syntax and data types
- Understanding of pointers and dynamic memory allocation
- Classes and structs knowledge
- Control flow and loops
- Functions and basic OOP concepts

================================================================================
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <memory>

using namespace std;

/*
================================================================================
                           NODE STRUCTURE DEFINITION
================================================================================

The Node is the fundamental building block of a linked list.
Think of it as a container that holds:
1. Data (the actual information we want to store)
2. A pointer to the next node (creating the "link" in linked list)

Analogy: Like train cars connected by couplers - each car holds cargo (data)
and has a coupler (pointer) connecting it to the next car.
*/

struct Node {
    int data;           // The actual data stored in this node
    Node* next;         // Pointer to the next node in the list
    
    // Constructor for easy node creation
    Node(int value) : data(value), next(nullptr) {
        cout << "    [Memory] Node created with value: " << value << endl;
    }
    
    // Destructor to show when node is destroyed
    ~Node() {
        cout << "    [Memory] Node with value " << data << " destroyed" << endl;
    }
};

/*
================================================================================
                        LINKED LIST TUTORIAL CLASS
================================================================================

This class encapsulates all linked list operations and provides educational
demonstrations for each concept. It includes visualization tools and
step-by-step explanations.
*/

class LinkedListTutorial {
private:
    Node* head;         // Pointer to the first node (head of the list)
    int size;           // Keep track of list size for educational purposes
    
public:
    // Constructor
    LinkedListTutorial() : head(nullptr), size(0) {
        cout << "    [Tutorial] Empty Linked List created" << endl;
    }
    
    // Destructor - demonstrates proper cleanup
    ~LinkedListTutorial() {
        cout << "\n    [Memory Management] Cleaning up linked list..." << endl;
        clear();
        cout << "    [Memory Management] All nodes properly destroyed" << endl;
    }
    
    /*
    ============================================================================
                            EDUCATIONAL HELPER FUNCTIONS
    ============================================================================
    */
    
    void printSeparator(const string& title = "") {
        cout << "\n" << string(80, '=') << endl;
        if (!title.empty()) {
            cout << "  " << title << endl;
            cout << string(80, '=') << endl;
        }
    }
    
    void waitForEnter() {
        cout << "\n    Press ENTER to continue...";
        cin.ignore();
        cin.get();
    }
    
    void visualizeList(const string& operation = "") {
        cout << "\n    [VISUALIZATION] Current List State";
        if (!operation.empty()) {
            cout << " - After " << operation;
        }
        cout << ":" << endl;
        
        if (head == nullptr) {
            cout << "    Empty List: [NULL]" << endl;
            cout << "    Size: 0" << endl;
            return;
        }
        
        cout << "    List: ";
        Node* current = head;
        int position = 0;
        
        while (current != nullptr) {
            cout << "[" << current->data << "]";
            if (current->next != nullptr) {
                cout << " -> ";
            } else {
                cout << " -> [NULL]";
            }
            current = current->next;
            position++;
        }
        
        cout << "\n    Size: " << size << " nodes" << endl;
        cout << "    Head points to: " << (head ? to_string(head->data) : "NULL") << endl;
    }
    
    void visualizeMemory() {
        cout << "\n    [MEMORY LAYOUT] Node Memory Addresses:" << endl;
        if (head == nullptr) {
            cout << "    No nodes in memory" << endl;
            return;
        }
        
        Node* current = head;
        int position = 0;
        
        while (current != nullptr) {
            cout << "    Position " << position << ": ";
            cout << "Data=" << current->data << ", ";
            cout << "Address=" << current << ", ";
            cout << "Next=" << current->next << endl;
            current = current->next;
            position++;
        }
    }
    
    /*
    ============================================================================
                        CORE LINKED LIST OPERATIONS
    ============================================================================
    */
    
    // Insert at the beginning (most efficient - O(1))
    void insertAtBeginning(int value) {
        printSeparator("INSERT AT BEGINNING OPERATION");
        
        cout << "    CONCEPT: Inserting at the beginning is the fastest insertion" << endl;
        cout << "    Time Complexity: O(1) - Constant time" << endl;
        cout << "    Why? We only need to update pointers, not traverse the list" << endl;
        
        cout << "\n    STEP-BY-STEP PROCESS:" << endl;
        cout << "    1. Create a new node with value: " << value << endl;
        
        // Step 1: Create new node
        Node* newNode = new Node(value);
        
        cout << "    2. Point new node's 'next' to current head" << endl;
        newNode->next = head;
        
        cout << "    3. Update head to point to new node" << endl;
        head = newNode;
        size++;
        
        visualizeList("Insert at Beginning");
        
        cout << "\n    MEMORY EXPLANATION:" << endl;
        cout << "    - New node is allocated in heap memory" << endl;
        cout << "    - Head pointer is updated to new node's address" << endl;
        cout << "    - Old head becomes the second node" << endl;
    }
    
    // Insert at the end (requires traversal - O(n))
    void insertAtEnd(int value) {
        printSeparator("INSERT AT END OPERATION");
        
        cout << "    CONCEPT: Inserting at the end requires traversing the entire list" << endl;
        cout << "    Time Complexity: O(n) - Linear time" << endl;
        cout << "    Why? We must traverse to find the last node" << endl;
        
        if (head == nullptr) {
            cout << "\n    SPECIAL CASE: Empty list - insert becomes first node" << endl;
            insertAtBeginning(value);
            return;
        }
        
        cout << "\n    STEP-BY-STEP PROCESS:" << endl;
        cout << "    1. Create a new node with value: " << value << endl;
        Node* newNode = new Node(value);
        
        cout << "    2. Traverse to find the last node" << endl;
        Node* current = head;
        int steps = 0;
        
        while (current->next != nullptr) {
            cout << "       Visiting node with value: " << current->data << endl;
            current = current->next;
            steps++;
        }
        
        cout << "    3. Found last node with value: " << current->data << endl;
        cout << "       (Required " << steps + 1 << " steps to reach end)" << endl;
        
        cout << "    4. Point last node's 'next' to new node" << endl;
        current->next = newNode;
        size++;
        
        visualizeList("Insert at End");
    }
    
    // Insert at specific position
    void insertAtPosition(int value, int position) {
        printSeparator("INSERT AT POSITION OPERATION");
        
        cout << "    CONCEPT: Inserting at a specific position" << endl;
        cout << "    Position: " << position << ", Value: " << value << endl;
        
        if (position < 0 || position > size) {
            cout << "    ERROR: Invalid position! Valid range: 0 to " << size << endl;
            return;
        }
        
        if (position == 0) {
            cout << "    OPTIMIZATION: Position 0 - using insertAtBeginning()" << endl;
            insertAtBeginning(value);
            return;
        }
        
        cout << "\n    STEP-BY-STEP PROCESS:" << endl;
        cout << "    1. Create a new node with value: " << value << endl;
        Node* newNode = new Node(value);
        
        cout << "    2. Traverse to position " << (position - 1) << endl;
        Node* current = head;
        
        for (int i = 0; i < position - 1; i++) {
            cout << "       Step " << (i + 1) << ": At node with value " << current->data << endl;
            current = current->next;
        }
        
        cout << "    3. Found node before insertion point: " << current->data << endl;
        cout << "    4. Update pointers to insert new node" << endl;
        
        newNode->next = current->next;
        current->next = newNode;
        size++;
        
        visualizeList("Insert at Position " + to_string(position));
    }
    
    // Delete from beginning
    void deleteFromBeginning() {
        printSeparator("DELETE FROM BEGINNING OPERATION");
        
        if (head == nullptr) {
            cout << "    ERROR: Cannot delete from empty list!" << endl;
            return;
        }
        
        cout << "    CONCEPT: Deleting from beginning is most efficient" << endl;
        cout << "    Time Complexity: O(1) - Constant time" << endl;
        
        cout << "\n    STEP-BY-STEP PROCESS:" << endl;
        cout << "    1. Store reference to current head: " << head->data << endl;
        
        Node* nodeToDelete = head;
        
        cout << "    2. Update head to point to second node" << endl;
        head = head->next;
        
        cout << "    3. Delete the old head node" << endl;
        delete nodeToDelete;  // This will trigger the destructor
        size--;
        
        visualizeList("Delete from Beginning");
    }
    
    // Delete from end
    void deleteFromEnd() {
        printSeparator("DELETE FROM END OPERATION");
        
        if (head == nullptr) {
            cout << "    ERROR: Cannot delete from empty list!" << endl;
            return;
        }
        
        if (head->next == nullptr) {
            cout << "    SPECIAL CASE: Only one node in list" << endl;
            deleteFromBeginning();
            return;
        }
        
        cout << "    CONCEPT: Deleting from end requires finding second-to-last node" << endl;
        cout << "    Time Complexity: O(n) - Linear time" << endl;
        
        cout << "\n    STEP-BY-STEP PROCESS:" << endl;
        cout << "    1. Traverse to find second-to-last node" << endl;
        
        Node* current = head;
        int steps = 0;
        
        while (current->next->next != nullptr) {
            cout << "       Step " << (steps + 1) << ": At node " << current->data << endl;
            current = current->next;
            steps++;
        }
        
        cout << "    2. Found second-to-last node: " << current->data << endl;
        cout << "    3. Last node to delete: " << current->next->data << endl;
        
        Node* nodeToDelete = current->next;
        current->next = nullptr;
        
        cout << "    4. Delete the last node" << endl;
        delete nodeToDelete;
        size--;
        
        visualizeList("Delete from End");
    }
    
    // Delete from specific position
    void deleteFromPosition(int position) {
        printSeparator("DELETE FROM POSITION OPERATION");
        
        if (head == nullptr) {
            cout << "    ERROR: Cannot delete from empty list!" << endl;
            return;
        }
        
        if (position < 0 || position >= size) {
            cout << "    ERROR: Invalid position! Valid range: 0 to " << (size - 1) << endl;
            return;
        }
        
        if (position == 0) {
            cout << "    OPTIMIZATION: Position 0 - using deleteFromBeginning()" << endl;
            deleteFromBeginning();
            return;
        }
        
        cout << "    CONCEPT: Deleting from position " << position << endl;
        
        cout << "\n    STEP-BY-STEP PROCESS:" << endl;
        cout << "    1. Traverse to position " << (position - 1) << endl;
        
        Node* current = head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        
        cout << "    2. Found node before deletion point: " << current->data << endl;
        cout << "    3. Node to delete: " << current->next->data << endl;
        
        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        
        cout << "    4. Delete the node" << endl;
        delete nodeToDelete;
        size--;
        
        visualizeList("Delete from Position " + to_string(position));
    }
    
    // Search for a value
    bool search(int value) {
        printSeparator("SEARCH OPERATION");
        
        cout << "    CONCEPT: Linear search through linked list" << endl;
        cout << "    Time Complexity: O(n) - Linear time" << endl;
        cout << "    Searching for value: " << value << endl;
        
        if (head == nullptr) {
            cout << "    Result: Value not found (empty list)" << endl;
            return false;
        }
        
        cout << "\n    SEARCH PROCESS:" << endl;
        Node* current = head;
        int position = 0;
        
        while (current != nullptr) {
            cout << "    Position " << position << ": Checking value " << current->data;
            
            if (current->data == value) {
                cout << " -> FOUND!" << endl;
                cout << "\n    SUCCESS: Value " << value << " found at position " << position << endl;
                return true;
            }
            
            cout << " -> Continue searching..." << endl;
            current = current->next;
            position++;
        }
        
        cout << "\n    Result: Value " << value << " not found in the list" << endl;
        return false;
    }
    
    // Traverse and display
    void traverse() {
        printSeparator("TRAVERSE OPERATION");
        
        cout << "    CONCEPT: Visiting each node in sequence" << endl;
        cout << "    Time Complexity: O(n) - Linear time" << endl;
        
        if (head == nullptr) {
            cout << "    Result: Empty list - nothing to traverse" << endl;
            return;
        }
        
        cout << "\n    TRAVERSAL PROCESS:" << endl;
        Node* current = head;
        int position = 0;
        
        while (current != nullptr) {
            cout << "    Position " << position << ": Value = " << current->data;
            cout << ", Address = " << current;
            cout << ", Next = " << current->next << endl;
            
            current = current->next;
            position++;
        }
        
        cout << "\n    Traversal complete! Visited " << position << " nodes." << endl;
    }
    
    // Clear the entire list
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }
    
    // Get current size
    int getSize() const {
        return size;
    }
    
    // Check if list is empty
    bool isEmpty() const {
        return head == nullptr;
    }
    
    /*
    ============================================================================
                        EDUCATIONAL DEMONSTRATIONS
    ============================================================================
    */
    
    void demonstrateNodeConcept() {
        printSeparator("NODE CONCEPT DEMONSTRATION");
        
        cout << "    UNDERSTANDING NODES:" << endl;
        cout << "    A node is like a container with two parts:" << endl;
        cout << "    1. Data: The actual information we want to store" << endl;
        cout << "    2. Next: A pointer/address to the next container" << endl;
        
        cout << "\n    ANALOGY: Think of nodes like train cars:" << endl;
        cout << "    - Each car (node) carries cargo (data)" << endl;
        cout << "    - Each car has a coupler (next pointer) to connect to the next car" << endl;
        cout << "    - The engine (head pointer) knows where the first car is" << endl;
        
        cout << "\n    Let's create some individual nodes to see this in action:" << endl;
        
        cout << "\n    Creating Node 1 with value 10:" << endl;
        Node* node1 = new Node(10);
        cout << "    Node 1 - Data: " << node1->data << ", Next: " << node1->next << endl;
        
        cout << "\n    Creating Node 2 with value 20:" << endl;
        Node* node2 = new Node(20);
        cout << "    Node 2 - Data: " << node2->data << ", Next: " << node2->next << endl;
        
        cout << "\n    Connecting Node 1 to Node 2:" << endl;
        node1->next = node2;
        cout << "    Node 1 - Data: " << node1->data << ", Next: " << node1->next << endl;
        cout << "    Node 2 - Data: " << node2->data << ", Next: " << node2->next << endl;
        
        cout << "\n    Now we have a simple linked structure!" << endl;
        cout << "    Node1[10] -> Node2[20] -> NULL" << endl;
        
        waitForEnter();
        
        // Clean up
        delete node1;
        delete node2;
    }
    
    void demonstrateMemoryManagement() {
        printSeparator("MEMORY MANAGEMENT DEMONSTRATION");
        
        cout << "    IMPORTANT: Linked lists use dynamic memory allocation" << endl;
        cout << "    This means we must carefully manage memory to avoid:" << endl;
        cout << "    1. Memory leaks (forgetting to delete nodes)" << endl;
        cout << "    2. Dangling pointers (using deleted memory)" << endl;
        cout << "    3. Double deletion (deleting the same memory twice)" << endl;
        
        cout << "\n    GOOD PRACTICES:" << endl;
        cout << "    1. Every 'new' should have a corresponding 'delete'" << endl;
        cout << "    2. Set pointers to nullptr after deletion" << endl;
        cout << "    3. Use destructors to ensure cleanup" << endl;
        cout << "    4. Be careful when sharing pointers between objects" << endl;
        
        cout << "\n    Let's demonstrate proper memory management:" << endl;
        
        // Add some nodes
        insertAtBeginning(100);
        insertAtBeginning(200);
        insertAtBeginning(300);
        
        visualizeMemory();
        
        cout << "\n    Now let's properly clean up all memory..." << endl;
        clear();
        
        cout << "    All nodes have been properly deleted!" << endl;
    }
    
    void demonstrateComplexityAnalysis() {
        printSeparator("TIME COMPLEXITY ANALYSIS");
        
        cout << "    LINKED LIST OPERATION COMPLEXITIES:" << endl;
        cout << "    +" << string(50, '-') << "+" << string(15, '-') << "+" << endl;
        cout << "    | Operation                                | Time Complexity |" << endl;
        cout << "    +" << string(50, '-') << "+" << string(15, '-') << "+" << endl;
        cout << "    | Insert at beginning                      | O(1)            |" << endl;
        cout << "    | Insert at end                            | O(n)            |" << endl;
        cout << "    | Insert at position                       | O(n)            |" << endl;
        cout << "    | Delete from beginning                    | O(1)            |" << endl;
        cout << "    | Delete from end                          | O(n)            |" << endl;
        cout << "    | Delete from position                     | O(n)            |" << endl;
        cout << "    | Search                                   | O(n)            |" << endl;
        cout << "    | Traverse                                 | O(n)            |" << endl;
        cout << "    +" << string(50, '-') << "+" << string(15, '-') << "+" << endl;
        
        cout << "\n    COMPARISON WITH ARRAYS:" << endl;
        cout << "    +" << string(30, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+" << endl;
        cout << "    | Operation                  | Array       | Linked List |" << endl;
        cout << "    +" << string(30, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+" << endl;
        cout << "    | Access by index            | O(1)        | O(n)        |" << endl;
        cout << "    | Insert at beginning        | O(n)        | O(1)        |" << endl;
        cout << "    | Insert at end              | O(1)        | O(n)        |" << endl;
        cout << "    | Delete from beginning      | O(n)        | O(1)        |" << endl;
        cout << "    | Memory usage               | Compact     | Extra space |" << endl;
        cout << "    | Cache performance          | Better      | Worse       |" << endl;
        cout << "    +" << string(30, '-') << "+" << string(15, '-') << "+" << string(15, '-') << "+" << endl;
        
        cout << "\n    KEY INSIGHTS:" << endl;
        cout << "    - Linked lists excel at insertion/deletion at the beginning" << endl;
        cout << "    - Arrays excel at random access by index" << endl;
        cout << "    - Choose the right data structure based on your use case!" << endl;
    }
    
    void demonstrateRealWorldApplications() {
        printSeparator("REAL-WORLD APPLICATIONS");
        
        cout << "    WHERE ARE LINKED LISTS USED?" << endl;
        
        cout << "\n    1. OPERATING SYSTEMS:" << endl;
        cout << "       - Process scheduling queues" << endl;
        cout << "       - Memory management (free block lists)" << endl;
        cout << "       - File system directory structures" << endl;
        
        cout << "\n    2. WEB BROWSERS:" << endl;
        cout << "       - Browser history (back/forward navigation)" << endl;
        cout << "       - Tab management" << endl;
        cout << "       - Undo/Redo operations" << endl;
        
        cout << "\n    3. MULTIMEDIA APPLICATIONS:" << endl;
        cout << "       - Music playlist management" << endl;
        cout << "       - Video frame sequences" << endl;
        cout << "       - Image processing pipelines" << endl;
        
        cout << "\n    4. DATABASES:" << endl;
        cout << "       - Hash table collision resolution (chaining)" << endl;
        cout << "       - Index structures" << endl;
        cout << "       - Query result caching" << endl;
        
        cout << "\n    5. NETWORK PROGRAMMING:" << endl;
        cout << "       - Packet queuing" << endl;
        cout << "       - Connection pools" << endl;
        cout << "       - Load balancer node lists" << endl;
        
        cout << "\n    6. GAMES:" << endl;
        cout << "       - Game object management" << endl;
        cout << "       - AI pathfinding node lists" << endl;
        cout << "       - Inventory systems" << endl;
    }
};

/*
================================================================================
                           INTERACTIVE MENU SYSTEM
================================================================================
*/

class TutorialMenu {
private:
    LinkedListTutorial tutorial;
    
public:
    void displayMainMenu() {
        cout << "\n" << string(80, '=') << endl;
        cout << "              INTERACTIVE LINKED LIST TUTORIAL MENU" << endl;
        cout << string(80, '=') << endl;
        cout << "  BASIC OPERATIONS:" << endl;
        cout << "    1. Insert at Beginning" << endl;
        cout << "    2. Insert at End" << endl;
        cout << "    3. Insert at Position" << endl;
        cout << "    4. Delete from Beginning" << endl;
        cout << "    5. Delete from End" << endl;
        cout << "    6. Delete from Position" << endl;
        cout << "    7. Search for Value" << endl;
        cout << "    8. Traverse List" << endl;
        cout << "\n  VISUALIZATION & ANALYSIS:" << endl;
        cout << "    9. Show Current List" << endl;
        cout << "    10. Show Memory Layout" << endl;
        cout << "    11. Clear Entire List" << endl;
        cout << "\n  EDUCATIONAL DEMONSTRATIONS:" << endl;
        cout << "    12. Node Concept Demo" << endl;
        cout << "    13. Memory Management Demo" << endl;
        cout << "    14. Complexity Analysis" << endl;
        cout << "    15. Real-World Applications" << endl;
        cout << "\n  PROGRAM CONTROL:" << endl;
        cout << "    16. Tutorial Introduction" << endl;
        cout << "    0. Exit Program" << endl;
        cout << string(80, '=') << endl;
        cout << "  Current List Size: " << tutorial.getSize() << " nodes" << endl;
        cout << "  Choose an option (0-16): ";
    }
    
    void handleUserChoice(int choice) {
        int value, position;
        
        switch (choice) {
            case 1:
                cout << "  Enter value to insert at beginning: ";
                cin >> value;
                tutorial.insertAtBeginning(value);
                tutorial.waitForEnter();
                break;
                
            case 2:
                cout << "  Enter value to insert at end: ";
                cin >> value;
                tutorial.insertAtEnd(value);
                tutorial.waitForEnter();
                break;
                
            case 3:
                cout << "  Enter value to insert: ";
                cin >> value;
                cout << "  Enter position (0-" << tutorial.getSize() << "): ";
                cin >> position;
                tutorial.insertAtPosition(value, position);
                tutorial.waitForEnter();
                break;
                
            case 4:
                tutorial.deleteFromBeginning();
                tutorial.waitForEnter();
                break;
                
            case 5:
                tutorial.deleteFromEnd();
                tutorial.waitForEnter();
                break;
                
            case 6:
                if (tutorial.getSize() == 0) {
                    cout << "  List is empty! Cannot delete." << endl;
                } else {
                    cout << "  Enter position to delete (0-" << (tutorial.getSize() - 1) << "): ";
                    cin >> position;
                    tutorial.deleteFromPosition(position);
                }
                tutorial.waitForEnter();
                break;
                
            case 7:
                cout << "  Enter value to search: ";
                cin >> value;
                tutorial.search(value);
                tutorial.waitForEnter();
                break;
                
            case 8:
                tutorial.traverse();
                tutorial.waitForEnter();
                break;
                
            case 9:
                tutorial.visualizeList();
                tutorial.waitForEnter();
                break;
                
            case 10:
                tutorial.visualizeMemory();
                tutorial.waitForEnter();
                break;
                
            case 11:
                tutorial.printSeparator("CLEAR LIST OPERATION");
                cout << "    Clearing all nodes from the list..." << endl;
                tutorial.clear();
                cout << "    List cleared successfully!" << endl;
                tutorial.waitForEnter();
                break;
                
            case 12:
                tutorial.demonstrateNodeConcept();
                break;
                
            case 13:
                tutorial.demonstrateMemoryManagement();
                tutorial.waitForEnter();
                break;
                
            case 14:
                tutorial.demonstrateComplexityAnalysis();
                tutorial.waitForEnter();
                break;
                
            case 15:
                tutorial.demonstrateRealWorldApplications();
                tutorial.waitForEnter();
                break;
                
            case 16:
                displayTutorialIntroduction();
                tutorial.waitForEnter();
                break;
                
            case 0:
                cout << "\n  Thank you for using the Linked List Tutorial!" << endl;
                break;
                
            default:
                cout << "  Invalid choice! Please try again." << endl;
                tutorial.waitForEnter();
                break;
        }
    }
    
    void displayTutorialIntroduction() {
        tutorial.printSeparator("WELCOME TO THE LINKED LIST TUTORIAL");
        
        cout << "    WHAT IS A LINKED LIST?" << endl;
        cout << "    A linked list is a linear data structure where elements (nodes)" << endl;
        cout << "    are not stored in contiguous memory locations. Instead, each" << endl;
        cout << "    node contains data and a pointer/reference to the next node." << endl;
        
        cout << "\n    KEY CHARACTERISTICS:" << endl;
        cout << "    • Dynamic size - can grow/shrink during runtime" << endl;
        cout << "    • Non-contiguous memory allocation" << endl;
        cout << "    • Efficient insertion/deletion at the beginning" << endl;
        cout << "    • No random access (must traverse from head)" << endl;
        
        cout << "\n    VISUAL REPRESENTATION:" << endl;
        cout << "    Head -> [Data|Next] -> [Data|Next] -> [Data|NULL]" << endl;
        cout << "             Node 1         Node 2         Node 3" << endl;
        
        cout << "\n    WHY USE LINKED LISTS?" << endl;
        cout << "    ✓ Dynamic memory allocation" << endl;
        cout << "    ✓ Efficient insertion/deletion at beginning" << endl;
        cout << "    ✓ Memory efficient (allocate only what's needed)" << endl;
        cout << "    ✓ No memory waste (unlike arrays with fixed size)" << endl;
        
        cout << "\n    WHEN NOT TO USE LINKED LISTS?" << endl;
        cout << "    ✗ When you need random access by index" << endl;
        cout << "    ✗ When memory is extremely limited (pointer overhead)" << endl;
        cout << "    ✗ When cache performance is critical" << endl;
        
        cout << "\n    COMPARISON WITH OTHER DATA STRUCTURES:" << endl;
        cout << "    Arrays vs Linked Lists:" << endl;
        cout << "    • Arrays: Fixed size, contiguous memory, O(1) access" << endl;
        cout << "    • Linked Lists: Dynamic size, scattered memory, O(n) access" << endl;
        
        cout << "\n    TUTORIAL LEARNING PATH:" << endl;
        cout << "    1. Start with Node Concept Demo (Option 12)" << endl;
        cout << "    2. Practice basic operations (Insert/Delete)" << endl;
        cout << "    3. Use visualization tools to understand memory layout" << endl;
        cout << "    4. Study complexity analysis" << endl;
        cout << "    5. Explore real-world applications" << endl;
        
        cout << "\n    MEMORY MANAGEMENT NOTES:" << endl;
        cout << "    • This tutorial demonstrates proper memory management" << endl;
        cout << "    • Watch the memory allocation/deallocation messages" << endl;
        cout << "    • Each 'new' operation is paired with 'delete'" << endl;
        cout << "    • Destructors ensure no memory leaks" << endl;
    }
    
    void run() {
        cout << "\n" << string(80, '*') << endl;
        cout << "              WELCOME TO THE INTERACTIVE LINKED LIST TUTORIAL" << endl;
        cout << "                           Complete C++ Educational Program" << endl;
        cout << string(80, '*') << endl;
        cout << "  This tutorial will teach you everything about linked lists through" << endl;
        cout << "  hands-on practice, detailed explanations, and visual demonstrations." << endl;
        cout << string(80, '*') << endl;
        
        // Show introduction first
        displayTutorialIntroduction();
        tutorial.waitForEnter();
        
        int choice;
        do {
            displayMainMenu();
            cin >> choice;
            
            // Clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            handleUserChoice(choice);
            
        } while (choice != 0);
        
        cout << "\n" << string(80, '*') << endl;
        cout << "                        TUTORIAL SUMMARY" << endl;
        cout << string(80, '*') << endl;
        cout << "  Congratulations! You've completed the Linked List Tutorial." << endl;
        cout << "\n  KEY CONCEPTS YOU'VE LEARNED:" << endl;
        cout << "  ✓ Node structure and implementation" << endl;
        cout << "  ✓ Creating and connecting nodes" << endl;
        cout << "  ✓ Traversing linked lists" << endl;
        cout << "  ✓ Inserting nodes (beginning, middle, end)" << endl;
        cout << "  ✓ Deleting nodes from various positions" << endl;
        cout << "  ✓ Memory management best practices" << endl;
        cout << "  ✓ Time complexity analysis" << endl;
        cout << "  ✓ Real-world applications" << endl;
        
        cout << "\n  NEXT STEPS FOR CONTINUED LEARNING:" << endl;
        cout << "  1. Implement doubly linked lists" << endl;
        cout << "  2. Study circular linked lists" << endl;
        cout << "  3. Learn about linked list variants (skip lists)" << endl;
        cout << "  4. Practice linked list problems:" << endl;
        cout << "     • Reverse a linked list" << endl;
        cout << "     • Detect cycles in a linked list" << endl;
        cout << "     • Merge two sorted linked lists" << endl;
        cout << "     • Find the middle node" << endl;
        cout << "     • Remove duplicates" << endl;
        
        cout << "\n  CODING BEST PRACTICES LEARNED:" << endl;
        cout << "  • Always check for null pointers" << endl;
        cout << "  • Implement proper destructors for cleanup" << endl;
        cout << "  • Use consistent naming conventions" << endl;
        cout << "  • Add comprehensive comments for educational code" << endl;
        cout << "  • Handle edge cases (empty list, single node)" << endl;
        cout << "  • Provide clear error messages" << endl;
        
        cout << "\n  PERFORMANCE INSIGHTS GAINED:" << endl;
        cout << "  • O(1) operations: Insert/delete at beginning" << endl;
        cout << "  • O(n) operations: Insert/delete at end, search, traverse" << endl;
        cout << "  • Memory overhead: Each node requires extra pointer storage" << endl;
        cout << "  • Cache performance: Poor due to non-contiguous memory" << endl;
        
        cout << string(80, '*') << endl;
        cout << "  Thank you for completing this comprehensive tutorial!" << endl;
        cout << "  Keep practicing and exploring data structures!" << endl;
        cout << string(80, '*') << endl;
    }
};

/*
================================================================================
                                MAIN FUNCTION
================================================================================

The main function initializes the tutorial system and starts the interactive
learning experience. It demonstrates proper program structure and exception
handling.
*/

int main() {
    try {
        cout << "Initializing Linked List Tutorial System..." << endl;
        
        // Create and run the tutorial menu system
        TutorialMenu menu;
        menu.run();
        
        cout << "\nTutorial system shutting down gracefully..." << endl;
        return 0;
        
    } catch (const exception& e) {
        cout << "Error occurred in tutorial system: " << e.what() << endl;
        return 1;
    } catch (...) {
        cout << "Unknown error occurred in tutorial system!" << endl;
        return 1;
    }
}

/*
================================================================================
                            COMPILATION AND USAGE NOTES
================================================================================

COMPILATION:
g++ -o linked_list_tutorial linked_list_tutorial.cpp -std=c++11

USAGE:
./linked_list_tutorial

FEATURES DEMONSTRATED IN THIS PROGRAM:
• Complete linked list implementation with all basic operations
• Educational explanations for each concept and operation
• Step-by-step visual demonstrations of operations
• Memory management with proper allocation/deallocation
• Interactive menu system for hands-on learning
• Time complexity analysis and performance comparisons
• Real-world applications and use cases
• Best practices for C++ programming
• Error handling and edge case management
• Comprehensive commenting and documentation

EDUCATIONAL VALUE:
This program serves as a complete learning resource for understanding:
• How linked lists work internally
• When and why to use linked lists
• How to implement linked list operations
• Memory management in dynamic data structures
• Algorithm complexity analysis
• C++ programming best practices

The program is designed to be:
• Self-contained and runnable
• Educational with extensive explanations
• Interactive for hands-on learning
• Well-documented with comprehensive comments
• Demonstrative of best practices
• Suitable for beginners with some C++ knowledge

CUSTOMIZATION:
You can easily modify this template to create similar tutorials for:
• Doubly linked lists
• Circular linked lists
• Binary trees
• Hash tables
• Stacks and queues
• Other data structures

Simply replace the core data structure implementation while keeping
the educational framework and interactive menu system.

================================================================================
*/
