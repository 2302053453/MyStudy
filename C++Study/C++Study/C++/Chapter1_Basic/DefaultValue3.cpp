//#include<iostream>
///*
//	2016-03-15
//	defaultValue����
//	�κ��� ����Ʈ �� ������ �ݵ�� ������ ������ ����Ʈ ������
//	�����ϴ� ���·� �����ؾ� �Ѵ�.
//*/
//
//// �Լ�����(DefaultValue ����)
//int BoxVolume(int length, int width = 1, int height = 2);
//
//int main()
//{
//	std::cout <<"[3, 3, 3]" <<BoxVolume(3,3,3) << std::endl;
//	std::cout <<"[5, 5, 0]" << BoxVolume(5, 5) << std::endl;
//	std::cout <<"[7, 0, 0]" << BoxVolume(7) <<std::endl;
//	return 0;
//}
//
//// �Լ��� ���ǿ��� defaultValue�� ������� �ʾƵ� ����ȴ�
//int BoxVolume(int length, int width, int height)
//{
//	return length + width + height;
//}