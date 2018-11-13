#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo(int form[N][N])//빙고판의 변수:form 
{
	int i,j=0;
	int tmp;  
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{

			form[i][j]=rand() % (N*N)+1;
			form[i][j]=tmp;
			if(tmp==form[i][j])
			{
				j--;
			}
			else
			return;
			
		}
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%i", form[i][j]);
		}
	}
}
	  
int main(int argc, char *argv[]) {
	
	int A[N][N];
	printf("빙고게임을 시작합니다.\n ");
	printf("%i",initiate_bingo(A));
	
	return ;
}
