#include "../include/union-find-tester.h"

#include <algorithm>
#include <set>
#include <sstream>

namespace uf {

UnionFindTester::UnionFindTester(uint32_t n)
    : union_find_impls_{
        { "QuickFind", new QuickFind(n) },
        { "QuickUnion", new QuickUnion(n) }
    }
{
}

UnionFindTester::~UnionFindTester() {
    std::for_each(union_find_impls_.begin(), union_find_impls_.end(),
                  [](auto& ufi_pair) {
                      delete ufi_pair.second;
                      ufi_pair.second = nullptr;
                  });
}

bool UnionFindTester::AreConnected(uint32_t e1, uint32_t e2) const {
    std::set<bool> results;
    for (const auto& ufi : union_find_impls_) {
        std::ostringstream log_entry;
        auto r = ufi.second->AreConnected(e1, e2);
        results.insert(r);
        log_entry << ufi.first << "::AreConnected(" << e1 << ", " << e2 << ") returned " << r;
        test_log_.push_back(log_entry.str());
    }
    if (results.size() > 1) {
        throw new std::runtime_error(UnionFindTester::kErrorMessage);
    }
    return *results.begin();
}

int UnionFindTester::Count() const {
    std::set<bool> results;
    for (const auto& ufi : union_find_impls_) {
        std::ostringstream log_entry;
        auto c = ufi.second->Count();
        results.insert(c);
        log_entry << ufi.first << "::Count() returned " << c;
        test_log_.push_back(log_entry.str());
    }
    if (results.size() > 1) {
        throw new std::runtime_error(UnionFindTester::kErrorMessage);
    }
    return *results.begin();
}

int UnionFindTester::Find(uint32_t e) const {
    std::set<bool> results;
    for (const auto& ufi : union_find_impls_) {
        std::ostringstream log_entry;
        auto f = ufi.second->Find(e);
        results.insert(f);
        log_entry << ufi.first << "::Find(" << e << ") returned " << f;
        test_log_.push_back(log_entry.str());
    }
    if (results.size() > 1) {
        throw new std::runtime_error(UnionFindTester::kErrorMessage);
    }
    return *results.begin();
}

void UnionFindTester::Union(uint32_t e1, uint32_t e2) {
    for (const auto& ufi : union_find_impls_) {
        std::ostringstream log_entry;
        ufi.second->Union(e1, e2);
        log_entry << ufi.first << "::Union(" << e1 << ", " << e2 << ") called";
        test_log_.push_back(log_entry.str());
    }
}

std::string UnionFindTester::getLog() {
    std::string result;
    std::for_each(test_log_.begin(), test_log_.end(), [&](auto e) { result += e + "\n"; });
    return result;
}

} // namespace uf
