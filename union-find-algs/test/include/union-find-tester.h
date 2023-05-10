#ifndef UNION_FIND_ALGS_TEST_UNION_FIND_TESTER_H_
#define UNION_FIND_ALGS_TEST_UNION_FIND_TESTER_H_

#include <array>
#include <map>
#include <memory>
#include <vector>

#include <union-find-algs/include/quick-find.h>
#include <union-find-algs/include/quick-union.h>
#include <union-find-algs/include/weighted-quick-union.h>

namespace uf {

class UnionFindTester {
public:
    static const uint8_t N = 3;

    UnionFindTester(uint32_t n);

    std::array<bool, N> AreConnected(uint32_t e1, uint32_t e2) const;
    std::array<int, N> Count() const;
    std::array<int, N> Find(uint32_t e) const;
    void Union(uint32_t e1, uint32_t e2);

    UnionFindTester(const UnionFindTester&) = delete;
    UnionFindTester(UnionFindTester&&) = delete;
    UnionFindTester& operator=(const UnionFindTester&) = delete;
    UnionFindTester& operator=(UnionFindTester&&) = delete;

private:
    std::array<std::unique_ptr<UnionFind>, N> union_find_impls_;
};

} // namespace uf

#endif // UNION_FIND_ALGS_TEST_UNION_FIND_TESTER_H_
