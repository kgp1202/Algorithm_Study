#include <cstdio>
#include <cstring>
int c, p;
int arr[102];
int temp[4];

int solve(char* a) {
	int len = strlen(a);
	int ans = 0;

	for (int i = 0; i < len; i++) {
		temp[i] = a[i] - '0';
	}

	bool correct = true;
	for (int i = 0; i + len <= c; i++) {
		int addN = arr[i] - temp[0];
		correct = true;
		for (int k = 0; k < len; k++) {
			if (arr[i + k] != temp[k] + addN) {
				correct = false;
			}
		}
		if (correct)	ans++;
	}

	return ans;
}


int main() {
	scanf("%d %d", &c, &p);
	for (int i = 0; i<c; ++i) scanf("%d", &arr[i]);
	switch (p) {
	case 1:
		printf("%d\n", solve("0") + solve("0000"));
		break;
	case 2:
		printf("%d\n", solve("00"));
		break;
	case 3:
		printf("%d\n", solve("001") + solve("10"));
		break;
	case 4:
		printf("%d\n", solve("100") + solve("01"));
		break;
	case 5:
		printf("%d\n", solve("000") + solve("01") + solve("101") + solve("10"));
		break;
	case 6:
		printf("%d\n", solve("000") + solve("00") + solve("011") + solve("20"));
		break;
	case 7:
		printf("%d\n", solve("000") + solve("02") + solve("110") + solve("00"));
		break;
	}
	return 0;
}