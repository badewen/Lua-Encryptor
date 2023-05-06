#pragma once

#include <stdint.h>

struct LuaInstruction
{
    union
    {
        struct
        {
            uint32_t Op : 7;
            uint32_t A : 8;
            uint32_t K : 1;
            uint32_t B : 8;
            uint32_t C : 8;
        } iABC;
        
        struct
        {
            uint32_t Op : 7;
            uint32_t A : 8;
            uint32_t Bx : 17;
        } iABx;

        struct
        {
            uint32_t Op : 7;
            uint32_t A : 8;
            uint32_t sBx : 17;
        } iAsBx;

        struct
        {
            uint32_t Op : 7;
            uint32_t Ax : 25;
        } iAx;

        struct
        {
            uint32_t Op : 7;
            uint32_t sJ : 25;
        } isJ;
        
        uint32_t Op : 7;
        uint32_t RawInstruction;
    };
};