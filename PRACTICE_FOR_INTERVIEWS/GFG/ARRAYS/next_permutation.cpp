#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> v)
{

    for(int i=0;i<v.size();i++)
    {

        cout<<v[i]<<" ";
    }
    cout<<endl;
}
vector<int> nextPermutation(vector<int> &v, int n)
{
    int i = n - 1;
    while(i>0)
    {

        if(v[i-1]> v[i])
        {
         i--;
        }
        else
        {
            break;
        }
    }
    if(i==0)
    {
        sort(v.begin(),v.end());
        return v;
    }
    else
    {
   // i = i - 1;
    int x = v[i-1];
    int nextGreater = i;
    for(int j=i+1;j<n;j++)
    {
        if(v[j]>x && v[j]<v[nextGreater])
        {
            nextGreater = j;
        }
    }
    swap(v[i-1],v[nextGreater]);
    sort(v.begin()+i,v.end());
    return v;

    }

}
int main()
 {
	int t,n;
	cin>>t;

	while(t--)
	{
	    vector<int> v;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        int no;
	        cin>>no;
	        v.push_back(no);
	    }
	    v = nextPermutation(v,n);
	    print(v);
	}
	return 0;
}


//// C++ program to find the smallest number which greater than a given number
//// and has same set of digits as given number
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//// Utility function to swap two digits
//void swap(char *a, char *b)
//{
//	char temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//// Given a number as a char array number[], this function finds the
//// next greater number. It modifies the same array to store the result
//void findNext(char number[], int n)
//{
//	int i, j;
//
//	// I) Start from the right most digit and find the first digit that is
//	// smaller than the digit next to it.
//	for (i = n-1; i > 0; i--)
//		if (number[i] > number[i-1])
//		break;
//
//	// If no such digit is found, then all digits are in descending order
//	// means there cannot be a greater number with same set of digits
//	if (i==0)
//	{
//		cout << "Next number is not possible";
//		return;
//	}
//
//	// II) Find the smallest digit on right side of (i-1)'th digit that is
//	// greater than number[i-1]
//	//cout<<i<<endl;
//	int x = number[i-1], smallest = i;
//	for (j = i+1; j < n; j++)
//		if (number[j] > x && number[j] < number[smallest])
//			smallest = j;
//
//	// III) Swap the above found smallest digit with number[i-1]
//	swap(&number[smallest], &number[i-1]);
//
//	// IV) Sort the digits after (i-1) in ascending order
//	sort(number + i, number + n);
//
//	cout << "Next number with same set of digits is " << number;
//
//	return;
//}
//
//// Driver program to test above function
//int main()
//{
//	char digits[] = "534976";
//	int n = strlen(digits);
//	findNext(digits, n);
//	return 0;
//}
