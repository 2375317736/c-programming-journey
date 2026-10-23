#include <stdio.h>
long long dp[25][25];
int main(void)
{
    int B_x, B_y, horse_x, horse_y;
    scanf("%d %d %d %d", &B_x, &B_y, &horse_x, &horse_y);
    dp[0][0] = 1;
    for (int i = 0; i <= B_x; i++)
    {
        for (int j = 0; j <= B_y; j++)
        {
            if (i > 0) dp[i][j]+=dp[i-1][j];
            if (j > 0) dp[i][j]+=dp[i][j-1];
        }
    }
    printf("%lld", dp[B_x][B_y]);
    return 0;
}
