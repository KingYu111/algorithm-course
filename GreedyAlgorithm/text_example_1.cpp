#include <iostream>

using namespace std;

void GreedyChoose(int len, int *startTime, int *endTime, bool *mark);

int main()
{
    int startTime[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int endTime[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    bool mark[11] = {false};
    GreedyChoose(11, startTime, endTime, mark);

    cout << "NO.\t" << "sTime\t" << "eTime\t" << endl;
    for(int i=0;i<11;i++)
    {
        if(mark[i])
        {
            cout << i+1 << "\t" << startTime[i] << "\t" << endTime[i] << endl;
        }
    }
    return 0;
}

void GreedyChoose(int len, int *startTime, int *endTime, bool *mark)
{
    mark[0]=true;

    int j=0;
    for(int i=0;i<len;i++)
    {
        if(startTime[i]>=endTime[j])
        {
            mark[i]=true;
            j=i;
        }
    }
}