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
        node * tail = n;
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
void addAtEnd(node* head , int d)
{
    while(head->next!=NULL)
    {
        head = head->next;
    }


    node * tail = head;
    node* n = new node(d);
    tail->next = n ;
    n->prev = tail;
    tail = n ;



}
void addAtMiddle(node* head , int d)
{
    node* slow = head ;
    node * fast = head->next;
    while(fast!= NULL && (fast->next)!= NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node * mid = slow;
    node * n = new node(d);
    n->next = mid->next;
    mid->next->prev=n;
    n->prev = mid;
    mid->next = n;
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
        cout<<head->data<<"<=>";
        head = head->next;
    }
    cout<<endl;
}
istream & operator>>(istream &is , node* &head)
{
    takeInput(head);
    return is;
}
ostream & operator<<(ostream &os , node* head)
{
    print(head);
    return os;
}
int main()
{
    node * head = NULL;
    int d;
    cin>>head;
    cout<<head;
    cout<<"Enter the number to add at end "<<endl;
    cin>>d;
    addAtEnd(head ,d);
    cout<<"At the End"<<endl<<endl<<head;
    addAtMiddle(head , d);
    cout<<"In the Mid"<<endl<<endl<<head;


    return 0;
}
