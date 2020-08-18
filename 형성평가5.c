#include <stdio.h>

int main(void)
{
	char seoul[] = "Seoul";
	char seoul_2[] = "10,312,545";
	char seoul_3[] = "+91,375";
	char pusan[] = "Pusan";
	char pusan_2[] = "3,567,910";
	char pusan_3[] = "+5,868";
	char incheon[] = "Incheon";
	char incheon_2[] = "2,758,296";
	char incheon_3[] = "+64,888";
	char daegu[] = "Daegu";
	char daegu_2[] = "2,511,676";
	char daegu_3[] = "+17,230";
	char gwangju[] = "Gwangju";
	char gwangju_2[] = "1,454,636";
	char gwangju_3[] = "+29,774";

	printf("%15s%15s%15s\n", seoul, seoul_2, seoul_3);
	printf("%15s%15s%15s\n", pusan, pusan_2, pusan_3);
	printf("%15s%15s%15s\n", incheon, incheon_2, incheon_3);
	printf("%15s%15s%15s\n", daegu, daegu_2, daegu_3);
	printf("%15s%15s%15s\n", gwangju, gwangju_2, gwangju_3);

	return 0;
}