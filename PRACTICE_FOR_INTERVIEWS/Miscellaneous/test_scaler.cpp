#include<iostream>
using namespace std;

int printTrib(int n)
{

    if(n==0 || n==1 || n==2)
    {
        return 0;
    }
    if(n==3)
        return 1;
    else
        return printTrib(n-1) + printTrib(n-2) + printTrib(n-3);
}

int fun(int A, int B)
{
    if(B==0)
        return A;
    else
        return fun(B, A%B);
}
int main()
{

    int ans = fun(100,2000);
    printf("%d",ans);

//    int i=0, sum =0;
//    while(i<100)
//    {
//
//        sum = sum +i;
//        sum = i+sum;
//        i+=1;
//    }
//    cout<<sum;
//for(int i=1;i<10;i++)
//{
//
//    cout<<printTrib(i)<<" ";
//};
return 0;
}
