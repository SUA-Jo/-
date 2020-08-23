#pragma warning(disable:4996)
#include <stdio.h>

int board[19][19];
int win, win_x, win_y;

void search(void);			//������� ���������� ã��
int go(int x, int y);		//���� ���� �밢��

int main(void)
{
	int i, j;

	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	search();

	printf("%d\n", win);
	if (win != 0) {
		printf("%d %d", win_x, win_y);
	}

	return 0;
}

void search()
{
	int i, j, a;
	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			if (i > 14 && j > 14) break;
			if (board[i][j] != 0) {
				a = go(i, j);
				if (a != 0) {
					win = a; win_x=i+1; win_y=j+1;
				}
			}
		}
	}
}

int go(int x, int y)
{
	int i, j, h, a = 0;
	h = board[x][y];
	for (i = x + 1; i < x + 5 && i < 19; i++) {		//���η� 5��
		if (board[i][y] != h) break;				//���� ���� �ƴϸ�
		a++;
	}
	if (a == 4) {									//5�� �������̸�
		if (board[x+5][y] != h && board[x-1][y]!=h) return h;			//�������� �ƴϸ� ���� ��ȯ
	}
	a = 0;
	for (i = y + 1; i < y + 5 && i < 19; i++) {		//���η� 5��
		if (board[x][i] != h) break;
		a++;
	}
	if (a == 4) {
		if (board[x][y+5] != h && board[x][y-1]!=h) return h;
	}
	a = 0;
	for (i = x + 1, j = y + 1; i < x + 5 && j < y + 5 && i < 19 && j < 19; i++, j++) {		//������ �Ʒ� ���� �밢��
		if (board[i][j] != h) break;
		a++;
	}
	if (a == 4) {
		if (board[x+5][y+5] != h && board[x-1][y-1]!=h) return h;
	}
	a = 0;
	for (i = x - 1, j = y + 1; i > x - 5 && j < y + 5 && i >= 0 && j < 19; i--, j++) {		//������ �� ���� �밢��
		if (board[i][j] != h) break;
		a++;
	}
	if (a == 4) {
		if (board[x - 5][y + 5] != h && board[x+1][y-1]!=h) return h;
	}
	return 0;
}