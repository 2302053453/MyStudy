//#include<stdio.h>
///*
//	2016-02-18
//	switch 예제 프로그램
//*/
//
//int main(void)
//{
//	char sel;
//	printf("M 오전, A 오후, E 저녁 \n");
//	printf("입력 : ");
//	// 문자를 입력받는다
//	scanf("%c", &sel);
//
//	switch (sel)
//	{
//		// case 'a': 후에 break 없이 case가 이어지면 or 조건으로 본다. 
//		// 지금같은 경우는 if(sel =='M' || sel =='m')과 동일하다.
//		case 'M':
//		case 'm':
//			printf("Morning \n");
//			break;
//		case 'A':
//		case 'a':
//			printf("Afternoon \n");
//			break;
//		case 'E':
//		case 'e':
//			printf("Evening \n");
//			break;
//	}
//
//	return 0;
//}