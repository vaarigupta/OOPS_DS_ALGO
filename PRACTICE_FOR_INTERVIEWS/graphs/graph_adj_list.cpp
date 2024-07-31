#include<iostream>
#include<list>
using namespace std;
class graph
{
    int v;
    list<int> *l;
public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addedge(int u, int v, bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }
    void printgraph()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<" - ";
            for(vertex: l[i])
            {
                cout<<vertex<<" =>";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(2,1);
    g.addedge(3,1);
    g.addedge(4,1);
    g.addedge(3,2);
    g.addedge(4,3);
    g.printgraph();
    return 0;
}

/*

0 1
0 4
2 1
3 1
4 1
3 2
4 3
0 - 1 =>4 =>
1 - 0 =>2 =>3 =>4 =>
2 - 1 =>3 =>
3 - 1 =>2 =>4 =>
4 - 0 =>1 =>3 =>

*/
