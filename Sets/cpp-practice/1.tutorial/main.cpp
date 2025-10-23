#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <chrono>
#include <vector>
#include <iomanip>

using namespace std;
using namespace chrono;

// ============================================================================
// UTILITY FUNCTIONS
// ============================================================================

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

template<typename T>
void displaySet(const set<T>& s, const string& setName) {
    cout << "\n" << setName << " contents: { ";
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << "}\nSize: " << s.size() << endl;
}

// ============================================================================
// LEVEL 1: BASIC SET OPERATIONS
// ============================================================================

void level1_BasicSetOperations() {
    clearScreen();
    cout << "=== LEVEL 1: BASIC SET OPERATIONS ===\n\n";
    
    set<int> numbers;
    int choice, value;
    
    do {
        cout << "\n--- Basic Set Menu ---\n";
        cout << "1. Insert element\n";
        cout << "2. Remove element\n";
        cout << "3. Check if element exists\n";
        cout << "4. Display set\n";
        cout << "5. Get set size\n";
        cout << "6. Clear set\n";
        cout << "0. Back to main menu\n";
        cout << "Choice: ";
        cin >> choice;
        
        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        
        switch (choice) {
            case 1: {
                cout << "Enter value to insert: ";
                cin >> value;
                
                // insert() returns a pair<iterator, bool>
                // bool indicates if insertion was successful (true) or element existed (false)
                auto result = numbers.insert(value);
                
                if (result.second) {
                    cout << "✓ Value " << value << " inserted successfully!\n";
                } else {
                    cout << "✗ Value " << value << " already exists in set (duplicates not allowed).\n";
                }
                break;
            }
            
            case 2: {
                cout << "Enter value to remove: ";
                cin >> value;
                
                // erase() returns number of elements removed (0 or 1 for set)
                size_t removed = numbers.erase(value);
                
                if (removed > 0) {
                    cout << "✓ Value " << value << " removed successfully!\n";
                } else {
                    cout << "✗ Value " << value << " not found in set.\n";
                }
                break;
            }
            
            case 3: {
                cout << "Enter value to search: ";
                cin >> value;
                
                // find() returns iterator to element or end() if not found
                auto it = numbers.find(value);
                
                if (it != numbers.end()) {
                    cout << "✓ Value " << value << " EXISTS in the set!\n";
                } else {
                    cout << "✗ Value " << value << " NOT FOUND in the set.\n";
                }
                
                // Alternative: count() returns 0 or 1 (faster for just checking existence)
                cout << "Using count(): " << (numbers.count(value) ? "EXISTS" : "NOT FOUND") << "\n";
                break;
            }
            
            case 4: {
                displaySet(numbers, "Numbers Set");
                cout << "\nNote: Elements are automatically sorted in ascending order!\n";
                break;
            }
            
            case 5: {
                cout << "Set size: " << numbers.size() << " elements\n";
                cout << "Is empty? " << (numbers.empty() ? "Yes" : "No") << "\n";
                break;
            }
            
            case 6: {
                numbers.clear();
                cout << "✓ Set cleared! All elements removed.\n";
                break;
            }
            
            case 0:
                cout << "Returning to main menu...\n";
                break;
                
            default:
                cout << "Invalid choice! Try again.\n";
        }
        
    } while (choice != 0);
}

// ============================================================================
// LEVEL 2: SET ITERATORS AND TRAVERSAL
// ============================================================================

