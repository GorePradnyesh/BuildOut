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

    template <
        typename T,
        typename Z,
        std::enable_if_t<std::is_same<T, Z>::value>* = nullptr>
    void TypeEqualitycheck(T inFirst, Z inSecond)
    {
        std::cout << "Types are the same " << std::endl;
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
        } // unnamed
        
        {
            std::uint32_t value_uint32_0 = 3;
            std::uint32_t value_uint32_1 = 4;
            std::int64_t value_int64_0 = 4;
            
            // TypeEqualitycheck(value_uint32_0, value_int64_0);    // should  fail since uint32 != int64
            TypeEqualitycheck(value_uint32_0, value_uint32_1);
            TypeEqualitycheck(value_uint32_0, static_cast<std::uint32_t>(value_int64_0));
        }
    }
} // Components
