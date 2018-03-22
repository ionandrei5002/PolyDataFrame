#ifndef VALUE_H
#define VALUE_H

#include <memory>
#include <string>

#include <boost/spirit/include/qi_parse.hpp>
#include <boost/spirit/include/qi_numeric.hpp>

#include "types.h"
#include "bytebuffer.h"
#include "array.h"

class Value
{
public:
    virtual ~Value() {}
    virtual std::unique_ptr<Value> get() = 0;
    virtual void set(std::unique_ptr<Value>& value) = 0;
    virtual std::unique_ptr<Value> unpack(const Array& row, uint64_t& offset) = 0;
    virtual ByteBuffer pack() = 0;
    virtual void print(std::ostream& out) = 0;
};

template<typename T>
class TypedValue: public Value
{
private:
    uint64_t _type_size = sizeof(typename T::c_type);
    ByteBuffer _value;
public:
    explicit TypedValue(const TypedValue<T>& value)
    {
        this->_value = value._value;
    }
    TypedValue(const ByteBuffer& value)
    {
        this->_value = value;
    }
    std::unique_ptr<Value> get() override
    {
        return std::make_unique<TypedValue<T>>(*this);
    }
    void set(std::unique_ptr<Value>& value) override
    {
        this->_value = static_cast<TypedValue<T>*>(value.get())->_value;
    }
    std::unique_ptr<Value> unpack(const Array& row, uint64_t& offset) override
    {
        ViewByteBuffer view(&row._data[offset], _type_size);

        offset += _type_size;

        return std::make_unique<TypedValue<T>>(view);
    }
    ByteBuffer pack() override
    {
        return this->_value;
    }
    void print(std::ostream& out) override
    {
        typedef typename T::c_type _type;
        out << *reinterpret_cast<_type*>(_value._data);
    }
};

#endif // VALUE_H
