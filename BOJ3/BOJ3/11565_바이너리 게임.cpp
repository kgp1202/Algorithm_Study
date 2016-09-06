#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int aOne = 0, bOne = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a.at(i) == '1') {
			aOne++;
		}
	}
	for (int i = 0; i < b.size(); i++) {
		if (b.at(i) == '1') {
			bOne++;
		}
	}

	if (aOne % 2 == 0) {
		if (aOne >= bOne) {
			cout << "VICTORY" << endl;
		}
		else {
			cout << "DEFEAT" << endl;
		}
	}
	else {
		if (aOne + 1 >= bOne) {
			cout << "VICTORY" << endl;
		}
		else {
			cout << "DEFEAT" << endl;
		}
	}
}