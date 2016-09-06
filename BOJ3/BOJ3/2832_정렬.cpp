#include <iostream>

using namespace std;

int pos[100003];

int main() {
	int N;
	cin >> N;

	for (int n = 1; n <= N; n++) {
		cin >> pos[n];
	}

	int temp = 0;
	int num = 1;
	int start = 1;
	for (int i = 1; i < N; i++) {
		if (pos[i] > pos[i + 1]) {
			num++;
		}
		else {
			if (num >= 2) {
				for (int k = 0; k < num / 2; k++) {
					temp = pos[start + k];
					pos[start + k] = pos[start + num - k - 1];
					pos[start + num - k - 1] = temp;
				}
				num = 1;
				start = i + 1;
			}
		}
	}
	if (num >= 2) {
		for (int k = 0; k < num / 2; k++) {
			temp = pos[start + k];
			pos[start + k] = pos[start + num - k - 1];
			pos[start + num - k - 1] = temp;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << pos[i] << " ";
	}
}