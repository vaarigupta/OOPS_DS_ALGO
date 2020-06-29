#include<iostream>
using namespace std;
int reverseInt(int n)
{
    long long rev = 0;
    int temp = n;
    while(temp)
    {
        rev = rev*10 + (temp%10);
        if(rev> INT_MAX || rev < INT_MIN )
        {
            return 0;
        }
        temp /= 10;
    }
    return rev;
}

int main()
{
     int n;
    cin>>n;
    cout<<reverseInt(n);
    return 0;
}
