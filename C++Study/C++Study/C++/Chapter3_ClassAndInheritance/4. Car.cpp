//#include"4. Car.h"
//#include<iostream>
//#include<cstring>
//using namespace std;
//
///*
//	2016-03-16
//	Class ���Ϻ��� ����
//*/
//
//// ���� ���¸� ����Ѵ�.
//void Car::ShowCarState()
//{
//	cout << "������ID : " << gamerID << endl;
//	cout << "���ᷮ : " << fuelGauge << endl;
//	cout << "����ӵ� : " << curSpeed << endl;
//}
//
//// �ӵ�����
//void Car::Accel()
//{
//	if (fuelGauge <= 0)
//		return;
//	else
//		fuelGauge -= FUEL_STEP;
//
//	if (curSpeed + ACC_STEP >= MAX_SPD)
//	{
//		curSpeed = MAX_SPD;
//		return;
//	}
//
//	curSpeed += ACC_STEP;
//}
//
//// �ӵ�����
//void Car::Break()
//{
//	if (curSpeed < BRK_STEP)
//	{
//		curSpeed = 0;
//		return;
//	}
//
//	curSpeed -= BRK_STEP;
//}
//
//void Car::InitMembers(char* ID, int fuel)
//{
//	strcpy(gamerID, ID);
//	fuelGauge = fuel;
//	curSpeed = 0;
//}