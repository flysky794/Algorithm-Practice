#include <iostream>
#include <vector>
#include <algorithm>
bool cmp(int a, int b)
{
    int pop_a = __builtin_popcount(a);
    int pop_b = __builtin_popcount(b);
    if (pop_a != pop_b)
        return pop_a < pop_b;

    int ctz_a = (a == 0) ? 31 : __builtin_ctz(a);
    int ctz_b = (b == 0) ? 31 : __builtin_ctz(b);
    if (ctz_a != ctz_b) 
        return ctz_a < ctz_b;

    return a < b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n = 0, k = 0;
    std::vector<int> nums; 
    std::cin >> n >> k; 
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        std::cin >> x;
        nums.push_back(x);
    }
    
    sort(nums.begin(), nums.end(), cmp);
    
    std::cout << nums[k - 1] << '\n';
    return 0;
}