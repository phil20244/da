#include <stdio.h>
#include <stdlib.h>

int main() {
    int p[10];
    int w[10];
    int f[10];
    float r[10];
    int sol[10];
    int n, m;
    int c = 0;
    float fraction = 0.0;

    printf("Enter number of fruits: ");
    scanf("%d", &n);
    printf("Enter max. capacity: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        printf("Enter profit of fruit %d: ", i + 1);
        scanf("%d", &p[i]);
        printf("Enter weight of fruit %d: ", i + 1);
        scanf("%d", &w[i]);
        r[i] = (float)p[i] / w[i];
        f[i] = i + 1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (r[j] < r[j + 1]) {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;

                temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;

                float tempRatio = r[j];
                r[j] = r[j + 1];
                r[j + 1] = tempRatio;
            }
        }
    }

    printf("Fruit\tProfit\tWeight\tRatio\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n", f[i], p[i], w[i], r[i]);
    }

    int wt = 0;
    int pro = 0;

    for (int i = 0; i < n; i++) {
        if (w[i] <= m) {
            wt += w[i];
            pro += p[i];
            m -= w[i];
            sol[c++] = f[i]; // Store the selected fruit index
        } else {
            fraction = (float)m / w[i];
            pro += p[i] * fraction;
            wt += w[i] * fraction;
            sol[c++] = f[i];
            break;
        }
    }

    printf("Selected Fruits: ");
    for (int i = 0; i < c - 1; i++) {
        printf("P%d ", sol[i]);
    }
    printf("%.2f * P%d\n", fraction, sol[c - 1]);
    printf("Total Profit: %d\nTotal Weight: %d\n", pro, wt);
    return 0;
}
