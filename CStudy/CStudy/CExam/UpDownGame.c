//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
///*
//	2016-02-19
//	������ ���ٿ����
//*/
//
//int main(void)
//{
//	int maximumChance = 7;
//	int chance;
//	int answer;
//	int num;
//	char retry;
//	srand((int)time(NULL));
//
//	while (1)
//	{
//		// �ܿ���ȸ �ʱ�ȭ
//		chance = 0;
//		// ��ǻ�Ͱ� ���ڸ� ���Ѵ�
//		answer = rand() % 100 + 1;
//		
//		// 7�� �ݺ�
//		while (chance < maximumChance)
//		{
//			printf("������ : ? (���� �õ�Ƚ�� = %dȸ)", maximumChance - chance);
//			scanf("%d", &num);
//
//			// ����� ��
//			if (num < answer)
//			{ 
//				printf("��! ���Դϴ�!\n");
//				chance++;
//			}
//			else if (num > answer)
//			{
//				printf("��! �ٿ��Դϴ�!\n");
//				chance++;
//			}
//			else if (num == answer)
//			{
//				printf("����! ����Ͻó׿�!\n");
//				break;
//			}
//
//			// �ܿ���ȸ���� �Ǻ�
//			if (maximumChance == chance)
//			{
//				printf("�̷�.... �����߼̳׿�...\n������ %d�����ϴ�! ���� ��ȸ��!\n", answer);
//			}
//
//		}
//
//		// �絵������
//		do{ 
//			printf("�ٽ��Ͻðڽ��ϱ�?( ��(y) /�ƴϿ�(n) ) ");
//			scanf(" %c", &retry);
//			if ((int)(retry != 'y') && ((int)retry != 'n') &&
//				(int)(retry != 'Y') && ((int)retry != 'N'))
//				printf("�̻��Ѱ� ���������� ����� �������ּ���!\n");
//			else
//				break;
//		} while (1);
//	
//		if ((int)retry == 'y')
//			continue;
//		else if ((int)retry == 'n')
//			return 0;
//	}	
//}