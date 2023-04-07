#include <vector>
#include <unordered_map>
#include <iostream>
#include <list>

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
	std::unordered_map<int, int> nrCounter;
	std::vector<int> auxVec = arr, result;
	std::list<int> auxList;
	int value, counter;


	for (unsigned int i = 0; i < arr.size(); i++) {
		counter = 1;
		value = arr[i];
		for (unsigned int j = i + 1; j < arr.size(); j++) {
			if (value == arr[j]) {
				counter++;
			}
		}
		std::pair<int, int> nrInsert(arr[i], counter);
		nrCounter.insert(nrInsert);
	}


	for (int i = auxVec.size() - 1; i >= 0; i--) {
		value = auxVec[i];
		if (nrCounter[auxVec[i]] > n) {
			nrCounter[auxVec[i]] = nrCounter[auxVec[i]] - 1;
		}else{
			auxList.push_front(value);
		}
	}

	for (auto x : auxList) {
		result.push_back(x);
	}
	

	return {result};
}

//int main() {
//	std::vector<int> auxVec = deleteNth({ 1, 3 ,2 ,1 , 3, 2, 1, 3, 2 }, 1);;
//	for (auto x : auxVec) {
//		std::cout << x << "\t";
//	}
//	return 0;
//}