#include <iostream>

using namespace std;

int arr[200000];

int main() {
	int n, d;
	cin >> n >> d;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[temp]++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (arr[i] > d) {
			ans++;
			arr[i] -= d - 1;
		}
	}

	cout << ans << endl;
}