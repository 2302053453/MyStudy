//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
///*
//	2016-02-19
//	간단한 업다운게임
//*/
//
//int main(void)
//{
//	int maximumChance = 7;
//	int chance;
//	int answer;
//	int num;
//	char retry;
//	srand((int)time(NULL));
//
//	while (1)
//	{
//		// 잔여기회 초기화
//		chance = 0;
//		// 컴퓨터가 숫자를 정한다
//		answer = rand() % 100 + 1;
//		
//		// 7번 반복
//		while (chance < maximumChance)
//		{
//			printf("정답은 : ? (남은 시도횟수 = %d회)", maximumChance - chance);
//			scanf("%d", &num);
//
//			// 정답과 비교
//			if (num < answer)
//			{ 
//				printf("땡! 업입니다!\n");
//				chance++;
//			}
//			else if (num > answer)
//			{
//				printf("땡! 다운입니다!\n");
//				chance++;
//			}
//			else if (num == answer)
//			{
//				printf("정답! 대단하시네요!\n");
//				break;
//			}
//
//			// 잔여기회유무 판별
//			if (maximumChance == chance)
//			{
//				printf("이런.... 못맞추셨네요...\n정답은 %d였습니다! 다음 기회에!\n", answer);
//			}
//
//		}
//
//		// 재도전유무
//		do{ 
//			printf("다시하시겠습니까?( 예(y) /아니오(n) ) ");
//			scanf(" %c", &retry);
//			if ((int)(retry != 'y') && ((int)retry != 'n') &&
//				(int)(retry != 'Y') && ((int)retry != 'N'))
//				printf("이상한거 누르지말고 제대로 선택해주세요!\n");
//			else
//				break;
//		} while (1);
//	
//		if ((int)retry == 'y')
//			continue;
//		else if ((int)retry == 'n')
//			return 0;
//	}	
//}