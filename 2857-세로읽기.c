#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)
{
	char array[5][15] = {NULL,};
	int i, j;

	for (i = 0; i < 5; i++)
	{
		scanf("%s", array[i]);
	}

	for (i = 0; i < 15; i++) {
		for (j = 0; j < 5; j++) {
			if (array[j][i] == NULL) continue;
			printf("%c", array[j][i]);
		}
	}

	return 0;
}