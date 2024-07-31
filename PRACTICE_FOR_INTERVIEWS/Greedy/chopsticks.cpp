#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,D;
    cin>>N>>D;
    vector<int> L;
    for(int i=0;i<N;i++)
    {
        int num;
        cin>>num;
        L.push_back(num);
    }
    sort(L.begin(),L.end());
    int i=0;
    int pairs =0;
    while(i<N)
    {
        if((L[i+1]-L[i])<=D && (i+1)<N)
        {
            i+=2;
            pairs++;
        }
        else
        {
            i+=1;
        }
    }
    cout<<pairs;
    return 0;
}


/*

5 2
1
3
3
9
4

8 2
1
3
3
9
4
5
6
8
*/
