#include <stdio.h>

int main()
{
char ch = 'A';
char* c_ptr = &ch;

printf("修改前：%c\n",ch);

*c_ptr = 'a';

printf("修改后：%c\n",ch);

return 0;
}
