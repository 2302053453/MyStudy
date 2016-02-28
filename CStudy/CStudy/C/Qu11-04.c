//#include<stdio.h>
///*
//	2016-02-22
//	문제(Qu11-04.c)
//	영단어를 char형 배열에 저장한다. 그 다음 영단어를 역순으로 뒤집는다.
//	그리고 입력했던 단어와 뒤집어진 단어를 출력한다.
//*/
//
//int main()
//{
//	// 영단어 저장을 위해 크기를 여유롭게 선언
//	char word[100];
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
//			length = i-1;
//			break;
//		}
//	}
//	// 역순으로 한 글자씩 출력
//	printf("문자열 : %s, 역순 : ", word);
//	for (int i = length; i >= 0; i--)
//		printf("%c", word[i]);
//
//	printf("\n");
//
//	return 0;
//}