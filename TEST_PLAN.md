# Test Plan for rosterllist Class

---

## Test Components

### 1. Scripted I/O Test
**Purpose:** Test basic operations with file input

**Implementation:**
- If a filename is provided as command line argument, redirect stdin to that file
- Call `testRoster()` to process commands
- Commands: `A <id> <first> <last>` (Add), `X <id>` (Erase), `L` (List)

**Expected:** Program output shows correct roster state after each operation

---

### 2. Dynamic Growth Test
**Purpose:** Verify linked list can grow without capacity limits

**Implementation:**
- Insert 100 persons programmatically
- Count elements using iterator
- Print count

**Expected:** Count = 100

---

### 3. Deletion Test
**Purpose:** Verify erase() removes nodes correctly

**Implementation:**
- Erase 3 persons from different positions (head, middle, tail)
- Recount elements using iterator
- Print count

**Expected:** Count = 97 (100 - 3)

---

### 4. Edge Cases Test
**Purpose:** Verify robustness with boundary conditions

**Implementation:**
- Erase from empty list (should not crash)
- Insert single element, then erase it
- Print pass message

**Expected:** No crashes, good handling

---

## Main Function Structure

```cpp
int main(int argc, char **argv) {
    // 1) I/O test (if there's a file)
    if (argc > 1) {
        // Redirect cin to file and call testRoster()
    }
    // 2) Insert 100 persons and count
    // 3) Erase 3 persons and recount
    // 4) Test edge cases
    
    return EXIT_SUCCESS;
}
```

---