#include <vector>
#include <iostream>

std::vector<int> move_zeroes(const std::vector<int>& input) {
    std::vector<int> result;
    int zeroCounter = 0;
    for (auto x : input) {
        if (x == 0) {
            zeroCounter++;
        }
        else {
            result.push_back(x);
        }
    }
    for (int i = 0; i < zeroCounter; i++) {
        result.push_back(0);
    }
    return { result };
}

//int main() {
//    std::vector<int> res;
//    res = move_zeroes(std::vector<int>{1, 2, 0, 1, 0, 1, 0, 3, 0, 1});
//    for (int i = 0; i < res.size(); i++) {
//        std::cout << res[i] << " ";
//    }
//    return 0;
//}