#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 팩토리얼을 계산하는 함수
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// nCk를 계산하는 함수
int combination(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int height;
    printf("파스칼 삼각형의 높이를 입력하세요: ");
    scanf("%d", &height);

    for (int i = 0; i < height; i++) {
        // 각 줄의 앞쪽 공백 출력 (삼각형 모양을 위해)
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }

        // 파스칼 삼각형의 값 출력
        for (int j = 0; j <= i; j++) {
            printf("%d ", combination(i, j));
        }
        printf("\n");
    }

    return 0;
}
