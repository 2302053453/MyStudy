//#include<iostream>
//#include<functional>
//#include<set>
//using namespace std;
///*
//	2016-03-18
//	set -> find�� ã�� key ����? -> find()�� ��� ��ȯ�ڰ� const���̹Ƿ� ���� �Ұ�!
//*/
//
//int main()
//{
//	set<int> set1;
//	set1.insert(10);
//	set1.insert(15);
//	set1.insert(12);
//	set1.insert(2);
//	set1.insert(100);
//
//	for (set<int>::iterator iter = set1.begin(); iter != set1.end(); ++iter)
//		cout << *iter << endl;
//
//	set<int>::iterator iter = set1.find(15);
//	if (iter != set1.end())
//		cout << "�˻���� : " << *iter << endl;
//
//	return 0;
//}