#include <iostream>

using namespace std;

class Point {
public:
	int max;
	int min;
	Point* parent;
	
	Point() {
		max = 0;
		min = 1000000000;
	}

	Point(int a) {
		max = a;
		min = a;
	}

	void makeParent() {
		
	}
	
};

Point* arr[100000];

int main() {
	int num, testCase;
	cin >> num >> testCase;

	int temp;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		arr[i] = new Point(temp);
	}



	for (int tc = 0; tc < testCase; tc++) {

	}
}