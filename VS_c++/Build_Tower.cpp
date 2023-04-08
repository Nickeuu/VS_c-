#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> towerBuilder(unsigned nFloors) {
	int starCounter = 1, whiteSpaces = 0, maxStars = nFloors * 2 - 1;
	std::string line;
	bool a;
	std::vector<std::string> result;
	whiteSpaces = nFloors - 1;
	for (int i = 0; i <= nFloors; i++) {
		a = false;
		for (int j = whiteSpaces; j >= 0; j--) {
			if (j != 0) {
				line.push_back(' ');
			}
			else {
				if (!a) {
					for (int k = starCounter; k > 0; k--) {
						line.push_back('*');
					}
					j = whiteSpaces + 1;
					a = true;
				}
			}
		}
		result.push_back(line);
		line = "";
		if (starCounter == maxStars) {
			break;
		}
		starCounter += 2;
		whiteSpaces--;
	}
	return result;
}

//int main() {
//	std::vector<std::string> result = towerBuilder(6);
//	
//	for (auto x : result) {
//		std::cout << x << std::endl;
//	}
//	return 0;
//}