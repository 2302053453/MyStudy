//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<list>
//
//using namespace std;
//
///*
//	2016-03-18
//	remove ����
//	�����̳ʿ� �ִ� Ư������ �����Ѵ�
//	�� �����̳��� ũ��� ������ �ʴ´�.
//	������ �����ϸ� ���� ����� �ƴ� �����͸� ������ �Űܳ���
//	��������ġ(end()�� �ƴ� ���� �� �� ������ �𸥵����͸� ���� ������ ��ġ) �ݺ��ڸ� ��ȯ�Ѵ�.
//	������ ��¥ �����Ϸ��� erase��()�� ����ؾ� �Ѵ�.
//*/
//
//int main()
//{
//	vector<int> vec1;
//	vec1.push_back(10); 
//	vec1.push_back(20);
//	vec1.push_back(20);
//	vec1.push_back(40);
//	vec1.push_back(50);
//	vec1.push_back(30);
//
//	vector<int>::iterator iter;
//	cout << "vec1�� �ִ� ��� ������ ��� " << endl;
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "vec1���� 20 remove  " << endl;
//	vector<int>::iterator removeIter = remove(vec1.begin(), vec1.end(), 20);
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "vec1���� 20 remove ���� ������� �ʴ� ���� ���� ���� " << endl;
//	while (removeIter != vec1.end())
//		removeIter = vec1.erase(removeIter);
//
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	return 0;
//
//}