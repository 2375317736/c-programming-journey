#include<stdio.h>

int main(void)
{
    FILE *file = fopen("student.txt", "r");

    if(file == NULL)
        {
            printf("文件打开失败！\n");
            return 0;
        }

    struct Student
    {
        char name[16];
        int age;
        char gender;
    };

    struct Student student;

    while(fscanf(file, "%15s %d %c",
        student.name,
        &student.age,
        &student.gender) == 3)
    {
        printf("姓名：%s\n", student.name);
        printf("年龄：%d\n",student.age);
        printf("性别：%c\n",student.gender);
    }

    printf("打印完成！\n");

    fclose(file);

    return 0;
}
