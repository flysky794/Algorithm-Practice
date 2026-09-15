#include <iostream>
#include <vector>
int main()
{
    std::vector<int> lamp(3, 0);
    int sum = 0;

    for(int i = 0; i < 3; i++)
    {
        std::cin >> lamp[i];
        if(lamp[i]) sum += i;
    }

    std::cout << sum << std::endl;
    return 0;
}