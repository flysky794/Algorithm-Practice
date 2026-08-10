#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    if(n == 1 || n == 2)
    {
        printf("1");
        return 0;
    }
    int a = 1, b = 1, c = 0;
    for(int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("%d", c);
}
