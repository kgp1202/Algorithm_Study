#include <iostream>
using namespace std;
int main() {
	char buffer[588896];
	int cur = 0;
	int N;
	cin >> N;

	for (int i = N; i > 0; i--) {
		int maxPos = 100000;
		while (0 == i / maxPos)
			maxPos /= 10;

		while (0 != maxPos) {
			buffer[cur++] = '0' + i % (maxPos * 10) / maxPos;
			maxPos /= 10;
		}
		buffer[cur++] = '\n';
	}
	buffer[cur] = '\0';
	cout << buffer;
	return 0;
}