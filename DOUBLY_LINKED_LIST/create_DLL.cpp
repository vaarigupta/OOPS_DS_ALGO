#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;

    ///Initializing node
    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
void addAtFront(node* &head , int d)
{
    if(head == NULL)
    {
        node * n = new node(d);
        head = n;
        return ;
    }
    else
    {
        node* n = new node(d);
        n->next = head;
        head->prev = n ;
        head = n;
    }
}
void takeInput(node* &head)
{
    int d ;
    cout<<"Enter the elements"<<endl;
    cin>>d;
    while(d!= -1)
    {
        addAtFront(head , d);
        cin>>d;

    }
    cout<<endl;
}
void print(node* head)
{
    cout<<"Doubly Linked List"<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<"=>";
        head = head->next;
    }
    cout<<endl;
}
int main()
{
    node * head = NULL;
    takeInput(head);
    print(head);

    return 0;
}
