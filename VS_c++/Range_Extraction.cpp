#include <string>
#include <vector>
#include <iostream>

std::string range_extraction(std::vector<int> args) {
    std::string result;
    bool midEl = false;
    //result.append(std::to_string(args[0]));

    //go through array
    for (int i = 1; i < args.size(); i++) {
        if (args[i] == args[i - 1] + 1) {
            if (args[i] == args[i + 1] - 1) {    //middle element x-1 | elem x | x+1
                if (i == 1) {
                    result.append(std::to_string(args[0]));
                }
                if (!midEl) {
                    result.append("-");
                    midEl = true;
                }
            }
            else {                            //x+1 is not 1 off
                if (i == 1) {
                    result.append(std::to_string(args[0]) + ',');
                }
                if (i != args.size() - 1) {
                    result.append(std::to_string(args[i]) + ',');
                }
                else {
                    result.append(std::to_string(args[i]));
                }
                midEl = false;
            }
        }
        else {
            if (i == 1) {
                result.append(std::to_string(args[0]) + ',');
            }
            if (i != args.size() - 1) {
                if (args[i] == args[i + 1] - 1 && args[i] == args[i + 2] - 2) {
                    result.append(std::to_string(args[i]));
                }
                else {
                    result.append(std::to_string(args[i]) + ',');
                }

            }
            else {
                //if is last element of the vector don't add ,
                result.append(std::to_string(args[i]));
            }

        }
    }
    return result;
}

//int main() {
//    std::cout << range_extraction({ -10, -8, -7, -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20 });
//    return 0;
//}