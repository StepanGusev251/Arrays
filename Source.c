#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define N 50

double* full_elements(double* ptr_array, int n); // заполнение массива
double F(double x); // функция из 8 лаб 6 варианту
int put_elements(double* ptr_array, int n); //печать элементов массива
double* calc_elements(double* ptr_array, int n); //обработка элементов массива 11 лаб
int find_element(double* ptr_array, int n, double element); // найти элемент в массиве
int function(double* arr, int n, int k);
double sum_elements(double* ptr_array, int begin, int end);
int findDZ(double* arr, int n, double A);

int main() // вариант 1 (9%27+1)
{
	setlocale(LC_ALL, "RUS");

	double array[N];
	int size;
	int begin, end;
	int choice;
	double k;
	double arr, A, a;

	printf("Введите размер массива > ");
	scanf("%d", &size);

	double* ptr_array = &array;

	full_elements(array, size);
	put_elements(array, size);

	do {
		
		printf("\n1. Поменять знаки элементов на противоположные.\n2. Сумма элементов с первого введенного пользователем номера элемента по конечного введенного номера элемента\n3. Поиск элемента равного a (введенный пользователем)\n4. Поиск порядкового номера минимального значения элементов, кратных k.\n5. Поиск порядкового номера минимального значения элементов, больших заданного значения А.\n");
		printf("\nВведите команду: \n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			calc_elements(ptr_array, size);
			put_elements(array, size);
			break;

		case 2:
			printf("Введите начао и конец:\n");
			scanf("%d %d", &begin, &end);
			sum_elements(array, begin, end);
			printf("Результат %lf", sum_elements(array, begin, end));
			
			break;
		case 3:
			printf("\nВведите число, которое хотите найти в массиве и узнать его индекс: ");

			scanf("%lf", &a);
			ptr_array[5] = 3.; // для проверки работы массива, т к в массиве числа с большим кол-вом знаков после ,
			int i_in_arr = find_element(ptr_array, size, a);
			if (i_in_arr == -1)
			{
				puts("Элемент не найден");
			}
			else printf("\nЭлемент %.4g имеет индекс %d", a, i_in_arr);

			break;
			break;
		case 4:
			printf("Введите  значение k\n");
			scanf("%f", &k);

			arr = function(array, size, k);
			printf("Номер элемента - %d", arr);
			
			break;
		case 5:
			printf("Введите  значение A\n");
			scanf("%d ", &A);
			printf("Номер элемента - %d", findDZ(array, size, A));
			break;
		case 0:
			printf("Выход \n");
			break;
		default:
			printf("Неверный выбор!\n");
		}
	} while (choice != 0);
}


double F(double x)
{ 
	return pow(x, 3) - 4 * pow(x, 2) + 2;
}

double* full_elements(double* ptr_array, int n)
{
	double a = 1.;
	int i = 0;
	for (i = 0; i < n; i++) {
		ptr_array[i] = F(a);
		a += 0.1;
	}
	return ptr_array;
} // заполнение массива

int put_elements(double* ptr_array, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("Array[%d] = %.4f\n", i, (*ptr_array++));
		i++;
	}
	return 1;
}; // вывод массива

double* calc_elements(double* ptr_array, int n) // 6 вариант в ДЗ по 11 лаб. работ
{
	for (int i = 0; i < n; i++) {
		ptr_array[i] = -ptr_array[i];
	}
	return ptr_array;
};

double sum_elements(double* ptr_array, int begin, int end)
{

	double result = 0.;

	while (begin <= end)
	{
		result += ptr_array[begin];
		begin++;
	}

	return result;
}

int find_element(double* ptr_array, int n, double element)
{
	int num_el = -1;


	for (int i = 0; i<n; i++)
	{
		if (ptr_array[i] == element)
		{
			num_el = i;
		}
	}
	return num_el;
}

int function(double* arr, int n, double k) {
	if (n <= 0 || fabs(k) < 1e-12) return -1;

	int minIndex = -1;
	bool found = false;

	for (int i = 0; i < n; i++) {
		// Проверяем кратность через остаток от деления
		// arr[i] кратно k, если остаток от деления близок к нулю
		double remainder = fmod(arr[i], k);

		// Учитываем погрешность вычислений с double
		if (fabs(remainder) < 1e-9) {
			if (!found || arr[i] < arr[minIndex]) {
				minIndex = i;
				found = true;
			}
		}
	}

	return minIndex;
}
int findDZ(double* arr, int n, double A) {
	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > A && (idx == -1 || arr[i] < arr[idx])) {
			idx = i;
		}
	}
	return idx;
}