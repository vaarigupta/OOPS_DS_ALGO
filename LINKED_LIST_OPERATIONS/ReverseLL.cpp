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
void addAtFront(node* &head , int d)
{
    if(head== NULL)
    {
        node *n = new node(d);
        head = n;
        return;
    }
    else
    {
        node *n = new node(d);
        n->next = head;
        head = n;

    }
}
void takeInput(node *&head)
{
    int d;
    cout<<"Enter the elements"<<endl;
    cin>>d;
    while(d!=(-1))
    {
        addAtFront(head,d);
        cin>>d;
    }
    cout<<endl;
}
void print(node * head)
{
    cout<<"Linked List:"<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<"=>";
        head = head->next;
    }
    cout<<endl;
}
node * length ( node* head)
{
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    if(temp->next==NULL)
    {
        return head;
    }
}
node * reverseLL(node *head)
{
    node * revHead = new node(head->data);
     node* temp = head->next;
    while(temp!=NULL)
    {

     addAtFront(revHead , temp->data);
     temp = temp->next;
    }
    return revHead;



}
istream& operator>>(istream & is , node *&head)
{
    takeInput(head);
    return is;

}
ostream & operator<<(ostream& os , node * head)
{
    print(head);
    return os;
}
int main()
{
    node *head = NULL;
    cin>>head;
    cout<<head;
   /// cout<<"Last Element : "<<length(head)->data<<endl;
   cout<<"Reverse LL :"<<reverseLL(head);
    return 0;
}
