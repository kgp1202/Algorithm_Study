#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Road {
	int a;
	int b;
	int len;
};

Road road[200002];

bool func(Road x, Road y) {
	return x.len > y.len;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int cityNum, roadNum;
		scanf("%d%d", &cityNum, &roadNum);


		for (int i = 0; i < cityNum - 1; i++) {
			road[i].a = i;
			scanf("%d%d", &road[i].b, &road[i].len);
		}

		for (int i = 0; i < roadNum; i++) {
			scanf("%d%d%d", &road[cityNum - 1 + i].a, &road[cityNum - 1 + i].b, &road[cityNum - 1 + i].len);
		}

		
	}
}