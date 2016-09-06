#include <iostream>
#include <cmath>
using namespace std;

int arr[20][11];
long long start[20][11];

long long func(long long a) {
	for (int i = 0; i < 10; i++) {
		
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		arr[1][i] = 1;

	arr[2][1] = 1;
	for(int a = 2; a <= 10; a++){
		for (int i = 2; i < 10; i++) {
			arr[a][i] = arr[a][i - 1] + arr[a - 1][i - 1];
		}
	}

	for(int i = 0; i < 10; i++)
		start[1][i] = i;
	
	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j < 10; j++) {
			start[i][j] = pow(10.0, i - 1) * j + start[i - 1][i - 2];
		}
	}

	int N;
	cin >> N;

	cout << func(N) << endl;

	if (N >= 1023) {
		cout << -1 << endl;
		return 0;
	}

	int BI, BJ;
	int sum = -1;
	int bSum = 0;
	bool isEnd = false;
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < 10; j++) {
			BI = i, BJ = j;
			bSum = sum;
			sum += arr[i][j];
			if (sum >= N) {
				isEnd = true;
				break;
			}
		}
		if (isEnd) break;
	}

	//cout << BI << " " << BJ << " " << N - bSum - 1 << endl;


	long long temp = start[BI][BJ];
	int count = N - bSum - 1;
	for (int i = 0; i < count; i++) {
		temp = func(temp);
	}
	cout << temp << endl;
}