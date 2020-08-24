#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
	int D, K, A, B, i, j;
	int ricecake[30] = {0,};
	scanf("%d %d", &D, &K);

	ricecake[0] = 1; ricecake[1] = 1;
	for (i = 2; i < 30; i++) {
		ricecake[i] = ricecake[i - 1] + ricecake[i - 2];
	}

	for (A = 1; A < 100; A++) {
		for (B = A + 1; B < 100; B++) {
			if (ricecake[D - 3] * A + ricecake[D - 2] * B == K) {
				printf("%d\n%d", A, B);
				return 0;
			}
		}
	}

	return 0;
}