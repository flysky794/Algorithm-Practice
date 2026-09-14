#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> multitBfs(vector<string>& grid, vector<bool>& row_bomb, vector<bool>& col_bomb)
{
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dis(m, vector<int>(n, -1));
    //距离为0入队列
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == '.' && !row_bomb[i] && !col_bomb[j])
            {
                dis[i][j] = 0;
                q.push({i, j});
            }
    
    while(!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n)
            {
                if(dis[x][y] == -1 && grid[x][y] != '#')
                {
                    dis[x][y] = dis[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    return dis;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long H = 0, W = 0, K = 0;
    cin >> H >> W >> K;
    vector<string> grid(H);
    //初始化网格
    for(long long i = 0; i < H; i++)
        cin >> grid[i];

    //标记炸弹
    vector<bool> row_bomb(H, false);
    vector<bool> col_bomb(W, false);
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            if(grid[i][j] == '#')
            {
                row_bomb[i] = true;
                col_bomb[j] = true;
            }
        }
    }
    //多源bfs
    vector<vector<int>> dis = multitBfs(grid, row_bomb, col_bomb);

    //统计结果
    long long ans = 0;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            if(grid[i][j] == '.'  && dis[i][j] != -1 && dis[i][j] <= K)
                ans++;

    cout << ans << '\n';
    return 0;
}