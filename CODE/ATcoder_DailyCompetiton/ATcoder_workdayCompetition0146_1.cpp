#include <iostream>
#include <string>
using namespace std;

struct Die
{
    long long pos = 0;
    int top = 0;
    int front = 0;
}dice[200005];

int main()
{
    int N, Q;
    long long M;
    //输入骰子个数、格子长度、操作次数
    cin >> N >> M >> Q;
    //输入每个骰子的初始状态
    for(int i = 0; i < N; i++)
        cin >> dice[i].pos >> dice[i].top >> dice[i].front;
    //输入Q次操作
    while(Q--)
    {
        char ch;
        long long index;
        cin >> index >> ch;
        if(ch == '+')
        {
            dice[index - 1].pos += 1; 
            int temp = dice[index - 1].top;
            dice[index - 1].top = 7 - dice[index - 1].front;
            dice[index - 1].front = temp;
        }
        if(ch == '-')
        {
            dice[index - 1].pos -= 1; 
            int temp = dice[index - 1].top;
            dice[index - 1].top = dice[index - 1].front;
            dice[index - 1].front = 7 - temp;
        }
    }

    for(int j = 0; j < N; j++)
    {
        cout << dice[j].pos << " " << dice[j].top << '\n';
    }
    return 0;
}