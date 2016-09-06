#include <iostream>
#include <cstdio>

using namespace std;

int primeCal[20005];
int arr[20005];

int track(int a) {
	if (a == 1) {
		arr[a] = 1;
		return 1;
	}
	else if( a == 0) {
		arr[a] = 2;
		return 2;
	}
	else if (arr[a] == 3) {
		arr[a] = 2;
		return 2;
	}
	else if (arr[a] == 0 && arr[a] == 1) {
		return arr[a];
	}

	int temp = a;
	int sum = 0;
	while (temp != 0) {
		sum += (temp % 10) * (temp % 10);
		temp /= 10;
	}

	arr[a] = 3;		//trackingÁßÀÏ¶§
	int ans = track(sum);
	arr[a] = ans;
	return ans;
}

int main() {
	int P;
	scanf("%d", &P);
	
	int primeNum = 0;
	for (int i = 2; i <= 10000; i++) {
		if (primeCal[i] == 0) {
			for (int j = 2; j * i <= 10000; j++) {
				primeCal[j * i] = -1;
			}
		}
	}
	
	primeCal[1] = -1;

	int a, input;
	for (int i = 0; i < P; i++) {
		//cin >> a >> input;
		scanf("%d%d", &a, &input);

		//cout << a << " " << input << " ";
		printf("%d %d ", a, input);
		if(primeCal[input] == 0){
			if (arr[input] == 1) {
				//cout << "YES" << endl;
				printf("YES\n");
			}
			else if (arr[input] == 2) {
				//cout << "NO" << endl;
				printf("NO\n");
			}
			else{
				if (track(input) == 1) {
					//cout << "YES" << endl;
					printf("YES\n");
				}
				else {
					//cout << "NO" << endl;
					printf("NO\n");
				}
			}
		}
		else {
			//cout << "NO" << endl;
			printf("NO\n");
		}
	}

}