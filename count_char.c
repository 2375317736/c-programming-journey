#include <stdio.h>
#include <string.h>

void count_char(const char s[], char c)
{
    int count = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == c)
        {
            count += 1;
        }
    }
    printf("查找到目标字母 %d 个！\n", count);
}

int main(void)
{
    char sentence[100] = "banana";
    char target_char = 'a';

    printf("自动测试计算英语单词香蕉含有几个字母a！\n");
    count_char(sentence, target_char);

    printf("请输入您要查找字母的英文句子：\n");
    fgets(sentence, sizeof(sentence), stdin);
    printf("请输入你要计数的字母：\n");
    scanf("%c", &target_char);
    count_char(sentence, target_char);

    return 0;
}
