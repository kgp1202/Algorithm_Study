#include <iostream>
using namespace std;
int main()
{
	int n, t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n <= 3 || n == 6)
			cout << "0" << endl;
		else if (n == 4)
			cout << "2" << endl;
		else
			cout << "1" << endl;
	}
	return 0;
}