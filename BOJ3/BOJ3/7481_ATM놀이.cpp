#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
		int a, b, wanted;
		bool swap = false;
		cin >> a >> b >> wanted;
		
		if (wanted == 0) {
			cout << "0 0\n";
			continue;
		}

		if (a < b) {
			swap = true;
			int temp = a;
			a = b;
			b = temp;
		}

		if (b > wanted) {
			cout << "Impossible" << endl;
		}
		else if (a > wanted) {
			if(wanted % b != 0)
				cout << "Impossible" << endl;
			else {
				swap ? printf("%d 0\n", wanted / b) : printf("0 %d\n", wanted / b);
			}
		}
		else {
			bool arr[10005];
			memset(arr, false, sizeof(arr));

			int N = wanted / a;
			int startN = wanted % a;
			bool isEndFor = false;

			for (int n = 0; n <= N; n++) {

				int temp2 = (startN + a * n) % b;
				if (temp2 == 0) {
					swap ? printf("%d %d\n", (startN + a * n) / b, N - n) : printf("%d %d\n", N - n, (startN + a * n) / b);
					break;
				}
				else {
					if (arr[temp2]) {
						cout << "Impossible\n";
						break;
					}
					else {
						arr[temp2] = true;
					}
				}

				if (n == N) {
					isEndFor = true;
				}
			}

			if (isEndFor == true) {
				cout << "Impossible\n";
			}
		}
	}
}