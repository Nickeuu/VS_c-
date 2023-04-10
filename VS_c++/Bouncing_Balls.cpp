#include <iostream>
using namespace std;

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window) {

        if (h <= 0 || bounce >= 1 || bounce <= 0 || window >= h) return -1;
        int counter = 0;

        while (window < h) {
            counter++;
            h *= bounce;
            if (h > window) counter++;
        }
        return counter;
    }
};

//int main() {
//    std::cout << Bouncingball::bouncingBall(30, 0.66, 1.5);
//    return 0;
//}