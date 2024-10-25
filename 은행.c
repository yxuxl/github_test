#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int balance = 100000;
    int option, amount = 0;

    while (1) {
        printf("\n1. 잔액 조회\n");
        printf("2. 입금\n");
        printf("3. 출금\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("현재 잔액: %d원\n", balance);
            break;
        case 2:
            printf("입금할 금액을 입력하세요: ");
            scanf("%d", &amount);
            if (amount > 0) {
                balance += amount;
                printf("입금 완료. 현재 잔액: %d원\n", balance);
            }
            else {
                printf("올바른 금액을 입력하세요.\n");
            }
            break;
        case 3:
            printf("출금할 금액을 입력하세요: ");
            scanf("%d", &amount);
            if (amount > balance) {
                printf("잔액이 부족합니다.\n");
            }
            else if (amount > 0) {
                balance -= amount;
                printf("출금 완료. 현재 잔액: %d원\n", balance);
            }
            else {
                printf("올바른 금액을 입력하세요.\n");
            }
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }
}
