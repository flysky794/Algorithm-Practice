#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, M = 0, S = 0, K = 0;
    int ans = 0;
    cin >> N >> M >> S >> K;
    //定义邻接表
    vector<vector<int>> adj(N + 1);
    //初始化邻接表
    
    for(int i = 0; i < M; i++)
    {
        int u = 0, v = 0;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    vector<int>dist(N + 1, -1);
    dist[S] = 0;
    q.push(S);
    
    //bfs
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        if(dist[i] != -1 && dist[i] <= K)
            ans++;
    }

    cout << ans << '\n';
    return 0;
}