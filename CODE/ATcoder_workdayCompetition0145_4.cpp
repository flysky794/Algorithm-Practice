#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    
    long long ans = abs(A - C) + abs(B - D);
    if ((A < B) != (C < D)) {
        ans--;
    }
    cout << ans << '\n';
    return 0;
}
