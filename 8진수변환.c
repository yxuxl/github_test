#include <stdio.h>
void ginsu_octal(int num)
{
    if (num < 8)
        printf("%d", num);
    else
    {
        int n = num % 8;
        ginsu_octal(num / 8);
        printf("%d", n);
    }
}

int main(void)
{
    int num;
    printf("Please enter a number: ");
    scanf_s("%d", &num);
    ginsu_octal(num);
    return 0;
}
