## Build Log Entry 1

**Date:** June 30,2026
**Duration:** 1.5 hours

**Goal:**
Implement Rule of Three in `DynamicArray` by adding:

* Copy Constructor
* Copy Assignment Operator
* Destructor

**Problem Encountered:**
No major conceptual issue. I already understood how copy constructor and assignment operator work, but I needed to integrate them correctly into my dynamic array implementation.

**What I Tried:**
I implemented:

* Destructor for freeing heap memory.
* Copy constructor for creating a deep copy of the internal array.
* Assignment operator for replacing old memory safely and copying new values.

I tested by copying one `DynamicArray` into another and modifying one instance to verify they worked independently.

**Outcome:**
The implementation worked correctly. My dynamic array now supports proper deep copying and avoids shared memory issues between copied objects.
