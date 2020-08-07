#include<iostream>
using namespace std;
bool IsPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i ==0)
        {
           return false;
        }
    }
    return true;
}

int Primes[10005];
void PreComputePrime(int range)
{
   Primes[0] =2;
   int k =1;
    for(int i=3;i<range;i += 2)
    {
      if(IsPrime(i))
      {
          Primes[k]= i;
          k++;
      }
    }
}
int main()
{  int range = 100000;
   PreComputePrime(range);
   int t,n;
   cin>>t;
   for(int i=0;i<t;i++)
   {
     cin>>n;
     cout<<Primes[n-1]<<endl;
   }
   return 0;

}
