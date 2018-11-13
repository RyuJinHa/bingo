#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo(int form[N-1][N-1])//빙고판의 변수:form 
{
	int i,j;
	int k;
 	srand((unsigned)time(NULL));//난수 배열 
	

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
	
			form[i][j]=rand() % (N*N)+1;
		}
	}
	
	for(i=0;i<N;i++)	
	{
		for(j=0;j<N;j++)
		{
			printf("  %i", form[i][j]);
			
		}
			printf("\n \n");
	}
	printf("\n");

return ;
}

int get_number_byMe(int num)//num은 숫자입력을 받기위한 변수
 
{
	printf("숫자를 입력하세요: ");
	scanf("%i",&num);
	
}



	  
int main(int argc, char *argv[]) {
	
	int form[N-1][N-1];
	printf("빙고게임을 시작합니다.\n ");
	printf(" %i",initiate_bingo(form));
	
	return ;
}
