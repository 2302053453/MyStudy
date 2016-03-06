//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-05
//	연습문제
//	점 5개로 이루어진 도형
//	점 
//	A (50, 200)
//	B (20, 80)
//	C (75, 10)
//	D (130, 80)
//	E (100, 200)
//	
//	1. 이 점들을  list로 만드시오 ( 순서대로 넣고 출력)
//	2. 새로운 점 F(180,150) 추가
//	3. D의 값을 (200,100)으로 변경
//	4. 점 C를 삭제
//*/
//
//// 점 구조체 선언
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
//	cout << "1. 이 점들을  list로 만드시오(순서대로 넣고 출력)" << endl;
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
//	cout << "2. 새로운 점 F(180, 150) 추가" << endl;
//	pointList.push_back(*new Point("F", 180, 150));
//
//	iterEnd = pointList.end();
//	for (list<Point>::iterator iter = pointList.begin(); iter != iterEnd; iter++)
//		cout << "point name : " << iter->pName << " position : " << iter->posX << "," << iter->posY << endl;
//
//	cout << "3. D의 값을 (200,100)으로 변경" << endl;
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
//	cout << "4. 점 C를 삭제" << endl;
//	iterPos--;
//	pointList.erase(iterPos);
//	
//	iterEnd = pointList.end();
//	for (list<Point>::iterator iter = pointList.begin(); iter != iterEnd; iter++)
//		cout << "point name : " << iter->pName << " position : " << iter->posX << "," << iter->posY << endl;
//	system("PAUSE");
//}
