#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int get_number_byMe(int (*user)[N],int (*com)[N])//���� ���� ��ȣ �Է� ����  
 
{
	int i,j,userinput;//userinput�� �����Է��� �ޱ����� ����
	int alreadynum=0;//�ߺ��� �����Է��� �����ϱ� ���� ���� 
	int tempcode=48-49;//tempcode�� ���õ� ���ڰ� -1�̶�� �����ϴ� ���� 
	int turnnum=0;
		
		
		while(1)
		{	
			printf(" \n1~25������ ���ڸ� �Է��ϼ���: ");//user���� ���� �Է¹ޱ� 
			scanf("%i",&userinput);
			
			
			if(userinput>25||userinput<1)//user�� 1~25������ ���� �Է����� ���� ��� 
			{
				printf("\n1~25������ ���� �ƴմϴ�. �ٽ� �Է����ּ���: ");
				scanf("%i", &userinput); 
			}
		
			else(userinput>=1 &&userinput<=25);//1~25������ ���� �Է��� ��� 
			{
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						if (user[i][j]==userinput)
						{
						user[i][j]=tempcode;//user�� �Է��� ���� ����ĭ�� ��� �ִ� ���� ������ ���ĭ�� �ӽ÷� tempcode��� �����Ѵ�.  
						alreadynum=1;//user�� �Է��� ���� alreadynum=1�̵ȴ�.  
						
						}
					}
				}	
				for(i=0;i<N;i++)
				{
				for(j=0;j<N;j++)
				{
					if (userinput==com[i][j])
					{
						com[i][j]=tempcode;//��ǻ�Ͱ� �Է��� ���� ����ĭ�� ��� �ִ� ���� ������ ���ĭ�� �ӽ÷� tempcode��� �����Ѵ�.
					}
				}
			}
			if(alreadynum==1)//alreadynum�� 1�ΰ�� �� while������ �������´� . 
				break;
			else//alreadynum�� 0�ΰ�� �̹� �Է��� �����̹Ƿ� �ٽ� �Է°��� �޵��� �Ѵ�.  
			{
				printf("\n�̹� �Է��� �����Դϴ�. \n \n�ٽ� �Է����ּ��� \n");
			}
	 		} 
		}
		
return userinput;
}
