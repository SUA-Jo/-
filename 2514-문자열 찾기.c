#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int main(void)
{
	char alphabet[10001] = { NULL, };
	scanf("%s", alphabet);
	int len = strlen(alphabet);
	int i;

	for (i = 0; i < len; i++) {
		if (alphabet[i] < 'A' || alphabet[i]>'Z') {
			printf("대문자 알파벳만 입력하시오.\n");
			scanf("%s", alphabet);
			i = 0;
		}
	}

	int KOI=0, IOI=0;
	i = 0;

	while (alphabet[i+2] != NULL)
	{
		if (alphabet[i] == 'K' && alphabet[i + 1] == 'O' && alphabet[i + 2] == 'I') {
			KOI++;
		 }
		else if (alphabet[i] == 'I' && alphabet[i + 1] == 'O' && alphabet[i + 2] == 'I') {
			IOI++;
		}
		i++;
	}
	
	printf("%d\n%d", KOI, IOI);

	return 0;
}