#include<bits/stdc++.h>
using namespace std;
void remove_duplicates(string str)
{
    string output = "";
     unordered_map<char, bool> mapping;
     for(int i=0;str[i]!='\0';i++)
     {
         mapping[str[i]] = true;
     }
      for(int i=0;str[i]!='\0';i++)
     {
         if(mapping[str[i]])
         {
             output+= str[i];
             mapping[str[i]] = false;
         }
     }
     cout<<output<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        getline(cin,str);
        while (str.length()==0 )
            getline(cin, str);
        remove_duplicates(str);
    }


	return 0;
}
