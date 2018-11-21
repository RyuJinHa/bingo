#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int print_bingo(int (*user)[N],int (*com)[N])//빙고 테이블 현재 상황을 화면에 출력  
{
	int i,j;
	int c;
	int tempcode=48-49;
	
	//user의 빙고판  
	printf("\n\n--------------당신의 빙고판--------------\n\n");
	//빙고판을 보기 좋게 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(user[i][j]==tempcode)//선택된 숫자를 -1로 표현하기 
			{	
				printf(" | %4d ",tempcode);
			}
		
			else//선택되지 않은 숫자는 그대로 표현하기
			{
				printf(" | %4d ", user[i][j]);
			}
		
		}
			printf("\n  \n");	
	}
	
	
	//computer의 빙고판  
	printf("\n\n--------------computer의 빙고판--------------\n\n");
	//빙고판을 보기 좋게 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(com[i][j]==tempcode)//선택된 숫자를 -1로 표현하기 
			{	
				printf(" | %4d ",tempcode);
			}
		
			else//선택되지 않은 숫자는 그대로 표현하기  
			{
				printf(" | %4d ", com[i][j]);
			}
		
		}
			printf("\n  \n");
	}
	printf("\n \n \n");
	
	return;
}

