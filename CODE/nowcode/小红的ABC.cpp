//最短回文子串，长度超过1
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

int main()
{
    std::string s;
    int ans = INT_MAX;
    std::cin >> s;

    //长度为2的回文串
    for(int i = 0; i + 1 < s.size(); ++i)
    {
        if(s[i] == s[i + 1])
        {
            std::cout << "2" << '\n';
            return 0;
        }
    }

    //长度为3的回文串
    for(int i = 0; i + 2 < s.size(); ++i)
    {
        if(s[i] == s[i + 2])
        {
            std::cout << "3" << '\n';
            return 0;
        }
    }

/*    for(int center = 0; center < s.size(); ++center)
    {

        //长度为奇数的回文串
        int l = center - 1, r = center + 1;
        while(l >= 0 && r < s.size() && s[l] == s[r])
        {
            ans = std::min(ans, r - l + 1);
            l--, r++;
        }

        //长度为偶数的回文串
        int left = center - 1, right = center;
        while(left >= 0 && right <= 0 && s[right] == s[left])
        {
            ans = std::min(ans, right - left + 1);
            l--, r++;
        }
    }
*/
    if(ans == INT_MAX)
        std::cout << "-1" << '\n';
    else
        std::cout << ans << '\n';
    return 0;
}