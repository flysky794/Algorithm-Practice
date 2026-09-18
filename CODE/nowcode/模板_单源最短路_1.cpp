#include <iostream>
#include <vector>
#include <queue>


int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u = 0, v = 0;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> dist(n + 1, -1);
    std::queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == n)  break;
        for(int v : adj[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    std::cout << dist[n] << '\n';
    return 0;
}