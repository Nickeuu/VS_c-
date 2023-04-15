#include<vector>
#include <iostream>

class Automaton
{
private:
	bool q1, q2, q3;
public:
	Automaton() {
		q2 = q3 = false;
		q1 = true;
	}
	bool read_commands(const std::vector<char>& commands) {
		for (auto x : commands) {
			if (x == '0') {
				if (q3) {
					q3 = false;
					q2 = true;
				}
				else if (q2) {
					q2 = false;
					q3 = true;
				}
			}
			else if (x == '1') {
				if (q1) {
					q1 = false;
					q2 = true;
				}else if (q3) {
					q3 = false;
					q2 = true;
				}
			}
		}
		return q2;
	}
};

//int main() {
//	auto automata = Automaton();
//	std::cout << automata.read_commands({ '1', '0', '0', '1' });
//	return 0;
//}