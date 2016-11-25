//
//  main.cpp
//  exe_2
//
//  Created by 陈昭文 on 2016/10/20.
//  Copyright © 2016年 陈昭文. All rights reserved.
//

#include "stdio.h"
#include "ctype.h"
int Succ(int n);
int t=0;
int main()
{
    int n,m,a;
    do{
    t=0;
    printf("请输入n的值：");
    while(!scanf("%d",&n))
    {
        fflush(stdin);
        printf("输入错误，请重新输入:\n");
        getchar();
    }
    m=Succ(n);
    printf("结果为：%d,共计算：%d次 ",m,t);
    printf("是否重新输入？0/1");
    scanf("%d",&a);
    }while(a);
}
int Succ(int n)
{
    int i=0;
    t++;
    if (n<=100) {
        i=Succ(Succ(n+11));
    }
    else if (n>=101)
    {
        i=n-10;
    }
    return i;
}
