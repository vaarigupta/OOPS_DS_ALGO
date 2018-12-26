#include<iostream>
using namespace std;
class node {

public:
 int data ;
 node *next;

 node(int d)
 {
  data = d;
  next = NULL;
 }

};

void addAtFront( node* &head , int data)
{
    if(head == NULL)
    {
        node *n = new node(data);
        head = n;
        return;
    }
    else
    {
        node *n = new node(data);
        n->next = head;
        head = n;
        return;

    }
}
void takeInput(node *&head)
{
    int data;
    cout<<"Enter the Elements in the LL"<<endl;
    cin>>data;
    while(data!=(-1))
    {
        addAtFront(head,data);
        cin>>data;
    }
}
void print ( node *head)
{
    for(;head!=NULL; head = head->next)
    {
      cout<<head->data<<"=>";
    }
    cout<<endl;

}
ostream& operator<<(ostream &os , node *head)
{
    print(head);
    return os;
}
istream& operator >>(istream &is , node* &head)
{
    takeInput(head);
    return is;
}
int main()
{

node *head = NULL;
cin>>head;
cout<<head;
    return 0;
}
