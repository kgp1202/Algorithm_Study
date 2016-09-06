#include <iostream>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

map<string, int> maps;
string input[2505];
int key[2505];

int main() {
	int N;
	scanf("%d", &N);

	string value;
	for (int n = 0; n < N; n++) {
		cin >> value;
		maps.insert(pair<string, int>(value, n));
	}

	for (int n = 0; n < N; n++) {
		cin >> input[n];
		key[n] = maps[input[n]];
	}

	int ans = 0;
	int count = 0;
	for (int s = 0; s < N - 1; s++) {
		for (int e = s + 1; e < N; e++) {
			count++;

			if (key[s] < key[e])
				ans++;
		}
	}

	printf("%d/%d", ans, count);
}