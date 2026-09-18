#include <iostream>

int main()
{
    int T = 0;
    std::cin >> T;
    while(T--)
    {
        long long n = 0, m = 0;
        std::cin >> n >> m;
        if(n <= 2 * m)
        {
            std::cout << "-1" << '\n';
        }
        else
        {
                std::cout << m << " " << n - m << '\n';
        }
    }
    return 0;
}