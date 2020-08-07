#include<bits/stdc++.h>
using namespace std;
//bool isPower(int n)
//{
//    if(n==1)
//    {
//        return true;
//    }
//    if(n<=0)
//    {
//        return false;
//    }
//
//   for(int i=2;i<=sqrt(n);i++)
//   {
//       double val = log(n)/log(i);
//       if(val- (int)val==0)
//       {
//           return true;
//       }
//   }
//   return false;
//}


//bool isPower(int a)
//{
//	if (a == 1)
//		return true;
//
//	for (int i = 2; i * i <= a; i++) {
//		double val = log(a) / log(i);
//		if ((val - (int)val) < 0.00000001)
//			return true;
//	}
//
//	return false;
//}
bool isPower(int n)
{
    if(n<1)
    {
        return false;
    }
    if(n==1)
    {
        return true;
    }
    for(int i=2;i*i<=n;i++)
    {
        int p = i;
        while(p<=n)
        {
            if(p==n)
            {
                return true;
            }
            p *=i;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;

    if(isPower(n))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"No " <<endl;
    }
    return 0;
}

