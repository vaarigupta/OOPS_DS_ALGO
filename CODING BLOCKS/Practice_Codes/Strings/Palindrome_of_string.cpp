#include<iostream>
#include<cstring>
using namespace std;
bool palindrome( char* a,char *b)
{
    int n1 = strlen(a);
    int n2 = strlen(b);
    int i=0, j=n2-1;
    if(n1==n2)
    {
        while(a[i]==b[j] && (i<j))
        {
            i++;
            j--;
        }
        if(i==j)
        {
            return true;
        }
    }
    return false;


}
int main()
{
    char a[100],b[100];
    cin.getline(a,100);
    cin.getline(b,100);
    if(palindrome(a,b))
    {
        cout<<"Yes, strings are palindromes of each other "<<endl;
    }
    else
    {
        cout<<"No, strings are not  palindromes of each other "<<endl;
    }


    return 0;
}



