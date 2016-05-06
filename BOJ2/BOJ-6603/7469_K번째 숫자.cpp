#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct node
{
	int data = 0;
	int index = 0;
};

bool comp(const node &a, const node &b)
{
	return a.data < b.data ? true : false;
}

int main()
{
	int n = 0, m = 0;
	int tmp = 0;
	scanf("%d %d", &n, &m);
	vector<node> arry(n + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arry[i].data);
		arry[i].index = i;
	}

	sort(arry.begin() + 1, arry.end(), comp);

	for (int z = 0; z < m; z++)
	{
		int i = 0, j = 0, k = 0;
		int cnt = 0;
		scanf("%d %d %d", &i, &j, &k);

		for (int x = 1; x <= n; x++)
		{
			if (arry[x].index < i)
				continue;
			else if (arry[x].index <= j)
			{
				cnt++;
				if (cnt == k)
				{
					printf("%d\n", arry[x].data);
					break;
				}
			}
		}
	}
	return 0;
}