#pragma warning(disable:4996)
#include <stdio.h>

int same_card_color(char* color);
int sequence(int* number);
void same_card_number(int* number);

int main(void)
{
	char color[5];
	int number[5], i,j;

	for (i = 0; i < 5; i++) {
		scanf("%c %d\n", &color[i], &number[i]);
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5 - 1; j++) {
			if (number[j] > number[j + 1]) {
				int tmp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = tmp;
			}
		}
	}

	int same_color = same_card_color(color);
	int consecutive = sequence(number);
	if (same_color == 5 && consecutive == 1) {		//1번
		printf("%d", number[4] + 900);
	}
	
}

int same_card_color(char* color)		//카드의 색이 모두 같은 색인가?
{
	int i, a=1;
	for (i = 1; i < 5; i++) {
		if (color[0] != color[i]) continue;
		a++;
	}

	return a;							//모두 같으면 5를 반환
}

int sequence(int* number)				//카드의 숫자가 연속적인가?
{
	int i, j, x=1;

	for (i = 0; i < 4; i++) {
		if (number[i + 1] == number[i] + 1) {
			x++;
		}
	}

	if (x == 5) return 1;		//연속이면 1을 반환
	else return 0;				//불연속이면 0을 반환
}

void same_card_number(int* number)
{

}