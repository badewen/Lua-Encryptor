#pragma once

#include <vector>

class Compiler
{
public:
    static std::vector<uint8_t> CompileStr(const char* script, bool strip);

};

