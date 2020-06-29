#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> v{1,1,2,2,3,3,3,3,4,5};
    vector<int>:: iterator upper1;
    upper1 = upper_bound(v.begin(),v.end(), 2.5);
    cout<<(upper1-v.begin())<<endl;
    return 0;
}
