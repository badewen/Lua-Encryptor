#include "LuaMath.h"

#include <iostream>

#include <lua/lua.hpp>

static lua_State* L = nullptr;

void Utils::Math::Init() 
{
    L = luaL_newstate();
    luaL_openlibs(L);
}

void Utils::Math::SetRandomSeed(uint64_t x, uint64_t y) 
{
    lua_getglobal(L, "math");
    lua_getfield(L, -1, "randomseed");

    lua_pushinteger(L, x);
    lua_pushinteger(L, y);

    lua_call(L, 2, 2);

    lua_settop(L, 0);
}

int64_t Utils::Math::Random(int64_t m, int64_t n)
{
    lua_getglobal(L, "math");
    lua_getfield(L, -1, "random");

    lua_pushinteger(L, m);
    lua_pushinteger(L, n);

    lua_call(L, 2, 1);

    lua_Integer num = lua_tointeger(L, -1);

    lua_settop(L, 0);

    return num;
}
