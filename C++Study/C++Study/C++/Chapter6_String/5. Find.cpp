//#include<iostream>
//#include<string>
//using namespace std;
///*
//2016-03-17
//strinf find ����
//*/
//
//int main()
//{
//	// ���� ���ڿ��� �Է� ����
//	string src = "ABCDEFG ȫ�浿 HIJKLM �浿 OPQRSTU �� VWXYZ";
//
//	// ã�� ���ڿ��� �Է¹���
//	cout << "ã�� ���ڿ� �Է� : ";
//	string findStr;
//	getline(cin, findStr);
//
//	// �˻��� �ʿ��� ������ �ʱ�ȭ
//	int cnt = 0;
//	string::size_type findOffset = 0;
//
//	while (true)
//	{
//		// �˻�
//		findOffset = src.find(findStr, findOffset);
//
//		// ã�� ������ ��
//		if (string::npos == findOffset)
//			break;
//
//		// ã�� ������ ���� �˻� ��ġ �̵�
//		++cnt;
//		++findOffset;
//	}
//
//	cout << "���ڿ� ( " << findStr << " ) �� ���� : " << cnt << endl;
//
//	return 0;
//}