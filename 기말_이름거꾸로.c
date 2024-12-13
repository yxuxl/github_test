#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int len = 0, i = 0;
	char voca[100], rev_voca[100];
	printf("영단어 입력: ");
	scanf("%s", voca);

	while (voca[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
		rev_voca[i] = voca[len - 1 - i];
	rev_voca[len] = '\0';

	printf("뒤집힌 영단어: %s \n", rev_voca);
	return 0;
}
