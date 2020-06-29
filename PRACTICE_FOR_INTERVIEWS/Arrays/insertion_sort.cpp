#include<iostream>
using namespace std;
void print(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void insertion_sort(int *a, int n)
{

    for(int i=1;i<=n-1;i++)
    {
        int curr = a[i];
        int j=i-1;
        while(j>=0 && a[j]>curr)
        {
            a[j+1] =a[j];
            print(a,n);
            j--;
        }
        a[j+1]= curr;
        print(a,n);
    }

}
int main()
{
    int arr[] = {2,5,1,0,4};
    int n = sizeof(arr)/sizeof(int);
    insertion_sort(arr,n);
    print(arr,n);

    return 0;
}

/*

2 5 1 0 4
2 5 5 0 4
2 2 5 0 4
1 2 5 0 4
1 2 5 5 4
1 2 2 5 4
1 1 2 5 4
0 1 2 5 4
0 1 2 5 5
0 1 2 4 5
0 1 2 4 5

*/
