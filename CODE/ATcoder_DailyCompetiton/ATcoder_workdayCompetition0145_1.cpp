#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, M = 0;
    int P_M = 0;
    int P = 0, reward = 0;
    long long sum = 0, ans = 0;
    cin >> N >> M;
    cin >> P;

    for(int i = 1; i <= N; i++)
    {
        cin >> P_M;
        cin >> reward;
        if(P_M <= M)    sum += reward;
    }
    
    ans = sum * (100 - P) / 100;
    cout << ans << '\n';

    return 0;
}