#include <stdio.h>





int main()
{
    int a = 20; // 10100 11100 = 28
    int err_code = 8;

    printf("%d\n", a);

    a = a | err_code;

    printf("%d\n", a);

    return 0;
}
