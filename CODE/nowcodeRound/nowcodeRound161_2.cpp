#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n = 0, max = 0, count = 1;
    std::cin >> n;
    std::vector<int> nums(n + 1, 0);
    std::vector<int> index(n + 1, 0);

    std::cin >> nums[1];
    max = nums[1];
    index[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        std::cin >> nums[i];
        if(nums[i] > max)
        {
            max = nums[i];
            count++;
            index[count] = i;
        }
    }

    if(count < 2)
    {
        std::cout << count << " " << 0 << '\n';
        return 0;
    }

    max = index[2] - index[1];
    for(int i = 3; i <= n; i++)
    {
        int pos = index[i] - index[i - 1];
        if(pos >= max)
            max = pos;
    }

    std::cout << count << " " <<  max << '\n';
    return 0;
}