//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-06
//	vector erase ����
//	1. ������ ������ ����
//	2. ������ ������ ������ ����
//*/
//
//void main()
//{
//	vector<int> vector1;
//
//	vector1.push_back(10);
//	vector1.push_back(20);
//	vector1.push_back(30);
//	vector1.push_back(40);
//	vector1.push_back(50);
//
//
//	int count = vector1.size();
//	for (int i = 0; i < count; i++)
//		cout << "vector 1 : " << vector1[i] << endl;
//	cout << endl;
//
//	cout << "erase �׽�Ʈ 1" << endl;
//
//	// ù ��° ������ ����
//	vector1.erase(vector1.begin());
//
//	count = vector1.size();
//	for (int i = 0; i < count; i++)
//		cout << "vector 1 : " << vector1[i] << endl;
//	cout << endl;
//
//	cout << "erase �׽�Ʈ 2" << endl;
//
//	// ������ ������ ������ ����
//	vector<int>::iterator iterInsertPos = vector1.begin();
//	vector1.erase(iterInsertPos, vector1.end());
//
//	if (vector1.empty())
//		cout << "vector1�� �ƹ� �͵� �����ϴ�" << endl;
//}