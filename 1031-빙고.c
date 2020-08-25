#pragma warning(disable:4996)
#include <stdio.h>

int bingo[5][5];
int count=0;

void function(int x, int y);

int main(void)
{	
	int call_bingo[5][5];
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf(" %d", &bingo[i][j]);
		}
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf(" %d", &call_bingo[i][j]);
		}
	}

	int x = 0, y = 0;
	while (count<3) {
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				if (call_bingo[x][y] == bingo[i][j]) {
					bingo[i][j] = 0;
					function(i,j);
					if (count >= 3) break;
					if (y == 4) {
						x++; y = 0;
					}
					else y++;
					i = 0; j = -1;
				}
			}
			if (count >= 3) break;
		}
	}

	printf("%d", x *5 + (y + 1));

	return 0;
}

void function(int x, int y)
{
	int i, j, a = 0;
	for (i = 0; i < 5; i++) {		//°¡·Îºù°í
		if (bingo[x][i] == 0)
			a++;
	}
	if (a == 5) {
		count++;
	}
	a = 0;
	for (i = 0; i < 5; i++) {		//¼¼·Îºù°í
		if (bingo[i][y] == 0) {
			a++;
		}
	}
	if (a == 5) {
		count++;
	}
	a = 0;
	if (x == y) {					//¿À¸¥ÂÊ À§¿¡¼­ ¿ÞÂÊ ¾Æ·¡ ºù°í
		for (i = 0, j = 0; i < 5 && j < 5; i++, j++) {
			if (bingo[i][j] == 0) {
				a++;
			}
		}
		if (a == 5) {
			count++;
		}
	}
	a = 0;
	if (x + y == 4) {				//¿ÞÂÊ À§¿¡¼­ ¿À¸¥ÂÊ ¾Æ·¡ ºù°í
		for (i = 0, j = 4; i < 5 && j >= 0; i++, j--) {
			if (bingo[i][j] == 0) a++;
		}
		if (a == 5) count++;
	}
}