#include <stdio.h>

double sqrtUser(double number, int n) {
    if (number < 0) {
        return -1; 
    }

    if (number == 0) {
        return 0;
    }

    double tolerance = 0.9;
    if (n == 0) {
        tolerance = 0;
    } else {
        for (int i = 0; i < n; i++) {
            tolerance = tolerance / 10.0;
        }
    }

    double new_number = number / 2;
    double prev_numb = 0;

    while (1) {
        double difference = new_number - prev_numb;
        if (difference < 0) {
            difference = -difference;
        }

        if (difference < tolerance) {
            return new_number;
        }

        prev_numb = new_number;
        new_number = 0.5 * (new_number + number / new_number); 
    }
}

int main() {
    double number;
    int n;

    printf("Enter the number to find the square root of: ");
    scanf("%lf", &number);

    printf("Enter the number of decimal places for precision: ");
    scanf("%d", &n);

    printf("The square root of %lf up to %d decimal places is: %.*lf\n", number, n, n, sqrtUser(number, n));
    return 0;
}
