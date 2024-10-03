#include <gtest/gtest.h>
#include "parser.cpp"

TEST(ParserTest, SuccessResult) {
    std::ifstream inputFile("testFile.log");

    std::vector<std::string> macAddresses = {"RA", "TA", "SA"};

    Parser parser = *new Parser(macAddresses);

    parser.parseFile(inputFile);

    std::vector<std::pair<std::string, int>> result = parser.saveResult();

    std::vector<std::pair<std::string, int>> expectedResult = {
            {"84:c5:a6:07:38:66", 28},
            {"6e:52:4e:5f:f9:eb", 51},
            {"b8:69:f4:7a:a5:93", 68},
            {"ff:ff:ff:ff:ff:ff", 98},
            {"4a:5f:99:ae:ea:99", 196},
            {"00:0c:29:65:08:ee", 3713},
            {"34:1c:f0:d2:78:5a", 7184},
            {"34:1c:f0:d3:40:a2", 7901},
            {"b8:69:f4:7a:a5:ac", 7966},
    };

    EXPECT_EQ(parser.saveResult(), expectedResult);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}