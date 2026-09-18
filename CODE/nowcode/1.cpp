#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main()
{
    int q = 0;
    int ans = 0;
    std::cin >> q;
    std::unordered_map<std::string, int> hash(q);
    while(q--)
    {
        std::string s;
        char opera = '0';
        std::cin >> opera >> s;
        //前缀
        if(opera == '+')
        {
            for(int i = 1; i <= s.size(); ++i)
            {
                std::string prefix = s.substr(0, i);
                if(hash[prefix]++)  ans++;
            }
        }
        
        else
        {
            for(int i = 0; i < s.size(); ++i)
            {
                std::string prefix = s.substr(0, i);
                if(--hash[prefix])  ans--;
            }
        }
    }

    std::cout << ans << '\n';
    return 0;
}