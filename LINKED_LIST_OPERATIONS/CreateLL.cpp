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
        else{
        node *n = new node(d);
        n->next = head;
        head = n;
       return ;

        }



    }
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
    void insertAtPosition(node *&head , int data , int pos)
    {

        if(pos == 0)
        {
            addAtFront(head , data);
            return;
        }
        else
        {
        int i = 1;
        node *temp = head;
        while(i<=(pos-1))
        {
           temp = temp->next;
           i++;
        }
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;

        }

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
    int d , p;
    node *head1 = NULL;
    node *head2= NULL;
    cin>>head1;
   cout<<head1;
   int l = length(head1);
   cout<<"Number of Nodes : "<<l<<endl;
   cout<<"Enter the data and position";
   cin>>d>>p;
   insertAtPosition(head1 , d , p);
   cout<<"Linked List after Insertion"<<endl<<head1;

    return 0;
}
