//#include<iostream>
///*
//	2016-03-15
//	defaultValue예제
//	부분적 디폴트 값 설정은 반드시 오른쪽 인자의 디폴트 값부터
//	지정하는 형태로 정의해야 한다.
//*/
//
//// 함수선언(DefaultValue 포함)
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
//// 함수의 정의에선 defaultValue를 명시하지 않아도 적용된다
//int BoxVolume(int length, int width, int height)
//{
//	return length + width + height;
//}