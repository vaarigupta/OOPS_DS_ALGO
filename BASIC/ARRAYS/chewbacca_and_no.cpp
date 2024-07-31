//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include<cstring>
//using namespace std;
//
//void chewbacca(string x)
//{
//    string ans = "";
//    int n = x.length();
//
//    if(x[0]> '4' && x[0] < '9')
//    {
//        ans += ('9' - x[0]) + '0';
//    }
//    else
//    {
//        ans += x[0];
//    }
//    for(int i=1;i<n;i++)
//    {
//       if(x[i]> '4' && x[i] <= '9')
//    {
//        ans += ('9' - x[i]) + '0';
//    }
//    else
//    {
//        ans += x[i];
//    }
//
//    }
//    cout<<ans;
//}
//
//int main() {
//   string  x;
//    cin>>x;
//    chewbacca(x);
//    return 0;
//}


#include<iostream>
using namespace std;
void chewbacca(string &x)
{
	//int n = x.length();
	int i=0;
	if(x[0]== '9')
	{
		i++;
	}
	for(;x[i]!='\0';i++)
	{
		if(x[i]> '4' && x[i]<= '9')
		{
			x[i] = ('9' - x[i]) + '0';
		}
		cout<<x[i]<<" ";
	}
	cout<<endl;
	cout<<x;

}
int main() {
	string x;
	cin>>x;
	chewbacca(x);
	return 0;
}
