#include<iostream>
#include<vector>
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
class linkedList
{
    public:
    node* head;
    linkedList()
    {
        head= NULL;
    }
    void addAtFront(int d)
    {
        if(head==NULL)
        {
            head = new node(d);
            return;
        }
        node* n = new node(d);
        n->next = head;
        head = n;

    }
    void addAtEnd(int d)
    {
        if(head==NULL)
        {
            head = new node(d);
            return;
        }
        node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        node *n = new node(d);
        temp->next = n;

    }
    int length_LL(node* head)
    {
        int cnt =0;
        while(head!=NULL)
        {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    void addAfterNode(int d, int places)
    {
        if(places==0)
        {
            addAtFront(d);
            return;
        }
        int len = length_LL(head);
        if(places>=len)
        {
            addAtEnd(d);
            return;
        }
        node* temp = head;
        for(int i=1;temp->next!=NULL && i<places;i++)
        {
            temp = temp->next;
        }
        node* n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
    node* buildList(vector<int> arr,int n)
    {
        for(int i=0;i<n;i++)
        {
           // addAtFront(arr[i]);
             addAtEnd(arr[i]);
        }
        return head;
    }
    void deletion(int place)
    {
        if(place==1)
        {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        node* prev = NULL;
        node* temp = head;
        for(int i=1;temp->next!=NULL && i<place;i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp->next==NULL)
        {
            prev->next = NULL;
            delete temp;
            return;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    void printList()
    {
        node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
    void addAtPosition()
    {
        int d,place;
        cin>>d>>place;
        addAfterNode(d,place);

    }

};
int main()
{
    int n;
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    linkedList l;
    l.buildList(arr,n);
    l.addAtPosition();
    l.printList();
    l.deletion(2);
    l.printList();
    return 0;
}
/*

add at beginning
6
1 2 3 4 5 6
6->5->4->3->2->1->

add at end
6
1 2 3 4 5 6
1->2->3->4->5->6

6
1 2 3 4 5 6
7 2
1->2->7->3->4->5->6->

6
1 2 3 4 5 6
7 7
1->2->3->4->5->6->7->

6
1 2 3 4 5 6
7 0
7->1->2->3->4->5->6->
*/
