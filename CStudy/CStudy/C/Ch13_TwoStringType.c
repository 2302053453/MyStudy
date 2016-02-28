//#include<stdio.h>
///*
//	2016-02-23
//	문자열 관련 포인터 예제
//*/
//
//int main(void)
//{
//	char str[] = "MY String";
//	// 포인터로 문자열지정 -> 배열처럼 되는 것이 아닌 전체문자열상수를 가리킨다.
//	char * str2 = "Your String";
//
//	// 가리키는 대상 변경
//	str2 = "Our String";
//
//	printf("%s %s \n", str, str2);
//
//	str[0] = 'X'; // 문자열 변경 성공
//	str2[0] = 'X'; // 믄자열 변경 실패(배열이 아니므로 이러한 방식으론 접근불가)
//
//	printf("%s %s \n", str, str2);
//
//	return 0;
//
//}