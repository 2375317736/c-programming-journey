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
    FILE *temp_file = fopen("temp_student.txt", "w");
        if (temp_file == NULL)
        {
            printf("临时文件打开失败！\n");
            fclose(file);
            return 1;
        }

    struct Student student;

    int scan_result = 0;
    int found = 0;
    char target_name[16];

    printf("请输入你要删除的学生名字：\n");
    scanf("%15s", target_name);

    while ((scan_result = fscanf(file, "%15s %d %c",
                                 student.name, &student.age,
                                 &student.gender)) == 3)
    {

        if (strcmp(student.name, target_name) != 0)
        {
            fprintf(temp_file, "%s %d %c\n",
                    student.name,
                    student.age,
                    student.gender);
        }
        else {found = 1;}
    }

    if (ferror(file))
    {
        printf("文件读取时发生错误！\n");
        fclose(file);
        fclose(temp_file);
        remove("temp_student.txt");
        return 1;
    }
    if (feof(file))
    {
        printf("文件格式错误！\n");
        fclose(file);
        fclose(temp_file);
        remove("temp_student.txt");
        return 1;
    }

    if (rename("temp_student.txt", "student.txt") != 0)
    {
        printf("文件替换失败！\n");
        fclose(file);
        fclose(temp_file);
        remove("temp_student.txt");
        return 1;
    }

    printf("删除完成！\n");
    return 0;
}
