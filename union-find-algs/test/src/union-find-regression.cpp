#include <gtest/gtest.h>

#include <fstream>
#include <filesystem>

#include "../include/union-find-tester.h"
#include "../include/regression-inputs.h"
#include "../include/regression-golds.h"

namespace uf {

static const uint16_t kBufferSize = 256;
static char kRegressionTestsDirPath[kBufferSize] = {};
static const char* kRegressionTestsFlag = "--regressionDataDir";

typedef std::vector<std::filesystem::path> FilePaths;

struct RegressionResult {
    std::array<std::string, UnionFindTester::N> currs;
    std::string gold;
};

RegressionResult Process(const std::string& input, const std::string& gold) {
    std::istringstream isstream{input};
    uint32_t n;
    isstream >> n;
    UnionFindTester uf_tester{n};

    std::array<std::ostringstream, UnionFindTester::N> osstreams;
    for (uint32_t p = 0, q = 0; isstream >> p >> q;) {
        if (uf_tester.Find(p) == uf_tester.Find(q)) {
            continue;
        }

        uf_tester.Union(p, q);

        std::for_each(osstreams.begin(), osstreams.end(), [=](auto& oss) { oss << p << ' ' << q << std::endl; });
    }

    auto counts = uf_tester.Count();
    for (auto i = 0; i < UnionFindTester::N; ++i) {
        osstreams[i] << counts[i] << " components" << std::endl;
    }

    RegressionResult result;
    for (auto i = 0; i < UnionFindTester::N; ++i) {
        result.currs[i] = osstreams[i].str();
    }

    result.gold = gold;
    return result;
}

FilePaths collectGoldFilePaths() {
    FilePaths gold_files;
    for (const auto& entry : std::filesystem::directory_iterator(kRegressionTestsDirPath)) {
        if (entry.is_regular_file()) {
            const auto& file_path = entry.path();
            if (0 == file_path.extension().compare(".gold")) {
                gold_files.push_back(file_path);
            }
        }
    }
    return gold_files;
}

TEST(UnionFind, BaseRegressionTests) {
    constexpr auto regression_inputs_count{std::size(UF_REGRESSION_INPUTS)};
    constexpr auto regression_golds_count{std::size(UF_REGRESSION_GOLDS)};

    static_assert(regression_inputs_count == regression_golds_count);

    for (auto i = 0; i < regression_inputs_count; ++i) {
        auto input{UF_REGRESSION_INPUTS[i]};
        auto gold{UF_REGRESSION_GOLDS[i]};

        auto result = Process(input, gold);
        std::for_each(result.currs.begin(), result.currs.end(), [&](const auto& curr) {
            ASSERT_EQ(curr, result.gold);
        });
    }
}

TEST(UnionFind, ExtendedRegressionTests) {
    if (!kRegressionTestsDirPath[0]) {
        GTEST_SKIP();
    }

    FilePaths gold_files;
    try {
        gold_files = collectGoldFilePaths();
        if (gold_files.empty()) {
            throw std::invalid_argument("");
        }
    } catch (std::exception& e) {
        std::cerr << "Error: could not collect gold file paths, "
                     "check provided path to the regression directory" << std::endl;
        ASSERT_TRUE(false);
    }

    for (const auto& gold_file : gold_files) {
        auto input_file{gold_file};
        input_file.replace_extension("");

        std::ifstream gold_fs{gold_file.c_str()};
        std::ifstream input_fs{input_file.c_str()};

        std::string gold(std::istreambuf_iterator<char>{gold_fs}, {});
        std::string input(std::istreambuf_iterator<char>{input_fs}, {});

        auto result = Process(input, gold);
        std::for_each(result.currs.begin(), result.currs.end(), [&](const auto& curr) {
            ASSERT_EQ(curr, result.gold);
        });
    }
}

} // namespace uf

int main(int argc, char* argv[]) {
    std::string argv_;
    for (auto i = 0; i < argc; ++i) {
        argv_.append(argv[i]).append(" ");
    }

    if (auto p = argv_.find(uf::kRegressionTestsFlag); p != std::string::npos) {
        std::string regression_tests_dir_path{};

        auto p1 = argv_.find(R"(")", p);
        auto p2 = argv_.find(R"(" )", p1 + 1);

        if (p1 == std::string::npos || p2 == std::string::npos) {
            std::cerr << "Error: cannot parse parameter for flag '--regressionDataDir': "
                         "check '\"' is present before and after the parameter value" << std::endl;
            uf::kRegressionTestsDirPath[0] = '\1';
        } else {
            regression_tests_dir_path = argv_.substr(p1 + 1, p2 - p1 - 1);
            if (regression_tests_dir_path.size() >= uf::kBufferSize) {
                std::cerr << "Error: cannot parse parameter for flag '--regressionDataDir': "
                             "too long path provided." << std::endl;
                throw std::invalid_argument("Check provided regression directory path");
            }
            std::copy_n(regression_tests_dir_path.begin(), regression_tests_dir_path.size(), uf::kRegressionTestsDirPath);
            uf::kRegressionTestsDirPath[regression_tests_dir_path.size()] = '\0';
        }
    }

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
