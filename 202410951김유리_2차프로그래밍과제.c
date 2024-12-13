#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char arr1[5][5];
char arr2[5][5];
int total = 25;
int c_count = 20;
int f_count = 5;
void func1()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", arr1[i][j]);
        }
        printf("\n");
    }
}
void func2()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr2[i][j] = '.';
        }
    }
    while (c_count > 0 || f_count > 0)
    {
        int random = rand() % total;
        int hang = random / 5;
        int yeol = random % 5;

        if (arr2[hang][yeol] != '.')
        {
            continue;
        }

        if (c_count > 0)
        {
            arr2[hang][yeol] = 'C';
            c_count--;
        }
        else if (f_count > 0)
        {
            arr2[hang][yeol] = 'F';
            f_count--;
        }
    }

    int found_c_count = 0;
    int attempts = 0;

    while (attempts < 5)
    {
        int hang, yeol;
        printf("���� �����ϼ��� (���ȣ ����ȣ): ");
        scanf("%d %d", &hang, &yeol);

        if (hang < 0 || hang >= 5 || yeol < 0 || yeol >= 5)
        {
            continue;
        }

        if (arr1[hang][yeol] != '.')
        {
            printf("�̹� ���� ���Դϴ�.\n");
            func1();
            continue;
        }

        char select = arr2[hang][yeol];
        arr1[hang][yeol] = select;

        if (select == 'F')
        {
            arr1[hang][yeol] = '#';
            printf("Ŀ�ǰ� �ƴ� ��� �����̳׿�!\n");
            break;
        }
        else if (select == 'C')
        {
            found_c_count++;
        }

        attempts++;

        if (attempts < 5)
        {
            func1();
        }
        else if (attempts == 5)
        {
            if (select == 'C')
                printf("����� �̰���ϴ�! Ŀ�� �ټ� ���� ����׿�!\n");
        }

        if (found_c_count == 20)
        {
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr1[i][j] == 'C' || arr1[i][j] == '#')
            {
                printf("%c", arr1[i][j]);
            }
            else if (arr2[i][j] == 'F')
            {
                printf("F");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr1[i][j] = '.';
            printf("%c", arr1[i][j]);
        }
        printf("\n");
    }

    func2();
    return 0;
}
