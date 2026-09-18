#include <iostream>
#include <vector>
#include <queue>
#include <climits>

typedef long long ll;
const ll INF = 1e18;
struct ege
{
    int to;
    ll w;
};

int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<ege>> adj(n + 1);
    for(int i = 1; i <= m; ++i)
    {
        int u = 0, v = 0;
        ll w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    std::vector<ll> dist(n + 1, INF);
    std::vector<bool> visited(n + 1, false);
    dist[1] = 0;
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(visited[u])  continue;
        visited[u] = true;
        for(const ege& v : adj[u])
        {
            ll nd = dist[u] + v.w;
            if(nd < dist[v.to])
            {
                dist[v.to] = nd;
                pq.push({nd, v.to});
            }
        }
    }

    if(dist[n] == INF)
        std::cout << "-1" << '\n';
    else
        std::cout << dist[n] << '\n';
    return 0;
}