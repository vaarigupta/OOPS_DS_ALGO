#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ///Declaring a vector
    ///vector - Resizable arrays which doubles its size
     vector<int>  v;
     for(int i = 1;i<=4;i++)
     {
         /// push_back() - pushing or inserting elements into the vector
         v.push_back(i*i);
     }
     ///size()- used to calculate the size of the vector
     for(int i = 0;i<v.size();i++)
     {
         cout<<v.at(i)<<" ";
         ///at() - used to print elements at position i
     }
     cout<<endl;
     v.pop_back();
     for(int i = 0;i<v.size();i++)
     {
         cout<<v[i]<<" ";
     }
     cout<<endl<<v.capacity(); /// Tells about the capacity of the vector
    return 0;
}
