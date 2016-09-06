#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

bool arr[102][102];
bool isCheck[102];
bool isTeamA[102];

int teamA[102];
int teamB[102];
int teamANum = 0;
int teamBNum = 0;

int N;


void check(int n) {
	isCheck[n] = true;
	//queue<int> tempQueue = queue<int>();
	for (int i = 1; i <= N; i++) {
		if (arr[n][i]) {
			if(!isCheck[i]){
				if (isTeamA[n]) {
					teamB[teamBNum++] = i;
					isTeamA[i] = false;
				} else {
					teamA[teamANum++] = i;
					isTeamA[i] = true;
				}
				check(i);
			}
		}
	}
}

int main() {
	cin >> N;

	memset(arr, false, sizeof(arr));
	memset(isCheck, false, sizeof(isCheck));
	memset(isTeamA, false, sizeof(isTeamA));

	int num, temp;
	for (int n = 1; n <= N; n++) {
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> temp;
			arr[n][temp] = true;
		}
	}

	teamA[teamANum++] = 1;
	isTeamA[1] = true;
	check(1);

	bool tempBool = false;
	for (int i = 1; i <= N; i++) {
		if (!isCheck[i]) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] && isCheck[j]) {
					if (isTeamA[j]) {
						teamA[teamANum++] = i;
						isTeamA[i] = true;
						check(i);
						continue;
					}
					else {
						teamB[teamBNum++] = i;
						isTeamA[i] = false;
						check(i);
						continue;
					}
				}
			}
			teamA[teamANum++] = i;
			isTeamA[i] = true;
			check(i);
		}
	}
	
	cout << teamANum << endl;
	sort(teamA, teamA + teamANum);
	for (int i = 0; i < teamANum; i++) {
		cout << teamA[i] << " ";
	}
	cout << endl <<  teamBNum << endl;
	sort(teamB, teamB + teamBNum);
	for (int i = 0; i < teamBNum; i++) {
		cout << teamB[i] << " ";
	}
	cout << endl;
}