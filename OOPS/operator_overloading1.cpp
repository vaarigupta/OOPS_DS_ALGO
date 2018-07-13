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

  void operator-( car &x)
  {
      char *old = name; /// here we just created a pointer x which points to the "BMW" ( name of the first car )as
      /// if this is not done then its name will be lost due to changing its address in the following step
        int a = strlen(name);/// length of name of first car
       int b = strlen(x.name); /// length of name of 2nd car
       name = new char[a+b+1]; /// created another dynamic char array of length a+b+1 , this is the step where
       /// the overwriting of name pointer takes place as firstly it was pointing to "BMW" (name of first car array)
       /// now its pointing to the char array on heap having length of a+b+1
       strcpy(name,old);/// here we copy the name of first car stored in old array( dynamic)
       strcpy(name+a,x.name);///here we copy the name of second car at the position afterwards from a means after 3 ("BMW")letter
       price +=x.price;
       delete []old;
  }
  /*void operator+( car &x)
  {
      char *old = name; /// here we just created a pointer x which points to the "BMW" ( name of the first car )as
      /// if this is not done then its name will be lost due to changing its address in the following step
        int a = strlen(name);/// length of name of first car
       int b = strlen(x.name); /// length of name of 2nd car
       name = new char[a+b+1]; /// created another dynamic char array of length a+b+1 , this is the step where
       /// the overwriting of name pointer takes place as firstly it was pointing to "BMW" (name of first car array)
       /// now its pointing to the char array on heap having length of a+b+1
       strcpy(name,old);/// here we copy the name of first car stored in old array( dynamic)
       strcpy(name+a,x.name);///here we copy the name of second car at the position afterwards from a means after 3 ("BMW")letter
       price +=x.price;
       delete []old;
  }
  */
  car& operator+(car &x)
  {
      car *a = new car;
      int l1 = strlen(name);
      int l2 = strlen(x.name);
      a->name = new char[l1+l2+1];
      strcpy(a->name,name);
      strcpy(a->name +l1,x.name);
      a->price = price+ x.price;
      return *a;
  }
   void operator[](char *n)
   {
       cout<<n<<" is sitting in the "<<name<<endl;
   }
   void operator !()
   {
       cout<<name <<" car is not available ...sorry!!"<<endl;
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
   car C(250,"Nissan");
   C.print();
   car D (400,"Lamborghini");
   D.print();
   car E(C+D); /// or E = C+D;
   E.print();

    car F ;
    F = C+A;
    F.print();
    A-D;
    A.print();
    A["Vaari"];
    !D;
  /// when I use '+' in both the func of operator overloading then it gives an error ..why there is
  ///an error at commented line 49 but I dont find any error when the operators used are different



}

