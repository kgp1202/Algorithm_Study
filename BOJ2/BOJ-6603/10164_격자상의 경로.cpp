#include <iostream>

using namespace std;

long long combination(int a, int b) {
	long long returnVal = 1;
	for (int i = 0; i < b; i++) {
		returnVal *= a - i;
	}
	for (int i = 1; i <= b; i++) {
		returnVal /= i;
	}
	
	return returnVal;
}

int main() {
	int Y, X, K;
	cin >> Y >> X >> K;

	if (K == 0) {
		K = 1;
	}

	int KX, KY;
	KX = (K - 1) % X;
	KY = (K - 1) / X;

	X--;
	Y--;

	long long ans = combination(KX + KY, KY) * combination(X - KX + Y - KY, X - KX);
	cout << ans << endl;

}