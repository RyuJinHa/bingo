#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int get_number_byCom(int (*user)[N],int (*com)[N])//��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
{	
	srand((unsigned)time(NULL));
	
	int i,j;
	int alreadynum;
	int cominput;//��ǻ�Ϳ��� �Է¹��� ����  
	int tempcode=48-49;
	

		printf("\n��ǻ���� �����Դϴ�.\n \n"); 
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
		
		printf("��ǻ�Ͱ� ������ �����Դϴ�. : %d\n",cominput);	

	return cominput;

}

