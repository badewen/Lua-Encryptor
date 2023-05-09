#include "LuaOpHelper.h"

#include <string>
#include <sstream>

#include <lua/lopnames.h>
#include <lua/lopcodes.h>

OpMode LuaOpHelper::GetOpFormat(LuaInstruction inst)
{
    return isJ;
}

std::string LuaOpHelper::iabcString(LuaInstruction inst)
{
    std::stringstream ret;
    ret << "A: " << inst.iABC.A << "\tB: " << inst.iABC.B << "\tC: " << inst.iABC.C << "\tK: " << inst.iABC.K;
    return ret.str();
}

std::string LuaOpHelper::iabxString(LuaInstruction inst)
{
    std::stringstream ret;
    ret << "A: " << inst.iABx.A << "\tBx: " << inst.iABx.Bx;
    return ret.str();
}

std::string LuaOpHelper::iAsBxString(LuaInstruction inst)
{
    std::stringstream ret;
    ret << "A: " << inst.iAsBx.A << "\tBx: " << inst.iAsBx.sBx;
    return ret.str();
}

std::string LuaOpHelper::iAxString(LuaInstruction inst)
{
    std::stringstream ret;
    ret << "Ax: " << inst.iAx.Ax;
    return ret.str();
}

std::string LuaOpHelper::isJString(LuaInstruction inst)
{
    std::stringstream ret;
    ret << "sJ: " << inst.isJ.sJ;
    return ret.str();
}

std::string LuaOpHelper::OpParameterString(LuaInstruction inst)
{
    OpMode opm = getOpMode(GET_OPCODE(inst.RawInstruction));
    switch (opm)
    {
    case iABC:
        return iabcString(inst);

    case iABx:
        return iabxString(inst);
    case iAsBx:
        return iAsBxString(inst);
    case iAx:
        return iAxString(inst);
    case isJ:
        return isJString(inst);
    }
    return std::string();
}

std::string LuaOpHelper::OpName(OpCode op)
{
    return opnames[op];
}

std::string LuaOpHelper::InstString(LuaInstruction inst)
{
    return OpName((OpCode)inst.Op) + "\t\t" + OpParameterString(inst);
}


