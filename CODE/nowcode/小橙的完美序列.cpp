#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> nums(n + 1, 0);
    std::unordered_map<int, int> hash;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> nums[i];
        int temp = i ^ nums[i];
        hash[temp]++;
    }
    int max_freq = 0;
    for(const auto& x : hash)
        max_freq = std::max(max_freq, x.second);

    int ans = n - max_freq;
    std::cout << ans << '\n';
    return 0;
}