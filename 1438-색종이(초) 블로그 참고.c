#pragma warning(disable:4996)
#include <stdio.h>

int square(int x, int y);
int squ[100][100] = { 0, };

int main(void)
{
	int number,x, y, i, width = 0;

	scanf("%d", &number);
	while (number > 100) {
		printf("100������ ������ ���� �Է��Ͻÿ�.\n");
		scanf("%d", &number);
	}

	for (i = 0; i < number; i++)
	{
		scanf("%d %d", &x, &y);
		while (x > 90 || y > 90) {
			printf("90������ ���� �Է��Ͻÿ�.\n");
			scanf("%d %d", &x, &y);
		}
		width += square(x,y);
	}

	printf("%d", width);

	return 0;
}
int square(int x, int y)
{
	int i, j, w = 0;

	for (i = x; i < (x + 10); i++)
	{
		for (j = y; j < (y + 10); j++)
		{
			if (squ[i][j] == 0)
			{
				squ[i][j] = 1;
				w++;
			}
		}
	}

	return w;
}