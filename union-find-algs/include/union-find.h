#ifndef UNION_FIND_ALGS_UNION_FIND_H_
#define UNION_FIND_ALGS_UNION_FIND_H_

#include <cstdint>
#include <stdexcept>

namespace uf {

class UnionFind {
public:
    virtual bool AreConnected(uint32_t e1, uint32_t e2) const = 0;

    virtual int Count() const = 0;

    virtual int Find(uint32_t e) const = 0;

    virtual void Union(uint32_t e1, uint32_t e2) = 0;

    virtual ~UnionFind() = default;

protected:
    template <typename... Targs>
    void CheckBoundary(uint32_t size, Targs... es) const {
        for (auto e : {es...}) {
            if (e < 0 || e >= size) {
                throw std::out_of_range("Index is out of bounds");
            }
        }
    }
};

} // namespace uf

#endif // UNION_FIND_ALGS_UNION_FIND_H_
