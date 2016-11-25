//
//  main.cpp
//  exe_3
//
//  Created by 陈昭文 on 2016/10/21.
//  Copyright © 2016年 陈昭文. All rights reserved.
//

#include "stdio.h"
#include "ctype.h"
/*
 在空间中建立直角坐标系的话，本题判断油井点到管道的距离实际就是就各个点与管道（y=k）的纵坐标差之和
 不难看出，当n为奇数时，为求最小，管道应该是一边两个点一边三个点，当管路通过中间的点时，距离和有最小值
 n为偶数的时候，当管道在中间的时候（上下各两点）有距离最小值
 */
void sort(int *a, int left, int right);
int a[100];          //a[][1]为坐标x值，a[][2]为y值，实际上本题只会用到y值
int main()
{
    int sum=0;
    char c;
    int i=0;
    int n=0;
    int j;
    printf("请输入油井的纵坐标，以空格分开：");
    while((c=getchar())!='\n')
    {
        if(isdigit(c))
        {
            ungetc(c,stdin);//将c送回输入流
            scanf("%d",&a[n++]);
        }
    }
    sort(a, 0, n-1);
    printf("共有%d口油井\n",n);
    if (n%2==0) {                   //n为偶数
        for (i=0; i<n/2; i++) {
            int j=n-i-1;
            sum+=a[j]-a[i];
        }
        i=n/2-1;j=n/2;
         printf("主管道最短时的位置坐标为y=%d到y=%d之间任一直线\n",a[i],a[j]);
    }
    else{
        for (i=0; i<n/2+1; i++) {   //n为奇数
            j=n-i-1;
            sum+=a[j]-a[i];
        }
        j=n/2;
        printf("主管道最短时的位置方程为y=%d\n",a[j]);
    }
    printf("主管道的最短长度为：%d\n",sum);
}
void sort(int *a, int left, int right)
{
    if(left >= right)
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
    
    while(i < j){
        while(i < j && key <= a[j])
                {
            j--;       }
        
        a[i] = a[j];
              while(i < j && key >= a[i])
        {
            i++;
        }
        
        a[j] = a[i];
    }
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
    /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}
