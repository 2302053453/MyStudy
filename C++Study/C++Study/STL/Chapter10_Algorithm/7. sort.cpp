//#include<vector>
//#include<iostream>
//#include<algorithm>
//#include<functional>
//
//using namespace std;
//
///*
//	2016-03-18
//	sort ����
//	�⺻������ ������������ ���ĵǸ�
//	������������ �����Ϸ���  �⺻���� ��� greater<>()�� less
//	�⺻���� �ƴϸ� ���� �������ڸ� �������ϸ�
//	���� ������ ������ �����̳ʿ����� ����� �����ϴ�.
//*/
//
//int main()
//{
//	vector<int> vec1(10);
//	generate(vec1.begin(), vec1.end(), rand);
//
//	vector<int>::iterator iter;
//
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "�������� ����" << endl;
//	sort(vec1.begin(), vec1.end());
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "�������� ����" << endl;
//	sort(vec1.begin(), vec1.end(), greater<int>());
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "�Ϻθ� �������� ����" << endl;
//	sort(vec1.begin()+3, vec1.end());
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	return 0;
//}