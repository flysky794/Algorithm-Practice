#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;
    for(long long i = 0; i < S.size(); i++)
        if(S[i] != 'A')
            S[i] = '.';

    cout << S << '\n';
    return 0;
}