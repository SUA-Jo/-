#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int main(void)
{
	char plate[51] = { NULL, };
	int i=0, sum = 10;
	scanf("%s", plate);
	int len = strlen(plate);

	for (i = 0; i < len; i++) {
		if (plate[i] != '(' && plate[i] !=')') {
			printf("( 또는 )만 입력하시오.\n");
			scanf("%s", plate);
			i = 0;
		}
	}

	i = 0;
	while(plate[i+1]!=NULL)
	{
		if (plate[i] != plate[i + 1]) sum += 10;
		else sum += 5;
		i++;
	}

	printf("%d", sum);

	return 0;
}