#pragma once

#include <lua/lua.hpp>
#include <lua/lobject.h>
#include <lua/lapi.h>

#include <vector>

#include "../Utils/VectorUtils.h"
#include "Structs.h"

namespace Dumper 
{
    static Proto* GetProtoFromState(lua_State* L)
    {
        TValue* o;
        api_checknelems(L, 1);
        o = s2v(L->top - 1);
        if (isLfunction(o))
            return getproto(o);
        else
            return nullptr;
    }

    static std::vector<LuaInstruction> GetInstructionsFromProto(Proto* p)
    {
        return Utils::ConstructVecFromAddr((LuaInstruction*)p->code, p->sizecode);
    }
}
