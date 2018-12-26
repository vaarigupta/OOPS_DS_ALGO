#include<iostream>
using namespace std;
class node
{

public:
    int data;
    node *next;

    node(int d)
    {

        data = d;
        next = NULL;
    }

};
void addAtFront(node *&head , int d)
    {
        if(head== NULL)
        {
            node *n = new node(d);
            head = n;
            return;
        }
        node *n = new node(d);
        n->next = head;
        head = n;
       return ;


    }
//void insertAtTail(node *&head)
//{
//    cout<<"Insert number at the tail"<<endl;
//    int d;
//    cin>>d;
//    node  *&save = head;
//    node *&temp = head;
//    while(temp!=NULL)
//    {
//        temp = temp->next;
//    }
//    if(temp->next == NULL)
//    {
//        node *n = new node(d);
//        temp->next = n;
//    }
//
//}
    void takeInput(node *&head)
    {
        int i;
        cout<<"Enter the Values for LL"<<endl;
        cin>>i;
        while(i!= (-1))
        {
            addAtFront(head , i);
            cin>>i;

        }

    }
    int length(node *head)
    {
        int l =1;
        for(;(head->next)!=NULL;head = head->next)
        {
            l++;

        }
        return l;
    }
    void print(node *head)
    {

        while(head!= NULL)
        {

            cout<<head->data<<"=>";
            head = head->next;
        }
        cout<<endl;
    }

    ostream& operator <<(ostream &os , node *head)
    {
        print(head);
        return os;
    }
istream& operator>>(istream& is , node* &head)
{
    takeInput(head);
    return is;

}

int main()
{
    node *head1 = NULL;
    node *head2= NULL;
        //    takeInput(head1);
     //    takeInput(head2);
     //    print(head);
    //    print(head);
    cin>>head1;
   cout<<head1;
   //insertAtTail(head1);
   int l = length(head1);
   cout<<"Number of Nodes"<<l;

    return 0;
}
