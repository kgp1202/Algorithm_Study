#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int i;
int T;
int N;
int height[300];
int divider[302][1000];
int cnt[302];

int past_ans[1000];
int ans[1000];
int dp[300][240];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &height[i]);
			divider[i][0] = 1;
			cnt[i] = 1;
		}

		for (int k = 0; k < N; k++) {

			for (i = 2; i*i < height[k]; i++) {
				if (height[k] % i)   continue;
				divider[k][cnt[k]] = i;
				cnt[k]++;
			}

			if (i*i == height[k]) {
				divider[k][cnt[k]] = i;
				cnt[k]++;
			}
			int num = cnt[k];
			for (i = 1; i <= num; i++) {
				if (height[k] % divider[k][num - i])   continue;
				if (divider[k][cnt[k] - 1] == height[k] / divider[k][num - i])
					continue;
				divider[k][cnt[k]] = height[k] / divider[k][num - i];
				cnt[k]++;
			}
		}

		/*for (int i = 0; i < cnt[0]; i++) {
			past_ans[i] = 1;
		}
		for (int n = 1; n < N; n++) {
			memset(ans, 0, sizeof(ans));
			for (int j = 0; j < cnt[n - 1]; j++) {
				for (int k = 0; k < cnt[n]; k++) {
					if (divider[n - 1][j] <= divider[n][k]) {
						ans[k] += past_ans[j];
						ans[k] %= 1000000007;
					}
				}
			}
			memcpy(past_ans, ans, sizeof(past_ans));
		} */
		for (int i = 0; i < N; i++) {
			for (int n = 0; n < cnt[i]; n++) {
				dp[i][n] = 0;
			}
		}
		for (int n = 0; n < cnt[0]; n++)
			dp[0][n] = 1;

		for (int i = 0; i < N - 1; i++) {
			for (int a = 0; a < cnt[i]; a++) {
				for (int b = 0; b < cnt[i + 1]; b++) {
					if (divider[i][a] <= divider[i + 1][b]) {
						dp[i + 1][b] += dp[i][a];
						dp[i + 1][b] %= 1000000007;
					}
				}
			}
		}

		int answer = 0;
		for (int i = 0; i < cnt[N - 1]; i++) {
			answer += dp[N - 1][i];
			answer %= 1000000007;

		}

		printf("%d\n", answer);
	}
}