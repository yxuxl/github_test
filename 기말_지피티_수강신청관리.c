#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 5
#define MAX_STUDENTS 3
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int studentID;
    char subjects[MAX_SUBJECTS][MAX_NAME_LENGTH];
    int subjectCount;
} Student;

void addSubject(Student *student, const char *subject);
int isEnrolledInSubject(Student *student, const char *subject);

int main() {
    Student students[MAX_STUDENTS] = {
        {"Kim Minsoo", 20231001, {{"Math"}, {"English"}}, 2},
        {"Park Jiwon", 20231002, {{"Physics"}}, 1},
        {"Lee Hana", 20231003, {{"Chemistry"}, {"Biology"}}, 2}
    };

    char subjectToAdd[MAX_NAME_LENGTH];
    char subjectToCheck[MAX_NAME_LENGTH];

    // 학생 1의 새로운 과목 추가
    printf("추가할 과목 입력: ");
    scanf("%s", subjectToAdd);
    addSubject(&students[0], subjectToAdd);

    // 학생 1의 수강 여부 확인
    printf("수강 여부 확인할 과목 입력: ");
    scanf("%s", subjectToCheck);
    if (isEnrolledInSubject(&students[0], subjectToCheck)) {
        printf("%s는 %s 수업을 듣고 있습니다.\n", students[0].name, subjectToCheck);
    } else {
        printf("%s는 %s 수업을 듣고 있지 않습니다.\n", students[0].name, subjectToCheck);
    }

    return 0;
}

void addSubject(Student *student, const char *subject) {
    if (student->subjectCount < MAX_SUBJECTS) {
        strcpy(student->subjects[student->subjectCount], subject);
        student->subjectCount++;
        printf("%s 과목이 추가되었습니다.\n", subject);
    } else {
        printf("수강 가능한 과목을 초과했습니다.\n");
    }
}

int isEnrolledInSubject(Student *student, const char *subject) {
    for (int i = 0; i < student->subjectCount; i++) {
        if (strcmp(student->subjects[i], subject) == 0) {
            return 1;
        }
    }
    return 0;
}
