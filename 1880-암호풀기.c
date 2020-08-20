#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char key[27];
	scanf("%s%*c", key);

	char alphabet[27] = {NULL,};
	char num = 97;
	for (i = 0; i < 26; i++)
	{
		alphabet[i] = num;
		num++;
	}

	char secret[81] = {NULL,};
	gets_s(secret, 80);
	int len = strlen(secret);
	char* pch;
	
	for (i = 0; i < len; i++) {
		if (secret[i] == ' ') printf(" ");
		else {
			if ((pch = strchr(alphabet, secret[i])) != NULL) {
				printf("%c", key[*pch - 97]);
			}
			else {
				secret[i]=secret[i] + 32;
				pch = strchr(alphabet, secret[i]);
				printf("%c", key[*pch - 97] - 32);
			}
		}
	}

	return 0;
}