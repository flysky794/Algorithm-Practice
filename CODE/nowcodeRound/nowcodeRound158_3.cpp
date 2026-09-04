#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    long long n = 0;
    cin >> n;
    unordered_map<long long, vector<int>>hash;
    for(int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        hash[x].push_back(i);
    }

    long long sum = 0;
    for(auto& v : hash)
    {
        auto& tmp = v.second;
        if(tmp.size() % 2)
            sum += tmp[tmp.size() / 2];
    }
    cout << sum << '\n';
    return 0;
}