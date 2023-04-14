#include <string>
#include <iostream>


std::string encrypt(std::string text, int n)
{
    std::string result;
    std::string aux = text;


    for (int j = 0; j < n; j++)
    {
        //Get odds
        for (int i = 1; i < aux.size(); i += 2) {
            result += aux[i];
        }
        //Get evens
        for (int i = 0; i < aux.size(); i += 2) {
            result += aux[i];
        }
        aux = result;
        result = "";
    }

    return aux;
}

std::string decrypt(std::string encryptedText, int n)
{
    std::string result;
    std::string aux = encryptedText;

    for (int j = 0; j < n; j++)
    {
        int size = encryptedText.size();
        int half = size / 2;
        int odds = 0;
        int evens = half;

        while (evens < size)
        {
            result.push_back(aux[evens]);
            if (odds < half) {
                result.push_back(aux[odds]);
                odds++;
            }
            evens++;
        }
        aux = result;
        result = "";
    }

    return aux;
}

//int main() {
//    std::cout << encrypt("This is a test!", 1) << std::endl;
//    std::cout << decrypt(" Tah itse sits!", 3);
//    return 0;
//}