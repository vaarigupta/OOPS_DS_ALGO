#include<bits/stdc++.h>
using namespace std;
//vector<int> flip(string A) {
//    int l = 0, lmax = -1, rmax = -1;
//    int maxi = 0, cmax = 0;
//    int len = A.length();
//    for(int i=0;i<len;i++) {
//        cmax += (A[i]=='0'?1:-1);
//        if(cmax>maxi) {
//            maxi = cmax;
//            lmax = l;
//            rmax = i;
//        }
//        if(cmax<0) {
//            l = i+1;
//            cmax = 0;
//        }
//    }
//    if(lmax == -1 || rmax == -1) {
//        return vector<int>(0, 0);
//    }
//    vector<int> t(2, 0);
//    t[0] = lmax+1;
//    t[1] = rmax+1;
//    return t;
//}
//

vector<int>  flip(string A) {

    int left = -1, right = -1 , currMax = 0, newleft = 0, max = 0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='0') currMax += 1;
        else currMax += -1;
        if(currMax > max)
        {
            max = currMax;
            left = newleft;
            right = i;
        }
        if(currMax < 0)
        {
            currMax = 0;
            newleft = i+1;
        }

    }

    if(left== -1 || right== -1)
    {
        return vector<int>(0);
    }
     vector<int> ans(2,0);
    ans[0] = left +1;
    ans[1] = right +1;
    //cout<<ans[0]<<" "<<ans[1];
    return ans;

}



int main()
{
    string str;
    cin>>str;
    vector<int> v = flip(str);
    for(auto no : v)
    {
        cout<<no;
    }
    return 0;
}

