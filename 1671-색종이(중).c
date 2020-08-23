#pragma warning(disable:4996)
#include <stdio.h>

int all[102][102] = { 0, };
int line(void);
int countf(int x, int y);

int main()
{
	int i,j, k, number, x, y;
	scanf("%d", &number);
	while (number > 100) {
		printf("100이하의 색종이 수를 입력하시오.\n");
		scanf("%d", &number);
	}

	for (i = 0; i < number; i++) {
		scanf("%d %d", &x, &y);
		for (j = x+1; j < x + 11; j++) {
			for (k = y+1; k < y + 11; k++) {
				all[j][k] = 1;
			}
		}
	}

	int sum=line();

	printf("%d", sum);

	return 0;
}

int line(void)
{
	int i, j,sum=0;
	for (i = 1; i < 101; i++) {
		for (j = 1; j < 101; j++) {
			if (all[i][j] == 1) {
				sum += countf(i, j);
			}
		}
	}
	return sum;
}

int countf(int x, int y)
{
	int cnt = 0;
	if (all[x][y + 1] == 0) cnt++;
	if (all[x][y - 1] == 0) cnt++;
	if (all[x + 1][y] == 0) cnt++;
	if (all[x - 1][y] == 0) cnt++;

	return cnt;
}