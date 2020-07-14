#include<bits/stdc++.h>
using namespace std;
void farthest_co_prime(int *arr, int n)
{
    int farthest_coprimes[251] = {0};
    for(int i=0;i<n;i++)
    {
        int max_diff = INT_MIN , co_prime =0;
        for(int j=2;j<=250;j++)
        {
            int diff = abs(arr[i]-j);
            if(diff >max_diff && __gcd(arr[i],j)==1)
            {
                max_diff = diff;
                co_prime = j;
            }
        }
        farthest_coprimes[i] = co_prime;
    }
    for(int i=0;i<n;i++)
    {
        cout<<farthest_coprimes[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[251];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    farthest_co_prime(arr,n);


}
