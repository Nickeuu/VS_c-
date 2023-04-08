#include <vector>
#include <iostream>
#include <cmath>

std::vector<unsigned int> sumDigPow(unsigned int a, unsigned int b) {
	std::vector<unsigned int> result;
	for (unsigned int i = a; i <= b; i++) {
		if (i < 10) {
			result.push_back(i);
			continue;
		}
		unsigned int auxInt = i, counter = 1, auxVal = 0;
		std::vector<unsigned int> auxVec;
		//split number in peaces
		while (auxInt > 0) {
			auxVec.push_back(auxInt % 10);
			auxInt /= 10;
		}
		for (int j = auxVec.size() - 1 ; j >= 0; j--) {
			auxVal += pow(auxVec[j], counter);
			counter++;
		}
		if (auxVal == i) {
			result.push_back(i);
		}

	}
	//your code here
	return { result };
}

//int main() {
//	std::vector<unsigned int> result = sumDigPow(1, 100);
//	for (auto x : result) {
//		std::cout << x << std::endl;
//	}
//	return 0;
//}