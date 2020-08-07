#include <bits/stdc++.h>
using namespace std;



vector<int> subUnsort(vector<int> &A) {

    vector<int> ans;
    int n = A.size();
    ///find start and end - assume these to be subarray
    // find min and max of that subarray
    /// Now traverse again through main array - if again any violation found then update start and end
    int start = -1, end = -1;
    for(int i=0;i<n-1;i++)
    {
        if(A[i]>A[i+1])
        {
            start = i;
            break;
        }
    }
    cout<<"start " <<start<<endl;
    if(start== -1)
    {
        ans.push_back(start);
        return ans;
    }
    for(int i=n-1;i>0;i--)
    {
        if(A[i]< A[i-1])
        {
            end = i;
            break;
        }
    }
    cout<<"end "<<end<<endl;
    int min = A[start], max = A[start];
    for(int i=start+1;i<=end;i++)
    {
        if(A[i]< min)
        {
            min = A[i];
        }
        if(A[i]>max)
        {
            max = A[i];
        }
    }
    cout<<"min :" <<min<<" "<<"max "<<max<<endl;
    for(int i=0;i<start;i++)
    {
        if(A[i]> min)
        {
            start =i;
            break;
        }
    }
    cout<<"start " <<start<<endl;
    for(int i =n-1;i>end;i--)
    {
        if(A[i]<max)
        {
            end = i;
            break;
        }
    }
    cout<<"end "<<end<<endl;
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}

void print(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
// Driver code
int main()
{
	vector<int> v;
	vector<int> ans;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
    {

        int no;
        cin>>no;
        v.push_back(no);

    }
    ans = subUnsort(v);
    print(ans);
	return 0;
}
