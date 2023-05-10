#ifndef UNION_FIND_ALGS_QUICK_UNION_H_
#define UNION_FIND_ALGS_QUICK_UNION_H_

#include "union-find.h"

#include <vector>

namespace uf {

class QuickUnion : public UnionFind
{
public:
    QuickUnion(uint32_t n);

    virtual bool AreConnected(uint32_t e1, uint32_t e2) const override;

    virtual int Count() const override;

    virtual int Find(uint32_t e) const override;

    virtual void Union(uint32_t e1, uint32_t e2) override;

protected:
    virtual uint32_t GetRoot(uint32_t e) const;

    mutable std::vector<uint32_t> root_ids_; // roots of each of the nodes
};

} // namespace uf

#endif // UNION_FIND_ALGS_QUICK_UNION_H_
