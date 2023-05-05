#pragma once

#include <vector>

namespace Utils {
    template<typename T>
    static void AppendVecToVec(std::vector<T> right, std::vector<T> left)
    {
        for (T item : left)
        {
            right.push_back(item);
        }
    }

    template <typename T>
    static std::vector<T> ConstructVecFromAddr(T* data, size_t data_length)
    {
        std::vector<T> ret{};

        for (size_t i = 0; i < data_length; i++)
        {
            ret.push_back(data[i]);
        }

        return ret;
    }
}
