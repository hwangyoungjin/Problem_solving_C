#include <stdio.h>
#include <string.h>

/*strlen 구현과 strtok_s 활용*/

/*strtok 이전버전
int main(void) {
   char str[] = "C 언어는 좀 어렵지만, 재미있는 언어입니다.";
   char* ptoken;
   char* delimiter = " ,."; // " " and , and . 으로 delimiter

   //str을 delimiter 기준으로 분리 후 str에 저장
   ptoken = strtok(str, delimiter);
   while (ptoken != NULL) {
	  printf("%10s ", ptoken);

	  //다음 토큰을 반환
	  //중간에 들어간 null을 시작으로 delimiter까지 분리
	  ptoken = strtok(NULL, delimiter);
   }
   return 0;
}

*/

/*현재 버전*/
int mystrlen(const char*);
int main(void) {
	char str[] = "C 언어는 좀 어렵지만, 재미있는 언어입니다.";
	char* context = NULL; // 분리된 문자열 저장 포인터
	char* ptoken; // 토큰 저장 포인터
	char* delimiter = " ,."; // " " and , and . 으로 delimiter

	/*맨 처음 토큰 저장*/
	//str을 delimiter 기준으로 분리 후 context에 저장, 중간엔 null들어간다.
	ptoken = strtok_s(str, delimiter, &context);

	while (ptoken != NULL) {
		printf("%10s ", ptoken);

		//mystrlen 확인
		printf("%5d %5d\n", mystrlen(ptoken), strlen(ptoken));

		//다음 토큰을 반환
		//중간에 들어간 null을 시작으로 delimiter까지 분리
		ptoken = strtok_s(NULL, delimiter, &context);
	}
	return 0;
}

int mystrlen(const char* s) {
	int idx = 0;
	while (s[idx] != '\0') {
		idx++;
	}
	return idx;
}