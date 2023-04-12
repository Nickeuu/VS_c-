#include <vector>
#include <iostream>

std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result;
    if (n == 0) return { result };
    result = signature;
    if (n == 2) {
        result.pop_back();
        return { result };
    }
    else if (n == 1) {
        result.pop_back();
        result.pop_back();
        return { result };
    }
    int res = 0;
    for (int i = 3; i < n; i++) {
        res = result[i - 1] + result[i - 2] + result[i - 3];
        result.push_back(res);
    }
    return { result };
}

//int main() {
//    std::vector<int> result = tribonacci({ 1, 1, 1 }, 4);
//    for (auto x : result) {
//        std::cout << x << std::endl;
//    }
//    return 0;
//}