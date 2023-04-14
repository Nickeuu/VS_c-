#include <vector>
#include <iostream>


long queueTime(std::vector<int> customers, int n) {
	long time = 0;
	bool myBool = true;
	if (customers.empty()) return 0;
	std::vector<int> auxVec1 = customers;
	std::vector<int> auxVec2 = customers;
	while (myBool) {
		for (int i = 0; i < n; i++) {
			try
			{
				if (auxVec1.at(i)) {
					auxVec2[i] = auxVec1[i] - 1;
				}
			}
			catch (const std::exception& e)
			{
				break;
			}
		}
		time++;
		auxVec1.clear();
		for (int i = 0; i < auxVec2.size(); i++) {
			if (auxVec2[i] != 0) {
				auxVec1.push_back(auxVec2[i]);
			}
		}
		auxVec2 = auxVec1;
		if (auxVec1.empty()) myBool = false;
	}
	return time;
}

//int main() {
//	std::cout << queueTime(std::vector<int>{1, 2, 3, 4, 5}, 100);
//	return 0;
//}