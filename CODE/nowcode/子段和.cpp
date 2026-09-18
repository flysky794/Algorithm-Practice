#include <iostream>
#include <vector>
#include <set>

int main()
{
    long long n = 0;
    std::cin >> n;
    std::vector<long long> a(n);
    bool has_zero = false;
    std::set<long long> hash;
    for(long long i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        if(a[i] == 0)
        {
            has_zero = true;
            std::cout << "NO" << '\n';
            return 0;
        }
        hash.insert(abs(a[i]));
    }

    bool fu = false, zh = false;
    if(hash.size() == 1)
    {
        for(long long i = 0; i < n; ++i)
        {
            if(a[i] > 0)    zh = true;
            if(a[i] < 0)    fu = true;
        }
    }

    if(zh && fu)
        std::cout << "NO" << '\n';
    else
        std::cout << "YES" << '\n';
    return 0;
}