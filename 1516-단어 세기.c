#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void)
{
	char array[30][200];
	int i, j = 0, k[30] = { 0, };		//k는 sArr에서 한 문장의 시작 index
	char* ptr;
	char* sArr[100] = { NULL, };
	int number[100] = { 0, };

	for (i = 0; i < 30; i++) {
		gets_s(array[i], 200);
		ptr = strtok(array[i], " ");
		while (ptr != NULL)
		{
			sArr[j] = ptr;
			int x = j;
			for (j = k[i]; j < x; j++) {
				if (sArr[j] != NULL && sArr[x] != NULL) {
					if (strcmp(sArr[j], sArr[x]) == 0) {
						number[j]++;
						sArr[x] = NULL;
					}
				}
			}
			number[j]++;
			j++;
			ptr = strtok(NULL, " ");
		}
		k[i+1] = j+1;
		if (strcmp(array[i], "END") == 0) break;
	}

	for (i = 0; i < 29; i++) {
		for (j = k[i]; j < k[i+1]; j++) {
			if (sArr[j] != NULL && sArr[j+1] != NULL) {
				if (strcmp(sArr[j], sArr[j + 1])>0) {
					char* tmp = sArr[j];
					sArr[j] = sArr[j + 1];
					sArr[j + 1] = tmp;

					int tmp1 = number[j];
					number[j] = number[j + 1];
					number[j + 1] = tmp1;
				}
			}
			else if (sArr[j + 1] == NULL && sArr[j]!=NULL) {
				int z = j + 2;
				while (sArr[z] == NULL) {
					z++;
				}
				if (z>= 99) break;
				else if (strcmp(sArr[j], sArr[z]) > 0) {
					char* tmp = sArr[j];
					sArr[j] = sArr[z];
					sArr[z] = tmp;

					int tmp1 = number[j];
					number[j] = number[z];
					number[z] = tmp1;
					j = z-1;
				}
				
			}
			if (sArr[j] == NULL || strcmp(sArr[j], "END") == 0) continue;
			printf("%s : %d\n", sArr[j], number[j]);
		}
	}

	return 0;
}