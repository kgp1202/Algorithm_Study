#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

int N, M, S;

class Node {
public:
	set<int> vec;
	bool isCheck = false;
};

Node node[1003];

void DFS(int s) {
	if (!node[s].isCheck) {
		cout << s << " ";
		node[s].isCheck = true;
		for (set<int>::iterator iter = node[s].vec.begin(); iter != node[s].vec.end(); iter++) {
			DFS(*iter);
		}
	}
}

queue<int> que;

void BFS(int start) {
	node[start].isCheck = true;
	cout << start << " ";
	que.push(start);

	while (!que.empty()) {
		int temp = que.front();
		que.pop();

		for (set<int>::iterator iter = node[temp].vec.begin(); iter != node[temp].vec.end(); iter++) {
			if(!node[*iter].isCheck){
				cout << *iter << " ";
				node[*iter].isCheck = true;
				que.push(*iter);
			}
		}
	}
}


int main() {
	cin >> N >> M >> S;
	
	int temp1, temp2;
	for (int m = 0; m < M; m++) {
		cin >> temp1 >> temp2;

		node[temp1].vec.insert(temp2);
		node[temp2].vec.insert(temp1);
	}
	DFS(S);
	cout << endl;

	for (int i = 1; i <= N; i++) {
		node[i].isCheck = false;
	}

	BFS(S);
}