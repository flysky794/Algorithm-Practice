#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> dx({0, 2, 2, 1, 1, -1, -1, -2, -2});
    vector<int> dy({0, 1, -1, 2, -2, 2, -2, 1, -1});
    int x_horse, y_horse;
    int n, m;
    cin >> n >> m;
    cin >> x_horse >> y_horse;
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> block(n + 2, vector<int>(m + 2, 0));
    //马的控制点
    for(int i = 0; i < 9; i++)
    {
        int nx = x_horse + dx[i];
        int ny = y_horse + dy[i];
        if(nx >= 0 && nx <= n && ny >= 0 && ny <= m)
            block[nx + 1][ny + 1] = true;
    }
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!block[i][j])
               dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m]  << "\n";
    return 0;
}