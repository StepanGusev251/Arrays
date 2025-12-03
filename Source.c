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
double F1(double x); // функция из 8 лаб 6 варианту
int put_elements(double* ptr_array, int n); //печать элементов массива
double calc_elements(double* ptr_array, int n); //обработка элементов массива 11 лаб
int find_element(double* ptr_array, int n, double element); // найти элемент в массиве
int findMinMultipleIndex(double* arr, int n, int k); // ДЗ

//функции для зад. 2
double sum_elements(double* ptr_array, int begin, int end);

int main() // вариант 1 (9%27+1)
{
	setlocale(LC_ALL, "RUS");

	double array[N];
	int size;
	int begin, end;
	double element;
	int i_in_arr; // для нахождения эл. в массиве
	int choice;
	double max;

	printf("Введите размер массива > ");
	scanf("%d", &size);

	double* ptr_array = &array;

	if (full_elements(ptr_array, size) == ptr_array) {
		puts("Массив array успешно заполнен значениями.\n");
	};

	if (put_elements(ptr_array, size)) {
		puts("\nМассив array успешно выведен в консоль\n");
	};
	double sr = calc_elements(ptr_array, size);
	if (sr) {
		printf("В массиве array успешно найдено среднее между отрицательными числами %.4g\n", sr);
	}
	else printf("В массиве array успешно найдено среднее между отрицательными числами %.4g\n", sr);


	printf("\nВыберите следующее действие:\n 1. Сумма элементов массива с начального (первое введённое число) по конечное значение (ввести 1)\n 2. Поиск числа в массиве и узнать его индекс (ввести 2)\n 3. Поиск порядкового номера минимального значения элементов, кратных k. ");

	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\nСумма элементов массива с начального (первое введённое число) по конечное значение: ");
		scanf("%d %d", &begin, &end);

		printf("Сумма элементов c индекса %d по индекс %d: %.4g\n", begin, end, sum_elements(ptr_array, begin, end));
		break;
	case 2:
		printf("\nВведите число, которое хотите найти в массиве и узнать его индекс: ");

		scanf("%lf", &element);
		ptr_array[5] = 5.; // для проверки работы массива, т к в массиве числа с большим кол-вом знаков после ,
		i_in_arr = find_element(ptr_array, size, element);
		if (i_in_arr == -1)
		{
			puts("Элемент не найден(");
		}
		else printf("\nЭлемент %.4g имеет индекс %d", element, i_in_arr);

		break;

		
	default: puts("Введено что-то не то");
		break;
	}

	return 0;
}

double F1(double x)
{ /*
  Принимает занчение и по функции возвращает рез-т
  */
	return pow(x, 3) - 4 * pow(x, 2) + 2;
}

double* full_elements(double* ptr_array, int n)
{/*
 ptr_array - указатель на массив
 n - размер массива
 */
	double a = 2.;
	int i = 0;
	while (i < n)
	{
		a += 0.02;
		ptr_array[i] = F1(a);
		i++;
	}
	return ptr_array;
} // заполнение массива

int put_elements(double* ptr_array, int n)
{/*
 ptr_array - указатель на массив
 n - размер массива
 */
	int i = 0;
	while (i < n)
	{
		printf("Array[%d] = %.4f\n", i, (*ptr_array++)); // разадресация 
		i++;
	}
	return 1;
}; // вывод массива

double calc_elements(double* ptr_array, int n) // 6 вариант в ДЗ по 11 лаб. работ
{
	
	int a[100];
	int i;
	int neg1 = -1, neg2 = -1;
	int sum = 0, count = 0;

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// Поиск двух отрицательных элементов в одном цикле
	for (i = 0; i < n; i++) {
		if (a[i] < 0) {
			if (neg1 == -1) {
				neg1 = i;      // Первый отрицательный
			}
			else {
				neg2 = i;      // Второй отрицательный
				break;         // Выходим из цикла
			}
		}
	}

	// Вычисление среднего

	for (i = neg1 + 1; i < neg2; i++) {
		sum += a[i];
		count++;
	}
	return (float)sum / count;
};

double sum_elements(double* ptr_array, int begin, int end)
{/*
 ptr_array - указатель на массив
 begin - индекс начального эл. массива
 end - индекс конечного эл. массива
 возвращает сумму элементов от begin до end
 */

	double result = 0.;

	while (begin <= end)
	{
		result += ptr_array[begin];
		begin++;
	}

	return result;
}

int find_element(double* ptr_array, int n, double element)
{/*
 ptr_array - указатель на массив
 n - размер массива
 element - значение, которое ищется в массиве
 возвращает индекс последнего найденного элемента в массиве = element
 */
	int i_min = -1;

	for (int i = 0; n > i; i++)
	{
		if (ptr_array[i] == element)
		{
			i_min = i;
		}
	}
	return i_min;
}

int findMinMultipleIndex(double* arr, int n, int k) {
	if (k == 0) return -1; // Защита от деления на ноль

	int minIndex = -1;

	for (int i = 0; i < n; i++) {
		// Проверяем кратность (сравниваем остаток с машинным нулем)
		if (fabs(fmod(arr[i], k)) < 1e-12) {
			if (minIndex == -1 || arr[i] < arr[minIndex]) {
				minIndex = i;
			}
		}
	}

	return minIndex;
}