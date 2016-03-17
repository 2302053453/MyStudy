//#include<iostream>
//using namespace std;
///*
//	2016-03-16
//	����ü(struct) ����
//
//	C++������ �⺻ �ڷ��� ������ �������̳� ����ü�� ������� ���ǵ� �ڷ����� ���� �����Ŀ� ���̰� ����.
//	C++������ ������ typedef ���� ���̵� ����ü ������ ������ �� �ִ�.
//	: struct Car basicCar;
//	: Car basicCar;
//
//	���� �Լ����� ����ü Car�� �������� �Լ����̴�. �׷����� �ұ��ϰ� �����Լ��� ���¸� ��� ������,
//	�� �Լ����� ����ü Car�� ���������� ��Ÿ���� ���ϰ� �ִ� ��Ȳ�̴�.
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
//};
//
//void ShowCarState(const Car & car)
//{
//	cout << "������ID : " << car.gamerID << endl;
//	cout << "���ᷮ : " << car.fuelGauge << endl;
//	cout << "����ӵ� : " << car.curSpeed << endl;
//}
//
//void Accel(Car & car)
//{
//	if (car.fuelGauge <= 0)
//		return;
//	else
//		car.fuelGauge -= FUEL_STEP;
//
//	if (car.curSpeed + ACC_STEP >= MAX_SPD)
//	{
//		car.curSpeed = MAX_SPD;
//		return;
//	}
//
//	car.curSpeed += ACC_STEP;
//}
//
//void Break(Car &car)
//{
//	if (car.curSpeed < BRK_STEP)
//	{
//		car.curSpeed = 0;
//		return;
//	}
//
//	car.curSpeed -= BRK_STEP;
//}
//
//int main()
//{
//	cout << "Exam01 : " << endl;
//
//	Car run99 = { "run99",100,0 };
//	Accel(run99);
//	Accel(run99);
//	ShowCarState(run99);
//	Break(run99);
//	ShowCarState(run99);
//
//	Car run77 = { "run77",100,0 };
//	Accel(run77);
//	Break(run77);
//	ShowCarState(run77);
//
//	return 0;
//}