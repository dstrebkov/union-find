#include "../include/quick-find.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>

namespace uf {

QuickFind::QuickFind(uint32_t n)
    : ids_(n) {
    std::iota(ids_.begin(), ids_.end(), 0);
}

bool QuickFind::AreConnected(uint32_t e1, uint32_t e2) const {
    return Find(e1) == Find(e2);
}

int QuickFind::Count() const {
    std::unordered_set<uint32_t> uniques;
    std::for_each(ids_.begin(), ids_.end(), [&](uint32_t e) { uniques.insert(e); });
    return uniques.size();
}

int QuickFind::Find(uint32_t e) const {
    UnionFind::CheckBoundary(ids_.size(), e);
    return ids_[e];
}

void QuickFind::Union(uint32_t e1, uint32_t e2) {
    if (AreConnected(e1, e2)) {
        return;
    }
    auto id_old = ids_[e1];
    auto id_new = ids_[e2];
    for (auto& e : ids_) {
        if (e == id_old) {
            e = id_new;
        }
    }
}

} // namespace uf
