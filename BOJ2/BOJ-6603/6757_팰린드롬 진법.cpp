#include <iostream>
#include <math.h>
#include <set>
#include <string.h>

using namespace std;

int arr[320];
set<int> mySet;
int candidate[10000000];

int main() {
	int X;
	cin >> X;

	if (X == 2)
		return 0;

	int cnt2 = 0;
	int cnt = 0;
	for (int i = 1; i <= sqrt(X); i++) {
		if (X % i == 0) {
			if (X / i != 2) {
				candidate[cnt2] = (X / i) - 1;
				cnt2++;
			}
		}
	}

	cnt = 0;
	int temp = 0;
	bool isCorrect = true;
	for (int i = 0; i < cnt2; i++) {
		temp = X;
		int d = candidate[i];
		while (temp / d != 0) {
			arr[cnt] = temp % d;
			temp = temp / d;
			cnt++;
		}
		arr[cnt] = temp;
		cnt++;

		for (int i = 0; i <= cnt / 2; i++) {
			if (arr[i] != arr[cnt - 1 - i]) {
				isCorrect = false;
				break;
			}
		}

		if (isCorrect)	mySet.insert(d);

		memset(arr, 0, 32);
		isCorrect = true;
		cnt = 0;
	}

	for (int d = 2; d <= sqrt(X); d++) {
		temp = X;
		while (temp / d != 0) {
			arr[cnt] = temp % d;
			temp = temp / d;
			cnt++;
		}
		arr[cnt] = temp;
		cnt++;

		for (int i = 0; i <= cnt / 2; i++) {
			if (arr[i] != arr[cnt - 1 - i]) {
				isCorrect = false;
				break;
			}
		}

		if (isCorrect)	mySet.insert(d);
		
		memset(arr, 0, 100);
		isCorrect = true;
		cnt = 0;
	}

	for (set<int>::iterator iter = mySet.begin(); iter != mySet.end(); iter++) {
		cout << *iter << endl;
	}
}