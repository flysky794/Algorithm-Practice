#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long x = 0;
    cin >> x;
    
    if(x == 0)  {cout << '0' << ' ' << '-1' << ' ' << '-1' << '\n'; return 0;}
    int min_pos = -1, max_pos = -1, count = 0;
    for(int i = 0; i <= 60; i++)
    {
        if((x >> i) & 1)
        {
            count++;
            if(min_pos == -1)   min_pos = i;
            max_pos = i;
        }
    }

    cout << count << ' ' << min_pos << ' ' << max_pos << '\n';
    return 0;
}