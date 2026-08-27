#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score[20];
    int target,i,flag=0,pos;
    //设置随机数种子
    srand((unsigned int)time(NULL));

    //随机生成20个0?100的整数
    for(i=0;i<20;i++)
    {
        score[i]=rand()%101;
    }

    //打印生成的成绩
    printf("生成的20个成绩: ");
    for(i=0;i<20;i++)
    {
        printf("%d ",score[i]);
    }
    printf("\n");

    //输入要查找的分数
    printf("请输入要查找的分数:");
    scanf("%d",&target);

    //遍历查找，找第一次出现的位置
    for(i=0;i<20;i++)
    {
        if(score[i]==target)
        {
            flag=1;
            pos=i;
            break;
        }
    }

    //输出结果
    if(flag==1)
    {
        printf("找到了！位置是：%d",pos);
    }
    else
    {
        printf("没有找到该分数！");
    }

    return 0;
}