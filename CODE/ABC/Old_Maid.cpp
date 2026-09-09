#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int N = 0, sum = 0;
    cin >> N;
    vector<int> nums(N, 0);
    unordered_map<int, int> hash;

    for(int i = 0; i < N; i++)
    {
        cin >> nums[i];
        hash[nums[i]]++;
    }

    for(auto& x : hash)
    {
        int count = x.second;
        if(count % 2)
            sum += x.first;
    }
    cout << sum << '\n';
    
    return 0;
}