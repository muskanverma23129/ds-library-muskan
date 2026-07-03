## Build Log Entry — DynamicArray Memory Design and Core Methods

**Date:** June 29, 2026
**Duration:** 4 hours

**Goal:**
Design the memory model of `DynamicArray` and implement its core methods.

**Problem Encountered:**
Coming from Java, I believed objects are always stored in heap memory. While designing the dynamic array, I realized that in C++, objects can also be stored on the stack depending on how they are created.

This changed how I thought about the structure.

**What I Tried:**
I designed the `DynamicArray` so:

* The `DynamicArray` object itself is stored on the stack.
* The internal array is allocated on the heap.
* The pointer to the heap array is stored inside the stack object.

After finalizing this memory model, I implemented:

* Constructor
* Destructor
* `append()`
* `insert()`
* `remove()`
* `get()`
* `getSize()`
* `getCapacity()`
* `regrow()`
* `shrink()`

I tested insertion, deletion, resizing, and element access.

**Outcome:**
The dynamic array worked correctly. I gained a better understanding of stack vs heap memory, object lifetime, and how dynamic memory is managed inside a container implementation.
