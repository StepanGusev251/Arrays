﻿/* arrays.h - Заголовочный файл для работы с массивами */

 // Заполняет массив значениями функции F(x) для x от 1 до n;
	; 
double* full_elements(double* ptr_array, int n);

// Математическая функция, вычисляет значение от аргумента x
double F(double x);

// Выводит элементы массива на экран (обычно в консоль)
int put_elements(double* ptr_array, int n);

// Вычисляет значения массива по какой-то формуле (возможно, с использованием F())
double* calc_elements(double* ptr_array, int n);

// Ищет элемент в массиве, возвращает его индекс или -1, если не найден
int find_element(double* ptr_array, int n, double element);

// Выполняет обработку массива с параметром k (специфичная для задачи функция)
int function(double* arr, int n, double k);

// Возвращает сумму элементов массива с индексами от begin до end включительно
double sum_elements(double* ptr_array, int begin, int end);

// Ищет элемент в массиве, удовлетворяющий условиям с параметром A 
int findDZ(double* arr, int n, double A);

// Заполняет массив случайными значениями
double* rand_full_elements(double* ptr_array, int n);

// Вставляет элемент в массив по определённому индексу/условию, возможно увеличивая размер
double* insert(double* ptr_arr, int size);