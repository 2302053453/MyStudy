//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-17
//	Vector 예제
//
//	class를 array처럼 사용하려면 array대신 vector를 사용하면 된다.
//	class로 array가 안되는 이유?
//	- array는 메모리에 공간을 미리 할당해야 되는데
//	  class의 크기가 어느정도인지 알 수 없다.
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
//	// 반복자를 사용한다
//	for (iter = iter_first; iter != iter_last; ++iter)
//		// iterator에서 값에 접근할 경우에는 *를 붙입니다.
//		cout << iter->GetTotal() << endl;
//
//	// 인덱스 사용
//	for (int i = 0; i< v1.size(); ++i)
//		cout << v1.at(i).GetTotal() << endl;
//
//	// 배열처럼 사용
//	for (int i = 0; i< v1.size(); ++i)
//		cout << v1[i].GetTotal() << endl;
//
//	return 0;
//}