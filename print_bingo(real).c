#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int print_bingo(int (*user)[N],int (*com)[N])//���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���  
{
	int i,j;
	int c;
	int tempcode=48-49;
	
	//user�� ������  
	printf("\n\n--------------����� ������--------------\n\n");
	//�������� ���� ���� �迭�ϱ� 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(user[i][j]==tempcode)//���õ� ���ڸ� -1�� ǥ���ϱ� 
			{	
				printf(" | %4d ",tempcode);
			}
		
			else//���õ��� ���� ���ڴ� �״�� ǥ���ϱ�
			{
				printf(" | %4d ", user[i][j]);
			}
		
		}
			printf("\n  \n");	
	}
	
	
	//computer�� ������  
	printf("\n\n--------------computer�� ������--------------\n\n");
	//�������� ���� ���� �迭�ϱ� 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(com[i][j]==tempcode)//���õ� ���ڸ� -1�� ǥ���ϱ� 
			{	
				printf(" | %4d ",tempcode);
			}
		
			else//���õ��� ���� ���ڴ� �״�� ǥ���ϱ�  
			{
				printf(" | %4d ", com[i][j]);
			}
		
		}
			printf("\n  \n");
	}
	printf("\n \n \n");
	
	return;
}

