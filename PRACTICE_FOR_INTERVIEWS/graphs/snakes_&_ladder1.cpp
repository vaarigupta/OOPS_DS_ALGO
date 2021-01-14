// C++ program to find minimum number of dice throws required to
// reach last cell from first cell of a given snake and ladder
// board
#include<iostream>
#include <queue>
using namespace std;
///from GFG
struct queueEntry
{
	int v;
	int dist;
	int cost;
};

queueEntry getMinDiceThrows(int move[], int N)
{

	bool *visited = new bool[N+1];
	for (int i = 0; i <=N; i++)
		visited[i] = false;
	queue<queueEntry> q;
	visited[0] = true;
	queueEntry s = {0, 0,0};
	q.push(s);

	queueEntry qe;
	while (!q.empty())
	{
		qe = q.front();
		int v = qe.v;
		if (v == N)
			break;
		q.pop();
		for (int j=v+1; j<=(v+6) && j<=N; ++j)
		{
			if (!visited[j])
			{
				queueEntry a;
				a.dist = (qe.dist + 1);
				visited[j] = true;
				if (move[j] != -1)
                {
                    a.v = move[j];
					a.cost = (a.v - qe.v)*20;
                }
				else
                {
                    a.v = j;
                }

				q.push(a);
			}
		}
	}

	return qe;
}

int main()
{
    int n,pairs;
    cin>>n>>pairs;
    int board[30];
    for(int i=0;i<=n;i++)
    {
        board[i] = -1;
    }
    for(int i=0;i<pairs;i++)
    {
        int index, value;
        cin>>index>>value;
        board[index] = value;
    }
    queueEntry ans = getMinDiceThrows(board, n);
	cout << "Min Dice throws required is " <<ans.dist ;
	return 0;
}

/*

9 4 2
2 5
4 3
6 8
7 1
*/
