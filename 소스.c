#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int number, sum, digit;

    while (1) {
        printf("숫자를 입력하세요 (음수 입력 시 종료): ");
        scanf("%d", &number);

        if (number < 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        sum = 0;
        while (number > 0) {
            digit = number % 10;
            sum += digit;
            number /= 10;
        }

        printf("자리수의 합: %d\n", sum);
    }

    return 0;
}
