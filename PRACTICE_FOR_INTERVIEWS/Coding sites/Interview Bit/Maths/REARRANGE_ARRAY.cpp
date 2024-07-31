#include<bits/stdc++.h>
using namespace std;
void print(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
//void arrange(vector<int> &A) {
//    int n = A.size();
//    vector<int> takencount(n,0);
//    for(int i=0;i<n;i++)
//    {
//        takencount[A[i]] = A[i];
//    }
//    for(int i=0;i<n;i++)
//    {
//        A[i] = takencount[i];
//    }
//
//}

void arrange(vector<int> &A) {
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        A[i] += ((A[A[i]]%n)*n);
    }
    for(int i=0;i<n;i++)
    {
        A[i] /= n;
    }

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
    print(v);
    arrange(v);
    print(v);
    return 0;
}


/*

5
3 2 1 0 4
3 2 1 0 4
0 1 2 3 4

*/
