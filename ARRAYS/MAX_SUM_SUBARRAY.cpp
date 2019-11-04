#include<iostream>
using namespace std;
void printSubarray(int *a , int s, int e)
{
    for(int i=s;i<=e;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void max_sum_subarrays1(int *a, int n)
{
    int cs = 0 , maxS = INT_MIN;
    int left =0 , right =0;
    for(int i=0;i<n;i++)
    {

        for(int j=i;j<n;j++)
        {
            cs = 0;
            for(int k=i;k<=j;k++)
            {
                cs += a[k];
            }
            if(cs> maxS)
            {
                maxS =cs;
                left = i;
                right = j;
            }
            //cout<<endl;
        }
    }
    cout<<"max sum :"<<maxS<<endl;
    printSubarray(a,left,right);

}

void max_sum_subarrays2(int *a, int n)
{
    int cs = 0 , maxS = INT_MIN;
    int left =0 , right =0;
    int *csum = new int[n]{0};
    csum[0] = a[0];
    for(int i=1;i<n;i++)
    {
        csum[i] = csum[i-1] + a[i];
    }
    for(int i=0;i<n;i++)
    {

        for(int j=i+1;j<n;j++)
        {
            cs = csum[j] - csum[i-1];
            if(cs> maxS)
            {
                maxS = cs;
                left = i;
                right = j;
            }

        }

    }
    delete[] csum;
    cout<<"max sum :"<<maxS<<endl;
    printSubarray(a,left,right);

}
void max_sum_subarrays3(int *a, int n)
{
    int curr_sum = 0 , max_sum = INT_MIN;
    int left =0, right = 0;
    for(int i=0;i<n;i++)
    {
        curr_sum += a[i];
       if(curr_sum<0)
       {
           curr_sum = 0;
           right = i;
       }
       if(curr_sum> max_sum)
       {
           max_sum = curr_sum;
           left = i;

       }


    }
    cout<<"max sum  "<<max_sum<<endl;
    printSubarray(a,left,right);
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    max_sum_subarrays2(a,n);
    //subarrays(a,n);

    return 0;
}

/*

9
-4 1 3 -2 6 2 -1 -4 -7
4
-1 2 3 -4
max sum  5

4
1 2 3 4

1
1 2
1 2 3
1 2 3 4
2
2 3
2 3 4
3
3 4
4

*/
