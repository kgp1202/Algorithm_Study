#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int func(int n) {
	int arr[10];
	int i = 0;
	while (n != 0) {
		arr[i++] = n % 10;
		n /= 10;
	}

	int temp = 0;
	int A = 0;
	int arr2[10];
	int max = 0;
	for (int a = 0; a < i; a++) {
		for (int b = a + 1; b < i; b++) {
			A = 0;
			memcpy(arr2, arr, sizeof(int) * i);

			temp = arr2[a];
			arr2[a] = arr2[b];
			arr2[b] = temp;

			for (int k = 0; k < i; k++) {
				A += arr2[k] * pow(10.0, k);
			}
			if (A > max)	max = A;
		}
	}
	
	return max;
}

int main() {
	int N, K;
	cin >> N >> K;

	if (N / 10 == 0) {
		cout << "-1" << endl;
		return 0;
	}
	if (N % 10 == 0 && N / 10 <= 9) {
		cout << "-1" << endl;
		return 0;
	}

	for (int i = 0; i < K; i++) {
		N = func(N);
	}

	cout << N << endl;
}