#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>

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
}

int put_elements(double* ptr_array, int n)
{
    int i = 0;
    while (i < n)
    {
        printf("Array[%d] = %.4lf\n", i, (*ptr_array++));
        i++;
    }
    return 1;
}

double* calc_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++) {
        ptr_array[i] = -ptr_array[i];
    }
    return ptr_array;
}

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

    for (int i = 0; i < n; i++)
    {
        if (fabs(ptr_array[i] - element) < 1e-9)
        {
            num_el = i;
            break; // Нашли первое вхождение - выходим
        }
    }
    return num_el;
}

int function(double* arr, int n, double k) {
    if (n <= 0 || fabs(k) < 1e-12) return -1;

    int minIndex = -1;
    int found = 0;  // Заменяем bool на int (0 = false, 1 = true)

    for (int i = 0; i < n; i++) {
        double remainder = fmod(arr[i], k);

        if (fabs(remainder) < 1e-9) {
            if (!found || arr[i] < arr[minIndex]) {
                minIndex = i;
                found = 1;
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

double* rand_full_elements(double* ptr_array, int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        ptr_array[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    return ptr_array;
}

double* insert(double* ptr_arr, int size) {
    int size_n = size + 1;

    double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));
    if (ptr_arr_n == NULL) {
        printf("Ошибка перевыделения памяти\n");
        return ptr_arr;
    }

    srand(time(NULL));
    int i_rand = rand() % size_n;

    for (int i = size_n - 1; i > i_rand; i--)
    {
        ptr_arr_n[i] = ptr_arr_n[i - 1];
    }

    ptr_arr_n[i_rand] = -999.0;

    return ptr_arr_n;
}