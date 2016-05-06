#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int arr[2005];
set<int> myset;
int N;

int func(int start, int term) {
	int value = arr[start];
	int len = 0;

	for (int i = 0; i < N; i++) {
		while (myset.find(value + term) != myset.end()) {
			len++;
			value += term;
		}
	}

	return len;
}

int main() {
	cin >> N;

	for (int n = 0; n < N; n++) {
		cin >> arr[n];
		myset.insert(arr[n]);
	}

	sort(arr, arr + N);
	int maxLen = 0;
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			temp = func(i, arr[j] - arr[i]);
			if (maxLen < temp) {
				maxLen = temp;
			}
		}
	}

	cout << maxLen;
}