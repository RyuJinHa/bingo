#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int initiate_bingo(int form[N-1][N-1])//�������� ����:form 
{
	int i,j;
	int k;
 	srand((unsigned)time(NULL));//���� �迭 
	

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
	
			form[i][j]=rand() % (N*N)+1;
		}
	}
	
	for(i=0;i<N;i++)	
	{
		for(j=0;j<N;j++)
		{
			printf("  %i", form[i][j]);
			
		}
			printf("\n \n");
	}
	printf("\n");

return ;
}

int get_number_byMe(int num)//num�� �����Է��� �ޱ����� ����
 
{
	printf("���ڸ� �Է��ϼ���: ");
	scanf("%i",&num);
	
}



	  
int main(int argc, char *argv[]) {
	
	int form[N-1][N-1];
	printf("��������� �����մϴ�.\n ");
	printf(" %i",initiate_bingo(form));
	
	return ;
}
