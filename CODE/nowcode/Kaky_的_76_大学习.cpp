#include <iostream>
#include <string>
int main()
{
    int n = 0;
    std::string ret = "152";
    std::cin >> n;
    if(n <= 2)
        std::cout << "No" << '\n';
    else
    {
        std::cout << "Yes" << '\n';
        ret += std::string(n - 3, '0');
        std::cout << ret << '\n';
    }
    return 0;
}