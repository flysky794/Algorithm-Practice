#include <iostream>
#include <vector>
using namespace std;


void dfs(int rem, int n, long long k, int quan, vector<long long>& path)
{
    //出口
    if(path.size() == n)
    {
        if(rem == 0)
        {
            for(int i = 0; i < n; i++)
                cout << path[i] << " ";
            cout << '\n';
        }
        return;
    }
    
    long long max_i = rem / quan;
    for(long long i = 0; i <= max_i; i++)
    {
        path.push_back(i);
        dfs(rem - i * quan, n, k, quan + 1, path);
        //回溯
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    int N = 0;
    long long K = 0;
    vector<long long> path;
    cin >> N >> K;
    //深搜
    dfs(K, N, K, 1, path);
    return 0;
}

