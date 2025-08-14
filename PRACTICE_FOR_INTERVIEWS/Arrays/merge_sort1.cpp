#include<iostream>
using namespace std;
void merge(int arr[], int s, int e, int mid)
{
	int n1 = mid-s+1;
	int n2 = e-mid;
	int left[n1], right[n2];
	for(int i=0;i<n1;i++)
	{
		left[i] = arr[s+i];
	}
	for(int i=0;i<n2;i++)
	{
		right[i] = arr[mid+1+i];
	}
	int i=0, j=0, k=s;
	while(i<n1 && j<n2)
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
	while(i<n1)
	{
		arr[k++] = left[i++];
	}
	while(j<n2)
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
	int mid = (s+e)/2;
	merge_sort(arr,s,mid);
	merge_sort(arr,mid+1,e);
	merge(arr,s,e,mid);

}
int main()
{
	int n;
	cin>>n;
	int arr[1000];
	for(int i=0;i<n;i++)
	{
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
