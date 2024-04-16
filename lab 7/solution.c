#include <stdio.h>

int main() {
    int n = 5; // Number of students
    int m = 3; // Number of components

    // Allocation matrix
    int alloc[n][m] = {
        {1, 1, 2},
        {2, 1, 2},
        {3, 0, 1},
        {0, 2, 0},
        {1, 1, 2}
    };

    // Maximum demand matrix
    int max[n][m] = {
        {5, 4, 4},
        {4, 3, 3},
        {9, 1, 3},
        {8, 6, 4},
        {2, 2, 3}
    };

    // Available vector
    int avail[m] = {10, 7, 8};

    // Calculate need matrix
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Print need matrix
    printf("Need matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Print available vector
    printf("Available vector: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", avail[i]);
    }
    printf("\n");

    // Banker's Algorithm
    int f[n], ans[n], ind = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 0;
    }

    int y = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    // Check if system is in safe state
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            break;
        }
    }

    if (flag == 1) {
        printf("Following is the SAFE Sequence:\n");
        for (int i = 0; i < n - 1; i++) {
            printf("S%d -> ", ans[i]);
        }
        printf("S%d\n", ans[n - 1]);
    } else {
        printf("The system is not in a safe state.\n");
    }

    return 0;
}

