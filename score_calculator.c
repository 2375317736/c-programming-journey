#include <stdio.h>

#define MAX_SUBJECT_COUNT 9

void calculate_sum( const double scores[], int subject_count)
{
    double sum = 0;

    for(int i = 0; i < subject_count; i++)
        {
        sum += scores[i];
        }
    printf("你的总分是%.1f\n", sum);
}

double calculate_average(const double scores[],int subject_count)
{
    double sum = 0;
    double average = 0;

    for (int i = 0; i < subject_count; i++)
        {
        sum += scores[i];
        }
    average = sum / subject_count;

    printf("你的平均分是%.1f\n",average);
}

int main()
{
    int subject_count = 3;

    printf("这是一个成绩计算器,会打印你的总/平均分\n");

    while(1)
        {
        printf("请输入学科数目（默认三门）\n"
               "(最大九门)\n");

        scanf("%d", &subject_count);

        if(subject_count > 0 && subject_count <= MAX_SUBJECT_COUNT)

            {break;}
        else
            {printf("学科数目不对，请重新输入\n");}
        }
    double scores[subject_count];

    printf("请分别输入高考成绩:\n");

    for(int i = 0; i < subject_count; i++)
        {
        scanf("%lf", &scores[i]);
        }
    calculate_sum(scores, subject_count);
    calculate_average(scores, subject_count);

    return 0;
}
