#include <iostream>
#include <string>

bool check(long long num)
{
    while(num)
    {
        int ind = num % 10;
        if(ind == 0)    return false;
        num /= 10;
    }
    return true;
}

int main()
{
    long long nums = 0;
    for(int i = 1; i <= 9; ++i)
    {
        nums = 0;
        nums = i * 100;
        for(int j = 1; j  <= 9; ++j)
        {
            nums += j * 10;
            for(int k = 1; k <= 9; ++k)
            {
                nums += k;
                if(i != j && j != k && i != k)
                {
                    long long nums_2 = 2 * nums;
                    long long nums_3 = 3 * nums;
                    if(check(nums) && check(nums_2) && check(nums_3))
                    {
                        if(nums_2 <= 999 && nums_3 <= 999)
                            std::cout << nums << " " << nums_2 << " " << nums_3 << '\n';
                        else
                            break;
                    }
                    else
                        continue;
                }
            }
        }
        
    }
    return 0;
}