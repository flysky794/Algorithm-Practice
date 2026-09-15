#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

//坐标
int dx4[4] = {0, 0, -1, 1};
int dy4[4] = {1, -1, 0, 0};

int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

//广搜
std::pair<int, int> bfs(std::vector<std::string>& grid, std::vector<std::vector<bool>>& visited4, int dir, int m, int n)
{
    std::queue<std::pair<int, int>> q;
    int count = 0;
    int max_area = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == '1' && !visited4[i][j])
            {
                q.push({i, j});
                visited4[i][j] = true;
                count++;
                int area = 0;

                while(!q.empty())
                {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    area++;
                    for(int k = 0; k < dir; k++)
                    {
                        int x = i + dx4[k], y = j + dy4[k];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !visited4[x][y])
                        {
                            q.push({x, y});
                            visited4[x][y] = true;
                        }
                    }
                    max_area = std::max(max_area, area);
                }
            }
        }
    }

    return {count, max_area};
}

std::pair<int, int> bfs(std::vector<std::string>& grid, std::vector<std::vector<bool>>& visited4, int m, int n, int dirs)
{
    std::queue<std::pair<int, int>> q;
    int count = 0;
    int max_area = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == '1' && !visited4[i][j])
            {
                q.push({i, j});
                visited4[i][j] = true;
                count++;
                int area = 0;

                while(!q.empty())
                {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    area++;
                    for(int k = 0; k < dirs; k++)
                    {
                        int x = i + dx8[k], y = j + dy8[k];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !visited4[x][y])
                        {
                            q.push({x, y});
                            visited4[x][y] = true;
                        }
                    }
                    max_area = std::max(max_area, area);
                }
            }
        }
    }

    return {count, max_area};
}

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m = 0, n = 0;
    std::cin >> m >> n;
    std::vector<std::string> grid(m);
    for(int i = 0; i < m; i++)
        std::cin >> grid[i];
    
    std::vector<std::vector<bool>> visited4(m, std::vector<bool>(n, false));
    auto [c4, s4] = bfs(grid, visited4, 4, m, n);
    std::vector<std::vector<bool>> visited8(m, std::vector<bool>(n, false));
    auto [c8, s8] = bfs(grid, visited8, m, n, 8);

    std::cout << c4 - c8  << " " << s4 << " " << s8 << '\n';
    return 0;
}