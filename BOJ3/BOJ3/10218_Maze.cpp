#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char map[11][11];
bool route[11][11];
int way[11];
int s = 0;
int num = 0;
int N, M;

bool go(int wayNum) {
	memset(route, false, sizeof(route));
	int tempNum = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (route[i][j] == true) {
				tempNum++;
				continue;
			}
			if (map[i][j] == '#')	continue;

			int x = i, y = j;
			for (int w = 0; w < wayNum; w++) {
				switch (way[w]) {
				case 0:			//down
					while (map[x][y] == '.') {
						route[x][y] = true;
						y++;
					}
					break;
				case 1:			//UP
					while (map[x][y] == '.') {
						route[x][y] = true;
						y--;
					}
					break;
				case 2:			//LEFT
					while (map[x][y] == '.') {
						route[x][y] = true;
						x--;
					}
					break;
				case 3:
					while (map[x][y] == '.') {
						route[x][y] = true;
						x++;
					}
					break;
				}

				if (map[x][y] == '#')	continue;
				if (map[x][y] == 'O') {
					tempNum++;
					break;
				}
			}
			if (map[x][y] == '#')	return false;
		}
	}

	return true;
}

bool curcular(int wayNum) {
	if (wayNum > 10)	return false;

	for (int i = 0; i < 4; i++) {
		way[wayNum] = i;
		if (curcular(wayNum + 1)) return true;
		if (go(wayNum)) {
			return true;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d%d", &N, &M);

		char temp;
		for (int n = 0; n < N; n++) {
			scanf("%s", map[n]);
			for (int m = 0; m < M; m++) {
				if (map[n][m] == '.')	num++;
			}
		}

		int wayNum;
		bool isEnd = false;
		curcular(1);

		if (isEnd) {
			for (int i = 0; i < wayNum; i++) {
				switch (way[i]) {
				case 0:
					printf("D");
					break;
				case 1:
					printf("U");
					break;
				case 2:
					printf("L");
					break;
				case 3:
					printf("R");
					break;
				}
			}
			printf("\n");
		}
		else {
			printf("XHAE\n");
		}

	}
}