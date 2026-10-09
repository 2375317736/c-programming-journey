#include <stdio.h>

void say_hello(char name[])
{
    printf("hello! %s\n",name);
}
int main()
{
    printf("请输入姓名\n");

    char name[16];

    scanf("%15s",name);

    say_hello(name);

    return 0;
}
