//#include<iostream>
///*
//2016-03-15
//�ּ� Call By Value ����
//C++������ �Լ� �ܺο� ����� ������ ���ٹ�� �� ����
//- �ּ� ���� �̿��� Call-by-reference (*)
//- �����ڸ� �̿��� Call-by-reference (&)
//
//Call-by-value�� ���·� ���ǵ� �Լ��� ���ο�����, �Լ��ܺο� ����� ������ ������ �Ұ����ϴ�.
//- SwapByValue�� ���޵� ���ڴ� SwapByValue�� ���������̴�.
//*/
//using namespace std;
//
//// call by reference
//void Swap(int ref1, int ref2)
//{
//	int temp = ref1;
//	ref1 = ref2;
//	ref2 = ref1;
//}
//int main()
//{
//	int val1 = 10;
//	int val2 = 20;
//
//	// val1�� val2�� ���� �ٲ۴�.(������ call by value�̱� ������ ���� ���� ������� �ʴ´�).
//	Swap(val1, val2);
//
//	cout << "val1 : " << val1 << endl;
//	cout << "val2 : " << val2 << endl;
//	return 0;
//}