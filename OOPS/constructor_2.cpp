#include<iostream>
#include<cstring>
using namespace std;
class swap_str
{
     char name[30];
     char name1[30];

public:
    swap_str()
    {
        cout<<"SWAPPING OF TWO STRINGS"<<endl;

    }
    swap_str(char *a , char *b)
    {
       strcpy(name , a);
       strcpy(name1,b);

    }
//    void get()
//    {
//        cout<<"Enter the first string"<<endl;
//        cin>>name;
//        cout<<"Enter the second string"<<endl;
//        cin>>name1;
//
//
//    }

 void swap1()
 {
     char temp[30];
     strcpy(temp,name);
     strcpy(name, name1);
     strcpy(name1,temp);
 }

    void display()
    {
        cout<<" Your first string is :"<<name<<endl;
        cout<<" Your second string is :"<<name1<<endl;;

    }
};
int main()
{

    swap_str s1("Vaari", "Abhishek");
    s1.swap1();
    s1.display();


}

