#include <iostream>
#include <string>

using namespace std;

int addResult[20];
void arr_add(int* a, int* b) {
	memset(addResult, 0, sizeof(addResult));
	int plus = 0;
	for (int i = 0; i < 20; i++) {
		plus = (a[i] + b[i] + plus) / 10;
		addResult[i] = (a[i] + b[i] + plus) % 10;
	}
}

int multipleResult[20];
void arr_multiple(int* a, int* b) {
	memset(multipleResult, 0, sizeof(multipleResult));
	for (int i = 0; i < 20; i++) {
		int temp[20];
		memset(temp, 0, sizeof(temp));
		for (int j = 0; j < b[i]; j++) {
			arr_add(addResult, a);
			
		}
		for (int k = 0; k < 20; k++) {
			temp[k + i] = temp[k];
		}
		arr_add(multipleResult, temp);
	}
}

int main() {
	int arr1[20] = { 1, 2,3 };
	int arr2[20] = { 3, 2 };

	arr_add(arr1, arr2);
	for (int i = 19; i >= 0; i--) {
		cout << addResult[i];
	}

	arr_multiple(arr1, arr2);
	for (int i = 19; i >= 0; i--) {
		cout << multipleResult[i];
	}
}