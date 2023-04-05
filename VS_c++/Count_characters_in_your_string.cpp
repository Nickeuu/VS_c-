#include <map>
#include <string>
#include <iostream>

std::map<char, unsigned> count(const std::string& string) {
    std::map<char, unsigned> result;
    std::map<char, unsigned>::iterator it;
    if (string.size() == 0) return {};
    for (int i = 0; i < string.size(); i++) {       //get through each element
        unsigned count = 0;
        it = result.find(string[i]);

        if (it != result.end()) {                   //check if we allready counted one element
            continue;                               //if yes go to next element to check
        }

        for (int j = i; j < string.size(); j++) {   //compare element with eachother

            if (string[i] == string[j]) {
                count++;
            }
        }
        //add the pair with the element and the count of it
        result.insert(std::pair<char, unsigned>(string[i], count));
        std::cout << result.at(string[i]) << "\t";
    }
    return { result };
}

int main() {
    count("aba");
    return 0;
}