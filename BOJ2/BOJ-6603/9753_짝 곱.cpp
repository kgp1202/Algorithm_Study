#include <iostream>

using namespace std;

int main() {
	int arr2[6000];
	int arr[51000];
	int k = 2;
	for (int i = 0; i < 51000; i++) {
		arr[i] = i;
	}

	int a = 0;
	int j = 0;
	int temp;
	for (int i = 2; i < 51000; i++) {
		if (arr[i] != 0) {
			arr2[a] = i;
			a++;

			temp = i * 2;
			while (temp < 51000) {
				arr[temp] = 0;
				temp += i;
			}
		}
	}

	int T, input;
	cin >> T;


	for (int t = 0; t < T; t++) {
		cin >> input;

		int temp2;
		int smallest = 99999999999;
		int x = 5200;
		int y = 0;
		while (x != y) {
			if (arr2[x] * arr2[y] < input) {
				y++;
			}
			else {
				if (smallest > arr2[x] * arr2[y]) {
					smallest = arr2[x] * arr2[y];
				}
				x--;
			}
		}

		cout << smallest << endl;
	}
}