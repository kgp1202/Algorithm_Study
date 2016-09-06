#include <iostream>
#include <string>
#include <math.h>

using namespace std;

char arr[12][12];

int main() {
	string str;
	cin >> str;

	int len = str.size();
	int X, Y;

	for (int i = 1; i <= sqrt(len); i++) {
		if (len % i == 0) {
			Y = i;
			X = len / i;
		}
	}

	int cnt = 0;
	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
			arr[x][y] = str.at(cnt++);
			if (cnt == len)	break;
		}
	}

	cnt = 0;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			cout << arr[x][y];
			if (cnt == len)	break;
		}
	}
	cout << endl;
}