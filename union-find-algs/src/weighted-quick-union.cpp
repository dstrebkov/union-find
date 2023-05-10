#include "../include/weighted-quick-union.h"

#include <algorithm>
#include <numeric>

namespace uf {

WeightedQuickUnion::WeightedQuickUnion(uint32_t n)
    : QuickUnion(n), sizes_(n, 1) {
}

void WeightedQuickUnion::Union(uint32_t e1, uint32_t e2) {
    auto e1_root = GetRoot(e1);
    auto e2_root = GetRoot(e2);

    auto e1_size = sizes_[e1_root];
    auto e2_size = sizes_[e2_root];

    if (e1_size > e2_size) {
        root_ids_[e2_root] = e1_root;
        sizes_[e1_root] += sizes_[e2_root];
    } else {
        root_ids_[e1_root] = e2_root;
        sizes_[e2_root] += sizes_[e1_root];
    }
}

uint32_t WeightedQuickUnion::GetRoot(uint32_t e) const {
    UnionFind::CheckBoundary(root_ids_.size(), e);
    while (e != root_ids_[e]) {
        root_ids_[e] = root_ids_[root_ids_[e]];
        e = root_ids_[e];
    }
    return e;
}

} // namespace uf
