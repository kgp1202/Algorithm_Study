#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool arr[1000005];
int ans[1000005];

int check(int a) {
	//cout << a << endl;
	if (a == 1 || ans[a] == 1) {
		return 1;
	}
	else if (ans[a] == -1) {
		return -1;
	}
	else if (ans[a] == 2) {
		return -1;
	}

	int origin = a;
	int total = 0;
	int temp;
	a *= 10;
	while ((a /= 10) != 0) {
		temp = a % 10;
		total += temp * temp;
	}

	ans[origin] = 2;
	ans[origin] = check(total);
}

int main() {
	int N;
	cin >> N;

	memset(arr, true, sizeof(arr));
	for (int i = 4; i <= N; i += 2)
		arr[i] = false;
	for (int i = 3; i * i <= N; i += 2) {
		if(arr[i]){
			for (int j = 2; i * j <= N; j++) {
				arr[i * j] = false;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (arr[i] && check(i) == 1) {
			//cout << i << endl;
			printf("%d\n", i);
		}
	}
}