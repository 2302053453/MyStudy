//#include<stdio.h>
///*
//	2016-02-22
//	문제(Qu11-05.c)
//	10자 이하인 영단어를 입력받아 아스키 코드값이 가장 큰 문자를 출력하라.
//	LOVE를 입력했다면 V가 출력되어야 한다.
//*/
//
//int main()
//{
//	// 영단어 저장을 위해 크기를 여유롭게 선언, max는 ASCII 값중 제일 작은 값으로 초기화
//	char word[100], max='0';
//
//	int length;
//
//	printf("영단어 입력 : ");
//	scanf("%s", word);
//
//	// 문자열의 마지막 인덱스를 구한다.
//	for (int i = 0; i < sizeof(word); i++)
//	{
//		// 문자열의 마지막 문자 : '\n'
//		if (word[i] == '\0')
//		{
//			length = i - 1;
//			break;
//		}
//	}
//	
//	printf("문자열 : %s, 제일큰 글자 : ", word);
//	for (int i = length; i >= 0; i--)
//		// 각 글자를 비교하여 제일 큰 값을 저장
//		max = (int)max >= (int)word[i] ? max : word[i];
//
//	printf("%c \n", max);
//
//	return 0;
//}