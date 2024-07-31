#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    while(1)
    {
        int N, load=0;
        cin>>N;
        if(N== -1)
        {
            break;
        }
        int jobs[9001];
        for(int i=0;i<N;i++)
        {
           cin>>jobs[i];
           load += jobs[i];

        }

        if(load%N!=0)
        {
            cout<<(-1)<<endl;
            continue;
        }
        load /= N;
        int curr_load= 0, max_load = INT_MIN;
        for(int i=0;i<N;i++)
        {
            curr_load += (jobs[i]-load);
            max_load = max(max_load, abs(curr_load));
        }
        cout<<max_load<<endl;

    }

    return 0;
}
