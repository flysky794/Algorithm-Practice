#include <iostream>
#include <queue>
using namespace std;
int n = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> map;
vector<vector<bool>> visited;

int main()
{
    cin >> n;
    map.resize(n);
    visited.resize(n);
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(map[i][0] == 0 && !visited[i][0])
        {
            q.push({i, 0});
            visited[i][0] = true;
        }
        if(map[i][n - 1] == 0 && !visited[i][n - 1])
        {
            q.push({i, n-1});
            visited[i][n-1] = true;
        }
    }

    for(int j = 0; j < n; j++)
    {
        if(map[0][j] == 0 && !visited[0][j])
        {
            q.push({0, j});
            visited[0][j] = true;
        }
        if(map[n-1][j] == 0 && !visited[n-1][j])
        {
            q.push({n-1, j});
            visited[n-1][j] = true;
        }
    }

    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if(!visited[nx][ny] && map[nx][ny] == '0')
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 0 && !visited[i][j])
            {
                map[i][j] = 2;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}