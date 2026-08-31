#include <iostream>
#include <vector>
using namespace std;

int find(const vector<long long>& arr, long long p)
{
    long long left = 0, right = arr.size() - 1;
    while(left < right)
    {
        long long mid = left + (right - left) / 2;
        if(arr[mid] >= p)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long m, q, b;
    cin >> m >> q >> b;
    vector<long long> arr(m, 0);
    for(int i = 0; i < m; i++)
    {
        long long x = 0;
        cin >> x;
        if(i == 0)  arr[i] = x;
        else    arr[i] = arr[i - 1] + x;
    }

    while(q--)
    {
        long long p = 0;
        cin >> p;
        long long index = find(arr, p);
        long long seg_id = index + 1;
        long long inside = 0;
        if(index == 0) inside = p;
        else    inside = p - arr[index - 1];
        bool st = false;
        if(seg_id % 2)  st = b;
        else    st = 1 - b; 
        cout << st << " " << seg_id << " " << inside << '\n';
    }

    return 0;
}