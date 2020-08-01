#include<iostream>
#include<vector>
using namespace std;
void insertion_sort(vector<int> &arr, int n)
{
	for(int i=1;i<=n-1;i++)
	{
		int num = arr[i];
		int j=i-1;
		while(j>=0)
		{
			if(num<arr[j])
			{
				arr[j+1] = arr[j];
				j--;

			}
			else
			{
				break;
			}

		}
		arr[j+1] = num;
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
	insertion_sort(arr,n);
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

