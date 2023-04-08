#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>


float find_uniq(const std::vector<float>& v)
{
    std::vector<float> result = v;
    float value, val1, val2;

    val1 = result[0];
    val2 = result[1];
    value = result[2];
    
    if (val1 == val2) {
        value = val1;
    }

    for (int i = 0; i < result.size(); i++) {
        if (result[i] != value) {
            value = result[i];
            break;
        }
    }

    return value;
}


//int main() {
//    std::cout << find_uniq(std::vector<float>{1, 2, 1, 1, 1, 1});
//    return 0;
//}