#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int number, sum, digit;

    while (1) {
        printf("���ڸ� �Է��ϼ��� (���� �Է� �� ����): ");
        scanf("%d", &number);

        if (number < 0) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        sum = 0;
        while (number > 0) {
            digit = number % 10;
            sum += digit;
            number /= 10;
        }

        printf("�ڸ����� ��: %d\n", sum);
    }

    return 0;
}
