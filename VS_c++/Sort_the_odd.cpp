#include <vector>
#include <list>
#include <iostream>


class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        std::list<int> orderedOdds;
        std::vector<int> result = array;
        std::vector<int> oddLocations;

        for (int i = 0; i < result.size(); i++) {
            if (result[i] % 2 != 0) {
                oddLocations.push_back(i);
                orderedOdds.push_back(result[i]);
            }
        }
        orderedOdds.sort();
        for (int i = 0; i < oddLocations.size(); i++) {
            result[oddLocations[i]] = orderedOdds.front();
            orderedOdds.pop_front();
        }

        return { result };
    }
};

//int main() {
//    Kata kata;
//    std::vector<int> actual = kata.sortArray({ 5, 3, 2, 8, 1, 4 });
//    for (auto x : actual) {
//        std::cout << x << ' ';
//    }
//    return 0;
//}