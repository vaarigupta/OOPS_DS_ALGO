#include<iostream>
#include<cstring>
using namespace std;
class car
{ public:
    int price;
    char *name;
    car()
    {
        price=0;
        name = NULL;
    }
    car (int p, char *n)
    {
        name = new char[strlen(n)+1];/// name pointer pointing to the char array formed on the heap
        strcpy(name , n);
        price = p; /// created on the stack

    }
    void print()
    {
        cout<<"price : "<<price<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<endl;
    }


};
int main()
{
   car A(100,"BMW");
   car B = A;
   B.price =200;
   B.name[1]='g';
   A.print();
   B.print();



}
