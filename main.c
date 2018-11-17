#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo(int user[N][N], int comp[N][N])//빙고테이블을 초기에 만들어줌  
{
	int i,j;
	int temp, ROW1, ROW2, COL1, COL2;
	int change=100; 
	int count=1;//이차원배열을 차례대로 하기 위한 상수설정 
	
 	srand((unsigned)time(NULL));//난수 배열 
	//user의 빙고판  
	printf("--------------당신의 빙고판--------------\n\n");
	//user :N*N 이차원배열을 차례대로 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			user[i][j]=count++;	
			
		}
	}

	//user: 2차원 배열 섞기 
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
	//빙고판을 보기 좋게 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" | %4d ", user[i][j]);
		}
			printf("\n  \n");
	}
	
	printf("\n \n \n");
	//컴퓨터의 빙고판  
	printf("------------Computer의 빙고판--------------\n\n");
	
	count=1;
	//computer :N*N 이차원배열을 차례대로 배열하기
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			comp[i][j]=count++;	
		}
	}
	//computer: 2차원 배열 섞기 
	for(i=0;i<change;i++)
	{
		ROW1=rand()%N;
		ROW2=rand()%N;
		
		COL1=rand()%N;
		COL2=rand()%N;
		
		temp=comp[ROW1][COL1];
		comp[ROW1][COL1]=comp[ROW2][COL2];
		comp[ROW2][COL2]=temp;
	}
	//빙고판을 보기 좋게 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" | %4d ", comp[i][j]);
		}
			printf("\n  \n");
	}
	
	printf("\n");

	return ;
}



int get_number_byMe(int userinput)//num은 숫자입력을 받기위한 변수
 
{
	printf("1~25까지의 숫자를 입력하세요: ");
	scanf("%i",&userinput);
}



int get_number_byCom(int compinput)
{
	compinput=rand()%N+1;
	printf("컴퓨터가 선택한 숫자입니다. : %d",compinput);
}


void process_bingo(int userinput)
{
	int user[N][N];

	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if((user[i][j]==get_number_byMe(userinput)))
			{
				user[i][j]==4549;
			}
			break;
		}
	}
}


int count_bingo(int bingocount)
{
	int i,j;
	int rows=0;
	int cols=0;
	int cross1=0;
	int cross2=0;
	int user[N][N];
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if (user[i][j]==4549)
			{
				rows++;
			}
			if (user[j][i]==4549)
			{
				cols++;
			}
			if(i==j&&user[i][j]==4549)
			{
				cross1++;
			}
			if(i==j&&user[j][i]==4549)
			{
				cross2++;
			}
		}
	
	}
	if(rows==5)
	{
		bingocount++;
	}
	if(cols==5)
	{
		bingocount++;
	}
	if(cross1==5)
	{
		bingocount++;
	}
	if(cross2==5)
	{
		bingocount++;
	}
}




int print_bingo()
{
	
}

	  
int main(int argc, char *argv[]) {
	
	int user[N][N];
	int comp[N][N];
	int userinput; 
	int compinput;
	
	printf("빙고게임을 시작합니다.\n \n당신의 빙고판입니다. \n \n \n");
	printf(" %i \n", initiate_bingo(user,comp));
	
	printf("%d",get_number_byMe(userinput));

	
	

	return ;
}
