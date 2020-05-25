#include <stdio.h>
#include <string.h>


void sumPrint(int data[][4], int row, int col) {
	// 함수 내부에서 실매개변수로 전달되는 배열 크기 알 수 없음
	// 따라서, 크기를 인자로 받는다

	// 원래크기 3*4*(int 4) = 48 이지만 int 4로 출력 
	printf("[%d]  \n\n", sizeof(data)); 
	
	int su = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("[%d]  ", data[i][j]);
			su += data[i][j];
		}
	}
	printf("\nsum = %d\n", su);
}

int main() {

	int data[][4] = { {1,2,3,4},{5,6,7,8}, {9,10,11,12} };
	int row = sizeof(data) / sizeof(data[0]);
	int col = sizeof(data[0]) / sizeof(data[0][0]);

	sumPrint(data,row,col);
	return 0;
}