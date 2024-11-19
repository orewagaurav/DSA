#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items based on value/weight ratio
void sortItems(int values[], int weights[], int n) {
    double ratios[n];
    for (int i = 0; i < n; i++) {
        ratios[i] = (double)values[i] / weights[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratios[i] < ratios[j]) {
                double tmpRatio = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = tmpRatio;

                swap(&values[i], &values[j]);
                swap(&weights[i], &weights[j]);
            }
        }
    }
}

// Function to calculate the maximum total value in the knapsack
double getMaxValue(int values[], int weights[], int n, int capacity) {
    sortItems(values, weights, n);

    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weights[i] <= capacity) {
            capacity -= weights[i];
            totalValue += values[i];
        } else {
            totalValue += (double)values[i] * capacity / weights[i];
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    scanf("%d %d", &n, &capacity);

    int values[n], weights[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &values[i], &weights[i]);
    }

    double maxValue = getMaxValue(values, weights, n, capacity);
    printf("Maximum total value in the knapsack: %.6f\n", maxValue);

    return 0;
}
