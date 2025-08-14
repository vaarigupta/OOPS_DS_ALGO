#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);

}
int cpFact(int A, int B)
{
   while(gcd(A,B)!=1)
   {
       A /= gcd(A,B);
   }
   return A;
}



int main()
{
    int a, b;
    cin>>a>>b;
    cout<<cpFact(a,b);
    return 0;
}
