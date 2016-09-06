#include <iostream>
#include <cstdio>
using namespace std;

int arr[100000];
int DP[100000];
double DP2[100000];
int partSum[100000];
int partPoint[100000];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);

		for (int n = 0; n < N; n++) {
			scanf("%d", &arr[n]);
		}

		int partNum = 0;
		int count = 1;
		int sum = arr[0];
		DP[0] = 1;
		for (int i = 1; i < N; i++) {
			if (sum / count > arr[i]){
				DP[i] = ++count;
				if(sum > 0)
					DP2[i] = sum;
			}
			else {
				partPoint[partNum] = i - 1;
				partSum[partNum++] = sum;
				
				sum = 0;
				count = 1;
				DP[i] = count;
				DP2[i] = arr[i];
			}
			sum += arr[i];
		}
		partPoint[partNum] = N - 1;
		partSum[partNum++] = sum;
		
		for (int i = 0; i < partNum; i++) {
			int temp = partSum[i];
			int j = i - 1;
			bool change = false;
			while (temp <= 0 && j >= 0) {
				temp += partSum[j++];

			}
		}

		int Q;
		scanf("%d", &Q);

		int temp;
		for (int i = 0; i < Q; i++) {
			scanf("%d", &temp);
			printf("%d ", DP[temp - 2]);
		}
		printf("\n");
			
	}
}