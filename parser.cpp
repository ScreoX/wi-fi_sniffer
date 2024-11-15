#include <iostream>
#include "fstream"
#include "unordered_map"
#include "vector"
#include "algorithm"

class Parser {

public:
    explicit Parser(const std::vector<std::string>& inputMacAddresses) : macAddresses(inputMacAddresses) {}

    void parseFile(std::ifstream& file) {
        std::string tempLine;
        while(std::getline(file, tempLine)) {
            parseLine(tempLine);
        }
    }

    std::vector<std::pair<std::string, int>> saveResult() const {
        std::vector<std::pair<std::string, int>> parseResult(counterMacAddresses.begin(), counterMacAddresses.end());

        std::sort(parseResult.begin(), parseResult.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        });

        return parseResult;
    }

private:
    const std::vector<std::string> macAddresses;
    std::unordered_map<std::string, int> counterMacAddresses;

    void parseLine(const std::string& line) {
        for (const std::string& mac : macAddresses) {
            size_t index_mac = line.find(mac);
            if (index_mac != std::string::npos) {
                while (line[index_mac] != '=') {
                    index_mac++;
                }
                size_t index_comma_after_mac = line.find(',', index_mac);
                if (index_comma_after_mac != std::string::npos) {
                    std::string address;
                    for (size_t i = index_mac + 1; i != index_comma_after_mac; i++) {
                        address += line[i];
                    }
                    counterMacAddresses[address]++;
                }
            }
        }
    }
};
