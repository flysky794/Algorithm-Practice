#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

const int INF = INT_MAX / 2;

int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1, INF));
    for(int i = 1; i <= n; i++)  g[i][i] = 0;
    for(int i = 1; i <= m; ++i)
    {
        int u = 0, v = 0, w = 0;
        std::cin >> u >> v >> w;
        //处理重边
        if(g[u][v] > w)
        {
            g[u][v] = w;
            g[v][u] = w;
        }
    }

    std::vector<int> visited(n + 1, false);
    std::vector<int> dist(n + 1, INF);
    dist[1] = 0;
    //visited[1] = true;
    for(int i = 1; i <= n; i++)
    {
        int u = -1, best = INF;
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j] && (u == -1 || dist[j] < best))
            {
                u = j;
                best = dist[u];
            }
        }

        if(dist[u] == INF)  break;
        visited[u] = true;
        for(int v = 1; v <= n; ++v)
        {
            if(!visited[v] && g[u][v] != INF)
            {
                dist[v] = std::min(dist[v], dist[u] + g[u][v]);
            }
        }
    }

    if(dist[n] == INF)
        std::cout << "-1" << '\n';
    else
        std::cout << dist[n] << '\n';
    return 0;
}