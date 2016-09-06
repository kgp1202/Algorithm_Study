#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string arr[10005];

bool func(string a, string b) {
	return a.length() < b.length();
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		string input;
		string temp;
		long ten = 1;
		set<string> s;
		bool isNo = false;

		for (int n = 0; n < N; n++) {
			cin >> input;
			arr[n] = input;
		}

		sort(arr, arr + N, func);

		for (int n = 0; n < N; n++) {
			input = arr[n];
			temp = input;
			ten = 1;

			for (int i = 1; i <= temp.length(); i++) {
				if (s.find(temp.substr(0, i)) != s.end()) {
					isNo = true;
				}
			}
			
			s.insert(input);
		}
		isNo ? printf("NO\n") : printf("YES\n");
	}
}