#include<iostream>
using namespace std;
class node {

public:
 int data ;
 node *next;

 node(int d)
 {
  data = d;
  next = NULL;
 }

};

void addAtFront( node* &head , int data)
{
    if(head == NULL)
    {
        node *n = new node(data);
        head = n;
        return;
    }
    else
    {
        node *n = new node(data);
        n->next = head;
        head = n;
        return;

    }
}
void takeInput(node *&head)
{
    int data;
    cout<<"Enter the Elements in the LL"<<endl;
    cin>>data;
    while(data!=(-1))
    {
        addAtFront(head,data);
        cin>>data;
    }
}
bool searchRecursive(node *head , int key)
{
   if(head==NULL)
   {
       return false;
   }
   if(head->data == key)
   {
       return true;
   }
   return searchRecursive(head->next , key);
}
bool searchIterative(node *head , int key)
{
    node * temp = head;
    for(; temp!=NULL ;temp = temp->next)
    {
        if(temp->data == key)
        {
            return true;
        }

    }
    if(temp == NULL)
    {
        return false;
    }

}
int midPoint(node* head)
{
    node* slow = head ;
    node* fast = head->next;


    while(fast!=NULL && (fast->next)!=NULL )
    {
        fast = fast->next->next;
        slow = slow->next;

    }
    return slow->data;

}
void print ( node *head)
{
    for(;head!=NULL; head = head->next)
    {
      cout<<head->data<<"=>";
    }
    cout<<endl;

}
ostream& operator<<(ostream &os , node *head)
{
    print(head);
    return os;
}
istream& operator >>(istream &is , node* &head)
{
    takeInput(head);
    return is;
}
int main()
{
int key;
node *head = NULL;
cin>>head;
cout<<head;
cout<<"Enter the element"<<endl;
cin>>key;
//bool ans = searchRecursive(head , key);
bool ans = searchIterative(head , key);
if(ans)
{
    cout<<"Found it "<<endl;
}
else
{

    cout<<"Not Found"<<endl;
}
int mid = midPoint(head);
cout<<"Mid point is"<<mid;
    return 0;
}
