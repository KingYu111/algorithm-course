/*#include <iostream>

using namespace std;

template <typename T>
T mymax(T a, T b, T c) {
	T maxnum = a;
	if (b > maxnum) maxnum = b;
	if (c > maxnum) maxnum = c;
	return maxnum;
}

int main()
{
	int type;
	cin >> type;

	if (type == 1) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << mymax(a, b, c) << endl;
	}
	else if (type == 2) {
		float a, b, c;
		cin >> a >> b >> c;
		cout << mymax(a, b, c) << endl;
	}
	else if (type == 3) {
		double a, b, c;
		cin >> a >> b >> c;
		cout << mymax(a, b, c) << endl;
	}

	return 0;
}
*/