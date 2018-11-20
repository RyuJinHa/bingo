#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int row_count_bingo(int (*user)[N])//°¡·Îºù°í°¹¼ö¼¼±â  
{
	int i,j;
	int rows=0;
	int count=0;
	int tempcode=48-49;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if (user[i][j]==tempcode)
			{
				rows++;
				if(rows==N)
				{
					count++;
				}
		}
	}
	}
		return count;
}
	
int col_count_bingo(int (*user)[N])//¼¼·Î ºù°í°¹¼ö ¼¼±â  
{
	int i,j;
	int cols=0;
	int count=0;
	int tempcode=48-49;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{		
			if (user[j][i]==tempcode)
			{
				cols++;
				if(cols==N)
				{
					count++;
				}
			}
		}
	}
		return count;
}

int cross1_count_bingo(int (*user)[N])//´ë°¢¼±1 ºù°í°¹¼ö ¼¼±â  
{
	int i,j;
	int cross1=0;
	int count=0;
	int tempcode=48-49;
	
		for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{			
			if(user[i][j]==tempcode&&i==j)
			{
				cross1++;
				if(cross1==N)
				{
					count++;
				}
			}
		}
	}
		return count;
}

int cross2_count_bingo(int (*user)[N])//´ë°¢¼±2 ºù°í°¹¼ö ¼¼±â  
{
	int i,j;
	int cross2=0;
	int count=0;
	int tempcode=48-49;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{			
			if(user[j][4-i]==tempcode&&i==j)
			{
				cross2++;
				if(cross2==N)
				{
					count++;
				}
			}
		}
	}
	return count;
}


int count_bingo(int (*user)[N])
{
	int bingocount;
	
	bingocount=row_count_bingo(user)+col_count_bingo(user)+cross1_count_bingo(user)+cross2_count_bingo(user);
	
	return bingocount;
}

