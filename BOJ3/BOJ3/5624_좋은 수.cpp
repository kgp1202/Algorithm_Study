#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int N;
int arr[5002];
set<int> mSet;

int main() {
	mSet = set<int>();
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%d", &arr[n]);
	}

	int ans = 0;
	int temp;
	for (int n = 0; n < N - 1; n++) {
		for (int i = 0; i <= n; i++) {
			mSet.insert(arr[n] + arr[i]);
		}

		for (int i = 0; i <= n; i++) {
			if (mSet.find(arr[n + 1] - arr[i]) != mSet.end()) {
				ans++;
				break;
			}
		}
	}

	printf("%d", ans);
}