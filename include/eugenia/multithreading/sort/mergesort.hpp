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
#ifndef EUGENIA_MULTITHREADING_SORT_MERGESORT_HPP
#define EUGENIA_MULTITHREADING_SORT_MERGESORT_HPP

#include <iterator>
#include <algorithm>
#include <thread>

#include "../defines.hpp"
#include "../helpers.hpp"

EUGENIA_MULTITHREADING_NAMESPACE_BEGIN

DETAILS_NAMESPACE_BEGIN

template <class RandomIterator, class Compare>
void mergesort(RandomIterator first, RandomIterator last, Compare comp, std::size_t max_depth, std::size_t current_depth = 0, std::size_t size = 0)
{
    if (size == 0 && first != last)
        size = std::distance(first, last);

    if (size <= 1)
        return;

    std::size_t left_half = size / 2;
    std::size_t right_half = size - left_half;
    RandomIterator mid = first;
    std::advance(mid, left_half);

    if (current_depth < max_depth)
    {
        std::thread thread_left = std::thread(mergesort<RandomIterator, Compare>, first, mid, comp, max_depth, current_depth + 1, left_half);
        std::thread thread_right = std::thread(mergesort<RandomIterator, Compare>, mid, last, comp, max_depth, current_depth + 1, right_half);

        thread_left.join();
        thread_right.join();
    }
    else
    {
        mergesort(first, mid, comp, max_depth, current_depth, left_half);
        mergesort(mid, last, comp, max_depth, current_depth, right_half);
    }
    std::inplace_merge(first, mid, last, comp);
}

DETAILS_NAMESPACE_END

template <class RandomIterator, class Compare>
void mergesort(RandomIterator first, RandomIterator last, Compare comp, std::size_t max_threads)
{
    if (max_threads == 0)
        max_threads = std::thread::hardware_concurrency();
    if (max_threads == 0)
        max_threads = 1;
    std::size_t max_depth = helpers::log2(max_threads);
    details::mergesort(first, last, comp, max_depth);
}

template <class RandomIterator>
void mergesort(RandomIterator first, RandomIterator last, std::size_t max_threads)
{
    mergesort(first, last, std::less<typename std::iterator_traits<RandomIterator>::value_type>(), max_threads);
}

EUGENIA_MULTITHREADING_NAMESPACE_END

#endif // !EUGENIA_MULTITHREADING_SORT_MERGESORT_HPP
