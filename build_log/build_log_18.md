# Build Log 02

**Date:** 9 July 2026 (Evening)  
**Duration:** 3 hours

## Goal

Support generic key and value types inside `RedisLite` while correctly handling both primitive and string values.

## Problem Encountered

After switching to `std::getline()`, every extracted token became a `std::string`.

However, `RedisLite` is a template class.

The parsed strings now had to be converted into the generic types:

```cpp
K
V
```

Initially, I was unsure how to convert a string into an arbitrary template type.

After solving this problem, another issue appeared.

Using `std::stringstream >>` for conversion behaved exactly like `std::cin`.

For example:

```text
SET 10 Hello World
```

The entire value was correctly stored inside the temporary string.

However,

```cpp
stringstream >> value;
```

only extracted:

```text
Hello
```

and ignored:

```text
World
```

This made string values behave incorrectly.

## What I Tried

I implemented a generic conversion function using `std::stringstream`.

```cpp
template<typename T>
T converter(const std::string& str)
```

The converter:

- creates a string stream
- extracts the required type using `>>`
- throws an exception if conversion fails

This worked correctly for primitive types such as:

- int
- float
- double

While testing with `std::string`, I observed that extraction stops at the first whitespace.

To solve this, I added a template specialization.

```cpp
template<>
std::string converter<std::string>(const std::string& str)
{
    return str;
}
```

Instead of extracting a word, it simply returns the complete string unchanged.

I also added validation for:

- missing key
- missing value
- unnecessary parameters
- invalid type conversions

## Outcome

Completed the first generic implementation of the Redis command parser.

Major learnings:

- generic type conversion using templates
- `std::stringstream` extraction behavior
- template specialization
- handling primitive and non-primitive types differently
- validating user input before executing commands