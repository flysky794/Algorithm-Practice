#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n = 0, q = 0;
    string s;
    cin >> n >> q;
    vector<long long> energy(n + 1, 0);
    for(int i = 1; i <= n; i++)
        cin >> energy[i];
    cin >> s;
    while(q--)
    {
        bool flag = 1;
        long long sum = 0;
        long long pos = 0;
        char opera;
        cin >> pos >> opera;
        s[pos - 1] = opera;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '+') sum += energy[i + 1];
            if(s[i] == '-') sum -= energy[i + 1];
            if(sum < 0) break;
        }
        if(flag)    cout << "YES" << '\n';
        else    cout << "NO" << '\n';
    }
    return 0;
}