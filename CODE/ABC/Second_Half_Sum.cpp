#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long N = 0;
    cin >> N;
    vector<long long> nums(N, 0);
    for(long long i = 0; i < N; i++)
        cin >> nums[i];
    
    long long mid = nums.size() / 2, ret = 0;
    for(long long i = mid; i < N; i++)
        ret += nums[i];

    cout << ret << '\n';
    return 0;
}