#include <iostream>

using namespace std;

int cal_5_count(int a)
{
	int count = 0;
	while (a >= 5)
	{
		if (a % 5 == 0)
		{
			count++;
			a = a / 5;
		}
		else break;
	}
	return count;
}

int main()
{
	int N;
	int count = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		count += cal_5_count(i);
	}

	cout << count;
	return 0;
}