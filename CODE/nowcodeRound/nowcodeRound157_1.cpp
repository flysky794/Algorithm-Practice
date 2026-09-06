#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n = 0, d = 0, count = 0, temp = 0;
    cin >> n >> d;
    string opera;
    cin >> opera;
    temp = d;
    for(auto& ch : opera)
    {
        if(ch == '+')
        {
            if(d == 9)
                d = 0;
            else
                d++;
            if(d == temp)
                count++;
        }
        else
        {
            if(d == 0)
                d = 9;
            else
                d--;
            if(d == temp)
                count++;
        }
    }

    cout << d << " " << count << '\n';
    return 0;
}