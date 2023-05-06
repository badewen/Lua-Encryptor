#pragma once

#include <vector>
#include <lua/lua.hpp>

class Compiler
{
public:
    static lua_State* L;
public:
    static std::vector<uint8_t> CompileStr(const char* script, bool strip);
    static void ResetState();
};

