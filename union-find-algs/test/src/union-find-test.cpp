#include <gtest/gtest.h>

#include <union-find-algs/include/quick-find.h>
#include "../include/union-find-tester.h"

namespace uf {

TEST(UnionFind, Union_AreConnected) {
    UnionFindTester uf_tester{5};
    auto v = {0, 1, 2, 3, 4};
    for (auto i : v) {
        for (auto j : v) {
            auto r = uf_tester.AreConnected(i, j);
            if (i == j) {
                std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_TRUE(e);} );
            } else {
                std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_FALSE(e);} );
            }
        }
    }

    uf_tester.Union(0, 1);
    auto r = uf_tester.AreConnected(0, 1);
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_TRUE(e);} );

    r = uf_tester.AreConnected(0, 2);
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_FALSE(e);} );

    uf_tester.Union(0, 2);
    r = uf_tester.AreConnected(0, 2);
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_TRUE(e);} );
}

TEST(UnionFind, Count) {
    UnionFindTester uf_tester{5};
    auto r = uf_tester.Count();
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_EQ(5, e);} );

    uf_tester.Union(0, 1);
    r = uf_tester.Count();
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_EQ(4, e);} );

    uf_tester.Union(0, 2);
    uf_tester.Union(0, 3);
    r = uf_tester.Count();
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_EQ(2, e);} );

    uf_tester.Union(4, 1);
    r = uf_tester.Count();
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_EQ(1, e);} );
}

TEST(UnionFind, Find) {
    UnionFindTester uf_tester{5};
    auto r = uf_tester.Find(0);
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_EQ(0, e);} );

    uf_tester.Union(0, 1);
    r = uf_tester.Find(0);
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_EQ(1, e);} );

    uf_tester.Union(4, 0);
    r = uf_tester.Find(0);
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_EQ(1, e);} );
    r = uf_tester.Find(4);
    std::for_each(r.begin(), r.end(), [&](const auto& e) {ASSERT_EQ(1, e);} );
}

TEST(UnionFind, OutOfBoundsAccess_OneArgument) {
    UnionFindTester uf_tester{5};
    ASSERT_THROW(uf_tester.Find(88), std::out_of_range);
}

TEST(UnionFind, OutOfBoundsAccess_TwoArguments) {
    UnionFindTester uf_tester{5};
    ASSERT_THROW(uf_tester.Union(0, 99), std::out_of_range);
}

} // namespace uf
