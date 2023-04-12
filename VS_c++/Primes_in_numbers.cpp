#include <string>
#include <vector>
#include <iostream>


class PrimeDecomp
{
public:
    static std::string factors(int lst) {
        int prime = 2, pow = 1, nr = lst;
        std::vector<int> primes;
        std::string result;

        //get primes driver
        while (nr != 1) {
            if (nr % prime == 0) {
                primes.push_back(prime);
                nr /= prime;
            }
            else {
                prime++;
            }
        }

        //string driver
        for (int i = 1; i < primes.size(); i++) {
            if (primes[i] == primes[i - 1]) {
                pow++;
            }
            else {
                if (pow == 1) {
                    result.append("(");
                    result.append(std::to_string(primes[i - 1]));
                    result.append(")");
                }
                else {
                    result.append("(");
                    result.append(std::to_string(primes[i - 1]));
                    result.append("**");
                    result.append(std::to_string(pow));
                    result.append(")");
                    pow = 1;
                }
            }
            if (i == primes.size() - 1) {
                if (pow == 1) {
                    result.append("(");
                    result.append(std::to_string(primes[i]));
                    result.append(")");
                }
                else {
                    result.append("(");
                    result.append(std::to_string(primes[i]));
                    result.append("**");
                    result.append(std::to_string(pow));
                    result.append(")");
                    pow = 1;
                }
            }
        }
        if (result.size() == 0) {
            result.append("(");
            result.append(std::to_string(lst));
            result.append(")");
        }
        
        return result;
    }
};


//int main() {
//    PrimeDecomp primeDecomp;
//    std::cout << primeDecomp.factors(7919);
//    return 0;
//}