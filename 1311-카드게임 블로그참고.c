#pragma warning(disable:4996)
#include <stdio.h>

int same_number[4][2] = { 0, };

int same_card_color(char* color);
int sequence(int* number);
void same_card_number(int* number);

int main(void)
{
	char color[5];
	int number[5], i,j;

	for (i = 0; i < 5; i++) {
		scanf(" %c %d", &color[i], &number[i]);
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5 - 1; j++) {
			if (number[j] > number[j + 1]) {
				int tmp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = tmp;

				char tmp1 = color[j];
				color[j] = color[j + 1];
				color[j + 1] = tmp1;
			}
		}
	}

	int same_color = same_card_color(color);
	int consecutive = sequence(number);
	if (same_color == 5 && consecutive == 1) {	//규칙 1번
		printf("%d", number[4] + 900);
	}
	else if (same_color == 5) {					//규칙 4번
		printf("%d", number[4] + 600);
	}
	else if (consecutive == 1) {				//규칙 5번
		printf("%d", number[4] + 500);
	}
	else {
		same_card_number(number);

		if (same_number[0][1] == 4) {			//규칙 2번
			printf("%d", same_number[0][0] + 800);
		}
		else if (same_number[0][1] == 3) {		//규칙 3번
			if(same_number[1][1] == 2)
				printf("%d", same_number[0][0] * 10 + same_number[1][0] + 700);
			else		//규칙 6번
				printf("%d", same_number[0][0] + 400);
		}
		else if (same_number[0][1] == 2) {		//규칙 7번
			if (same_number[1][1]==2) {
				printf("%d", same_number[1][0] * 10 + same_number[0][0] + 300);
			}
			else {								//규칙 8번
				printf("%d", same_number[0][0] + 200);
			}
		}
		else {									//규칙 9번
			printf("%d", number[4] + 100);
		}
	}


	return 0;
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

void same_card_number(int* number)		//카드의 숫자가 동일한가?
{
	int i, j, a = 0, tmp;
	for (i = 0; i < 5;) {
		same_number[a][0] = number[i];
		same_number[a][1] = 1;
		for (j = i + 1; j < 5; j++) {
			if (number[i] == number[j])
				same_number[a][1]++;
			else {
				i = j; a++; break;
			}
		}
		if (a > 3 || j > 4) break;
	}
	for (i = 0; i < 3; i++) {
		for (j = i + 1; j < 4; j++) {
			if (same_number[i][1] < same_number[j][1]) {
				tmp = same_number[i][0];
				same_number[i][0] = same_number[j][0];
				same_number[j][0] = tmp;

				tmp = same_number[i][1];
				same_number[i][1] = same_number[j][1];
				same_number[j][1] = tmp;
			}
		}
	}
}