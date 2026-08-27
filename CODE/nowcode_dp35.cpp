#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    
    while(q--)
    {
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        long long ret = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout << ret << '\n';
    }
    return 0;
}