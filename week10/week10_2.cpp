#include <iostream>

using namespace std;

struct Activity
{
    int start;
    int end;
};

int main()
{
    int n;
    cin >> n;

    Activity acts[10000];
    for(int i=0;i<n;i++)
    {
        cin >> acts[i].start >> acts[i].end;
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(acts[j].end > acts[j+1].end)
            {
                Activity temp = acts[j];
                acts[j] = acts[j+1];
                acts[j+1] = temp;
            }
        }
    }

    int count = 1;
    int last_end = acts[0].end;//上一次活动的结束时间

    for(int i=0;i<n;i++)
    {
        if(acts[i].start > last_end)
        {
            count++;
            last_end = acts[i].end;
        }
    }

    cout << count << endl;
    return 0;
}