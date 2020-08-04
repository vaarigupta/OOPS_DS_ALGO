#include<iostream>
using namespace std;
/*
We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique numbers separated by space

Sample Input
4
3 1 2 1
Sample Output
2 3
Explanation
Smaller number comes before larger number

*/
void findTwoUniqueNo(int *a, int n)
{
    int res=0;
   for(int i=0;i<n;i++ )
   {
       res ^= a[i];
   }
   int j=0, temp =res;

   while(temp>0)
   {
       if(!temp&1)
       {
           j++;
           //break;
       }
       else
       {
           break;
       }
       temp >>= 1;

   }
    int mask = 1<<j;
    /// this mask will help us to nullify other number
    ///bcz set bit comes only from only one of the numbers
    /// and ANDing of mask with first number will definitely give only first number
    int firstNo = 0;
    for(int i=0;i<n;i++)
    {
        if(mask&a[i])
        {
           firstNo  ^= a[i];
        }

    }
    int secondNo = firstNo^res;
    cout<<"Unique No's are : "<<firstNo<<" "<<secondNo<<endl;

}
int main()
{
    int a[] = {1,1,2,2,3,3,5,5,6,6,7,8};
    int n = sizeof(a)/sizeof(int);
    findTwoUniqueNo(a,n);
    return 0;
}


