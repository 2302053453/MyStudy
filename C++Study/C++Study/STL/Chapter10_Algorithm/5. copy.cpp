//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<list>
//
//using namespace std;
//
///*
//	2016-03-18
//	copy ����
//	�����̳ʿ� ������ �Ͱ� ���� �ڷ����� �����ϴ� 
//	�ٸ� �����̳ʿ� �����ϰ� ���� �� ���
//	�����Ҷ� A�� B�� copy�� �� B�� �ּ��� A��ŭ�� ũ�⸦ 
//	Ȯ���ϰ� �־�� �Ѵ�.
//	-> copy�� �� �� �̸� ������ ������ �ξ�� �Ѵ�.
//*/
//
//int main()
//{
//	vector<int> vec1(10);
//	// copy�� �� �� �ֵ��� �̸� ������ �Ҵ�
//	vector<int> vec2(10);
//	generate(vec1.begin(), vec1.end(), rand);
//
//	cout << "vec1�� ��� �����͸� vec2�� copy" << endl;
//	copy(vec1.begin(), vec1.end(), vec2.begin());
//	int count = vec2.size();
//
//	for (int i = 0; i < count; i++)
//		cout << vec2[i] << endl;
//
//	cout << "vec1�� ��� �����͸� list1�� copy" << endl;
//	// copy�� �� �� �ֵ��� �̸� ������ �Ҵ�
//	list<int> list1(10);
//	copy(vec1.begin(), vec1.end(), list1.begin());
//	for (list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
//		cout << *iter << endl;
//	return 0;
//}