#include <iostream>
#include <algorithm>

using namespace std;

int money[21];
int people[21];
int arr[1101];

int main() {
	for (int i = 0; i < 1101; i++) {
		arr[i] = 999999999;
	}
	arr[0] = 0;

	int wantedNum, cityNum;
	cin >> wantedNum >> cityNum;

	for (int cn = 0; cn < cityNum; cn++) {
		cin >> money[cn] >> people[cn];

		if (arr[people[cn]] < arr[money[cn]]) {
			arr[people[cn]] = arr[money[cn]];
		}
	}


	for (int i = 1; i < 1101; i++) {
		for (int cn = 0; cn < cityNum; cn++) {	
			if (i - people[cn] >= 0) {
				if (arr[i] > arr[i - people[cn]] + money[cn]) {
					arr[i] = arr[i - people[cn]] + money[cn];
				}
			}
		}
	}

	int shortest = 9999999999999;
	for (int i = wantedNum; i < 1101; i++) {
		if (shortest > arr[i]) {
			shortest = arr[i];
		}
	}

	cout << shortest;
}