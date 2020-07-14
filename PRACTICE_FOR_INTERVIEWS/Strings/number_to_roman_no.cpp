#include<bits/stdc++.h>
using namespace std;
string repeatedString(string x, int cnt)
{
    string output = "";
    for(int i=0;i<cnt;i++)
    {
        output += x;
    }
    return output;
}
string convertToRoman(int n)
{
    map<int, string> mapping = {{1,"I"}, {4, "IV"},
    {5, "V"}, {9, "IX"},
    {10, "X"}, {40, "XL"},
    {50, "L"}, {90, "XC"},
    {100, "C"}, {400, "CD"},
    {500, "D"},{900, "CM"},
    {1000, "M"}};
    vector<int> romans{1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string  output = "";
    int i=0,cnt=0;
    while(n>0)
    {
        cnt = 0;
        for(i=0;i<romans.size();i++)
        {
            int base = n/romans[i];
            if(base>0)
            {
                n = n%romans[i];
                cnt = floor(base);
                break;
            }
        }
        output += repeatedString(mapping[romans[i]],cnt);

    }
    return output;

}
int main()
{
    //cout<<repeatedString("AB",4);
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        cout<<convertToRoman(n)<<endl;
    }
    return 0;
}

  //    for(auto x: mapping)
//    {
//        cout<<x.first<<" => "<<x.second<<endl;
//    }
//    pair<int, string> helper[20] = {make_pair(1,"I"), make_pair(4, "IV"),
//   make_pair(5, "V"), make_pair(9, "IX"),
//   make_pair(10, "X"), make_pair(40, "XL"},
//    make_pair(50, "L"), make_pair(90, "XC"),
//    make_pair(100, "C"), make_pair(400, "CD"),
//    make_pair(500, "D"),make_pair(1000, "M")};
//    for(int i=0;i<romans.size();i++)
//    {
//        cout<<romans[i]<<" ";
//    }
