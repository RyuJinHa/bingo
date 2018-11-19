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
	int count=1;//�������迭�� ���ʴ�� �ϱ� ���� ������� 
	
 	srand((unsigned)time(NULL));//���� �迭 


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
	
	count=1;
	//computer :N*N �������迭�� ���ʴ�� �迭�ϱ� 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			com[i][j]=count++;	
			
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
				printf(" |   -1 ");
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
				printf(" |   -1 ");
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
	
		printf("����� �����Դϴ�. \n \n1~25������ ���ڸ� �Է��ϼ���: ");
		scanf("%i",&userinput);
		
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if (user[i][j]==userinput)
				{
				user[i][j]=tempcode;
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
return;
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
	

	return;

}




int user_count_bingo(int (*user)[N])
{
	int i,j;
	int rows,cols,cross1,cross2=0;
	int count=0;
	int tempcode=48-49;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if (user[i][j]==tempcode)
			{
				rows++;
			}
			if (user[j][i]==tempcode)
			{
				cols++;
			}
			if(i==j&&user[i][j]==tempcode)
			{
				cross1++;
			}
			if(i==j&&user[j][i]==tempcode)
			{
				cross2++;
			}
		}
	
	}
	if(rows==5)
	{
		count++;
	}
	if(cols==5)
	{
		count++;
	}
	if(cross1==5)
	{
		count++;
	}
	if(cross2==5)
	{
		count++;
	}
	
	printf("\n����� ������ ���� : %d \n \n",count);
	
	return count;

}

int com_count_bingo(int (*com)[N])
{
	int i,j;
	int rows,cols,cross1,cross2=0;
	int count=0;
	int tempcode=48-49;
	//���κ����� ����  
	for(i=0;i<N;i++)
	{	 
	for(j=0;j<N;j++)
		{
			if (com[i][j]==tempcode)
			{
				rows++;
				
				if(rows==5)
				{
					count++;
				}	
			}
		}	
	}
	
		
	//���κ���������  
	for(i=0;i<N;i++)
	{	
	for(j=0;j<N;j++)
		{
			if (com[i][j]==tempcode)
			{
				cols++;
				
				if(cols==5)
				{
					count++;
				}	
			}
		}
	}
	//�밢������������ 		
	for(i=0;i<N;i++)
	{
	for(j=0;j<N;j++)	
		{
			if(i==j&&com[i][j]==tempcode)
			{
				cross1++;
			}
			if(cross1==5)
			{
				count++;
			}
		}	
	}
	//�밢��2����������  
	for(i=0;i<N;i++)
	{	 
	for(j=0;j<N;j++)			
		{
			if(i==j&&com[j][i]==tempcode)
			{
				cross2++;
			}
			if(cross2==5)
			{
				count++;
			}
			
		}

	}

	
	printf("\ncomputer�� ������ ���� : %d \n \n",count);
	
	return count;


}



	  
int main(int argc, char *argv[]) {
	
	int user[N][N];
	int com[N][N];

	int count;

	printf("��������� �����մϴ�. ");
	initiate_bingo(user,com);	
	
	print_bingo(user,com);
	
	while(user_count_bingo(user)<=4 && com_count_bingo(user)<=4)
	{
		get_number_byMe(user,com);
	
		get_number_byCom(user,com);
		user_count_bingo(user);
		com_count_bingo(com);
			
		print_bingo(user,com);
		
		
	
	}
	
	
	

	
	

	return ;
}
