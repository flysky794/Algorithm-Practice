#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main()
{
    int T = 0;
    std::cin >> T;
    while(T--)
    {
        int n = 0, k = 0;
        bool hit = false;
        std::string s;
        std::cin >> n >> k;
        std::cin >> s;
        std::vector<std::pair<int, int>>  barrier; 
        for(int i = 0; i < k; i++)
            std::cin >> barrier[i].first >> barrier[i].second;
        
        int cx = 0, cy = 0, R = 0;
        for(char ch : s)
        {
            if(hit) break;
            switch(ch)
            {
                case 'U' : cx -= 1; break;
                case 'D' : cx += 1; break;
                case 'L' : cy += 1; break;
                case 'R' : cy -= 1; break;
                case 'N' : R += 1; break;
            }
            for(const auto& p : barrier)
            {
                if(abs(cx - p.first) + abs(cy - p.second) <= R)
                    hit = true;
            }
        }
        if(hit)
            std::cout << "yes" << '\n';
        else
            std::cout << "No" << '\n';
    }
    return 0;
}