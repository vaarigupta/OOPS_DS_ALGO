#include<bits/stdc++.h>
using namespace std;

void print(string arr[], int i, int n)
{

    if(i == n)
        return;

    cout<<"<"<<arr[i]<<">"<<endl;
    print(arr,i+1,n);
    cout<<"</"<<arr[i]<<">"<<endl;

}
int main()
{

    string arr[5] = {"HTML", "Body","H1","br", "p1"};

    int n = 5;
    print(arr,0,n);
    return 0;
}

//landi gyr interview question

