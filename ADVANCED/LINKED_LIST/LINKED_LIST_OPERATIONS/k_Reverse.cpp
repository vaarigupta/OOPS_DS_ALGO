#include<iostream>
using namespace std;
///Incomplete Solution
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
node* reverse(node* head)
{
    node *prev = NULL;
    node* curr = head;
    node*nex = head;
    while(nex!=NULL)
    {
        nex = nex->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}
void kReverse(node* head , int k)
{
    node * savePtr = new node[](0);
    node * temp = head;
    int cnt = 1;
    savePtr[1]= head;
    while(temp!=NULL)
    {
        if(cnt%k ==0)
        {
            temp->next = savePtr[cnt];

        }
        temp = temp->next;
        cnt++;
    }



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
    node* head = NULL;
    cin>>head;
    cout<<head;

    return 0;
}
