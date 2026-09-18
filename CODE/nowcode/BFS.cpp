#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    if(s.size() < 3)    {std::cout << "-1" << '\n'; return 0;}
    int left = 0, right = 2;
    while(right < s.size())
    {
        bool match1 = (s[left] == 'B' || s[left] == 'b');
        bool match2 = (s[left + 1] == 'O' || s[left + 1] == 'o');
        bool match3 = (s[left + 2] == 'b' || s[left + 2] == 'B');
        if(match1 && match2 && match3)
        {
            std::cout << left << '\n';
            return 0;
        }
        left++, right++;
    }
    
    std::cout << "-1" << '\n';
    return 0;
}