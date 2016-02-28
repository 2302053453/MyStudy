//#include<stdio.h>
///*
//	2016-02-19
//	¹®Á¦2(Qu09-02.c)
//	¼·¾¾(Celsius)¸¦ ÀÔ·Â¹Þ¾Æ¼­ È­¾¾(Fahrenheit)·Î º¯È¯ÇÏ¿© ¸®ÅÏÇÏ´Â ÇÔ¼ö¿Í
//	È­¾¾¸¦ ÀÔ·Â¹Þ¾Æ¼­ ¼·¾¾·Î º¯È¯ÇÏ¿© ¸®ÅÏÇÏ´Â ÇÔ¼ö¸¦ ¸¸µé¾î¶ó.
//	È­¾¾ = 1.8 * ¼·¾¾ + 32
//	¼·¾¾ = (È­¾¾ - 32) / 1.8
//*/
//
//double Convert(int select, double value);
//
//int main()
//{
//	int select;
//	double value;
//	printf("1.¼·¾¾, 2.È­¾¾ ¾î¶²°ÍÀ» ÀÔ·ÂÇÏ½Ã°Ú½À´Ï±î? : ");
//	scanf("%d", &select);
//	if (select != 1 && select != 2)
//	{ 
//		printf("Àß¸øµÈ°ªÀÔ´Ï´Ù. ÇÁ·Î±×·¥À» Á¾·áÇÕ´Ï´Ù\n");
//		return 0;
//	}
//
//	printf("°ªÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä.");
//	scanf("%f", &value);
//	Convert(select, value);
//	
//	printf("°á°ú : %f \n", value);
//	return 0;
//}
//
//double Convert(int select, double value)
//{
//	switch (select)
//	{
//		//¼·¾¾ -> È­¾¾
//		case 1:
//			return  (double)1.8 * value + (double)32;
//		//È­¾¾ -> ¼·¾¾
//		case 2:
//			return (value - 32) / 1.8;
//		default:
//			printf("¿¡·¯\n");
//			break;
//	}
//}
//
