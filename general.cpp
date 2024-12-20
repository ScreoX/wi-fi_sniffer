#include "parser.cpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Invalid number of arguments";
        return 1;
    }

    std::ifstream inputFile(argv[1]);

    if (!inputFile.is_open()) {
        std::cout << "Could not open the file";
        return 1;
    }

    const std::vector<std::string> macAddresses = {"RA", "TA", "SA"};

    Parser parser(macAddresses);

    parser.parseFile(inputFile);

    const std::vector<std::pair<std::string, int>> result = parser.saveResult();

    for (const auto& frame : result) {
        std::cout << frame.first << " " << frame.second << '\n';
    }

    return 0;
}
