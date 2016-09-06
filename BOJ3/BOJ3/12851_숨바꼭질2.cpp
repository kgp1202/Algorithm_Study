#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int smallestTime = 100000;
	int way = 0;
};

Point point[300000];
queue<int> myQueue = queue<int>();

void check(int index) {
	if(0 <= index && index <= 100000){
		if (point[index - 1].smallestTime == point[index].smallestTime + 1) {
			point[index - 1].way++;
			myQueue.push(index - 1);
		}
		else if (point[index - 1].smallestTime > point[index].smallestTime + 1) {
			point[index - 1].smallestTime = point[index].smallestTime + 1;
			point[index - 1].way = 1;
			myQueue.push(index - 1);
		}


		if (point[index + 1].smallestTime == point[index].smallestTime + 1) {
			point[index + 1].way++;
			myQueue.push(index + 1);
		}
		else if (point[index + 1].smallestTime > point[index].smallestTime + 1) {
			point[index + 1].smallestTime = point[index].smallestTime + 1;
			point[index + 1].way = 1;
			myQueue.push(index + 1);
		}


		if (point[index * 2].smallestTime == point[index].smallestTime + 1) {
			point[index * 2].way++;
			myQueue.push(index * 2);
		}
		else if (point[index * 2].smallestTime > point[index].smallestTime + 1) {
			point[index * 2].smallestTime = point[index].smallestTime + 1;
			point[index * 2].way = 1;
			myQueue.push(index * 2);
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	
	point[N].smallestTime = 0;
	point[N].way = 1;
	check(N);
	while (!myQueue.empty()) {
		check(myQueue.front());
		myQueue.pop();
	}

	cout << point[K].smallestTime << endl << point[K].way << endl;
}