#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initiate_bingo.h"
#include "print_bingo.h"
#include "count_bingo.h"
#include "get_number_byMe.h"
#include "get_number_byCom.h"
#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


	  
int main(int argc, char *argv[]) {
	
	int user[N][N];
	int com[N][N];

	int count;

	printf("빙고게임을 시작합니다. ");
	
	initiate_bingo(user,com);	
	
	print_bingo(user,com);
	
	while(count_bingo(user)<=4 &&count_bingo(com)<=4)
	{
		get_number_byMe(user,com);
	
		get_number_byCom(user,com);
		
		print_bingo(user,com);
		
		printf("나의 빙고 갯수 : %d  ,  컴퓨터의 빙고 갯수 : %d \n \n",count_bingo(user), count_bingo(com));
	
	
		if(count_bingo(user)>=5||count_bingo(com)>=5)
		{
			if(count_bingo(user)>=5)
			{	
				printf("축하합니다. 빙고게임을 이겼습니다. ");
			}
			if(count_bingo(com)>=5) 
			{
				printf(" 안타깝네요. computer가 빙고게임을 이겼습니다. ");
			}
		} 			
	}

	return ;
}
