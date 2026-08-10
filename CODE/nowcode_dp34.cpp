#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0, m = 0;
    int l = 0, r = 0;
    
    cin >> n >> m;
    vector<int> nums(n + 1, 0);
    vector<long long> dp(n + 1, 0);
    for(int i = 1; i <= n; i++)  cin >> nums[i];
    for(int j = 1; j <= n; j++) dp[j] = dp[j - 1] + nums[j];
    while(m--)
    {
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }

    return 0;
}