#include <chrono>
#include <iostream>

#include "../../union-find-algs/include/weighted-quick-union.h"

int main(int argc, char** argv) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    uf::WeightedQuickUnion wqu(3);
    wqu.Union(0, 1);
    std::cout << wqu.Count() << std::endl;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference (sec) = "
              << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) /1000000.0
              << std::endl;
    return EXIT_SUCCESS;
}
