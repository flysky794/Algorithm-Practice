#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> multiply(std::vector<int>& fact, int b)
{
    std::vector<int> c;
    int carry = 0;
    for(int i = 0; i < fact.size() || carry; ++i)
    {
        if(i < fact.size())
            carry += fact[i] * b;
        c.push_back(carry % 10);
        carry /= 10;
    }
    return c;
}

std::vector<int> add(std::vector<int>& sum, std::vector<int> face)
{
    std::vector<int> c;
    int carry = 0;
    int n = std::max(sum.size(), face.size());
    for(int i = 0; i < n || carry; ++i)
    {
        if(i < sum.size())  carry += sum[i];
        if(i < face.size()) carry += face[i];
        c.push_back(carry % 10);
        carry /= 10;
    }
    return c;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<int> fact = { 1 };
    std::vector<int> sum;
    for(int i = 1; i <= n; ++i)
    {
        fact = multiply(fact, i);
        sum = add(sum, fact);
    }

    for(long long i = sum.size() - 1; i >= 0; --i)
    {
        std::cout << sum[i];
    }
    std::cout << '\n';
    return 0;
}