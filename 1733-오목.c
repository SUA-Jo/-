#pragma warning(disable:4996)
#include <stdio.h>

void black(int** board);
void white(int** board);

int main(void)
{
	int board[19][19];
	int i, j, k;

	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			scanf("%d ", board[i][j]);
		}
		printf("\n");
	}

	black(board);
	white(board);

	return 0;
}

void black(int** board)
{
	int i,j, x = 0, index_i, index_j;
	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			while (board[i][j] == 1) {
				x++;
				if (x == 5) {
					index_i = i; index_j = j;
					printf("1\n%d %d", i - 1, j - 6);
					break;
				}
			}
			while (board[j][i] == 1) {
				x++;
				if (x == 5) {
					index_i = i; index_j = j;
					printf("1\n%d %d", j - 6, i - 1);
					break;
				}
			}
			while (board[i][j] == 1) {
				i++; j++;
				x++;
				if (x == 5) {
					index_i = i; index_j = j;
					printf("1\n%d %d", i - 6, j - 6);
					break;
				}
			}
			x = 0;
		}
	}
}

void white(int** board)
{
	int i, j, y = 0, index_i, index_j;
	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			while (board[i][j] == 2) {
				y++;
				if (y == 5) {
					index_i = i; index_j = j;
					printf("1\n%d %d", i - 1, j - 6);
					break;
				}
			}
			while (board[j][i] == 2) {
				y++;
				if (y == 5) {
					index_i = i; index_j = j;
					printf("1\n%d %d", j - 6, i - 1);
					break;
				}
			}
			while (board[i][j] == 2) {
				i++; j++;
				y++;
				if (y == 5) {
					index_i = i; index_j = j;
					printf("1\n%d %d", i - 6, j - 6);
					break;
				}
			}
			y = 0;
		}
	}
}