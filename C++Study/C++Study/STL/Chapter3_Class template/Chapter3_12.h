/*
	2016-03-03
	탬플릿 클래스의 선언과 정의를 각각 다른 파일에 한다 (inline방식) 
*/
template<typename T>
class Stack 
{
public:
	void Clear();
};

// inl파일에서 정의
#include"Chapter3_12.inl"