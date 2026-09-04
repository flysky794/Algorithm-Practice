#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int H = 0, W = 0;
    //输入行和列
    cin >> H >> W;
    vector<vector<long long>> G(H, vector<long long>(W));
    vector<long long> sum_row(H, 0);
    vector<long long> sum_col(W, 0);
    //输入每个单元格亮度，并计算每一行每一列的亮度和
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> G[i][j];
            sum_row[i] += G[i][j];
            sum_col[j] += G[i][j];
        }
    }

    long long ans = -1e18;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            long long score = sum_row[i] + sum_col[j] - G[i][j];
            if(score > ans)
                ans = score;
        }
    }
    
    cout << ans << '\n';
    return 0;
}