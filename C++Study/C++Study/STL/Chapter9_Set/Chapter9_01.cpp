//#include<iostream>
//#include<functional>
//#include<set>
//using namespace std;
///*
//	2016-03-18
//	set ����( insert �� ���)
//	map�� (key, value)�� ���������� set�� key���� �����Ѵ�.
//	����ϸ� ���� ���
//	- �����ؾ� �� ��
//	- key�� �ִ��� ������ �˾ƾ� �� ��
//	- ���� �ڷḦ �����ϰ�, �˻� �ӵ��� ����� �� �� 
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
//	set<int>::iterator iter = set1.begin();
//
//	++iter;
//	set1.insert(iter, 90);
//
//	cout << endl;
//	cout << "90�� �߰� �� ser1�� ��� ��� ���" << endl;
//
//	for (set<int>::iterator iter = set1.begin(); iter != set1.end(); ++iter)
//		cout << *iter << endl;
//
//	return 0;
//}