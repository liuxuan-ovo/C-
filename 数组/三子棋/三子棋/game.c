#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i = 0;i < ROW;i++)
	{
		for(j = 0;j < col;j++)
		{
			board[i][j] = ' '; 
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row,int col)
{
	int i = 0;
	for(i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//1����ӡһ�е�����
			printf(" %c ",board[i][j]);
			if (j < col -1)
				printf("|");
		}
		printf("\n");
		//2����ӡ�ݸ���
		if(i < row - 1)
		{
			for (j = 0;j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}


void PlayerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�>\n");
	while (1)
	{
		printf("������Ҫ�µ����꣺");
		scanf("%d %d",&x,&y);
		//�ж�x y�ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y<= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}
void ComputerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>\n");
	while (1)
	{
		x = rand()%row;
		y = rand()%col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//����1��ʾ�������ˣ�����0��ʾ����û��
int IsFull(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ') 
			{
				return 0;//û��
			}
		}
	}
	return 1;//����
}

char IsWin(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	//�жϺ���
	for(i = 0;i < row;i++)
	{
		for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//�ж�����
	for (i = 0; i < row - 2; i++)
	{
			for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}	
	}
	//�����Խ���
		for (i = 0; i < row - 2; i++)
	{
			for (j = 0; j < col - 2; j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
			else if (board[i +2][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i][j + 2] && board[i +1 ][j + 1] != ' ')
			{
				return board[i + 1][j + 1];
			}
		}	
	}
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board,ROW,COL))
	{
		return 'Q';
	}
	return 'C';
}
