#include <vector>
#include <string>
#include <iostream>


std::vector<std::string> wave(std::string y) {
	std::vector<std::string> data;
	std::string s;
	for (int i = 0; i < y.size(); i++) {
		s = y;
		if (s[i] == ' ') continue;
		s[i] = toupper(s[i]);
		data.push_back(s);
	}
	return {data};
}

//int main() {
//	std::vector<std::string> v_wave = wave("two words");
//	for (auto x : v_wave) {
//		std::cout << x << '\t';
//	}
//	return 0;
//}