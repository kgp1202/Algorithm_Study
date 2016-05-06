#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sqrt(i) ; j++) {
			if (i % j == 0)
				sum++;
		}
	}

	cout << sum << endl;
}