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
	if (same_color == 5 && consecutive == 1) {	//��Ģ 1��
		printf("%d", number[4] + 900);
	}
	else if (same_color == 5) {					//��Ģ 4��
		printf("%d", number[4] + 600);
	}
	else if (consecutive == 1) {				//��Ģ 5��
		printf("%d", number[4] + 500);
	}
	else {
		same_card_number(number);

		if (same_number[0][1] == 4) {			//��Ģ 2��
			printf("%d", same_number[0][0] + 800);
		}
		else if (same_number[0][1] == 3) {		//��Ģ 3��
			if(same_number[1][1] == 2)
				printf("%d", same_number[0][0] * 10 + same_number[1][0] + 700);
			else		//��Ģ 6��
				printf("%d", same_number[0][0] + 400);
		}
		else if (same_number[0][1] == 2) {		//��Ģ 7��
			if (same_number[1][1]==2) {
				printf("%d", same_number[1][0] * 10 + same_number[0][0] + 300);
			}
			else {								//��Ģ 8��
				printf("%d", same_number[0][0] + 200);
			}
		}
		else {									//��Ģ 9��
			printf("%d", number[4] + 100);
		}
	}


	return 0;
}

int same_card_color(char* color)		//ī���� ���� ��� ���� ���ΰ�?
{
	int i, a=1;
	for (i = 1; i < 5; i++) {
		if (color[0] != color[i]) continue;
		a++;
	}

	return a;							//��� ������ 5�� ��ȯ
}

int sequence(int* number)				//ī���� ���ڰ� �������ΰ�?
{
	int i, j, x=1;

	for (i = 0; i < 4; i++) {
		if (number[i + 1] == number[i] + 1) {
			x++;
		}
	}

	if (x == 5) return 1;		//�����̸� 1�� ��ȯ
	else return 0;				//�ҿ����̸� 0�� ��ȯ
}

void same_card_number(int* number)		//ī���� ���ڰ� �����Ѱ�?
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