#include <string>
#include <iostream>
#include <sstream>
#include <vector>


long parse_int(std::string number) {
    std::string tmp, auxStr;
    std::stringstream ss(number), ssAux;
    std::vector<std::string> words;

    bool isDelim = false;

    //Split string by whitespace and '-'

    while (std::getline(ss, tmp, ' ')) {        //get words splitted by space
        for (int i = 0; i < tmp.size(); i++) {  //go through word chars
            if (tmp[i] == '-') {                //if word has char '-'
                ssAux.str(tmp);
                isDelim = true;
                while (std::getline(ssAux, auxStr, '-')) {
                    words.push_back(auxStr);
                }
                std::stringstream().swap(ssAux);//reset stringstream
            }    
        }
        if (!isDelim) {
            words.push_back(tmp);
        }
        else {
            isDelim = false;
        }
    }   

    //End of splitting


    //Memory cleaning
    std::stringstream().swap(ss);   //reset stringstream
    std::stringstream().swap(ssAux);//reset stringstream

    long result = 0, nrAux = 0;

    

    for (int i = 0; i < words.size(); i++) {
        if (words[i] == "one") {
            result += 1;
        }else if (words[i] == "two") {
            result += 2;
        }else if (words[i] == "three") {
            result += 3;
        }else if (words[i] == "four") {
            result += 4;
        }else if (words[i] == "five") {
            result += 5;
        }else if (words[i] == "six") {
            result += 6;
        }else if (words[i] == "seven") {
            result += 7;
        }else if (words[i] == "eight") {
            result += 8;
        }else if (words[i] == "nine") {
            result += 9;
        }
        
        else if (words[i] == "ten") {
            result += 10;
        }else if (words[i] == "twenty") {
            result += 20;
        }else if (words[i] == "thirty") {
            result += 30;
        }else if (words[i] == "forty") {
            result += 40;
        }else if (words[i] == "fifty") {
            result += 50;
        }else if (words[i] == "sixty") {
            result += 60;
        }else if (words[i] == "seventy") {
            result += 70;
        }else if (words[i] == "eighty") {
            result += 80;
        }else if (words[i] == "ninety") {
            result += 90;
        }

        else if (words[i] == "eleven") {
            result += 11;
        }
        else if (words[i] == "twelve") {
            result += 12;
        }
        else if (words[i] == "thirteen") {
            result += 13;
        }
        else if (words[i] == "fourteen") {
            result += 14;
        }
        else if (words[i] == "fifteen") {
            result += 15;
        }
        else if (words[i] == "sixteen") {
            result += 16;
        }
        else if (words[i] == "seventeen") {
            result += 17;
        }
        else if (words[i] == "eighteen") {
            result += 18;
        }
        else if (words[i] == "nineteen") {
            result += 19;
        }

        else if (words[i] == "hundred") {
            if (result == 0) {
                result++;
                result *= 100;
                result--;
            }
            else {
                result *= 100;
            }
            
        }else if (words[i] == "thousand") {
            if (result == 0) {
                result++;
                result *= 1000;
                result--;
            }
            else {
                result *= 1000;
                nrAux = result;
                result = 0;
            }
        }else if (words[i] == "million") {

            result *= 1000000;
        }  
    }
    result = nrAux + result;
    
    return result;
}


int main() {
    std::cout << parse_int("one million");
    return 0;
}

//one thousand three hundred thirty seven
