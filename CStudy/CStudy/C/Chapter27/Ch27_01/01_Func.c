
/*
	2016-03-10
	파일분할 예제(함수)
*/

// Ch27_01_num.c에 있는 num변수를 불러온다
extern int num;

void Inceasement(void)
{
	num++;
}
int GetNum(void)
{
	return num;
}