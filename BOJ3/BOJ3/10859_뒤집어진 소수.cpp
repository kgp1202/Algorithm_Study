#include <iostream>

using namespace std;

bool isPrime(long long a) {
	if (a == 1) {
		return false;
	}
	else if (a == 2) {
		return true;
	} 
	else if(a % 2 == 0){
		return false;
	}
	else {
		for (long long i = 3; i * i <= a; i += 2) {
			if (a % i == 0) {
				return false;
			}
		}
	}
	return true;
}

long long func(long long a) {
	int arr[20];
	int i = 0;
	while (a != 0) {
		int A = a % 10;
		if (A == 3 || A == 4 || A == 7)	return 1;
		else if (A == 6) A = 9;
		else if (A == 9) A = 6;

		arr[i++] = A;
		a /= 10;
	}

	long long returnVal = 0;
	long long B = 1;
	for (i; i > 0; i--) {
		returnVal += arr[i - 1] * B;
		B *= 10;
	}
	return returnVal;
}

int main() {
	long long N;
	bool result = true;
	cin >> N;
	if (!isPrime(N)) {
		cout << "no";
		return 0;
	}
	
	long long N2 = func(N);
	if (!isPrime(N2)) {
		cout << "no";
		return 0;
	}

	cout << "yes";
}