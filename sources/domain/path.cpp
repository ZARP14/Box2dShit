#include "path.hpp"

#include <windows.h>

std::string
Path::path() noexcept
{
    CHAR buffer[MAX_PATH] = {0};
    uint8_t size = GetModuleFileNameA(NULL, buffer, MAX_PATH);
    for (int i = 0; i < 2; ++i)
        while (buffer[--size] != L'\\')
            ;
    buffer[size + 1] = 0;
    return std::string(buffer);
}