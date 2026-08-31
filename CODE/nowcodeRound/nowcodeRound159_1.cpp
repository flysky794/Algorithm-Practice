#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s, a, b;
    cin >> s >> a >> b;
    if(s)
        cout << b << '\n';
    else
        cout << a << '\n';
    return 0;
}