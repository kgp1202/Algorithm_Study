#include <iostream>
#include <cstdio>
using namespace std;

int arr[10005];
int xLine[100005];
int yLine[100005];
int xNeed[10005];
int yNeed[10005];
int xCount[10005];
int yCount[10005];

int main() {
	int N, M;
	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		scanf("%d%d", &xLine[m], &yLine[m]);
		xCount[xLine[m]]++;
		yCount[yLine[m]]++;
	}

	//x = 1일떄의 count
	int xMin = 0;
	int yMin = 0;
	for (int m = 0; m < M; m++) {
		yLine[m] - 1 ? xNeed[1] += yLine[m] - 1 : xNeed[1] -= yLine[m] - 1;
	}
	xMin = xNeed[1];

	//x = 2부터 N까지의 count
	int mid = yCount[1];
	for (int y = 2; y <= N; y++) {
		xNeed[y] = xNeed[y - 1] + mid - (M - mid);
		if (xMin > xNeed[y])	xMin = xNeed[y];
		mid += yCount[y];
	}

	//y = 1일떄의 count
	for (int m = 0; m < M; m++) {
		xLine[m] - 1 ? yNeed[1] += xLine[m] - 1 : yNeed[1] -= xLine[m] - 1;
	}
	yMin = yNeed[1];

	//y = 2부터 N까지의 count
	mid = xCount[1];
	for (int y = 2; y <= N; y++) {
		yNeed[y] = yNeed[y - 1] + mid - (M - mid);
		if (yMin > yNeed[y])	yMin = yNeed[y];
		mid += xCount[y];
	}

	cout << xMin + yMin << endl;
}