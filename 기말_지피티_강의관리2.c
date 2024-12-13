#include <stdio.h>
#include <string.h>

#define MAX_LECTURES 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int startTime; // 24시간 형식 예: 1300 = 1:00 PM
} Lecture;

void addLecture(Lecture lectures[], int *count, const char *name, int startTime);
void deleteLecture(Lecture lectures[], int *count, const char *name);
void sortLectures(Lecture lectures[], int count);
void printLectures(Lecture lectures[], int count);

int main() {
    Lecture lectures[MAX_LECTURES] = {{"Math", 900}, {"English", 1400}};
    int lectureCount = 2;

    // 초기 강의 출력
    printf("현재 강의 목록:\n");
    printLectures(lectures, lectureCount);

    // 강의 추가
    addLecture(lectures, &lectureCount, "Physics", 1100);
    printf("강의 추가 후 목록:\n");
    printLectures(lectures, lectureCount);

    // 강의 삭제
    deleteLecture(lectures, &lectureCount, "Math");
    printf("강의 삭제 후 목록:\n");
    printLectures(lectures, lectureCount);

    // 강의 정렬
    sortLectures(lectures, lectureCount);
    printf("정렬된 강의 목록:\n");
    printLectures(lectures, lectureCount);

    return 0;
}

void addLecture(Lecture lectures[], int *count, const char *name, int startTime) {
    if (*count < MAX_LECTURES) {
        strcpy(lectures[*count].name, name);
        lectures[*count].startTime = startTime;
        (*count)++;
    } else {
        printf("더 이상 강의를 추가할 수 없습니다.\n");
    }
}

void deleteLecture(Lecture lectures[], int *count, const char *name) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(lectures[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                lectures[j] = lectures[j + 1];
            }
            (*count)--;
            return;
        }
    }
    printf("삭제할 강의를 찾을 수 없습니다.\n");
}

void sortLectures(Lecture lectures[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (lectures[j].startTime > lectures[j + 1].startTime) {
                Lecture temp = lectures[j];
                lectures[j] = lectures[j + 1];
                lectures[j + 1] = temp;
            }
        }
    }
}

void printLectures(Lecture lectures[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s (%d)\n", lectures[i].name, lectures[i].startTime);
    }
}
