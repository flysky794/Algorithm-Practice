#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long N = 0, K = 0, ret = 0;
    //输入N名学生，K个班级
    cin >> N >> K;
    vector<long long> classes(N, 0);
    vector<long long> cnt(K + 1, 0);
    for(long long i = 0; i < N; i++)
    {
        long long x = 0;
        cin >> x;
        cnt[x]++;
    }

    long long max_cla = *max_element(cnt.begin()+1,cnt.end());
    for(long long i = 1; i <= K; i++)
    {
        if(cnt[i] + 1 >= max_cla)   ret++;
    }

    cout << ret << '\n';
    return 0;
}