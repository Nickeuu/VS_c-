#include <cinttypes>
#include <list>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

struct PeakData {
    vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int>& v) {
    PeakData result;
    vector<int> myVec(1);
    myVec[0] = 0;
    if (v.size() == 0) return result;

    int curPos = 0, curPeak = 0;
    bool myVal = false;

    //traverse vector and save diff as -1 ; 0 ; 1
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) myVec.push_back(-1);
        else if (v[i] > v[i - 1]) myVec.push_back(1);
        else myVec.push_back(0);
    }

    for (int i = 0; i < v.size(); i++) {
        if (myVec[i] == 1 && myVal == false) {
            myVal = true;
            curPos = i;
            curPeak = v[i];
        }
        else if (myVec[i] == 1 && myVal == true) {
            curPos = i;
            curPeak = v[i];
        }
        else if (myVec[i] == -1 && myVal == true) {
            result.peaks.push_back(curPeak);
            result.pos.push_back(curPos);
            myVal = false;
        }
    }


    return result;
}

int main() {
    PeakData actual;
    actual = pick_peaks(std::vector<int> {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 5, 5});
    for (int i = 0; i < actual.peaks.size(); i++) {
        cout << actual.pos[i] << endl << actual.peaks[i] << endl;
    }
    return 0;
}