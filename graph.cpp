#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>edgeWeightPair;
class Graph
{
    int V;
    list <edgeWeightPair> *adj;

    public:
        Graph(int V)
        {
            this->V = V;
            this->adj = new list<edgeWeightPair>[V];
        }

    void addEdge(int u,int v,int w)
    {
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    void printNeighbour(int chk)
    {   
        cout<<chk<<":";
        for (auto i = adj[chk].begin();i != adj[chk].end();i++)
        {
            cout<<"("<<(*i).first<<","<<(*i).second<<")";
        }
    }
    void BFS(int source)
    {
        vector<bool>visited(V,false);
        queue<int>q;
        visited[source] = true;
        q.push(source);
        while (!q.empty())
        {
            int u = q.front();
            cout<<u<<" ";
            q.pop();
            for (auto element:adj[u])
            {
                int v = element.first;
                if (visited[v] != true)
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
    }
    void DFS(int source)
    {
        static vector<bool>visited(V,false);
        queue<int>q;
        visited[source] = true;
        cout<<source<<" ";
        for (auto element:adj[source])
        {
            int v = element.first;
            if (visited[v] != true)
            {
                DFS(v);
            }
        }
    }

};

int main()
{
    int V,E;
    cin>>V>>E;
    Graph g(V);
    for (int i = 0;i < E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    for (int i = 0;i < V;i++)
    {
        g.printNeighbour(i);
        cout<<endl;
    }
    g.BFS(0);
    cout<<endl;
    g.DFS(0);
    return 0;
}


// Bi-directional Weighted Graph
// input:
// 7 10 
// 0 1 7
// 0 2 1
// 0 5 3
// 1 3 11
// 2 3 3
// 2 5 8
// 3 6 1
// 4 5 6
// 4 6 4
// 5 6 2
