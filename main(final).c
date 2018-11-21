#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initiate_bingo(real).h"
#include "print_bingo(real).h"
#include "count_bingo(real).h"
#include "get_number_byMe(real).h"
#include "get_number_byCom(real).h"
#define N 5
#define winner 5
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	
	int user[N][N];//user�� ����迭  
	int com[N][N];//computer�� ����迭  
	int turnnum=0;//���° �������� �˰��ϱ� ���� ����  
	int count;

	printf("��������� �����մϴ�. ");
	
	initiate_bingo(user,com);//�������̺��� �ʱ⿡ �������	
	
	print_bingo(user,com);//���� ���̺� ���� ��Ȳ�� ȭ�鿡 ���  
	
	while(count_bingo(user)<=N-1 &&count_bingo(com)<=N-1)
	{
	
		get_number_byMe(user,com);//���� ���� ��ȣ �Է� ����
		get_number_byCom(user,com);//��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ����
		print_bingo(user,com);//���� ���̺� ���� ��Ȳ�� ȭ�鿡 ��� 
		count_bingo(user);//user�� ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ
		count_bingo(com);//computer�� ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
		turnnum++;//while���� �ݺ��Ҷ�����  turnnum�� �������� ���? �������� �˰��Ѵ�.  
		printf("%d ��° ���Դϴ�. \n\n", turnnum);
		printf("���� ���� ���� : %d  ,  ��ǻ���� ���� ���� : %d \n \n",count_bingo(user), count_bingo(com));
		 
		if(count_bingo(user)>=winner||count_bingo(com)>=winner)//�������� N�� �̻��� ��� ��������� ���̳���.  
		{
			if(count_bingo(user)>=winner)
			{	
				printf("�����մϴ�. %d�� °�� ��������� �̰���ϴ�. ",turnnum);
			}
			if(count_bingo(com)>=winner) 
			{
				printf(" ��Ÿ���׿�. computer�� %d�� °�� ��������� �̰���ϴ�. ",turnnum);
			}
		} 			
	}

	return ;
}
