#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N = 0;
    cin >> N;
    vector<long long> nums(N, 0);
    for(long long i = 0; i < N; i++)
        cin >> nums[i];

    long long current_group = 0;
    bool ok = true;
    for( auto num : nums)
    {
        long long group = (num - 1) / 10;
        if(group < current_group)
        {
            ok = false;
            break;
        }
        else
        {
            current_group = group;
        }
    }

    if(ok)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}