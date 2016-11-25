//
//  main.cpp
//  exe4_2
//
//  Created by 陈昭文 on 2016/10/24.
//  Copyright © 2016年 陈昭文. All rights reserved.
//

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MAX 100

char poker[]={'0','3','4','5','6','7','8','9','1','J','Q','K','A','2','j'};//开始的‘0’放在poker[0]占位，之后用‘1’代表10，‘j’代表joker
int a[MAX];
int b[MAX];
char str[MAX];
int Search()           //将存到字符串里的牌与预存的poker做比较，相同时向数组中放入poker[i]的值
{
    int i,j,flag;flag=0;
    for (i=0; str[i]!='\0'&&str[i]!='\n';i++) {
        if(str[i]!='-'&&flag==0){
        for (j=0; poker[j]!=0; j++) {                   //扑克牌与预存数据相同时（排除JOKER）
            if (str[i]==' ') {                          //数组为空格时直接跳过本次循环
                break;
            }
            if (str[i]==poker[j]&&str[i+1]!='O') {
                a[i]=j;
                break;
            }
            else if (str[i+1]=='O'){                    //检测到str[i]为‘J’时判断其后面一位是否为‘O’，是的话就是JOKER
                a[i]=15;
                i=i+5;                                  //将i+5可以直接跳过JOKER中的K单词
                break;
            }
            else if (str[i]=='j'){
                a[i]=14;
                i=i+5;
                break;
            }
        }
    }
        if (str[i]=='-'){                                  //设定flag，当扫描到‘-’时就把flag设定为1，此后对比得到的数就放到b数组中
            flag=1;
            i++;
        }
        if(flag==1){
            for (j=0; poker[j]!=0; j++) {                   //扑克牌与预存数据相同时（排除JOKER）
                    if (str[i]==' ') {
                        break;
                    }
                    if (str[i]==poker[j]&&str[i+1]!='O') {
                        b[i]=j;
                        break;
                    }
                    else if (str[i+1]=='O'){                    //输入为JOKER时
                        b[i]=15;
                        i=i+5;
                        break;
                    }
                    else if (str[i]=='j'){
                        b[i]=14;
                        i=i+5;
                        break;
                    }
                }
            }
        }
        return 1;
}
int Delete_0()                                  //将数组中的非零数字前移到数组的最前面
{
    int i,j;
    for (i=0; i<25; i++) {
        for (j=i; j<22; j++) {
            if (a[i]!=0) {
                break;
            }
            else if (a[j]==0)   continue;
            else{
                a[i]=a[j];
                a[j]=0;
            }
        }
    }
    for (i=0; i<25; i++) {
        for (j=i; j<22; j++) {
            if (b[i]!=0) {
                break;
            }
            else if (b[j]==0)   continue;
            else{
                b[i]=b[j];
                b[j]=0;
            }
        }
    }
    return 1;
}

int Correct()
{
    int m,n;
    for (m=0; a[m]!=0; m++) {           //前一组牌的数量

    }
    for (n=0; b[n]!=0; n++) {           //后一组牌的数量
        
    }
    if (m==0||n==0)
    {return 0;}
    if (m==1&&n==1) {
        return 1;
    }
    
    if (m==n&&m<=5&&a[0]!=14&&b[0]!=14)
    {
        if (m!=5)   {
            for (int i=0; i<m-1; i++) {
                if (a[i+1]==a[i]&&b[i+1]==b[i])   continue;
                else {
                    printf("输入错误!0");
                    return 0;
                }
            }
        }
        if(m==5)                                // 当为同花顺的时候需要判断是否为递增排序
        {
            for (int i=0; i<4; i++) {
                if ((a[i+1]-a[i])==1&&(b[i+1]-b[i]==1)) {
                    continue;
                }
                else {
                    printf("输入错误!1");
                    return 0;
                }
            }
        }
    }
    else if (a[0]==14||b[0]==14)      //有joker时
    {
        if (a[0]==14&&a[1]==15)         return 1;
        else if (b[0]==14&&b[1]==15)    return 1;
        else {
            printf("输入错误!4");
            return 0;
        }
    }

    else if (m==4||n==4)             //有炸弹时
    {
        if (m==4) {
            if (a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
                return 1;
            else {
                printf("输入错误!2");
                return 0;
            }
        }
        if (n==4){
            if (b[0]==b[1]&&b[1]==b[2]&&b[2]==b[3])     return 1;
            else {
                printf("输入错误!3");
                return 0;
            }
        }
    }
        else {
        printf("输入错误！4");
        return 0;
    }
       return 1;
}
int Compare()
{
    int m,n;
    for (m=0; a[m]!=0; m++) {           //前一组牌的数量
        
    }
    for (n=0; b[n]!=0; n++) {           //后一组牌的数量
        
    }
    if (m==n) {
        if (a[0]>b[0])    return 1;
        if (a[0]<b[0])    return 2;
    }
    else if(a[0]==14||b[0]==14){
        if (a[0]==14)   return 1;
        else return 2;
    }

    else if(m==4||n==4){
        if (m==4&&b[0]!=14)  return 1;
        if(n==4&&a[0]!=14)   return 2;
    }
        return 0;
}
int main()
{
    int i,j,k;
    printf("请输入扑克牌（以-分隔）: \n");
    fgets(str, MAX, stdin);
    Search();
    Delete_0();
    j=Correct();
    
    while (j==0) {
        printf("请重新输入：");
        a[MAX]={0};b[MAX]={0};
        fgets(str, MAX, stdin);
        Search();
        Delete_0();
        j=Correct();
    }
    if(j==1)
    {
        i=Compare();
        if (i==1)
            printf("前一组牌大");
        if (i==2)
            printf("后一组牌大");
    }
    
}
