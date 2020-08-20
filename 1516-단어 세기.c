#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void)
{
	char array[30][201];
	int i, j = 0, k[30] = { 0, };		//k는 sArr에서 한 문장의 시작 index
	char* ptr;
	char* sArr[100] = { NULL, };
	int number[100] = { 0, };

	for (i = 0; i < 30; i++) {
		gets_s(array[i], 200);
		if (strcmp(array[i], "END") == 0) break;
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
		k[i+1] = j;
	}

	for (i = 0; i < 29; i++) {
		for (j = k[i]; j < k[i + 1]; j++) {
			for (int z = k[i]; z < k[i + 1] - 1; z++) {
				if (sArr[z] != NULL && sArr[z + 1] != NULL) {
					if (strcmp(sArr[z], sArr[z + 1]) > 0) {
						char* tmp = sArr[z];
						sArr[z] = sArr[z + 1];
						sArr[z + 1] = tmp;

						int tmp1 = number[z];
						number[z] = number[z + 1];
						number[z + 1] = tmp1;
					}
				}
				else if (sArr[z + 1] == NULL && sArr[z] != NULL) {
					int y = z + 2;
					while (sArr[y] == NULL) {
						y++;
					}
					if (y >= k[i+1]) break;
					else if (strcmp(sArr[z], sArr[y]) > 0) {
						char* tmp = sArr[z];
						sArr[z] = sArr[y];
						sArr[y] = tmp;

						int tmp1 = number[z];
						number[z] = number[y];
						number[y] = tmp1;
						z = y - 1;
					}
				}
			}
		}
	}

	for (i = 0; i < 100; i++) {
		if (sArr[i] == NULL || strcmp(sArr[i], "END") == 0) continue;
		printf("%s : %d\n", sArr[i], number[i]);
	}

	return 0;
}