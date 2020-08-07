#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v)
{
     for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
bool areAllNines(vector<int> A)
{
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==9)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
vector<int>& plusOne1(vector<int> &A) {
     int i = A.size() -1 ;
     if(A.size()==1)
     {
         A[i] = A[i]+1;
         return A;
     }
    vector<int> output(A.size()+1);
   if(areAllNines(A))
    {
        output.push_back(1);
        fill(output.begin()+1,output.end(),0);
        return output;
    }
    do
    {
        output[i] = (A[i] + 1)%10;
        if(output[i]==0)
        {
            i--;
        }

    }while(i>=0);
    return output;


}


vector<int> plusOne1(vector<int> &A) {
    int n = A.size() - 1;
    int carry =0;
    A[n] +=1;
    carry = A[n]/10;
    A[n] = A[n] % 10;
    int j=0;
    for(int j=n-1;j>=0;j--)
    {
       if(carry==1)
       {
           A[j] +=1;
           carry = A[j]/10;
           A[j] = A[j]% 10;

       }
    }
    if(carry==1)
    {
        A.insert(A.begin(),1);
    }
    return A;

}



vector<int> plusOne(vector<int> &A) {
    vector<int> rev;
    int n = A.size() - 1;
    rev.push_back((A[n]+1)%10);
    int carry = (A[n]+1)/10;
    for(int i=n-1;i>=0;i--)
    {
        rev.push_back((A[i]+carry)%10);
        carry = (A[i]+carry)/10;
    }
    if(carry)
    {
        rev.push_back(carry);
    }
    print(rev);
    int beg = 0;
    int last = rev.size()-1;
    while(beg<=last)
    {
        swap(rev[beg],rev[last]);
        beg++;
        last--;
    }
   // print(rev);
    //reverse(rev.begin(),rev.end());
    while(rev[0]==0)
    {
       rev.erase(rev.begin());
    }
    return rev;


}

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
    }
    vector<int> newVector = plusOne(v);
    print(newVector);
    return 0;
}

// 0 6 0 6 4 8 8 1
