long long dp[25][25];
int ban[25][25];

int main(void)
{
    int B_x, B_y, horse_x, horse_y;
    scanf("%d %d %d %d", &B_x, &B_y, &horse_x, &horse_y);

    int hr_x[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    int hr_y[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2};

    for (int k = 0; k < 9; k++)
    {
        int ban_x = horse_x + hr_x[k];
        int ban_y = horse_y + hr_y[k];
        ban[ban_x][ban_y] = 1;
    }

    for (int i = 0; i <= B_x; i++)
    {
        for (int j = 0; j <= B_y; j++)
        {
            if (ban[i][j]) dp[i][j] = 0;
            else if (i == 0 && j == 0) dp[i][j] = 1;
            else
            {
                long long up = (i > 0) ? dp[i-1][j] : 0;
                long long left = (j > 0) ? dp[i][j-1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    printf("%lld\n", dp[B_x][B_y]);
    return 0;
}
                dp[i][j] = up + left;
            }
        }
    }
    printf("%lld\n", dp[B_x][B_y]);
    return 0;
}
