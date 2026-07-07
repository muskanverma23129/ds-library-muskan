## Build Log – Session 2

**Date:** July 6, 2026

**Duration:** 1 Hour 30 Minutes

### Goal

Complete the core deletion operations of the LinkedList and verify that memory was released correctly.

### Problem Encountered

No major issues were encountered during implementation. The main focus was correctly updating pointers after deleting nodes from different positions in the list.

### What I Tried

I implemented the deletion operations while considering different scenarios, including deleting from an empty list, deleting the only node, and deleting from a list containing multiple nodes.

The following methods were completed:

- `deleteFront()`
- `deleteBack()`

After implementing each method, I verified that dynamically allocated memory was released correctly and that the `head`, `tail`, and `size` members reflected the current state of the LinkedList.

### Outcome

The LinkedList supported both insertion and deletion operations successfully. With the core functionality complete, the data structure was ready for implementing the remaining utility methods.