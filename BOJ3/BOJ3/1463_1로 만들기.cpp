#include <iostream>
#include <cstring>
using namespace std;

int DP[3000002];
int main() {
	int N;

	memset(DP, 60000, sizeof(DP));
	cin >> N;
	DP[1] = 0;
	for (int i = 1; i <= N; i++) {
		if (DP[i + 1] > DP[i] + 1) {
			DP[i + 1] = DP[i] + 1;
		}
		if (DP[2 * i] > DP[i] + 1) {
			DP[2 * i] = DP[i] + 1;
		}
		if (DP[3 * i] > DP[i] + 1) {
			DP[3 * i] = DP[i] + 1;
		}
	}

	cout << DP[N];
}