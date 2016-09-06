#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int x1, y1, p1, q1, x2, y2, p2, q2;
	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

		int x = x1 - x2;
		int y = y1 - y2;
		int w1 = p1 - x1;
		int h1 = q1 - y1;
		int w2 = p2 - x2;
		int h2 = q2 - y2;

		char result;
		int w, h;
		if (x == 0) {
			w = x1;
		}
		if (y == 0) {
			h = y1;
		}
		if (x > 0) {
			w = w2;
		}
		if (x < 0) {
			x *= (-1);
			w = w1;
		}
		if (y > 0) {
			h = h2;
		}
		if (y < 0) {
			y *= (-1);
			h = h1;
		}

		if (x < w && y < h) {
			result = 'a';
		}
		else if (x > w || y > h) {
			result = 'd';
		}
		else if (x == w && y == h) {
			result = 'c';
		}
		else {
			result = 'b';
		}

		cout << result << endl;
	}
}