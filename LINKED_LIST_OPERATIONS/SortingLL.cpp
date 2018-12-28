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
    if(head == NULL)
    {
        node * n = new node(d);
        head = n;
        return;
    }
    else
    {

        node*n = new node(d);
        n->next = head;
        head = n;
    }


}
void takeInput(node *&head)
{
    int d ;
    cout<<"Enter the elements"<<endl;
    cin>>d;
    while(d!=(-1))
    {
        addAtFront(head,d);
        cin>>d;
    }
}
void print (node *head)
{
    cout<<"Linked List:"<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<"=>";
        head = head->next;
    }
    cout<<endl;
}
node* midPoint(node* head)
{
    node* slow = head ;
    node* fast = head->next;


    while(fast!=NULL && (fast->next)!=NULL )
    {
        fast = fast->next->next;
        slow = slow->next;

    }
    return slow;

}
node* &mergeLL(node *&head1 , node *&head2)
{
    node* temp1 = head1;
    node* temp2 = head2;
    node* mergeTemp = NULL;
    while(temp1!= NULL && temp2!=NULL)
    {
        if(temp1->data <= temp2->data)
        {

            addAtFront(mergeTemp , temp1->data);
            temp1= temp1->next;

        }
        else
        {
            addAtFront(mergeTemp , temp2->data);
            temp2 = temp2->next;

        }


    }
    if(temp1!=NULL)
    {
        while(temp1!= NULL)
    {
        addAtFront(mergeTemp,temp1->data);
        temp1 = temp1->next;
    }

    }

      if(temp2!= NULL)
      {
             while(temp2!= NULL)
    {
        addAtFront(mergeTemp,temp2->data);
        temp2 = temp2->next;
    }
      }


    return mergeTemp;
}
node* merge(node * head1 , node* head2)
{
    node* a = head1;
    node* b = head2;
    ///Base Case
    if(a== NULL)
    {
        return b;
    }
    if(b == NULL)
    {
        return a;
    }
    ///Rec Case
    node* c = NULL;

    if(a->data <= b->data)
    {
       c = a;
       c->next = merge(a->next , b);
    }
    else
    {
    c = b;
    c->next = merge(a , b->next);

    }
    return c;
}

node *mergeSort(node* head)
{

    ///Base Case
    if(head == NULL || (head->next)==NULL)
    {
        return head;
    }
    ///Divide ,Conquer and Combine
    node* l1 = head;
    node* midNode =  midPoint(head);
    node* l2 = midNode->next;
    midNode->next = NULL;
    l1 = mergeSort(l1);
    l2 = mergeSort(l2);
    return merge(l1,l2);

}
istream& operator>>(istream &is , node *&head)
{
    takeInput(head);
    return is;
}
ostream& operator<<(ostream &os , node * head)
{
    print(head);
    return os;
}
int main()
{
    node * head1 = NULL;
    node * head2 = NULL;
    cin>>head1;
    cout<<head1;
//    cin>>head2;
//    cout<<head2;
//    node *MergeList = merge(head1 , head2);
   node* MergeList = mergeSort(head1);
    cout<<"Sorted "<<MergeList;



    return 0;
}
