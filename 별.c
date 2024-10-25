#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//역피라미드
int main()
{
	int a, b, c = 0;
	int line = 5;
	for (a = 1;a <= line;a++)
	{
		for (b = a;b > 1 && b < 6;b--)
			printf(" ");
		for (c = 11-(2*a); c > 0; c--)
			printf("*");
		printf("\n");
	}
}

/* 약간 역피마리드 절반
int main()
{
	int a, b, c = 0;
	int line = 5;
	for (a = 1;a <= line;a++)
	{
		for (b = a;b>1&&b<6;b--)
			printf(" ");
		for (c = 6-a; c > 0; c--)
			printf("*");
		printf("\n");
	}
}
*/

/*정석 피라미드
int main()
{
	int a, b, c = 0;
	int line = 5;
	for (a = 1; a <= line; a++)
	{
		for (b = a; b < line; b++)
			printf(" ");
		for (c = 1; c < 2*a; c++)
			printf("*");
		printf("\n");
	}
	
}*/
/* 이건 중간에 작대기 들어간 거
int a, b, c;
int line = 5;
for (a = 1; a <= line; a++)
{
    for (b = a; b < line; b++)
        printf(" ");
    for (c = 1; c <= ((2 * a) - 1); c++)
    {
        if (c == 1 || c == ((a * 2) - 1))
            printf("*");
        else printf("-");
    }
    printf("\n");

}
return 0;
*/