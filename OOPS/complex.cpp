#include<iostream>
using namespace std;
class complex1
{
    int real;
    int img;
    public:
    complex1()  /// complex no having 0 real n img part
    {
        real = 0;
        img = 0;

    }
    complex1(int r , int i) /// complex no having different real n img part

    {
        real = r;
        img = i;
    }
    complex1(int a) /// complex no having same real n img part
    {
       real = a;
       img = a;

    }
    void input()
    {   cout<<"Enter the Real and Imaginary"<<endl;
        cin>>real>>img;
    }
    void print()
    {
        cout<<"Complex No:"<<real<<" + "<<img<<"i"<<endl;
    }
    };
int main()
{
    complex1 c1;
     c1.input();
     c1.print();
     complex1 c2(7);
     c2.print();
     complex1 c3(1,4);
     c3.print();


    return 0;
}
