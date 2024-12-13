#include <stdio.h>

typedef struct {
    char title[50];
    char author[50];
    int year;
} Book;

void addBook(Book books[], int *count);
void searchByAuthor(Book books[], int count);
int compareStrings(char str1[], char str2[]);
void printBooks(Book books[], int count);

int main() {
    Book books[10];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n1. 책 추가\n2. 저자로 검색\n3. 종료\n선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addBook(books, &bookCount);
        } else if (choice == 2) {
            searchByAuthor(books, bookCount);
        } else if (choice == 3) {
            break;
        } else {
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}

void addBook(Book books[], int *count) {
    if (*count >= 10) {
        printf("책 목록이 가득 찼습니다.\n");
        return;
    }

    printf("책 제목: ");
    scanf(" %[^\n]s", books[*count].title); // 개행 문자 제외 입력
    printf("저자: ");
    scanf(" %[^\n]s", books[*count].author);
    printf("출판 연도: ");
    scanf("%d", &books[*count].year);

    (*count)++;
}

void searchByAuthor(Book books[], int count) {
    char searchAuthor[50];
    int found = 0;

    printf("검색할 저자 이름: ");
    scanf(" %[^\n]s", searchAuthor);

    for (int i = 0; i < count; i++) {
        if (compareStrings(books[i].author, searchAuthor) == 0) {
            printf("\n책 제목: %s\n저자: %s\n출판 연도: %d\n", books[i].title, books[i].author, books[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("해당 저자의 책을 찾을 수 없습니다.\n");
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
