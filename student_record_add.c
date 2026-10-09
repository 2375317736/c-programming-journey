#include<stdio.h>

int main(void)
{
    FILE *file = fopen("student.txt","a");

    if (file == NULL)
    {
        printf("打开失败！");
        return 1;
    }

    struct Student
    {
        char name[16];
        int age;
        char gender;
    };

    struct Student student;

    printf("请输入你想追加学生的姓名，年龄，性别：\n");

    scanf("%15s %d %c",
        student.name,
        &student.age,
        &student.gender);

    fprintf(file,"%s %d %c\n",
        student.name,
        student.age,
        student.gender);

    printf("追加完成！");

    fclose(file);

    return 0;
}
