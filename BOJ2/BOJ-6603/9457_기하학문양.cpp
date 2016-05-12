#include <iostream>

using namespace std;

int arr[10000];

int main() {

	arr[0] = 1;
	arr[1] = 4;
	
	for (int i = 2; i <= 10; i++) {
		arr[i] = arr[i - 1] * 3 + arr[i - 1] - arr[i - 2];
	}

	for (int i = 0; i <= 10; i++) {
		cout << arr[i] << endl;
	}
}