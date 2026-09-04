#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n = 0, k = 0;
    cin >> n >> k;
    vector<long long> nums(n + 1, 0);
    vector<long long> cnt(n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    long long left = 1, right = 1, ans = LLONG_MAX, val = 0;
    for(right = 1; right <= n; right++)
    {
        val += cnt[nums[right]];
        cnt[nums[right]]++;
        while(val >= k)
        {
            ans = min(right - left + 1, ans);
            cnt[nums[left]]--;
            val -= cnt[nums[left]];
            left++;
        }
    }

    if(ans == LLONG_MAX)    cout << -1 << '\n';
    else    cout << ans << '\n';
    return 0;
}