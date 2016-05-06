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
	// �� ù ���ڰ� �������� ��� ����
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// �����ڰ� �ƴ� ù ���ڸ� ã�´�
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token�� ã������ vector�� �߰��Ѵ�
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// �����ڸ� �پ�Ѵ´�.  "not_of"�� �����϶�
		lastPos = str.find_first_not_of(delimiters, pos);
		// ���� �����ڰ� �ƴ� ���ڸ� ã�´�
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