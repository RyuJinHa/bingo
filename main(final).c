#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initiate_bingo(real).h"
#include "print_bingo(real).h"
#include "count_bingo(real).h"
#include "get_number_byMe(real).h"
#include "get_number_byCom(real).h"
#define N 5
#define winner 5
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	
	int user[N][N];//user의 빙고배열  
	int com[N][N];//computer의 빙고배열  
	int turnnum=0;//몇번째 턴인지를 알게하기 위한 변수  
	int count;

	printf("빙고게임을 시작합니다. ");
	
	initiate_bingo(user,com);//빙고테이블을 초기에 만들어줌	
	
	print_bingo(user,com);//빙고 테이블 현재 상황을 화면에 출력  
	
	while(count_bingo(user)<=N-1 &&count_bingo(com)<=N-1)
	{
	
		get_number_byMe(user,com);//내가 빙고 번호 입력 선택
		get_number_byCom(user,com);//컴퓨터가 임의로 빙고 번호 선택
		print_bingo(user,com);//빙고 테이블 현재 상황을 화면에 출력 
		count_bingo(user);//user의 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환
		count_bingo(com);//computer의 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 
		turnnum++;//while문을 반복할때마다  turnnum을 증가시켜 몇번? 턴인지를 알게한다.  
		printf("%d 번째 턴입니다. \n\n", turnnum);
		printf("나의 빙고 갯수 : %d  ,  컴퓨터의 빙고 갯수 : %d \n \n",count_bingo(user), count_bingo(com));
		 
		if(count_bingo(user)>=winner||count_bingo(com)>=winner)//빙고개수가 N개 이상인 경우 빙고게임이 끝이난다.  
		{
			if(count_bingo(user)>=winner)
			{	
				printf("축하합니다. %d번 째에 빙고게임을 이겼습니다. ",turnnum);
			}
			if(count_bingo(com)>=winner) 
			{
				printf(" 안타깝네요. computer가 %d번 째에 빙고게임을 이겼습니다. ",turnnum);
			}
		} 			
	}

	return ;
}
