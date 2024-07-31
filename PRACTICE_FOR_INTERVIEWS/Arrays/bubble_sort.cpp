#include<iostream>
#include<vector>
using namespace std;
void bubble_sort(vector<int> &arr, int n)
{
int count =0;

for(int i=0;i<n-1;i++)
{

	for(int j=0;j<n-i-1;j++)
	{
		if(arr[j]>arr[j+1])
		{
			swap(arr[j],arr[j+1]);
			count++;
		}

	}
}
cout<<count;
}
void optimized_bubble_sort(vector<int> &arr, int n)
{
	for(int i=0;i<n-1;i++)
	{
		bool swapped = false;
		for(int j=0;j<(n-1-i);j++)
		{
			if(arr[j]> arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped)
		{
			break;
		}
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
	bubble_sort(arr,n);

	//optimized_bubble_sort(arr,n);
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
