#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int initiate_bingo(int (*user)[N],int (*com)[N])//�������̺��� �ʱ⿡ �������  
{
	int i,j;
	int temp, ROW1, ROW2, COL1, COL2;
	int change=100; 
	int number=1;//�������迭�� ���ʴ�� �ϱ� ���� ������� 
	
 	srand((unsigned)time(NULL));//���� �迭 


	//user :N*N �������迭�� ���ʴ�� �迭�ϱ� 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			user[i][j]=number++;		
		}
	}

	//user: 2���� �迭 ���� 
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
	
	number=1;
	//computer :N*N �������迭�� ���ʴ�� �迭�ϱ� 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			com[i][j]=number++;	
			
		}
	}

	//computer: 2���� �迭 ���� 
	for(i=0;i<change;i++)
	{
		ROW1=rand()%N;
		ROW2=rand()%N;
		
		COL1=rand()%N;
		COL2=rand()%N;
		
		temp=com[ROW1][COL1];
		com[ROW1][COL1]=com[ROW2][COL2];
		com[ROW2][COL2]=temp;
	}
	return ;
	}
