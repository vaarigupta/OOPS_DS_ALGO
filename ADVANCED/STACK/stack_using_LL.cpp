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
void addAtHead(node* &head , int d)
{
    if(head == NULL)
    {
        node * n = new node(d);
        head = n;
        return ;
    }
    else
    {
        node * n = new node(d);
        n->next = head;
        head = n;
        return ;
    }

}
void takeInput(node*&head)
{
    int d;
    cout<<"Insert the Elements in the Stack"<<endl;
    cin>>d;
    while(d!= -1)
    {
        addAtHead(head , d);
        cin>>d;
    }
}
void print(node*head)
{
    cout<<"Stack : - ";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        node * temp = head;
        head = head->next;
        delete temp;
    }
}
istream & operator>>(istream &is ,node* &head)
{
    takeInput(head);
    return is;
}
ostream & operator<<(ostream &os , node*head)
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
