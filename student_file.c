#include <stdio.h>
#define STUDENT_COUNT 3

struct Student
{
    char name[16];
    int age;
};

int main(void)
{
    struct Student student[STUDENT_COUNT] = {0};
    FILE *file = fopen("student.txt", "w");
    if (file == NULL)
    {
        printf("文件打开失败！\n");
        perror("file");
        return 1;
    }
    printf("请输入你要保存的姓名，年龄(空格隔开 %d组):\n", STUDENT_COUNT);

    for (int i = 0; i < STUDENT_COUNT; i++)
    {
        if (scanf("%15s %d", student[i].name, &student[i].age) != 2)
        {perror("scanf"); printf("输入格式错误！\n"); fclose(file); return 1;}
        if (fprintf(file, "%s %d\n",
                       student[i].name,
                       student[i].age) != 2)
        {perror("fprintf"); printf("写入失败！\n"); fclose(file); return 1;}
        if (fclose(file) != 0)
        {perror(file); printf("文件关闭失败！\n"); return 1;}

    return 0;
}
