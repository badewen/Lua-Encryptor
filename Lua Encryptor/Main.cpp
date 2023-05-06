#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <lua/lua.hpp>
#include <lua/lauxlib.h>
#include <lua/lopcodes.h>
#include <lua/lopnames.h>

#include "Compiler/Compiler.h"
#include "Utils/LuaMath.h"
#include "Encryptor/Encryptor.h"
#include "Dumper/Dumper.h"
#include "LuaOpHelper/LuaOpHelper.h"

const char* script = R"( 
a = {}
a["uhuh"] = "babi"
a[2] = "anjing"
a["s"] = a;
)";
const char* key = "WOasewqerqwerqwerW";

int main() {

    Utils::Math::Init();

    std::vector<uint8_t> bytecode = Compiler::CompileStr(script, true);

    //auto res = Encryptor::Encrypt(bytecode, (uint8_t*)key, strlen(key));

    std::vector<LuaInstruction> instructions = Dumper::GetInstructionsFromProto(Dumper::GetProtoFromState(Compiler::L));

    for (LuaInstruction inst : instructions)
    {
        std::cout << LuaOpHelper::InstString(inst) << '\n';
    }

    FILE* f = fopen("strip.luac", "wb");

    fwrite(bytecode.data(), 1, bytecode.size(), f);

    fclose(f);

    return 0;

}
