#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>  // для типа bool

#define N 50



int main()
{
    setlocale(LC_ALL, "RUS");

    int choice;

    printf("1. Лабораторная работа 14\n");
    printf("2. Лабораторная работа 16\n");
    printf("Выберите лабораторную работу: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        lab_14();
        break;
    case 2:
        lab_16();
        break;
    default:
        printf("Неверный выбор!\n");
    }

    return 0;
}

int lab_14()
{
    double array[N];
    int size;
    int begin, end;
    int choice;
    double k;
    double a;
    double A;
    int result;

    printf("Введите размер массива > ");
    scanf("%d", &size);

    if (size > N) {
        printf("Размер массива не должен превышать %d\n", N);
        return -1;
    }

    double* ptr_array = array;

    full_elements(array, size);
    put_elements(array, size);

    while (1) {
        printf("\n1. Поменять знаки элементов на противоположные.\n");
        printf("2. Сумма элементов с первого введенного пользователем номера элемента по конечного введенного номера элемента\n");
        printf("3. Поиск элемента равного a (введенный пользователем)\n");
        printf("4. Поиск порядкового номера минимального значения элементов, кратных k.\n");
        printf("5. Поиск порядкового номера минимального значения элементов, больших заданного значения А.\n");
        printf("0. Выход\n");
        printf("\nВведите команду: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            calc_elements(ptr_array, size);
            put_elements(array, size);
            break;

        case 2:
            printf("Введите начало и конец:\n");
            scanf("%d %d", &begin, &end);
            if (begin < 0 || end >= size || begin > end) {
                printf("Некорректные индексы!\n");
            }
            else {
                printf("Результат %lf\n", sum_elements(array, begin, end));
            }
            break;

        case 3:
            printf("\nВведите число, которое хотите найти в массиве и узнать его индекс: ");
            scanf("%lf", &a);

            // Для проверки работы поиска добавляем известное значение
            if (size > 5) array[5] = 3.0;

            int i_in_arr = find_element(ptr_array, size, a);
            if (i_in_arr == -1)
            {
                puts("Элемент не найден");
            }
            else printf("\nЭлемент %.4lf имеет индекс %d\n", a, i_in_arr);
            break;

        case 4:
            printf("Введите значение k: ");
            scanf("%lf", &k);

            result = function(array, size, k);
            if (result == -1) {
                printf("Элементы, кратные k, не найдены\n");
            }
            else {
                printf("Номер элемента - %d\n", result);
            }
            break;

        case 5:
            printf("Введите значение A: ");
            scanf("%lf", &A);

            result = findDZ(array, size, A);
            if (result == -1) {
                printf("Элементы, большие A, не найдены\n");
            }
            else {
                printf("Номер элемента - %d\n", result);
            }
            break;

        case 0:
            printf("Выход из программы\n");
            return 0;

        default:
            printf("Неверный выбор!\n");
        }
    }

    return 0;
}

int lab_16()
{
    setlocale(LC_ALL, "RUS");
    int size;
    double* ptr_array;

    printf("Введите размер массива > ");
    scanf("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));

    if (ptr_array == NULL) {
        puts("Ошибка выделения памяти");
        return -1;
    }

    // лаб 16 задание 1
    full_elements(ptr_array, size);
    puts("Массив A:");
    put_elements(ptr_array, size);

    double* array_copy = (double*)malloc(size * sizeof(double));
    if (array_copy != NULL) {
        memcpy(array_copy, ptr_array, size * sizeof(double));
        puts("\nМассив B (квадрат элементов первого массива):");
        // Возводим в квадрат
        for (int i = 0; i < size; i++) {
            array_copy[i] = ptr_array[i] * ptr_array[i];
        }
        put_elements(array_copy, size);
        free(array_copy);
    }

    rand_full_elements(ptr_array, size);
    puts("\nМассив A со случайными элементами (от -1 до 1):");
    put_elements(ptr_array, size);

    // лаб 16 задание 2
    puts("\nМассив со случайно вставленным значением -999:");
    double* new_array = insert(ptr_array, size);
    if (new_array != NULL) {
        put_elements(new_array, size + 1);
        free(new_array);
    }
    else {
        put_elements(ptr_array, size);
    }

    puts(" ");
    return 0;
}
