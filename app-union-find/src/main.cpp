#include <chrono>
#include <iostream>

#include <include/union-find-algs/quick-find.h>
#include <include/union-find-algs/quick-union.h>
#include <include/union-find-algs/weighted-quick-union.h>

int main(int argc, char** argv) {
    uint32_t n;
    std::cin >> n;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    uf::QuickFind quick_find(n);
    uf::QuickUnion quick_union(n);
    uf::WeightedQuickUnion weighted_quick_union(n);

    uf::UnionFind& uf = weighted_quick_union;
    for (uint32_t p = 0, q = 0; std::cin >> p >> q;) {
        if (uf.Find(p) == uf.Find(q)) {
            continue;
        }
        uf.Union(p, q);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time: "
              << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.0
              << " sec. " << std::endl;
    return EXIT_SUCCESS;
}
