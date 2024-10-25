#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("*** 신한/국민 K-패스 체크카드 시뮬레이션 프로그램 ***\n");
	int bus=0, survice=0;
	int bus_discount=0, survice_discount=0;
	int other=0;
	int han_sum_discount1 = 0, min_sum_discount1 = 0;

	printf("월평균 대중교통 요금: ");
	scanf("%d", &bus);

	while (bus < 0)
	{
		printf("0원 이상의 값으로 다시 입력하세요.\n");
		printf("월평균 대중교통 요금: ");
		scanf("%d", &bus);
	}

	printf("월평균 생활서비스 결제액: ");
	scanf("%d", &survice);
	while (survice < 0)
	{
		printf("0원 이상의 값으로 다시 입력하세요.\n");
		printf("월평균 생활서비스 결제액: ");
		scanf("%d", &survice);
	}

	printf("월평균 기타 결제액: ");
	scanf("%d", &other);
	while (other < 0)
	{
		printf("0원 이상의 값으로 다시 입력하세요.\n");
		printf("월평균 기타 결제액: ");
		scanf("%d", &other);
	}
	// 신한 할인 계산
	int han_sum = bus + survice + other;
	if (han_sum >= 200000 && han_sum<500000)
	{
		bus_discount = bus * 0.1;
		if (bus_discount > 2000)
			bus_discount = 2000;

		survice_discount = survice * 0.02;
		if (survice_discount > 2000)
			survice_discount = 2000;

		han_sum_discount1 = bus_discount + survice_discount;
		double han_sum_discount2 = (double)han_sum_discount1 / han_sum * 100;
		printf("신한 K-패스의 체크카드의 예상 할인 금액은 %d원이며, 할인률은 %.2f%%입니다.\n",han_sum_discount1, han_sum_discount2);
	}
	else if (han_sum >= 500000)
	{
		bus_discount = bus * 0.1;
		if (bus_discount > 5000)
			bus_discount = 5000;

		survice_discount = survice * 0.02;
		if (survice_discount > 5000)
			survice_discount = 5000;

		han_sum_discount1 = bus_discount + survice_discount;
		double han_sum_discount2 = (double)han_sum_discount1 / han_sum * 100;
		printf("신한 K-패스의 체크카드의 예상 할인 금액은 %d원이며, 할인률은 %.2f%%입니다.\n", han_sum_discount1, han_sum_discount2);
	}
	else
	{
		han_sum_discount1 = 0;
		double han_sum_discount2 = 0;
		printf("신한 K-패스의 체크카드의 예상 할인 금액은 %d원이며, 할인률은 %.2f%%입니다.\n", han_sum_discount1, han_sum_discount2);
	}
	// 국민 할인 계산

	int min_sum = bus + survice + other;
	if (min_sum >= 200000)
	{
		bus_discount = bus * 0.1;
		if (bus_discount > 2000)
			bus_discount = 2000;

		survice_discount = survice * 0.02;
		if (survice_discount > 8000)
			survice_discount = 8000;

		min_sum_discount1 = bus_discount + survice_discount;
		double min_sum_discount2 = (double)min_sum_discount1 / han_sum * 100;
		printf("국민 K-패스의 체크카드의 예상 할인 금액은 %d원이며, 할인률은 %.2f%%입니다.\n", min_sum_discount1, min_sum_discount2);
	}

	else
	{
		min_sum_discount1 = 0;
		double min_sum_discount2 = 0;
		printf("국민 K-패스의 체크카드의 예상 할인 금액은 %d원이며, 할인률은 %.2f%%입니다.\n", min_sum_discount1, min_sum_discount2);
	}

	if (han_sum_discount1 > min_sum_discount1)
	{
		printf("따라서 신한 K-패스 체크카드가 더 나은 선택입니다.\n");
	}
	else if (han_sum_discount1 < min_sum_discount1)
	{
		printf("따라서 국민 K-패스 체크카드가 더 나은 선택입니다.\n");
	}
	else
	{
		printf("따라서 어느 것을 선택하셔도 혜택이 동일합니다.\n");
	}
	

	return 0;
}
