//#include<stdio.h>
///*
//	2016-02-24
//	����5
//	�ʸ� �Է¹޾Ƽ� 00�ð� 00�� 00�� ���·� ����ϴ� ���α׷���
//	�Լ��� �̿��Ͽ� �ۼ��϶�
//	��¿� : 2458�� -> 0�ð� 41�� 25��
//	3456�� -> 0�ð� 57�� 36��
//*/
//
//int ConvertSecondToTime(int time)
//{
//	// �ð� : 3600��
//	int hour = time / 3600;
//	// �� : �ʸ� 60���� ������ 60���� �������� ���Ѵ�(1~59��)
//	int minite = (time / 60)%60;
//	// �� : �ð��� ���� ���� ������
//	int second = (time % 60) % 60;
//	printf("%d�� -> %d�ð� %d�� %d��\n", time, hour, minite, second);
//}
//void main()
//{
//	int second;
//	printf("�ʸ� �Է��ϼ��� : ");
//	scanf("%d", &second);
//	ConvertSecondToTime(second);
//}