#include <stdio.h>

int main() {
    int number, reverse = 0;

    while (1) {
        printf("숫자를 입력하세요 (음수 입력 시 종료): ");
        scanf("%d", &number);

        if (number < 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        reverse = 0; // reverse를 초기화

        while (number != 0) {
            reverse = reverse * 10 + number % 10; // 기존 reverse에 10을 곱하고 새 자리 추가
            number /= 10; // 다음 자리로 이동
        }

        printf("뒤집은 숫자: %d\n", reverse);
    }

    return 0;
}
