//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-17
//	Vector ����
//
//	class�� arrayó�� ����Ϸ��� array��� vector�� ����ϸ� �ȴ�.
//	class�� array�� �ȵǴ� ����?
//	- array�� �޸𸮿� ������ �̸� �Ҵ��ؾ� �Ǵµ�
//	  class�� ũ�Ⱑ ����������� �� �� ����.
//*/
//
//class AppleBox
//{
//public:
//	AppleBox() { Empty(); }
//	void Add(int n) { total += n; }
//	void Empty() { total = 0; }
//	int GetTotal() { return total; }
//private:
//	int total;
//};
//
//int main()
//{
//	AppleBox a1;
//	a1.Add(10);
//
//	AppleBox a2;
//	a2.Add(20);
//
//	AppleBox a3;
//	a3.Add(30);
//
//	vector<AppleBox> v1;
//
//	v1.push_back(a1);
//	v1.push_back(a2);
//	v1.push_back(a3);
//
//	vector<AppleBox>::iterator iter_first, iter_last, iter;
//	iter_first = v1.begin();
//	iter_last = v1.end();
//
//	// �ݺ��ڸ� ����Ѵ�
//	for (iter = iter_first; iter != iter_last; ++iter)
//		// iterator���� ���� ������ ��쿡�� *�� ���Դϴ�.
//		cout << iter->GetTotal() << endl;
//
//	// �ε��� ���
//	for (int i = 0; i< v1.size(); ++i)
//		cout << v1.at(i).GetTotal() << endl;
//
//	// �迭ó�� ���
//	for (int i = 0; i< v1.size(); ++i)
//		cout << v1[i].GetTotal() << endl;
//
//	return 0;
//}