//#include<iostream>
//using namespace std;
///*
//	2016-03-16
//	����ü(struct) ����(����ü ���ξ� �Լ� ����)
//
//	C++������ ����ü �ȿ� �Լ��� �����ϴ� ���� ���ȴ�.
//	�Լ��� ����ü ���� ���ԵǸ鼭 ����ü ���� ����� ������ ���������� ����������.
//
//	��� ����ü ���� ���� �Լ��� ���� ������ �����ϴ� ��ó�� ������ ���µ�,
//	�����δ� ��� Car ����ü ������ �ϳ��� �Լ��� �����Ѵ�.
//	- �������� ������ ������ �ڽ��� �Լ��� ������ ���ϴ� �Ͱ� ���� ȿ�� �� ����� ���δ�.
//	�Լ� -> ����ü�� �����ɶ��� �ƴ� �̸� �����ȴ�.
//*/
//
//#define ID_LEN	20
//#define MAX_SPD	200
//#define FUEL_STEP 2
//#define ACC_STEP 10
//#define BRK_STEP 10
//
//struct  Car
//{
//	char gamerID[ID_LEN];	// ������ ID
//	int fuelGauge;			// ���ᷮ
//	int curSpeed;			// ����ӵ�
//
//	// �Լ����� ����ü �ȿ� �ִ´�.
//	void ShowCarState()
//	{
//		cout << "������ID : " << gamerID << endl;
//		cout << "���ᷮ : " << fuelGauge << endl;
//		cout << "����ӵ� : " << curSpeed << endl;
//	}
//
//	void Accel()
//	{
//		if (fuelGauge <= 0)
//			return;
//		else
//			fuelGauge -= FUEL_STEP;
//
//		if (curSpeed + ACC_STEP >= MAX_SPD)
//		{
//			curSpeed = MAX_SPD;
//			return;
//		}
//
//		curSpeed += ACC_STEP;
//	}
//
//	void Break()
//	{
//		if (curSpeed < BRK_STEP)
//		{
//			curSpeed = 0;
//			return;
//		}
//
//		curSpeed -= BRK_STEP;
//	}
//};
//
//
//
//int main()
//{
//	cout << "Exam02 : " << endl;
//
//	Car run99 = { "run99",100,0 };
//	run99.Accel();
//	run99.Accel();
//	run99.ShowCarState();
//	run99.Break();
//	run99.ShowCarState();
//
//	Car run77 = { "run77",100,0 };
//	run77.Accel();
//	run77.Break();
//	run77.ShowCarState();
//
//	return 0;
//}