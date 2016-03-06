//#include<stdio.h>
///*
//	문제(Qu11-03.c)
//	하나의 영단어를 입력받아서 길이를 계산하여 출력하라. morning라고 입력하면 7이 출력되야한다.
//*/
//
//int main()
//{
//	// 영단어 저장을 위해 크기를 여유롭게 선언
//	char word[100];
//	
//	printf("영단어 입력 : ");
//	scanf("%s", word);
//	
//	for (int i = 0; i < sizeof(word); i++)
//	{
//		// 문자열의 마지막 문자 : '\n'
//		if (word[i] == '\0')
//		{
//			printf("%s의 길이 : %d \n", word, i);
//			break;
//		}		
//	}
//	
//	return 0;
//}