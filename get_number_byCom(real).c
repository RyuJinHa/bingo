#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int get_number_byCom(int (*user)[N],int (*com)[N])//컴퓨터가 임의로 빙고 번호 선택 
{	
	srand((unsigned)time(NULL));
	
	int i,j;
	int alreadynum;//중복된 숫자입력을 방지하기 위한 변수 
	int cominput;//컴퓨터에게 입력받을 변수  
	int tempcode=48-49;//tempcode는 선택된 숫자가 -1이라고 지정하는 변수
	

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
					user[i][j]=tempcode;//user가 입력한 값과 빙고칸에 들어 있던 값이 같으면 방고칸을 임시로 tempcode라고 저장한다.  
					alreadynum=1;//user가 입력한 값은 alreadynum=1이된다.  
				}
				if(com[i][j]==cominput)
				{
					com[i][j]=tempcode;//컴퓨터가 입력한 값과 빙고칸에 들어 있던 값이 같으면 방고칸을 임시로 tempcode라고 저장한다.
				}	
			}
		}
		if(alreadynum)
			break;
		} 
		
		printf("컴퓨터가 선택한 숫자입니다. : %d\n",cominput);	

	return cominput;

}
