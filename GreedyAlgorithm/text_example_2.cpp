// 核心思路：采用贪心策略，自定义比较函数，将数字数组重新排序，以拼接成最大的整数。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Custom comparison function for sorting
bool compare(int a, int b) {
    return std::to_string(a) + std::to_string(b) > std::to_string(b) + std::to_string(a);
}

int main() {
    int n;
    std::cout << "please enter the number n:" << std::endl;
    std::cin >> n;
    std::vector<int> array(n);

    // Input n numbers
    std::cout << "please enter the numbers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    // Sort the array using the custom comparison function
    std::sort(array.begin(), array.end(), compare);

    std::cout << "the max number is:";
    for (int x : array) {
        std::cout << x;
    }
    std::cout << std::endl;

    return 0;
}

/*
#include <iostream>
#include <cmath>

using namespace std;

bool compare(int Num1, int Num2);

int main()
{
    int N;
    cout << "please enter the number n:" << endl;
    cin >> N;
    int *array= new int[N];

    //输入N个数
    cout << "please enter the numbers:" << endl;
    for(int i=0;i<N;i++)
    {
        cin >> array[i];
    }

    //按给定顺序排序
    for(int i=0;i<=N;++i)
    {
        for(int j=0;j<N-1-i;j++)
        {
            if(compare(array[j],array[j+1]))
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    cout << "the max number is:";
    for(int i=N-1;i>=0;i--)
    {
        cout << array[i];
    }
    cout << endl;

    //释放内存
    delete[] array;

    return 0;
}
bool compare(int Num1, int Num2)
{
    int count1 = 0,count2 = 0;
    int MidNum1 = Num1,MidNum2 = Num2;
    //计算Num1的位数
    while(MidNum1)
    {
        count1++;
        MidNum1 /= 10;
    }
    //计算Num2的位数
    while(MidNum2)
    {
        count2++;
        MidNum2 /= 10;
    }

    int a = Num1 * pow(10,count2) + Num2;
    int b = Num2 * pow(10,count1) + Num1;

    return a>b;
}*/
