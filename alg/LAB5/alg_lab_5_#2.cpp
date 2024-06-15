
#include <stdio.h>  
#include <conio.h>  
#include <math.h>  
#include <locale.h>


void integer(int x1) // перевод целочисленного типа данных в бинарную систему
{
	setlocale(LC_ALL, "Russian");
	int i, b;
	long c = 0;
	for (i = 0; x1 > 0; i++)
	{
		b = x1 % 2;
		x1 = (x1 - b) / 2;
		c += b * pow(10, i);
	}

	printf("\nДвоичное число: %d", c);
}

float real(void) // перевод дробной части числа
{
		setlocale(LC_ALL, "Russian");
			float x2; // первоначальное дробное число

			printf("Введите вещественное число 0<x<1: \n");
			scanf_s("%f", &x2);
			printf("Двоичное число: 0.");
			for (int i = 0; i < 24; i++)
			{
				x2 *= 2;
				int t = x2; // здесь хранится целая часть x2
				printf("%d", t);
				x2 = x2 - t;
				if (x2 <= 1e-8) // количество чисел после запятой
					break;
			}
			printf("\n");
		return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	printf("Введите целое число:");
	scanf_s("%d", &a);
	integer(a);
	_getch();
	printf("\n");
	real();
	_getch();
}