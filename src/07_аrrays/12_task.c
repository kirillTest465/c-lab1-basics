#include <stdio.h>  // Подключаем библиотеку для ввода и вывода
#include <stdlib.h> // Подключаем библиотеку для функции rand
#include <time.h>   // Подключаем библиотеку для функции time

// Устанавливаем константное значение для двухмерного массива
#define SIZE 5

int main()
{

    // Инициализация двухмерного массива
    int matrix[SIZE][SIZE];

    int row_array[SIZE * SIZE]; // Массив для хранения по строкам
    int col_array[SIZE * SIZE]; // Массив для хранения по столбцам

    // Инициализация генератора случайных числе
    srand(time(NULL));

    // Заполняем двухмерных массив случайными числами и выводим на экран
    printf("Сгенерированная матрица %dX%d:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 10000; // Заполняем числами от 0 до 9999
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Копирование в одномерный массив по строкам
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            row_array[i * SIZE + j] = matrix[i][j];
        }
    }

    // Копирование в одномерный массив по столбцам
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            col_array[j * SIZE + i] = matrix[i][j];
        }
    }

    // Вывод содержимого массива в виде матрицы в порядке строк
    printf("\nХранение по строкам:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%5d", row_array[i * SIZE + j]);
        }
        printf("\n");
    }

    // Вывод содержимого массива в виде матрицы в порядке столбца
    printf("\nХранение по столбцам:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%5d", col_array[j * SIZE + i]);
        }
        printf("\n");
    }

    return 0; // Успешное завершение программы
}