# Data Structures & Algorithms Practice Repository

## 📋 Overview

This repository focuses on **data structures and algorithms** concepts that require in-depth understanding and extensive practice. These topics extend beyond basic C++ fundamentals and are essential for technical interviews and advanced programming.

## 🎯 Purpose

While solidifying C++ fundamentals in my [main C++ practice repository](https://github.com/fares-boulahmi/cpp-practice-for-masterclass.git), I identified critical DSA concepts from MIT courses that needed deeper exploration. This repository provides:
- Comprehensive tutorials for complex data structures
- Structured problem-solving practice
- Progressive difficulty challenges
- Multi-source learning approach for thorough understanding

## 📁 Repository Structure

```
.
├── LinkedList/
│   ├── cpp-practice-with-challenge/
│   │   ├── tutorial/              # Core implementations & explanations
│   │   ├── tutorial-challenge/    # 3 problems per concept (2 easy, 1 medium)
│   │   └── problemPractice/       # 8 progressive problems
│   └── LinkedListFCC/             # freeCodeCamp supplementary practice
│
├── Trees/
│   ├── cpp-practice-with-challenge/
│   │   ├── tutorial/
│   │   ├── tutorial-challenge/
│   │   └── problemPractice/
│   └── TreesFCC/
│
├── Graphs/
│   ├── cpp-practice-with-challenge/
│   │   ├── tutorial/
│   │   ├── tutorial-challenge/
│   │   └── problemPractice/
│   └── GraphsFCC/
│
└── Sets/
    ├── cpp-practice-with-challenge/
        ├── tutorial/
        ├── tutorial-challenge/
        └── problemPractice/
```

## 🏗️ Practice Structure

### Each Concept Follows This Pattern:

#### 1. **Tutorial** (`tutorial/`)
- Detailed concept explanations
- Core implementations from scratch
- Code comments and complexity analysis
- Key operations and use cases

#### 2. **Tutorial Challenge** (`tutorial-challenge/`)
For **each concept** in the tutorial:
- **2 Easy problems** - Direct application
- **1 Medium problem** - Combined scenarios

#### 3. **Problem Practice** (`problemPractice/`)
- **8 Progressive problems**
- Difficulty increases incrementally
- Combines multiple concepts
- Interview-level complexity

### 🔧 Running Solutions

Both `tutorial-challenge` and `problemPractice` use the same execution system:

```bash
# Build and run
build-cpp

# Select from interactive menu
rooster
```

The interactive terminal menu lets you choose which problem to solve and test.

## 📚 Learning Sources

### Primary Source (MIT OpenCourseWare)
1. [Introduction to Algorithms (MIT 6.006)](https://www.youtube.com/playlist?list=PLUl4u3cNGP63EdVPNLG3ToM6LaEUuStEY)
2. [Design and Analysis of Algorithms (MIT 6.046J)](https://www.youtube.com/playlist?list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)
3. [Advanced Data Structures (MIT 6.851)](https://www.youtube.com/playlist?list=PLUl4u3cNGP63VIBQVWguXxZZi0566y7Wf)

### Supplementary Resources

When MIT lectures need clarification, I dive deeper using:

#### Main Supplementary Channels
- **[freeCodeCamp.org](https://www.youtube.com/@freecodecamp)** - Comprehensive tutorials with practice
- **[Hussein Nasser](https://www.youtube.com/@hnasr)** - Deep technical breakdowns

#### Concept-Specific Resources
- **Linked Lists**: [Linked Lists for Technical Interviews](https://www.youtube.com/watch?v=Hj_rA0dhr2I)
- *(Additional resources added as needed)*

### Multi-Language Practice

When supplementary sources provide practice in other languages:
- Complete those exercises in their original language
- Store in dedicated folders (e.g., `LinkedListFCC/`)
- Re-implement key concepts in C++ within `cpp-practice-with-challenge/`

## 🎓 Data Structures Covered

- **Linked Lists** - Singly, doubly, circular, applications
- **Trees** - Binary trees, BST, AVL, heaps, traversals
- **Graphs** - Representations, DFS, BFS, shortest paths, MST
- **Sets** - Hash sets, tree sets, operations
- **Hash Tables** *(planned)*
- **Heaps & Priority Queues** *(planned)*
- **Advanced Structures** *(from MIT 6.851)*

## 🚀 Getting Started

### Prerequisites
```bash
# C++ Compiler (C++20 support)
g++ --version  # or clang++

# Build tools
# rooster (custom build system)
```

### Compilation Example
```bash
# Standard compilation
g++ -std=c++20 -o output filename.cpp

# With debugging
g++ -std=c++20 -g -Wall -Wextra -o output filename.cpp
```

## 💡 Learning Workflow

1. **Learn** - Watch MIT lectures on the concept
2. **Supplement** - If unclear, study from freeCodeCamp or Hussein Nasser
3. **Practice (Other Languages)** - Complete exercises from supplementary sources
4. **Implement Tutorial** - Code concept from scratch in C++
5. **Tutorial Challenge** - Solve 3 problems per concept (2 easy, 1 medium)
6. **Problem Practice** - Tackle 8 progressive problems
7. **Review** - Optimize and analyze solutions

## 📊 Progress Tracking

### Linked Lists
- [ ] Tutorial implementations
- [ ] Tutorial challenges (per concept)
- [ ] Problem Practice (8 problems)
- [ ] freeCodeCamp supplementary exercises

### Trees
- [ ] Tutorial implementations
- [ ] Tutorial challenges
- [ ] Problem Practice

### Graphs
- [ ] Tutorial implementations
- [ ] Tutorial challenges
- [ ] Problem Practice

### Sets
- [ ] Tutorial implementations
- [ ] Tutorial challenges
- [ ] Problem Practice

### Etc...

## 🔗 Related Repository

**[C++ Practice for Masterclass](https://github.com/fares-boulahmi/cpp-practice-for-masterclass.git)** - Fundamental C++ concepts practice (Chapters 4-19) from 31-hour course with 4 problems per chapter.

## 📖 Additional Resources

- [C++ Reference](https://en.cppreference.com/)
- [MIT OpenCourseWare](https://ocw.mit.edu/)
- [LeetCode](https://leetcode.com/)
- [GeeksforGeeks](https://www.geeksforgeeks.org/)
- [Visualgo](https://visualgo.net/) - Algorithm visualizations

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

**Status**: 🚧 Active Development | **Focus**: Deep DSA understanding through MIT + supplementary sources


