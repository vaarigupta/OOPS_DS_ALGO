#include<iostream>
#include<cstring>
using namespace std;
class car
{ int price =100;
  char name[30];
  public:
  car()
  {
      cout<<"Creating a car by default constructor"<<endl;
      strcpy(name,"xyz");
  }
  car(int p, char *n) /// parameterised constructor
  {   cout<<"Car is created by parameterised constructor"<<endl;
      strcpy(name,n);
      if(p>price)
      {
        price = p;
      }
      else
      {
          price = 100;
      }
  }
  void print()
  {
      cout<<"Price :"<<price<<endl;
      cout<<"Name :"<<name<<endl;
  }
  car (car &X) /// copy constructor -> always pass the value by reference
  {
      cout<<"Car is created by copy constructor"<<endl;
      price = X.price;
      strcpy(name , X.name);

  }
  ~car()
  {
      cout<<"Destroying the car : "<<name<<endl;
  }


};
int main()
{
  car A;
  car B(101,"BMW");
  B.print();
  car C(B);///copy constructor
  C.print();
  car D = B;
  D.print();
  car E ;/// default constructor is being called
  E = A; /// copy assignment constructor is being called here
  E.print();
  car *F = new car (1200,"Ferrari");
  (*F).print();
  delete F;


return 0;
}
