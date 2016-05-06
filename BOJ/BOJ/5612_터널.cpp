#include <iostream>

using namespace std;

int main() {
	int time, ternal;
	cin >> time >> ternal;

	int max = ternal;
	bool end1 = false;
	int in1, out1;
	for (int t = 0; t < time; t++) {
		cin >> in1 >> out1;
		ternal = ternal + in1 - out1;

		if (ternal < 0) {
			end1 = true;
			break;
		}

		if (max < ternal) {
			max = ternal;
		}

	}

	if (end1) {
		cout << "0" << endl;
	}
	else
		cout << max << endl;
}