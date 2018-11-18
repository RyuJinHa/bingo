#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo(int (*user)[N],int (*com)[N])//빙고테이블을 초기에 만들어줌  
{
	int i,j;
	int temp, ROW1, ROW2, COL1, COL2;
	int change=100; 
	int count=1;//이차원배열을 차례대로 하기 위한 상수설정 
	
 	srand((unsigned)time(NULL));//난수 배열 


	//user :N*N 이차원배열을 차례대로 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			user[i][j]=count++;	
			
		}
	}

	//user: 2차원 배열 섞기 
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
	//computer :N*N 이차원배열을 차례대로 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			com[i][j]=count++;	
			
		}
	}

	//computer: 2차원 배열 섞기 
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
	
	//user의 빙고판  
	printf("--------------당신의 빙고판--------------\n\n");
	//빙고판을 보기 좋게 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(user[i][j]==45)
			{	
				printf(" | -1 ");
			}
		
			else
			{
				printf(" | %4d ", user[i][j]);
			}
		
		}
			printf("\n  \n");	
	}
	
	
	//computer의 빙고판  
	printf("--------------computer의 빙고판--------------\n\n");
	//빙고판을 보기 좋게 배열하기 
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(com[i][j]==45)
			{	
				printf(" | -1 ");
			}
		
			else
			{
				printf(" | %4d ", com[i][j]);
			}
		
		}
			printf("\n  \n");
	}
	printf("\n \n \n");
}



int get_number_byMe(int (*user)[N],int (*com)[N])//num은 숫자입력을 받기위한 변수
 
{
	int i,j,userinput;
	int alreadynum=0;
	int count;
	while(1)
	{
		printf("1~25까지의 숫자를 입력하세요: ");
		scanf("%i",&userinput);
		
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if (user[i][j]==userinput)
				user[i][j]=0;
				alreadynum=1;
	
			}
		if(alreadynum)
			break;
		else
			printf("이미 입력한 숫자입니다. 다른 숫자를 입력해주세요.: \n");
			
		}
		
		
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if (com[i][j]==userinput)
				{
					com[i][j]=0;
				}
			}
		}

	

}

}

int get_number_byCom(int (*user)[N],int (*com)[N])
{	
	srand((unsigned)time(NULL));
	int i,j;
	int alreadynum;
	int count;
	int cominput;
	
	
	

	while(1)
	{printf("컴퓨터의 차례입니다. "); 
		cominput=rand()%(N*N)+1;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if (user[i][j]==cominput)
				{
					user[i][j]=0;
					alreadynum=1;
				}
				if(com[i][j]==cominput)
				{
					com[i][j]=0;
				}	
			}
		}
		if(alreadynum)
			break;
		
	printf("컴퓨터가 선택한 숫자입니다. : %d",cominput);	
	}

	

}


void process_bingo(int user[N][N], int com[N][N])
{
	
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(user[i][j]==0)
			{
				user[i][j]=45;
			}
			break;
		}
	}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(com[i][j]==0)
			{
				com[i][j]=45;
			}
			break;
		}
	}
}


int count_bingo(int user[N][N])
{
	int i,j;
	int rows,cols,cross1,cross2=0;
	int count=0;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if (user[i][j]==45)
			{
				rows++;
			}
			if (user[j][i]==45)
			{
				cols++;
			}
			if(i==j&&user[i][j]==45)
			{
				cross1++;
			}
			if(i==j&&user[j][i]==45)
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
	
	return count;
}




	  
int main(int argc, char *argv[]) {
	
	int user[N][N];
	int com[N][N];

	int count;
	
	initiate_bingo(user,com);	
	
	print_bingo(user,com);
	
	while(count_bingo(user)<=4 && count_bingo(com)<=4)
	{
		get_number_byMe(user,com);
		get_number_byCom(user,com);
		print_bingo(user,com);
		printf("내 빙고 개수: %d \n computer의 빙고 개수: %d", count_bingo(user),count_bingo(com));
	}
	
	
	


	
	

	return ;
}
