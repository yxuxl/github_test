#include <stdio.h>

void sortWords(char words[5][20], int count);
int compareStrings(char str1[], char str2[]);
void swapStrings(char str1[], char str2[]);

int main() {
    char words[5][20];
    int count = 0;

    printf("단어 최대 5개를 입력하세요 (각 단어는 20글자 이내):\n");
    for (int i = 0; i < 5; i++) {
        printf("단어 %d: ", i + 1);
        scanf("%s", words[i]);
        count++;
    }

    sortWords(words, count);

    printf("\n정렬된 단어:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

void sortWords(char words[5][20], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compareStrings(words[j], words[j + 1]) > 0) {
                swapStrings(words[j], words[j + 1]);
            }
        }
    }
}

int compareStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void swapStrings(char str1[], char str2[]) {
    char temp[20];
    int i = 0;
    while (str1[i] != '\0') {
        temp[i] = str1[i];
        i++;
    }
    temp[i] = '\0';

    i = 0;
    while (str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';

    i = 0;
    while (temp[i] != '\0') {
        str2[i] = temp[i];
        i++;
    }
    str2[i] = '\0';
}
