#include <string>
#include <iostream>
#include <ctype.h>

std::string incrementString(const std::string& str)
{
    std::string stringNr = "";
    std::string stringChar;
    bool myBool = true, myBool1 = false, isdig = false;
    int nr, zeros = 0, aux = 0, aux1 = 0, counter = 0, counter1 = 0;
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            isdig = true;
            stringNr.push_back(str[i]);
            if (str[i] == '0' && myBool) {
                zeros++;
            }
            else {
                myBool = false;
            }
        }
        else {
            if (isdig) {
                stringChar += stringNr;
                zeros = 0;
                stringNr = "";
                isdig = false;
            }
            stringChar.push_back(str[i]);
        }
    }
    if (stringNr.empty()) {
        return stringChar + '1';
    }
    nr = std::stoi(stringNr);
    if (nr == 0) {
        zeros--;
        myBool1 = true;
    }
    aux = nr;
    nr++;
    aux1 = nr;
    if (!myBool1) {
        while (aux1 > 0) {
            if (aux > 0) {
                counter++;
                aux = aux / 10;
            }
            counter1++;
            aux1 = aux1 / 10;
        }
        if (counter != counter1) zeros--;
    }
    for (; zeros > 0; zeros--) {
        stringChar += '0';
    }
    stringChar += std::to_string(nr);

    return stringChar;
}

//int main() {
//    std::cout << incrementString("foo99bar99");
//    return 0;
//}