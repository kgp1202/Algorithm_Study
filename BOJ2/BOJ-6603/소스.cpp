#include <iostream>

using namespace std;

int arr[13];
int memory[6];

void print(int* start,int* end, int num, int* mem = memory) {
	if (num == 1) {
		int* point = start;
		while (point != end) {
			for (int i = 0; i < 5; i++) {
				cout << *(mem + i) << " ";
			}
			cout << *point;
			cout << endl;
			point++;
		}
	}
	else {
		int* point = start;
		while (point != end) {
			*(mem + 6 - num) = *(point);
			point++;
			print(point, end, num - 1, mem);
		}
	}
}

int main() {
	int k;
	cin >> k;
	
	while (k != 0) {
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		
		print(arr, arr + k, 6);
		cout << endl;

		cin >> k;
	}
}