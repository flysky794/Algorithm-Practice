#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findMin(vector<int>& nums)
{
  int ret = INT_MAX;
  int left = 0, right = nums.size() - 1;
  int x = nums[right];

  while(left < right)
  {
    int mid = left + (right - left) / 2;
    if(nums[mid] > x) left = mid + 1;
    else  right = mid;
  }

  ret = nums[right];
  cout << "The result :" << ret << endl;
}

int main()
{
  vector<int> num({3,4,5,1,2});
  findMin(num);
  return 0;
}
