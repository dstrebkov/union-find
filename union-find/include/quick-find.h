#ifndef UNION_FIND_IMPL_UNION_FIND_QUICK_FIND_H_
#define UNION_FIND_IMPL_UNION_FIND_QUICK_FIND_H_

#include "union-find.h"

#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <vector>

namespace uf {

class QuickFind : public UnionFind {
public:
    QuickFind(uint32_t n);

    virtual bool AreConnected(uint32_t e1, uint32_t e2) override;
    virtual int Count() override;
    virtual int Find(uint32_t e) override;
    virtual void Union(uint32_t e1, uint32_t e2) override;

private:
    std::vector<uint32_t> ids; // connected component id
};

} // namespace uf

#endif // UNION_FIND_IMPL_UNION_FIND_QUICK_FIND_H_
