#ifndef OPERATORS_H
#define OPERATORS_H

#include <string>
#include <boost/spirit/include/qi_parse.hpp>
#include <boost/spirit/include/qi_numeric.hpp>

#include "types.h"
#include "bytebuffer.h"
#include "value.h"

class UnaryOperator
{
public:
    virtual ~UnaryOperator() {}
    virtual std::unique_ptr<Value> operation(const ByteBuffer &value) = 0;
    virtual std::unique_ptr<Value> operation(const ViewByteBuffer &value) = 0;
};

template<typename T>
class FromStringCast: public UnaryOperator
{
public:
    std::unique_ptr<Value> operation(const ByteBuffer &value) override
    {
        throw;
    }
    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
    {
        throw;
    }
};

template<>
class FromStringCast<Int8Type>: public UnaryOperator
{
public:
    std::unique_ptr<Value> operation(const ByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        int8_t cast_value = static_cast<int8_t>(std::stoi(str));

        return std::make_unique<TypedValue<Int8Type>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(int8_t))));
    }
    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        int8_t cast_value = static_cast<int8_t>(std::stoi(str));

        return std::make_unique<TypedValue<Int8Type>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(int8_t))));
    }
};

template<>
class FromStringCast<Int16Type>: public UnaryOperator
{
public:
    std::unique_ptr<Value> operation(const ByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        int16_t cast_value = static_cast<int16_t>(std::stoi(str));

        return std::make_unique<TypedValue<Int16Type>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(int16_t))));
    }
    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        int16_t cast_value = static_cast<int16_t>(std::stoi(str));

        return std::make_unique<TypedValue<Int16Type>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(int16_t))));
    }
};

template<>
class FromStringCast<Int32Type>: public UnaryOperator
{
public:
    std::unique_ptr<Value> operation(const ByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        int32_t cast_value = std::stoi(str);

        return std::make_unique<TypedValue<Int32Type>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(int32_t))));
    }
    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        int32_t cast_value = std::stoi(str);

        return std::make_unique<TypedValue<Int32Type>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(int32_t))));
    }
};

template<>
class FromStringCast<Int64Type>: public UnaryOperator
{
public:
    std::unique_ptr<Value> operation(const ByteBuffer &value) override
    {
        std::experimental::string_view str(value._data, value._size);
        int64_t cast_value = 0;
        boost::spirit::qi::parse(str.begin(), str.end(), boost::spirit::qi::long_, cast_value);

        return std::make_unique<TypedValue<Int64Type>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(int64_t))));
    }
    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
    {
        std::experimental::string_view str(value._data, value._size);
        int64_t cast_value = 0;
        boost::spirit::qi::parse(str.begin(), str.end(), boost::spirit::qi::long_, cast_value);

        return std::make_unique<TypedValue<Int64Type>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(int64_t))));
    }
};

template<>
class FromStringCast<FloatType>: public UnaryOperator
{
public:
    std::unique_ptr<Value> operation(const ByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        float cast_value = std::stof(str);

        return std::make_unique<TypedValue<FloatType>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(float))));
    }
    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        float cast_value = std::stof(str);

        return std::make_unique<TypedValue<FloatType>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(float))));
    }
};

template<>
class FromStringCast<DoubleType>: public UnaryOperator
{
public:
    std::unique_ptr<Value> operation(const ByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        double cast_value = std::stod(str);

        return std::make_unique<TypedValue<DoubleType>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(double))));
    }
    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
    {
        std::string str(value._data, value._size);
        double cast_value = std::stod(str);

        return std::make_unique<TypedValue<DoubleType>>(std::move(ByteBuffer(reinterpret_cast<char*>(&cast_value), sizeof(double))));
    }
};

template<>
class FromStringCast<StringType>: public UnaryOperator
{
public:
    std::unique_ptr<Value> operation(const ByteBuffer &value) override
    {
        return std::make_unique<TypedValue<StringType>>(std::move(ByteBuffer(value._data, value._size)));
    }
    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
    {
        return std::make_unique<TypedValue<StringType>>(std::move(ByteBuffer(value._data, value._size)));
    }
};

//template<typename T>
//class ToStringCast: public UnaryOperator
//{
//public:
//    std::unique_ptr<Value> operation(const ByteBuffer &value) override
//    {
//        throw;
//    }
//    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
//    {
//        throw;
//    }
//};
//
//template<>
//class ToStringCast<Int8Type>: public UnaryOperator
//{
//public:
//    std::unique_ptr<Value> operation(const ByteBuffer &value) override
//    {
//        int8_t cast_value = *reinterpret_cast<int8_t*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<Int8Type>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
//    {
//        int8_t cast_value = *reinterpret_cast<int8_t*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<Int8Type>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//};

//template<>
//class ToStringCast<Int16Type>: public UnaryOperator
//{
//public:
//    std::unique_ptr<Value> operation(const ByteBuffer &value) override
//    {
//        int16_t cast_value = *reinterpret_cast<int16_t*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<Int16Type>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
//    {
//        int16_t cast_value = *reinterpret_cast<int16_t*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<Int16Type>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//};

//template<>
//class ToStringCast<Int32Type>: public UnaryOperator
//{
//public:
//    std::unique_ptr<Value> operation(const ByteBuffer &value) override
//    {
//        int32_t cast_value = *reinterpret_cast<int32_t*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<Int32Type>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
//    {
//        int32_t cast_value = *reinterpret_cast<int32_t*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<Int32Type>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//};

//template<>
//class ToStringCast<Int64Type>: public UnaryOperator
//{
//public:
//    std::unique_ptr<Value> operation(const ByteBuffer &value) override
//    {
//        int64_t cast_value = *reinterpret_cast<int64_t*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<Int64Type>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
//    {
//        int64_t cast_value = *reinterpret_cast<int64_t*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<Int64Type>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//};

//template<>
//class ToStringCast<FloatType>: public UnaryOperator
//{
//public:
//    std::unique_ptr<Value> operation(const ByteBuffer &value) override
//    {
//        float cast_value = *reinterpret_cast<float*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<FloatType>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
//    {
//        float cast_value = *reinterpret_cast<float*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<FloatType>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//};

//template<>
//class ToStringCast<DoubleType>: public UnaryOperator
//{
//public:
//    std::unique_ptr<Value> operation(const ByteBuffer &value) override
//    {
//        double cast_value = *reinterpret_cast<double*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<DoubleType>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
//    {
//        double cast_value = *reinterpret_cast<double*>(value._data);
//        std::string str = std::to_string(cast_value);

//        return std::make_unique<TypedValue<DoubleType>>(std::move(ByteBuffer(str.size(), str.data())));
//    }
//};

//template<>
//class ToStringCast<StringType>: public UnaryOperator
//{
//public:
//    std::unique_ptr<Value> operation(const ByteBuffer &value) override
//    {
//        return std::make_unique<TypedValue<StringType>>(std::move(value));
//    }
//    std::unique_ptr<Value> operation(const ViewByteBuffer &value) override
//    {
//        return std::make_unique<TypedValue<StringType>>(std::move(ByteBuffer(value)));
//    }
//};

#endif // OPERATORS_H