void level2_IteratorsAndTraversal() {
    clearScreen();
    cout << "=== LEVEL 2: SET ITERATORS AND TRAVERSAL ===\n\n";
    
    set<string> words = {"apple", "banana", "cherry", "date", "elderberry"};
    
    int choice;
    
    do {
        displaySet(words, "Words Set");
        
        cout << "\n--- Iterator Operations Menu ---\n";
        cout << "1. Forward iteration (begin to end)\n";
        cout << "2. Reverse iteration (rbegin to rend)\n";
        cout << "3. Access first and last elements\n";
        cout << "4. Find and iterate from specific element\n";
        cout << "5. Range-based iteration\n";
        cout << "6. Add custom word\n";
        cout << "0. Back to main menu\n";
        cout << "Choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        switch (choice) {
            case 1: {
                cout << "\nForward iteration using iterators:\n";
                cout << "for (auto it = words.begin(); it != words.end(); ++it)\n\n";
                
                int index = 0;
                for (auto it = words.begin(); it != words.end(); ++it) {
                    cout << "  Position " << index++ << ": " << *it << "\n";
                }
                pauseScreen();
                break;
            }
            
            case 2: {
                cout << "\nReverse iteration using reverse iterators:\n";
                cout << "for (auto it = words.rbegin(); it != words.rend(); ++it)\n\n";
                
                for (auto it = words.rbegin(); it != words.rend(); ++it) {
                    cout << "  " << *it << "\n";
                }
                pauseScreen();
                break;
            }
            
            case 3: {
                if (!words.empty()) {
                    // Sets don't have front() or back() methods
                    // Use iterators or begin()/rbegin() instead
                    cout << "\nFirst element: " << *words.begin() << "\n";
                    cout << "Last element: " << *words.rbegin() << "\n";
                    
                    cout << "\nNote: Sets don't have direct access like vectors.\n";
                    cout << "Use iterators or begin()/rbegin() for first/last elements.\n";
                } else {
                    cout << "Set is empty!\n";
                }
                pauseScreen();
                break;
            }
            
            case 4: {
                cout << "Enter word to find: ";
                string word;
                cin >> word;
                
                auto it = words.find(word);
                
                if (it != words.end()) {
                    cout << "\n✓ Found '" << *it << "'!\n";
                    cout << "\nElements from '" << word << "' onwards:\n";
                    
                    // Iterate from found position to end
                    for (auto current = it; current != words.end(); ++current) {
                        cout << "  " << *current << "\n";
                    }
                } else {
                    cout << "✗ Word not found!\n";
                }
                pauseScreen();
                break;
            }
            
            case 5: {
                cout << "\nRange-based for loop (most common and readable):\n";
                cout << "for (const auto& word : words)\n\n";
                
                for (const auto& word : words) {
                    cout << "  → " << word << "\n";
                }
                
                cout << "\nThis is the preferred way for simple iteration!\n";
                pauseScreen();
                break;
            }
            
            case 6: {
                cout << "Enter word to add: ";
                string word;
                cin >> word;
                
                words.insert(word);
                cout << "✓ Word added! Set auto-sorted alphabetically.\n";
                pauseScreen();
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
        
        clearScreen();
        
    } while (choice != 0);
}

// ============================================================================
// LEVEL 3: SET ALGORITHMS AND OPERATIONS
// ============================================================================

void level3_SetAlgorithms() {
    clearScreen();
    cout << "=== LEVEL 3: SET ALGORITHMS AND OPERATIONS ===\n\n";
    
    set<int> setA = {1, 2, 3, 4, 5};
    set<int> setB = {4, 5, 6, 7, 8};
    
    int choice;
    
    do {
        displaySet(setA, "Set A");
        displaySet(setB, "Set B");
        
        cout << "\n--- Set Algorithms Menu ---\n";
        cout << "1. Union (A ∪ B) - All elements from both sets\n";
        cout << "2. Intersection (A ∩ B) - Common elements\n";
        cout << "3. Difference (A - B) - Elements in A but not in B\n";
        cout << "4. Symmetric Difference (A Δ B) - Elements in either but not both\n";
        cout << "5. Subset check - Is A subset of B?\n";
        cout << "6. Modify sets\n";
        cout << "0. Back to main menu\n";
        cout << "Choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        switch (choice) {
            case 1: {
                // Union: combines all unique elements from both sets
                set<int> result;
                set_union(setA.begin(), setA.end(),
                         setB.begin(), setB.end(),
                         inserter(result, result.begin()));
                
                displaySet(result, "\nUnion (A ∪ B)");
                cout << "\nExplanation: Contains all elements that are in A OR B (or both).\n";
                cout << "Use case: Combining two collections without duplicates.\n";
                pauseScreen();
                break;
            }
            
            case 2: {
                // Intersection: only elements present in both sets
                set<int> result;
                set_intersection(setA.begin(), setA.end(),
                               setB.begin(), setB.end(),
                               inserter(result, result.begin()));
                
                displaySet(result, "\nIntersection (A ∩ B)");
                cout << "\nExplanation: Contains only elements that are in BOTH A AND B.\n";
                cout << "Use case: Finding common items (e.g., mutual friends, shared interests).\n";
                pauseScreen();
                break;
            }
            
            case 3: {
                // Difference: elements in A but not in B
                set<int> result;
                set_difference(setA.begin(), setA.end(),
                             setB.begin(), setB.end(),
                             inserter(result, result.begin()));
                
                displaySet(result, "\nDifference (A - B)");
                cout << "\nExplanation: Contains elements that are in A but NOT in B.\n";
                cout << "Use case: Finding what's unique to one set (e.g., items not purchased).\n";
                pauseScreen();
                break;
            }
            
            case 4: {
                // Symmetric difference: elements in either A or B but not in both
                set<int> result;
                set_symmetric_difference(setA.begin(), setA.end(),
                                       setB.begin(), setB.end(),
                                       inserter(result, result.begin()));
                
                displaySet(result, "\nSymmetric Difference (A Δ B)");
                cout << "\nExplanation: Elements that are in A OR B but NOT in both.\n";
                cout << "Use case: Finding differences between two versions.\n";
                pauseScreen();
                break;
            }
            
            case 5: {
                // Check if setA is subset of setB
                bool isSubset = includes(setB.begin(), setB.end(),
                                       setA.begin(), setA.end());
                
                cout << "\nIs Set A a subset of Set B? " << (isSubset ? "YES" : "NO") << "\n";
                
                // Check if setB is subset of setA
                isSubset = includes(setA.begin(), setA.end(),
                                  setB.begin(), setB.end());
                
                cout << "Is Set B a subset of Set A? " << (isSubset ? "YES" : "NO") << "\n";
                
                cout << "\nExplanation: A is subset of B if all elements of A are in B.\n";
                cout << "Use case: Checking permissions, validating requirements.\n";
                pauseScreen();
                break;
            }
            
            case 6: {
                cout << "\nModify which set? (1=A, 2=B): ";
                int setChoice;
                cin >> setChoice;
                
                set<int>& targetSet = (setChoice == 1) ? setA : setB;
                
                cout << "1. Add element\n2. Remove element\n3. Clear set\nChoice: ";
                int action;
                cin >> action;
                
                if (action == 1) {
                    cout << "Enter value: ";
                    int val;
                    cin >> val;
                    targetSet.insert(val);
                } else if (action == 2) {
                    cout << "Enter value: ";
                    int val;
                    cin >> val;
                    targetSet.erase(val);
                } else if (action == 3) {
                    targetSet.clear();
                }
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
        
        clearScreen();
        
    } while (choice != 0);
}

// ============================================================================
// LEVEL 4: CUSTOM COMPARATORS AND ADVANCED FEATURES
// ============================================================================

// Custom struct for demonstrating custom objects in sets
struct Student {
    string name;
    int score;
    
    // Constructor
    Student(string n, int s) : name(n), score(s) {}
    
    // Operator < required for set ordering
    bool operator<(const Student& other) const {
        // Sort by score descending, then by name ascending
        if (score != other.score)
            return score > other.score;  // Higher scores first
        return name < other.name;
    }
};

// Custom comparator as a separate function object
struct CompareByName {
    bool operator()(const Student& a, const Student& b) const {
        return a.name < b.name;  // Sort alphabetically by name
    }
};

void level4_CustomComparators() {
    clearScreen();
    cout << "=== LEVEL 4: CUSTOM COMPARATORS AND ADVANCED FEATURES ===\n\n";
    
    // Set with default comparator (uses Student::operator<)
    set<Student> studentsByScore;
    
    // Set with custom comparator
    set<Student, CompareByName> studentsByName;
    
    // Add some sample students
    studentsByScore.insert(Student("Alice", 95));
    studentsByScore.insert(Student("Bob", 87));
    studentsByScore.insert(Student("Charlie", 95));
    studentsByScore.insert(Student("Diana", 92));
    
    studentsByName.insert(Student("Alice", 95));
    studentsByName.insert(Student("Bob", 87));
    studentsByName.insert(Student("Charlie", 95));
    studentsByName.insert(Student("Diana", 92));
    
    int choice;
    
    do {
        cout << "\n--- Custom Comparators Menu ---\n";
        cout << "1. Display students sorted by score (default comparator)\n";
        cout << "2. Display students sorted by name (custom comparator)\n";
        cout << "3. Add new student\n";
        cout << "4. Find student by name\n";
        cout << "5. Remove student\n";
        cout << "6. Demonstrate lower_bound and upper_bound\n";
        cout << "0. Back to main menu\n";
        cout << "Choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        switch (choice) {
            case 1: {
                cout << "\nStudents sorted by SCORE (descending), then by NAME:\n";
                cout << setw(15) << left << "Name" << "Score\n";
                cout << "------------------------\n";
                for (const auto& student : studentsByScore) {
                    cout << setw(15) << left << student.name 
                         << student.score << "\n";
                }
                pauseScreen();
                break;
            }
            
            case 2: {
                cout << "\nStudents sorted by NAME (alphabetically):\n";
                cout << setw(15) << left << "Name" << "Score\n";
                cout << "------------------------\n";
                for (const auto& student : studentsByName) {
                    cout << setw(15) << left << student.name 
                         << student.score << "\n";
                }
                pauseScreen();
                break;
            }
            
            case 3: {
                cin.ignore();
                cout << "Enter student name: ";
                string name;
                getline(cin, name);
                cout << "Enter score: ";
                int score;
                cin >> score;
                
                Student newStudent(name, score);
                studentsByScore.insert(newStudent);
                studentsByName.insert(newStudent);
                
                cout << "✓ Student added to both sets!\n";
                pauseScreen();
                break;
            }
            
            case 4: {
                cin.ignore();
                cout << "Enter student name to find: ";
                string name;
                getline(cin, name);
                
                // Create temporary student for searching
                Student temp(name, 0);
                auto it = studentsByName.find(temp);
                
                if (it != studentsByName.end()) {
                    cout << "\n✓ Found: " << it->name 
                         << " with score " << it->score << "\n";
                } else {
                    cout << "\n✗ Student not found!\n";
                }
                pauseScreen();
                break;
            }
            
            case 5: {
                cin.ignore();
                cout << "Enter student name to remove: ";
                string name;
                getline(cin, name);
                
                Student temp(name, 0);
                size_t removed = studentsByName.erase(temp);
                
                if (removed > 0) {
                    cout << "✓ Student removed!\n";
                } else {
                    cout << "✗ Student not found!\n";
                }
                pauseScreen();
                break;
            }
            
            case 6: {
                cout << "\nDemonstrating lower_bound and upper_bound:\n";
                cout << "\nThese find the first position where an element could be inserted.\n";
                
                // Create a simple integer set for demonstration
                set<int> numbers = {10, 20, 30, 40, 50};
                displaySet(numbers, "Number Set");
                
                cout << "\nEnter a value to search: ";
                int val;
                cin >> val;
                
                // lower_bound: first element >= val
                auto lower = numbers.lower_bound(val);
                if (lower != numbers.end()) {
                    cout << "lower_bound(" << val << ") = " << *lower 
                         << " (first element >= " << val << ")\n";
                } else {
                    cout << "lower_bound(" << val << ") = end() (all elements < " << val << ")\n";
                }
                
                // upper_bound: first element > val
                auto upper = numbers.upper_bound(val);
                if (upper != numbers.end()) {
                    cout << "upper_bound(" << val << ") = " << *upper 
                         << " (first element > " << val << ")\n";
                } else {
                    cout << "upper_bound(" << val << ") = end() (all elements <= " << val << ")\n";
                }
                
                cout << "\nUse case: Finding ranges, implementing binary search operations.\n";
                pauseScreen();
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
        
        clearScreen();
        
    } while (choice != 0);
}

// ============================================================================
// LEVEL 5: SET VS UNORDERED_SET COMPARISON
// ============================================================================

void level5_SetVsUnorderedSet() {
    clearScreen();
    cout << "=== LEVEL 5: SET VS UNORDERED_SET PERFORMANCE ===\n\n";
    
    int choice;
    
    do {
        cout << "\n--- Performance Comparison Menu ---\n";
        cout << "1. Compare insertion performance\n";
        cout << "2. Compare search performance\n";
        cout << "3. Compare iteration performance\n";
        cout << "4. Display ordering differences\n";
        cout << "5. Memory usage characteristics\n";
        cout << "0. Back to main menu\n";
        cout << "Choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        switch (choice) {
            case 1: {
                cout << "\nInserting 100,000 elements...\n\n";
                
                // Test set insertion
                set<int> orderedSet;
                auto start = high_resolution_clock::now();
                for (int i = 0; i < 100000; i++) {
                    orderedSet.insert(i);
                }
                auto end = high_resolution_clock::now();
                auto setTime = duration_cast<microseconds>(end - start).count();
                
                // Test unordered_set insertion
                unordered_set<int> unorderedSet;
                start = high_resolution_clock::now();
                for (int i = 0; i < 100000; i++) {
                    unorderedSet.insert(i);
                }
                end = high_resolution_clock::now();
                auto unorderedTime = duration_cast<microseconds>(end - start).count();
                
                cout << "set<int> insertion time: " << setTime << " μs\n";
                cout << "unordered_set<int> insertion time: " << unorderedTime << " μs\n";
                cout << "\nSpeed difference: " 
                     << fixed << setprecision(2)
                     << (double)setTime / unorderedTime << "x\n";
                
                cout << "\n📊 Analysis:\n";
                cout << "• set: O(log n) per insertion (Red-Black Tree)\n";
                cout << "• unordered_set: O(1) average per insertion (Hash Table)\n";
                cout << "• unordered_set is typically faster for insertion!\n";
                
                pauseScreen();
                break;
            }
            
            case 2: {
                cout << "\nSearching for 10,000 elements in 50,000 element containers...\n\n";
                
                // Prepare data
                set<int> orderedSet;
                unordered_set<int> unorderedSet;
                for (int i = 0; i < 50000; i++) {
                    orderedSet.insert(i);
                    unorderedSet.insert(i);
                }
                
                // Test set search
                auto start = high_resolution_clock::now();
                for (int i = 0; i < 10000; i++) {
                    orderedSet.find(i * 5);
                }
                auto end = high_resolution_clock::now();
                auto setTime = duration_cast<microseconds>(end - start).count();
                
                // Test unordered_set search
                start = high_resolution_clock::now();
                for (int i = 0; i < 10000; i++) {
                    unorderedSet.find(i * 5);
                }
                end = high_resolution_clock::now();
                auto unorderedTime = duration_cast<microseconds>(end - start).count();
                
                cout << "set<int> search time: " << setTime << " μs\n";
                cout << "unordered_set<int> search time: " << unorderedTime << " μs\n";
                cout << "\nSpeed difference: " 
                     << fixed << setprecision(2)
                     << (double)setTime / unorderedTime << "x\n";
                
                cout << "\n📊 Analysis:\n";
                cout << "• set: O(log n) per search\n";
                cout << "• unordered_set: O(1) average per search\n";
                cout << "• unordered_set is significantly faster for lookups!\n";
                
                pauseScreen();
                break;
            }
            
            case 3: {
                cout << "\nIterating through 100,000 elements...\n\n";
                
                // Prepare data
                set<int> orderedSet;
                unordered_set<int> unorderedSet;
                for (int i = 0; i < 100000; i++) {
                    orderedSet.insert(i);
                    unorderedSet.insert(i);
                }
                
                // Test set iteration
                auto start = high_resolution_clock::now();
                long long sum = 0;
                for (const auto& val : orderedSet) {
                    sum += val;
                }
                auto end = high_resolution_clock::now();
                auto setTime = duration_cast<microseconds>(end - start).count();
                
                // Test unordered_set iteration
                start = high_resolution_clock::now();
                sum = 0;
                for (const auto& val : unorderedSet) {
                    sum += val;
                }
                end = high_resolution_clock::now();
                auto unorderedTime = duration_cast<microseconds>(end - start).count();
                
                cout << "set<int> iteration time: " << setTime << " μs\n";
                cout << "unordered_set<int> iteration time: " << unorderedTime << " μs\n";
                
                cout << "\n📊 Analysis:\n";
                cout << "• set: O(n) - sequential tree traversal\n";
                cout << "• unordered_set: O(n) - iterates through hash buckets\n";
                cout << "• Similar performance, but set has better cache locality\n";
                
                pauseScreen();
                break;
            }
            
            case 4: {
                set<int> orderedSet = {50, 10, 30, 20, 40};
                unordered_set<int> unorderedSet = {50, 10, 30, 20, 40};
                
                cout << "\nInput order: 50, 10, 30, 20, 40\n";
                
                cout << "\nset<int> (always sorted):\n";
                cout << "{ ";
                for (const auto& val : orderedSet) {
                    cout << val << " ";
                }
                cout << "}\n";
                
                cout << "\nunordered_set<int> (no guaranteed order):\n";
                cout << "{ ";
                for (const auto& val : unorderedSet) {
                    cout << val << " ";
                }
                cout << "}\n";
                
                cout << "\n📊 Key Difference:\n";
                cout << "• set: ALWAYS maintains sorted order (Red-Black Tree)\n";
                cout << "• unordered_set: NO order guarantee (Hash Table)\n";
                cout << "• Use set when you need sorted data!\n";
                
                pauseScreen();
                break;
            }
            
            case 5: {
                cout << "\n📊 MEMORY USAGE CHARACTERISTICS:\n\n";
                
                cout << "set<T> (Red-Black Tree):\n";
                cout << "• Per element: ~3 pointers + data + color bit\n";
                cout << "• Overhead: ~24-32 bytes per element (64-bit system)\n";
                cout << "• Total: sizeof(T) + ~28 bytes\n";
                cout << "• Better cache locality due to tree structure\n\n";
                
                cout << "unordered_set<T> (Hash Table):\n";
                cout << "• Per element: 1 pointer + data\n";
                cout << "• Overhead: ~8-16 bytes per element\n";
                cout << "• Additional: bucket array (can be large)\n";
                cout << "• Total: sizeof(T) + ~12 bytes + bucket overhead\n";
                cout << "• Worse cache locality (scattered in memory)\n\n";
                
                cout << "WHEN TO USE WHICH:\n\n";
                cout << "Use set when:\n";
                cout << "  ✓ You need sorted/ordered data\n";
                cout << "  ✓ You need range queries (lower_bound, upper_bound)\n";
                cout << "  ✓ You want predictable performance (no hash collisions)\n";
                cout << "  ✓ Memory usage is critical\n\n";
                
                cout << "Use unordered_set when:\n";
                cout << "  ✓ You need fastest insertion/search (O(1) vs O(log n))\n";
                cout << "  ✓ You don't care about order\n";
                cout << "  ✓ You have a good hash function\n";
                cout << "  ✓ Performance is more important than memory\n";
                
                pauseScreen();
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
        
        clearScreen();
        
    } while (choice != 0);
}

// ============================================================================
// LEVEL 6: REAL-WORLD APPLICATIONS
// ============================================================================

void level6_RealWorldApplications() {
    clearScreen();
    cout << "=== LEVEL 6: REAL-WORLD APPLICATIONS ===\n\n";
    
    int choice;
    
    do {
        cout << "\n--- Real-World Examples Menu ---\n";
        cout << "1. Duplicate Removal System\n";
        cout << "2. Unique Visitor Tracker\n";
        cout << "3. Spell Checker Dictionary\n";
        cout << "4. Friend Recommendation System\n";
        cout << "5. Tag Management System\n";
        cout << "0. Back to main menu\n";
        cout << "Choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        switch (choice) {
            case 1: {
                cout << "\n=== DUPLICATE REMOVAL SYSTEM ===\n";
                cout << "Use case: Remove duplicates from email list, log entries, etc.\n\n";
                
                vector<string> emails = {
                    "user1@email.com", "user2@email.com", "user1@email.com",
                    "user3@email.com", "user2@email.com", "user4@email.com"
                };
                
                cout << "Original email list (" << emails.size() << " entries):\n";
                for (const auto& email : emails) {
                    cout << "  " << email << "\n";
                }
                
                // Remove duplicates using set
                set<string> uniqueEmails(emails.begin(), emails.end());
                
                cout << "\nAfter removing duplicates (" << uniqueEmails.size() << " unique):\n";
                for (const auto& email : uniqueEmails) {
                    cout << "  " << email << "\n";
                }
                
                cout << "\n✓ Removed " << (emails.size() - uniqueEmails.size()) 
                     << " duplicate entries!\n";
                
                cout << "\nCode explanation:\n";
                cout << "set<string> uniqueEmails(emails.begin(), emails.end());\n";
                cout << "• Constructor automatically removes duplicates\n";
                cout << "• O(n log n) time complexity\n";
                cout << "• Maintains alphabetical order as bonus!\n";
                
                pauseScreen();
                break;
            }
            
            case 2: {
                cout << "\n=== UNIQUE VISITOR TRACKER ===\n";
                cout << "Use case: Track unique visitors to a website\n\n";
                
                set<string> uniqueVisitors;
                vector<string> visitorLog;
                
                cout << "Simulating visitor tracking...\n";
                cout << "Enter visitor IPs (or 'done' to finish):\n\n";
                
                cin.ignore();
                string ip;
                while (true) {
                    cout << "Visitor IP: ";
                    getline(cin, ip);
                    
                    if (ip == "done") break;
                    
                    visitorLog.push_back(ip);
                    auto result = uniqueVisitors.insert(ip);
                    
                    if (result.second) {
                        cout << "  → New visitor! Total unique: " << uniqueVisitors.size() << "\n";
                    } else {
                        cout << "  → Returning visitor! Total unique: " << uniqueVisitors.size() << "\n";
                    }
                }
                
                cout << "\n📊 STATISTICS:\n";
                cout << "Total visits: " << visitorLog.size() << "\n";
                cout << "Unique visitors: " << uniqueVisitors.size() << "\n";
                cout << "Repeat visits: " << (visitorLog.size() - uniqueVisitors.size()) << "\n";
                
                if (!uniqueVisitors.empty()) {
                    cout << "\nUnique visitor list:\n";
                    for (const auto& visitor : uniqueVisitors) {
                        cout << "  • " << visitor << "\n";
                    }
                }
                
                pauseScreen();
                break;
            }
            
            case 3: {
                cout << "\n=== SPELL CHECKER DICTIONARY ===\n";
                cout << "Use case: Fast word lookup for spell checking\n\n";
                
                // Dictionary of valid words
                set<string> dictionary = {
                    "hello", "world", "computer", "program", "algorithm",
                    "data", "structure", "variable", "function", "class"
                };
                
                cout << "Dictionary loaded with " << dictionary.size() << " words.\n\n";
                
                cin.ignore();
                string text;
                cout << "Enter text to check (single line):\n";
                getline(cin, text);
                
                // Simple tokenization (split by spaces)
                vector<string> words;
                string word = "";
                for (char c : text) {
                    if (c == ' ') {
                        if (!word.empty()) {
                            words.push_back(word);
                            word = "";
                        }
                    } else {
                        word += tolower(c);
                    }
                }
                if (!word.empty()) words.push_back(word);
                
                cout << "\n📝 Spell Check Results:\n";
                int errors = 0;
                for (const auto& w : words) {
                    // O(log n) lookup
                    if (dictionary.find(w) == dictionary.end()) {
                        cout << "  ✗ '" << w << "' - NOT in dictionary\n";
                        errors++;
                    } else {
                        cout << "  ✓ '" << w << "' - OK\n";
                    }
                }
                
                cout << "\nTotal: " << words.size() << " words, " 
                     << errors << " errors\n";
                
                cout << "\n⚡ Performance: O(log n) lookup per word!\n";
                cout << "For 100,000 word dictionary: ~17 comparisons max\n";
                
                pauseScreen();
                break;
            }
            
            case 4: {
                cout << "\n=== FRIEND RECOMMENDATION SYSTEM ===\n";
                cout << "Use case: Social network - find mutual friends\n\n";
                
                // Friend lists
                set<string> aliceFriends = {"Bob", "Charlie", "David", "Eve"};
                set<string> bobFriends = {"Alice", "Charlie", "Frank", "Grace"};
                
                cout << "Alice's friends: ";
                for (const auto& f : aliceFriends) cout << f << " ";
                cout << "\n\nBob's friends: ";
                for (const auto& f : bobFriends) cout << f << " ";
                cout << "\n";
                
                // Find mutual friends (intersection)
                set<string> mutualFriends;
                set_intersection(aliceFriends.begin(), aliceFriends.end(),
                               bobFriends.begin(), bobFriends.end(),
                               inserter(mutualFriends, mutualFriends.begin()));
                
                cout << "\n👥 Mutual friends: ";
                for (const auto& f : mutualFriends) cout << f << " ";
                cout << "\n";
                
                // Find potential recommendations (friends of friends)
                set<string> recommendations;
                set_union(aliceFriends.begin(), aliceFriends.end(),
                         bobFriends.begin(), bobFriends.end(),
                         inserter(recommendations, recommendations.begin()));
                
                // Remove already connected people
                recommendations.erase("Alice");
                recommendations.erase("Bob");
                for (const auto& f : aliceFriends) {
                    recommendations.erase(f);
                }
                
                cout << "\n💡 Friend recommendations for Alice: ";
                for (const auto& f : recommendations) cout << f << " ";
                cout << "\n";
                
                cout << "\n📊 Application: Facebook, LinkedIn friend suggestions\n";
                cout << "Uses set_intersection for mutual connections\n";
                
                pauseScreen();
                break;
            }
            
            case 5: {
                cout << "\n=== TAG MANAGEMENT SYSTEM ===\n";
                cout << "Use case: Blog posts, articles, products\n\n";
                
                set<string> postTags;
                
                int tagChoice;
                do {
                    cout << "\nCurrent tags: ";
                    if (postTags.empty()) {
                        cout << "(none)";
                    } else {
                        for (const auto& tag : postTags) {
                            cout << "#" << tag << " ";
                        }
                    }
                    cout << "\n\n";
                    
                    cout << "1. Add tag\n";
                    cout << "2. Remove tag\n";
                    cout << "3. Check if tag exists\n";
                    cout << "4. Clear all tags\n";
                    cout << "0. Back\n";
                    cout << "Choice: ";
                    cin >> tagChoice;
                    
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        continue;
                    }
                    
                    cin.ignore();
                    
                    switch (tagChoice) {
                        case 1: {
                            cout << "Enter tag name: ";
                            string tag;
                            getline(cin, tag);
                            
                            auto result = postTags.insert(tag);
                            if (result.second) {
                                cout << "✓ Tag added!\n";
                            } else {
                                cout << "✗ Tag already exists!\n";
                            }
                            break;
                        }
                        
                        case 2: {
                            cout << "Enter tag to remove: ";
                            string tag;
                            getline(cin, tag);
                            
                            if (postTags.erase(tag)) {
                                cout << "✓ Tag removed!\n";
                            } else {
                                cout << "✗ Tag not found!\n";
                            }
                            break;
                        }
                        
                        case 3: {
                            cout << "Enter tag to check: ";
                            string tag;
                            getline(cin, tag);
                            
                            if (postTags.count(tag)) {
                                cout << "✓ Tag exists!\n";
                            } else {
                                cout << "✗ Tag not found!\n";
                            }
                            break;
                        }
                        
                        case 4: {
                            postTags.clear();
                            cout << "✓ All tags cleared!\n";
                            break;
                        }
                    }
                    
                } while (tagChoice != 0);
                
                break;
            }
            
            case 0:
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
        
        clearScreen();
        
    } while (choice != 0);
}

// ============================================================================
// MAIN MENU
// ============================================================================

void displayMainMenu() {
    cout << "\n╔════════════════════════════════════════════════════════╗\n";
    cout << "║         C++ SETS - INTERACTIVE LEARNING PROGRAM        ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n\n";
    
    cout << "📚 LEARNING LEVELS:\n\n";
    cout << "  1. Level 1: Basic Set Operations\n";
    cout << "     → Insert, remove, search, display\n\n";
    
    cout << "  2. Level 2: Iterators and Traversal\n";
    cout << "     → Forward, reverse, range-based loops\n\n";
    
    cout << "  3. Level 3: Set Algorithms\n";
    cout << "     → Union, intersection, difference\n\n";
    
    cout << "  4. Level 4: Custom Comparators\n";
    cout << "     → Custom objects, sorting, advanced features\n\n";
    
    cout << "  5. Level 5: Set vs Unordered_Set\n";
    cout << "     → Performance comparison, benchmarks\n\n";
    
    cout << "  6. Level 6: Real-World Applications\n";
    cout << "     → Practical examples and use cases\n\n";
    
    cout << "  0. Exit Program\n\n";
    cout << "╔════════════════════════════════════════════════════════╗\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    
    cout << "Welcome to the C++ Sets Interactive Learning Program!\n";
    cout << "This program will teach you everything about sets in C++.\n";
    pauseScreen();
    
    do {
        clearScreen();
        displayMainMenu();
        cin >> choice;
        
        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input! Please enter a number.\n";
            pauseScreen();
            continue;
        }
        
        switch (choice) {
            case 1:
                level1_BasicSetOperations();
                break;
                
            case 2:
                level2_IteratorsAndTraversal();
                break;
                
            case 3:
                level3_SetAlgorithms();
                break;
                
            case 4:
                level4_CustomComparators();
                break;
                
            case 5:
                level5_SetVsUnorderedSet();
                break;
                
            case 6:
                level6_RealWorldApplications();
                break;
                
            case 0:
                clearScreen();
                cout << "\n╔════════════════════════════════════════════════════════╗\n";
                cout << "║    Thank you for using the C++ Sets Learning Program!  ║\n";
                cout << "║           Keep practicing and happy coding! 🚀         ║\n";
                cout << "╚════════════════════════════════════════════════════════╝\n\n";
                break;
                
            default:
                cout << "\nInvalid choice! Please select 0-6.\n";
                pauseScreen();
        }
        
    } while (choice != 0);
    
    return 0;
}