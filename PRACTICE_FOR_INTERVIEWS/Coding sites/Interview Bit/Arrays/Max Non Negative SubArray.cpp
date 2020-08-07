#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v)
{
     for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
///kadane algorithm
int maxSumSubarray(vector<int> v)
{
    int max_so_far = v[0], max_till_ending = v[0];
    //int start=0 , last =0,beg=0;
    for(int i=1;i<v.size();i++)
    {
        max_till_ending = max(max_till_ending+v[i],v[i] );
        if(max_so_far< max_till_ending)
        {
            max_so_far = max_till_ending;
            //start = beg;
            //last = i;

        }

    }
    //cout<<start<<" "<<last<<endl;
    return max_so_far;
}

vector<int> maxset(vector<int> &A) {

     int curr_sum =A[0], max_sum = A[0], start=0, end =0, beg=0;

    for(int i=1;i<A.size();i++)
    {
        int temp =  max(curr_sum+A[i],A[i]);
        if(temp> curr_sum)
        {
            curr_sum = temp;
            start = beg +1;

        }
        if(max_sum< curr_sum )
        {
            max_sum = curr_sum;
            end = i;
            start = beg;
        }
    }
    vector<int> output;
    if(max_sum<0)
    {
        return output;
    }
    for(int i=start;i<=end;i++)
    {
        output.push_back(A[i]);
    }
    return output;

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
   //print(v);
    //cout<<maxSumSubarray(v)<<endl;
    vector<int> output = maxset(v);
    print(output);
    cout<<endl<<maxSumSubarray(v);
    return 0;
}

/*
8
-2 -3 4 -1 -2 1 5 -3
7

*/

