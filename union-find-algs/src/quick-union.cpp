#include "../include/quick-union.h"

#include <algorithm>
#include <numeric>

namespace uf {

QuickUnion::QuickUnion(uint32_t n)
    : root_ids_(n) {
    std::iota(root_ids_.begin(), root_ids_.end(), 0);
}

bool QuickUnion::AreConnected(uint32_t e1, uint32_t e2) {
    return Find(e1) == Find(e2);
}

int QuickUnion::Count() {
    return std::count_if(root_ids_.begin(), root_ids_.end(), [&](uint32_t e) { return root_ids_[e] == e; });
}

int QuickUnion::Find(uint32_t e) {
    return getRoot(e);
}

void QuickUnion::Union(uint32_t e1, uint32_t e2) {
    auto e1_root = getRoot(e1);
    auto e2_root = getRoot(e2);
    root_ids_[e1_root] = e2_root;
}

uint32_t QuickUnion::getRoot(uint32_t e) {
    UnionFind::CheckBoundary(root_ids_.size(), e);
    for (; root_ids_[e] != e; e = root_ids_[e]);
    return e;
}

} // namespace uf
