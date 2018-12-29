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
void addAtFront(node *&head , int d)
{
    if(head == NULL)
    {
        node * n = new node(d);
        head = n;
        return;
    }
    else
    {
        node * n = new node(d);
        n->next = head ;
        head = n ;
    }
}
void takeInput(node *&head)
{
    int d ;
    cout<<"Enter the elements : "<<endl;
    cin>>d;
    while(d!= -1)
    {
        addAtFront(head , d);
        cin>>d;
    }
}
node* reverse (node *&head)
{
    node *prev = NULL;
    node * curr = head;
    node * nex = head;
    while(curr!= NULL && nex!= NULL)
    {
        ///Save the remaining List
        nex = curr->next;
        ///Point the current node to previous
        curr->next = prev;
        ///Update previous and current node
        prev = curr ;
        curr = nex;
        //nex = curr->next;
    }
    return prev;
}
void print(node * head)
{
    cout<<"Linked List : "<<endl;
    while(head!= NULL)
    {
        cout<<head->data<<"=>";
        head = head->next;
    }
    cout<<endl;
}
istream& operator>>(istream &is , node *&head)
{
    takeInput(head);
    return is;
}
ostream& operator <<(ostream &os , node *head)
{
    print(head);
    return os;
}
int main()
{
   node * head = NULL;
   cin>>head;
   cout<<head;
   cout<<"Reverse"<<reverse(head);


    return 0;
}
