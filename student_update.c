#include <stdio.h>
#include <string.h>

struct Student
{
    char name[16];
    int age;
    char gender;
};

int main(void)
{
    FILE *file = fopen("student.txt", "r");
        if (file == NULL)
        {
            printf("文件打开失败！\n");
            return 1;
        }

    FILE *temp_file = fopen("temp_student.txt","w");
        if (temp_file == NULL)
        {
            printf("临时文件打开失败！\n");
            fclose(file);
            return 1;
        }

    int found = 0;
    char target_name[16];
    char new_name[16];
    int new_age;
    char new_gender;

    struct Student student;

    printf("请输入你要修改的学生姓名：\n");

    scanf("%15s", target_name);

    int scanf_result;

    while ((scanf_result = fscanf(file, "%15s %d %c",
                          student.name,
                          &student.age,
                          &student.gender)) == 3)
    {
        if (strcmp(student.name, target_name) == 0)
        {
            printf("请输入修改后的姓名，年龄，性别(F/M)：\n");

            if (scanf("%15s %d %c", new_name, &new_age, &new_gender) != 3)
            {
                printf("格式输入错误！\n");
                fclose(file);
                fclose(temp_file);
                remove("temp_student.txt");
                return 1;
            }

            strcpy(student.name, new_name);
            student.age = new_age;
            student.gender = new_gender;

            found = 1;

        }

        fprintf(temp_file, "%s %d %c\n",
                student.name,
                student.age,
                student.gender);
    }
        if (ferror(file))
        {
            printf("读取文件时发生错误！\n");
            fclose(file);
            fclose(temp_file);
            remove("temp_student.txt");
            return 1;
        }

        if (!feof(file))
        {
            printf("文件格式错误，取消修改！\n");
            fclose(file);
            fclose(temp_file);
            remove("temp_student.txt");
            return 1;
        }


    fclose(file);
    fclose(temp_file);

    if (found != 1)
    {
        printf("未找到查找目标！\n");

        remove("temp_student.txt");

        return 1;
    }

    if (rename("temp_student.txt", "student.txt") != 0)
    {
        printf("文件替换失败！\n");

        remove("temp_student.txt");

        return 1;

    }

    printf("修改成功！\n");

    return 0;
}
