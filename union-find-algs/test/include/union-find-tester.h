#ifndef UNION_FIND_ALGS_TEST_UNION_FIND_TESTER_H_
#define UNION_FIND_ALGS_TEST_UNION_FIND_TESTER_H_

#include <map>
#include <memory>
#include <vector>

#include <union-find-algs/include/quick-find.h>
#include <union-find-algs/include/quick-union.h>

namespace uf {

class UnionFindTester : public UnionFind {
public:
    UnionFindTester(uint32_t n);
    ~UnionFindTester();

    virtual bool AreConnected(uint32_t e1, uint32_t e2) const override;
    virtual int Count() const override;
    virtual int Find(uint32_t e) const override;
    virtual void Union(uint32_t e1, uint32_t e2) override;

    std::string getLog();

    UnionFindTester(const UnionFindTester&) = delete;
    UnionFindTester(UnionFindTester&&) = delete;
    UnionFindTester& operator=(const UnionFindTester&) = delete;
    UnionFindTester& operator=(UnionFindTester&&) = delete;

private:
    static constexpr const char* kErrorMessage =
        "Error: different results returned by Union-Find implementations, "
        "check log for more information";

    std::map<std::string, UnionFind*> union_find_impls_;

    mutable std::vector<std::string> test_log_;
};

} // namespace uf

#endif // UNION_FIND_ALGS_TEST_UNION_FIND_TESTER_H_
