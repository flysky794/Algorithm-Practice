#include <iostream>
#include <vector>
using namespace std;

void takeAttendance(vector<int>& records)
{
  int left = 0, right = records.size() - 1;

  while(left < right)
  {
    int mid = left + (right - left + 1) / 2;
    if(records[mid] > mid)  right = mid - 1;
    else  left = mid;
  }

  if(records[right] > right)
    cout << "The missing number is " << right << endl;
  else  cout << "The missing number is " << records[right] + 1 << endl;
}
int main()
{
  int n = 0;
  cout << "please enter the length of the data " << endl;
  cin >> n;
  vector<int> nums(n);
  
  for(int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  takeAttendance(nums);
  return 0;
}
