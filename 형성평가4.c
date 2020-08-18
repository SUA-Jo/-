#include <stdio.h>

int main(void)
{
	printf("kor 90\n");
	printf("mat 80\n");
	printf("eng 100\n");

	int sum, avg;
	sum = 90 + 80 + 100;
	avg = (90 + 80 + 100) / 3;

	printf("sum %d\n", sum);
	printf("avg %d", avg);

	return 0;
}