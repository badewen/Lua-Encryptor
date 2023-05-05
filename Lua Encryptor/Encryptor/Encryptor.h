#pragma once

#include <vector>

class Encryptor
{
public:
    static std::vector<uint8_t> Encrypt(const std::vector<uint8_t> data, const uint8_t* key, size_t key_length);
};

