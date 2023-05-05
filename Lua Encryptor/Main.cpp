#include <iostream>

#include <lua/lua.hpp>
#include <lua/lauxlib.h>

#include "Compiler/Compiler.h"
#include "Utils/LuaMath.h"
#include "Encryptor/Encryptor.h"

const char* script = R"( print("sabruh2");print("SABASER");print("Lmalsmdlasdmlasmdlasmdalsdlasmslfnlewrjgejrngsjdlfsgojnerotaeo;jfgerg") )";
const char* key = "WOasewqerqwerqwerW";

int main() {

    Utils::Math::Init();

    std::vector<uint8_t> bytecode = Compiler::CompileStr(script, false);
    
    auto res = Encryptor::Encrypt(bytecode, (uint8_t*)key, strlen(key));

    fwrite(res.data(), 1, res.size(), stdout);

    return 0;

}
