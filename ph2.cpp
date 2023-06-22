#include<bits/stdc++.h>
using namespace std;

vector<int>v[100];
bool visit[100];

void bfs(int source)
{
    queue<int>q;
    q.push(source);
    while (!q.empty())
    {
        int parant = q.front();
        q.pop();
        if (visit[parant] == true) continue;
        cout<<parant<<" ";
        for (int i =0;i < v[parant].size();i++)
        {   
            int childe = v[parant][i];
            if (visit[childe] == false)
            {
                q.push(childe);
            }
        }
        visit[parant] = true;
    }
    
}

int main()
{
    int n,e;
    cin>>n>>e;
    for (int i = 0;i < e;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        
    }
    memset(visit,false,sizeof(v));
    bfs(1);
    return 0;
}