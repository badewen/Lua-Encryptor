#include "Compiler.h"

#include <iostream>

#include <lua/lua.hpp>

lua_State* Compiler::L = luaL_newstate();

static int lua_writer_callback(lua_State* L, const void* chunk, size_t size, void* user_data)
{
    std::vector<uint8_t>* out = reinterpret_cast<std::vector<uint8_t>*>(user_data);

    for (size_t i = 0; i < size; i++) {
        out->push_back(((uint8_t*)chunk)[i]);
    }

    return 0;
}

std::vector<uint8_t> Compiler::CompileStr(const char* script, bool strip)
{
    std::vector<uint8_t> ret{};
    
    if (luaL_loadstring(L, script) == LUA_ERRSYNTAX) {
        std::cout << "SYNTAX ERROR: " << lua_tostring(L, -1);
        lua_close(L);
        return ret;
    }
    
    lua_dump(L, lua_writer_callback, &ret, strip);
    
    return ret;
}

void Compiler::ResetState()
{
    lua_close(L);

    L = luaL_newstate();

}
