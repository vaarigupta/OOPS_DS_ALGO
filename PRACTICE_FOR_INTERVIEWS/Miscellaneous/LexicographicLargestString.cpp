#include<iostream>
using namespace std;
string LexicographicLargest(string str)
{
    int n = str.length();
    int swaps = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(str[i]<str[j])
            {
                swap(str[i],str[j]);
                swaps++;
                if(swaps==1)
                    break;
            }
        }
        if(swaps==1)
             break;
    }

    return str;

}
int main()
{

    string str;
    cin>>str;
    str = LexicographicLargest(str);
    cout<<str;
}
