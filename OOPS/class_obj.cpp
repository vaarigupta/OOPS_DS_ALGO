#include<iostream>
#include<cstring>
using namespace std;
class student
{
    int roll_no;
    char name[100];
public:
    student()
    {
        cout<<"Student's portal"<<endl;
        roll_no = 1;
        strcpy(name, "xyz");
    }
    void get_input()
    {
        cout<<"Enter the roll no "<<endl;
        cin>>roll_no;
        cout<<"Enter the name"<<endl;
        cin>>name;

    }
    void display()
    {
        cout<<"Roll No is :"<<roll_no<<endl;
        cout<<"Your Name is :"<<name<<endl;
        cout<<endl;
    }
};
int main()
{

   student s1;
   s1.get_input();
   s1.display();
   student s2;
   s2.display();
}
