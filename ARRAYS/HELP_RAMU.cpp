#include<iostream>
using namespace std;
int main()
{
    int t,c1,c2,c3,c4,n,m,rick[1005],cab[1005];
    cin>>t;
    for(int i =0;i<t;i++)
    {
        cin>>c1>>c2>>c3>>c4>>n>>m;
        for(int j=0;j<n;j++) ///rickshaw
        {
            cin>>rick[j];
        }
        for(int j=0;j<m;j++)///cabs
        {
            cin>>cab[j];
        }
        int rickCost = 0;
        for(int j=0;j<n;j++) ///rickshaws
        {
            rickCost += min(c1*rick[j],c2);
        }
        rickCost = min(rickCost,c3);
        int cabCost = 0;
        for(int j=0;j<m;j++) ///cabs
        {
            cabCost += min(c1*cab[j],c2);
        }
        cabCost = min(cabCost,c3);
        int ans =0;
        ans = min(c4,rickCost+cabCost);
        cout<<ans<<endl;

    }
    return 0;
}
