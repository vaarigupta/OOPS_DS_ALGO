#include<iostream>
using namespace std;
class node
{
  public:
      int data;
      node* Xor;

      node(int d)
      {
          data = d;
          Xor = NULL;
      }

};
void addAtFront(node * &head , int d)
{
    if(head==NULL)
    {
        node* n = new node(d);
        head = n;
        return ;
    }
    else
    {
        node* n = new node(d);
        n->Xor= head;
        head->Xor = n^(n->Xor);
        head = n ;
        return;
    }
}
void takeInput(node * &head)
{
    int d;
    cout<<"Enter the Elements:"<<endl;
    cin>>d;
    while(d!= -1)
    {
        addAtFront(head , d);
        cin>>d;

    }
    cout<<endl;

}
void print (node * head)
{
    cout<<"XOR Linked List :"<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<"=>";
        head = head->Xor;
    }
    cout<<endl;

}
istream& operator>>(istream & is , node* &head)
{
    takeInput(head);
    return is;
}
ostream & operator<<(ostream & os , node * head)
{
    print(head);
    return os;
}
int main()
{
    node* head = NULL;
    cin>>head;
    cout<<head;
    return 0;
}
