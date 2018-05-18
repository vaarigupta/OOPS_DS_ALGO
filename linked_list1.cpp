#include<iostream>
using namespace std;
class node
{ public:
    int data1;
    node *next;
    node (int d)
    {
        data1 = d;
        next = NULL;
    }



};
void addatfront(node* &head , int data)
{
    if(head==NULL)
    {
        node *n = new node(data);
        n->next = NULL;
        head = n;

    }
    else
    {
       node *n1 = new node(data);
       n1->next = head;
       head =n1;

    }


}

void takedata(node*&head)
{
    int d;
    cout<<"Enter the value"<<endl;
    cin>>d;
    while(d!=-1)
    {
        addatfront(head,d);
        cout<<"Enter the value"<<endl;
        cin>>d;


    }
}
void print(node*head)
{   node* temp;
    temp= head;
    while (temp!=NULL)
    {
        cout<<temp->data1<<"=>";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}

int main()
{
    node *head = NULL;
    takedata(head);
    print(head);



    return 0;
}
