#include <iostream>
#include <vector>
using namespace std;

int Solution(long long& n, long long& k)
{
    long long ret = 1, sum = 0;
    vector<long long> nums(n + 1, 0);
    for(long long i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    
    //滑动窗口
    long long left = 1, right = 2;
    for(right = 2; right <= n; right++)
    {
        //入窗口
        sum += abs(nums[right] - nums[right - 1]);
        //判断
        while(sum > k)
        {
            //出窗口
            left++;
            sum -= abs(nums[left] - nums[left - 1]);
        }
        //更新结果
        ret = max(ret, right - left + 1);
    }

    return ret;
}

int main()
{
    long long n = 0, k = 0, ans = 0;
    cin >> n >> k;
    ans = Solution(n, k);
    cout << ans << '\n';
    return 0;
}