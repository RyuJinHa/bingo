#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5



int count_bingo(int user[N][N])
{
	int i,j;
	int rows=0;//���� ���� ���� ���� 
	int cols=0;//���� ���� ���� ���� 
	int cross1=0;//�밢��1 ���� ���� ���� 
	int cross2=0;//�밢��2 ���� ���� ���� 
	int count=0;//���� ���� ���� ���� 
	int tempcode=48-49;

	for(i=0;i<N;i++)
	{
			rows=0;
			cols=0;
		for(j=0;j<N;j++)
		{
			if (user[i][j]==tempcode)	rows++;//���� ���� ���� ���� 
			if (user[j][i]==tempcode)	cols++;//���� ���� ���� ����  
			if(user[i][j]==tempcode&&i==j)	cross1++;//�밢�� 1 ���� ���� ����  
			if(user[j][N-1-i]==tempcode&&i==j)	cross2++;//�밢�� 2 ���� ���� ����  
			if(rows==N)//rows�� N���� �Ǹ� ���� ���� �ϼ�
 			{
				count++;
			}
			if(cols==N)//cols�� N���� �Ǹ� ���� ���� �ϼ� 
			{
				count++;
			}	
	}		
		
		
	}	
		if(cross1==N)//cross1�� N���� �Ǹ� ���� ���� �ϼ�  
		{
			count++;
		}

		if(cross2==N)//cross2�� N���� �Ǹ� ���� ���� �ϼ� 
		{
			count++;
		}

	

	return count ;
}

