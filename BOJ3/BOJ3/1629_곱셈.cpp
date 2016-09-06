#include <iostream>

using namespace std;

long long A, B, C;
int arr[100];
long long modNum[100];

int main() {
	cin >> A >> B >> C;

	if (B >= 2) {
		int count = 0;
		while (B != 0) {
			arr[count++] = B % 2;
			B = B / 2;
		}
		
		modNum[0] = A % C;
		for (int i = 1; i < count; i++) {
			modNum[i] = (modNum[i - 1] * modNum[i - 1]) % C;
		}

		long long ans = 1;
		for (int i = 0; i < count; i++) {
			if (arr[i] == 1) {
				ans = (ans * modNum[i]) % C;
			}
		}

		cout << ans << endl;
	}
	else {
		cout << A % C << endl;
	}
}