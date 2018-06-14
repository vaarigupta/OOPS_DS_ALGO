#include<iostream>
using namespace std;
class node
{   public:
    int data;
    node* next;
    node(int d)
    {
        data = d;
        next = NULL;
    }

};

void addatfront(node *&head , int data)
{
  if(head==NULL)
  {
     node *n = new node(data);
     n->next = NULL;
     head = n;

  }
  else
  {
     node *n1 = new node (data);
     n1->next = head;
     head = n1;

  }

}
void takenode(node *&head)
{
    int d;
    cout<<"Enter the value"<<endl;
    cin>>d;
    while(d!=-1)
    {
        addatfront(head, d);
        cin>>d;
    }

}
void print( node *head)
{
    node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"=>";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
ostream& operator<<(ostream &o1,node *& o2)
{
    print(o2);
    return o1;
}
istream& operator>>(istream &o1 , node * &o2)
{
    takenode(o2);
    return o1;
}
node* merge1(node *h1 , node *h2)
{

    ///base case
   if(h1==NULL)
   {
       return h2;
   }
   if (h2 ==NULL)
   {
       return h1;
   }

    ///rec case
      node *h3;
      if(h1->data < h2->data)
      {
          h3 = h1;
          h3->next = merge1(h1->next , h2);
      }
      else
      {
          h3 = h2;
          h3->next = merge1(h1 , h2->next);
      }
      return h3;
}
int main()
{
   node *head1 =NULL;
   node *head2 = NULL;
   takenode(head1);
   print(head1);
   cin>>head2;
   cout<<head2;
   head1 = merge1(head1 , head2);
   cout<<head1;
 return 0;
}
