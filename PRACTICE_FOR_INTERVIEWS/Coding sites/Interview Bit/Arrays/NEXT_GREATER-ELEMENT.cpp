#include<iostream>
#include<stack>
using namespace std;
void findNextGreater(int *a, int n)
{
    stack<int> st;
    int next =0, i=1;
    st.push(a[0]);
    for(int i=1;i<n;i++)
    {
         if(s.empty())
        {
            st.push(a[i]);
            continue;
        }
        if(a[i]>st.top())
        {
            next = a[i];
            cout<<a[i-1]<<" - "<<next<<endl;
            st.pop();
        }




    }
    while(!st.empty())
    {
        cout<<st.top()<<" - "<< -1 <<endl;
        st.pop();
    }


}
int main()
{
    int a[] = {4,5,2,25};
    int n = sizeof(a)/sizeof(a[0]);
   findNextGreater(a,n);
    return 0;
}
