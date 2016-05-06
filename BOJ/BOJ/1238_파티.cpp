#include <iostream>

using namespace std;

class Bridge;
class Node {
public:
	int num;
	Bridge* ptr;
	int sum;
	int bridgeNum;

	void connect(Bridge* a) {
		if (ptr == NULL) {
			ptr = a;
		}
		else {
			ptr->nextPtr = a;
		}
		bridgeNum++;
	}
	Node(int num) {
		this->num = num;
		bridgeNum = 0;
	}
};

class Bridge {
public:
	Node* A;
	Node* B;
	Bridge* nextPtr;
	int time;

	Bridge(Node* a, Node* b, int t) {
		A = a;
		B = b;
		time = t;
	}
};

void DFS(Node* a) {
	Bridge* temp;
	for (int i = 0; i < a->bridgeNum; i++) {
		if (i == 0) {
			
		}
	}
}

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	
	Node** Nodes = new Node*[N];
	Bridge* temp;
	for (int m =0; m < M; m++) {
		int a, b, time;
		cin >> a >> b >> time;

		temp = new Bridge(Nodes[a], Nodes[b], time);
	}

}