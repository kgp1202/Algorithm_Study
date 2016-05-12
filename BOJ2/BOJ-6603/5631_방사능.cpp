#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

class Point {
public:
	int x;
	int y;
	Point() {}
};

Point point[200100];
float distanceR1[200000];
float distanceR2[200000];

int main() {
	int count = 0;
	int N = 1;
	scanf("%d", &N);

	while(N != 0){
		for (int i = 0; i < N; i++) {
			//cin >> point[i].x >> point[i].y;
			scanf("%d%d", &point[i].x, &point[i].y);
		}

		int ax, ay, bx, by, Q;
		//cin >> ax >> ay >> bx >> by >> Q;
		scanf("%d%d%d%d%d", &ax, &ay, &bx, &by, &Q);

		for (int i = 0; i < N; i++) {
			distanceR1[i] = sqrt((ax - point[i].x)*(ax - point[i].x) + (ay - point[i].y)*(ay - point[i].y));
			distanceR2[i] = sqrt((bx - point[i].x)*(bx - point[i].x) + (by - point[i].y)*(by - point[i].y));
		}

		sort(distanceR1, distanceR1 + N);
		sort(distanceR2, distanceR2 + N);

		count++;
		printf("Case %d:\n", count);

		int R1, R2;
		int temp1, temp2;
		int answer;
		for(int q = 0; q < Q; q++){
			scanf("%d%d", &R1, &R2);
			temp1 = upper_bound(distanceR1, distanceR1 + N, R1) - distanceR1;
			temp2 = upper_bound(distanceR2, distanceR2 + N, R2) - distanceR2;

			answer = N - (temp1 + temp2);
			if (answer < 0)	printf("0\n");
			else
			{
				printf("%d\n", answer);
			}
		}

		scanf("%d", &N);
	}
}
