#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int maximumGap(const vector<int> &A) {
    int maxi = INT_MIN , mini = INT_MAX;
    int max_diff = 0;
    int n = A.size();
    vector<int> minArr(A.size(),-1);
    vector<int> maxArr(A.size(),-1);
    if(A.size()<2)
    {
        return 0;
    }
    for(int i=0;i<A.size();i++)
    {

        if(A[i]>maxi)
        {
            maxi = A[i];
        }
        if(A[i]<mini)
        {
            mini = A[i];
        }
    }
    cout<<"MAX "<<maxi<<" "<<"MIN"<<mini<<endl;
    int gap = maxi -mini;
    gap = gap / (n-1);
    cout<<"GAP "<<gap<<endl;
    if(gap==0)
    {
        return maxi - mini;
    }
    for(int i=0;i<A.size();i++)
    {
        int index = (int)((A[i]-mini)/gap);
        if(minArr[index]<0)
        {
            minArr[index] = A[i];
            maxArr[index] = A[i];
        }
        else
        {
           minArr[index] = min(minArr[index],A[i]);
           maxArr[index] = max(maxArr[index],A[i]);
        }
    }
    cout<<"Min array "<<endl;
    print(minArr);
    cout<<"Max array "<<endl;
    print(maxArr);
    int index = 0;
    for(int i=0;i<n;i++)
    {
        if(minArr[i]>=0)
        {
            max_diff = max(max_diff, minArr[i]- maxArr[index]);
            index = i;
        }
    }
    return max_diff;

}

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {

        int no;
        cin>>no;
        v.push_back(no);
    }
    cout<<maximumGap(v);


}

/*

5
5 8 3 2 10
MAX 10 MIN2
GAP 2
Min array
2 5 -1 -1 10
Max array
2 5 -1 8 10
5

*/
