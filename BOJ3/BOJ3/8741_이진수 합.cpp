#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
		printf("1");
	for (int i = 0; i < k - 1; i++)
		printf("0");
}