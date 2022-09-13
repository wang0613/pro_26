#include <stdio.h>
#include <stdlib.h>

//动态内存 总结：
//结构体中最后一个元素大小是未知的 这就叫做柔型数组的成员

struct S{
    int n;
    int arr[0]; //柔性数组成员前面至少有一个其他成员
};

int main1() {

//    printf("%d\n",sizeof(struct S)); //4
    //为arr开辟20个字节
    struct S* ps = (struct S*)malloc(sizeof(struct S)+5*sizeof(int));
    ps->n = 100;
    int i = 0;
    for(i = 0; i<5;i++)
    {
        ps->arr[i] = i;
    }


    //重新开辟
    struct S* pps = (struct S*)realloc(ps,40);
    if(pps != NULL)
    {
        ps = pps; //重新开辟的空间的地址 给
    }
    for(i = 1;i <10; i++)
    {
        ps->arr[i] = i;
    }

    for( i = 0; i <10; i++)
    {
        printf("%d ",ps->arr[i]);
    }
    free(pps);
    pps= NULL;
    return 0;
}

struct SS
{
    int n;
    int* arr;
};

int main()
{
    struct SS* p = (struct SS*)malloc(sizeof(struct SS));
    p->n = 100;
    //为arr 开辟40个字节
    p->arr = (int*) malloc(10*sizeof(int));

    int i = 0;
    for(i =0; i <10; i++)
    {
        p->arr[i] = i;
    }
    for(i = 0 ;i < 10;i++)
    {
        printf("%d ",p->arr[i]);
    }

    free(p->arr);
    p->arr = NULL;
    free(p);
    p= NULL;

    return 0;

}