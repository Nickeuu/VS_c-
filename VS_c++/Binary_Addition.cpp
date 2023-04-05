#include <cstdint>
#include <string>
#include <iostream>
#include <vector>

std::string add_binary(uint64_t a, uint64_t b) {
    uint64_t result = a + b;
    if (result == 0) return "0";
    int nr[100000], i;
    std::string resultStr;
    for (i = 0; result > 0; i++) {
        nr[i] = result % 2;
        result /= 2;
    }

    for (i = i - 1; i >= 0; i--) {
        resultStr.append(std::to_string(nr[i]));
    }

    return resultStr;
}

//int main() {
//    std::cout << add_binary(51, 12);
//    return 0;
//}