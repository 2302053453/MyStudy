//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
///*
//	2016-03-18
//	�̹� ���� �Ǿ� �ִ� �� �߿��� Ư�� ������(���ǿ� �´� ������)�� ������ ������ �ִ��� �����ϴ� �˰���
//*/
//
//int main()
//{
//	vector<int> vec1;
//	vec1.push_back(10);
//	vec1.push_back(20);
//	vec1.push_back(15);
//	vec1.push_back(7);
//	vec1.push_back(100);
//	vec1.push_back(40);
//	vec1.push_back(11);
//	vec1.push_back(60);
//	vec1.push_back(140);
//
//	// �������� �ʰ� binary_search�� ����ϸ� �������� ������� ���� �� ����.
//	bool find = binary_search(vec1.begin(), vec1.end(), 15);
//	if (false == find)
//		cout << "15�� ã�� ���߽��ϴ�." << endl;
//	else
//		cout << "15�� ã�ҽ��ϴ�." << endl;
//
//	// ���� �� ���
//	sort(vec1.begin(), vec1.end());
//	find = binary_search(vec1.begin(), vec1.end(), 15);
//	if (false == find)
//		cout << "15�� ã�� ���߽��ϴ�." << endl;
//	else
//		cout << "15�� ã�ҽ��ϴ�." << endl;
//
//	return 0;
//}