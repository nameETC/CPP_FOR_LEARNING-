#include <cstdio>
#include "./add/add.h"
#include "./sub/sub.h"
 
int main()
{
    int a=1,b=2;
 
    printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", sub(a, b));
 
    //getchar();
    return 0;
}