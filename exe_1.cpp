//
//  main.cpp
//  exe_1
//
//  Created by 陈昭文 on 2016/10/20.
//  Copyright © 2016年 陈昭文. All rights reserved.
//

#include "stdio.h"
void costitute(int n,int m);
int b[100];
int main()
{
    char a[10][2]={0};
    int t,N,M,i;
    do{
    printf("请输入测试数据组数(0到10之间)");
        scanf("%d",&t);}while(t<=0||t>10);
    for (i=1; i<=t; i++) {
        printf("请输入N，M的值(以逗号分隔):");
        scanf("%d,%d",&N,&M);
        if (M<=N&&N<=30) {
            a[i][0]=N;
            a[i][1]=M;
        }
        else do{
            printf("输入错误，请重新输入！");
            scanf("%d,%d",&N,&M);
            a[i][0]=N;
            a[i][1]=M;
        }while(M>N);
    }
    for (i=1; i<=t; i++) {
        printf("第%d组的所有可能组合情况为：\n",i);
        b[0]=a[i][1];
        costitute(a[i][0],a[i][1]);
        printf("\n");
    }
}

void costitute(int n,int m)
{
    int i,j;
    for (i=n; i>=m; i--) {
        b[m]=i;
        if (m>1) {
            costitute(i-1, m-1);
        }
        else{
            for (j=b[0]; j>0; j--) {
                printf("%d ",b[j]);
                
            }
            printf("\n");
        }
    }
}
