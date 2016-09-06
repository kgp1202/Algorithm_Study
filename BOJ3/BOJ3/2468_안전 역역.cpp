#include <iostream>
#include <cstring>

using namespace std;

bool map[105][105];
int arr[105][105];
int count1 = 0;

void draw(int x, int y) {
	if (map[x + 1][y]) {
		map[x + 1][y] = false;
		draw(x + 1, y);
	} 
	if (map[x][y + 1]) {
		map[x][y + 1] = false;
		draw(x, y + 1);
	}
	if (map[x][y - 1]) {
		map[x][y - 1] = false;
		draw(x, y - 1);
	}
	if (map[x - 1][y]) {
		map[x - 1][y] = false;
		draw(x - 1, y);
	}
}

void check(int x, int y) {
	if (!map[x][y])	return;

	map[x][y] = false;
	count1++;

	draw(x, y);
}

int main() {
	int N;
	cin >> N;

	int temp;
	int max = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> arr[x][y];
			if (max < arr[x][y])	max = arr[x][y];
		}
	}

	int maxCount = 0;
	for (int h = 0; h <= max; h++) {
		memset(map, false, sizeof(map));
		count1 = 0;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (arr[x][y] > h) {
					map[x][y] = true;
				}
			}
		}

		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				check(x, y);
			}
		}
		if (maxCount < count1)	maxCount = count1;
	}

	cout << maxCount;
}