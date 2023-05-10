#ifndef UNION_FIND_ALGS_WEIGHTED_QUICK_UNION_H_
#define UNION_FIND_ALGS_WEIGHTED_QUICK_UNION_H_

#include "quick-union.h"

#include <vector>

namespace uf {

class WeightedQuickUnion : public QuickUnion
{
public:
    WeightedQuickUnion(uint32_t n);

    virtual void Union(uint32_t e1, uint32_t e2) override;

protected:
    uint32_t GetRoot(uint32_t e) const override;

private:
    std::vector<uint32_t> sizes_; // sizes of the trees
};

} // namespace uf

#endif // UNION_FIND_ALGS_WEIGHTED_QUICK_UNION_H_
