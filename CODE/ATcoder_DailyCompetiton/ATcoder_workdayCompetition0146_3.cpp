#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N = 0, M = 0, K = 0;
    //输入花坛数量、浇水次数、每次湿度增加值
    cin >> N >> M >> K;
    vector<long long> humidity(N + 2, 0);
    vector<long long> diff(N + 2, 0);
    //输入每个花坛的初始状态
    for(int i = 1; i <= N; i++)
        cin >> humidity[i];

    for(long long i = 1; i <= M; i++)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }

    long long ans = 0, count = 0;
    for(long long i = 1; i <= N; i++)
    {
        ans += diff[i];
        humidity[i] += ans;
        if(humidity[i] >= K)
            count++;
    }

    cout << count << '\n';
    return 0;
}