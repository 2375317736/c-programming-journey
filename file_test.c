#include<stdio.h>

int main(void)
{
    FILE *file = fopen("student.txt", "w");

    if(file == NULL)
        {
        printf("打开失败！\n");
        return 1;
        }

    fprintf(file,"刘丽琴 18 F\n"
        "姜凌越 18 M\n"
        "李泽刚 18 M\n");

    fclose(file);

    printf("保存成功！\n");

    return 0;
}
