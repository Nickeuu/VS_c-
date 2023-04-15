#include <string>
#include <vector>
#include <iostream>

//Working on visual studio but not in CodeWars


std::string encoder(const std::string& data)
{
    std::vector<std::string> dictionary;
    std::vector<std::string>::iterator it;
    std::vector<std::string>::iterator it2;
    std::string output;
    std::string value;

    dictionary.push_back("");

    for (unsigned long i = 0; i < data.size(); i++) {
        value = data[i];
        it = std::find(dictionary.begin(), dictionary.end(), value);
        if (it == dictionary.end()) {
            output += std::to_string(0) + value;
            dictionary.push_back(value);
        }
        else {
            do
            {
                i++;
                it2 = std::find(dictionary.begin(), dictionary.end(), value);
                value += data[i];
                it = std::find(dictionary.begin(), dictionary.end(), value);
            } while (it != dictionary.end());
            output += std::to_string(it2 - dictionary.begin()) + data[i];
            dictionary.push_back(value);
        }

    }
    return output;
}

std::string decoder(const std::string& data)
{
    std::vector<std::string> dictionary;
    std::string output;
    dictionary.push_back("");
    for (unsigned long i = 0; i < data.size(); i++) {
        if (data[i] == '0') {
            i++;
            std::string myStr = "";
            myStr += data[i];
            dictionary.push_back(myStr);
            output += data[i];
        }
        else {
            std::string myStr = "";
            while (isdigit(data[i])) {
                myStr += data[i];
                i++;
            }
            int index = std::stoi(myStr);
            output += dictionary[index] + data[i];
            myStr = dictionary[index] + data[i];
            dictionary.push_back(myStr);
        }
    }
    return output;
}

//int main() {
//    std::string file = "ABCDDEFGABCDEDBBDEAAEDAEDCDABC";
//    std::string encoded = encoder(file);
//    std::string decoded = decoder(encoded);
//    std::cout << encoded << std::endl << decoded;
//    return 0;
//}