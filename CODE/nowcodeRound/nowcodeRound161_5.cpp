#include <iostream>
#include <vector>

struct ege
{
    int v;
    int d;
    int r;
};

long long max_d = LLONG_MAX, max_r = LLONG_MAX;

void dfs(std::vector<std::vector<ege>>& adj, std::vector<bool>& visited, int n, int u, long long cur_d, long long cur_r)
{
    //出口
    if(cur_d > max_d)   return;
    if(cur_d == max_d && cur_r > max_r) return;
    //更新结果
    if(u == n)
    {
        if(cur_d < max_d || (cur_d == max_d && cur_r < max_r))
        {
            max_d = cur_d; 
            max_r = cur_r;
            return;
        }
    }

    for(const auto& e : adj[u])
    {
        if(!visited[e.v])
        {
            visited[e.v] = true;
            dfs(adj, visited, n, e.v, cur_d += e.d, cur_r += e.r);
            visited[e.v] = false;
        }
    }

}

int main()
{
    int m = 0, n = 0;
    std::cin >> n >> m;
    std::vector<bool> visited(m + 1, false);
    std::vector<std::vector<ege>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u = 0, v = 0, d = 0, r = 0;
        std::cin >> u >> v >> d >> r;
        adj[u].push_back({v, d, r});
    }

    visited[1] = true;
    dfs(adj, visited, n, 1, 0, 0);
    
    if(max_d == LLONG_MAX || max_r == LLONG_MAX)
        std::cout << -1 << " " << -1 << '\n';
    else
        std::cout << max_d << " " << max_r << '\n';
    return 0;
}