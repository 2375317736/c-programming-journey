#include <stdio.h>

int main()
{
int n = 0;

char name[3][22];

printf("请输入打招呼人数n\n");

scanf("%d",&n);

printf ("请输入姓名\n");

for(int i=0;i<n;i++)
	{
	scanf("%s",name[i]);
	}
for(int i = 0;i<n;i++){
printf("<%s>,你好\n",name[i]);}
printf("睾丸乐");
return 0;
}
