#include <stdio.h>

void ginsu_hex(int num) {
    if (num < 16) {
        if (num < 10)
            printf("%d", num);  // 0~9는 숫자 그대로 출력
        else
            printf("%c", 'A' + (num - 10));  // 10~15는 A~F로 출력
    } else {
        int n = num % 16;  // 현재 자리의 16진수 값 구하기
        ginsu_hex(num / 16);  // 상위 자리 변환을 위해 재귀 호출

        if (n < 10)
            printf("%d", n);  // 0~9는 숫자 그대로 출력
        else
            printf("%c", 'A' + (n - 10));  // 10~15는 A~F로 출력
    }
}

int main(void) {
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);
    ginsu_hex(num);
    return 0;
}
