#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <math.h>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
using namespace std;

map<int, int> s;

struct Node {
	bool isCheck = false;
	vector<int> vec;
	int routeSize = 0;
	int route[50];
};

Node node[100005];
int currentRoute[50];
int currentRouteCount = 0;
queue<int> current;
queue<int> future;

void search() {
	if (current.empty())	return;
	
	int temp;
	while (!current.empty()) {
		temp = current.front();
		if (!node[temp].isCheck) {
			node[temp].isCheck = true;
			for (vector<int>::iterator iter = node[temp].vec.begin(); iter != node[temp].vec.end(); iter++) {
				future.push(*iter);
				memcpy(node[*iter].route, node[temp].route, sizeof(int) * node[temp].routeSize);
				node[*iter].route[node[temp].routeSize] = temp;
				node[*iter].routeSize = node[temp].routeSize + 1;
			}
		}
		current.pop();
	}

	current = future;
	future = queue<int>();
	search();
}

int main() {
	int N, K;
	scanf("%d%d", &N, &K);

	char input[31];
	int temp = 0;
	for (int n = 0; n < N; n++) {
		scanf("%s", input);
		
		temp = 0;
		for (int i = 0; i < K; i++) {
			temp += (input[i] - 48) * pow(2.0, K - i - 1);
		}
		s.insert(pair<int, int>(temp, n));
	}

	for (map<int, int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		int multi = 2;
		int temp = (*iter).first;
		map<int, int>::iterator result;
		for (int k = 0; k < K; k++) {
 			if (temp % 2 == 0 ) {
				//printf("%d, %d\n", (*iter).first, (*iter).first + (multi / 2));
				result = s.find((*iter).first + (multi / 2));
				if(result != s.end()){
					//printf("c => %d %d\n", (*iter).second, (*s.find((*iter).first + (multi / 2))).second);
					node[(*iter).second].vec.push_back((*result).second);
				}
			}
			temp /= 2;
			multi *= 2;
		}
	}

	current.push(0);
	search();

	int M;
	scanf("%d", &M);

	int temp2;
	for (int m = 0; m < M; m++) {
		scanf("%d", &temp2);
		if (temp2 == 1)	printf("1\n");
		else if (node[temp2 - 1].routeSize == 0) {
			printf("-1\n");
		}
		else {
			for (int i = 0; i < node[temp2 - 1].routeSize; i++) {
				cout << node[temp2 - 1].route[i] + 1 << " ";
			}
			cout << temp2 << endl;
		}
	}
}