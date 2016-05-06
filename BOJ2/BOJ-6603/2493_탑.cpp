#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

class Node {
public:
	int position;
	int data;

	Node() {}
	Node(int a, int b) {
		position = a;
		data = b;
	}
};

bool operator <(Node a, Node b) {
	if (a.data < b.data)	return true;
	else return false;
}

Node arr[500000];

int search(int length, int findData) {
	if (length <= 0)
		return -1;

	int left = 0;
	int right = length - 1;
	int mid;

	while (left <= right) {
		mid = left + (right - left) / 2;

		if (arr[mid].data == findData) {
			return mid;
		}
		else if (arr[mid].data < findData) {
			left = mid + 1;
		}
		else if (arr[mid].data > findData) {
			right = mid - 1;
		}
	}

	return left;
}

int main() {
	/*
	int N;
	cin >> N;

	int a, b;
		scanf("%d", &a);
	for (int i = 0; i < N; i++) {
		arr[i] = Node(i, a);
	}

	set<Node>::iterator point;
	Node temp;
	for (int i = N - 1; i >= 0; i--) {
		temp = arr[i];
		
	}
	*/
	set<Node> mySet;


	mySet.insert(Node(1, 3));
	mySet.insert(Node(2, 1));
	mySet.insert(Node(4, 6));

	for (set<Node>::iterator iter = mySet.begin(); iter != mySet.end(); iter++) {
		cout << (*iter).data << endl;
	}

	cout << search(3, 3);
}