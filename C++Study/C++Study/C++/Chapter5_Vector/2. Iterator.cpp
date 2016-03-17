//#include<iostream>
//#include<vector>
//using namespace std;
///*
//2016-03-17
//Vector 예제
//
//vector 클래스는 메모리가 부족한 경우에 자동으로 메모리를 확보
//그러므로 배열과는 다르게 사이즈에 신경을 쓸 필요가 없다.
//
//C++언어에는 템플릿 클래스를 사용하는 표준 라이브러리가 있다.
//이것을 표준 템플릿 라이브러리(STL : Standard Template Library)라고 한다.
//- 배열 vector 클래스
//- 리스트 list 클래스
//- 큐 queue 클래스
//- 스택 stack 클래스
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
//	// 반복자를 사용한다
//	for (iter = iter_first; iter != iter_last; ++iter)
//		// iterator에서 값에 접근할 경우에는 *를 붙입니다.
//		cout << *iter << endl;
//
//	// 인덱스 사용
//	for (int i = 0; i<  v1.size(); ++i  )
//		cout << v1.at(i) << endl;
//
//	// 배열처럼 사용
//	for (int i = 0; i< v1.size(); ++i)
//		cout << v1[i] << endl;
//
//	return 0;
//}