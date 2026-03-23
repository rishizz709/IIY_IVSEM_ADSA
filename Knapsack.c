#include <stdio.h>

#define MAX 50

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int wt[MAX], val[MAX], dp[MAX][MAX];
    int n, W, i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &val[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    // Build DP table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i] <= j)
                dp[i][j] = max(val[i] + dp[i-1][j - wt[i]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("Maximum profit = %d\n", dp[n][W]);

    return 0;
}