#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int max = 1;
	int increase = 1;
	int decrease = 1;
	int now;
	int before;
	scanf("%d", &before);
	for (int i = 1; i < N; i++) {
		scanf("%d", &now);

		if (before < now) {
			increase++;
			if (max < increase)	max = increase;
			decrease = 1;
		}
		else if (before > now) {
			decrease++;
			if (max < decrease)	max = decrease;
			increase = 1;
		}
		else if (before == now) {
			decrease++;
			increase++;
			if (max < decrease)	max = decrease;
			if (max < increase)	max = increase;
		}

		before = now;
	}

	cout << max << endl;
}