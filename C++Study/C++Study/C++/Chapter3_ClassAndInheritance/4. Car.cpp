//#include"4. Car.h"
//#include<iostream>
//#include<cstring>
//using namespace std;
//
///*
//	2016-03-16
//	Class 파일분할 예쩨
//*/
//
//// 현재 상태를 출력한다.
//void Car::ShowCarState()
//{
//	cout << "소유자ID : " << gamerID << endl;
//	cout << "연료량 : " << fuelGauge << endl;
//	cout << "현재속도 : " << curSpeed << endl;
//}
//
//// 속도증가
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
//// 속도감소
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