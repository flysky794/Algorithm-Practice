#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N = 0, ret = INT_MAX;
    cin >> N;
    vector<int> nums(N + 1, 0);
    vector<int> dp(N + 1, 0);
    for(int i = 1; i <= N; i++)
        cin >> nums[i];
        
    for(int i = 1; i <= N; i++)
        dp[i] = dp[i - 1] + nums[i];
    
    for(int i = 1; i <= N; i++)
    {
        int sub = dp[N] - dp[i];
        int tmp = abs(dp[i] - sub);
        ret = min(ret, tmp);
    }

    cout << ret << '\n';
    return 0;
}