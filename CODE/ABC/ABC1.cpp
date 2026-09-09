#include <iostream>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    if(x != 1)
        cout << x - 1 << '\n';
    else
        cout << x + 1 << '\n';
    return 0;
}