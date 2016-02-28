//#include<stdio.h>
///*
//2016-02-26
//문제4
//회문(Palindrome)은 앞 or 뒤에서 읽어도 동일한 단어를 뜻한다.
//noon, level 과 같은 단어들이 회문에 속한다.
//사용자로부터 문자열을 입력받은후 회문인지 아닌지 판단하는 프로그램을 작성하시오.
//대소문자까지 동일해야 회문으로 인정함.
//출력예시)
//단어를 입력하시오. : noon
//회문입니다.
//단어를 입력하시오. : love
//회문이 아닙니다.
//*/
//
//enum BOOL { FALSE = 0, TRUE = 1};
//void main()
//{
//	char wordArr[100];
//
//	int length=0,isPalindrome=1;
//
//	printf("단어를 입력하시오 : ");
//	scanf("%s", wordArr);
//
//	// 단어의 길이를 찾는다
//	while (wordArr[length] != '\0')
//		length++;
//
//	// 단어의 처음과 끝을비교 -> 그 다음 2번째 글자와 끝에서 2번째와 비교 ......
//	for (int i = 0; i < (length / 2); i++)
//		if (wordArr[i] != wordArr[length-(i+1)])
//		{
//			isPalindrome = FALSE;
//			break;
//		}
//
//	printf(isPalindrome == TRUE ? "회문입니다\n" : "회문이 아닙니다\n");
//}