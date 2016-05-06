#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <cstdlib>

using namespace std;

void Tokenize(const string& str,
	vector<string>& tokens,
	const string& delimiters = ",")
{
	// 맨 첫 글자가 구분자인 경우 무시
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// 구분자가 아닌 첫 글자를 찾는다
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token을 찾았으니 vector에 추가한다
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// 구분자를 뛰어넘는다.  "not_of"에 주의하라
		lastPos = str.find_first_not_of(delimiters, pos);
		// 다음 구분자가 아닌 글자를 찾는다
		pos = str.find_first_of(delimiters, lastPos);
	}
}

int main() {
	int pageNum;
	cin >> pageNum;

	string str;
	while (pageNum != 0) {
		cin >> str;

		int sum = 0;
		bool arr[1003];
		memset(arr, false, 1000);

		vector<string> token;
		Tokenize(str, token);
		
		string temp;
		int pos;
		for (vector<string>::iterator it = token.begin(); it != token.end(); it++) {
			temp = *it;
			size_t found = temp.find('-');
			if (found != string::npos) {
				int startNum = stoi(temp.substr(0, found));
				int endNum = stoi(temp.substr(found + 1, temp.size() - 1));

				for (int i = startNum; i <= endNum; i++) {
					if (i <= pageNum)
						arr[i] = true;
					else
						break;
				}
			}
			else {
				int num = stoi(temp);
				if (num <= 1000) {
					arr[num] = true;
				}
			}
		}

		for (int i = 1; i <= pageNum; i++) {
			if (arr[i] == true)
				sum++;
		}

		cout << sum << endl;

		cin >> pageNum;
	}
}