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
/// reverse the Linked List using iterative method by taking three pointers - prev , curr , next
/// make the current node points to the previous and update previous and current
///and Shift next pointer to the next of current
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
///Finding mid point by taking two pointers slow and fast
node* midPoint (node * head)
{
    node * slow = head;
    node* fast = head->next;
    while(fast!= NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
/// Find Mid point and then break list into two parts before and after the list and
///compare the two sub lists
bool palindromeByMid(node* head)
{
    node * mid = midPoint(head);
    node* reverseLL = reverse(mid->next);
    mid->next = NULL;
    while(head!=NULL & reverseLL!=NULL)
    {
        if(head->data == reverseLL->data)
        {
            head = head->next;
            reverseLL = reverseLL->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}
///take reverse of the Linked Lists and compare both of them
bool palindrome(node* head)
{
    node* real = head;
    node * temp = reverse(head);
    while(temp!=NULL && real!=NULL)
    {
        if(temp->data == real->data)
        {
            temp = temp->next;
            real = real->next;
        }
        else
        {
            return false;
        }
    }
    return true;
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
    cout<<head<<endl;
    //head = reverse(head);
    //cout<<"Reverse "<<head<<endl;
    if(palindromeByMid(head))
    {
        cout<<"Yippe ,Given List is palindrome"<<endl;
    }
    else
    {
        cout<<"No , It's not palindrome "<<endl;
    }

//node * mid = midPoint(head);
//cout<<"MID POINT : "<<mid->data<<endl;
    return 0;
}
