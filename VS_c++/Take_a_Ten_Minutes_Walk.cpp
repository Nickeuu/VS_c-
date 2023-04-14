#include<vector>
#include <iostream>

bool isValidWalk(std::vector<char> walk) {
	//your code here
	if (walk.size() != 10) return false;
	int x, y; x = y = 0;

	for (int i = 0; i < 10; i++) {
		if (walk[i] == 'n') y++;
		if (walk[i] == 's') y--;
		if (walk[i] == 'e') x++;
		if (walk[i] == 'w') x--;
	}
	if (x == 0 && y == 0)
		return true;
	else
		return false;
}

//int main() {
//	using V = std::vector<char>;
//	std::cout << isValidWalk(V{ 'n','s','n','s','n','s','n','s','n','n' });
//	return 0;
//}