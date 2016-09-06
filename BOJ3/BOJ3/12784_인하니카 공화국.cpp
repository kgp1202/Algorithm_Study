#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

struct Bridge;

struct Node {
	vector<Bridge> vec;
	int totalCost;
};

struct Bridge {
	int to;
	int cost;
};

Node nodes[1005];

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

set<int> child;
set<int> child2;
int ans = 0;
void func() {
	for (set<int>::iterator iter = child.begin(); iter != child.end(); iter++) {
		//cout << *iter << " ";
		if (nodes[*iter].vec.at(0).to == 1) {
			ans += min(nodes[*iter].totalCost, nodes[*iter].vec.at(0).cost);
			continue;
		}
		
		nodes[nodes[*iter].vec.at(0).to].totalCost += min(nodes[*iter].totalCost, nodes[*iter].vec.at(0).cost);
		child2.insert(nodes[*iter].vec.at(0).to);
	}
	//cout << endl;
	child.clear();
	child.insert(child2.begin(), child2.end());
	child2.clear();
	if(!child.empty())
		func();
}

int main() {
	int T;
	scanf("%d", &T);

	for(int t = 0; t < T; t++) {
		ans = 0;
		child.clear();
		child2.clear();
		int N, M;
		scanf("%d%d", &N, &M);

		int node1, node2, cost;
		for (int n = 1; n <= N; n++) {
			nodes[n].vec.clear();
			nodes[n].totalCost = 0;
		}

		for (int m = 0; m < M; m++) {
			cin >> node1 >> node2 >> cost;
			Bridge b;
			b.to = node2;
			b.cost = cost;
			nodes[node1].vec.push_back(b);
			b.to = node1;
			nodes[node2].vec.push_back(b);
		}

		for (int i = 2; i <= N; i++) {
			if (nodes[i].vec.size() == 1) {
				child.insert(i);
				nodes[i].totalCost = nodes[i].vec.at(0).cost;
			}
		}

		func();

		cout << ans << endl;
	}
}