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

void takedata(node*&head)/// we pass head by reference so we are building it and we dont want
/// to create any copy of this
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
void print(node*head) /// we pass by value as copy of head is passed not actual head
/// so that any change in head , does not affect the actual head like if we use head instead of temp
/// then head becomes NULL at the end of the func but we dont want thats y , we create local copy of head
{   node* temp;
    temp= head;
    while (temp!=NULL)
    {
        cout<<temp->data1<<"=>";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}
ostream& operator<<(ostream &o1, node* head)
{
    print(head);
    return o1;
}
istream& operator>> (istream &o1, node* &head)
{
    takedata(head);
    return o1;


}
void addatpos(node* &head , int data , int pos)
{
    if(pos==0)
    {
        addatfront(head, data);
    }
    else
    { int i=1;
        node*temp = head;
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
int length (node*head)
{    int cnt =0;
    node* temp = head;
    while(temp!=NULL)
    {
        cnt++;
        temp = temp->next;

    }
    return cnt;

}
void addattail(node*head )
{   int data;
    cout<<"Enter the value to be inserted at the tail of the linked list: "<<endl;
    cin>>data;
    addatpos(head , data , length(head));

}
node* printmid(node*head) /// returns the middle node of the linked list
{
    int t = length(head)/2;
    int i =1;
    node *temp = head;
    while(i<=(t-1))
    {
        temp = temp->next;
        i++;
    }
    return temp;

}
int main()
{   int d , pos;
    node *head = NULL;
    cin>>head;
    cout<<head<<endl;
    ///cout<<"Enter the data and position"<<endl;
    ///cin>>d>>pos;
    ///addatpos(head,d,pos);
    ///cout<<head;
    cout<<"Length of Linked list :- "<<length(head)<<endl;
    ///addattail(head);
    ///cout<<head;
    cout<<"The middle element is : "<<printmid(head)->data1;
    return 0;
}


