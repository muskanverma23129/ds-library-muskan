# Build Log 02

**Date:** 8 July 2026  
**Duration:** 4.5 hours

## Goal

Convert the integer-specific `HashMap` into a generic template implementation and improve its internal design.

## Problem Encountered

After completing the integer implementation, I generalized the class using templates.

While reviewing the class design, I initially believed `HashMap` also required its own Rule of Three because it stores dynamic containers.

However, while examining destruction and copying, I realized that `HashMap` itself never directly allocates heap memory.

The actual ownership belongs to:

- `DynamicArray`
- `LinkList`

Both already implement correct resource management.

## What I Tried

I converted the implementation into:

```cpp
template<typename K, typename V>
```

making the container generic.

While reviewing destruction, I observed:

When a `HashMap` object is destroyed,

- the compiler-generated destructor is called,
- which automatically destroys the member `DynamicArray`,
- the `DynamicArray` destructor releases its heap memory,
- each stored `LinkList` is destroyed,
- every linked-list node is released,
- each stored `Pair` object is destroyed automatically.

I made similar observations for copying.

Since `DynamicArray` already implements deep copying, the compiler-generated copy constructor and assignment operator correctly copy the `HashMap`.

Because `HashMap` owns no raw heap memory itself, I removed the manually written Rule of Three.

Finally, I replaced the simple division hash function with MurmurHash to improve key distribution and reduce clustering.

## Outcome

The `HashMap` became:

- generic
- simpler
- easier to maintain
- correctly managed through composition

Major learnings:

- ownership determines whether Rule of Three is required
- member objects automatically manage their own destruction
- compiler-generated special member functions are sufficient when no raw resources are owned
- MurmurHash provides significantly better key distribution than simple modulo hashing