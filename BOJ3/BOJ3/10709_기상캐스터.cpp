#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char arr[100][100];

int main() {
	int N, M;
	scanf("%d%d", &N, &M);

	string tempStr;
	for (int n = 0; n < N; n++) {
		cin >> tempStr;

		for (int m = 0; m < M; m++) {
			arr[n][m] = tempStr.at(m);
		}
	}

	int count = -1;
	for (int n = 0; n < N; n++) {
		count = -1;
		for (int m = 0; m < M; m++) {
			if (count == -1) {
				if (arr[n][m] == '.') {
					cout << count << " ";
				}
				else {
					count++;
					cout << count << " ";
				}
			}
			else {
				if (arr[n][m] == '.') {
					count++;
					cout << count << " ";
				}
				else {
					count = 0;
					cout << count << " ";
				}
			}
		}
		cout << endl;
	}
}