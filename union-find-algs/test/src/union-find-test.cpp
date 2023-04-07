#include <gtest/gtest.h>

#include <union-find-algs/include/quick-find.h>

namespace uf {

TEST(QuickFind, Union_AreConnected) {
    uf::QuickFind quick_find(5);
    auto v = {0, 1, 2, 3, 4};
    for (auto i : v)
        for (auto j : v)
            if (i == j) ASSERT_TRUE(quick_find.AreConnected(i, j));
            else ASSERT_FALSE(quick_find.AreConnected(i, j));

    quick_find.Union(0, 1);
    ASSERT_TRUE(quick_find.AreConnected(0, 1));
    ASSERT_FALSE(quick_find.AreConnected(0, 2));
    quick_find.Union(0, 2);
    ASSERT_TRUE(quick_find.AreConnected(0, 2));
}

TEST(QuickFind, Count) {
    uf::QuickFind quick_find(5);
    ASSERT_EQ(5, quick_find.Count());
    quick_find.Union(0, 1);
    ASSERT_EQ(4, quick_find.Count());
    quick_find.Union(0, 2);
    quick_find.Union(0, 3);
    ASSERT_EQ(2, quick_find.Count());
    quick_find.Union(4, 1);
    ASSERT_EQ(1, quick_find.Count());
}

TEST(QuickFind, Find) {
    uf::QuickFind quick_find(5);
    ASSERT_EQ(0, quick_find.Find(0));
    quick_find.Union(0, 1);
    ASSERT_EQ(1, quick_find.Find(0));
    quick_find.Union(4, 0);
    ASSERT_EQ(1, quick_find.Find(0));
    ASSERT_EQ(1, quick_find.Find(4));
}

TEST(QuickFind, OutOfBoundsAccess_OneArgument) {
    uf::QuickFind quick_find(5);
    ASSERT_THROW(quick_find.Find(88), std::out_of_range);
}

TEST(QuickFind, OutOfBoundsAccess_TwoArguments) {
    uf::QuickFind quick_find(5);
    ASSERT_THROW(quick_find.Union(0, 99), std::out_of_range);
}

} // namespace uf
