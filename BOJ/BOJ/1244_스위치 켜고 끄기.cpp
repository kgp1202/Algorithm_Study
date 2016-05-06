#include <iostream>

using namespace std;

bool arr[105];

int main() {
	int switchNum, studentNum;
	cin >> switchNum;

	for (int s = 0; s < switchNum; s++) {
		cin >> arr[s];
	}

	cin >> studentNum;

	int gender, num, i,k;
	for (int s = 0; s < studentNum; s++) {
		cin >> gender >> num;
	
		if (gender == 1) {
			i = 1;
			while (num * i < switchNum) {
				arr[num * i] = arr[num * i] ^ 0;
				i++;
			}
		}
		else {
			k = 1;
			while (num - k >= 0 && num + k < switchNum) {
				if (arr[num - k] == arr[num + k]) {
					arr[num - k] = arr[num - k] ^ 0;
					arr[num + k] = arr[num + k] ^ 0;
					k++;
				}
				else {
					break;
				}
			}
		}

		for (int i = 0; i < switchNum; i++)
			cout << arr[i] << " ";
	}
}