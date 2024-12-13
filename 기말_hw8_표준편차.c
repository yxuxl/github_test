#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double A(double arr[], int n);

int main()
{
    double numbers[5];
    printf("Enter 5 real numbers: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%lf", &numbers[i]);
    }
    double result = A(numbers, 5);
    printf("Standard Deviation= %.3f\n", result);
    return 0;
}

double A(double arr[], int n)
{
    double sum = 0.0, mean=0.0, variance = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    mean = sum / n;
    for (int i = 0; i < n; i++)
    {
        variance += pow(arr[i] - mean, 2);
    }
    variance /= n;
    return sqrt(variance);
}
