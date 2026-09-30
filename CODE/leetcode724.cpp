#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lsum(n, 0);
        vector<int> rsum(n, 0);
        
        for(int i = 1; i < n; i++)
            lsum[i] = lsum[i - 1] + nums[i - 1];
        for(int i = n - 2; i >= 0; i--)
            rsum[i] = rsum[i + 1] + nums[i + 1];

        for(int i = 0; i < n; i++)
            if(lsum[i] == rsum[i])
                return i;

        return -1;
    }
};

int main()
{
  Solution solution;
  int n = 0;
  cout << "Please enter an number :  " << '\n';
  cin >> n;
  vector<int> arr(n, 0);
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  cout << '\n';
  cout << solution.pivotIndex(arr) << '\n';
  return 0;
}
