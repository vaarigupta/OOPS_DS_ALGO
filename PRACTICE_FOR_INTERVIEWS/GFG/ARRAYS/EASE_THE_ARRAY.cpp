#include<iostream>
using namespace std;
int main()
{
    int t , a[100] ,n;
    cin>>t;
    for(int i =0;i<t;i++)
    {
        cin>>n;
        int *a = new int[n];
        for(int j =0;j<n;j++)
        {
            cin>>a[j];

        }

        int *b = new int[n];
         int k = 0;
         for(int j =0;j<n;j++)
        {

           if(a[j]== 0)
           {
               b[n-k]=0;
               j++;
           }
           else
           {
               b[k] = a[j];
               k++;
           }

        }
        for(int j =0;j<n;j++)
        {
            int curr = b[j];
            int next = b[j+1];
            if(curr == next)
            {
                curr *= 2;
                next = 0;
            }
            int k = j+1;
            while(a[k]==0)
            {
                k++;
            }
            if(a[k]!= 0)
            {
                swap(a[k],a[j+1]);
            }

        }
        for(int j=0;j<n;j++)
        {
           cout<<b[j]<<" ";
        }
        cout<<endl;

    }
    return 0;
}
