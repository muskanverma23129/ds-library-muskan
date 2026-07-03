## Build Log 01

**Date:** 30 June 2026
**Duration:** 3 hours

**Goal:**
Revise the original `DynamicArray` memory model during implementation and redraw operation-level memory diagrams to match actual object lifecycle behavior.

**Problem Encountered:**
While implementing `DynamicArray`, I realized my original design proposal had an incorrect memory model.

In the original proposal, I had placed the `DynamicArray` object itself on the heap and only focused on raw allocation.

During implementation, I learned that:

* the container object can exist on the stack
* only its internal storage should be dynamically allocated
* object lifecycle becomes important during reallocation

My earlier diagrams did not consider:

* constructor calls for object types
* destructor calls during deletion
* copy behavior during regrow
* how shifting works for objects during insert

This made the original memory diagrams incomplete.

**What I Tried:**

I revisited and redrew memory diagrams for:

### Constructor

I corrected the model to:

* `DynamicArray` object lives on stack
* `arr` points to heap memory
* `size` and `capacity` stored inside stack object

For primitive types:

* direct value storage inside heap block

For non-primitive types:

* object slots stored in heap
* each object maintains its own lifecycle

For `string`:

* array stores string objects
* string objects internally own character buffers

For `Student`:

* object fields stored inside each slot with possible nested ownership

---

### Append

I redrew append behavior to include:

Best case:

* place element in free slot

Worst case:

* allocate new block
* construct/copy old objects into new block
* destroy old objects
* free old memory

This helped me understand reallocation lifecycle.

---

### Insert

I redrew insertion for:

Best case:

* insert at end

Average case:

* shift half elements

Worst case:

* shift all elements from front

I tracked how object movement works during shifting and how assignments affect existing objects.

---

I also updated complexity diagrams for:

* constructor
* append
* insert

Including:

* Best case
* Average case
* Worst case

After understanding this, I updated my design proposal to reflect:

* corrected stack/heap ownership
* object lifecycle during regrow
* proper object movement
* primitive vs object storage representation
* nested ownership for strings

**Outcome:**
My design proposal now matches the actual implementation model.

Major understanding gained:

* stack object vs heap internal storage
* reallocation is not just memory copy for objects
* object construction/destruction matters during resize
* shifting objects during insert affects lifecycle
* primitive and object storage behave differently in generic containers

This redesign fixed major flaws in my original proposal and gave me a correct implementation blueprint.
