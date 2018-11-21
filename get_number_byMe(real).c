#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int get_number_byMe(int (*user)[N],int (*com)[N])//내가 빙고 번호 입력 선택  
 
{
	int i,j,userinput;//userinput은 숫자입력을 받기위한 변수
	int alreadynum=0;//중복된 숫자입력을 방지하기 위한 변수 
	int tempcode=48-49;//tempcode는 선택된 숫자가 -1이라고 지정하는 변수 
	int turnnum=0;
		
		
		while(1)
		{	
			printf(" \n1~25까지의 숫자를 입력하세요: ");//user에게 숫자 입력받기 
			scanf("%i",&userinput);
			
			
			if(userinput>25||userinput<1)//user가 1~25사이의 값을 입력하지 않은 경우 
			{
				printf("\n1~25사이의 값이 아닙니다. 다시 입력해주세요: ");
				scanf("%i", &userinput); 
			}
		
			else(userinput>=1 &&userinput<=25);//1~25사이의 값을 입력한 경우 
			{
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						if (user[i][j]==userinput)
						{
						user[i][j]=tempcode;//user가 입력한 값과 빙고칸에 들어 있던 값이 같으면 방고칸을 임시로 tempcode라고 저장한다.  
						alreadynum=1;//user가 입력한 값은 alreadynum=1이된다.  
						
						}
					}
				}	
				for(i=0;i<N;i++)
				{
				for(j=0;j<N;j++)
				{
					if (userinput==com[i][j])
					{
						com[i][j]=tempcode;//컴퓨터가 입력한 값과 빙고칸에 들어 있던 값이 같으면 방고칸을 임시로 tempcode라고 저장한다.
					}
				}
			}
			if(alreadynum==1)//alreadynum이 1인경우 이 while문에서 빠져나온다 . 
				break;
			else//alreadynum이 0인경우 이미 입력한 숫자이므로 다시 입력값을 받도록 한다.  
			{
				printf("\n이미 입력한 숫자입니다. \n \n다시 입력해주세요 \n");
			}
	 		} 
		}
		
return userinput;
}
