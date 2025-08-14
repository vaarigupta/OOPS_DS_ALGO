#include<iostream>
using namespace std;
void escape_from_park(char park[102][102], int n , int m , int k , int s)
{
	bool success = true;
	for(int row=0;row<n;row++)
	{
		for(int col=0;col < m; col++)
		{
			if(s <k)
			{
				success = false;
				break;
			}

			if(park[row][col]== '.')
			{
				s -= 2;

			}
			else if(park[row][col]== '*')
			{
				s += 5;
			}

			else if(park[row][col]== '#')
			{
				break;
			}
			if(col!=m-1)
			{
				s -= 1;
			}
		}

	}
	if(success)
	{
		cout<<"Yes"<<endl;
		cout<<s;
	}
	else
	{
		cout<<"No";
	}

}
int main() {
	int n, m , k, s;
	cin>>n>>m>>k>>s;
	char park[102][102];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>park[i][j];
		}
	}
	escape_from_park(park, n,m,k,s);
	return 0;
}
