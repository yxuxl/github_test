#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr1[6] = { 1,2,3,4,5,6 };
	int arr2[6] = { 7,8,9,10,11,12 };
	int i = 0, temp = 0;
	int* a = &arr1[0];
	int* b = &arr2[0];


	printf("arr1: ");
	for (i = 0;i < 6;i++)
		printf("%d ", arr1[i]);
	printf("\narr2: ");
	for (i = 0;i < 6;i++)
		printf("%d ", arr2[i]);

	printf("\nafter swap\n");
	for (i = 0;i < 6;i++)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		a++;
		b++;
	}
	printf("arr1: ");
	for (i = 0;i < 6;i++)
		printf("%d ", arr1[i]);
	printf("\narr2: ");
	for (i = 0;i < 6;i++)
		printf("%d ", arr2[i]);


}
