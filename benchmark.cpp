#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

#include <eugenia/multithreading/multithreading.hpp>

EUGENIA_MULTITHREADING_NAMESPACE_BEGIN

namespace benchmark
{

void generate_random(std::vector<int>& a, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
        a.push_back(std::rand() % 1000);
}

template <class Function, class ...Args>
std::size_t measure_elapsed_time(Function&& function, Args&&... args)
{
    using clock = std::chrono::steady_clock;
    auto start = clock::now();
    std::invoke(std::forward<Function>(function), std::forward<Args>(args)...);
    auto end = clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

void mergesort_stdsort_vector_benchmark(const int max_threads = 4, const int iterations = 10)
{
    const int vector_sizes[] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
    std::cout << "emth::mergesort benchmark (max_threads = " << max_threads << ", iterations = " << iterations << ")" << std::endl;
    std::cout << "-------------------------+-----------------+-----------------" << std::endl;
    std::cout << " std::vector<int>.size() | emth::mergesort |    std::sort    " << std::endl;
    std::cout << "-------------------------+-----------------+-----------------" << std::endl;
    for (auto size : vector_sizes)
    {    
        std::vector<std::size_t> emth_times;
        emth_times.reserve(iterations);
        std::vector<std::size_t> std_times;
        std_times.reserve(iterations);
    
        static const auto avg = [](std::vector<std::size_t>& times) -> double
        {
            std::size_t sum = 0;
            for (auto time : times)
                sum += time;
            return static_cast<double>(sum) / static_cast<double>(times.size());
        };

        for (int i = 0; i < iterations; ++i)
        {
            std::vector<int> a;
            a.reserve(size);
            emth::benchmark::generate_random(a, size);
            std::vector<int> b = a;

            emth_times.push_back(emth::benchmark::measure_elapsed_time(emth::mergesort<std::vector<int>::iterator>, a.begin(), a.end(), max_threads));
            std_times.push_back(emth::benchmark::measure_elapsed_time(std::sort<std::vector<int>::iterator>, b.begin(), b.end()));
        }

        std::cout << std::setw(24) << size << " | "
                  << std::setw(12) << std::fixed << std::setprecision(3) << avg(emth_times) << " ms | "
                  << std::setw(12) << std::fixed << std::setprecision(3) << avg(std_times) << " ms" << std::endl;
    }
}

} // namespace benchmark

EUGENIA_MULTITHREADING_NAMESPACE_END

int main()
{
    emth::benchmark::mergesort_stdsort_vector_benchmark();
    return 0;
}