#include <iostream>
#include <cstring>

using namespace std;

int N, M;

int input[102][102];

bool complete[102];
bool isBase[102];

int returnVal[102];
//a를 만드는데 드는 비용 조사.
bool func(int a) {
	if (isBase[a]) {
		return false;
	}

	if (complete[a]) {
		memcpy(returnVal, input[a], sizeof(returnVal));
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (input[a][i] != 0) {
				if (!func(i))	continue;
				for (int j = 0; j < N; j++) {
					input[a][j] += returnVal[j] * input[a][i];
				}
				input[a][i] = 0;
			}
		}
		complete[a] = true;
		memcpy(returnVal, input[a], sizeof(returnVal));
	}
}

int main() {
	int completeNum;
	int A, B, C;

	memset(isBase, true, sizeof(isBase));
	memset(complete, true, sizeof(complete));
	complete[0] = true;

	cin >> N >> M;

	for (int n = 0; n < M; n++) {
		cin >> A >> B >> C;

		input[A][B] = C;
		complete[A] = false;
		isBase[A] = false;
	}

	for (int n = 1; n <= N; n++) {
		func(n);
	}

	for (int i = 1; i < N; i++) {
		if (isBase[i]) {
			cout << i << " " << input[N][i] << endl;
		}
	}
}