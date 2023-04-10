#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>


size_t duplicateCount(const char* in)
{
    int count = 0;
    std::string myString = in;
    std::vector<char> myVector;
    std::vector<char>::iterator it;

    std::transform(myString.begin(), myString.end(), myString.begin(), [](unsigned char c) { return std::tolower(c); });

    for (int i = 0; i < myString.size(); i++) {
        it = std::find(myVector.begin(), myVector.end(), myString[i]);
        if (it != myVector.end()) {
            continue;
        }
        for (int j = i + 1; j < myString.size(); j++) {
            if (myString[i] == myString[j]) {
                count++;
                myVector.push_back(myString[i]);
                break;
            }
        }
    }
    return count;
}

//int main() {
//    std::cout << duplicateCount("aAabaabaaabaaa11");
//    return 0;
//}
