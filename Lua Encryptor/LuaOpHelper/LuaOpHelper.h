#pragma once

#include <string>

#include <lua/lapi.h>
#include <lua/lopcodes.h>

#include "../Dumper/Structs.h"

namespace LuaOpHelper
{
    extern OpMode GetOpFormat(LuaInstruction inst);
    

    extern std::string iabcString(LuaInstruction inst);
    extern std::string iabxString(LuaInstruction inst);
    extern std::string iAsBxString(LuaInstruction inst);
    extern std::string iAxString(LuaInstruction inst);
    extern std::string isJString(LuaInstruction inst);

    extern std::string OpParameterString(LuaInstruction inst);
    extern std::string OpName(OpCode op);
    extern std::string InstString(LuaInstruction inst);
}

