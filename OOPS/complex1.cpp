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
    { if (img>=0)
    {
       cout<<"Complex No:"<<real<<" + "<<img<<"i"<<endl;
    }
    else
    {
        cout<<"Complex No:"<<real<<" - "<<(-1)*img<<"i"<<endl;
    }

    }

    void operator+(complex1 &c1)
    {
        real += c1.real;
        img +=c1.img;
    }
    void operator-(complex1 &c1)
    {
        real -= c1.real;
        img  -= c1.img;
    }
    complex1 operator*(complex1 &c2)
    {   complex1 c1;
        c1.real = real *c2.real;
        c1.img = img*c2.img;
        return c1;

    }
    void operator[](char *n)
    {
        if(n=="real")
        {
            cout<<"The Real Part of the complex No : "<<real<<endl;
        }
        else
        {
            cout<<"The imaginary part of the complex No : "<<img<<endl;
        }
    }
    };
int main()
{
    complex1 c1(1,2);
     c1.print();

     complex1 c2(7);
     c2.print();

     complex1 c3(1,4);
     c3.print();

     complex1 c4(10,20);
     c4.print();

     c2 + c3;
     c2.print();

     c3-c4;
     c3.print();

     complex1 c5(c4*c1);
     c5.print();

     c5["real"];
     c5["img"];


    return 0;
}

