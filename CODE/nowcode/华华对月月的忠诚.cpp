#include <iostream>

int main()
{
    long long A = 0, B = 0, N = 0;
    std::cin >> A >> B >> N;
    while(B > 0)
    {
        long long c = A % B;
        A = B;
        B = c;
    }
    std::cout << A << '\n';
    return 0;
}