/****************************************************************
 *****************************************************************/
#pragma once

#include <iostream>

namespace
{
    // Enable The function only for floating point types.
    template <
        typename T,
        std::enable_if_t<std::is_floating_point<T>::value>* = nullptr>
    T FloatingPointEnforcer(T inArg)
    {
        return inArg + 1;
    }

}   // unnamed namespace

namespace Components
{
    void EnableIfCaller()
    {
        {
            FloatingPointEnforcer<float>(44.0f);
            FloatingPointEnforcer<double>(44.0);
            // FloatingPointEnforcer<int>(44); // should fail to compile
        }
    }
} // Components
