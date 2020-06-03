#include<stdio.h>


/*한 학급은 4명의 학생
, 각 학생들은 3개의 시험
  시험별 최고점수,평균과
  학생별 최고점수,평균 구하기
  4명의 학생, 3개의 시험 2차원배열로 입력
*/



//시험별 최고점수와 평균점수 출력하기
void term(int stu[][3], int size);

//학생별 최고점수와 평균점수 출력하기
void student(int stu[][3], int size);

int main(void) {

    int stu[4][3]; //4명의 학생, 한학생당 총 3번의 시험
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("학생 %d의 %d번째 시험 성적: ", i + 1, j + 1);
            scanf_s("%d", &stu[i][j]);
        }
    }
    printf("\n<시험별 통계>\n");
    term(stu, 4);

    printf("\n\n<학생별 통계>\n");
    student(stu, 4);

    return 0;
}



//시험별 최고점수와 평균점수 출력하기
void term(int stu[][3], int size) {
    int max, sum, i, j;
    float average;

    for (i = 0; i < sizeof(stu[0]) / sizeof(int); i++) {
        max = 0;
        average = 0;
        sum = 0;
        for (j = 0; j < size; j++) {
            if (max < stu[j][i]) {
                max = stu[j][i];
            }
            sum += stu[j][i];
        }
        printf("\n%d번째 시험을 치른 모든 학생들 중 최고 점수 = %d", i + 1, max);
        average = sum / 4.0f;
        printf("\n%d번째시험을 치른 모든 학생들에 대한 평균 점수 = %.6f\n", i + 1, average);
    }
}

//학생별 최고점수와 평균점수 출력하기
void student(int stu[][3], int size) {
    int max, sum, i, j;
    float average;


    for (i = 0; i < size; i++) {
        max = 0;
        average = 0;
        sum = 0;
        for (j = 0; j < sizeof(stu[0]) / sizeof(int); j++) {
            if (max < stu[i][j]) {
                max = stu[i][j];
            }
            sum += stu[i][j];
        }
        printf("\n%d번째 학생의 최고 점수 = %d", i + 1, max);
        average = sum / 3.0f;
        printf("\n%d번째 학생의 평균 점수 = %.6f\n", i + 1, average);
    }
}