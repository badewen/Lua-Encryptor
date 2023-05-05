#pragma once

#include <vector>
#include <assert.h>
#include <iostream>

namespace Utils {

    // size : size in byte
    // _off : offset
    static void __combineSingle(size_t to_off, size_t from_off, size_t size, const std::vector<uint8_t> data, std::vector<uint8_t>& out)
    {
        for (size_t i = 0; i < size; i++)
        {
            out[i] = data[size - i + to_off] ^ data[data.size() - i - 1 - from_off];
        }
    }

    static std::vector<uint8_t> CombineN(const std::vector<uint8_t> data, size_t out_len)
    {
        assert(data.size() > out_len && "CombineN Error : Data.size() < out_len");
        assert(data.size() % out_len == 0 && "CombineN Error : data.size() must be divisible by out_len");

        std::vector<uint8_t> out{};
        out.resize(out_len);

        for (size_t n = 0; n < data.size() / out_len; n++)
        {
            __combineSingle(0, out_len * n, out_len, data, out);
        }
        return out;
    }

}
