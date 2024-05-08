#include<iostream>
using namespace std;
int solve(int A) {


    int count =0;
    for(int num=1;num<=A;num++)
    {
        while(num)
        {
            count += (num&1);
            cout<<num<<" "<<endl;
            num >>=1;

        }
    }

    return count;

}

int main()
{
    solve(4);
    return 0;
}
