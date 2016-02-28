//#include<stdio.h>
///*
//	2016-02-22
//	1.숫자와문자를 무작위로 입력받는다. > 123abc654ijuyh
//	2.이중에 숫자만 찾아낸다.
//	3.찾아낸 숫자의 합을 구해서 출력한다.
//	4.Ex_ASCII.c 를 활용하여 문제를 해결한다.
//	실행예)
//	정수형데이터입력 : ufhuu78875kkh
//	입력 받은 문자열 ufhuu78875kkh
//	u->문자
//	f->문자
//	h->문자
//	u->문자
//	u->문자
//	7->숫자
//	8->숫자
//	8->숫자
//	7->숫자
//	5->숫자
//	k->문자
//	k->문자
//	h->문자
//	숫자의 합 : 35
//	계속하려면 아무 키나 누르십시오 . . .
//*/
//
//int PrintNumOrChar(char word)
//{
//	// 문자의 ASCII 값을 구한다.
//	int ascii = (int)word;
//
//	// '0' = 48, '9' = 57
//	if(ascii >= 48 && ascii <= 57)
//	{ 
//		printf("%c ->숫자 \n", word);
//		ascii -= '0';
//	}
//	// 이외의 경우
//	else
//	{ 
//		printf("%c ->문자 \n", word);
//		return 0;
//	}
//	return ascii;
//}
//
//int main()
//{
//	// 문자열을 저장할 변수
//	char word[100];
//	// 문자열의 인덱스와 수의 합계를 저장할 변수 선언
//	int idx=0, sum=0;
//
//	printf("정수형데이터입력 : ");
//	scanf("%s", word);
//	printf("입력 받은 문자열 : %s \n", word);
//
//	// 문자열길이의 끝을 구한다
//	while (word[idx] != '\0')
//		idx++;
//
//	for (int i = 0; i < idx; i++)
//	{ 
//		sum += PrintNumOrChar(word[i]);
//	}
//	printf("합계 : %d \n", sum);
//
//	return 0;
//}
//
