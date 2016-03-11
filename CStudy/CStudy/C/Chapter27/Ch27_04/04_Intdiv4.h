/*
	2016-03-10
	구조체 파일분할 + 중복정의 방지
*/

// 현재 HEADER파일이 호출되어 정의되어있으면 다시 실행하지 않는다.
#ifndef __04_INTDIV04_H__
#define __04_INTDIV04_H__

#include "04_stdiv.h"
Div IntDiv(int num1, int num2);
#endif // ! __INTDIV04_H__
