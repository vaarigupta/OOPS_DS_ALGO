#include<iostream>

using namespace std;


 void inorder(int s[][5],int l,int h)
 {
 	if(s[l][h]!=0)
 	{
 		cout<<"(";
	 	inorder(s,l,s[l][h]);
	 }
	if(s[l][h]==0)
	{
	 		cout<<"A"<<s[l][h+1];
	}
		 if(s[l][h]!=0)
		 {

		 inorder(s,s[l][h]+1,h);

		 cout<<")";
	 }
 }





int main()
{
    int n=5,i;
    int p[]={5,4,6,2,7};
    int m[5][5]={0};
    int s[5][5]={0};

    int j,q;

    for (int d=1; d<n-1; d++)
    {
        for (int i=1; i<n-d; i++)
        {
            j = i+d;
            m[i][j] = 32767;

            for (int k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
		    s[i][j] =k;
                }
            }
        }
    }

    cout<<m[1][n-1]<<" ";
    inorder(s,1,4);

    return 0;
}
