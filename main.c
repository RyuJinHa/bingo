#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
	



int print_bingo(int (*user)[N],int (*com)[N])
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
			if(user[i][j]==tempcode)
			{	
				printf(" | %4d ",tempcode);
			}
		
			else
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
			if(com[i][j]==tempcode)
			{	
				printf(" | %4d ",tempcode);
			}
		
			else
			{
				printf(" | %4d ", com[i][j]);
			}
		
		}
			printf("\n  \n");
	}
	printf("\n \n \n");
	
	return;
}



int get_number_byMe(int (*user)[N],int (*com)[N])//num�� �����Է��� �ޱ����� ����
 
{
	int i,j,userinput;
	int alreadynum=0;
	int count;
	int tempcode=48-49;
	
		
		
		while(1)
		{	printf(" \n1~25������ ���ڸ� �Է��ϼ���: ");
			scanf("%i",&userinput);
			
			
			if(userinput>25||userinput<1)
			{
				printf("1~25������ ���� �ƴմϴ�. �ٽ� �Է����ּ���: ");
				scanf("%i", &userinput); 
			}
		
			else(userinput>=1 &&userinput<=25);
			{
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						if (user[i][j]==userinput)
						{
						user[i][j]=tempcode;
						alreadynum=1;
						}
					}
				}	
				for(i=0;i<N;i++)
				{
				for(j=0;j<N;j++)
				{
					if (userinput==com[i][j])
					{
						com[i][j]=tempcode;
					}
				}
			}
			if(alreadynum)
				break;
			else
			{
				printf("\n�̹� �Է��� �����Դϴ�. \n \n�ٽ� �Է����ּ��� \n");
			}
	 		} 
		}
		
return userinput;
}

int get_number_byCom(int (*user)[N],int (*com)[N])
{	
	srand((unsigned)time(NULL));
	int i,j;
	int alreadynum;
	int count;
	int cominput;
	int tempcode=48-49;
	

		printf("\n��ǻ���� �����Դϴ�.\n \n"); 
		cominput=rand()%(N*N)+1;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if (user[i][j]==cominput)
				{
					user[i][j]=tempcode;
					alreadynum=1;
				}
				if(com[i][j]==cominput)
				{
					com[i][j]=tempcode;
				}	
			}
		}
		
	printf("��ǻ�Ͱ� ������ �����Դϴ�. : %d\n",cominput);	
	

	return cominput;

}




int count_bingo(int user[N][N])
{
	int i,j;
	int rows=0;
	int cols=0;
	int cross1=0;
	int cross2=0;
	int count=0;
	int tempcode=48-49;
	
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if (user[i][j]==tempcode)
			{
				rows++;
				if(rows==5)
				{
					count++;
				}
			}
			else 
			{
				rows=0;
			}
		}
	}
	
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{		
			if (user[j][i]==tempcode)
			{
				cols++;
				if(cols==5)
				{
					count++;
				}
			}
			else cols=0;
		}
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{			
			if(i==j&&user[i][j]==tempcode)
			{
				cross1++;
				if(cross1==5)
				{
					count++;
				}
			}
			else cross1=0;
		}
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{			
			if(i==j&&user[j][4-i]==tempcode)
			{
				cross2++;
				if(cross2==5)
				{
					count++;
				}
			}
			else cross2=0;
		}
	}

	return count;

}




	  
int main(int argc, char *argv[]) {
	
	int user[N][N];
	int com[N][N];

	int count;

	printf("��������� �����մϴ�. ");
	initiate_bingo(user,com);	
	
	print_bingo(user,com);
	
	while(count_bingo(user)<=4 &&count_bingo(user)<=4)
	{
		get_number_byMe(user,com);
	
		get_number_byCom(user,com);
		
			
		print_bingo(user,com);
		
		printf("���� ���� ���� : %d  ,  ��ǻ���� ���� ���� : %d \n \n",count_bingo(user), count_bingo(com));
	
	
	}
	
	
	

	
	

	return ;
}
