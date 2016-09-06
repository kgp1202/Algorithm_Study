#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int num;
	vector<Node*> vec = vector<Node*>();
};

Node node[20002];

int not(int a) {
	if (a > 10000) {
		a -= 10000;
	}else {
		a += 10000;
	}
	return a;
}

void connect(int a, int b) {
	node[not(a)].vec.push_back(&node[b]);
	node[not(b)].vec.push_back(&node[a]);
}

int main() {
	int studentNum, M;
	cin >> studentNum >> M;

	int temp1, temp2;
	for (int i = 0; i < studentNum; i++) {
		cin >> temp1 >> temp2;
		if (temp1 < 0) { temp1 = temp1 * (-1) + 10000; }
		if (temp2 < 0) { temp2 = temp2 * (-1) + 10000; }

		connect(temp1, temp2);
	}


}