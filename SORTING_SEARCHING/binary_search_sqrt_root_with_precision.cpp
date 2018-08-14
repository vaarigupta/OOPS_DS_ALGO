#include<iostream>
using namespace std;
/// Doing binary search to find out the square root of a number
int sqrtRoot(int num)
{
    int s=0, e=num , mid ,ans;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(mid*mid == num)
          {
              ans = mid;
              break;
          }
        if(mid*mid < num)
        {
            s = mid +1;
            ans = mid;
        }
        else
        {
            e = mid -1;
        }

    }

    return ans;
}
int main()
{
    int num ;
    cout<<"Please!! Enter the number"<<endl;
    cin>>num;
    cout<<"Square Root of "<<num<<" is "<<sqrtRoot(num) ;
    return 0;
}
