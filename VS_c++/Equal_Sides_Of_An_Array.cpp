#include <vector>
#include <iostream>
using namespace std;

int find_even_index(const vector <int> numbers) {
	int left = 0, right = 0;
	for (int i = 0; i < numbers.size(); i++) {
		for (int l = 0; l < i; l++) {
			left += numbers[l];
		}
		for (int r = i + 1; r < numbers.size(); r++) {
			right += numbers[r];
		}
		if (left == right) return i;
		left = right = 0;
	}
	return -1;
}

//int main() {
//	std::cout << find_even_index({ 1,2,3,4,5,6 });
//	return 0;
//}