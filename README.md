# RosterLinkedList

A C++ implementation of a student roster using a singly-linked list data structure.

## Overview

This project implements a dynamic linked list for managing student records (Person objects) without the capacity limitations of array-based implementations. It demonstrates:

- **Dynamic memory management** with proper allocation and deallocation
- **C++ iterator pattern** for traversing the list
- **Error handling** for allocation failures
- **Modern C++ features** (C++20 standard)

## Features

✅ **Node class** - Linked list nodes with constructor and destructor  
✅ **Iterator class** - Full iterator support with `!=`, `*`, and `++` operators  
✅ **RosterLList class** - Main container with insert, erase, begin, end methods  
✅ **No capacity limit** - Grows dynamically as needed  
✅ **Memory safety** - Proper cleanup in destructor to prevent leaks  
✅ **Comprehensive tests** - Validates all functionality including edge cases

## Project Structure

```
.
├── person.h              # Person class definition (Plain Old Data)
├── roster.h              # Base Roster class (array-based)
├── roster.cxx            # Base Roster implementation
├── rosterllist.h         # RosterLList class declaration (linked list)
├── rosterllist.cxx       # RosterLList implementation (YOUR WORK)
├── rostertest.cxx        # testRoster() implementation
├── rosterllistmain.cxx   # Main test program
├── Makefile              # Build configuration
├── TEST_PLAN.md          # Comprehensive test plan
└── test_input.txt        # Sample input for scripted tests
```

## Building

Compile using the provided Makefile:

```bash
make
```

Clean build artifacts:

```bash
make clean
```

## Running

**Without input file (programmatic tests only):**
```bash
./rosterllisttest
```

**With scripted input file:**
```bash
./rosterllisttest test_input.txt
```

## Expected Output

```
[TEST] count after inserts: 100
[TEST] count after erases: 97
[TEST] edge cases: PASSED
```

## Input File Format

Commands for scripted testing:
- `A <id> <firstname> <lastname>` - Add a person
- `X <id>` - Erase a person by ID
- `L` - List all persons

Example:
```
A 10000001 John Doe
A 10000002 Jane Smith
L
X 10000001
L
```

## Implementation Details

### Node Class
- Stores Person data and pointer to next node
- Constructor initializes `next` to nullptr
- Destructor is empty (RosterLList handles node deletion)

### Iterator Class
- Wraps a Node pointer for traversal
- Supports `!=` for comparison, `*` for dereferencing, `++` for advancement
- Enables range-based for loops

### RosterLList Class
- **insert()** - Adds new node at head (O(1))
- **erase()** - Removes node by ID (O(n))
- **begin()** - Returns iterator to head
- **end()** - Returns iterator to nullptr
- **Destructor** - Deletes all nodes to prevent memory leaks

## Memory Management

All nodes are dynamically allocated using `new` and deallocated using `delete`. The destructor ensures all nodes are properly freed:

```cpp
RosterLList::~RosterLList() {
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}
```

## Testing

The test suite validates:
1. **Dynamic growth** - Insert 100 elements
2. **Deletion** - Remove from head, middle, and tail
3. **Edge cases** - Empty list, single element
4. **Iterator** - Correct traversal and counting

Check for memory leaks (if valgrind is installed):
```bash
valgrind --leak-check=full ./rosterllisttest
```

## Requirements

- C++20 compatible compiler (g++, clang++)
- Make build system

## Course Information

CSEN 79 - Lab 6  
Santa Clara University

## License

Academic project - for educational purposes only

