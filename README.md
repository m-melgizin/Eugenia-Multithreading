# Eugenia-Multithreading
Eugenia Multithreading Library is collection of various multithreading algorithms implemented in C++

- [Eugenia-Multithreading](#eugenia-multithreading)
- [Algorithms](#algorithms)
  - [Sorting](#sorting)
    - [Merge Sort](#merge-sort)


# Algorithms
## Sorting
### Merge Sort
Merge Sort algorithm implemented with multithreading and STL-containers support.

```cpp
template <class RandomIterator>
void mergesort(RandomIterator first, RandomIterator last, std::size_t max_threads);

template <class RandomIterator, class Compare>
void mergesort(RandomIterator first, RandomIterator last, Compare comp, std::size_t max_threads);
```

Sorts the elements in the range [`first`, `last`) in non-descending order. 
  - (1) Elements are sorted with respect to `std::less`.
  - (2) Elements are sorted with respect to `comp`.
  - (1, 2) The implementation will use the number of threads <= `max_threads`.

**Parameters**
  - `first`, `last` - the range of elements to sort.
  - `comp` - comparison function.

**Complexity**

Given $N$ as `last` - `first`:
  - (1) $O(N \cdot \log(N))$ comparisons using `std::less`.
  - (2) $O(N \cdot \log(N))$ applications of the comparator `comp`.

**Example**:
```cpp
#include <iostream>
#include <vector>
#include <eugenia/multithreading/sort/mergesort.hpp>

int main()
{
    constexpr std::size_t max_threads = 4
    std::vector<int> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    auto print = [&s](const std::string& rem)
    {
        for (auto a : s)
            std::cout << a << ' ';
        std::cout << ": " << rem << std::endl;
    };

    emth::mergesort(a.begin(), a.end(), max_threads);
    print("sorted with the default std::less");

    emth::mergesort(s.begin(), s.end(), std::greater<int>(), max_threads);
    print("sorted with the standard library compare function object");

    struct
    {
        bool operator()(int a, int b) const { return a < b; }
    }
    customLess;
 
    emth::mergesort(s.begin(), s.end(), customLess, max_threads);
    print("sorted with a custom function object");


    emth::mergesort(s.begin(), s.end(), [](int a, int b)
                                  {
                                      return a > b;
                                  }, max_threads);
    print("sorted with a lambda expression");
}
```

**Output**

```
0 1 2 3 4 5 6 7 8 9 : sorted with the default std::less
9 8 7 6 5 4 3 2 1 0 : sorted with the standard library compare function object
0 1 2 3 4 5 6 7 8 9 : sorted with a custom function object
9 8 7 6 5 4 3 2 1 0 : sorted with a lambda expression
```
