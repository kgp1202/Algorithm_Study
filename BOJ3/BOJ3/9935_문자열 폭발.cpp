#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char> myList = list<char>();

int main() {
	string str,	bomb;
	cin >> str >> bomb;
	
	char* ans = new char[bomb.size()];
	char* temp = new char[bomb.size()];

	for (int i = 0; i < bomb.size(); i++) {
		ans[i] = bomb.at(bomb.size() - i - 1);
	}
	
	for (int i = 0; i < str.size(); i++) {
		myList.push_back(str.at(i));
		int count = 0;
		bool isAnswer = true;
		for (list<char>::iterator iter = myList.end(); iter != myList.begin(); iter--) {
			iter--;
			temp[count++] = *iter;
			if (count == bomb.size()) {
				for (int i = 0; i < bomb.size(); i++) {
					if (ans[i] != temp[i]) {
						isAnswer = false;
						break;
					}
				}
				if (isAnswer == true) {
					for (int i = 0; i < bomb.size(); i++) {
						myList.pop_back();
					}
				}
				break;
			}
			iter++;
		}
	}

	for (list<char>::iterator iter = myList.begin(); iter != myList.end(); iter++) {
		cout << *iter;
	}

	if (myList.size() == 0) {
		cout << "FRULA" << endl;
	}
}