#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node*&head, int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node * n = new node(d);
    n->next = head;
    head = n;
}

void insertAtTail(node * &head, int d)
{
    if(head==NULL)
    {
        insertAtHead(head,d);
        return;
    }
    node * temp=head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(d);

}

void buildList(node *&head)
{
    int d;
    cout<<"Enter the Elements :"<<endl;
    cin>>d;
    while(d!=-1)
    {
        insertAtTail(head,d);
        cin>>d;
    }
}
void printList(node *head)
{
    if(head==NULL)
    {
        return;
    }
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    return;
}
istream & operator>>(istream &is , node * &head)
{
    buildList(head);
    return is;
}
ostream & operator<<(ostream &os , node* head)
{
    printList(head);
    return os;
}

void reverseList(node *&head)
{
    node * prev = NULL;
    node* curr = head;
    node* N = NULL;
    while(curr!=NULL)
    {
        N = curr->next;
        curr->next = prev;
        prev = curr;
        curr = N;
    }
    head = prev;
}

node* reverseRecursive(node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node *smallHead = reverseRecursive(head->next);
    node* curr = head;
    curr->next->next = curr;
    curr->next = NULL;
    return smallHead;

}


int main(){


    ///Create a LL of nodes
    node* head = NULL;


    cin>>head;
    cout<<head<<endl<<endl;
    cout<<"Reverse A list "<<endl;
    head = reverseRecursive(head);
    cout<<head;


return 0;
}
