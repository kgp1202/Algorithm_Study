#include <iostream>
#include <string.h>
using namespace std;

int arr[10112][10112];

int main() {
	int testCase;
	cin >> testCase;

	int N;
	for (int tc = 0; tc < testCase; tc++) {
		cin >> N;

		int max = 0;
		int x, y;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			x += 11;
			y += 11;
			for (int a = x - 11; a <= x; a++) {
				for (int b = y - 11; b <= y; b++) {
					arr[a][b]++;
					if (max < arr[a][b])	max = arr[a][b];
				}
			}
		}

		cout << max << endl;

		for (int i = 0; i < 10112; i++)
			memset(arr + i * 10112, 0, 10112);
		//memset(arr, 0, 10112* 10112);
	}
}