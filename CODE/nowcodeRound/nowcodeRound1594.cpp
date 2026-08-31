#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n = 0, b = 0;
    cin >> n >> b;
    vector<bool> exist(1 << b, false);
    vector<long long> masks(n, 0);
    for(int i = 0; i < n; i++)
    {
        string s;
        int mask = 0;
        cin >> s;
        for(int j = 0; j < b; j++)
        {
            if(s[j] == '1')
                mask |= (1 << j);
        }
        masks[i] = mask;
        exist[mask] = true;
    }

    vector<long long> anst(b, 0);
    for(auto num : masks)
    {
        for(int k = 0; k < b; k++)
        {
            int y = num ^ (1 << k);
            if(exist[y])    anst[k]++;
        }
    }

    long long total = 0;
    for(int k = 0; k < b; k++)
    {
        anst[k] /= 2;
        total += anst[k];
    }
    cout << total << '\n';
    for(int f = 0; f < b; f++)
    {
        if(f > 0)   cout << " ";
        cout << anst[f];
    }
    cout << '\n';
    return 0;
}