#ifndef TYPES_H
#define TYPES_H

#include <memory>
#include <string>

struct Type
{
    enum type
    {
        UINT8 = 0,
        INT8 = 1,
        UINT16 = 2,
        INT16 = 3,
        UINT32 = 4,
        INT32 = 5,
        UINT64 = 6,
        INT64 = 7,
        FLOAT = 8,
        DOUBLE = 9,
        STRING = 10
    };
};

template<int TYPE>
struct type_traits
{};


template<>
struct type_traits<Type::UINT8>
{
    typedef uint8_t value_type;
    static constexpr char* name = const_cast<char*>("UINT8");
    static constexpr int value_byte_size = 1;
};

template<>
struct type_traits<Type::INT8>
{
    typedef int8_t value_type;
    static constexpr char* name = const_cast<char*>("INT8");
    static constexpr int value_byte_size = 1;
};

template<>
struct type_traits<Type::UINT16>
{
    typedef uint16_t value_type;
    static constexpr char* name = const_cast<char*>("UINT16");
    static constexpr int value_byte_size = 2;
};

template<>
struct type_traits<Type::INT16>
{
    typedef int16_t value_type;
    static constexpr char* name = const_cast<char*>("INT16");
    static constexpr int value_byte_size = 2;
};

template<>
struct type_traits<Type::UINT32>
{
    typedef uint32_t value_type;
    static constexpr char* name = const_cast<char*>("UINT32");
    static constexpr int value_byte_size = 4;
};

template<>
struct type_traits<Type::INT32>
{
    typedef int32_t value_type;
    static constexpr char* name = const_cast<char*>("INT32");
    static constexpr int value_byte_size = 4;
};

template<>
struct type_traits<Type::UINT64>
{
    typedef uint64_t value_type;
    static constexpr char* name = const_cast<char*>("UINT64");
    static constexpr int value_byte_size = 8;
};

template<>
struct type_traits<Type::INT64>
{
    typedef int64_t value_type;
    static constexpr char* name = const_cast<char*>("INT64");
    static constexpr int value_byte_size = 8;
};

template<>
struct type_traits<Type::FLOAT>
{
    typedef float value_type;
    static constexpr char* name = const_cast<char*>("FLOAT");
    static constexpr int value_byte_size = 4;
};

template<>
struct type_traits<Type::DOUBLE>
{
    typedef double value_type;
    static constexpr char* name = const_cast<char*>("DOUBLE");
    static constexpr int value_byte_size = 8;
};

template<>
struct type_traits<Type::STRING>
{
    typedef std::string value_type;
    static constexpr char* name = const_cast<char*>("STRING");
    static constexpr int value_byte_size = sizeof(std::string);
};

template<Type::type TYPE>
struct DataType
{
    static constexpr Type::type type_num = TYPE;
    static constexpr char* name = type_traits<TYPE>::name;
    typedef typename type_traits<TYPE>::value_type c_type;
};

typedef DataType<Type::UINT8> UInt8Type;
typedef DataType<Type::INT8> Int8Type;
typedef DataType<Type::UINT16> UInt16Type;
typedef DataType<Type::INT16> Int16Type;
typedef DataType<Type::UINT32> UInt32Type;
typedef DataType<Type::INT32> Int32Type;
typedef DataType<Type::UINT64> UInt64Type;
typedef DataType<Type::INT64> Int64Type;
typedef DataType<Type::FLOAT> FloatType;
typedef DataType<Type::DOUBLE> DoubleType;
typedef DataType<Type::STRING> StringType;

#endif // TYPES_H
