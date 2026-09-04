#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n = 0, ret = -1;
    int hash[26] = { 0 };
    string s;

    cin >> n >> s;
    for(long long i = 0; i < n; i++)
    {
        if(++hash[s[i] - 'a'] == 3)
        {
            ret = i + 1;
            break;
        }
    }

    cout << ret << '\n';
    return 0;
}