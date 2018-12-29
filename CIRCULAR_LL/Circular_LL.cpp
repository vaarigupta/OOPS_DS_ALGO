#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void addAtFront(node *&head , int d )
{
    if(head == NULL)
    {
        node * n = new node(d);
        head = n;
        n->next = head;
        return ;
    }
    else
    {
        node * n = new node(d);
        n->next = head->next;
        head->next = n;

    }
}
 void takeInput(node* &head )
 {
     int d;
     cout<<"ENTER THE ELEMENTS"<<endl;
     cin>>d;
     while(d!= -1)
     {
         addAtFront(head ,d);
         cin>>d;
     }
 }
 void print (node *head)
 {
     node * temp = head;
     cout<<"Circular Linked List"<<endl;
     do
     {
         cout<<temp->data<<"=>";
         temp = temp->next;
     }while(temp!=head);

 }
 istream & operator>>(istream &is , node*&head)
 {
     takeInput(head);
     return is;
 }
 ostream & operator<<(ostream &os, node*head)
 {
     print(head);
     return os;
 }
int main()
{
    node * head = NULL;
    cin>>head;
    cout<<head;
    return 0;
}
