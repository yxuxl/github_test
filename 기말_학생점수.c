#include <stdio.h>

typedef struct {
    char name[30];
    int scores[3]; // [국어, 영어, 수학]
    float average;
} Student;

void calculateAverages(Student students[], int count);
int findTopStudent(Student students[], int count);

int main() {
    Student students[5] = {
        {"Kim Minsoo", {90, 80, 85}, 0},
        {"Park Jiwon", {95, 70, 75}, 0},
        {"Lee Hana", {60, 85, 90}, 0},
        {"Choi Youngho", {85, 95, 80}, 0},
        {"Jung Seoyeon", {75, 65, 70}, 0}
    };

    calculateAverages(students, 5);
    int topStudentIndex = findTopStudent(students, 5);

    printf("모든 과목 평균 점수가 가장 높은 학생:\n");
    printf("이름: %s, 평균 점수: %.2f\n", students[topStudentIndex].name, students[topStudentIndex].average);

    return 0;
}

void calculateAverages(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        int total = 0;
        for (int j = 0; j < 3; j++) {
            total += students[i].scores[j];
        }
        students[i].average = total / 3.0;
    }
}

int findTopStudent(Student students[], int count) {
    int topIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].average > students[topIndex].average) {
            topIndex = i;
        }
    }
    return topIndex;
}
