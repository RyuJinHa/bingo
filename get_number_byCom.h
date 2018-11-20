#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int get_number_byCom(int (*user)[N],int (*com)[N])//컴퓨터가 임의로 빙고 번호 선택 
{	
	srand((unsigned)time(NULL));
	
	int i,j;
	int alreadynum;
	int cominput;//컴퓨터에게 입력받을 변수  
	int tempcode=48-49;
	

		printf("\n컴퓨터의 차례입니다.\n \n"); 
		cominput=rand()%(N*N)+1;
		
		while(1)
		{
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
		if(alreadynum)
			break;
		} 
		
		printf("컴퓨터가 선택한 숫자입니다. : %d\n",cominput);	

	return cominput;

}

