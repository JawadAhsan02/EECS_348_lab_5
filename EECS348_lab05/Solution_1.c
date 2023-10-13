#include <stdio.h>

float CalculateAverage(float arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;

}

int main() {
    char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float sales[12];

    FILE *inputFILE = fopen("input.txt", "r");
    if (inputFILE == NULL) {
        printf("Error opeining the file\n");
        return 1;
    }

    for (int i = 0; i < 12; i++) {
        fscanf(inputFILE, "%f", &sales[i]);
    }

    fclose(inputFILE);

    printf("Monthly sales report for 2022:\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\t\t$%.2f\n", month[i], sales[i]);

    }

    float min = sales[0], max = sales[0];
    float sum = sales[0];
    int minIndex = 0, maxIndex = 0;

    for (int i = 1; i < 12; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }
        sum += sales[i];

    }

    float average = sum / 12;

    printf("\nsales summary:\n");
    printf("Minimum sales; $%.2f (%s)\n", min, month[minIndex]);
    printf("Maximum sales; $%.2f (%s)\n", max, month[maxIndex]);
    printf("Average sales: $%.2f\n", average);

    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++) {
        float movingAverage = CalculateAverage(sales + i, 6);
        printf("%s - %s $#.3f\n", month[i], month[i + 5], movingAverage);

    }

    printf("\nSales Report (Hughest to Lowest);\n");
    for (int i = 11; i >= 0; i--) {
        printf("%s\t\t$%.2f\n", month[i], sales[i]);

    }

    return 0;
    
}