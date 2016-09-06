#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;

class Node {
public:
	vector<int> vec = vector<int>();
	bool isCheck = false;
};

Node node[102];

void check(int n) {

}

int main() {
	cin >> N;

	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;

			if (temp == 0 && i != j) {
				node[i].vec.push_back(j);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= N; k++) {
			node[k].isCheck = false;
		}
		check(i);
	}

}