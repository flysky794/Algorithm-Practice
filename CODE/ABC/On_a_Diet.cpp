#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N = 0, M = 0;
    long long K = 0, sum = 0;
    cin >> N >> M >> K;
    vector<long long> nums(N, 0);
    vector<bool> vis(N, 0);
    for(int i = 0; i < N; i++)
        cin >> nums[i];
    
    int left = 0, right = 0;
    for(right = 0; right < N; right++)
    {
        while(right - left + 1 > M)
        {
            if(vis[left])
                sum -= nums[left];
            left++;
        }
        if(sum + nums[right] <= K)   
        {
            sum += nums[right]; //吃--进窗口
            vis[right] = true;  //标记第i天吃了
            cout << "Yes" << '\n';
        }
        else
        {
            vis[right] = false;
            cout << "No" << '\n';
        }
    }

    return 0;
}