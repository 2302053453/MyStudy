//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-06
//	vector assign ����
//	1. Ư������ n��ŭ ä���
//	2. Ư�� ������ ���� Ư�� ������ ������ ä���
//*/
//
//void main()
//{
//	vector<int> vector1;
//	
//	// 4�� 7�� ä���
//	// 
//	vector1.assign(7, 4);
//	int count = vector1.size();
//
//	for (int i = 0; i < count; i++)
//		cout << "vector1 : " << vector1[i] << endl;
//
//	vector<int> vector2;
//	vector2.push_back(10);
//	vector2.push_back(20);
//	vector2.push_back(30);
//
//	// vector2�� ��ҷ� ä���
//	vector1.assign(vector2.begin(), vector2.end());
//
//	count = vector1.size();
//
//	for (int i = 0; i < count; i++)
//		cout << "vector1 : " << vector1[i] << endl;
//}