#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5



int count_bingo(int user[N][N])
{
	int i,j;
	int rows=0;//가로 개수 세기 변수 
	int cols=0;//세로 개수 세기 변수 
	int cross1=0;//대각선1 개수 세기 변수 
	int cross2=0;//대각선2 개수 세기 변수 
	int count=0;//빙고 개수 세기 변수 
	int tempcode=48-49;

	for(i=0;i<N;i++)
	{
			rows=0;
			cols=0;
		for(j=0;j<N;j++)
		{
			if (user[i][j]==tempcode)	rows++;//가로 빙고 개수 세기 
			if (user[j][i]==tempcode)	cols++;//세로 빙고 개수 세기  
			if(user[i][j]==tempcode&&i==j)	cross1++;//대각선 1 빙고 개수 세기  
			if(user[j][N-1-i]==tempcode&&i==j)	cross2++;//대각선 2 빙고 개수 세기  
			if(rows==N)//rows가 N개가 되면 빙고 한줄 완성
 			{
				count++;
			}
			if(cols==N)//cols가 N개가 되면 빙고 한줄 완성 
			{
				count++;
			}	
	}		
		
		
	}	
		if(cross1==N)//cross1이 N개가 되면 빙고 한줄 완성  
		{
			count++;
		}

		if(cross2==N)//cross2이 N개가 되면 빙고 한줄 완성 
		{
			count++;
		}

	

	return count ;
}

