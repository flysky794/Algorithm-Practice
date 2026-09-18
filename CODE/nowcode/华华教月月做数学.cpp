#include <iostream>

typedef long long LL;

LL fastPow(LL a, LL b, LL p)
{
    LL ans = 1 % p;
    a %= p;
    while(b > 0)
    {
        if(b & 1)   ans = (__int128)ans * a % p;
        a = (__int128)a * a % p;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int T = 0;
    std::cin >> T;
    while(T--)
    {
        LL A = 0, B = 0, P = 0;
        std::cin >> A >> B >> P;
        std::cout << fastPow(A, B, P) << '\n';
    }
    return 0;
}