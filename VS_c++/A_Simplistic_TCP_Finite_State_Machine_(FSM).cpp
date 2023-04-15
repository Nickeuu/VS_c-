#include <string>
#include <vector>
#include <iostream>

std::string traverse_TCP_states(const std::vector<std::string>& events) {
	bool closed = true;
	bool listen = false;
	bool syn_rcvd = false;
	bool syn_sent = false;
	bool established = false;
	bool close_wait = false;
	bool last_ack = false;
	bool fin_wait_1 = false;
	bool fin_wait_2 = false;
	bool closing = false;
	bool time_wait = false;

	std::string returnedString;

	for (auto x : events) {
		//Closed
		if (closed) {
			closed = false;
			if (x == "APP_PASSIVE_OPEN") {
				listen = true;
				returnedString = "LISTEN";
			}
			else if (x == "APP_ACTIVE_OPEN") {
				syn_sent = true;
				returnedString = "SYN_SENT";
			}
			else return "ERROR";
			continue;
		}
		//Listen
		if (listen) {
			listen = false;
			if (x == "RCV_SYN") {
				syn_rcvd = true;
				returnedString = "SYN_RCVD";
			}
			else if (x == "APP_SEND") {
				syn_sent = true;
				returnedString = "SYN_SENT";
			}
			else if (x == "APP_CLOSE") {
				closed = true;
				returnedString = "CLOSED";
			}
			else return "ERROR";
			continue;
		}
		//Syn_rcvd
		if (syn_rcvd) {
			syn_rcvd = false;
			if (x == "APP_CLOSE") {
				fin_wait_1 = true;
				returnedString = "FIN_WAIT_1";
			}
			else if (x == "RCV_ACK") {
				established = true;
				returnedString = "ESTABLISHED";
			}
			else return "ERROR";
			continue;
		}
		//Syn_sent
		if (syn_sent)
		{
			syn_sent = false;
			if (x == "RCV_SYN") {
				syn_rcvd = true;
				returnedString = "SYN_RCVD";
			}
			else if (x == "RCV_SYN_ACK") {
				established = true;
				returnedString = "ESTABLISHED";
			}
			else if (x == "APP_CLOSE") {
				closed = true;
				returnedString = "CLOSED";
			}
			else return "ERROR";
			continue;
		}
		//Established
		if (established)
		{
			established = false;
			if (x == "APP_CLOSE") {
				fin_wait_1 = true;
				returnedString = "FIN_WAIT_1";
			}
			else if (x == "RCV_FIN") {
				close_wait = true;
				returnedString = "CLOSE_WAIT";
			}
			else return "ERROR";
			continue;
		}
		//Fin_wait_1
		if (fin_wait_1)
		{
			fin_wait_1 = false;
			if (x == "RCV_FIN") {
				closing = true;
				returnedString = "CLOSING";
			}
			else if (x == "RCV_FIN_ACK") {
				time_wait = true;
				returnedString = "TIME_WAIT";
			}
			else if (x == "RCV_ACK") {
				fin_wait_2 = true;
				returnedString = "FIN_WAIT_2";
			}
			else return "ERROR";
			continue;
		}
		//Closing
		if (closing)
		{
			closing = false;
			if (x == "RCV_ACK") {
				time_wait = true;
				returnedString = "TIME_WAIT";
			}
			else return "ERROR";
			continue;
		}
		//Fin_wait_2
		if (fin_wait_2)
		{
			fin_wait_2 = false;
			if (x == "RCV_FIN") {
				time_wait = true;
				returnedString = "TIME_WAIT";
			}
			else return "ERROR";
			continue;
		}
		//Time_wait
		if (time_wait)
		{
			time_wait = false;
			if (x == "APP_TIMEOUT") {
				closed = true;
				returnedString = "CLOSED";
			}
			else return "ERROR";
			continue;
		}
		//Close_wait
		if (close_wait)
		{
			close_wait = false;
			if (x == "APP_CLOSE") {
				last_ack = true;
				returnedString = "LAST_ACK";
			}
			else return "ERROR";
			continue;
		}
		//Last_ack
		if (last_ack)
		{
			last_ack = false;
			if (x == "RCV_ACK") {
				closed = true;
				returnedString = "CLOSED";
			}
			else return "ERROR";
			continue;
		}
	}
	return returnedString;
}

//int main() {
//	using vs = std::vector<std::string>;
//	vs test1 = { "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN" };
//	vs test2 = { "APP_PASSIVE_OPEN",  "RCV_SYN","RCV_ACK" };
//	vs test3 = { "APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN","APP_CLOSE" };
//	vs test4 = { "APP_ACTIVE_OPEN" };
//	vs test5 = { "APP_PASSIVE_OPEN","RCV_SYN","RCV_ACK","APP_CLOSE","APP_SEND" };
//	std::cout << traverse_TCP_states(test1) << " = CLOSE_WAIT\n";
//	std::cout << traverse_TCP_states(test2) << " = ESTABLISHED\n";
//	std::cout << traverse_TCP_states(test3) << " = LAST_ACK\n";
//	std::cout << traverse_TCP_states(test4) << " = SYN_SENT\n";
//	std::cout << traverse_TCP_states(test5) << " = ERROR\n";
//}