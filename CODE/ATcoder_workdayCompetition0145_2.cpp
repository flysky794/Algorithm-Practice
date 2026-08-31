#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, cnt = 0;
    long long total = 0, sum = 0;
    cin >> N ;
    vector<long long> arr(N);
    
    for(int i = 0; i < N; i++) cin >> arr[i], total += arr[i];
    sort(arr.rbegin(), arr.rend());
    long long target = (total + 1) / 2;

    for(auto x : arr)
    {
        sum += x;
        cnt++;
        if(sum >= target)   break;
    }

    cout << cnt << '\n';

    return 0;
}