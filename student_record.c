#include<stdio.h>

int main()
{
    FILE *file = fopen("student.txt","w");

    if(file == NULL)
    {
        printf("打开失败！\n");
        return 1;
    }

    struct Student
    {
        char name[16];
        int age;
        char gender;
    };

    int student_count = 0;

    printf("请输入你要记录的人数：\n");

    scanf("%d", &student_count);

    struct Student student[student_count];

    printf("请输入每个学生的姓名(不超5个字)，年龄，性别(F/M)：\n");

    for(int i = 0; i < student_count; i++)
        {
            scanf("%15s %d %c",
                student[i].name,
                &student[i].age,
                &student[i].gender);

            fprintf(file,"%s %d %c\n",
                student[i].name,
                student[i].age,
                student[i].gender);
        }

    printf("记录完成！");

    fclose(file);
    return 0;
}
