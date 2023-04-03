#include <gtest/gtest.h>

#include <union-find/include/quick-find.h>

#include "../include/regression-inputs.h"
#include "../include/regression-golds.h"

#include <cstdint>
#include <filesystem>
#include <fstream>

bool EXECUTE_LARGE_TEST = false;

struct RegressionResult {
    std::string curr;
    std::string gold;
};

RegressionResult Process(const std::string& input, const std::string& gold) {
    std::istringstream isstream{input};
    uint32_t n;
    isstream >> n;
    uf::QuickFind quick_find(n);

    std::ostringstream osstream;
    for (uint32_t p = 0, q = 0; isstream >> p >> q;) {
        if (quick_find.Find(p) == quick_find.Find(q)) continue;
        quick_find.Union(p, q);
        osstream << p << ' ' << q << std::endl;
    }
    osstream << quick_find.Count() << " components" << std::endl;

    auto curr{osstream.str()};

    return {curr, gold};
}

TEST(UnionFind, RegressionTests) {
    constexpr auto regression_inputs_count = std::size(UF_REGRESSION_INPUTS);
    constexpr auto regression_golds_count = std::size(UF_REGRESSION_GOLDS);

    static_assert(regression_inputs_count == regression_golds_count);

    for (auto i = 0; i < regression_inputs_count; ++i) {
        auto input{UF_REGRESSION_INPUTS[i]};
        auto gold{UF_REGRESSION_GOLDS[i]};

        auto result = Process(input, gold);

        ASSERT_EQ(result.curr, result.gold);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    if (std::string(argv[1]) == "dummy1") {
        EXECUTE_LARGE_TEST = true;
    }

    return RUN_ALL_TESTS();
}
