#include<iostream>
#include<vector>
using namespace std;
void selection_sort(vector<int> &arr, int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				swap(arr[i],arr[j]);
			}
		}
	}

}
///improved
void selection_sort1(vector<int> &arr, int n)
{
	for(int i=0;i<n-1;i++)
	{
		int minIndex = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[minIndex]>arr[j])
			{
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}

}

int main()
{
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		arr.push_back(num);
	}
	selection_sort(arr,n);
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
