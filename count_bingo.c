#include <stdio.h>
#include <stdlib.h>

#define N 5

int count_bingo(int (*user)[N])//빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환  
{
	int i,j;
	int rows=0;
	int cols=0;
	int cross1=0;
	int cross2=0;
	int count=0;
	int tempcode=48-49;


	for(i=0;i<N;i++)//가로 세로 빙고 개수 세기  
	{
		for(j=0;j<N;j++)
		{
			if (user[i][j]==tempcode)	rows++;
			if (user[j][i]==tempcode)	cols++;
		}
	}
	
	if(rows==N) count++;
	if(cols==N) count++;

	
	for(i=0;i<N;i++)//대각선 빙고 개수 세기  
	{
		for(j=0;j<N;j++)
		{
		
			if(user[i][j]==tempcode&&i==j)	cross1++;
			if(user[j][N-1-i]==tempcode&&i==j)	cross2++;
		}		
		
		
	}
		if(cross1==N)
		{
			count++;
		}

		if(cross2==N)
		{
			count++;
		}

	

	return count ;
}


