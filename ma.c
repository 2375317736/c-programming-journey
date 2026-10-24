#include <stdio.h>        /*怎么得出答案？------先考虑答案是什么---从(0,0)到达终点(end_x,end_y)这个格子的路径数*/
long long DP[25][25];     /*难点在于一般人想不到------斐波那契数列---P[1]=1； P[2]=2； P[3]=P[2]+P[1]； P[4]=P[3]+P[2]；......; P[i]=P[i-1]+P[i-2]*/
int ban[25][25];          /*和这题的关系是什么？------小卒只能往下和往右走---即-抵达终点格子路径数为此格---左一格+右一格的路径数之和*/
                          /*为什么？你肯定会考虑往下和往右走一格答案不久+1了吗？不是这样的，答案是终点的路径数---即从(0,0)到终点的唯一路径数*/
int main(void)            /*也就是说回来---其实抵达你左边和上边的路径数之和，就是抵达你终点的路径数*/
{                         /*答案怎么来？很简单，想象一张网格图，你从最左上角(0,0)开始，往右的所有格都填1，往下的也填1；那么(1,-1)应该填几？没错上面加下面路径数 填2！*/
    int end_x, end_y, horse_x, horse_y;                                //如何用代码实现？------看我演示代码就行
    printf("输入终点的xy坐标，再输入马点的xy坐标（空格分开）");
    scanf("%d %d %d %d", &end_x, &end_y, &horse_x, &horse_y);

    ban[horse_x][horse_y] = 1;
    ban[horse_x + 1][horse_y + 2] = 1;    ban[horse_x + 2][horse_y + 1] = 1;
    if (horse_y > 1) ban[horse_x + 2][horse_y - 1] = 1;    if (horse_y > 2) ban[horse_x + 1][horse_y - 2] = 1;
    if (horse_x > 1 && horse_y > 2) ban[horse_x - 1][horse_y - 2] = 1;    if (horse_x >= 2 && horse_y >= 1) ban[horse_x - 2][horse_y - 1] = 1;
    if (horse_x >= 2) ban[horse_x - 2][horse_y + 1] = 1;    if (horse_x >= 1) ban[horse_x - 1][horse_y + 2] = 1;

    for(int i = 0; i <= end_x; i++)
    {
        for(int j = 0; j <= end_y; j++)
        {
            DP[0][0] = 1;

            if (i > 0) DP[i][j] += DP[i-1][j];
            if (j > 0) DP[i][j] += DP[i][j-1];
            if (ban[i][j]) DP[i][j] = 0;
        }
    }
    printf("%lld", DP[end_x][end_y]);
    return 0;
}
