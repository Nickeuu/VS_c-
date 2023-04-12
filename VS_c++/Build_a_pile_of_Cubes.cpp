#include <iostream>


class ASum
{
public:
	static long long findNb(long long m) {
		long long output = 1;
		long long check = 0;
		while (check <= m)
		{
			check += output * output * output;
			if (check == m) return output;
			output++;
		}
		return -1;
	}
};

//int main() {
//	std::cout << ASum::findNb(135440716410000);//4824
//	return 0;
//}