#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int T = 0;
    std::cin >> T;

    while(T-- > 0)
    {
        int n = 0, k = 0, ans = 0;
        std::cin >> n >> k;
        std::vector<int> nums(k + 1, -1);
        for(int i = 1; i <= k; i++)
            std::cin >> nums[i];
        ans = std::max(nums[1] - 1, n - nums[k]);
        for(int i = 1; i + 1 <= k; ++i)
        {
            ans = std::max(ans, (nums[i+1] - nums[i]) / 2);
        }
        std::cout << ans << '\n';
    }

    return 0;
}