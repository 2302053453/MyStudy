//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-05
//	��������
//	�� 5���� �̷���� ����
//	�� 
//	A (50, 200)
//	B (20, 80)
//	C (75, 10)
//	D (130, 80)
//	E (100, 200)
//	
//	1. �� ������  list�� ����ÿ� ( ������� �ְ� ���)
//	2. ���ο� �� F(180,150) �߰�
//	3. D�� ���� (200,100)���� ����
//	4. �� C�� ����
//*/
//
//// �� ����ü ����
//struct Point
//{
//	Point(char* name, int posx, int posy)
//	{
//		pName = name;
//		posX = posx;
//		posY = posy;
//	}
//	char* pName;
//	int posX;
//	int posY;
//};
//
//void main()
//{
//	cout << "1. �� ������  list�� ����ÿ�(������� �ְ� ���)" << endl;
//	list<Point> pointList;
//	pointList.push_back(*new Point("A",500, 200));
//	pointList.push_back(*new Point("B", 20, 80));
//	pointList.push_back();
//	pointList.push_back(*new Point("D", 130, 80));
//	pointList.push_back(*new Point("E", 100, 200));
//
//	list<Point>::iterator iterEnd = pointList.end();
//	for (list<Point>::iterator iter = pointList.begin(); iter != iterEnd; iter++)
//		cout << "point name : " << iter->pName << " position : " << iter->posX << "," << iter->posY << endl;
//
//
//	cout << "2. ���ο� �� F(180, 150) �߰�" << endl;
//	pointList.push_back(*new Point("F", 180, 150));
//
//	iterEnd = pointList.end();
//	for (list<Point>::iterator iter = pointList.begin(); iter != iterEnd; iter++)
//		cout << "point name : " << iter->pName << " position : " << iter->posX << "," << iter->posY << endl;
//
//	cout << "3. D�� ���� (200,100)���� ����" << endl;
//	list<Point>::iterator iterPos = pointList.begin();
//	iterPos++;
//	iterPos++;
//	iterPos++;
//	iterPos->posX = 200;
//	iterPos->posY = 100;
//
//	for (list<Point>::iterator iter = pointList.begin(); iter != iterEnd; iter++)
//		cout << "point name : " << iter->pName << " position : " << iter->posX << "," << iter->posY << endl;
//	
//
//	cout << "4. �� C�� ����" << endl;
//	iterPos--;
//	pointList.erase(iterPos);
//	
//	iterEnd = pointList.end();
//	for (list<Point>::iterator iter = pointList.begin(); iter != iterEnd; iter++)
//		cout << "point name : " << iter->pName << " position : " << iter->posX << "," << iter->posY << endl;
//	system("PAUSE");
//}
