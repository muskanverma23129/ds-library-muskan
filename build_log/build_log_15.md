# Build Log 01

**Date:** 8 July 2026  
**Duration:** 5.5 hours

## Goal

Implement the first working version of `HashMap` using separate chaining with linked lists and support insertion, retrieval, resizing, and collision handling.

## Problem Encountered

I first implemented `HashMap` only for `int` keys and `string` values.

While implementing `set()`, I noticed something unexpected.

Inside `set()`, I created a temporary `Pair` object and passed it to `LinkList::insertBack()`.

When the linked-list node was created, another `Pair` object was constructed inside the node.

Initially, I thought two `Pair` objects were permanently stored, indicating unnecessary duplication.

This confused me because I expected only one object to exist.

## What I Tried

I implemented the initial `HashMap` using:

- `DynamicArray<LinkList<Pair>>`
- integer keys
- string values
- division hashing

I implemented:

- `set()`
- `get()`
- `reHash()`

During insertion, I traced the complete object lifetime.

The sequence was:

1. `set()` creates a temporary `Pair` object on the stack.
2. The temporary object is passed by reference to `insertBack()`.
3. `insertBack()` allocates memory for a new node.
4. The node constructor copy-constructs a new `Pair` object inside heap memory.
5. The temporary `Pair` object created in `set()` is destroyed when the function returns.

This helped me understand that only one `Pair` object remains inside the linked list, while the temporary object exists only during insertion.

After understanding this behavior, I completed:

- `print()`
- `reHash()`
- `find()`
- `remove()`
- `exist()`

## Outcome

Completed the first working version of `HashMap` for integer keys.

Major learnings:

- lifetime of temporary objects
- object construction inside linked-list nodes
- stack vs heap object lifetime
- collision handling using separate chaining
- automatic resizing using load factor