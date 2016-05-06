#include <iostream>

using namespace std;

int arr[3001];
bool spot[2000005];

int find(int start, int interval, int sum) {
	if (spot[start + 2 * interval]) {
		sum += start + 2 * interval;
		int returnVal = find(start + interval, interval, sum);

		if (returnVal != 0) {
			sum = returnVal;
		}

		return sum;
	}
	return 0;
}

int main() {
	int N;
	cin >> N;
	
	int biggest = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		spot[arr[i]] = true;
	}

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			temp = find(arr[i], arr[j] - arr[i], arr[i] + arr[j]);
			
			if (biggest < temp) {
				biggest = temp;
			}
		}
	}

	cout << biggest << endl;
}