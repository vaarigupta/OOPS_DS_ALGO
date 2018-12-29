#include<iostream>
using namespace std;
class node
{
    public:
    int data ;
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
        head =n;
        return;
    }
    else
    {
        node *n = new node(d);
        n->next = head;
        head = n;
        return;

    }
}
void takeInput(node * &head )
{
    int d ;
    cout<<"Enter the elements"<<endl;
    cin>>d;
    while(d!= -1)
    {
        addAtFront(head , d);
        cin>>d;
    }
    cout<<endl;
}
node * lastNode(node *head)
{
    while(head->next!=NULL)
    {
        head = head->next;
    }
    return head;
}
node* cycleDetection(node* head)
{
    ///both slow and fast pointing to the head
  node* slow = head;
  node* fast = head;
  /// run atleast one time and change the speed
  ///fast jumps twice the times of slow
  do
  {
      slow = slow->next;
      fast = fast->next->next;
      if(fast == NULL || fast->next==NULL || slow==NULL)
      {
          return NULL;
      }
  }while(fast!=slow);

/// if fast and slow meets at some node then we implement floyd detection cycle algo
/// start slow with head again and move both fast and slow only 1 position
  if(fast == slow)
  {
      slow = head;
      while(fast!= slow)
      {
          fast = fast->next;
          slow = slow->next;
      }
      /// they meet only at the linked node
      if(fast == slow)
      {
        return fast;
      }
  }
}

void print (node * head)
{
    cout<<"Linked List"<<endl;
    while(head!=NULL)
    {
       cout<<head->data<<"=>";
       head = head->next;
    }
    cout<<endl;
}
istream & operator>> (istream & is , node *&head)
{

    takeInput(head);
    return is;
}
ostream & operator<<(ostream &os , node* head)
{
    print(head);
    return os;
}

int main()
{
    node * head = NULL;
    cin>>head;
    cout<<head;
    node * tail = lastNode(head);
    tail->next = head->next->next;
     node * detectedNode = cycleDetection(head);
    if(detectedNode!=NULL)
    {
        cout<<"Cycle Detected "<<endl;
        cout<<detectedNode->data<<" is the connected Node"<<endl;
    }
    else
    {
        cout<<"Cycle Not Detected"<<endl;
    }
    return 0;
}
