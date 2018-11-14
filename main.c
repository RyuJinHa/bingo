#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo(int user[N][N], int computer[N][N])//빙고테이블을 초기에 만들어줌  
{
	int i,j;
	int temp, ROW1, ROW2, COL1, COL2;
	int change=100; 
	int count=1;//이차원배열을 차례대로 하기 위한 상수설정 
	
 	srand((unsigned)time(NULL));//난수 배열 
	
	//N*N 이차원배열을 차례대로 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			user[i][j]=count++;	
		}
	}

	//2차원 배열 섞기 
	for(i=0;i<change;i++)
	{
		ROW1=rand()%N;
		ROW2=rand()%N;
		
		COL1=rand()%N;
		COL2=rand()%N;
		
		temp=user[ROW1][COL1];
		user[ROW1][COL1]=user[ROW2][COL2];
		user[ROW2][COL2]=temp;
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" |  %d   ", user[i][j]);
		}
			printf("\n  \n");
	}

	for(i=0;i<change;i++)
	{
		ROW1=rand()%N;
		ROW2=rand()%N;
		
		COL1=rand()%N;
		COL2=rand()%N;
		
		temp=computer[ROW1][COL1];
		computer[ROW1][COL1]=computer[ROW2][COL2];
		computer[ROW2][COL2]=temp;
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" |  %d   ", user[i][j]);
		}
			printf("\n  \n");
	}
	printf("\n");
	

	return ;
}



int get_number_byMe(int num)//num은 숫자입력을 받기위한 변수
 
{
	printf("숫자를 입력하세요: ");
	scanf("%i",&num);
	
}

int get_number_byCom(int num)
{
	num=rand()%N+1;
	printf("컴퓨터가 선택한 숫자입니다. : %d",num);
}
int process_bingo()
{
	
}
int print_bingo()
{
	
}

	  
int main(int argc, char *argv[]) {
	
	int user[N][N];
	int computer[N][N];
	
	
	printf("빙고게임을 시작합니다.\n \n당신의 빙고판입니다. \n \n \n");
	printf(" %i \n",initiate_bingo(user));
	initiate_bingo(computer);
	return ;
}
