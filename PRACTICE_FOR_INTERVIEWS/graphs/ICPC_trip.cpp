#include<bits/stdc++.h>
using namespace std;
class city
{
public:
    int name;
    int flight;
    int train;

    city(int n, int f, int t)
    {
        name = n;
        flight = f;
        train = t;
    }
    bool operator==(const city& c) const
    {
        return name==c.name && flight == c.flight && train == c.train;
    }
};
class myHashFunction
{
public:
    size_t operator()(const city& c) const
    {
        return (c.name + c.flight + c.train);
    }
};
class graph
{
    public:
    unordered_map<city,list<city>,myHashFunction > m;
    graph()
    {

    }
    void addEdge(city c1, city c2, bool bidir =true)
    {

        m[c1].push_back(c2);
        if(bidir)
        {
            m[c2].push_back(c1);
        }
    }
    void printgraph()
    {

        for(auto node: m)
        {
            cout<<node.first.name<<" => ";
            for(auto l:node.second)
            {
                cout<<"( "<<l.name<<" ,"<<l.flight<<" ,"<<l.train<<" ), ";
            }
            cout<<endl;
        }
    }

};


int main()
{
    graph g;
    city a(1,2,3);
    city b(2,3,4);
    city c(3,4,5);
    city d(5,4,5);
    g.addEdge(a,b);
    g.addEdge(b,c);
    g.addEdge(a,c);
    g.addEdge(a,d);
    g.addEdge(c,d);
    g.printgraph();


    return 0;
}
