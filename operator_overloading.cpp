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
    car ( car &X)
         /// this copy constructor helps in making deep copy in order to overcome
         /// the creation of shallow copy by the default copy constructor
    {
        price = X.price;
        name = new char[strlen(X.name) +1]; /// creating a new pointer pointing to another memory location on the heap
        strcpy(name , X.name);
    }
    void print()
    {
        cout<<"price : "<<price<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<endl;
    }

  void operator +( car &x)
  {
      ///char *old = name; /// here we just created a pointer x which points to the  name of the first car
       /// int a = strlen(name);/// length of name of first car
       ///int b = strlen(x.name); /// length of name of 2nd car
       name = new char[10]; /// created another dynamic char array of length a+b+1
       ///strcpy(name,old);
       ///strcpy(name+a,x.name);
       price +=x.price;
       ///delete []old;



  }

};
int main()
{
   car A(100,"BMW");
   car B = A; /// shallow copy is being created here as
   /// default copy constructor is being called by the compiler
   /// which is creating copy of the pointer due to which both the object
   /// will point to the same memory location on the heap
   /// so any changes made to the content on the (memory location)heap which is
   ///pointed by the pointer on the stack will make changes in the all the object
   /// irrespective of the particular object used for calling the data member
   /// to overcome this changes made to all the objects , we will have to create
   /// our own copy constructor , which is called deep copy of the object

   B.price =200;
   B.name[1]='g';
   A.print();
   B.print();
   A+B;
   A.print();




}

