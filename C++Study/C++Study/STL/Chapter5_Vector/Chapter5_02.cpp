//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-06
//	vector insert ����
//*/
//
//void main()
//{
//	vector<int> vector1;
//
//	vector1.push_back(20);
//	vector1.push_back(30);
//
//	cout << "���� �׽�Ʈ 1" << endl;
//
//	// ù��° ��ġ�� �����Ѵ�.
//	vector<int>::iterator iterInsertPos = vector1.begin();
//	vector1.insert(iterInsertPos, 100);
//
//	vector<int>::iterator iterEnd = vector1.end();
//	for (vector<int>::iterator iterPos = vector1.begin(); iterPos != iterEnd; iterPos++)
//		cout << "vector 1 : " << *iterPos << endl;
//
//	cout << "���� �׽�Ʈ 2" << endl;
//
//	// �� ��° ��ġ�� 200�� 2�� �����Ѵ�.
//	iterInsertPos = vector1.begin();
//	++iterInsertPos;
//	vector1.insert(iterInsertPos, 2, 200);
//
//	iterEnd = vector1.end();
//	for (vector<int>::iterator iterPos = vector1.begin(); iterPos != iterEnd; iterPos++)
//		cout << "vector 1 : " << *iterPos << endl;
//
//	cout << "���� �׽�Ʈ 3" << endl;
//	vector<int> vector2;
//	vector2.push_back(1000);
//	vector2.push_back(2000);
//	vector2.push_back(3000);
//
//	// �� ��° ��ġ�� vector2�� ��� �����͸� �����Ѵ�.
//	iterInsertPos = vector1.begin();
//	
//	vector1.insert(++iterInsertPos, vector2.begin(), vector2.end());
//	iterEnd = vector1.end();
//	for (vector<int>::iterator iterPos = vector1.begin(); iterPos != iterEnd; iterPos++)
//		cout << "vector 1 : " << *iterPos << endl;
//}