#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int point;
	bool check;
};

node arr[1004];

bool func(node a, node b) {
	return a.point < b.point;
}

int main() {
	int h, w, pageNum, N;
	cin >> h >> w >> pageNum >> N;

	int maxH = 0;
	int tempH, tempW;
	for (int i = 0; i < N; i++) {
		cin >> tempH >> tempW;
		
		if (tempH > maxH) maxH = tempH;
		arr[i].point = tempW;
	}
	arr[N].point = 99999999;

	sort(arr, arr + N, func);

	int count = 0;
	int temp;
	while(true){
		count = 0;
		for (int n = 0; n < N; n++)
			arr[n].check = false;
		for (int n = 0; n < N; n++) {
			if (!arr[n].check) {
				count++;
				arr[n].check = true;
				temp = arr[n].point;
				while (arr[n + 1].point < temp + maxH) {
					arr[n + 1].check = true;
					n++;
				}
			}
		}
		if (count <= pageNum)
			break;
		else maxH++;
	}
	cout << maxH << endl;
}