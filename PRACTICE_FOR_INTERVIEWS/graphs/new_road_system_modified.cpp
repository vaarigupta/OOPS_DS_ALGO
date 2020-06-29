#include<bits/stdc++.h>
using namespace std;
void convenient_FM(vector<vector<bool> > FlightMap,int N)
{

    vector<vector<bool> > incoming(N, vector<bool> (N,false));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(FlightMap[i][j])
            {
                incoming[j][i] = true;
            }
        }
    }
    int inF =0, outF=0;
    int i=0;
    bool ans =true;
    for(i=0;i<N;i++)
    {
        int in =0, out =0;
        for(int j=0;j<N;j++)
        {
            if(FlightMap[i][j])
            {
                out++;
            }
            if(incoming[i][j])
            {
                in++;
            }
        }
        inF+= in;
        outF+=out;
        if(in!=out)
        {
            ans = false;
        }
    }
    if(ans)
    {
        cout<<"Yes"<<endl<<inF<<" "<<outF;
    }
    else
    {
        cout<<"No"<<endl<<inF<<" "<<outF;
    }

}
int main()
{
    int N;
    cin>>N;
    vector<vector<bool> > FlightMap(N,vector<bool> (N,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            bool num;
            cin>>num;
            FlightMap[i][j] = num;
        }
    }
    convenient_FM(FlightMap,N);
    return 0;
}
