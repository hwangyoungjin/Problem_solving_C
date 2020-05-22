#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*N개의 정수를 입력받는다
1. 입력한 정수 배열에 저장 후 거꾸로 출력
2. 입력된 정수들을 앞에서 부터 3개 씩 묶어서 그중 가장 큰 수, 작은 수 새로 배열에 저장하고 출력
3. n개의 수 중 가장 큰 수, 가장 작은 수 가 남을때까지 2단계를 반복

ex. input
	10
	1 2 3 4 5 6 7 8 9 
	ouput
	□ 10 9 8 7 6 5 4 3 2 1
	□ 3  6  9  10
	□ 1  4  7  10
	□ 3 10
	□ 1 10
	□ 10
	□ 1
	*/

int main() {

/*n개 정수 입력 받아서 배열의 저장한후 거꾸로 출력*/
	int n;
	int arr[20];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		int su;
		scanf_s("%d", &su);
		arr[i] = su;
	}
	printf("\n\n□");
	for (int i = n-1; i>=0; i--) {
		printf("  %d",arr[i]);
	}

	/*입력된 정수 앞에서 3개씩 묶어서*/
	/*그 중 가장 큰 수,작은수를 차례로 배열에 저장*/
	int arrMax[20];
	int arrMin[20];
	int max=0,min=0;
	
	int idx = -1; // arrMax와 arrMin의 index
	for (int i = 0; i < n; i++) {
		
		if (i % 3 == 0) {
			min = arr[i];
			max = arr[i];
			idx++;
		}
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
		if (i % 3 == 2 ) {
			arrMax[idx] = max;
			arrMin[idx] = min;
		}
	}
	if (n % 3 != 0) { //n 은 3의 배수 x
		arrMax[idx] = max;
		arrMin[idx] = min;
	}

	/*arrMax 출력*/
	printf("\n□");
	for (int i = 0; i <=idx; i++) {
		printf("  %d", arrMax[i]);
	}
	/*arrMin 출력*/
	printf("\n□");
	for (int i = 0; i <=idx; i++) {
		printf("  %d", arrMin[i]);
	}


	/*반복*/

	int maxarrMax = 0;
	int minarrMin = 0;
	

	n = idx+1; // data 개수 init
	int arrMax2[20]; // 새로 구할 maxArray
	int arrMin2[20]; // 새로 구할 minArray
	while (n != 1) {

		idx = -1;
		for (int i = 0; i < n; i++) {

			if (i % 3 == 0) {
				maxarrMax = arrMax[i];
				minarrMin = arrMin[i];
				idx++;
			}
			if (arrMax[i] > maxarrMax) {
				maxarrMax = arrMax[i];
			}
			if (arrMin[i] < minarrMin) {
				minarrMin = arrMin[i];
			}
			if (i % 3 == 2) {
				arrMax2[idx] = maxarrMax;
				arrMin2[idx] = minarrMin;
			}
		}

		if (n % 3 != 0) { //n 은 3의 배수 x
			arrMax2[idx] = maxarrMax;
			arrMin2[idx] = minarrMin;
		}
		/*arrMax 출력*/
		printf("\n□");
		for (int i = 0; i <= idx; i++) {
			printf("  %d", arrMax2[i]);
		}
		/*arrMin 출력*/
		printf("\n□");
		for (int i = 0; i <= idx; i++) {
			printf("  %d", arrMin2[i]);
		}

		n = idx+1;
		memmove(arrMax, arrMax2, sizeof(int)* n);
		memmove(arrMin, arrMin2, sizeof(int)* n);
	}

	printf("\n\n");
	return 0;
}