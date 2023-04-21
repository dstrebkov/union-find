#include "../include/quick-union.h"

#include <algorithm>
#include <numeric>

namespace uf {

QuickUnion::QuickUnion(uint32_t n)
    : root_ids_(n) {
    std::iota(root_ids_.begin(), root_ids_.end(), 0);
}

bool QuickUnion::AreConnected(uint32_t e1, uint32_t e2) const {
    return Find(e1) == Find(e2);
}

int QuickUnion::Count() const {
    uint32_t count = 0;
    for (auto i = 0; i < root_ids_.size(); ++i) {
        count += (root_ids_[i] == i) ? 1 : 0;
    }
    return count;
}

int QuickUnion::Find(uint32_t e) const {
    return GetRoot(e);
}

void QuickUnion::Union(uint32_t e1, uint32_t e2) {
    auto e1_root = GetRoot(e1);
    auto e2_root = GetRoot(e2);
    root_ids_[e1_root] = e2_root;
}

uint32_t QuickUnion::GetRoot(uint32_t e) const {
    UnionFind::CheckBoundary(root_ids_.size(), e);
    for (; root_ids_[e] != e; e = root_ids_[e]);
    return e;
}

} // namespace uf
