#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int main()
{
    std::vector<std::string> zips = {"PO12345",
                                     "PO 12345",
                                     "PZ973ND",
                                     "WE20456"};
        std::regex r(R"([(PO)|(PZ)]\D?\s?\d{3,5}[A-Z]?[A-Z]?)");
        for (auto &el : zips) {
            std::smatch m;
            if (std::regex_match(el, m, r)) {
                std::cout << "zip is valid: " << el << std::endl;
            } else {
                std::cout << "error: invalid zip:" << el << std::endl;
            }
        }
    return 0;
}
