#include <iostream>
#include <cstring>
#include <set>
#include <cstdio>

using namespace std;

set<int> candidate[9][9];
int ans[9][9];
bool checkBox[9][10];
bool checkXLine[9][10];
bool checkYLine[9][10];

int getPosition(int x, int y) {
	if (0 <= x && x <= 2 && 0 <= y && y <= 2)	return 0;
	else if (3 <= x && x <= 5 && 0 <= y && y <= 2)	return 1;
	else if (6 <= x && x <= 8 && 0 <= y && y <= 2)	return 2;
	else if (0 <= x && x <= 2 && 3 <= y && y <= 5)	return 3;
	else if (3 <= x && x <= 5 && 3 <= y && y <= 5)	return 4;
	else if (6 <= x && x <= 8 && 3 <= y && y <= 5)	return 5;
	else if (0 <= x && x <= 2 && 6 <= y && y <= 8)	return 6;
	else if (3 <= x && x <= 5 && 6 <= y && y <= 8)	return 7;
	else if (6 <= x && x <= 8 && 6 <= y && y <= 8)	return 8;
}

bool func(int pos) {
	int x = pos % 9;
	int y = pos / 9;
	if (pos == 81) {
		return true;
	}

	
	if (candidate[x][y].empty()) {
		if (func(++pos)) return true;
	}else {
		for (set<int>::iterator iter = candidate[x][y].begin(); iter != candidate[x][y].end(); iter++) {
			//타당한지 체크
			if (checkBox[getPosition(x, y)][*iter] == true) continue;
			if (checkXLine[y][*iter] == true)	continue;
			if (checkYLine[x][*iter] == true)	continue;

			checkBox[getPosition(x, y)][*iter] = true;
			checkXLine[y][*iter] = true;
			checkYLine[x][*iter] = true;
			ans[x][y] = *iter;

			if(func(pos + 1)) return true;

			checkBox[getPosition(x, y)][*iter] = false;
			checkXLine[y][*iter] = false;
			checkYLine[x][*iter] = false;
		}
	}

}

int main() {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			for (int i = 1; i <= 9; i++) {
				candidate[x][y].insert(i);
			}
		}
	}
	int temp;
	memset(checkBox, false, sizeof(checkBox));
	memset(checkXLine, false, sizeof(checkXLine));
	memset(checkYLine, false, sizeof(checkYLine));
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			scanf("%d", &temp);

			checkBox[getPosition(x, y)][temp] = true;
			checkXLine[y][temp] = true;
			checkYLine[x][temp] = true;
			ans[x][y] = temp;
		}
	}

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			if (ans[x][y] == 0) {
				for (int i = 1; i <= 9; i++) {
					if (checkXLine[y][i] == true)	candidate[x][y].erase(i);
					if (checkYLine[x][i] == true)	candidate[x][y].erase(i);
					if (checkBox[getPosition(x, y)][i] == true) candidate[x][y].erase(i);
				}
			}
			else {
				candidate[x][y].clear();
			}
		}
	}

	func(0);

	printf("\n");
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			printf("%d ", ans[x][y]);
			//cout << ans[x][y] << " ";
		}
		printf("\n");
		//cout << endl;
	}
}