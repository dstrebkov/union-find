#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../../union-find-algs/include/quick-find.h"
#include "../../union-find-algs/include/quick-union.h"
#include "../../union-find-algs/include/weighted-quick-union.h"

int main(int argc, char** argv) {
    std::ifstream input_fs{"/home/dstrebkov/Devel/cpp_projects/union-find/union-find-algs/test/test-data/uf_2M.txt"};
    if (!input_fs) {
        std::cerr << "Input file not found." << std::endl;
        return EXIT_FAILURE;
    }

    std::string input(std::istreambuf_iterator<char>{input_fs}, {});
    std::istringstream isstream{input};
    uint32_t n;
    isstream >> n;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    uf::QuickFind quick_find(n);
    uf::QuickUnion quick_union(n);
    uf::WeightedQuickUnion weighted_quick_union(n);

    uf::UnionFind& uf = weighted_quick_union;
    for (uint32_t p = 0, q = 0; isstream >> p >> q;) {
        if (uf.Find(p) == uf.Find(q)) {
            continue;
        }
        uf.Union(p, q);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time: "
              << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) /1000000.0
              << " sec. " << std::endl;
    return EXIT_SUCCESS;
}
