#include "Server.hpp"

void Server::parse(char *buf, int bytes) {
	string str(buf, avail_bytes);

	vector <int> vec;
	int sum = 0;
	int i = 0;

	for (i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			sum += str[i] - '0';
			vec.push_back(str[i] - '0');
		}
	}
	if (!vec.empty()) {
		cout << "sum = " << sum << "\n";
	}

	sort(vec.rbegin(), vec.rend());
	for (i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	if (!vec.empty()) {
		cout << "\nMAX = " << vec[0] << " MIN = " << vec[vec.size() - 1] << endl;
	}
}

