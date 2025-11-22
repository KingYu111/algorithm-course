//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int GCD(int a, int b)
//{
//	while (b != 0)
//	{
//		int temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}
//
//int mingongbei(int a, int b)
//{
//	if (a == 0 || b == 0)
//	{
//		return 0;
//	}
//
//	return abs(a * b) / GCD(a, b);
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//
//	cout << mingongbei(a, b);
//
//	return 0;
//}