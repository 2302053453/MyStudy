//#include<stdio.h>
///*
//	����6(Qu07-06.c)
//	����ڷκ��� 2���� ������ �Է¹޴´�. ���� 2�� 6�� �Է¹޾Ҵٸ�
//	2+3+4+5+6�� ���ϴ� ���α׷��� �ۼ��϶�.
//	�� 6�� 2�� �Է¹޴´ٸ� 6+5+4+3+2�� ���ؾ� �Ѵ�.
//*/
//
//int main(void)
//{
//	int startNum, endNum, num, sum=0;
//	
//	char sign = '+';
//
//	// ������� üũ�� ����
//	int isEnd = 0;
//
//	printf("���� ���۰� : ");
//	scanf("%d", &startNum);
//	
//	printf("���� �������� : ");
//	scanf("%d", &endNum);
//
//	// num�� ���۰� : startNum
//	num = startNum;
//
//	while (isEnd == 0)
//	{
//		// ���ڸ� �հ迡 ���Ѵ�
//		sum += num;
//		printf("%d",num);
//
//		// ���Ѽ��ڰ� endNum�� ���� - ����
//		isEnd = num == endNum ? 1 : 0;
//		
//		// ���ۼ��ڰ� ũ�� endNum���� ����, ������ ������Ų��.
//		startNum > endNum ? num-- : num++;
//		
//		// ������ ������ ���� ���б�ȣ ����
//		sign = isEnd == 1 ? '=' : '+';
//		
//		printf("%c",sign);
//	}
//
//	printf("%d \n", sum);
//
//	return 0;
//}