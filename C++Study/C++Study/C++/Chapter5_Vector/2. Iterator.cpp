//#include<iostream>
//#include<vector>
//using namespace std;
///*
//2016-03-17
//Vector ����
//
//vector Ŭ������ �޸𸮰� ������ ��쿡 �ڵ����� �޸𸮸� Ȯ��
//�׷��Ƿ� �迭���� �ٸ��� ����� �Ű��� �� �ʿ䰡 ����.
//
//C++���� ���ø� Ŭ������ ����ϴ� ǥ�� ���̺귯���� �ִ�.
//�̰��� ǥ�� ���ø� ���̺귯��(STL : Standard Template Library)��� �Ѵ�.
//- �迭 vector Ŭ����
//- ����Ʈ list Ŭ����
//- ť queue Ŭ����
//- ���� stack Ŭ����
//*/
//
//int main()
//{
//	vector<int>  v1;
//
//	v1.push_back(10);
//	v1.push_back(11);
//	v1.push_back(15);
//
//	vector<int>::iterator iter_first, iter_last, iter;
//	iter_first = v1.begin();
//	iter_last = v1.end();
//
//	// �ݺ��ڸ� ����Ѵ�
//	for (iter = iter_first; iter != iter_last; ++iter)
//		// iterator���� ���� ������ ��쿡�� *�� ���Դϴ�.
//		cout << *iter << endl;
//
//	// �ε��� ���
//	for (int i = 0; i<  v1.size(); ++i  )
//		cout << v1.at(i) << endl;
//
//	// �迭ó�� ���
//	for (int i = 0; i< v1.size(); ++i)
//		cout << v1[i] << endl;
//
//	return 0;
//}