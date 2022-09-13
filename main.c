#include <stdio.h>

//动态内存 总结：
//结构体中最后一个元素大小是未知的 这就叫做柔型数组的成员

struct S{
    int n;
    int arr[0]; //柔性数组成员前面至少有一个其他成员
};

int main() {



    return 0;
}
