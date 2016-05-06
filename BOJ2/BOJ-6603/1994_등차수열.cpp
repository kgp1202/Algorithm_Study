#include <iostream>

using namespace std;

bool arr[105];

void change(bool* a) {
	
}

int main() {
	int switchNum, studentNum;
	cin >> switchNum;

	for (int s = 1; s <= switchNum; s++) {
		cin >> arr[s];
	}

	cin >> studentNum;

	int gender, num, i, k;
	for (int s = 0; s < studentNum; s++) {
		cin >> gender >> num;

		if (gender == 1) {
			i = 1;
			while (num * i <= switchNum) {
				arr[num * i] ^= 1;
				i++;
			}
		}
		else {
			arr[num] ^= 1;
			k = 1;
			while (num - k > 0 && num + k <= switchNum) {
				if (arr[num - k] == arr[num + k]) {
					arr[num - k] ^= 1;
					arr[num + k] ^= 1;
					k++;
				}
				else {
					break;
				}
			}
		}
	}
	for (int j = 1; j <= switchNum; j++){		cout<< arr[j];
		if (j == 20 || j == 40 || j == 60 || j == 80) {
			cout << endl;
		}
		else {
			cout << " ";		}
	}
}