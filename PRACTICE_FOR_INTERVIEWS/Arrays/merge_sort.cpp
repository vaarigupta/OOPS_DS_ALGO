#include<iostream>
using namespace std;
void merge(int *arr, int *left, int *right, int s, int e, int mid)
{
    int i=s, j= mid+1,k=s;
    while(i<=mid && j<=e)
    {
        if(left[i]<=right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while(i<=mid)
    {
         arr[k++] = left[i++];
    }
    while(j<=e)
    {
        arr[k++] = right[j++];
    }
}
void merge_sort(int* arr, int s, int e)
{
    if(s>=e)
    {
        return;
    }

    int mid = s + (e-s)/2;
    int left[100];
    int right[100];
    for(int i=s;i<=mid;i++)
    {
        left[i] = arr[i];
    }

    for(int i=mid+1;i<=e;i++)
    {
        right[i] = arr[i];
    }
    merge_sort(left,s,mid);
    merge_sort(right,mid+1,e);
    merge(arr, left,right,s,e,mid);
}
//void print(vector<int> arr, int n)
//{
//    for(int i=0;i<n;i++)
//    {
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//}
int main()
{
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<n;i++)
	{
		//int num;
		cin>>arr[i];

	}
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

/*
5
2 3 1 0 5
*/
