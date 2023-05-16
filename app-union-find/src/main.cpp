#include <chrono>
#include <iostream>
#include <memory>

#include <include/union-find-algs/quick-find.h>
#include <include/union-find-algs/quick-union.h>
#include <include/union-find-algs/weighted-quick-union.h>

int main(int argc, char** argv) {
    std::string uf_alg;
    std::cin >> uf_alg;

    uint32_t n;
    std::cin >> n;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    std::unique_ptr<uf::UnionFind> uf;
    if (uf_alg == "QuickFind") {
        uf = std::make_unique<uf::QuickFind>(uf::QuickFind(n));
    } else if (uf_alg == "QuickUnion") {
        uf = std::make_unique<uf::QuickUnion>(uf::QuickUnion(n));
    } else if (uf_alg == "WeightedQuickUnion") {
        uf = std::make_unique<uf::WeightedQuickUnion>(uf::WeightedQuickUnion(n));
    } else {
        std::cerr << "Error: Supported values are 'QuickFind', 'QuickUnion' and 'WeightedQuickUnion'.";
        return EXIT_FAILURE;
    }

    for (uint32_t p = 0, q = 0; std::cin >> p >> q;) {
        if (uf->Find(p) == uf->Find(q)) {
            continue;
        }
        uf->Union(p, q);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time: "
              << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.0
              << " sec. " << std::endl;
    return EXIT_SUCCESS;
}
