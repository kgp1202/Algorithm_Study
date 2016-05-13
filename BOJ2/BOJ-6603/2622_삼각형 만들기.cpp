#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	double DN = N;
	int ans = 0;
	for (int i = DN / 3 + 1; i < DN / 2; i++) {
		int last = (N - i);
		ans += last / 2 - (last - 1) + i;
	}
	if (N % 3 == 0)	ans++;


	cout << ans << endl;
}