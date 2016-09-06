#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[305][305];
int after[305][305];
bool checkArr[305][305];

int checkNum = 0;
void check(int a, int b) {
	if (checkArr[a][b]) {
		return ;
	}else{
		checkArr[a][b] = true;
		checkNum++;
	}

	if (arr[a - 1][b] > 0)	check(a - 1, b);
	if (arr[a + 1][b] > 0)	check(a + 1, b);
	if (arr[a][b - 1] > 0)	check(a, b - 1);
	if (arr[a][b + 1] > 0)	check(a, b + 1);
}

int main() {
	int N, M;
	cin >> N >> M;
	
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> arr[n][m];
		}
	}

	int existA = 0;
	int firstA = 0, firstB = 0;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (arr[n][m] > 0) {
				existA++;
				if (firstA == 0) {
					firstA = n;
					firstB = m;
				}
			}
		}
	}

	checkNum = 0;
	check(firstA, firstB);

	if (existA != checkNum) {
		cout << 0 << endl;
		return 0;
	}

	int answer = 0;
	int exist = 0;
	do{
		answer++;
		exist = 0;
		int count = 0;
		firstA = 0;
		firstB = 0;
		for (int n = 1; n <= N; n++) {
			for (int m = 1; m <= M; m++) {
				if (arr[n][m] <= 0) continue;

				if (arr[n - 1][m] <= 0)	count++;
				if (arr[n + 1][m] <= 0)	count++;
				if (arr[n][m - 1] <= 0) count++;
				if (arr[n][m + 1] <= 0) count++;

				after[n][m] = arr[n][m] - count;
				if (after[n][m] > 0) {
					exist++;
					if (firstA == 0) {
						firstA = n;
						firstB = m;
					}
				}
				count = 0;
			}
		} 

		memcpy(arr, after, sizeof(arr));

		memset(checkArr, false, sizeof(checkArr));
		checkNum = 0;
		if (firstA == 0) {
			break;
		}
		check(firstA, firstB);

		/*
		int tempConnect = 0;
		for (int n = 1; n <= N; n++) {
			for (int m = 1; m <= M; m++) {
				if (arr[n][m] <= 0)	continue;

				if (arr[n - 1][m] > 0 || arr[n + 1][m] > 0 || arr[n][m - 1] > 0 || arr[n][m + 1] > 0) {
					tempConnect++;
				}
			}
		}*/

		if (exist != checkNum) {
			cout << answer << endl;
			return 0;
		}
	} while (exist != 0);

	cout << 0 << endl;
}