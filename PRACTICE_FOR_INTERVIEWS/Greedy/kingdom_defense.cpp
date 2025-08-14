#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int w,h,n;
        cin>>w>>h>>n;
        int x[40001];
        int y[40001];
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }
        sort(x,x+n);
        sort(y,y+n);
        int delx = x[0]-1 , dely = y[0]-1;
        for(int i=1;i<n;i++)
        {
            delx = max(delx, x[i]-x[i-1]-1);
            dely = max(dely, y[i]-y[i-1]-1);
        }
        delx = max(delx, w-x[n-1]);
        dely = max(dely, h-y[n-1]);
        long long penalty = delx*dely;
        cout<<penalty<<endl;
    }
    return 0;
}

/*

1
8 8 2
3 8
8 6
20

*/
