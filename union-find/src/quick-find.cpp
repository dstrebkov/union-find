#include "../include/quick-find.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>

namespace uf {

QuickFind::QuickFind(uint32_t n)
    : ids(n) {
    std::iota(ids.begin(), ids.end(), 0);
}

bool QuickFind::AreConnected(uint32_t e1, uint32_t e2) {
    return Find(e1) == Find(e2);
}

int QuickFind::Count() {
    std::unordered_set<uint32_t> uniques;
    std::for_each(ids.begin(), ids.end(), [&](uint32_t e) { uniques.insert(e); });
    return uniques.size();
}

int QuickFind::Find(uint32_t e) {
    return ids[e];
}

void QuickFind::Union(uint32_t e1, uint32_t e2) {
    auto id_old = ids[e1];
    auto id_new = ids[e2];
    for (auto& e : ids) {
        if (e == id_old) {
            e = id_new;
        }
    }
}

} // namespace uf
