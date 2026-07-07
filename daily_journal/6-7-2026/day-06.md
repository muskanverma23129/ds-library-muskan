# Day 1 Journal
**Date:** July 6, 2026

---

# Section 1 – Specific Bug

No major compiler errors or runtime issues were encountered during today's implementation. The implementation progressed as planned, and the methods worked correctly after routine verification. Only minor syntax corrections were made during coding, which were resolved immediately.

---

# Section 2 – Failed Attempt

There was no significant failed implementation today. Before implementing each operation, I planned how the `head`, `tail`, and `size` members should change in different scenarios such as an empty list, a single-node list, and a multi-node list. This approach helped me avoid logical mistakes during implementation.

---

# Section 3 – Memory Diagram

**(Hand-drawn memory diagram attached separately.)**

The memory diagram contains:

- Empty LinkedList
- `insertFront()`
- `insertBack()`
- `insert(index)`
- `deleteFront()`
- `deleteBack()`
- Pointer updates for `head` and `tail`

---

# Section 4 – Code Reference

### Final Commit Hash

`1647095557cce74047606ecbb082732a142b37c2`

### Development Commits

| Commit | Description |
|---------|-------------|
| 59595809eac93ecb354b710e2e65914d849e493d | Constructor and `insertFront()` |
| 2e39b6d2b6027410c9c3490b4ff6e53dc4c647f1 | `insertBack()` |
| 57f5419ef407e1343cd0186e4a96deb77f3f96ea | `insert(index)` |
| 1647095557cce74047606ecbb082732a142b37c2 | `deleteFront()` and `deleteBack()` |

### Files

- LinkList.h
- LinkList.cpp

### Approximate Line Numbers (LinkList.cpp)

| Function | Approx. Lines |
|----------|---------------|
| Constructor | 5–6 |
| Destructor | 7–19 |
| insertFront() | 44–64 |
| insertBack() | 66–86 |
| insert() | 88–119 |
| deleteFront() | 121–143 |
| deleteBack() | 145–169 |

---

# Section 5 – Learning Reflection

Today's implementation strengthened my understanding of dynamic memory management in a singly linked list. I became more confident in updating `head`, `tail`, and `size` correctly after insertion and deletion operations. Implementing front and back insertion and deletion also reinforced how pointer updates differ between empty lists, single-node lists, and larger lists. Planning the pointer changes before writing the code helped me complete the implementation without significant issues.