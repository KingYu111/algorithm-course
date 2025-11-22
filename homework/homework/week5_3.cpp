/*#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main() {
	char str1[100];
	char str2[100];

	cin >> str1;
	
	cin >> str2;
	//cout << str1 <<endl;
	//cout << str2 << endl;

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int num1 = 0;
	int num2 = 0;

	for (int i = 0 ; i < len1; i++) {
		num1 = num1 * 10 + str1[i] - '0';
	}
	for (int i = 0; i < len2; i++) {
		num2 = num2 * 10 + str2[i] - '0';
	}

	int sum;
	sum = num1 + num2;
	cout << sum << endl;

	return 0;
}
*/