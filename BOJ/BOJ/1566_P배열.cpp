#include <iostream>

using namespace std;

int start[20][20];
int arr[20][20];
int N, M;
int count1 = 0;
bool isFirst = true;

void change(bool isWidth, int point) {
	if(!isFirst){
		//�������� Ȯ���ϰ� �����ϸ� ����
		bool isSame = true;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (start[n][m] != arr[n][m]) {
					isSame = false;
					break;
				}
			}
		}
		if (isSame){
			return;
		}
	}
	else {
		isFirst = false;
	}
	
	count1++;
	//�ش� ������ ������ �ٲ۴�
	if (isWidth) {
		for (int i = 0; i < N; i++) {
			arr[point][i] = arr[point][i] * (-1);
		}
	}
	else {
		for (int i = 0; i < M; i++) {
			arr[i][point] = arr[i][point] * (-1);
		}
	}


	//���� ���� ���� ã�´�.
	int point2;
	bool isWidth2 = false;
	int temp = 0;
	int smallest = 100;
	for (int w = 0; w < N; w++) {
		for (int i = 0; i < M; i++) {
			temp += arr[w][i];
		}
		if (temp < smallest) {
			point2 = w;
			isWidth2 = true;
			smallest = temp;
			temp = 0;
		}
	}
	for (int h = 0; h < M; h++) {
		for (int i = 0; i < N; i++) {
			temp += arr[i][h];
		}
		if (temp < smallest) {
			point2 = h;
			isWidth2 = false;
			smallest = temp;
			temp = 0;
		}
	}

	if (smallest <= 0) {
		change(isWidth2, point2);
	}
}

int main() {
	cin >> N >> M;//N ����, M ����

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> arr[n][m];
		}
	}

	memcpy(start, arr, 20 * 20 * sizeof(int));

	int point;
	bool isWidth = false;
	int temp = 0;
	int smallest = 100;
	for (int w = 0; w < N; w++) {
		for (int i = 0; i < M; i++) {
			temp += arr[w][i];
		}
		if (temp < smallest) {
			point = w;
			isWidth = true;
			smallest = temp;
			temp = 0;
		}
	}

	for (int h = 0; h < M; h++) {
		for (int i = 0; i < N; i++) {
			temp += arr[i][h];
		}
		if (temp < smallest) {
			point = h;
			isWidth = false;
			smallest = temp;
			temp = 0;
		}
	}

	if (smallest <= 0) {
		change(isWidth, point);
	}

	cout << count1 << endl;

}