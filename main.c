#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo(int user[N][N], int comp[N][N])//�������̺��� �ʱ⿡ �������  
{
	int i,j;
	int temp, ROW1, ROW2, COL1, COL2;
	int change=100; 
	int count=1;//�������迭�� ���ʴ�� �ϱ� ���� ������� 
	
 	srand((unsigned)time(NULL));//���� �迭 
	
	printf("--------------����� ������--------------\n\n");
	//user :N*N �������迭�� ���ʴ�� �迭�ϱ� 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			user[i][j]=count++;	
			
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
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" |  %d   ", user[i][j]);
		}
			printf("\n  \n");
	}
	
	printf("\n \n \n");
	printf("------------Computer�� ������--------------\n\n");
	
	count=1;
	//computer :N*N �������迭�� ���ʴ�� �迭�ϱ�
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			comp[i][j]=count++;	
		}
	}
	//computer: 2���� �迭 ���� 
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
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf(" |  %d   ", comp[i][j]);
		}
			printf("\n  \n");
	}
	
	printf("\n");

	return ;
}



int get_number_byMe(int userinput)//num�� �����Է��� �ޱ����� ����
 
{
	printf("1~25������ ���ڸ� �Է��ϼ���: ");
	scanf("%i",&userinput);
}



int get_number_byCom(int num)
{
	num=rand()%N+1;
	printf("��ǻ�Ͱ� ������ �����Դϴ�. : %d",num);
}


int process_bingo(int form[N][N],int userinput)
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(form[i][j]==userinput)
			{
				form[i][j]=-1;
			}
		}
	}
}
int print_bingo()
{
	
}

	  
int main(int argc, char *argv[]) {
	
	int user[N][N];
	int comp[N][N];
	
	
	printf("��������� �����մϴ�.\n \n����� �������Դϴ�. \n \n \n");
	printf(" %i \n", initiate_bingo(user,comp));
	
	

	return ;
}
