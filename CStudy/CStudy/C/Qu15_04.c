//#include<stdio.h>
///*
//2016-02-26
//����4
//ȸ��(Palindrome)�� �� or �ڿ��� �о ������ �ܾ ���Ѵ�.
//noon, level �� ���� �ܾ���� ȸ���� ���Ѵ�.
//����ڷκ��� ���ڿ��� �Է¹����� ȸ������ �ƴ��� �Ǵ��ϴ� ���α׷��� �ۼ��Ͻÿ�.
//��ҹ��ڱ��� �����ؾ� ȸ������ ������.
//��¿���)
//�ܾ �Է��Ͻÿ�. : noon
//ȸ���Դϴ�.
//�ܾ �Է��Ͻÿ�. : love
//ȸ���� �ƴմϴ�.
//*/
//
//enum BOOL { FALSE = 0, TRUE = 1};
//void main()
//{
//	char wordArr[100];
//
//	int length=0,isPalindrome=1;
//
//	printf("�ܾ �Է��Ͻÿ� : ");
//	scanf("%s", wordArr);
//
//	// �ܾ��� ���̸� ã�´�
//	while (wordArr[length] != '\0')
//		length++;
//
//	// �ܾ��� ó���� ������ -> �� ���� 2��° ���ڿ� ������ 2��°�� �� ......
//	for (int i = 0; i < (length / 2); i++)
//		if (wordArr[i] != wordArr[length-(i+1)])
//		{
//			isPalindrome = FALSE;
//			break;
//		}
//
//	printf(isPalindrome == TRUE ? "ȸ���Դϴ�\n" : "ȸ���� �ƴմϴ�\n");
//}