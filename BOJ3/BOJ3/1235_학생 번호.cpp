#include <iostream>
#include <string>

using namespace std;

int check(string a, string b) {
	int count = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a.at(i) == b.at(i)) {
			count++;
		}
		else {
			return count;
		}
	}
}

string arr[1005];

int main() {
	int N;
	cin >> N;

	string temp;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}

	int max = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (max < check(arr[i], arr[j])) {
				max = check(arr[i], arr[j]);
			}
		}
	}

	cout << max + 1;
}