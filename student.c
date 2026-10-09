#include <stdio.h>

struct Student
{
    char name[16];
    int age;
    char gender;
};

void print_student(struct Student student)
{
    printf("已存入姓名：%s\n年龄：%d\n性别：%c\n",
        student.name,
        student.age,
        student.gender);
}

void change_age(struct Student *student)
{
    printf("请输入您要修改的年龄：\n");

    scanf("%d",&student->age);

    printf("修改成功！\n");
}
int main(void)
{
    int student_count = 0;
    int change_number = 0;
    printf("你想存几名学生：\n");

    scanf("%d",&student_count);

    struct Student student[student_count];

    for(int i = 0; i < student_count; i++)
        {
        printf("请输入姓名(不超过5个字)，年龄，性别（F/M）\n");

        scanf("%15s %d %c",
            student[i].name,
            &student[i].age,
            &student[i].gender);

        print_student(student[i]);
        }

    printf("你已存入%d名学生信息\n",student_count);
    printf("是否修改学生年龄？是 请输入学生序号，否 请输入0\n");

    scanf("%d", &change_number);

    if(change_number == 0)
        {
        return 0;
        }
    else
        {
        change_age(&student[change_number - 1]);

        print_student(student[change_number - 1]);
        }

    return 0;
}
