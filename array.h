#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <memory.h>
#include <vector>

#include "bytebuffer.h"

class Array
{
public:
    char* _data = nullptr;
    uint64_t _capacity = 0;
    uint64_t _size = 0;
public:
    Array(uint64_t capacity)
    {
        _data = new char[capacity];
        _capacity = capacity;
        _size = 0;
    }
    Array(const Array& ot)
    {
        _size = ot._size;
        _data = new char[ot._size];
        memcpy(_data, ot._data, ot._size);
    }
    Array& operator=(const Array& ot)
    {
        _size = ot._size;
        _data = new char[ot._size];
        memcpy(_data, ot._data, ot._size);
        return *this;
    }
    Array(Array&& ot)
    {
        _size = ot._size;
        _data = ot._data;
        ot._data = nullptr;
    }
    Array& operator=(Array&& ot)
    {
        _size = ot._size;
        _data = ot._data;
        ot._data = nullptr;
        return *this;
    }
    inline void emplace_back(const char* data, uint64_t size)
    {
        memcpy(&_data[_size], data, size);
        _size += size;
    }
    inline void emplace_back(const ByteBuffer& data)
    {
        memcpy(&_data[_size], data._data, data._size);
        _size += data._size;
    }
    inline char* get(uint64_t offset)
    {
        return &_data[offset];
    }
    inline uint64_t size()
    {
        return _size;
    }
    inline uint64_t capacity()
    {
        return _capacity;
    }
    ~Array()
    {
        delete[] _data;
        _data = nullptr;
        _capacity = 0;
        _size = 0;
    }
};

#endif // ARRAY_H
