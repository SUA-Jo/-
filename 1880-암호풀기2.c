#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i,j;
	char key[27];
	scanf("%s%*c", key);

	char alphabet[27] = { NULL, };
	char num = 97;
	for (i = 0; i < 26; i++)
	{
		alphabet[i] = num;
		num++;
	}

	char secret[81] = { NULL, };
	gets_s(secret, 80);
	int len = strlen(secret);

	for (i = 0; i < len; i++) {
		if (secret[i] == ' ') printf(" ");
		for (j = 0; j < 26; j++) {
			if (secret[i] == alphabet[j]) {
				printf("%c", key[j]);
			}
			else if (secret[i]==alphabet[j]-32) {
				printf("%c", key[j] - 32);
			}
		}
	}

	return 0;
}