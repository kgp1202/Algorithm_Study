#include <iostream>
#include <cmath>
#include <set>
using namespace std;

class Node {
public:
	int goTo[502];
	int comeFrom[502];
	int goToCount = 0;
	int comeFromCount = 0;
	int point;
	int len;
	bool oneWay;
};

Node node[505];

int useCount = 0;
set<int> useSet;
int useArr[505];

void DFS(int goPoint, int fromPoint) {
	int current = useArr[useCount];
	if (goPoint <= fromPoint) {
		for (int i = 0; i < node[current].goToCount; i++) {
			if (useSet.find(node[current].goTo[i]) == useSet.end()) {
				return;
			}
			else {
				useSet.insert(node[current].goTo[i]);
				useArr[useCount] = node[current].goTo[i];
				useCount++;

				DFS(useCount, false);
			}
		}
	}
	else {
		for (int i = 0; i < node[current].comeFromCount; i++) {
			if (useSet.find(node[current].comeFrom[i]) == useSet.end()) {
				return;
			}
			else {
				useSet.insert(node[current].goTo[i]);
				useArr[useCount] = node[current].goTo[i];
				useCount++;

				DFS(useCount, false);
			}
		}
	}
}


int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> node[i].point >> node[i].len >> node[i].oneWay;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (node[j].point - node[i].point <= node[i].len) {
				node[i].goTo[node[i].goToCount] = j;
				node[i].goToCount++;
			}
			if (node[i].point - node[j].point <= node[i].len) {
				node[i].comeFrom[node[i].comeFromCount] = i;
				node[i].comeFromCount++;
			}
		}
	}




}