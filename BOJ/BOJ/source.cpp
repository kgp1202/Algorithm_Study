#include <iostream>

using namespace std;

int arr[1005][1005];

int main() {
	std::ios::sync_with_stdio(false);

	int testCase;
	cin >> testCase;
	
	for (int tc = 0; tc < testCase; tc++) {
		int N, M;
		cin >> N >> M;

		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= M; y++) {
				cin >> arr[x][y];
			}
		}

		for (int x = 1; x <= N; x++) {
			arr[x][0] = 1;
		}
		for (int x = 1; x <= N; x++) {
			arr[x][M + 1] = 1;
		}
		for (int y = 1; y <= M; y++) {
			arr[0][y] = 1;
		}
		for (int y = 1; y <= M; y++) {
			arr[N + 1][y] = 1;
		}

		int temp = 0;
		bool isEnd = false;
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= M; y++) {
				if (!isEnd) {
					if (arr[x][y] == 0) {
						temp = 0;
						if (arr[x - 1][y] == 0) {
							temp++;
						}
						if (arr[x + 1][y] == 0) {
							temp++;
						}
						if (arr[x][y + 1] == 0) {
							temp++;
						}
						if (arr[x][y - 1] == 0) {
							temp++;
						}

						if (temp % 2 == 1) {
							//cout << x << y << endl;
							cout << "0" << endl;
							isEnd = true;
						}
					}
				}
			}
		}

		if (!isEnd) {
			cout << "1" << endl;
		}
	}
}