#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Node {
public:
	int num;
	int fruitNum;
	vector<Node*> vec = vector<Node*>();
	bool check;

	Node() {}
};

Node node[10002];

int root;
int DFS(Node* s, int result) {
	if (s->check)	return result;

	s->check = true;
	result += s->fruitNum;

	int max = 0;
	for (vector<Node*>::iterator iter = s->vec.begin(); iter != s->vec.end(); iter++) {
		int temp = DFS(*iter, result);
		if (max < temp)
			max = temp;
	}

	return max;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		cin >> node[n].fruitNum;
		node[n].num = n;
	}

	int a, b;
	for (int n = 0; n < N - 1; n++) {
		//cin >> a >> b;
		scanf("%d%d", &a, &b);

		node[a].vec.push_back(&node[b]);
 		node[b].vec.push_back(&node[a]);
	}

	bool changed = true;
	while (changed) {
		for (int i = 1; i <= N; i++) {
			if (node[i].vec.size() == 1 && node[i].num == 0) {
				//node[i].vec.back()->
			}
		}
	}

	int maxRoot = 0;
	int max = 0;
	for (int i = 1; i <= N; i++) {
		
		for (int j = 1; j <= N; j++) {
			node[j].check = false;
		}

		if (node[i].vec.size() >= 2)	continue;

		int result = DFS(&node[i], 0);
		if (max < result) {
			max = result;
			maxRoot = node[i].num;
		}
	}

	printf("%d %d", max, maxRoot);
	//cout << max << " " << maxRoot << endl;
}