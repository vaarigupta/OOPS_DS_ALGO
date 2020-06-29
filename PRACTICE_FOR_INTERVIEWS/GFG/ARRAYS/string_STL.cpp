#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string str = "1234";
    int num = stoi(str);
    cout<<num<<endl;
    string str1 = "HELLO WORLD ! ";
    string str2 = "GEEKY PEOPLE ";
    //str1.append(str2,2,3);
    //str1.append("VAARI");
    //str1.append("ASHANKA", 4);
    //str1.append(4,'4');
    str1.append(str2.begin()+7, str2.end());
    cout<<str1<<endl;


    return 0;
}
