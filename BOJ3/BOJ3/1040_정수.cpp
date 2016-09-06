#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int arr[10];
long long number;

void func() {

}

int main() {
	string str;
	int K;
	cin >> str;
	cin >> K;

	number = atoi(str.c_str());
	int count = 0;

	for (int i = 0; i < str.size(); i++) {
		arr[str.at(i) - 48]++;
	}

	for (int i = 0; i < 10; i++) {
		if (arr[i] != 0) {
			count++;
		}
	}

	int elseN = 0;
	int currentN = 0;
	int i = 0;
	while (count == K) {
		if (--arr[str.at(i) - 48] == 0) {
			count--;
		}

		if (count > K) {
			currentN++;
			count--;
		}
		else if (count < K) {
			elseN++;
			count++;
		}
	}

	while (currentN != 0) {
		for (int i = str.at(currentN - 1) - 48; i < 10; i++) {
			if (arr[i] != 0) {
				str.at(currentN - 1) = i + 48;
				break;
			}
			if (i == 9) {
				if (str.at(currentN) - 48 == 9) {

				}
				str.at(currentN) = str.at(currentN) + 1;
				
			}
		}
	}
	while (elseN != 0) {

	}
}