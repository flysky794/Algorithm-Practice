#include <iostream>
#include <vector>

long long gcd(long long a, long long b)
{
    while(b)
    {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int T = 0;
     std::cin >> T;

    while(T--)
    {
        long long x = 0, y = 0, a = 0, b = 0, c = 0, d = 0;
        std::cin >> x >> y;

        std::cin >> a >> b;
        std::cin >> c >> d;
        long long ans_y = gcd(a, b);
        long long ans_x = gcd(c, d);
        if((y % ans_y == 0) && (x % ans_x))
        {
            std::cout << "YES" << '\n';
        }
        else
            std::cout << "NO" << '\n';
    }

    return 0;
}