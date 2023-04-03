#ifndef UNION_FIND_IMPL_UNION_FIND_UNION_FIND_H_
#define UNION_FIND_IMPL_UNION_FIND_UNION_FIND_H_

#include <cstdint>

namespace uf {

class UnionFind {
public:
    virtual bool AreConnected(uint32_t e1, uint32_t e2) = 0;

    virtual int Count() = 0;

    virtual int Find(uint32_t e) = 0;

    virtual void Union(uint32_t e1, uint32_t e2) = 0;

    virtual ~UnionFind() = default;
};

} // namespace uf

#endif // UNION_FIND_IMPL_UNION_FIND_UNION_FIND_H_
