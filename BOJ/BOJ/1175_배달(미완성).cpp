#include <iostream>

using namespace std;

int height, width;

class Point {
public:
	int h;
	int w;
	int inputDirection;
	int value = 999999;

	Point() {
		value = 999999;
	}
	Point(int h, int w) {
		this->h = h;
		this->w = w;
		value = 999999;
	}
};

Point* points[4][50][50];

void search(Point* startPoint, int direction) {
	switch (direction) {
	case 0:		//동쪽으로
		if (startPoint->w + 1 < height) {
			if (startPoint->value + 1 < points[0][startPoint->h][startPoint->w + 1]->value) {
				points[0][startPoint->h][startPoint->w + 1]->value = startPoint->value + 1;
				
				points[0][startPoint->h][startPoint->w + 1]->inputDirection = 0;
				search(points[0][startPoint->h][startPoint->w + 1], 1);
				search(points[0][startPoint->h][startPoint->w + 1], 2);
				search(points[0][startPoint->h][startPoint->w + 1], 3);
			}
		}
		else {
			return;
		}
		break;
	case 1:		//서쪽으로
		if (startPoint->w - 1 >= 0) {
			if (startPoint->value + 1 < points[1][startPoint->h][startPoint->w - 1]->value) {
				points[1][startPoint->h][startPoint->w - 1]->value = startPoint->value + 1;

				points[1][startPoint->h][startPoint->w - 1]->inputDirection = 1;
				search(points[1][startPoint->h][startPoint->w - 1], 0);
				search(points[1][startPoint->h][startPoint->w - 1], 2);
				search(points[1][startPoint->h][startPoint->w - 1], 3);
			}
		}
		else {
			return;
		}
		break;
	case 2:		//남쪽으로
		if (startPoint->h + 1 < height) {
			if (startPoint->value + 1 < points[2][startPoint->h + 1][startPoint->w]->value) {
				points[2][startPoint->h + 1][startPoint->w]->value = startPoint->value + 1;

				points[2][startPoint->h + 1][startPoint->w]->inputDirection = 2;
				search(points[2][startPoint->h + 1][startPoint->w], 0);
				search(points[2][startPoint->h + 1][startPoint->w], 1);
				search(points[2][startPoint->h + 1][startPoint->w], 3);
			}
		}
		else {
			return;
		}
		break;
	case 3:		//북쪽으로
		if (startPoint->h - 1 >= 0) {
			if (startPoint->value + 1 < points[3][startPoint->h - 1][startPoint->w]->value) {
				points[3][startPoint->h - 1][startPoint->w]->value = startPoint->value + 1;

				points[3][startPoint->h - 1][startPoint->w]->inputDirection = 3;
				search(points[3][startPoint->h - 1][startPoint->w], 0);
				search(points[3][startPoint->h - 1][startPoint->w], 1);
				search(points[3][startPoint->h - 1][startPoint->w], 2);
			}
		}
		else {
			return;
		}
		break;

	}
}

int main() {
	cin >> height >> width;

	for (int dir = 0; dir < 4; dir++) {
		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
				points[dir][h][w] = new Point(h ,w);
			}
		}
	}	

	/*
	Point*** points = new Point**[2];
	for (int i = 0; i < 4; i++) {
		points[i] = new Point*[height];
		for (int h = 0; h < height; h++) {
			points[i][h] = new Point[width];
		}
	}
	*/

	//points[i][h][w] i => 방향 1,2,3,4 동 서 남 북
	
	char map[50][50];

	int startH;
	int startW;
	int endH;
	int endW;
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			cin >> map[h][w];
			if (map[h][w] == 'S') {
				startH = h;
				startW = w;
			}
			if (map[h][w] == 'C') {
				endH = h;
				endW = w;
			}
		}
	}
	cout << "startPoint => " << startH << " " << startW << endl;
	cout << "endPoint => " << endH << " " << endW << endl;
	cout << points[0][endH][endW]->value << endl;

	points[0][startH][startW]->value = 0;
	points[1][startH][startW]->value = 0;
	points[2][startH][startW]->value = 0;
	points[3][startH][startW]->value = 0;

	search(points[0][startH][startW], 0);
	search(points[0][startH][startW], 1);
	search(points[0][startH][startW], 2);
	search(points[0][startH][startW], 3);

	int shortest = 0;
	for (int dir = 0; dir < 4; dir++) {
		if (shortest > points[dir][endH][endW]->value) {
			shortest = points[dir][endH][endW]->value;
		}
	}

	cout << shortest;
}