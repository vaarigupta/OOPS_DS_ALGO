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
void addAtend(node* &head , int d)
{
    if(head== NULL)
    {
        node * n = new node(d);
        head = n;
        return;
    }
    else
    {
        node* tail = head;
        while(tail->next!= NULL)
        {
          tail = tail->next;
        }
        node * n = new node(d);
        tail->next = n;

    }
}
void takeInput(node* &head)
{
    int d;
    cout<<"Enter the Elements"<<endl;
    cin>>d;
    while(d!= -1)
    {
        addAtend(head , d);
        cin>>d;
    }
    cout<<endl;
}
void print(node * head)
{
    cout<<"Linked List"<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<"=>";
        head = head->next;
    }
}
node* kthNodeEnd(node * head , int k)
{
    node* fast = head;
    node* slow = head;
    int cnt = 0;
    while(cnt!=k)
    {
        fast = fast->next;
        cnt++;
    }
    while(fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;

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
    node * head = NULL;
    int k;
    cin>>head;
    cout<<head<<endl;
    cout<<"Enter the kth node "<<endl;
    cin>>k;
    node * temp = kthNodeEnd(head , k);
    cout<<"Value from the end : "<<temp->data<<endl;
    return 0;
}
