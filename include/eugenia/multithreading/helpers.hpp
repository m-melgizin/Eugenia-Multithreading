/*
 * Copyright 2024 Marat Melgizin
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
#ifndef EUGENIA_MULTITHREADING_HELPERS_HPP
#define EUGENIA_MULTITHREADING_HELPERS_HPP

#include <type_traits>
#include <cstdint>

#if defined(_MSC_VER)
#include <intrin.h>
#endif

#include "defines.hpp"

EUGENIA_NAMESPACE_BEGIN

HELPERS_NAMESPACE_BEGIN

uint32_t count_leading_zeros(uint32_t value)
{
#if defined(__GNUC__) || defined(__clang__)
    return __builtin_clzl(value);
#elif defined(_MSC_VER)
    UnsignedInteger leading_zeros = 0;
    if (_BitScanReverse(&leading_zeros, value))
        return 31 - leading_zeros;
    return 32;
#endif
}

uint64_t count_leading_zeros(uint64_t value)
{
#if defined(__GNUC__) || defined(__clang__)
    return __builtin_clzll(value);
#elif defined(_MSC_VER)
    UnsignedInteger leading_zeros = 0;
    if (_BitScanReverse(&leading_zeros, value))
        return 63 - leading_zeros;
    return 64;
#endif
}

template <class UnsignedInteger>
typename std::enable_if<std::is_unsigned<UnsignedInteger>::value, UnsignedInteger>::type
log2(UnsignedInteger value)
{
    return 8 * sizeof(UnsignedInteger) - 1 - count_leading_zeros(value);
}

HELPERS_NAMESPACE_END

EUGENIA_NAMESPACE_END

#endif // !EUGENIA_MULTITHREADING_HELPERS_HPP
