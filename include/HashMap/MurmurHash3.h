#ifndef MURMURHASH_H
#define MURMURHASH_H

#include <cstdint>
#include <cstddef>
#include <string>

// Rotate Left (32-bit)
inline uint32_t rotl32(uint32_t value, int shift)
{
    return (value << shift) | (value >> (32 - shift));
}

// MurmurHash3 (32-bit)
inline uint32_t murmurHash3(const unsigned char* data, size_t length)
{
    uint32_t hash = 0;

    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    size_t remaining = length;

    // Process 4 bytes at a time
    while (remaining >= 4)
    {
        uint32_t k = *(const uint32_t*)data;

        k *= c1;
        k = rotl32(k, 15);
        k *= c2;

        hash ^= k;
        hash = rotl32(hash, 13);
        hash = hash * 5 + 0xe6546b64;

        data += 4;
        remaining -= 4;
    }

    // Handle remaining 1-3 bytes
    uint32_t k = 0;

    switch (remaining)
    {
        case 3:
            k ^= (uint32_t)data[2] << 16;
        case 2:
            k ^= (uint32_t)data[1] << 8;
        case 1:
            k ^= (uint32_t)data[0];
            k *= c1;
            k = rotl32(k, 15);
            k *= c2;
            hash ^= k;
    }

    // Finalization
    hash ^= (uint32_t)length;

    hash ^= hash >> 16;
    hash *= 0x85ebca6b;

    hash ^= hash >> 13;
    hash *= 0xc2b2ae35;

    hash ^= hash >> 16;

    return hash;
}

// Generic hash (works for int, char, float, double, etc.)
template<typename T>
inline size_t getHash(const T& key)
{
    return murmurHash3(
        reinterpret_cast<const unsigned char*>(&key),
        sizeof(T)
    );
}

// Specialization for std::string
template<>
inline size_t getHash<std::string>(const std::string& key)
{
    return murmurHash3(
        reinterpret_cast<const unsigned char*>(key.data()),
        key.size()
    );
}

#endif