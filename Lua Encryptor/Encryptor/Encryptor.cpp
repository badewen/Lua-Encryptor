#include "Encryptor.h"

#include <cmath>

#include <SHA256/SHA256.h>
#include "../Utils/LuaMath.h"
#include "../Utils/Combine.h"
#include "../Utils/VectorUtils.h"

//create some noise to confuse reverser / decryptor.
//note: sometime this can create tons of noise and sometime otherwise

#define NOISE_LERP 0.15
#define NOISE_MIN 3


// dont destroy the lua header to confuse 'em even more.

#define NOISE_START 20

// imma spill it here for the readers, the noise can be defeated
//  by just getting the seed.
// Scripts are going to be decrypted in the end, so i wont put
// too much effort onto this Encrypt function.

std::vector<uint8_t> Encryptor::Encrypt(const std::vector<uint8_t> data, const uint8_t* key, size_t key_length)
{
    std::vector<uint8_t> ret{data};
    static SHA256 sha{};
    std::vector<uint8_t> temp = {};

    sha.update(key, key_length);
    uint8_t* hash = sha.digest();

    temp = Utils::ConstructVecFromAddr(hash, 32);

    temp = Utils::CombineN(temp, 16);

    // random, but consistent enough for every unique script
    ((uint64_t*)temp.data())[0] = ((uint64_t*)temp.data())[0] ^ data.size();

    Utils::Math::SetRandomSeed(((uint64_t*)temp.data())[0], ((uint64_t*)temp.data())[1]);

    // gonna generate some noise :troll:
    size_t n = Utils::Math::Random(NOISE_MIN, floor( Utils::Lerp( 0, data.size() - 20, NOISE_LERP ) ) );

    for (size_t i = 0; i < n; i++)
    {
        size_t chosen_loc = Utils::Math::Random(20, ret.size()) - 1;
        ret[chosen_loc] = ret[chosen_loc] ^ Utils::Math::Random(0x01, 0xFF);
    }

    return ret;
}
