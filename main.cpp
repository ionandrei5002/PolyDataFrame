#include <iostream>
#include <vector>

#include "array.h"
#include "value.h"
#include "operators.h"

using namespace std;

int main()
{
    std::vector<Array> rows;

    rows.reserve(1000);

    FromStringCast<Int64Type> int64Cast;
    FromStringCast<Int32Type> int32Cast;

    for(uint64_t i = 0; i < 1000; i++) {
        std::string udid = "99";
        std::string val = "9";

        std::unique_ptr<Value> _udid = int64Cast.operation(ViewByteBuffer(udid.data(), udid.size()));
        std::unique_ptr<Value> _val = int32Cast.operation(ViewByteBuffer(val.data(), val.size()));

        Array chunk(_udid->pack()._size + _val->pack()._size);
        chunk.emplace_back(_udid->pack());
        chunk.emplace_back(_val->pack());

        rows.emplace_back(chunk);
    }

    for(uint64_t i = 0; i < 1000; i++)
    {
        uint64_t offset = 0;
        Array row = rows[i];
        TypedValue<Int64Type> udid(ByteBuffer(nullptr, 0));
        TypedValue<Int32Type> val(ByteBuffer(nullptr, 0));

        std::unique_ptr<Value> cell = udid.unpack(row, offset);
        cell->print(std::cout);
        std::cout << " ";
        cell = val.unpack(row, offset);
        cell->print(std::cout);
        std::cout << std::endl;
    }

    return 0;
}
