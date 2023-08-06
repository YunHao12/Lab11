#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n;
    printf("Number of values of coins: ");
    scanf("%d", &n);

    int coins[n];
    printf("Coins:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    int amount;
    printf("Amount: ");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);

    printf("Answer: %d\n", result);

    return 0;
}
