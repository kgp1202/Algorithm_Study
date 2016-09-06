#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[1000001];
int main() {
	int sum = 1;
	gets(str);
	int len = strlen(str);
	for (int i = 1; i < len; i++)
		if (str[i] == ' ')
			sum++;
	if (str[len - 1] == ' ') sum--;
	cout << sum;
}