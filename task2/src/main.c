#include <stdio.h>

int iteration(int number, int degree)
{
	int rez = 1;
	if (degree < 0) {
		printf("Степень меньше нуля, так что вам БАН");
		return 0;
	}
	if (degree > 0) {
		for(int i = 0; i < degree; i++) {
			rez *= number;
		}
	return rez;
	} else return 1;
}

int recursion(int number, int degree)
{
	if (degree < 0) {
		printf("Степень меньше нуля, так что вам БАН");
		return 0;
	}
	if (degree > 0) {
		return number*recursion(number, degree - 1);
	} else return 1;
}

int main()
{
	int number;
	int degree;
	int rez;
	printf("Введіть чило:\n");
	scanf("%d", &number);
	printf("Введіть степінь:\n");
	scanf("%d", &degree);
	int key;
	printf("Введіть ключ режиму(0 - рекурсивний метод, 1 - ітераційний метод):\n");
	scanf("%d", &key);
	if (key == 0) {
		rez = recursion(number, degree);
	}
	if (key == 1) {
		rez = iteration(number, degree);
	}
	printf("number в степени degree:\n%d", rez);
	
	return 0;
}