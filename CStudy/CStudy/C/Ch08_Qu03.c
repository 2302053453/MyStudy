//#include<stdio.h>
///*
//	����3(Qu08-03.c)
//	�л��� ��ü ��������� ���� ������ ����ϴ� ���α׷��� �ۼ��϶�.
//	����� ����, ����, ������ ������ ���ʷ� �Է¹����� ����� ���� ��
//	90���̻� A, 80���̻� B, 70���̻� C, 50���̻� D, �� �̸��̸� F�� ����Ѵ�.
//*/
//
//int main(void)
//{
//	int korScore, engScore, mathScore,average;
//
//	printf("�������� : ");
//	scanf("%d", &korScore);
//	printf("�������� : ");
//	scanf("%d", &engScore);
//	printf("�������� : ");
//	scanf("%d", &mathScore);
//
//	// �� �Ҽ������� ����ó��
//	average = ( korScore + engScore + mathScore ) / 3;
//
//	// average ���� 10���� ���� ������ �Ǻ�
//	switch ((average / 10))
//	{
//		// 90�̻� =  9 or 10
//		case 9:
//		case 10:
//			printf("��� : %d \n��� : A\n", average);
//			break;
//		case 8:
//			printf("��� : %d \n��� : B\n", average);
//			break;
//		case 7:
//			printf("��� : %d \n��� : C\n", average);
//			break;
//		// 50���̻� 70�̸� = 5 or 6
//		case 6:
//		case 5:
//			printf("��� : %d \n��� : D\n", average);
//			break;
//		// �� �̿��� ��� = 50�̸�
//		default:
//			printf("��� : %d \n��� : F\n", average);
//			break;
//	}
//	return 0;
//
//}