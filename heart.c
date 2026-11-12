#include <stdio.h>                                          // 需要 putchar 来逐个输出字符

int main(void)
{
    for (double y = 1.5; y > -1.5; y -= 0.1)            // y 坐标从上往下一行行扫过 1.5 → -1.5
    {
        for (double x = -1.5; x < 1.5; x += 0.05)       // x 坐标从左往右扫过 -1.5 → 1.5
        {
            double a = x * x + y * y - 1;               // 心形公式的一部分：x² + y² - 1
            if (a * a * a - x * x * y * y * y <= 0.0)   // (x²+y²-1)³ - x²y³ ≤ 0 的点落在心形内部
            {
                putchar('*');                           // 心形内部画 *
            }
            else
            {
                putchar(' ');                           // 心形外部留空格
            }
        }
        putchar('\n');                                  // 一行扫完，换行
    }
    return 0;
}