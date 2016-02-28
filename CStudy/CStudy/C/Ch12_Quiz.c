//#include<stdio.h>
///*
//	2016-02-22
//	CH12.포인터
//
//	문제1(Qu12-01.c) : 출력의 결과도 예상해보자
//	int main(void)
//	{
//	int num = 10;
//	int * ptr1 = &num;
//	int * ptr2 = ptr1;
//
//	(*ptr1)++;
//	(*ptr2)++;
//	printf("%d \n", num);
//	return 0;
//	}
//	해답 : 12
//	이유 : (*ptr1) = num, ptr1 = ptr2, 즉 (*ptr1) = (*ptr2)
//
//	문제2(Qu12-02.c) : int형 변수 num1과 num2를 선언과 동시에 각각 10과 20으로 초기화하고,
//	int형 포인터 변수 ptr1, ptr2 를 선언하여 num1, num2를 가리키게 하자.
//	ptr1, ptr2를 이용해서 num1 10증가, num2 10감소후 출력...
//	ptr1, ptr2가 가리키는 대상을 서로 바꾼후 15증가시킨다.
//	그리고 ptr1, ptr2가 가리키는 변수에 저장된 값을 출력...
//*/
//int main()
//{
//	int num1=10, num2 = 20;
//	int * ptr1 = &num1;
//	int * ptr2 = &num2;
//
//	(*ptr1)+=10;
//	(*ptr2)-=10;
//	printf("num1 : %d, num2 : %d \n", (*ptr1), (*ptr2));
//
//	// 가리키는 대상을 변경한다.
//	ptr1 = &num2;
//	ptr2 = &num1;
//	
//	ptr1 += 10;
//	(*ptr2) -= 10;
//	printf("num1 : %d, num2 : %d \n", (*ptr1), (*ptr2));
//
//	return 0;
//
//}