//挖金矿问题
#include <iostream>
using namespace std;

int n;//金矿数
int peopleTotal;//可以用于挖金子的人数
int peopleNeed[100];//每个金矿需要的人数
int gold[100];//每个金矿的金子数
int maxGold[10000][100];//macGold[i][j]保存了i个人挖前j个金矿能够得到的最大金子数，等于-1时表示未知

//初始化数据
void init_Gold()
{
    int i,j;
    cout << "请输入金矿数：" << endl;
    cin >> n;
    cout << "请输入可以用于挖金子的人数：" << endl;
    cin >> peopleTotal;
    cout << "请输入每个金矿需要的人数：" << endl;
    for(i=0;i<n;i++)
    {
        cin >> peopleNeed[i];
    }
    cout << "请输入每个金矿的金子数：" << endl;
    for(i=0;i<n;i++)
    {
        cin >> gold[i];
    }

    //初始化maxGold数组
    for(i=0;i<=peopleTotal;i++)
    {
        for(j=0;j<n;j++)
        {
            maxGold[i][j]=-1;//表示未知,对应动态规划中的“备忘录”
        }
    }
}

int max_Gold(int a, int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//获得在仅有people个人挖前mineNum个金矿时能够得到的最大金子数，注意“前多少个”也是从0开始编号的
int GetMaxGold(int people, int mineNum)
{
    //声明返回的最大金子数
    int retMaxGold;
    //如果这个问题曾经计算过（对应动态规划中的“备忘录”）
    if(maxGold[people][mineNum]!=-1)
    {
        retMaxGold = maxGold[people][mineNum];
    }
    else if(mineNum == 0)//如果只有一个金矿（对应动态规划中的“边界”）
    {
        //当给出的人数足够开采这个金矿时
        if(people >= peopleNeed[mineNum])
        {
            //得到的最大值就是这座金矿的金子数
            retMaxGold = gold[mineNum];
        }
        else//如果给出的人数不足以开采这座金矿
        {
            //得到的最大值就是0
            retMaxGold = 0;
        }
    }
    else if(people >= peopleNeed[mineNum])//如果给出的人够开采这座金矿（对应动态规划中的“最优子结构”）
    {
        //考虑开采和不开采；两种情况，取最大值
        retMaxGold = max_Gold(GetMaxGold(people-peopleNeed[mineNum],mineNum-1)+gold[mineNum],GetMaxGold(people,mineNum-1));
    }
    else//否则给出的人不够开采这座金矿
    {
        //仅考虑不开采的情况
        retMaxGold = GetMaxGold(people,mineNum-1);
    }

    //做备忘录
    maxGold[people][mineNum] = retMaxGold;
    return retMaxGold;
}

int main()
{
    init_Gold();
    //编号从0开始，所以是n-1
    cout << "能够得到的最大金子数为：" << GetMaxGold(peopleTotal,n-1) << endl;
    return 0;
}