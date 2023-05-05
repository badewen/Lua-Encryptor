#pragma once

#include <stdint.h>
#include "Math.h"

namespace Utils {
    class Math {
    public:
        static void Init();
        static void SetRandomSeed(uint64_t x, uint64_t y = 0);
        static int64_t Random(int64_t m, int64_t n);
    };
}