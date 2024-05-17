#include <stdio.h>

int minCoins(int coins[], int n, int amount, int usedCoins[]) {
    int i, minCoins = 0;
    for (i = n - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            minCoins++;
            amount -= coins[i];
            usedCoins[i]++;
        }
    }
    return minCoins;
}

int main() {
    int coins[10];
    int usedCoins[10] = {0};  // To keep track of the coins used
    int n, i, amount;

    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    printf("Enter the coin denominations:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount: ");
    scanf("%d", &amount);

    int amountCopy = amount;  // Copy of the original amount to use for printing later

    int minCoinsRequired = minCoins(coins, n, amount, usedCoins);

    printf("Coin denominations and minimum number of coins used:\n");
    for (i = n - 1; i >= 0; i--) {
        if (usedCoins[i] > 0) {
            printf("%d x %d coins\n", usedCoins[i], coins[i]);
        }
    }

    printf("Minimum number of coins required: %d\n", minCoinsRequired);

    return 0;
}
