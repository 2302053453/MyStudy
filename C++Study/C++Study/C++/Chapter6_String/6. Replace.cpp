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
//	// �ٲ� ���ڿ� �Է� ����
//	cout << "�ٲ� ���ڿ� �Է� : ";
//	string replaceStr;
//	getline(cin, replaceStr);
//
//	// ���� ���ڿ� ���
//	cout << "���� ���ڿ� : " << src << endl;
//
//	// �˻��� �ʿ��� ������ �ʱ�ȭ
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
//		else
//			// ã�� ���ڿ��� �ٲ� ���ڿ��� �ٲ�
//			src.replace(findOffset, findStr.length(), replaceStr);
//	}
//
//	cout << "�ٲ﹮�ڿ� : " << src << endl;
//
//	return 0;
//}