//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//bool IsPrime(int a)
//{
//	if (a == 1) return false;
//	for (int i = 2; i <=  sqrt(a); i++) {
//		if (a % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int a;
//	int blank = 0;
//	cin >> a;
//	for (int k = 1; k < a; k++) {
//		if (IsPrime(k)) {
//			if (blank) {
//				cout << " " << k;
//			}
//			else {
//				cout << k;
//				blank = 1;
//			}
//		}
//	}
//	return 0;
//}