#include <iostream>
#include <algorithm>

int FF, FS, SF, SS;

using namespace std;

int main() {
	cin >> FF >> FS >> SF >> SS;

	int res = 0;
	if (FS != 0) {
		res = FF + SS;
		if (FS > SF) {
			res += SF * 2 + 1;
		}
		else if (FS <= SF) {
			res += FS * 2;
		}
	}
	else {
		if (FF != 0) { res = FF; }
		else {
			if (SF == 0)	res = SS;
			else res = SS + 1;
		}
	}

	cout << res << endl;
}