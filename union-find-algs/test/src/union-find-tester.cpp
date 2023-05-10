#include "../include/union-find-tester.h"
#include "union-find-algs/include/weighted-quick-union.h"

#include <algorithm>
#include <set>
#include <sstream>

namespace uf {

UnionFindTester::UnionFindTester(uint32_t n)
    : union_find_impls_{
        std::unique_ptr<UnionFind>(new QuickFind(n)),
        std::unique_ptr<UnionFind>(new QuickUnion(n)),
        std::unique_ptr<UnionFind>(new WeightedQuickUnion(n))
    }
{
}

std::array<bool, UnionFindTester::N> UnionFindTester::AreConnected(uint32_t e1, uint32_t e2) const
{
    std::array<bool, N> results;
    for (auto i = 0; i < union_find_impls_.size(); ++i) {
        auto r = union_find_impls_[i]->AreConnected(e1, e2);
        results[i] = r;
    }
    return results;
}

std::array<int, UnionFindTester::N> UnionFindTester::Count() const {
    std::array<int, N> results;
    for (auto i = 0; i < union_find_impls_.size(); ++i) {
        auto r = union_find_impls_[i]->Count();
        results[i] = r;
    }
    return results;
}

std::array<int, UnionFindTester::N> UnionFindTester::Find(uint32_t e) const {
    std::array<int, N> results;
    for (auto i = 0; i < union_find_impls_.size(); ++i) {
        auto r = union_find_impls_[i]->Find(e);
        results[i] = r;
    }
    return results;
}

void UnionFindTester::Union(uint32_t e1, uint32_t e2) {
    for (auto i = 0; i < union_find_impls_.size(); ++i) {
        union_find_impls_[i]->Union(e1, e2);
    }
}

} // namespace uf
