#include <stdio.h>
#include <stdlib.h>

//��̬�ڴ� �ܽ᣺
//�ṹ�������һ��Ԫ�ش�С��δ֪�� ��ͽ�����������ĳ�Ա

struct S{
    int n;
    int arr[0]; //���������Աǰ��������һ��������Ա
};

int main() {

//    printf("%d\n",sizeof(struct S)); //4
    //Ϊarr����20���ֽ�
    struct S* ps = (struct S*)malloc(sizeof(struct S)+5*sizeof(int));
    ps->n = 100;
    int i = 0;
    for(i = 0; i<5;i++)
    {
        ps->arr[i] = i;
    }


    //���¿���
    struct S* pps = (struct S*)realloc(ps,40);
    if(pps != NULL)
    {
        ps = pps;
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
