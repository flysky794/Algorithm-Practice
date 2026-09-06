#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int Solution(long long& n)
{
    long long ret = 0;
    vector<long long> nums(n + 1, 0);
    unordered_map<long long, vector<long long>> hash;
    for(long long i = 1; i <= n; i++)
    {
        cin >> nums[i];
        hash[nums[i]].push_back(i);
    }

    for(auto& v : hash)
    {
        auto& tmp = v.second;
        if(tmp[0] < tmp[tmp.size() - 1])
            if((tmp[tmp.size() - 1] - tmp[0]) % 2 == 0)
                ret++;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n = 0;
    cin >> n;
    long long ans = Solution(n);
    cout << ans << '\n';
    return 0;
}