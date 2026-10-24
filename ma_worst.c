#include <stdio.h>
int main(void)
{
    long long DP[25][25] = {0};
    int ban [25][25] = {0};
    int B_x, B_y, horse_x, horse_y;

    scanf("%d %d %d %d", &B_x, &B_y, &horse_x, &horse_y);

    int dx[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    int dy[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
    int k = 0;
    for (k = 0; k < 9; k++)
    {
        int nx = horse_x + dx[k];
        int ny = horse_y + dy[k];
        if (nx >= 0 && nx <= B_x && ny >= 0 && ny <= B_y)
        {
            ban[nx][ny] = 1;
        }
    }
    int i, j;
    for (i = 0; i <= B_x; i++)
    {
        for (j = 0; j <= B_y; j++)
        {
            if (ban[i][j]) DP[i][j] = 0;
            else if (i == 0 && j == 0) DP[i][j] = 1;
            else
            {
                long long up = (i > 0) ? DP[i-1][j] : 0;
                long long left = (j > 0) ? DP[i][j-1] : 0;
                DP[i][j] = up + left;
            }
        }
    }
    printf("%lld\n",DP[B_x][B_y]);
    return 0;
}
