//#include<iostream>
//using namespace std;
///*
//	2016-03-15
//	reference array element ����
//	array�� ��ҿ� ���Ͽ� ������ ������ �����ϴ�
//
//	*�����ڰ� ������ �ȵǴ� ����(ERROR �߻�!)
//		- �������� ������ ���� ( int &ref=20;, �� const �����ڴ� ��������� �����ϴ� )
//		- �����ڸ� �����ϰ� �ʱ�ȭ ��Ű�� �ʴ� ���( int &ref;)
//		- NULL�� �ʱ�ȭ �ϴ°��( int &ref=NULL;)
//*/
//
//int main()
//{
//	int arr[3] = { 1,3,5 };
//	
//	// Array�� ��ҿ� ���Ͽ� reference�� ����
//	int &ref1 = arr[0];
//	int &ref2 = arr[1];
//	int &ref3 = arr[2];
//
//	cout << ref1 << endl;
//	cout << ref2 << endl;
//	cout << ref3 << endl;
//	return 0;
//}