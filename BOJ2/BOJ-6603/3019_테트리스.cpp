#include <iostream>

using namespace std;

int arr[102];

int main() {
	int C, P;
	cin >> C >> P;

	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}

	int answer = 0;
	
	switch (P) {
	case 1:
		answer += C;
		if(C >= 4){
			for (int i = 0; i <= C - 4; i++) {
				if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2] && arr[i + 2] == arr[i + 3]) {
					answer++;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i <= C - 2; i++) {
			if (arr[i] == arr[i + 1]) {
				answer++;
			}
		}
		
		break;
	case 3:
		for (int i = 0; i <= C - 3; i++) {
			if (arr[i] == arr[i + 1] && arr[i + 1] + 1 == arr[i + 2]) {
				answer++;
			}
		}
		for (int i = 0; i <= C - 2; i++) {
			if (arr[i] == arr[i + 1] + 1) {
				answer++;
			}
		}
		break;
	case 4:
		for (int i = 0; i <= C - 3; i++) {
			if (arr[i] == arr[i + 1] + 1 && arr[i + 1] == arr[i + 2]) {
				answer++;
			}
		}
		for (int i = 0; i <= C - 2; i++) {
			if (arr[i] + 1 == arr[i + 1]) {
				answer++;
			}
		}
		break;
	case 5:
		for (int i = 0; i <= C - 3; i++) {
			if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
				answer++;
			}
			if (arr[i] == arr[i + 1] + 1 && arr[i + 1] + 1 == arr[i + 2]) {
				answer++;
			}
		}
		for (int i = 0; i <= C - 2; i++) {
			if (arr[i] == arr[i + 1] + 1) {
				answer++;
			}
			if (arr[i] + 1 == arr[i + 1]) {
				answer++;
			}
		}
		break;
	case 6:
		for (int i = 0; i <= C - 3; i++) {
			if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
				answer++;
			}
			if (arr[i] + 1 == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
				answer++;
			}
		}
		for (int i = 0; i <= C - 2; i++) {
			if (arr[i] == arr[i + 1]) {
				answer++;
			}
			if (arr[i] == arr[i + 1] + 2) {
				answer++;
			}
		}
		break;
	case 7:
		for (int i = 0; i <= C - 3; i++) {
			if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
				answer++;
			}
			if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2] + 1) {
				answer++;
			}
		}
		for (int i = 0; i <= C - 2; i++) {
			if (arr[i] == arr[i + 1]) {
				answer++;
			}
			if (arr[i] + 2 == arr[i + 1]) {
				answer++;
			}
		}
		break;
	}

	cout << answer << endl;
}