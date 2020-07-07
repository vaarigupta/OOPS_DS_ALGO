#include<bits/stdc++.h>
using namespace std;
double median(vector<int> arr1, vector<int> arr2, int m, int n)
{
    int i=0, j=0,k=0, index=0;
    //int m1=0, m2=0;
    vector<int> arr3(n+m,0);
    while(i<m && j<n)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            arr3[k] = arr2[j];
            j++;
        }
        else
        {
            arr3[k] = arr1[i];
            arr3[k+1] = arr2[j];
            i++;
            j++;
        }
        k++;

    }
    while(i<m)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while(j<n)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }

//    for(int p=0;p<k;p++)
//    {
//        cout<<arr3[p]<<" ";
//    }
//    cout<<endl<<k<<endl;
    if(k&1)
    {
        index = k/2;
        return arr3[index];
    }
    else
    {
        index = k/2;
        double value = (arr3[index] + arr3[index-1])/2;
        return value;
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> arr1,arr2;
    for(int i=0;i<m;i++)
    {
        int num;
        cin>>num;
        arr1.push_back(num);
    }
    for(int j=0;j<n;j++)
    {
        int num;
        cin>>num;
        arr2.push_back(num);

    }
    cout<<median(arr1,arr2,m,n);
    return 0;
}
/*
3 3
1 4 7
2 5 6


3 4
1 4 7
2 5 6 8

3 8
1 4 7
2 5 6 8 8 9 10 11
1 2 4 5 6 7 8 8 9 10 11
*/
